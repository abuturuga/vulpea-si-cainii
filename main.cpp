#include <iostream>
#include <graphics.h>
#include <winbgim.h>

#include "GameState.h"
#include "Field.h"

using namespace std;

const int WIDTH = 600;
const int HEIGHT = 600;

int main()
{
    initwindow(WIDTH, HEIGHT);
    GameState* gameState = new GameState();
    setbkcolor(GREEN);
    Field* field = new Field();

    int x, y;
    do {
        if (ismouseclick(WM_LBUTTONDOWN)) {
            clearmouseclick(WM_LBUTTONDOWN);
            x=mousex(); y=mousey();
            cout << field->getFieldX(x) << " " << field->getFieldY(y) << endl;
        }
        field->setDimensions(WIDTH, HEIGHT);
        field->Draw();
        field->renderGameState(gameState);
    } while(true);

    closegraph();
    return 0;
}
