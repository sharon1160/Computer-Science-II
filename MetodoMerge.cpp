#include <iostream>

using namespace std;


void mergeSort(int [],int );
void mergee(int [],int ,int [],int ,int []);
void mostrar(int [],int);

int main(){
    int A[]={5,3,2,8};
    int n=4;
    mergeSort(A,n);
    mostrar(A,n);
    return 0;

}

void mergeSort(int A[],int n)
{
    if(n==1){
      return;
    }
    //divide la cadena de numeros

    int mitad = n / 2;
    int listizq[mitad];
    int listder[n-mitad];

    for(int i=0;i<mitad;i++)
        listizq[i] = A[i];
    for(int i=mitad;i<n;i++)
        listder[i-mitad] = A[i];

    mergeSort(listizq, mitad);
    mergeSort(listder, n-mitad);
    mergee(listizq, mitad, listder, n-mitad, A);
}

void mergee(int listizq[],int nroIzq,int listder[],int nroDer,int A[])
{
    int i=0,j=0,k=0;
    while( ( i < nroIzq ) && ( j < nroDer ) )
    {
        if( listizq[i] <= listder[j])
        {
            A[k] = listizq[i];
            i++;
        }
        else
        {
            A[k] = listder[j];
            j++;
        }
        k++;
    }

    while(i < nroIzq)
    {
        A[k] = listizq[i];
        i++;k++;
    }

    while(j < nroDer)
    {
        A[k] = listder[j];
        j++;k++;
    }
}
void mostrar (int A[],int n){
    for(int i=0;i<n;i++)
        cout<<A[i]<<" ";
}



