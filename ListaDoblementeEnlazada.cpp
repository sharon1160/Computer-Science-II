#include <iostream>

using namespace std;

template< class T> 
class Nodo{
    private:
        T dato;
        Nodo* anterior;
        Nodo* siguiente;
        
    public:
        Nodo(T _dato){
            siguiente=NULL;
            anterior=NULL;
            dato=_dato;
        }
        void setSiguiente(Nodo<T>* _siguiente){
            siguiente= _siguiente;
        }
        void setAnterior(Nodo<T>* _anterior){
            anterior=_anterior;
        }
        void setDato(T _dato){
            dato=_dato;
        }
        Nodo<T>* getSiguiente(){
            return siguiente;
        }
        Nodo<T>* getAnterior(){
            return anterior;
        }
        T getDato()
        {
            return dato;
        }
};

template <class T>
class ListaDoble
{
    private:
        Nodo<T>* head;
        Nodo<T>* cola;
        int tam;
    public:
        ListaDoble(){//constructor
            head=NULL;
            cola=NULL;
            tam=0;
        }
        ~ListaDoble(){//destructor
            for(int i =0 ; i<tam ; i++)
            {
                Nodo<T>* lista = head;
                head = head->getSiguiente();
                delete lista;
            }
        }
        void mostrar(){//para mostrar la lista
            Nodo<T>* aux=head;
            while(aux!=NULL){
                cout<<aux->getDato()<<" ";
                aux=aux->getSiguiente();
            }
            cout<<endl;
        }
        void push(T dato){//para añadir a la parte frontal de la lista
            Nodo<T> *aux =  new Nodo<T>(dato);
            if(tam==0){
                aux->setAnterior(NULL);
                aux->setSiguiente(head);
                cola=aux;
                head = aux;
                tam++;
            }
            else if(tam>0){
                aux->setAnterior(NULL);
                aux->setSiguiente(head);
    
                head = aux;
                tam++;
            }
        }
        
        void inyectar(T dato){//para añadir al final de la lista
            Nodo<T> *aux =  new Nodo<T>(dato);
            if(tam==0){
                push(aux->getDato());
            }
            else if(tam>0){
                aux->setAnterior(cola);
                aux->setSiguiente(NULL);
                cola->setSiguiente(aux);
                cola=aux;
                tam++;
            }
        }
        
        T pop(){//para eliminar el elemento frontal de la lista
                T dato;
                if(tam==0){
                       return 0;
                }
                else if(tam>0){
                        Nodo<T> *eliminar = head;
                        head=head->getSiguiente();
                         dato=eliminar->getDato();
                         delete eliminar;
                        tam--;
                        return dato;
               }
        }
        T expulsar(){//para eliminar el ultimo elemento de la lista
            T dato;
            if(tam==0){
                return 0;
            }
            else if(tam>0){
                Nodo<T> *eliminar = cola;
                cola=cola->getAnterior();
                cola->setSiguiente(NULL);
                dato=eliminar->getDato();
                delete eliminar;
                tam--;
                return dato;
                
            }
        }
};


int main()
{
    ListaDoble<int> lis;
    lis.push(3);
    lis.push(6);
    lis.push(8);
    lis.inyectar(5);
    lis.inyectar(2);
    cout<<"_____________Lista___________"<<endl;
    lis.mostrar();
    cout<<"Primer dato ha eliminar : "<<lis.pop()<<endl;
    cout<<"_____________Lista___________"<<endl;
    lis.mostrar();
    cout<<"Utimo dato ha eliminar : "<<lis.expulsar()<<endl;
    cout<<"_____________Lista___________"<<endl;
    lis.mostrar();
    cout<<"Utimo dato ha eliminar : "<<lis.expulsar()<<endl;
    cout<<"_____________Lista___________"<<endl;
    lis.mostrar();
    return 0;
}
