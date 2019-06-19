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
//clase Pila
template<class T>
class Pila
{
    private:
        Node<T>* raiz;
    public:
        Pila();
        ~Pila();
        void push(T);
        void pop();
        void imprimir();
        T top();
        int size();
};
//constructor
template<class T>
Pila <T>::Pila()
{
    raiz = NULL;
}
//para insertar elementos
template<class T>
void Pila<T>::push(T n)
{
    Node<T> *nuevo=new Node<T>(n);
    nuevo->setSiguiente(NULL);
    if (raiz != NULL)
    {

        nuevo->setSiguiente(raiz);
    }
    raiz=nuevo;

}
//para retornar el ultimo elemento
template<class T>
T Pila<T>::top()
{
  Node<T> * aux = raiz;
  if (raiz == NULL)
    cout << "La pila esta vacia!"<<endl;
  else
  {
    return aux->getDato();
  }
}
//para mostrar la pila
template<class T>
void Pila<T>::imprimir()
{
    Node<T> *aux = raiz;
    cout << "Listado de todos los elementos de la pila.\n";
    if (raiz == NULL)
        cout<<"pila vacia";
    else
    {
        while (aux != NULL)
        {
            cout << aux->getDato() << "\n";
            aux = aux->getSiguiente();
        }
        cout << "\n";
    }
}
//para sacar el ultimo elemento puesto en la pila
template<class T>
void Pila<T>::pop()
{
    if (raiz != NULL)
    {
        Node<T> *aux = raiz;
        raiz = raiz->getSiguiente();
        delete aux;

    }
    else
    {
        cout<<"la pila esta vacia"<<endl;
    }
}
//para obtener el tamaño de la pila
template<class T>
int Pila<T> ::size()
{
      Node<T>* aux1 = raiz;
      if (raiz == NULL)
         return 0;
      else
      {
        int contador = 0;
        while (aux1!=NULL)
        {
          aux1 = aux1->getSiguiente();
          contador++;
        }
        return contador;
      }
}
//destructor de la clase Pila
template<class T>
Pila<T>::~Pila()
{
    Node<T> *aux = raiz;
    Node<T> *bor;
    while (aux != NULL)
    {
        bor = aux;
        aux = aux->getSiguiente();
        delete bor;
    }
    cout<<"Memoria Liberada"<<endl;
}


int main()
{
    Pila<int> pila1;
    pila1.push(10);
    pila1.push(40);
    pila1.push(3);
    pila1.push(20);
    pila1.imprimir();
    pila1.pop();
    pila1.imprimir();
    cout<<"El tamaño de la pila es: "<<pila1.size()<<endl;
    cout<<"El top de la pila es:"<<pila1.top()<<endl;
    return 0;

}

