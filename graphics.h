typedef struct graphics
{
    SDL_Surface* surface;
    SDL_Rect screen;
    
    SDL_Rect back;
    SDL_Color back_color;
    
    SDL_Rect path;
    SDL_Color path_color;
    
    SDL_Rect fill;
    SDL_Color fill_color;
} Graphics;

void graphicsInit( Graphics* gfx )
{
    gfx->surface    = SDL_SetVideoMode( SCREEN_W, SCREEN_H, 32, SDL_SWSURFACE );
    gfx->screen     = ( SDL_Rect  ){    0,    0, SCREEN_W, SCREEN_H };
    gfx->back       = ( SDL_Rect  ){    1,    1,      698,      698 };
    gfx->back_color = ( SDL_Color ){ 0xFF, 0xFF,     0xFF,     0xFF };
    gfx->path       = ( SDL_Rect  ){   30,   30,      640,      640 };
    gfx->path_color = ( SDL_Color ){ 0x00, 0x00,     0x00,     0xFF };
    gfx->fill       = ( SDL_Rect  ){  150,  150,      400,      400 };
    gfx->fill_color = ( SDL_Color ){ 0xFF, 0xFF,     0xFF,     0xFF };
}

void graphicsDraw( Graphics* gfx, Player* plyr, Target* trgt )
{
    SDL_FillRect( gfx->surface, NULL, SDL_MapRGB( gfx->surface->format, 0x00, 0x00, 0x00 ) );
    SDL_FillRect( gfx->surface, &gfx->back, SDL_MapRGB( gfx->surface->format, gfx->back_color.r, gfx->back_color.g, gfx->back_color.b ) );
    SDL_FillRect( gfx->surface, &gfx->path, SDL_MapRGB( gfx->surface->format, gfx->path_color.r, gfx->path_color.g, gfx->path_color.b ) );
    SDL_FillRect( gfx->surface, &gfx->fill, SDL_MapRGB( gfx->surface->format, gfx->fill_color.r, gfx->fill_color.g, gfx->fill_color.b ) );
    
    SDL_FillRect( gfx->surface, &trgt->clear, SDL_MapRGB( gfx->surface->format, 0x00, 0x00, 0x00 ) );
    SDL_FillRect( gfx->surface, &trgt->outter, SDL_MapRGB( gfx->surface->format, trgt->color.r, trgt->color.g, trgt->color.b ) );
    SDL_FillRect( gfx->surface, &trgt->fill, SDL_MapRGB( gfx->surface->format, 0x00, 0x00, 0x00 ) );
    SDL_FillRect( gfx->surface, &trgt->goal, SDL_MapRGB( gfx->surface->format, trgt->color.r, trgt->color.g, trgt->color.b ) );
    
    SDL_FillRect( gfx->surface, &plyr->body, SDL_MapRGB( gfx->surface->format, plyr->color.r, plyr->color.g, plyr->color.b ) );
}