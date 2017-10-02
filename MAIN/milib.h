#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <stdlib.h>
#include <string.h>

#define ANCHO 640
#define ALTO 360
#define FPS 60
#define FPS_2 10   // usado en seleccion de personajes
#define FPS_3 10   // usado en seleccion de personajes

enum {jugador1,jugador2,enemigo};
enum {Vegeta,Goku,Frezeer,Bills}; 


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


struct player{
	int ID;
	int x;
	int y;
	int lives;
	int speed;
	int boundx;
	int boundy;
	int score;
	};

int crear_timer(ALLEGRO_TIMER **,const float);
int init_al(void);
int crear_evento(ALLEGRO_EVENT_QUEUE **);
int crear_display(ALLEGRO_DISPLAY **,int,int);
int SELECCION_DE_PERSONAJES(ALLEGRO_DISPLAY *);
int MENU(ALLEGRO_MOUSE_STATE * ,struct color *,struct color *,struct color *);
void free_image(ALLEGRO_BITMAP **, const int);  // segundo argumento recibe la cantidad de cuadros a liberar ==> "maxFrame"
int game_play(ALLEGRO_DISPLAY **);// este "const int " define que personaje se va a usar. ""enum PJ{Vegeta=0,Goku=1,Frezeer=2,Bills=3};""  
void Move_player_Up(struct player *);
void Move_player_Down(struct player *);
void Move_player_Left(struct player *);
void Move_player_Right(struct player *);
void Draw_player(struct player *);// este "const int " define que personaje se va a usar. ""enum PJ{Vegeta=0,Goku=1,Frezeer=2,Bills=3};""
void Init_player1(struct player *); 
void Init_player2(struct player *); 
void load_image(const int,ALLEGRO_BITMAP **,ALLEGRO_BITMAP **);
