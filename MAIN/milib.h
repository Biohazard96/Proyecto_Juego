#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <stdlib.h>
#include <string.h>

#define ANCHO 640
#define ALTO 360
#define FPS 60
#define FPS_2 10   // usado en seleccion de personajes

struct color{     
	int RED;
	int GREEN;
	int BLUE;
	};

struct frames{ // USADO PARA MANEJAR SPRITES
	const int maxFrame ; // maximo de cuadros que tendra una animacion de sprite. CANTIDAD DE IMAGENES
	int curFrame ;    // contador 
	int frameCount ;  // contador de cuadros
	int frameDelay ; // retraso que tendra la animacion luego de completar su ciclo, si es cercano al "cero" va mas rapido. Tambien varia de los FPS 
};


int crear_timer(ALLEGRO_TIMER **,const float);
int init_al(void);
int crear_evento(ALLEGRO_EVENT_QUEUE **);
int crear_display(ALLEGRO_DISPLAY **,int,int);
int SELECCION_DE_PERSONAJES(ALLEGRO_DISPLAY *);
int MENU(ALLEGRO_MOUSE_STATE * ,struct color *,struct color *,struct color *);
void free_image(ALLEGRO_BITMAP **, const int);  // segundo argumento recibe la cantidad de cuadros a liberar ==> "maxFrame"
//void game_play(ALLEGRO_DISPLAY ***,xxxxxxxxxx);
