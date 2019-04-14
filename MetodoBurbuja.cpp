//METODO BURBUJA

#include<iostream>


using namespace std;

int main(){
	int vectorr[5] = {2,3,1,5,4};
	int i,j,aux;

	for(i=0;i<5;i++){
		for(j=0;j<4;j++){
			if(vectorr[j] > vectorr[j+1]){
				aux = vectorr[j];
				vectorr[j] = vectorr[j+1];
				vectorr[j+1] = aux;
			}
		}
	}

	cout<<"Vector en forma Ascendente: ";
	for(i=0;i<5;i++){
		cout<<vectorr[i]<<" ";
	}

	cout<<"\nVector en forma Descendente: ";
	for(i=4;i>=0;i--){
		cout<<vectorr[i]<<" ";
	}


	return 0;
}
