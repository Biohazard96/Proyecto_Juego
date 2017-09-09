#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "milib.h"

const float FPS = 60;

int main(int argc, char **argv){
   int i;
   ALLEGRO_DISPLAY *display = NULL;
   ALLEGRO_EVENT_QUEUE *event_queue = NULL;
   ALLEGRO_TIMER *timer = NULL;
   bool redraw = true;
	
	if(!init_al()) return -1;
	
	display = al_create_display(640, 480);
   if(!display) {
      fprintf(stderr, "failed to create display!\n");
      al_destroy_timer(timer);
      return -1;
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
		
	 
   al_register_event_source(event_queue, al_get_display_event_source(display));
 
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
         if(i<255)i++;
         else i=0;
      }
      else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
         break;
      }
 
      if(redraw && al_is_event_queue_empty(event_queue)) {
         redraw = false;
         al_clear_to_color(al_map_rgb(i,i,i));
         al_flip_display();
      }
   }
 
   al_destroy_timer(timer);
   al_destroy_display(display);
   al_destroy_event_queue(event_queue);
	
	return 0;	
	}
