#include "GameState.h"

GameState::GameState()
{
    this->fox = new GameObject(3, 2);
    for(int i = 0; i < 4; i++) {
        this->dogs[i] = new GameObject(i * 2 + 1 , 8);
    }
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
