typedef struct target
{
    SDL_Rect clear;
    SDL_Rect outter;
    SDL_Rect fill;
    SDL_Rect goal;
    SDL_Color color;
} Target;

void targetInit( Target* trgt )
{
    trgt->clear = ( SDL_Rect ){ 8, 8, 164, 164 };
    trgt->outter = ( SDL_Rect ){ 12, 12, 156, 156 };
    trgt->fill = ( SDL_Rect ){ 25, 25, 130, 130 };
    trgt->goal = ( SDL_Rect ){ 29, 29, 122, 122 };
    trgt->color = ( SDL_Color ){ 0x00, 0xCC, 0xFF, 0xFF };
}