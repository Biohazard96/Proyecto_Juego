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

int game_play(ALLEGRO_DISPLAY ** display){
	
   ALLEGRO_BITMAP *image = NULL;
   ALLEGRO_EVENT_QUEUE *event_queue = NULL;
   ALLEGRO_TIMER *timer = NULL;
   bool redraw = true;
 
	   timer = al_create_timer(1.0 / FPS_2);
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
   

   image = al_load_bitmap ("./sprites/Seleccion_de_personajes.png");

	
	
   al_register_event_source(event_queue, al_get_display_event_source(*display));
 
   al_register_event_source(event_queue, al_get_timer_event_source(timer));
 
   al_clear_to_color(al_map_rgb(0,0,0));
 
   al_flip_display();
 
   al_start_timer(timer);
 
   while(1)
   {
      ALLEGRO_EVENT ev;
      al_wait_for_event(event_queue, &ev);
 
      if(ev.type == ALLEGRO_EVENT_TIMER) {
         redraw = true;
      }
      else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
         return 0;
      }
 
      if(redraw && al_is_event_queue_empty(event_queue)) {
         redraw = false;
         al_clear_to_color(al_map_rgb(0,0,0));
         al_draw_bitmap(image,0,0,0);
         
         
         al_flip_display();
      }
   }
 

   
   return 1;
	}
