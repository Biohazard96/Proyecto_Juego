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




int SELECCION_DE_PERSONAJES(ALLEGRO_DISPLAY *display){
	
   struct color aux1={0,255,0}; // color de "<-VOLVER"	
   struct color aux2={0,0,255};// color de "VEGETA"
   struct color aux3={0,0,255};// color de "GOKU"
   struct color aux4={0,0,255};//color de "FREZEER"
   struct color aux5={0,0,255};//color de "BILLS"
   struct frames GOKU={4,0,0,5};	
   struct frames VEGETA={3,0,0,5};
   struct frames FREZEER={3,0,0,5};
   struct frames BILLS={29,0,0,10};
   int i;                   // auxiliar usada para ciclo for 
   int pos_x = ANCHO / 2;   // posicion en eje x
   int pos_y = ALTO / 2;    // posicion en eje y
   ALLEGRO_FONT * font = NULL;
   ALLEGRO_EVENT_QUEUE *event_queue = NULL;  //cola de eventos
   ALLEGRO_TIMER *timer = NULL;  
   ALLEGRO_BITMAP *image=NULL;
   ALLEGRO_MOUSE_STATE  state_mouse2;
   ALLEGRO_BITMAP *goku[GOKU.maxFrame]; //bitmap usada para cargar imagen de goku blue
   ALLEGRO_BITMAP *vegeta[VEGETA.maxFrame]; //bitmap usada para cargar imagen de vegeta blue
   ALLEGRO_BITMAP *frezeer[FREZEER.maxFrame]; //bitmap usada para cargar imagen de golden freezer
   ALLEGRO_BITMAP *bills[BILLS.maxFrame]; //bitmap usada para cargar imagen de bills
   bool redraw = true;   // bool usada para el estado del timer
 

   timer = al_create_timer(1.0 / FPS_2);
   if(!timer) {
      fprintf(stderr, "failed to create timer!\n");
      return 1;
   }
 

 
   event_queue = al_create_event_queue();   // creo la cola de eventos
   if(!event_queue) {
      fprintf(stderr, "failed to create event_queue!\n");
      al_destroy_display((display));
      al_destroy_timer(timer);
      return 1;
   }
   
   al_init_primitives_addon(); //addon para hacer figuras
   al_install_keyboard(); //instalo el teclado
   al_install_mouse(); // instalo el mouse
   al_init_font_addon();  // addon para cargar fuentes de letras#CE5F5F
   al_init_ttf_addon(); // addon para usar fuentes .ttf
   
   font=al_load_font("arial.ttf",25,0); // asigno font 
   
//---------------RUTINA PARA CARGAR IMAGEN---------------------------------------------------------------------------------------------------------------------------------
   image=al_load_bitmap("Seleccion_de_personajes.png"); // cargo fondo de pantalla          PENDIENTE: HACER UN IF EN CASO DE QUE NO CARGUE LA IMAGEN
   goku[0]=al_load_bitmap("goku2.png"); //cargo imagen                                      // PENDIENTE : HACER FUNCION QUE CARGE IMAGENES
   goku[1]=al_load_bitmap("goku3.png"); //cargo imagen
   goku[2]=al_load_bitmap("goku4.png"); //cargo imagen
   goku[3]=al_load_bitmap("goku5.png"); //cargo imagen
   
   vegeta[0]=al_load_bitmap("vegeta1.png"); //cargo imagen
   vegeta[1]=al_load_bitmap("vegeta2.png"); //cargo imagen
   vegeta[2]=al_load_bitmap("vegeta3.png"); //cargo imagen
   
   frezeer[0]=al_load_bitmap("frezeer1.png"); //cargo imagen
   frezeer[1]=al_load_bitmap("frezeer2.png"); //cargo imagen
   frezeer[2]=al_load_bitmap("frezeer3.png"); //cargo imagen
   
   bills[0]=al_load_bitmap("b1.bmp"); //cargo imagen
   bills[1]=al_load_bitmap("b2.bmp"); //cargo imagen
   bills[2]=al_load_bitmap("b3.bmp"); //cargo imagen
   bills[3]=al_load_bitmap("b4.bmp"); //cargo imagen
   bills[4]=al_load_bitmap("b5.bmp"); //cargo imagen
   bills[5]=al_load_bitmap("b6.bmp"); //cargo imagen
   bills[6]=al_load_bitmap("b7.bmp"); //cargo imagen
   bills[7]=al_load_bitmap("b8.bmp"); //cargo imagen
   bills[8]=al_load_bitmap("b9.bmp"); //cargo imagen
   bills[9]=al_load_bitmap("b10.bmp"); //cargo imagen
   bills[10]=al_load_bitmap("b11.bmp"); //cargo imagen
   bills[11]=al_load_bitmap("b12.bmp"); //cargo imagen
   bills[12]=al_load_bitmap("b13.bmp"); //cargo imagen
   bills[13]=al_load_bitmap("b14.bmp"); //cargo imagen
   bills[14]=al_load_bitmap("b15.bmp"); //cargo imagen
   bills[15]=al_load_bitmap("b16.bmp"); //cargo imagen
   bills[16]=al_load_bitmap("b17.bmp"); //cargo imagen
   bills[17]=al_load_bitmap("b18.bmp"); //cargo imagen
   bills[18]=al_load_bitmap("b19.bmp"); //cargo imagen
   bills[19]=al_load_bitmap("b20.bmp"); //cargo imagen
   bills[20]=al_load_bitmap("b21.bmp"); //cargo imagen
   bills[21]=al_load_bitmap("b22.bmp"); //cargo imagen
   bills[22]=al_load_bitmap("b23.bmp"); //cargo imagen
   bills[23]=al_load_bitmap("b24.bmp"); //cargo imagen
   bills[24]=al_load_bitmap("b25.bmp"); //cargo imagen
   bills[25]=al_load_bitmap("b26.bmp"); //cargo imagen
   bills[26]=al_load_bitmap("b27.bmp"); //cargo imagen
   bills[27]=al_load_bitmap("b28.bmp"); //cargo imagen
   bills[28]=al_load_bitmap("b29.bmp"); //cargo imagen
   

    for(i=0 ; i<BILLS.maxFrame;i++){
		al_convert_mask_to_alpha(bills[i],al_map_rgb(107,204,48));   // con esto borro el fondo de un sprite para dejar solo la imagen
		
		}
//------------------------------------------------------------------------------------------------------------------------------------------------		
   al_register_event_source(event_queue, al_get_keyboard_event_source()); // le digo a la cola de evento que puede recibir eventos del teclado
   
   al_register_event_source(event_queue, al_get_display_event_source((display))); // le digo a la cola de evento que puede recibir eventos del display
 
   al_register_event_source(event_queue, al_get_timer_event_source(timer)); // le digo a la cola de evento que puede recibir eventos del timer
 
   al_clear_to_color(al_map_rgb(0,0,0));
 
   al_flip_display();
 
   al_start_timer(timer); // comienza en timer
   
   
 //-----------------------------//////////COMIENZO WHILE(1)////////////////////////////////---------------------------------------------------------------------
   while(1)
   {
      ALLEGRO_EVENT ev;    // variable usada para guardar eventos
      
      al_wait_for_event(event_queue, &ev); 
      

   if(ev.type == ALLEGRO_EVENT_TIMER) {  // SIEMPRE ENTRA 
         redraw = true;
//----------------------RUTINA de goku/vegeta/frezeer sprite-----------------------------------------------------         
		if(++GOKU.frameCount >= GOKU.frameDelay){
				if(++GOKU.curFrame >= GOKU.maxFrame){
					GOKU.curFrame=0;
					GOKU.frameCount=0;
				}
			
			}
		if(++VEGETA.frameCount >= VEGETA.frameDelay){
				if(++VEGETA.curFrame >= VEGETA.maxFrame){
					VEGETA.curFrame=0;
					VEGETA.frameCount=0;
				}
			
			}
		if(++FREZEER.frameCount >= FREZEER.frameDelay){
				if(++FREZEER.curFrame >= FREZEER.maxFrame){
					FREZEER.curFrame=0;
					FREZEER.frameCount=0;
				}
			
			}
			
		if(++BILLS.frameCount >= BILLS.frameDelay){
				if(++BILLS.curFrame >= BILLS.maxFrame){
					BILLS.curFrame=0;
					BILLS.frameCount=0;
				}
			
			}
//----------------------RUTINA DE MOVIMIENTO DEL MOUSE-----------------------------------------------------			
		al_get_mouse_state(&state_mouse2);
         
		if(state_mouse2.x > 30 && state_mouse2.x < 85 && state_mouse2.y > 325 && state_mouse2.y < 345){ // Cuando el mouse esta sobre "VOLVER" le cambia color
           aux1.RED=0;
           aux1.GREEN=0;
           aux1.BLUE=255;
			if(state_mouse2.buttons & 1){ // si hago click sobre VOLVER regresa al menu
				for(i=0 ; i<4;i++){    //libero imagen
				al_destroy_bitmap(goku[i]);
				}  
			al_destroy_bitmap(image);//libero imagen
		   
			  return 0;
		   }
		   }else if(state_mouse2.x > 50 && state_mouse2.x < 125 && state_mouse2.y > 160 && state_mouse2.y < 175){ // Cuando el mouse esta sobre "VEGETA" le cambia color
           aux2.RED=255;
           aux2.GREEN=255;
           aux2.BLUE=0;
			if(state_mouse2.buttons & 1) // si hago click sobre VEGETA regresa al menu
            {//TEMPORAL
				for(i=0 ; i<4;i++) {al_destroy_bitmap(goku[i]);}
		
				al_destroy_bitmap(image);//libero imagen
			  return 0;
			}
		 }else if(state_mouse2.x > 220 && state_mouse2.x < 280 && state_mouse2.y > 160 && state_mouse2.y < 175){ // Cuando el mouse esta sobre "GOKU" le cambia color
           aux3.RED=255;
           aux3.GREEN=255;
           aux3.BLUE=0;
			if(state_mouse2.buttons & 1) // si hago click sobre GOKU regresa al menu
            {//TEMPORAL
				for(i=0 ; i<4;i++){ al_destroy_bitmap(goku[i]);}
		
				al_destroy_bitmap(image);//libero imagen
			  return 0;
			}
			}else if(state_mouse2.x > 370 && state_mouse2.x < 460 && state_mouse2.y > 160 && state_mouse2.y < 175){ // Cuando el mouse esta sobre "FREZEER" le cambia color
           aux4.RED=255;
           aux4.GREEN=255;
           aux4.BLUE=0;
			if(state_mouse2.buttons & 1) // si hago click sobre VEGETA regresa al menu
            {//TEMPORAL
				for(i=0 ; i<4;i++) {al_destroy_bitmap(goku[i]);}
		
				al_destroy_bitmap(image);//libero imagen
			  return 0;
			}
			}else if(state_mouse2.x > 550 && state_mouse2.x < 610 && state_mouse2.y > 160 && state_mouse2.y < 175){ // Cuando el mouse esta sobre "BILLS" le cambia color
           aux5.RED=255;
           aux5.GREEN=255;
           aux5.BLUE=0;
			if(state_mouse2.buttons & 1) // si hago click sobre VEGETA regresa al menu
            {//TEMPORAL
				for(i=0 ; i<4;i++){al_destroy_bitmap(goku[i]);}
		
				al_destroy_bitmap(image);//libero imagen
			  return 0;
			}
			}else {
           aux1.RED=255;
           aux1.GREEN=0;
           aux1.BLUE=0;
           aux2.RED=0;
           aux2.GREEN=0;
           aux2.BLUE=255;
           aux3.RED=0;
           aux3.GREEN=0;
           aux3.BLUE=255;
           aux4.RED=0;
           aux4.GREEN=0;
           aux4.BLUE=255;
           aux5.RED=0;
           aux5.GREEN=0;
           aux5.BLUE=255;
			 }
		
      
  }
//----------------------------RUTINA DE TECLADO---------------------------------------------------------------------------------------------
   else if(ev.type == ALLEGRO_EVENT_KEY_DOWN){
				switch(ev.keyboard.keycode)
				{
					case ALLEGRO_KEY_UP:   
					   pos_y-=10;
					   break;
					case ALLEGRO_KEY_DOWN:   
					   pos_y+=10;
					   break;			   
					case ALLEGRO_KEY_LEFT:   
					   pos_x-=10;
					   break;
					case ALLEGRO_KEY_RIGHT:   
					   pos_x+=10;
						break;   
				}
		   
		   }
//-------------------------------------------------------------------------------------------------------------------------------------------	  
   else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			for(i=0 ; i<4;i++){
				al_destroy_bitmap(goku[i]);
				}  
			al_destroy_bitmap(image);
         return -1;
      }
    printf("pos x = %d  pos y = %d \n",state_mouse2.x,state_mouse2.y); // sirve para saber la posicion del mouse en el eje (x ,y)
 //------------------------------------------------------------------------------------------------>
      if(redraw && al_is_event_queue_empty(event_queue)) {                                          
          redraw = false;																			
          al_draw_bitmap(image,0,0,0); // pongo fondo de pantalla									
          al_draw_bitmap(goku[GOKU.curFrame],pos_x,pos_y,0);//pongo en pantalla a goku TEMPORAL PARA PRUEBA
          al_draw_bitmap(vegeta[VEGETA.curFrame],70,95,0);//pongo en pantalla a vegeta
          al_draw_bitmap(goku[GOKU.curFrame],230,90,0);//pongo en pantalla a goku
          al_draw_bitmap(frezeer[FREZEER.curFrame],390,105,0);//pongo en pantalla a frezeer
          al_draw_bitmap(bills[BILLS.curFrame],550,85,0);//pongo en pantalla a bills
		  al_draw_text(font,al_map_rgb(aux1.RED,aux1.GREEN,aux1.BLUE),20,320,0,"<-Volver"); //muestro texto
		  al_draw_text(font,al_map_rgb(aux2.RED,aux2.GREEN,aux2.BLUE),50,155,0,"VEGETA"); //muestro texto 
		  al_draw_text(font,al_map_rgb(aux3.RED,aux3.GREEN,aux3.BLUE),220,155,0,"GOKU"); //muestro texto
		  al_draw_text(font,al_map_rgb(aux4.RED,aux4.GREEN,aux4.BLUE),370,155,0,"FREZEER"); //muestro texto
		  al_draw_text(font,al_map_rgb(aux5.RED,aux5.GREEN,aux5.BLUE),550,155,0,"BILLS"); //muestro texto
		  al_draw_text(font,al_map_rgb(0,0,255),190,20,0,"SELECCION DE PERSONAJES"); //muestro texto en posicion (x,y)
		  al_flip_display();
          al_clear_to_color(al_map_rgb(0,0,0));																								
																									
      }
   }
///////////////////////////FIN WHILE(1)//////////////////////////////////////////////////////////////////////////////////////////////////////////   
     for(i=0 ; i<4;i++){
		al_destroy_bitmap(goku[i]);
		}  
     al_destroy_bitmap(image);

 
   return -2;
}
