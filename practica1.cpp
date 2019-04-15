#include <iostream >

// **********************************PRACTICA Nª 01*****************************************************
using namespace std;

//CONSTANTES

# define PI 3.14159
# define NEWLINE '\n'

int main ()
{
    double r = 5.0;
    double circle ;

    circle = 2 * PI * r; // circle = 2 * 3.14159 * r;
    cout << circle << NEWLINE ; // cout << circle << ’\n ’;

    return 0;
}

//////////////////////////////////////////////////////////////

int main()
{
    const int pathwidth = 100;
    // pathwidth = 2; this will cause a compiler error !
    const char tabulator = '\t';
    cout << " tabulator =" << tabulator << '\n';
}
//////////////////////////////////////////////////////////////
//INCREMENT,DECREMENT OPERATORS (++, --)

int main(){
    // this code outputs 0 to 9
    for(int i = 0; i < 10;)
    {
        cout << i++ << "\n";
    }
    cout<<'\n';
    // this code outputs 1 to 10
    for(int i = 0; i < 10;)
    {
        cout << ++i << "\n";
    }
}
////////////////////////////////////////////////////////////
//TYPE CONVERSIONS

int main(){
    int x = (int) 5.0; // float should be explicitly " cast " to int
    short s = 3;
    long l = s; // does not need explicit cast , but
    // long l = ( long )s is also valid
    float y = s + 3.4; // compiler implicitly converts s
    // to float for addition
}
/////////////////////////////////////////////////////////////
//SWITCH

int main (){
    int n=6;
    switch (n) {

        case 0:
            cout << "You typed zero .\n";
            break ;
        case 1:
        case 4:
        case 9:
            cout << "n is a perfect square .\n";
            break ;
        case 2:
            cout << "n is an even number .\n";
        case 3:
        case 5:
        case 7:
            cout << "n is a prime number .\n";
            break ;
        case 6:
        case 8:
            cout << "n is an even number .\n";//numero par
            break ;
        default :
            cout << " Only single - digit positive numbers are allowed .\n";
            break ;
    }
}
////////////////////////////////////////////////////////////////////////////
//BREAK

// outputs first 10 positive integers
int main(){
 int i = 1;
 while ( true )
 {
    if(i > 10)
        break ;
    cout << i << "\n";
    ++i;
 }
}
///////////////////////////////////////////////////////////////////////////
//CONTINUE

// print out even numbers in
int main(){
    for(int i = 0; i <= 10; ++i)
    {
        if(i % 2 != 0)
            continue ; // skips all odd numbers
        cout << i << "\n";
    }
}
//////////////////////////////////////////////////////////////////////////
//HOLA MUNDO 2.1

int main ()
{
    const char * str =" Hello , World ! ";
    cout << str << " \n ";
    return 0;
}
////////////////////////////////////////////////////////////////////////////
//HOLA MUNDO 2.2

//FOR
int main ()
{
    int N ;
    cin >> N ;
    for (; N-- > 0;)
    {
        cout << " Hello , World !\n ";
    }
    return 0;
}
//////////////////////////////////////////////////////////////////////////
//WHILE

int main ()
{
    int N ;
    cin >> N ;
    while (N-- > 0)
    {
        cout << " Hello , World !\n ";
    }
    return 0;
}
/////////////////////////////////////////////////////////////////////////
//DO WHILE

int main ()
{
    int N;
    cin >> N;
    do
    {
        cout << "Hello , World !\n ";
    }while (- - N > 0);
    return 0;
}
///////////////////////////////////////////////////////////////////////////
//SCOPE 1

int main ()
{
    int arg1 ;
    arg1 = -1;
    int x, y, z;
    char myDouble = '5';
    char arg1 = 'A';//error CONFLICTING DECLARATION 'CHAR ARG1' ,PREVIOUS DECLARATION AS 'INT ARG1'
    cout << arg1 << "\n";
    return 0;
}
////////////////////////////////////////////////////////////////////////
//SCOPE 2

int main ()
{
  int arg1 ;
  arg1 = -1;
   {
    char arg1 = 'A';
    cout << arg1 << "\n";//imprime 'A'

   }
   return 0;
}
///////////////////////////////////////////////////////////////////////////
//SCOPE 3

int main ()
{
  int arg1 ;
  arg1 = -1;
   {
    char arg1 = 'A';
    cout << arg1 << "\n";//imprime 'A' ,char
   }
   return 0;
}
///////////////////////////////////////////////////////////////////////////
//SCOPE 4

int main ()
{
   int arg1 ;
   arg1 = -1;
   {
    char arg1 = 'A';
   }
   cout << arg1 << "\n";// imprime -1
   return 0;
}
///////////////////////////////////////////////////////////////////////////
//SCOPE 5

# include <iostream > // esta linea se tuvo que mover ya que estuvo al final

int main ()
{
    cout << "Hello , World !\n";
    return 0;
}
/////////////////////////////////////////////////////////////////////////////
//3.2

int main ()
 {
    int N ;
    cout << " Enter N : ";
    cin >> N ;
    int acc = 0;

    // handle the first number separately
    cin >> acc ;
    int minVal = acc ;
    int maxVal = acc ;

    // then process the rest of the input
    for(int i = 1; i < N ; ++ i )
    {
        int a;
        cin >> a ;
        acc += a ;
        if(a < minVal )
        {
            minVal = a ;
        }
        if(a > maxVal )
        {

            maxVal = a ;
        }
    }

    cout << " Mean : " << ( double ) acc / N << " \n ";
    cout << " Max : " << maxVal << " \n ";
    cout << " Min : " << minVal << " \4n ";
    cout << " Range : " << ( maxVal - minVal ) << " \n ";

    return 0;
 }
///////////////////////////////////////////////////////////////
//3.3 NUMEROS PRIMOS

int main ()
{
    int N ;//genera el numero de primos que usted desee
    cin >> N ;
    for(int i = 2; N > 0; ++ i )
    {
        bool isPrime = true ;
        for (int j = 2; j < i ; ++ j )
        {
            if(i % j == 0)
            {
                isPrime = false ;
                break ;
            }
        }
        if( isPrime )
        {
            --N ;
            cout << i << " \n ";
        }
    }
    return 0;
}
///////////////////////////////////////////////////////
//3.4 MULTIPLOS DE NUMEROS

//3.4.1 TERNARY OPERATOR

int main ()
{
    while (1)//si es multiplo de 5 muetra el numero entre 5
    {
        int N ;
        cin >> N ;
        cout << (( N % 5 == 0 && N >= 0) ? N /5 : -1) << " \n ";
    }
    return 0;
}
/////////////////////////////////////////////////////////////////
//3.4.2 CONTINUE

int main ()//si es multiplo de 5 lo divide entre 5 y si no bota -1
{
    while (1)//como tiene continue el bucle es infinito
    {
        int N ;
        cin >> N ;
        if( N % 5 > 0)
        {
            cout << " -1\n ";
            continue ;
        }
        cout << N /5 << " \n ";
    }
    return 0;
}
//////////////////////////////////////////////////////////////////////
//3.4.3 BREAK

int main ()
{
    while (1)
    {
        int N ;
        cin >> N ;
        if( N % 5 > 0)
        {
            cout << " -1\n ";
            continue ;
        }
        if( N == -1)
        {
            break ;
        }
        cout << N/5 << "\n ";
    }
    cout << " Goodbye !\n";
    return 0;
}
///////////////////////////////////////////////////////////////
//3.5
//1.

int main(){
    int dole=1,bob=2;
    int accumulator = 0;
    while ( true )
    {
        if( dole == 0) break ;
        accumulator += (( dole % 2 == 1) ? bob : 0);
        dole /= 2;
        bob *= 2;
    }
    cout << accumulator << "\n";//2
}
////////////////////////////////////////////////////////////////
//2.

# define O 1 // That ’s an oh , not a zero
int main ()
{
  return O;//retorna 1
}
///////////////////////////////////////////////////////////////
//3.

int main(){
// N is a nonnegative integer
    int N=2;
    double acc = 0;
    for(int i = 1; i <= N; ++i)
    {
        double term = (1.0/ i);
        acc += term * term ;
        for (int j = 1; j < i; ++j)
        {
            acc *= -1;
        }
    }
    cout << acc << "\n";//imprime 0
}
///////////////////////////////////////////////////////////////

//4.1 Writing the factorial program

int main ()
{
 short number ; // solo hasta el numero 12 saca el factorial
 cout << " Enter a number : ";
 cin >> number ;

 cout << "The factorial of " << number << " is ";
 int accumulator = 1;
 for (; number > 0; accumulator *= number --);
 cout << accumulator << ".\n";

 return 0;
}
///////////////////////////////////////////////////////////////

//4.4 REWRINTING FACTORIAL I

long long accumulator = 1;//solo hasta 20 saca bien el factorial

int main ()
{
    int number ;
    cout << " Enter a number : ";
    cin >> number ;
    int aux=number;
    if( number < 0)
    {
        cout << " No negative numbers allowed !\n ";
        return 1;
    }
    if( number > 20)
    {
        cout << " Program will not produce correct result !\n ";
    }
    for (; number > 0; accumulator *= number --) ;
    cout << " The factorial of " << aux << " is " << accumulator<< " .\n ";
    return 0;
}
////////////////////////////////////////////////////////////////////////////////
//4.5 REWRITING FACTORIAL II

int main ()
{
    int number ;
    cout << " Enter a number : ";
    cin >> number ;
    switch ( number )
    {
        case 0:
        case 1:
            cout << "1\n";
            break ;
        case 2:
            cout << "2\n";
            break ;
        case 3:
            cout << "6\n";
            break ;
        case 4:
            cout << "24\ n";
            break ;
        case 5:
            cout << " 120\ n";
            break ;
        case 6:
            cout << " 720\ n";
            break ;
        case 7:
            cout << " 5040\ n";
            break ;
        case 8:
            cout << " 40320\ n ";
            break ;
        case 9:
            cout << " 362880\ n ";
            break ;
        case 10:
            cout << " 3628800\ n ";
            break ;
        default :
            cout << " Input not supported !\n ";
            break ;
    }
    return 0;
}
////////////////////////////////////////////////////////////////////////
