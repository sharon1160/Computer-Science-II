#pragma once 
#include <SFML/Graphics.hpp>

#include <stdlib.h>
using namespace sf;
using namespace std;


class Enemigo {
	public:
		
		Enemigo(Vector2f posicion);
		Sprite get_sprite();
		float get_seconds();
		
	private:
		Texture txt_monster;
		Sprite spr_monster;

		Clock * reloj1;
		Time * tiempo1;
	
};
