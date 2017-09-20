#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include "allegro5/allegro_native_dialog.h"
#include <allegro5/allegro_ttf.h>
#include "allegro5/allegro_image.h"
#include <stdlib.h>
#include <string.h>
#include "milib.h"
#define ANCHO 640
#define ALTO 360
const float FPS = 60;


struct color{
	int RED;
	int GREEN;
	int BLUE;
	};


int main(int argc, char **argv){
   
   struct color aux1={255,0,0};
   struct color aux2={255,0,0};
   struct color aux3={255,0,0};
   //int pos_x = ANCHO / 2;
   //int pos_y = ALTO / 2;
   //int x=0;
   ALLEGRO_DISPLAY *display = NULL;
   ALLEGRO_EVENT_QUEUE *event_queue = NULL;
   ALLEGRO_TIMER *timer = NULL;
   ALLEGRO_FONT * font = NULL;
   ALLEGRO_BITMAP *image   = NULL;
   ALLEGRO_MOUSE_STATE state;
   bool redraw = true;

	
	
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
		
	al_init_primitives_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_install_mouse(); 
	
	font = al_load_font("arial.ttf",25,0); 
	image = al_load_bitmap("MENU.png");
	
	if(!image) {
      al_show_native_message_box(display, "Error", "Error", "Failed to load image!", 
                                 NULL, ALLEGRO_MESSAGEBOX_ERROR);
      al_destroy_display(display);
      return 0;
   }
  
	 
   al_register_event_source(event_queue, al_get_display_event_source(display));
 
   al_register_event_source(event_queue, al_get_timer_event_source(timer));
   
   al_register_event_source(event_queue,al_get_mouse_event_source());
	
   al_clear_to_color(al_map_rgb(0,0,0));
  
   al_flip_display();
 
   al_start_timer(timer);
 
   while(1)
   {
      ALLEGRO_EVENT ev;
      al_wait_for_event(event_queue, &ev);
 
      if(ev.type == ALLEGRO_EVENT_TIMER) {
         redraw = true;

		al_get_mouse_state(&state);
		
		if(state.x > 20 && state.x < 210 && state.y > 300 && state.y < 320){
           aux1.RED=0;
           aux1.GREEN=0;
           aux1.BLUE=255;         
		  }
		else if(state.x > 320 && state.x < 405 && state.y > 300 && state.y < 320){
           aux2.RED=0;
           aux2.GREEN=0;
           aux2.BLUE=255;         
		  }			  
		else if(state.x > 500 && state.x < 555 && state.y > 300 && state.y < 320){
           aux3.RED=0;
           aux3.GREEN=0;
           aux3.BLUE=255;         
		  }else {
			  aux1.RED=255;
			  aux1.GREEN=255;
              aux1.BLUE=0;				
			  aux2.RED=255;
			  aux2.GREEN=255;
              aux2.BLUE=0;				
			  aux3.RED=255;
			  aux3.GREEN=255;
              aux3.BLUE=0;				
			  }
		printf("pos x = %d  pos y = %d \n",state.x,state.y);
		
		
      }
      else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
         break;
      }
	  

 
      if(redraw && al_is_event_queue_empty(event_queue)) {
         redraw = false;
         
         al_clear_to_color(al_map_rgb(0,0,0));
         al_draw_bitmap(image,0,0,0);
		al_draw_text(font,al_map_rgb(aux1.RED,aux1.GREEN,aux1.BLUE),20,300,0,"COMENZAR JUEGO");
		al_draw_text(font,al_map_rgb(aux2.RED,aux2.GREEN,aux2.BLUE),320,300,0,"PUNTOS");
		al_draw_text(font,al_map_rgb(aux3.RED,aux3.GREEN,aux3.BLUE),500,300,0,"SALIR");
         al_flip_display();
      }
   }
   al_destroy_bitmap(image);
   al_destroy_timer(timer);
   al_destroy_display(display);
   al_destroy_event_queue(event_queue);
   al_destroy_font(font);
	return 0;	
	}
