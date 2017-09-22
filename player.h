typedef struct player
{
    SDL_Rect body;
    SDL_Color color;
    SDL_Rect bounds;
    int x_speed, y_speed;
    Direction dir;
} Player;

void playerDraw( Player* plyr, SDL_Surface* surface )
{
    SDL_FillRect( surface, &plyr->body, SDL_MapRGB( surface->format, plyr->color.r, plyr->color.g, plyr->color.b ) );
}

void playerInit( Player* plyr )
{
    plyr->body = ( SDL_Rect ){ 30, 30, 120, 120 };
    plyr->color = ( SDL_Color ){ 0xFF, 0x00, 0x00, 0xFF };
    plyr->bounds = ( SDL_Rect ){ 30, 30, 550, 550 };
    plyr->x_speed = plyr->y_speed = 0;
    plyr->dir = ( Direction )RIGHT;
}

void playerMovement( Player* plyr )
{
    if( plyr->body.x == plyr->bounds.x && plyr->body.y == plyr->bounds.y )
    {
        plyr->dir = RIGHT;
    }
    if( plyr->body.x == plyr->bounds.w && plyr->body.y == plyr->bounds.y )
    {
        plyr->dir = DOWN;
    }
    if( plyr->body.x == plyr->bounds.w && plyr->body.y == plyr->bounds.h )
    {
        plyr->dir = LEFT;
    }
    if( plyr->body.x == plyr->bounds.x && plyr->body.y == plyr->bounds.h )
    {
        plyr->dir = UP;
    }

    switch( plyr->dir )
    {
        case RIGHT:
            plyr->x_speed = 5;
            plyr->y_speed = 0;
            break;
        case DOWN:
            plyr->x_speed = 0;
            plyr->y_speed = 5;
            break;
        case LEFT:
            plyr->x_speed = -5;
            plyr->y_speed = 0;
            break;
        case UP:
            plyr->x_speed = 0;
            plyr->y_speed = -5;
            break;
        case STOP:
            plyr->x_speed = 0;
            plyr->y_speed = 0;
            break;
    }

    plyr->body.x += plyr->x_speed;
    plyr->body.y += plyr->y_speed;
}