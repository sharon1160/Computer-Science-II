//METODO DE ORDENAMIENTO POR INSERCION
#include<iostream>


using namespace std;

int main(){
	int numeros[] = {3,4,2,1};
	int i,pos,actual;

	for(i=0;i<4;i++){
		pos = i;
		actual = numeros[i];

		while((pos>0) && (numeros[pos-1] > actual))
        {
			numeros[pos] = numeros[pos-1];
			pos--;
		}
		numeros[pos] = actual;
	}

	cout<<"Orden Ascendente: ";
	for(i=0;i<4;i++){
		cout<<numeros[i]<<" ";
	}

	cout<<"\nOrden Descendente: ";
	for(i=3;i>=0;i--){
		cout<<numeros[i]<<" ";
	}


	return 0;
}
