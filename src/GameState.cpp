#include "GameState.h"

const int PLAYER_1 = 0;
const int PLAYER_2 = 1;

GameState::GameState()
{
    this->fox = new GameObject(3, 2);
    for(int i = 0; i < 4; i++) {
        this->dogs[i] = new GameObject(i * 2 + 1 , 8);
    }

    this->turn = PLAYER_1;
}

GameState::~GameState()
{
    //dtor
}

void GameState::setFox(int x, int y) {
    this->fox->setX(x);
    this->fox->setY(y);
}

GameObject* GameState::getFox() {
    return this->fox;
}

GameObject* GameState::getDog(int index) {
    return this->dogs[index];
}

int GameState::GetTurn() {
    return this->turn;
}

void GameState::NextTurn() {
    this->turn = (this->turn == PLAYER_1) ? PLAYER_2 : PLAYER_1;
}
