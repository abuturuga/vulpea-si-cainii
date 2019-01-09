#include <iostream>
#include <graphics.h>
#include <winbgim.h>

#include "GameState.h"
#include "Field.h"

using namespace std;

const int WIDTH = 600;
const int HEIGHT = 600;

void render(Field* field, GameState* gameState, int x, int y) {
    cleardevice();
    setbkcolor(BLUE);

    setcolor(WHITE);
    field->Draw();
    field->renderGameState(gameState);
}

void game_loop(Field* field, GameState* gameState) {
    int x, y;
    gameState->winner = -1;
    gameState->gameEnd = false;
    render(field, gameState, 0, 0);
    do {
        if (ismouseclick(WM_LBUTTONDOWN)) {
            clearmouseclick(WM_LBUTTONDOWN);
            x = field->getFieldX(mousex());
            y = field->getFieldY(mousey());
            gameState->UpdatePlayer(x, y);
            render(field, gameState, x, y);
        }
    } while(true);
}

int main()
{
    initwindow(WIDTH, HEIGHT);
    GameState* gameState = new GameState();

    Field* field = new Field();
    field->setDimensions(WIDTH, HEIGHT);

    game_loop(field, gameState);

    closegraph();
    getch();
    return 0;
}
