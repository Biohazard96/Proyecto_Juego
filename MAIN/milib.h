#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <stdlib.h>
#include <string.h>

#define ANCHO 640
#define ALTO 360
#define FPS 60

struct color{
	int RED;
	int GREEN;
	int BLUE;
	};





int crear_timer(ALLEGRO_TIMER **,const float);
int init_al(void);
int crear_evento(ALLEGRO_EVENT_QUEUE **);
int crear_display(ALLEGRO_DISPLAY **,int,int);
int SELECCION_DE_PERSONAJES(ALLEGRO_DISPLAY *,ALLEGRO_MOUSE_STATE *);
int MENU(ALLEGRO_MOUSE_STATE * ,struct color *,struct color *,struct color *);
