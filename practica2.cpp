#include <iostream>

using namespace std;
//FUNCIONES
//1.1.1 DEFAULT ARGUMENTS
/*
void printNTimes ( char * msg, int n ) {
    for ( int i = 0; i < n ; ++ i ) {
        cout << msg ;

    }
}
int main ()
{
    char* msg="hola mundo";
    int n=3;
    printNTimes(msg,n);
    return 0;
}
*/
/*
void printNTimes ( char * msg , int n = 1) {
 for ( int i = 0; i < n ; ++i ) {
        cout << msg ;
 }
}
int main ()
{
    char* msg="hola mundo";
    int n=3;
    printNTimes(msg);
    return 0;
}
*/
/*
void printNTimes ( char * msg = " \ n", int n = 1) {

 for ( int i = 0; i < n ; ++ i ) {
    cout << msg ;
 }

}
int main ()
{
    char* msg="hola mundo";
    int n=3;
    printNTimes();
    return 0;
}
*/
//1.1.2 CONSTANT ARGUMENTS
/*
void print ( const int n ) {

    cout << n ;

}
int main (){
    int n=3;
    print(n);
}
*/
/*
void print ( const long &x ) { // Pass - by - reference avoids overhead
// of copying large number
    cout << x ;
}

int main () {

 long x = 234923592;

 print ( x ); // We are guaranteed that x

 // will not be changed by this

 return 0;

}
*/
//1.1.3 FUNCIONES DE GENERACIONES DE NUMEROS ALEATORIOS
/*
#include <cstdlib> // C standard library ­
                    // defines rand () , srand () , RAND_MAX
#include <ctime> // C time functions - defines time ()

int main () {
    srand ( time (0) );//ESTABLECE LA SEMILLA
    //tiempo (0) devuelve la hora actual como un número
    int randNum = rand () ;
    std :: cout << "A random number : " << randNum << endl ;
    return 0;
}
*/
//1.2 Pointers
//1.2.1 Pointers to Pointers

void setString ( char ** strPtr ) {
    int x;
    cin >> x;
    if(x < 0)
        * strPtr = " Negative ! ";
    else
        * strPtr = " Nonnegative ! ";
}



int main () {
    char * str ;
    setString (& str ) ;
    cout << str ; // String has been set by setString
    return 0;
}
/*
//1.2.2 Returning Pointers
int * getRandNumPtr (){
    int x = rand ();
    return &x ;
}

int main () {

    int * randNumPtr = getRandNumPtr () ;
    cout << * randNumPtr ; // ERROR
    return 0;
}
//1.3 Arrays and Pointers
//1.3.1 Arrays of Pointers

const char * suitNames [] = {" Clubs ", " Diamonds ", " Spades ", " Clubs "};
cout << " Enter a suit number (1 -4) : ";
unsigned int suitNum ;
cin >> suitNum ;
if( suitNum <= 3)
    cout << suitNames [ suitNum - 1];
//1.3.2 Pointers to Array Elements

const int ARRAY_LEN = 100;
int arr [ ARRAY_LEN ];
int * p = arr ;
int * q = & arr [0];

//

int * z = & arr [10];

//2 A Simple Function
void f( const int a = 5)
{
    std :: cout << a*2 << " \ n";
}
int a = 123;
int main ()
{
    f(1) ;
    f(a) ;
    int b = 3;
    f (b) ;
    int a = 4;
    f (a) ;
    f();
}

//3 Fix the Function
//3.1

void printNum (int number ) { std :: cout << number ; }
int main () {
    printNum (35) ;
    return 0;
}


//3.2

void printNum (number) { std :: cout << number ; };

int main () {

 int number = 35;
 printNum ( number );
 return 0;
}

 //3.3
void doubleNumber (int &num ) {num = num * 2;}

int main () {
 int num = 35;
 doubleNumber (num ) ;
 std :: cout << num ; // Should print 70
 return 0;
}

//3.4
#include <cstdlib> // contains some math functions

int difference ( const int x , const int y) {
    int diff = abs ( x - y ) ; // abs ( n) returns absolute value of n
    return diff;
}



int main () {

    std :: cout << difference (24 , 1238) ;
    return 0;
}
 //3.5

int sum ( const int x, const int y,const int z ) {
    return x + y +z;
}

int main () {
    std :: cout << sum (1, 2, 3); // Should print 6
    return 0;
}

//3.6
const int ARRAY_LEN = 10;

int main () {

    int arr [ ARRAY_LEN ] = {10}; // Note implicit initialization of
    // other elements
    int * xPtr = arr , *yPtr = arr + ARRAY_LEN - 1;
    std :: cout << * xPtr << ' ' << * yPtr ; // Should output 10 0
    return 0;
}
//sums
// 4.1 solucion

int sum ( const int x , const int y ) {
    return x + y ;
}

double sum ( const double x , const double y ) {
    return x + y ;
}
//4.3
int sum ( const int x , const int y , const int z ) {
    return x + y + z ;
}

int sum ( const int a , const int b , const int c , const int d ) {
    return a + b + c + d ;
}
//4.4
int sum( const int a, const int b, const int c = 0 , const int d = 0)
{
    return a + b + c + d ;
}
 //4.5
int sum( const int numbers [], const int numbersLen ) {
    int sum = 0;
    for(int i = 0; i < numbersLen ; ++i ) {
        sum += numbers [ i];
    }
    return sum;
}
//4.6
int sum ( const int numbers [] , const int numbersLen ) {
    return numbersLen == 0 ? 0 : numbers [0] + sum ( numbers + 1 ,numbersLen - 1) ;
}
//5 Calculating π
//5.1

double x = rand () / ( double ) RAND_MAX , y = rand () / ( double ) RAND_MAX ;

//5.2

int dartsInCircle = 0;

for(int i = 0; i < n ; ++ i ) {
    double x = rand () / ( double ) RAND_MAX , y = rand () / ( double )
        RAND_MAX ;
    if( sqrt ( x * x + y * y ) < 1 ) {
        ++ dartsInCircle ;
    }
}
//5.3
double computePi ( const int n){
    srand ( time (0) ) ;
    int dartsInCircle = 0;
    for(int i = 0; i < n ; ++i ) {
        double x = rand () / ( double ) RAND_MAX , y = rand () / ( double )
            RAND_MAX ;
        if( sqrt ( x * x + y * y ) < 1 ) {
            ++ dartsInCircle ;
        }
    }
 // r^2 is 1 , and a/4 = dartsInCircle /n, yielding this for pi:
 return dartsInCircle / static_cast <double >(n ) * 4;
}
//6 Array Operations
//6.1

void printArray ( const int arr [], const int len ) {
    for(int i = 0; i < len; ++i ) {
        cout << arr [ i];
        if( i < len -1) {
            cout << ", ";
        }
    }
}

//6.2

void reverse (int numbers [] , const int numbersLen ) {

    for(int i = 0; i < numbersLen / 2; ++ i ) {
        int tmp = numbers [ i ];
        int indexFromEnd = numbersLen - i - 1;
        numbers [ i ] = numbers [ indexFromEnd ];
        numbers [ indexFromEnd ] = tmp ;
    }
}

//6.3

void transpose ( const int input [][ LENGTH ] , int output [][ WIDTH ]) {
    for(int i = 0; i < WIDTH ; ++ i ) {
        for (int j = 0; j < LENGTH ; ++ j ) {
            output [ j ][ i ] = input [ i ][ j ];
        }
    }
}
 //6.5
void reverse (int numbers [] , const int numbersLen ) {
    for(int i = 0; i < numbersLen / 2; ++ i ) {
        int tmp = *( numbers + i ) ;
        int indexFromEnd = numbersLen - i - 1;
        *( numbers + i ) = *( numbers + indexFromEnd ) ;
        *( numbers + indexFromEnd ) = tmp ;
    }
}
//7 Pointers and Strings
//7.1

int stringLength ( const char * str ) {
    int length = 0;
    while (*( str + length ) != '\0') {
        ++ length ;
    }
    return length ;
}

 //7.2
void swap (int &x, int & y ) {
    int tmp = x ;
    x = y ;
    y = tmp;
}
//7.3
void swap (int *x , int * y ) {

    int tmp = * x ;
    * x = * y ;
    * y = tmp ;
}
 //7.4
void swap (int ** x , int ** y ) {

    int * tmp = * x ;
    * x = * y
    * y = tmp ;
}
//7.5
	 char *nthCharPtr = &oddOrEven[5];
	 nthCharPtr -= 2; or nthCharPtr = oddOrEven + 3;
	 cout << *nthCharPtr;
	 char **pointerPtr = &nthCharPtr;
	 cout << pointerPtr;
	 cout << **pointerPtr;
	 nthCharPtr++; to point to the next character in oddOrEven (i.e. one character past
    the location it currently points to)
	 cout << nthCharPtr - oddOrEven;

 //7.4

int x = 5, y = 6;
int * ptr1 = &x, * ptr2 = & y;
swap (& ptr1 , & ptr2 ) ;
cout << * ptr1 << ' ' << * ptr2 ; // Prints "6 5"

//7.5

char * oddOrEven = " Never odd or even ";
*/


