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
class LinkedList
{
    private:
        Node<T> *head;
        int tam;
    public:
        LinkedList();//constructor
        ~LinkedList();//destructor
        void push_front(T);//para poner un elemento delante de toda la lista
        void push_back(T);//para poner un elemto al final de la lista
        void add(T,int);//para añadir un elemento de tipo T en alguna posicion

        T get_front();//para obtener el primer elemento
        T get_back();//para obtener el ultimo elemento
        T get(int);//para obtener un dato de la posicion en la que se desea

        void eliminar_front();//para eliminar el primer elemento
        void eliminar_back();//para eliminar el ultimo elemento
        void eliminar(int);//para eliminar cualquier elemento

        int getSize()//para obtener el tamanio
        {
            return tam;
        }

        void mostrar();//para mostrar la lista
        //////////////////////////////////////
        Node<T>* begin();
        Node<T>* end() ;
        //////////////////////
};


template<class T>
LinkedList<T>::LinkedList()
{
    head=NULL;
    tam=0;
}

template<class T>
void LinkedList<T>::push_back(T dato)
{
    Node<T>* aux =  new Node<T>(dato);

    if(head==NULL)
        head = aux;

    else
    {
        Node<T>* ptr = head;
        while(ptr->getSiguiente() != NULL)
            ptr = ptr->getSiguiente();
        ptr->setSiguiente(aux);
    }
    tam++;
}

template<class T>
void LinkedList<T>::push_front(T dato)
{
    Node<T> *aux =  new Node<T>(dato);
    aux->setSiguiente(head);
    head = aux;
    tam++;
}

template<class T>
void LinkedList<T>::add(T dato,int n)
{
    Node<T>* aux =  new Node<T>(dato);

    if(n>tam)
        cout<<"introduzca un numero menor al tamaño de la lista";
    else if(n==0)
    {
        aux->setSiguiente(head);
        head = aux;
    }
    if(head==NULL)
        head = aux;
    else
    {
        int cont = 0;
        Node<T>* puntero = head ;
        while(cont < (n-1))
        {
            puntero = head->getSiguiente();
            cont++;
        }
        aux->setSiguiente(puntero->getSiguiente());
        puntero->setSiguiente(aux);
    }
    tam++;
}

template<class T>
T LinkedList<T>::get_front()
{
    if(tam == 0)
       return 0;
    return (head->getDato());
}

template<class T>
T LinkedList<T>::get_back()
{
    if(tam == 0)
        return 0;
    Node<T>* ptr = head;
    while(ptr->getSiguiente()  != NULL)
        ptr = ptr->getSiguiente();
    return (ptr->getDato());

}

template<class T>
T LinkedList<T>::get(int n)
{
    if(n>=tam)
       return NULL;
    Node<T> ptr = head;
    int cont = 0;
    while(cont < n)
        ptr = ptr->getSiguiente();
    return (ptr->getDato());
}

template<class T>
void LinkedList<T>::eliminar_front()
{
    if(tam ==0) return ;
    Node<T>* elimnado = head;
    head = head->getSiguiente();
    delete elimnado;
    tam--;
}


template<class T>
void LinkedList<T>::eliminar_back()
{
    if(tam ==0)
       return ;
    if(tam ==1)
        eliminar_front();
    else
    {
        Node<T>* ptr = head;
        while(ptr->getSiguiente()->getSiguiente() != NULL)
            ptr = ptr->getSiguiente();
        Node<T>* eliminado = ptr->getSiguiente();
        ptr->setSiguiente(NULL);
        delete eliminado;
        tam--;
    }
}

template <class T>
void LinkedList<T>::eliminar(int n)
{
    if(n >= tam)
        return ;
    if(n == 0)
        eliminar_front();
    else
    {
        Node<T>* ptr = head;
        int cont = 0;
        while(cont < (n-1) )
        {
            ptr = ptr->getSiguiente();
            cont++;
        }
        Node<T>* eliminado = ptr->getSiguiente();
        ptr->setSiguiente(eliminado->getSiguiente());
        delete eliminado;
        tam--;
    }
}

template<class T>
void LinkedList<T>::mostrar()
{
    Node<T>* ptr = head;
    for(int i =0 ; i<tam ; i++)
    {
        cout << ptr->getDato() <<" ";
        ptr = ptr->getSiguiente();
    }
    cout <<endl;
}
/////////////////////////////////////
template<class T>
Node<T>* LinkedList<T>::begin()
{
    return head;
}

template<class T>
Node<T>* LinkedList<T>::end()
{
    Node<T>* ptr = head;
    while(ptr->getSiguiente() != NULL)
        ptr = ptr->getSiguiente();
    return ptr->getSiguiente();
}
/////////////////////////////////////
template<class T>
LinkedList<T>::~LinkedList()
{
    for(int i =0 ; i<tam ; i++)
    {
        Node<T>* lista = head;
        head = head->getSiguiente();
        delete lista;
    }
}
//////////////////////////////////////////////////////////

template <class T>
class IteratorList
{
    private:
        Node<T>* iterador;
    public:
        IteratorList();

        void operator++();
        void operator=(Node<T>* ptro);
        bool operator!=(Node<T>* ptro);

        T operator*();
};

template<class T>
IteratorList<T>::IteratorList()
{
    iterador=NULL;
}
template<class T>
void IteratorList<T>::operator++()
{
    iterador = iterador->getSiguiente();
}

template<class T>
void IteratorList<T>::operator=(Node<T>* ptro)
{
    iterador = ptro;
}

template<class T>
bool IteratorList<T>::operator!=(Node<T> *ptro)
{
    return iterador!=ptro;
}

template<class T>
T IteratorList<T>::operator*()
{
    return iterador->getDato();
}

///////////////////////////////////////////////////////
int main()
{

    LinkedList<int> listanumeros;
    listanumeros.push_back(0);
    listanumeros.push_back(5);
    listanumeros.push_front(78);
    listanumeros.push_back(56);
    cout<<"LISTA :";
    listanumeros.mostrar();
    cout<<"PRIMER NUMERO: "<<listanumeros.get_front()<<endl;
    cout<<"ULTIMO NUMERO: "<<listanumeros.get_back()<<endl;
    cout<<"LISTA :";
    listanumeros.mostrar();
    listanumeros.eliminar_front();
    listanumeros.eliminar_back();
    cout<<"LISTA :";
    listanumeros.mostrar();
    listanumeros.add(7,1);
    cout<<"LISTA :";
    listanumeros.mostrar();
    listanumeros.eliminar(2);
    cout<<"LISTA :";
    listanumeros.mostrar();
    cout<<endl;
    cout<<"MOSTRANDO LISTA CON EL ITERATOR : ";
    IteratorList<int> it;
    //la variable it primero es asignado al puntero al primer nodo
    //luego se compara la variable it con el puntero a NULL
    //despues it recorre con el operador ++
    //luego se imprime el contenido de la variable it
    for(it=listanumeros.begin() ; it != listanumeros.end() ; ++it )
        cout << *it << " ";
    cout<<endl;
    return 0;
}




