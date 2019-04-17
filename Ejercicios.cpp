#include <iostream>
#include <cmath>

using namespace std;

//Ejercicio 2

int main()
{
    int x=1,y=2,aux=0,s=0;
    bool a=true;
    for (int i=0;a!=false;i++){
        if(y%2==0)
            s=s+y;
        aux=x+y;
        x=y;
        y=aux;
        if (y>4000000)
            a=false;
    }

    cout<<s;

    return 0;
}

//Ejercicio 5

int main()
{
   bool b=true;
   for(int j=20;b==true;j++){
       int acc=0;
       for(int i=1;i<=20;i++){
           if(j%i==0)
                acc++;
       }
       if(acc==20){
           b=false;
           cout<<j;
       }
    }
    return 0;
}

//Ejercicio 7

int main()
{
   int cantpri=0,b,contdiv;
   bool a=true;
   for(int i=2;a==true;i++){
       contdiv=0;
       if(cantpri<10001){
           for(int j=1;j<=i;j++){
               if(i%j==0)
                    contdiv+=1;
           }
           if(contdiv == 2){
               b=i;
               cantpri+=1;
           }
       }
       else
            a=false;
    }
    cout<<b;
    return 0;
}

//Ejercicio 4

bool palindromo (int);

int main()
{
    int m=0,a=0;
    for(int i=100;i<1000;i++){
        for(int j=100;j<1000;j++){
            m=i*j;
            if (palindromo(m)==true){
                if(a<m)
                    a=m;
            }

        }
    }
    cout<<a;
    return 0;
}

bool palindromo(int a)
{
        int u,d,c,m,m1,m2;
        if (a>99999 && a<1000000){
            u=a%10;
            d=(a%100)/10;
            c=(a%1000)/100;
            m=(a%10000)/1000;
            m1=(a%100000)/10000;
            m2=a/100000;
            if(u==m2 && d==m1 && c==m ){
                    return true;
            }
            else
                return false;
        }
        if (a>9999 && a<100000){
            u=a%10;
            d=(a%100)/10;
            m=(a/10000)/1000;
            m1=(a/10000);
            if(u==d && m==m1)
                return true;
            else
                return false;
        }

}


//Ejercicio 3

bool primo (int);
int main()
{   int a=0;
    for(int i=1;i<13195;i++){
        if(13195%i==0){
            if (primo(i)==true){
                a=i;
            }
        }
    }
    cout<<a;
    return 0;
}

bool primo (int b){
    for(int j=2;j<=b/2;j++){
        if(b%j==0)
            return false;
    }
    return true;

}


//Ejercicio 10

bool primo (int);
int main()
{   int s=0;
    for(long long i=2;i<10;i++){
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

