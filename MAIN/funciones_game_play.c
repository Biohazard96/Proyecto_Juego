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
	aux->life =100;
	aux->speed = 15;
	aux->boundx =6;
	aux->boundy =7;
	aux->score =0;
	}
void Init_player2(struct player * aux)
	{
	aux->x = 500;
	aux->y = 260;
	aux->ID = jugador2; // equivale a 1
	aux->life =100;
	aux->speed = 15;
	aux->boundx =6;
	aux->boundy =7;
	aux->score =0;
	}

void Move_player_Up(struct player * aux)
	{
	aux->y-= aux->speed;
	if(aux->y < 100) aux->y=100;
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

void load_Move(const int J, ALLEGRO_BITMAP ** MOVIMIENTO , ALLEGRO_BITMAP ** ESTATICO , ALLEGRO_BITMAP ** VUELO, ALLEGRO_BITMAP ** BAJAR,ALLEGRO_BITMAP **RETRATO)
	{
		switch(J)
			{
				case Vegeta:
					*MOVIMIENTO = al_load_bitmap ("./sprites/8.png");
					*ESTATICO = al_load_bitmap ("./sprites/vegeta1.png");
					*VUELO = al_load_bitmap ("./sprites/17.png");
					*BAJAR = al_load_bitmap ("./sprites/84.png");
					*RETRATO = al_load_bitmap("./retratos/vegeta_retrato.png");
						break;
				case Goku:
					*MOVIMIENTO = al_load_bitmap ("./sprites/21.png");
					*ESTATICO = al_load_bitmap ("./sprites/goku2.png");
					*VUELO = al_load_bitmap ("./sprites/15.png");
					*BAJAR = al_load_bitmap ("./sprites/73.png");
					*RETRATO = al_load_bitmap("./retratos/Goku_blue.png");
						break;
				case Frezeer:
					*MOVIMIENTO = al_load_bitmap ("./sprites/12.png");
					*ESTATICO = al_load_bitmap("./sprites/frezeer1.png");
					*VUELO = al_load_bitmap("./sprites/121.png");
					*BAJAR = al_load_bitmap ("./sprites/120.png");
					*RETRATO = al_load_bitmap("./retratos/freezer_retrato2.png");
						break;
				case Bills:
					*MOVIMIENTO = al_load_bitmap ("./sprites/b3.bmp");
					*ESTATICO = al_load_bitmap ("./sprites/b1.bmp");
					*VUELO = al_load_bitmap ("./sprites/b2.bmp");
					*BAJAR = al_load_bitmap ("./sprites/b7.bmp");					
					*RETRATO = al_load_bitmap("./retratos/bills_retrato.png");
					al_convert_mask_to_alpha(*MOVIMIENTO,al_map_rgb(107,204,48));
					al_convert_mask_to_alpha(*ESTATICO,al_map_rgb(107,204,48));
					al_convert_mask_to_alpha(*VUELO,al_map_rgb(107,204,48));
					al_convert_mask_to_alpha(*BAJAR,al_map_rgb(107,204,48));
						break;																		
			}
	}
	
void load_Attack(const int J, ALLEGRO_BITMAP ** MOV_KEY_PUNCH)
	{
				switch(J)
			{
				case Vegeta:
					*MOV_KEY_PUNCH = al_load_bitmap ("./sprites/28.png");
						break;
				case Goku:
					*MOV_KEY_PUNCH = al_load_bitmap ("./sprites/31.png");
						break;
				case Frezeer:
					*MOV_KEY_PUNCH = al_load_bitmap("./sprites/30.png");
						break;
				case Bills:
					*MOV_KEY_PUNCH = al_load_bitmap ("./sprites/b16.bmp");					
					al_convert_mask_to_alpha(*MOV_KEY_PUNCH,al_map_rgb(107,204,48));
						break;
			}
	}
