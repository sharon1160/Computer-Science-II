#include<iostream>

using namespace std; /*
Donde:
    A->primera matriz
    B->segunda matriz
    FA->filas de A
    CA->columnas de A
    FB->filas de B
    CB->columnas de B
    C->matriz resultante de la multiplicacion de dimension FAxCB

CONDICION:dos matrices se pueden multiplicar si las columnas de la primera matriz es igual a las filas de la segunda matriz
*/
void multiplicacion(int **A,int FA,int CA,int **B,int FB,int CB,int **C ){

    if(CA==FB){//para que se puedan multiplicar dos matrices
        for(int i=0;i<FA;i++){
            for(int j=0;j<CB;j++){
                *(*(C+i)+j)=0;//inicializar
                for(int k=0;k<CA;k++){
                    *(*(C+i)+j)=*(*(C+i)+j)+*(*(A+i)+k)* *(*(B+k)+j);
                }
            }
        }
    }
}
void llenar_matriz(int **&M,int f,int c){
    cout<<"ingrese datos de la matriz:"<<endl;
    for(int i=0;i<f;i++){
        for(int j=0;j<c;j++){
            cin>>*(*(M+i)+j);
        }
    }
}
void mostrar_matriz(int **&M,int f,int c){
    cout<<endl;
    for(int i=0;i<f;i++){
        for(int j=0;j<c;j++){
            cout<<*(*(M+i)+j)<<"\t";
        }cout<<endl;
    }cout<<endl;
}

 void crear(int **&p,int f,int c)
 {
    p=new int*[f];
    for (int i=0;i<f;i++)
        p[i]=new int [c];

 }


  void eliminar(int **&p,int f)
 {
    for(int i=0;i<3;i++)
        delete [] p[i];
    delete [] p;

 }

int main ()
{
    int **A;
    int **B;
    int **C;
    int fa,ca,fb,cb;
    cout<<"\t"<<"MATRIZ A:"<<endl;
    cout<<"ingrese filas de la matriz A:";
    cin>>fa;
    cout<<"ingrese columnas de la matri A:";
    cin>>ca;
    crear(A,fa,ca);
    llenar_matriz(A,fa,ca);
    cout<<"\t"<<"MATRIZ B:"<<endl;
    cout<<"el numero de filas tiene que ser:"<<ca<<" para que se puedan multiplicar"<<endl;
    fb=ca;
    cout<<"ingrese columnas de la matriz B:";
    cin>>cb;
    crear(B,fb,cb);
    llenar_matriz(B,fb,cb);
    crear(C,fa,cb);
    multiplicacion(A,fa,ca,B,fb,cb,C);
    cout<<"matriz A:"<<endl;
    mostrar_matriz(A,fa,ca);
    cout<<"matriz A:"<<endl;
    mostrar_matriz(B,fb,cb);
    cout<<"matriz AXB:"<<endl;
    mostrar_matriz(C,fa,cb);
    eliminar(A,fa);
    eliminar(B,fb);
    eliminar(C,fa);

    return 0;
}

