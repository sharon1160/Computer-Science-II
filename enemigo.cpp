#include"enemigo.h"

#include<stdlib.h>

using namespace std;

Enemigo::Enemigo(Vector2f posicion)
{
	int numero_enemigo;
	numero_enemigo =rand()% 3 + 1;

	string path;

	path= "monster" + to_string(numero_enemigo)+ ".png";
    txt_monster.loadFromFile(path);
	spr_monster.setTexture(txt_monster);

	spr_monster.setPosition(posicion);

	reloj1 = new Clock;
	tiempo1 = new Time;
	*tiempo1 =reloj1->getElapsedTime();

}

Sprite Enemigo::get_sprite(){
	return spr_monster;
}

float Enemigo::get_seconds()
{
	*tiempo1 = reloj1->getElapsedTime();

	return tiempo1->asSeconds();
}