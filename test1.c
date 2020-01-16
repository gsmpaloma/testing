//
//  main.c
//  123
//
//  Created by abdeslam on 13/01/2020.
//  Copyright © 2020 abdeslam. All rights reserved.
//

#include <stdio.h>
#include <SDL2/SDL.h>
#include <stdbool.h>

SDL_Window * window;
SDL_Renderer * renderer;
int gameIsRunning = false;




int initialize(void)
{
     if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
     {
         fprintf(stderr, "error incializing...\n ");
         return (0);
     }
    
    window = SDL_CreateWindow("game window",
                              SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED,
                              640,
                              480,
                              SDL_WINDOW_SHOWN);
    
    if(!window)
    {
        fprintf(stderr, "error creating window...\n ");
        return(0);
    }    
    renderer = SDL_CreateRenderer( window,
                                  -1,
                                  0);

    if(!renderer)
    {
        fprintf(stderr, "error rendering..\n ");
        return(0);
    }

     
    return(1);
    
}

void process_input(){
      SDL_Event event;
      SDL_PollEvent(&event);

           switch(event.type) 
   {
      
              case SDL_QUIT:
	         gameIsRunning = false;
                    break;
              case SDL_KEYDOWN:
                   if(event.key.keysym.sym == SDLK_ESCAPE) 
		       {
                         gameIsRunning = false;
	                      break;
                        }	     
  
  
   }

}

void render(){
    SDL_SetRenderDrawColor(renderer, 0 ,0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}

void update(){

}


 void setup(){

}

void destroy_window(){
 
SDL_DestroyRenderer(renderer);
SDL_DestroyWindow(window);
SDL_Quit();

 
}

int main(int argc, const char * argv[]) {
    
    
    
gameIsRunning =    initialize();
    
setup();

while (gameIsRunning){

  process_input();
  update();
  render();


}

destroy_window();




}
