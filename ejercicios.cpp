#include<iostream>

using namespace  std;

//EJERCICIO 2.1

//A la línea 20 le falta un punto
// y coma .doubleVal () no se puede aplicar a myPoint
//porque myPoint es constante.

class Point
{
    private :
        int x,y;
    public:
        Point (int u,int v): x(u),y(u){}
        int getx(){return x;}
        int gety(){return y;}
        void doubleVal()//esta funcion no es constante por eso no se puede aplicar a my point(mypoint es una constante)
        {
            x*=2;
            y*=2;
        }
};

int main ()
{

    const Point myPoint(5,3)//falta punto y coma
    myPoint.doubleVal();
    cout<<myPoint.getx()<<" "<<myPoint.gety()<<"\n";
    return 0;
}


// EJERCICIO 2.2

//La línea 11 contiene un error porque la función se declara const,
// es decir, como no modifica ninguna variable de instancia, pero asigna x a otro valor

class Point{
    private:
        int x,y;
    public:
        Point(int u,int v):x(u),y(v){}
        int getX(){return x;}
        int getY(){return y;}
        void setX(int newX)const{x =newX;}//la funcion setX es constante, sin embargo asigna x a otro valor
};

int main()

{
    Point p(5,3);
    p.setX(9001);
    cout<<p.getX()<<' '<<p.getY();
    return 0;
}


//EJERCICIO 2.3

//x e y son miembros privados y no se puede acceder a ellos fuera de la clase.

class Point

{
    private:
        int x,y;

    public:
        Point(int u,int v):x(u),y(v){}
        int getX(){return x;}
        int getY(){return y;}
};

int main()
{
    Point p(5,3);
    cout<<p.x<<" "<<p.y<<"\n";//no se puede acceder a x e y desde el main ya q son miembros privados
    return 0;
}


// EJERCICIO 2.4

//a setX le falta el ámbito; las funciones deben declararse

//como void Point :: setX (intnewX) {x = newX;}


class Point
{
    private:
        int x,y;
    public:
        Point(int u,int v):x(u),y(v){}
        int getX(){return x;}
        void setX(int newX);
};
void setX(int newX){x = newX;}//void Point :: setX (intnewX) {x = newX;} , le falta el ambito

int main()
{
    Point p(5,3);
    p.setX (0);
    cout<<p.getX()<<" "<<"\n";
    return 0;
}


//EJERCICIO 2.5


//Eliminar una matriz asignada dinámicamente requiere delete [], no delete

...
int size ;
cin >> size ;
int * nums = new int[ size ];
for(int i = 0; i < size ; ++i)
{
    cin >> nums [i];
}
... // Calculations with nums omitted
delete nums ;//delete [] nums;
...


//EJERCICIO 2.6

//p se asigna utilizando new, pero nunca se desasigna con delete.
// Cada parte de la memoria asignada con new debe ser desasignada
//en algún lugar con un delete correspondiente.


class Point
{
    private :
        int x, y;

    public :
        Point (int u, int v) : x(u), y(v) {}
        int getX () { return x; }
        int getY () { return y; }
};

int main ()

{
    Point *p = new Point (5, 3);
    cout << p-> getX () <<' '<< p-> getY ();
    //le falto el delete [] p;
    return 0;
}

//(segerencia: este error es un error logico, no un syntax error.)


//EJERCICIO 3.1: geometry.h

//Crea la clase con dos ints privados. Nómbralos x y y


class Point {
        int x, y;

    public :
        Point (int xx =0, int yy =0) {x = xx; y = yy ;}
        int getX () const { return x;}
        int getY () const { return y;}
        void setX ( const int xx) {x = xx ;}
        void setY ( const int yy) {y = yy ;}
};
//Note: las funciones getX y getY realmente deberían haber sido declaradas como const, pero
// hemos omitido pedirle que lo haga, por lo que está bien si no lo hizo.



//EJERCICIO 4.1:geometry.h

//Cree la clase con dos miembros privados, un puntero al comienzo de una matriz de Puntos y
//un int que almacena el tamaño (longitud) de la matriz.

class PointArray {
    int size ;
    Point * points ;

    void resize (int size );
public :
    PointArray ();
    PointArray ( const Point pts [], const int size );
    PointArray ( const PointArray &pv);
    ~ PointArray ();
    void clear ();
    int getSize () const { return size ;}
    void push_back ( const Point &p);
    void insert ( const int pos , const Point &p);
    void remove ( const int pos );
    Point *get( const int pos);
    const Point *get( const int pos) const ;
};


//EJERCICIO 4.2:Geometry.cpp


//Implementar el constructor predeterminado (un constructor sin argumentos) con lo siguiente
//firma. Debería crear una matriz con tamaño 0.
//Implementar un constructor que tome una matriz de puntos llamada puntos y un tamaño llamado int
//como sus argumentos. Debería inicializar un PointArray con el tamaño especificado, copiando los valores.
//desde puntos. Deberá asignar dinámicamente la matriz interna de PointArray a la
//tamaño especificado
//PointArray :: PointArray (const Point points [], const int size)
//Finalmente, implemente un constructor que cree una copia de un determinado PointArray (un constructor de copia).
//PointArray :: PointArray (const PointArray & pv)
//(Sugerencia: asegúrese de que los dos PointArrays no terminen usando la misma memoria para sus arreglos internos. También asegúrese de que el contenido del arreglo original se copie, como
//bien.)

#include "geometry .h"

PointArray :: PointArray () {
    size = 0;
    points = new Point [0]; // Permite borrar mas tarde
}

PointArray :: PointArray ( const Point ptsToCopy [], const int toCopySize) {
    size = toCopySize ;
    points = new Point [ toCopySize ];
    for(int i = 0; i < toCopySize ; ++i) {
        points [i] = ptsToCopy [i];
    }
}

PointArray :: PointArray ( const PointArray & other ) {
    // Cualquier código en la clase PointArray tiene acceso a
    // variables privadas como tamaño y puntos
    size = other . size ;
    points = new Point [ size ];
    for (int i = 0; i < size ; i++) {
        points [i] = other . points [i];
    }
}

PointArray ::~ PointArray (){
    delete [] points ;
}

void PointArray :: resize ( int newSize ) {
    Point *pts = new Point [ newSize ];
    int minSize = ( newSize > size ? size : newSize );
    for (int i = 0; i < minSize ; i++)
        pts[i] = points [i];
    delete [] points ;
    size = newSize ;
    points = pts ;
}

void PointArray :: clear () {
    resize (0) ;
}


void PointArray :: push_back ( const Point &p) {
    resize ( size + 1);
    points [ size - 1] = p;
    // También podría simplemente utilizar insertar (size, p);
}

 void PointArray :: insert ( const int pos , const Point &p) {
    resize ( size + 1);

    for (int i = size - 1; i > pos; i --) {
        points [i] = points [i -1];
    }

    points [pos ] = p;
 }

void PointArray :: remove ( const int pos ) {
    if( pos >= 0 && pos < size ) { // pos <size implica size> 0
        // Mueve todo a la izquierda
        for(int i = pos; i < size - 2; i++) {
            points [i] = points [i + 1];
        }
        resize ( size - 1);
    }
}

Point * PointArray :: get( const int pos) {
    return pos >= 0 && pos < size ? points + pos : NULL ;
}

const Point * PointArray :: get( const int pos) const {
    return pos >= 0 && pos < size ? points + pos : NULL ;
}

//POLYGONO AND FRIENDS
//EJERCICIO 5.1.1:GEOMETRY.H

//Cree la clase con dos miembros protegidos: un PointArray y un int estático para mantener
//seguimiento de la cantidad de instancias de Polygon actualmente en existencia

class Polygon {
    protected :
        static int numPolygons ;
        PointArray points ;

    public :
        Polygon ( const PointArray &pa);
        Polygon ( const Point points [], const int numPoints );
        virtual double area () const = 0;
        static int getNumPolygons () { return numPolygons ;}
        int getNumSides () const { return points . getSize () ;}
        const PointArray * getPoints () const { return & points ;}
        ~ Polygon () {-- numPolygons ;}
};

//EJERCICIO 5.1.2

int Polygon ::n = 0;

Polygon :: Polygon ( const PointArray &pa) : points (pa) {
    ++ numPolygons ;
}

Polygon :: Polygon ( const Point pointArr [], const int numPoints ) : points ( pointArr , numPoints ) {
    ++ numPolygons ;
}


//EJERCICIO 5.2.1
//5.4 Rectángulo

//Escribe una subclase de Polígono llamada Rectángulo que modela un rectángulo. Tu código debería
//• Permitir la construcción de un rectángulo a partir de dos puntos (la coordenada inferior izquierda y la coordenada superior derecha)
//• Permitir construir un rectángulo a partir de cuatro pulgadas.
//• Anule el comportamiento de Polygon :: area ...
class Rectangle : public Polygon {
 public :
    Rectangle ( const Point &a, const Point &b);
    Rectangle ( const int a, const int b, const int c, const int d);
    virtual double area () const ;
};



//EJERCICIO 5.2.2
//GEOMETRY.CPP

Point constructorPoints [4];

Point * updateConstructorPoints ( const Point &p1 , const Point &p2 , const Point &p3 , const Point &p4 = Point (0 ,0)) {
    constructorPoints [0] = p1;
    constructorPoints [1] = p2;
    constructorPoints [2] = p3;
    constructorPoints [3] = p4;
    return constructorPoints ;
}

Rectangle :: Rectangle ( const Point &ll , const Point &ur): Polygon ( updateConstructorPoints (ll , Point (ll. getX () , ur. getY ()), ur , Point (ur. getX () , ll. getY ())), 4) {}

Rectangle :: Rectangle ( const int llx , const int lly , const int urx ,const int ury): Polygon ( updateConstructorPoints ( Point (llx , lly), Point (llx ,ury),Point (urx , ury), Point (urx ,lly)), 4) {}

double Rectangle :: area () const {
    int length = points .get (1) ->getY () - points .get (0) ->getY ();
    int width = points .get (2) ->getX () - points .get (1) ->getX ();
    return std :: abs (( double ) length * width );
}
//(You’ll need to add #include <cmath> at the top of your file to use the abs function.)


//EJERCICIO 5.3.1
//GEOMETRY.H
//Escribe una subclase de Polígono llamado Triángulo que modela un triángulo. Tu código debería
//• Construye un triángulo a partir de tres puntos
//• Anule la función del área de tal manera que calcula el área usando la fórmula de Heron

class Triangle : public Polygon {

    public :
        Triangle ( const Point &a, const Point &b, const Point &c);
        virtual double area () const ;
};


//EJERCICIO 5.4
//GEOMETRY.CPP

Triangle :: Triangle ( const Point &a, const Point &b, const Point &c): Polygon ( updateConstructorPoints (a, b, c), 3) {}

double Triangle :: area () const {
    int dx01 = points .get (0) ->getX () - points .get (1) ->getX () ,
        dx12 = points .get (1) ->getX () - points .get (2) ->getX () ,
        dx20 = points .get (2) ->getX () - points .get (0) ->getX ();
    int dy01 = points .get (0) ->getY () - points .get (1) ->getY () ,
        dy12 = points .get (1) ->getY () - points .get (2) ->getY () ,
        dy20 = points .get (2) ->getY () - points .get (0) ->getY ();

    double a = std :: sqrt ( dx01 * dx01 + dy01 * dy01 ),
            b = std :: sqrt ( dx12 * dx12 + dy12 * dy12 ),
            c = std :: sqrt ( dx20 * dx20 + dy20 * dy20 );

    double s = (a + b + c) / 2;

    return std :: sqrt ( s * (s-a) * (s-b) * (s-c) );
}

//EJERCICIO 5.5
//MAIN.CPP

# include <iostream >

using namespace std;

# include " geometry .h"

void printAttributes ( Polygon *p) {
    cout << "p’s area is " << p-> area () << ".\n";

    cout << "p’s points are :\n";
    const PointArray *pa = p-> getPoints ();
    for(int i = 0; i < pa -> getSize (); ++i) {
        cout << "(" << pa ->get (i) ->getX () << ", " << pa ->get (i) ->getY () << ")\n";
    }

}

int main (int argc , char * argv []) {
    cout << " Enter lower left and upper right coords of rectangle asfour space separated integers : ";
    int llx , lly , urx , ury;
    cin >> llx >> lly >> urx >> ury;
    Point ll(llx , lly), ur(urx , ury);
    Rectangle r(ll , ur);
    printAttributes (&r);

    cout << " Enter three coords of triangle as six space separated integers : ";
    int x1 , y1 , x2 , y2 , x3 , y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    Point a(x1 , y1), b(x2 , y2), c(x3 , y3);
    Triangle t(a, b, c);
    printAttributes (&t);

    return 0;
}

//EJERCICIO 6
//En esta sección, escribirá un programa que convierte una palabra en inglés dada
//en Pig Latin. Pig Latin es un juego de lenguaje de alteraciones jugado en inglés.

const string vowels = " aeiou ";

string pigLatinify ( const string s) {
    if(s. size () == 0) {
        //Uy, cadena vacía
        return s;
    }
    if(s. find ("qu") == 0) { // Comienza con "qu"
        return s. substr (2, s. size () -2) + "-" + s. substr (0, 2) + "ay";
    } else if( vowels . find (s [0]) != string :: npos ) { // Comienza con una vocal
            return s + " way";
    } else {
        return s. substr (1, s. size () -1) + "-" + s[0] + "ay";
    }
}

