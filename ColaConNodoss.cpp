#include <iostream>

using namespace std;

template<class T>
class Node
{
    private:
        T dato;
        Node<T>* siguiente;
    public:
        Node(T);
        void setSiguiente(Node<T>*);
        void setDato(T);
        Node<T>* getSiguiente();
        T getDato();
};
//constructor
template<class T>
Node<T>::Node(T _dato)
{
    siguiente=NULL;
    dato = _dato;
}
//Establece el puntero al nodo siguiente
template<class T>
void Node<T>::setSiguiente(Node<T>* _siguiente)
{
    siguiente = _siguiente;
}

template<class T>
void Node<T>::setDato(T _dato)
{
    dato = _dato;
}
//se obtiene el puntero al siguiente
template<class T>
Node<T>* Node<T>::getSiguiente()
{
    return siguiente;
}
//se obtiene el contenido del nodo
template<class T>
T Node<T>::getDato()
{
    return dato;
}

template<class T>
class Cola {
private:
    Node<T> *raiz;
    Node<T> *fondo;
public:
    Cola();
    ~Cola();
    void insertar(T);
    int extraer();
    void imprimir();
    bool vacia();
};

template<class T>
Cola<T>::Cola()
{
    raiz = NULL;
    fondo = NULL;
}
template<class T>
Cola<T>::~Cola()
{
    Node<T> *aux = raiz;
    Node<T> *bor;
    while (aux != NULL)
    {
        bor = aux;
        aux = aux->getSiguiente();
        delete bor;
    }
}
template<class T>
void Cola<T>::insertar(T x)
{
    Node<T> *nuevo;
    nuevo = new Node<T>(x);
    nuevo->setDato(x);
    nuevo->setSiguiente(NULL);
    if (vacia())
    {
        raiz = nuevo;
        fondo = nuevo;
    }
    else {
        fondo->setSiguiente(nuevo);
        fondo = nuevo;
    }
}
template<class T>
int Cola<T>::extraer()
{
    if (!vacia())
    {
        T informacion = raiz->getDato();
        Node<T> *bor = raiz;
        if (raiz == fondo)
        {
            raiz = NULL;
            fondo = NULL;
        }
        else
        {
            raiz = raiz->getSiguiente();
        }
        delete bor;
        return informacion;
    }
    else
        return -1;
}
template<class T>
void Cola<T>::imprimir()
{
    Node<T> *aux = raiz;
    cout << "Listado de todos los elementos de la cola"<<endl;
    while (aux != NULL)
    {
        cout << aux->getDato() <<endl;
        aux = aux->getSiguiente();
    }
    cout <<endl;
}
template<class T>
bool Cola<T>::vacia()
{
    if (raiz == NULL)
        return true;
    else
        return false;
}

int main()
{
    Cola<int> cola1;
    cout<<"Insertamos el numero 5"<<endl;
    cola1.insertar(5);
    cout<<"Insertamos el numero 10"<<endl;
    cola1.insertar(10);
    cout<<"Insertamos el numero 50"<<endl;
    cola1.insertar(50);
    cola1.imprimir();
    cout <<"Extraemos uno de la cola:" <<cola1.extraer()<<endl;
    cola1.imprimir();
    cout<<"Insertamos el numero 34"<<endl;
    cola1.insertar(34);
    cola1.imprimir();
    cout <<"Extraemos uno de la cola:" <<cola1.extraer()<<endl;
    return 0;
}
