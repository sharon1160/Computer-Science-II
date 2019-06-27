#pragma once 
#include "SFML/Graphics.hpp"
#include <iostream>

using namespace sf;

using namespace std;

class juego
{
    public:
        juego(Vector2i dimension,std::string titulo);
        void dibujar();
        void gameloop();
        void procesar_eventos();
        //void procesar_mouse();
        //void procesar_colisiones();
        ~juego();
    private:
        RenderWindow * ventana1;//para crear la ventana
        int fps;
        Texture * textura1;//textura del fonde CEMENTERIO.JPG
        Sprite * sprite1;// el sprite del fodo CEMENTERIO.JPG
        //Sprite * sprite2;

        Texture * textura2;//textura del PERSONAJE
        Sprite *sprite2;//sprite del PESONAJE

        Texture * textura3;//textura de la MANCHA DE SANGRE
        Sprite * sprite3;//Otro sprite del PERSONAJE(azul)

        Texture txt_mira;//textura de la mira del arma
		Sprite spr_mira;//sprite de la mira del arma

        Event * evento1;//para que se den los eventos(para cerrar ventana, para que camine el personaje)

        Vector2i posicion_mouse;//para las coordenadas del mouse

        RectangleShape * caja1;//para crear la figura del rectangulo

        Clock * reloj1;//un reloj
        Time * tiempo1;//variable tiempo1
    
        float tiempo2;//variable tiempo
        
};