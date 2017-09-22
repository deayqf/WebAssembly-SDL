typedef struct target
{
    SDL_Rect clear;
    SDL_Rect outter;
    SDL_Rect fill;
    SDL_Rect goal;
    SDL_Rect inner;
    SDL_Color color;
    Direction dir;
} Target;

void targetInit( Target* trgt )
{
    trgt->clear  = ( SDL_Rect  ){    8,    8,  164,  164 };
    trgt->outter = ( SDL_Rect  ){   12,   12,  156,  156 };
    trgt->fill   = ( SDL_Rect  ){   25,   25,  130,  130 };
    trgt->goal   = ( SDL_Rect  ){   29,   29,  122,  122 };
    trgt->inner  = ( SDL_Rect  ){   30,   30,  120,  120 };
    trgt->color  = ( SDL_Color ){ 0x00, 0xCC, 0xFF, 0xFF };
    trgt->dir    = STOP;
}

int targetCheck( Target* trgt, Player* plyr )
{
    int plyr_x = plyr->body.x;
    int plyr_y = plyr->body.y;
    int plyr_w = plyr->body.x + plyr->body.w;
    int plyr_h = plyr->body.y + plyr->body.h;

    int outt_x = trgt->outter.x;
    int outt_y = trgt->outter.y;
    int outt_w = trgt->outter.x + trgt->outter.w;
    int outt_h = trgt->outter.y + trgt->outter.h;

    int fill_x = trgt->fill.x;
    int fill_y = trgt->fill.y;
    int fill_w = trgt->fill.x + trgt->fill.w;
    int fill_h = trgt->fill.y + trgt->fill.h;

    int goal_x = trgt->goal.x;
    int goal_y = trgt->goal.y;
    int goal_w = trgt->goal.x + trgt->goal.w;
    int goal_h = trgt->goal.y + trgt->goal.h;

    if( plyr_x > outt_x && plyr_y > outt_y && plyr_w < outt_w && plyr_h < outt_h )
    {
        trgt->color = ( SDL_Color ){ 0xFF, 0xFF, 0x00, 0xFF };
        if( plyr_x > fill_x && plyr_y > fill_y && plyr_w < fill_w && plyr_h < fill_h )
        {
            trgt->color = ( SDL_Color ){ 0x00, 0xFF, 0xFF, 0xFF };
        }
        return 1;
    }
    else
    {
        trgt->color = ( SDL_Color ){ 0xFF, 0x00, 0x00, 0xFF };
        return 0;
    }
}