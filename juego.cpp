#include "juego.h"

juego::juego(Vector2i dimension, std::string titulo )
{
    fps=60;//frames por segundo

    ventana1 = new RenderWindow(VideoMode(dimension.x,dimension.y),titulo);//se crea la ventana
    
    ventana1->setFramerateLimit(fps);//se establece la velocidad

    ventana1->setMouseCursorVisible(false);//para no hacer visible el cursor de nuestro mouse

    reloj1 = new Clock();//creamo un reloj

    tiempo1 = new Time();//creamos el tiempo1

    tiempo2=0;//variable float tiempo
    
    textura1 = new Texture;//se crea la textura para el CEMENTERIO
    sprite1 = new Sprite;//se crea el sprite para el CEMENTERIO

    textura1->loadFromFile("cementerio.jpg");//se carga el documento en formato CEMENTERIO.JPG
    sprite1->setTexture(*textura1);//el sprite1 toma la textura del CEMENTERIO
    //sprite2 = new Sprite;

    //sprite2->setTexture(*textura1);

    //sprite2->setPosition(400, 300);
    
    //sprite2->setOrigin(sprite2->getTexture()->getSize().x/2.f,sprite2->getTexture()->getSize().y/2.f);

    //sprite2->setColor(Color::Cyan);

    //sprite1->setScale(((float)ventana1->getSize().x/sprite1->getTexture()->getSize().x),((float)ventana1->getSize().y/sprite1->getTexture()->getSize().y));
    
    Color color_1(255,255,255);//R,G,B,A  R=red G=green B=blue A=alpha transparencia u opacidad

    textura2 = new Texture;//se crea la textura para el PERSONAJE(zombie)
    sprite2 = new Sprite;//se crea el sprite para el PERSONAJE(zombie)

    textura2->loadFromFile("zombie1.png");//se carga el documento en formato ZOMBIE.PNG
    sprite2->setTexture(*textura2);//el sprite2 toma la textura del ZOMBIE

    sprite2->setScale(215.f/sprite2->getTexture()->getSize().x,260.f/sprite2->getTexture()->getSize().y);//la dimension deseada o tamaño deseado dividido tamaño actual
    //lo de arriba es para modificar el tamaño del PERSONAJE(zombie)
    textura3 = new Texture;//se crea la textura para la SANGRE
    sprite3 = new Sprite;//se crea OTRO sprite para el PERSONAJE(zombie)

    textura3->loadFromFile("sangre.png");//se carga el documento de la SANGRE.PNG
    sprite3->setTexture(*textura2);//el sprite toma la textura del ZOMBIE
    sprite3->setScale(215.f/sprite3->getTexture()->getSize().x,260.f/sprite3->getTexture()->getSize().y);//la dimension deseada o tamaño deseado dividido tamaño actual
    //sprite3->setColor(Color::Blue);//el personaje del sprite 3 toma el color azul
    sprite3->setPosition(0,460);//se ubica el PERSONAJE enel centro de la pantalla
    
    txt_mira.loadFromFile("mira.png");
	spr_mira.setTexture(txt_mira);

    evento1=new Event;//se crea Evento

    caja1 = new RectangleShape({64,64});//se crea un rectangulo de 64x64
    caja1->setFillColor(Color::Green);// se pone el rectangulo de color azul
    caja1->setPosition(300,300);//se ubica el rectangulo en el 300 por 300
    caja1->setTexture(textura3);//el rectangulo toma la textura 3 que es la SANGRE
   

    gameloop();
}
void juego :: dibujar()//para que se muestre en pantalla
{
    ventana1->clear(Color::Black);//paralimpiar pantalla
     
    ventana1->draw(*sprite1); //para dibujar el CEMENTERIO

    ventana1->draw(*sprite2);//para dibujar el PERSONAJE

    ventana1->draw(*sprite3);//para dibujar el segundo PERSONAJE

    //ventana1->draw(*caja1);//para dibujarse la SANGRE

    //ventana1->draw(*sprite2);

    ventana1->draw(spr_mira);//para dibujar la mira

    ventana1->display();//para mostrar
}
void juego :: gameloop()
{
    while(ventana1->isOpen())
    {   /* 
        *tiempo1 = reloj1->getElapsedTime();//tiempo1 obtine el tiempo del reloj
        
        if(tiempo1->asSeconds() > 1/fps)// tiempo1 se convierte a segundos y se compara 
        {
            tiempo2 += 0.5;//vade 5 en 5
            if(tiempo2 > 5)
            {
                sprite2->rotate(10);//rota 10 grados por cada iteracion
                tiempo2=0;//y se restaura el tiempo2 en cero
            }
            // sprite2->setRotation(sprite2->getRotation()+3);
            procesar_mouse();
            procesar_eventos();
            procesar_colisiones();
            dibujar();
            reloj1->restart();//se restaura el reloj
            
        }
        */
            procesar_eventos();
            dibujar();
    }

}
void juego :: procesar_eventos()
{
    while(ventana1->pollEvent(*evento1))
    {
        switch (evento1->type)
        {
        case Event::MouseMoved:
			//a nuestra mira le pasa la posicion
			spr_mira.setPosition((Vector2f)Mouse::getPosition(*ventana1));
			break;
        case Event::Closed:
            ventana1->close();//para que se pueda cerrar y mover la ventana
            exit(1);
            break;
        case Event::KeyPressed:
            if(Keyboard::isKeyPressed(Keyboard::Up))//para que el personaje camine para arriba
            {
                sprite2->setPosition(sprite2->getPosition().x,sprite2->getPosition().y-2);
            }
            else if(Keyboard::isKeyPressed(Keyboard::Down))//paraque el personaje camine para abajo
            {
                sprite2->setPosition(sprite2->getPosition().x,sprite2->getPosition().y+2);
            }
            else if(Keyboard::isKeyPressed(Keyboard::Right))//paraque el personaje camine para derecha
            {
                sprite2->setPosition(sprite2->getPosition().x+2,sprite2->getPosition().y);
            }
            else if(Keyboard::isKeyPressed(Keyboard::Left))//paraque el personaje camine para izquierda
            {
                sprite2->setPosition(sprite2->getPosition().x-2,sprite2->getPosition().y);
            }
            break;
        
        case Event::MouseButtonPressed:
            if(Mouse::isButtonPressed(Mouse::Left))//cada vez q se preione el boton izquierdo del mouse
            {
                /* 
                if(posicion_mouse == (Vector2i)sprite1->getPosition())
                {
                    sprite1->setColor(Color::Red);
                }
                */
               //sprite1->setPosition(Vector2f(posicion_mouse));
            }
            break;
        }
    }
}
/* 
void juego ::procesar_mouse()
{
    posicion_mouse = Mouse::getPosition(*ventana1);

    posicion_mouse = (Vector2i)ventana1->mapPixelToCoords(posicion_mouse);
}
void juego :: procesar_colisiones()
{
    FloatRect posicion_del_mouse(Vector2f(posicion_mouse),{32,32});
    if(sprite2->getGlobalBounds().intersects(posicion_del_mouse))//cada vez que el mouse choque con el PERSONAJE este se va a mover con el mouse
    {
        sprite2->setPosition(Vector2f(posicion_mouse));
    }

    //colision personaje con mostruo azul

    if(sprite2->getGlobalBounds().intersects(sprite3->getGlobalBounds()))
    {
        sprite3->rotate(3);//cada ves que los personajes ZOMBIE choquen el PERSONAJE AZUL rotara
    }
}
*/
juego :: ~juego()//destructor
{
    delete ventana1;

    delete textura1;

    delete sprite1;

    //delete sprite2;
    
    delete textura2;

    delete sprite2;

    delete textura3;

    delete sprite3;

    delete caja1;

    delete tiempo1;

    delete reloj1;

    delete evento1;

}
