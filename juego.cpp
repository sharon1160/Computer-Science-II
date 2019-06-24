#include"juego.h"

#include <iostream>
#include <string>

using namespace std;

Juego::Juego(Vector2f resolucion, string titulo){//Constructor de la clase Juego 
	game_over=false;
	fps =60;
	vidas=3;//numero de vidas 
	ventana1=new RenderWindow(VideoMode(resolucion.x,resolucion.y),titulo);//esto es para abrir una ventana para el juego
	ventana1->setFramerateLimit(fps);
	//Hacer que no se vea la flecha 
	ventana1->setMouseCursorVisible(false);
	
	for(int i=0;i<4;i++){
		slots_monsters[i]=false;
	}
	
	evento1=new Event;
	
	cargar_graficos();
	
	reloj1=new Clock;
	tiempo1=new Time;
	tiempo2=0;

	game_loop();
	
}

void Juego::game_loop(){//la funcion game_loop
	
	while(!game_over){
		*tiempo1=reloj1->getElapsedTime();
		
		if(tiempo1->asSeconds()>5+ tiempo2)
		{
			tiempo2=tiempo1->asSeconds();
			int resultado;
			resultado =rand()%100+1;

			if(resultado<30){
				//no creamos monstruo
			}
			else
			{	
				bool espacio_disponible= false;
				for(int i=0;i<4;i++)
				{
					if(!slots_monsters[i])
					{
					       espacio_disponible = true;
						   break;
					}
				}
				if(espacio_disponible)
				{
					while (1)
					{
						int resultado = rand() % 3 + 0;

						if (!slots_monsters[resultado])
						{
							monsters[resultado]= new Enemigo({(float)(200.0*resultado),300.0});
							break;
						}
						
					}
				}
			}
		}
		chequear_enemigos();
		
		ventana1->clear();//para limpiar la pantalla en cada vuelta

		procesar_eventos();

		ventana1->draw(spr_fondo);
		/*
		for(int i=0; i<4;i++)
		{
			if (monsters[i] != NULL)
			{
				ventana1->draw(monsters[i]->get_sprite());
			}
		}
		*/
		ventana1->draw(spr_mira);
		

		ventana1->display();

		if(vidas <1)
		{
			game_over=true;
		}
	}
}

void Juego::cargar_graficos(){

	

	txt_fondo.loadFromFile("cementerio.jpg");
	spr_fondo.setTexture(txt_fondo);
    spr_fondo.setScale((float)ventana1->getSize().x/txt_fondo.getSize().x,(float)ventana1->getSize().y/txt_fondo.getSize().y);

	txt_mira.loadFromFile("mira.png");
	spr_mira.setTexture(txt_mira);		
	
	
}
/*
void Juego::dibujar(){
	
	ventana1->draw(spr_fondo);
	for(int i=0;i<4;i++){
		if (monsters[i]!=NULL){
		    ventana1->draw(monsters[i]->get_sprite());
		}
	}
	ventana1->draw(spr_mira);
}
*/

void Juego::procesar_eventos(){
	
	while(ventana1->pollEvent(*evento1))
	{
		switch(evento1->type)
		{
			case Event::MouseMoved:
				//a nuestra mira le pasa la posicion
				spr_mira.setPosition((Vector2f)Mouse::getPosition(*ventana1));
				break;
			//Poder cerrar las ventanas
			case Event::Closed:
			exit(1);
			break; 

			case Event::MouseButtonPressed:

				FloatRect recta (spr_mira.getPosition(), (Vector2f)spr_mira.getTexture()->getSize());
				for(int i=0; i<4;i++)
				{
					if(monsters[i])
					{
						if (monsters[i]->get_sprite().getGlobalBounds().intersects(recta));
						{
							monsters[i]=NULL;
						}
					}
				}

				break;
			
		}
	}
}

void Juego :: chequear_enemigos()
{
	for(int i=0;i<4;i++) 
	{
		/*
		if(monsters[i])
		{
			if(monsters[i]->get_seconds()>5)
			{
				monsters[i] = NULL;
				vidas--;
			}
		}
		*/
	}
}
