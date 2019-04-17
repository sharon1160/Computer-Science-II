//Ejercicio 10

#include <iostream>
using namespace std;



bool primo (int);
int main()
{   long long s=0;
    for(long long i=2;i<2000000;i++){
        if(primo(i)==true)
            s+=i;
    }
    cout<<s;
    return 0;
}

bool primo (int n){

    for(int j=2;j<=n/2;j++){
        if(n%j==0)
            return false;
    }
    return true;
}
