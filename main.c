#include <stdio.h>
#include <SDL/SDL.h>
#include <emscripten.h>

#define TRUE 1
#define FALSE 0
static int running = TRUE;

static const int SCREEN_W = 700;
static const int SCREEN_H = 700;

#include "direction.h"
#include "player.h"
#include "target.h"
#include "graphics.h"

Graphics gfx;
Target trgt;
Player plyr;

void loop()
{
    static SDL_Event e;
    while( SDL_PollEvent( &e ) != 0 )
    {
        if( e.type == SDL_QUIT )
        {
            running = FALSE;
        }
        else if( e.type == SDL_KEYDOWN )
        {
            if( e.key.keysym.sym == SDLK_SPACE )
            {
                if( targetCheck( &trgt, &plyr ) == TRUE )
                {
                    printf( "True\n" );
                }
                else
                {
                    printf( "False\n" );
                }
            }
        }
    }
    
    playerMovement( &plyr );
    graphicsDraw( &gfx, &plyr, &trgt );
    SDL_Flip( gfx.surface );
}

int main( int argc, char* args[] )
{
    printf( "SDL running through Emscripten\n" );

    SDL_Init( SDL_INIT_VIDEO );
    graphicsInit( &gfx );
    targetInit( &trgt );
    playerInit( &plyr );

    #ifdef EMSCRIPTEN
        emscripten_set_main_loop( loop, 0, 1 );
    #else
        while( running == TRUE )
        {
            loop();
        }
    #endif

    SDL_Quit();
    printf( "SDL_Quit\n" );
    return 0;
}
