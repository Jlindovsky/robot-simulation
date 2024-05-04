#include "window.h"

void window::clickInEdit(inputData * gamePiece,int x , int y)
{
    if((x>=PLAY_X || x <= PLAY_X + PLAY_W - SIZE_B) && (y>=0 || y<=PLAY_H - SIZE_B))
    {
        //clicked inside of playground
    }
    else if((x>= 0 || x< IPANEL_W) && (y>=0 || y<=IPANEL_H))
    {
        //clicked in I panel 
    }
}

