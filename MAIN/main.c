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

int main(int argc, char **argv){
   
   struct color aux1={255,0,0};
   struct color aux2={255,0,0};
   struct color aux3={255,0,0};

   
   ALLEGRO_DISPLAY *display = NULL;
   ALLEGRO_EVENT_QUEUE *event_queue = NULL;
   ALLEGRO_TIMER *timer = NULL;
   ALLEGRO_FONT * font = NULL;
   ALLEGRO_BITMAP *image   = NULL;
   ALLEGRO_MOUSE_STATE state_mouse;
   bool redraw = true;

	
	//al_init	
	if(!init_al()) return -1;

	if(!crear_display(&display,ANCHO,ALTO)) return -1;

    if(!al_init_image_addon()) {
      al_show_native_message_box(display, "Error", "Error", "Failed to initialize al_init_image_addon!", 
                                 NULL, ALLEGRO_MESSAGEBOX_ERROR);
      return 0;
   }

	
	if(!crear_timer(&timer,FPS)) {
		al_destroy_display(display);
	return -1;
		}
		
	if(!crear_evento(&event_queue)) {	
		al_destroy_display(display);
		al_destroy_timer(timer);
		return -1;
		}
		
	al_init_primitives_addon(); //addon para hacer figura
	al_init_font_addon();  // addon para cargar fuentes de letras
	al_init_ttf_addon(); // addon para usar fuentes .ttf
	al_install_mouse();  // instalo el mouse 
	al_install_keyboard();  //instalo el teclado
	
	font = al_load_font("arial.ttf",25,0);  // le asigno el font 
	image = al_load_bitmap("./sprites/MENU.png"); //le asigno la imagen del menu
	
	if(!image) {
      al_show_native_message_box(display, "Error", "Error", "Failed to load image!", 
                                 NULL, ALLEGRO_MESSAGEBOX_ERROR);
      al_destroy_display(display);
      return 0;
   }
  //----------------EVENTOS QUE PUEDE recibir LA COLA DE EVENTOS--------------------------------------------------------------------- 
   al_register_event_source(event_queue, al_get_keyboard_event_source());
	 
   al_register_event_source(event_queue, al_get_display_event_source(display));
 
   al_register_event_source(event_queue, al_get_timer_event_source(timer));
   
   al_register_event_source(event_queue,al_get_mouse_event_source());
//-------------------------------------------------------------------------------------	
   al_clear_to_color(al_map_rgb(0,0,0));
  
   al_flip_display();
 
   al_start_timer(timer);
 
   while(1)
   {
      ALLEGRO_EVENT ev;
      al_wait_for_event(event_queue, &ev);
 
      if(ev.type == ALLEGRO_EVENT_TIMER) {
         redraw = true;
		 al_get_mouse_state(&state_mouse);
		
	  if(MENU(&state_mouse,&aux1,&aux2,&aux3)==-1){ //SI APRETO SALIR O LA CRUZ
			break;
			}else if(MENU(&state_mouse,&aux1,&aux2,&aux3)==1){ //SI APRETO COMENZAR JUEGO 
				
				if(SELECCION_DE_PERSONAJES(display)==0){ // SI APRETO VOLVER o CRUZ // LLAMO FUNCION SELECCION DE PERSONAJES
					
					MENU(&state_mouse,&aux1,&aux2,&aux3);
					 
					}
				}else if (MENU(&state_mouse,&aux1,&aux2,&aux3)==2){//SI APRETO "PUNTOS"
					break; //TEMPORAL
					}
		
      }
      else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) { //Si apreto la cruz sale del programa
         break;
      }
	  

 
      if(redraw && al_is_event_queue_empty(event_queue)) {
         redraw = false;
         
         al_clear_to_color(al_map_rgb(0,0,0)); //actualizo el fondo en negro
         al_draw_bitmap(image,0,0,0); // muestro lo asignado en image , Fondo de pantalla
		 al_draw_text(font,al_map_rgb(aux1.RED,aux1.GREEN,aux1.BLUE),20,300,0,"COMENZAR JUEGO"); //muestro texto
		 al_draw_text(font,al_map_rgb(aux2.RED,aux2.GREEN,aux2.BLUE),320,300,0,"PUNTOS");  //muestro texto
		 al_draw_text(font,al_map_rgb(aux3.RED,aux3.GREEN,aux3.BLUE),500,300,0,"SALIR"); //muestro texto
		 
         al_flip_display();
      }
   }
   
   //al_destroy 
   
   al_destroy_timer(timer);
   al_destroy_display(display);
   al_destroy_event_queue(event_queue);
   al_destroy_font(font);
   
 return 0;	
	}
