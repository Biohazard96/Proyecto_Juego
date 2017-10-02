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

enum KEYS_PLAYER1{W,S,A,D,F,G,C,V}; //{arriba,abajo,izquierda,derecha,piña,patada,poder,poder}
enum KEYS_PLAYER2{UP,DOWN,LEFT,RIGHT,O,P,K,L}; //{arriba,abajo,izquierda,derecha,piña,patada,poder,poder}
bool keys_player1[8]={false,false,false,false,false,false,false,false};
bool keys_player2[8]={false,false,false,false,false,false,false,false};

int game_play(ALLEGRO_DISPLAY ** display,const int J1,const int J2){
	
   struct player player1;
   struct player player2;
   
   ALLEGRO_BITMAP *image=NULL;
   ALLEGRO_BITMAP *RETRATO_J1 = NULL;	
   ALLEGRO_BITMAP *RETRATO_J2 = NULL;
   ALLEGRO_BITMAP *VUELO_J1 = NULL;
   ALLEGRO_BITMAP *VUELO_J2 = NULL;
   ALLEGRO_BITMAP *BAJAR_J1 = NULL;
   ALLEGRO_BITMAP *BAJAR_J2 = NULL;
   ALLEGRO_BITMAP * MOVIMIENTO_J1 = NULL;
   ALLEGRO_BITMAP * ESTATICO_J1 = NULL;
   ALLEGRO_BITMAP * MOVIMIENTO_J2 = NULL;
   ALLEGRO_BITMAP * ESTATICO_J2 = NULL;
   ALLEGRO_BITMAP * MOV_KEY_F_J1=NULL;  //imagenes del movimiento efectuado al apretar la tecla "F"
   ALLEGRO_BITMAP * MOV_KEY_O_J2=NULL;  //imagenes del movimiento efectuado al apretar la tecla "O"
   
   ALLEGRO_FONT *font = NULL;
   ALLEGRO_EVENT_QUEUE *event_queue = NULL;
   ALLEGRO_TIMER *timer = NULL;
   bool redraw = true;
   int DIRECTION_J1 = 0 ; 
   int DIRECTION_J2 = 1 ; 
   int cont_tiempo = 1;
   int delay = 1;
   char tiempo[5];
  
	   timer = al_create_timer(1.0 / FPS_3);
   if(!timer) {
      fprintf(stderr, "failed to create timer!\n");
      return 1;
   }
 

 
   event_queue = al_create_event_queue();   // creo la cola de eventos
   if(!event_queue) {
      fprintf(stderr, "failed to create event_queue!\n");
      al_destroy_display((*display));
      al_destroy_timer(timer);
      return 1;
   }
    al_init_primitives_addon();
    al_init_ttf_addon();
    al_init_font_addon();
	al_install_keyboard();
	Init_player1(&player1);
	Init_player2(&player2);
	
	font = al_load_font("arial.ttf",50,0);
	
   image = al_load_bitmap ("./sprites/campo.png");
   load_Move(J1, &MOVIMIENTO_J1, &ESTATICO_J1, &VUELO_J1, &BAJAR_J1,&RETRATO_J1);
   load_Move(J2, &MOVIMIENTO_J2, &ESTATICO_J2, &VUELO_J2, &BAJAR_J2,&RETRATO_J2);
   load_Attack(J1,&MOV_KEY_F_J1);
   load_Attack(J2,&MOV_KEY_O_J2);
   
   al_register_event_source(event_queue, al_get_keyboard_event_source());
	
   al_register_event_source(event_queue, al_get_display_event_source(*display));
 
   al_register_event_source(event_queue, al_get_timer_event_source(timer));
 
   al_clear_to_color(al_map_rgb(0,0,0));
 
   al_flip_display();
 
   al_start_timer(timer);
 
   while(1)
   {
      ALLEGRO_EVENT ev;
      al_wait_for_event(event_queue, &ev);
      
    printf("x : %d // y : %d\n",player1.x,player1.y);    //<<<<<<<<<<<<<<<<<<<<<---------- esta para probar
   if(ev.type == ALLEGRO_EVENT_TIMER) {
         redraw = true;
         if (++delay>10)
         {
		 if(cont_tiempo <= 60)
			 {
			 	sprintf(tiempo,"%d",cont_tiempo++);
			 	delay=1;	
			 }
		 
		 else cont_tiempo =0;
		 }
		 	
         if(keys_player1[W])
			Move_player_Up(&player1); // hay  que crear un "struct player player1"
			
         if(keys_player1[S])
			Move_player_Down(&player1);
			
         if(keys_player1[A])
			Move_player_Left(&player1);
			
         if(keys_player1[D])
			Move_player_Right(&player1);       

         if(keys_player2[UP])
			Move_player_Up(&player2); // hay  que crear un "struct player player2"
			
         if(keys_player2[DOWN])
			Move_player_Down(&player2);
			
         if(keys_player2[LEFT])
			Move_player_Left(&player2);
			
         if(keys_player2[RIGHT])
			Move_player_Right(&player2);
			


      }
   else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
         break;
      }
      
   if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
		switch(ev.keyboard.keycode)
		{
			case ALLEGRO_KEY_W:
					keys_player1[W]=true;
					break;
			case ALLEGRO_KEY_S:
					keys_player1[S]=true;
					break;		
			case ALLEGRO_KEY_A:
					keys_player1[A]=true;
					DIRECTION_J1 = 1;
					break;		
			case ALLEGRO_KEY_D:
					keys_player1[D]=true;
					DIRECTION_J1 = 0;
					break;					
			case ALLEGRO_KEY_F:
					keys_player1[F]=true;
					break;
			case ALLEGRO_KEY_UP:
					keys_player2[UP]=true;
					break;
			case ALLEGRO_KEY_DOWN:
					keys_player2[DOWN]=true;
					break;		
			case ALLEGRO_KEY_LEFT:
					keys_player2[LEFT]=true;
					DIRECTION_J2 = 1;
					break;		
			case ALLEGRO_KEY_RIGHT:
					keys_player2[RIGHT]=true;
					DIRECTION_J2 = 0;
					break;
			case ALLEGRO_KEY_O:
					keys_player2[O]=true;
					break;					

		}
		    
		}
	else if(ev.type == ALLEGRO_EVENT_KEY_UP)
		{
		switch(ev.keyboard.keycode)
		{
			case ALLEGRO_KEY_W:
					keys_player1[W]=false;
					break;
			case ALLEGRO_KEY_S:
					keys_player1[S]=false;
					break;		
			case ALLEGRO_KEY_A:
					keys_player1[A]=false;
					break;		
			case ALLEGRO_KEY_D:
					keys_player1[D]=false;
					break;				
			case ALLEGRO_KEY_UP:
					keys_player2[UP]=false;
					break;
			case ALLEGRO_KEY_DOWN:
					keys_player2[DOWN]=false;
					break;		
			case ALLEGRO_KEY_LEFT:
					keys_player2[LEFT]=false;
					break;		
			case ALLEGRO_KEY_RIGHT:
					keys_player2[RIGHT]=false;
					break;	
		}   
		}
   
		
      if(redraw && al_is_event_queue_empty(event_queue)) {
         redraw = false;
         al_clear_to_color(al_map_rgb(0,0,0));
         al_draw_bitmap(image,0,0,0);
         
         al_draw_text(font,al_map_rgb(255,0,0),(ANCHO/2)-20,20,0,tiempo);
       
         al_draw_rounded_rectangle(50,50,100+(player1.life*1.5),50,0,0,al_map_rgb(0,255,255),50);
         al_draw_rounded_rectangle(400,50,450+(player2.life*1.5),50,0,0,al_map_rgb(0,255,255),50);
         
         al_draw_bitmap(RETRATO_J1,0,0,0);
         al_draw_bitmap(RETRATO_J2,540,0,0);
         
         if(keys_player1[D] && !keys_player1[A])
		     {
				al_draw_bitmap(MOVIMIENTO_J1,player1.x,player1.y,0);
			 }
        else if(keys_player1[A] && !keys_player1[D])
		     {
				al_draw_bitmap(MOVIMIENTO_J1,player1.x,player1.y,1);
			 }
        else if(keys_player1[W] && !keys_player1[S])
		     {
				al_draw_bitmap(VUELO_J1,player1.x,player1.y,DIRECTION_J1);
			 }
        else if(keys_player1[S] && !keys_player1[W])
		     {
				al_draw_bitmap(BAJAR_J1,player1.x,player1.y,DIRECTION_J1);
			 }
		else if(keys_player1[F] && !keys_player1[A] && !keys_player1[D])
			{
				al_draw_bitmap(MOV_KEY_F_J1 , player1.x , player1.y,DIRECTION_J1);
				keys_player1[F]=false;
			}         
         else {
			 al_draw_bitmap(ESTATICO_J1,player1.x,player1.y,DIRECTION_J1);
			 }


         if(keys_player2[RIGHT] && !keys_player2[LEFT])
		     {
				al_draw_bitmap(MOVIMIENTO_J2,player2.x,player2.y,0);
			 }
        else if(keys_player2[LEFT] && !keys_player2[RIGHT])
		     {
				al_draw_bitmap(MOVIMIENTO_J2,player2.x,player2.y,1);
			 }
        else if(keys_player2[UP] && !keys_player2[DOWN])
		     {
				al_draw_bitmap(VUELO_J2,player2.x,player2.y,DIRECTION_J2);
			 }
        else if(keys_player2[DOWN] && !keys_player2[UP])
		     {
				al_draw_bitmap(BAJAR_J2,player2.x,player2.y,DIRECTION_J2);
			 }    			          
		else if(keys_player2[O] && !keys_player2[LEFT] && !keys_player2[RIGHT])
			{
				al_draw_bitmap(MOV_KEY_O_J2 , player2.x , player2.y,DIRECTION_J2);
				keys_player2[O]=false;				
			}
         else {
			 al_draw_bitmap(ESTATICO_J2,player2.x,player2.y,DIRECTION_J2);
			 }
		
		

						
         al_flip_display();
      }
      

   }
 
      al_destroy_bitmap(image);
      al_destroy_bitmap(MOVIMIENTO_J1);
      al_destroy_bitmap(MOVIMIENTO_J2);
      al_destroy_bitmap(ESTATICO_J1);
      al_destroy_bitmap(ESTATICO_J2);
      return 0;
   

	}


