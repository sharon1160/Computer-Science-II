#include "SFML/Graphics.hpp"
#include "juego.h" 

using namespace sf;

using namespace std;

int main(int argc,char * args[])
{   
    Vector2i dimension;//vector de dos enteros que guardaran el largo y el ancho de la pantalla

    dimension.x=1366;//para el tamaño
    dimension.y=768;//de la pantalla

    juego* partida1;//se crea dinamicamente un objeto de clase JUEGO
    partida1 = new juego(dimension,"Mi juego");//creamos con el new pasamos la dimension y el nombre de nuestro juego

    delete partida1;//liberamos memoria borrando el objeto Juego llamado partida1
    return 0;
}