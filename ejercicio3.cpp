//Ejercicio 3

#include <iostream>
using namespace std;



int main()
{   long long n=600851475143;
    for(int i=2;i<n;i++){
        while(n%i==0)
            n/=i;

    }
    cout<<n;
    return 0;
}
