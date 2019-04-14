//METODO QUICKSORT
#include <iostream>

using namespace std;

void mostrarOrden(int [], int);
void quicksort(int [], int, int);

int main(){
    int n=5, A[]={1,22,43,4,3};
    quicksort(A, 0, n - 1);
    mostrarOrden(A, n);
    return 0;
}

void mostrarOrden(int A[], int n){
    cout<<"Array en forma ascendente : "<<endl;
    for(int i = 0; i < n; i++){
        cout<<A[i]<<" ";
    }
}

void quicksort(int A[], int primerapos, int ultimapos){
    //el quicksort necesita una lista, la 1ra y ultima posicion del array
    //el pivote es el valor medio de la lista
    int poscentral, i, j, pivote;
    poscentral = (primerapos + ultimapos)/2; //posicion central del array
    //capturar valor del medio del array
    pivote = A[poscentral];
    //esta igualacion es para separar los segmentos
    i = primerapos;
    j = ultimapos;

    //toda lista necesita un recorrido, en este caso con do while

    do{
        //separando en 2 partes el array
        while(A[i] < pivote) i++; //separando valores menores del pivote
        while(A[j] > pivote) j--; //separando valores mayores del pivote
        if(i <= j){
        //se hace el intercambio de valores
            int aux;
            aux= A[i];
            A[i] = A[j];
            A[j] = aux;
            i++;
            j--;
        }
    } while(i<=j);

    if(primerapos < j)
        quicksort(A, primerapos, j);
    if(i < ultimapos)
        quicksort(A, i, ultimapos);
}
