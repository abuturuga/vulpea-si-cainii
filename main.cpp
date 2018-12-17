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
    field->setDimensions(WIDTH, HEIGHT);

    int x, y;
    do {
        cleardevice();
        if (ismouseclick(WM_LBUTTONDOWN)) {
            clearmouseclick(WM_LBUTTONDOWN);
            x = field->getFieldX(mousex());
            y = field->getFieldY(mousey());

        }
        setcolor(BLUE);
        setbkcolor(BLUE);
        rectangle(0,0, WIDTH, HEIGHT);

        setcolor(WHITE);
        field->Draw();
        field->renderGameState(gameState);
        Sleep(1000);
    } while(true);

    closegraph();
    return 0;
}
