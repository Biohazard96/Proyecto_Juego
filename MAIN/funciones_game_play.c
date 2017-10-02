#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <stdlib.h>
#include <string.h>
#include "milib.h"

void Init_player1(struct player * aux)
	{
	aux->x = 100;
	aux->y = 260;
	aux->ID = jugador1; // equivale a 0
	aux->lives =3;
	aux->speed = 7;
	aux->boundx =6;
	aux->boundy =7;
	aux->score =0;
	}
void Init_player2(struct player * aux)
	{
	aux->x = 500;
	aux->y = 260;
	aux->ID = jugador1; // equivale a 0
	aux->lives =3;
	aux->speed = 10;
	aux->boundx =6;
	aux->boundy =7;
	aux->score =0;
	}

void Move_player_Up(struct player * aux)
	{
	aux->y-= aux->speed;
	if(aux->y < 0) aux->y=0;
	}
void Move_player_Down(struct player * aux)
	{
	aux->y+= aux->speed;
	if(aux->y > 260) aux->y=260;
	}
void Move_player_Left(struct player * aux)
	{
	aux->x-= aux->speed;
	if(aux->x < 0) aux->x=0;		
	}
void Move_player_Right(struct player * aux)
	{
	aux->x+= aux->speed;
	if(aux->x > ANCHO-40) aux->x=ANCHO-40;
	}
void Draw_player(struct player * aux)// este "const int " define que personaje se va a usar. ""enum PJ{Vegeta=0,Goku=1,Frezeer=2,Bills=3};""
	{


return ;
	}

void load_image(const int J1, ALLEGRO_BITMAP ** MOVIMIENTO,ALLEGRO_BITMAP ** ESTATICO)
	{
		switch(J1)
			{
				case Vegeta:
					*MOVIMIENTO = al_load_bitmap ("./sprites/8.png");
					*ESTATICO = al_load_bitmap ("./sprites/vegeta1.png");
						break;
				case Goku:
					*MOVIMIENTO = al_load_bitmap ("./sprites/21.png");
					*ESTATICO = al_load_bitmap ("./sprites/goku2.png");
						break;
				case Frezeer:
					*MOVIMIENTO = al_load_bitmap ("./sprites/12.png");
					*ESTATICO = al_load_bitmap ("./sprites/freezer1.png");
						break;
				case Bills:
						break;																		
			}
	}
