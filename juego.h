#include <SFML/Graphics.hpp>

#include "enemigo.h"

using namespace sf;
using namespace std;

class Juego{	
	public:
		Juego(Vector2f resolucion, string titulo);
		void game_loop();//creamos un loop para mantener abierta la instancia del juego
		void cargar_graficos();//para cargar los sprites
		void procesar_eventos();
		void chequear_enemigos();
	private:

		RenderWindow *ventana1;

		int vidas;
		
		//Sprites
		

		Texture txt_fondo;//textura del fondo 
		Sprite spr_fondo;//sprite del fondo
		
		Texture txt_mira;//textura de la mira del arma
		Sprite spr_mira;//sprite de la mira del arma
		
		Event *evento1;
		
		Enemigo *monsters[4];//creamos un arreglo de 4  objetos de clase Enemigo
		
		Clock *reloj1;
		Time  *tiempo1;
		float tiempo2;

		bool game_over;
		
		//Dividir la pantalla en 4;
		bool slots_monsters[4];
		
		int fps;
	
		
};