#include "GameState.h"
#include <iostream>
using namespace std;

const int PLAYER_1 = 0;
const int PLAYER_2 = 1;

const int DOGS_LENGTH = 4;

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

void GameState::SetHasUpdates(bool hasUpdates) {
    this->hasUpdates = hasUpdates;
}

bool GameState::HasUpdates() {
    return this->hasUpdates;
}

bool GameState::IsPlayerSelected(int x, int y) {
    if (this->turn == PLAYER_1 && this->fox->HasCoords(x, y)) {
        return true;
    } else if (this->turn == PLAYER_2) {
        for (int index = 0; index < DOGS_LENGTH; index++) {
            if (this->dogs[index]->HasCoords(x, y)) {
                return true;
            }
        }
    }

    return false;
}

bool GameState::HasHitPlayer(int x, int y) {
    if (this->fox->getX() == x && this->fox->getY() == y) {
        return true;
    }

    for (int index = 0; index < DOGS_LENGTH; index++) {
        if (dogs[index]->getX() == x && dogs[index]->getY() == y) {
            return true;
        }
    }

    return false;
}

GameObject *GameState::GetPlayer(int x, int y) {
    if (this->turn == PLAYER_1) {
        return this->fox;
    }

    for (int index = 0; index < DOGS_LENGTH; index++) {
        if (this->dogs[index]->getX() == x && this->dogs[index]->getY() == y) {
            return this->dogs[index];
        }
    }

    return NULL;
}

bool GameState::DogValidMove(int x, int y, GameObject* player) {
    int yOffset = -1;

    if (player == NULL) {
        return false;
    }

    int playerX = player->getX();
    int playerY = player->getY();

    if (x > 8 || y > 8 || x < 1 || y < 1) {
        return false;
    } if (y != playerY + yOffset) {
        return false;
    }

    if ((x == playerX + 1 || x == playerX - 1) && !this->HasHitPlayer(x, y)) {
        return true;
    }

    return false;
}

bool GameState::FoxValidMove(int x, int y, GameObject* player) {
    if (player == NULL) {
        return false;
    }

    int playerX = player->getX();
    int playerY = player->getY();

    int leftOffset = playerX - 1;
    int rightOffset = playerX + 1;
    int topOffset = playerY - 1;
    int bottomOffset = playerY + 1;

    if (x < 1 || x > 8 || y < 1 || y > 8) {
        return false;
    }

    bool side = (x == leftOffset || x == rightOffset);
    bool topBottom = (y == topOffset || y == bottomOffset);


    return (side && topBottom && !this->HasHitPlayer(x, y));
}


bool GameState::IsValidMove(int x, int y, GameObject* player) {
    if (this->turn == PLAYER_1) {
        return this->FoxValidMove(x, y, player);
    } else {
        return this->DogValidMove(x, y, player);
    }
}

bool GameState::HasDogsWin() {
    int playerX = this->fox->getX();
    int playerY = this->fox->getY();

    int leftOffset = playerX - 1;
    int rightOffset = playerX + 1;
    int topOffset = playerY - 1;
    int bottomOffset = playerY + 1;

    if (
        !this->FoxValidMove(leftOffset, topOffset, this->fox) &&
        !this->FoxValidMove(leftOffset, bottomOffset, this->fox) &&
        !this->FoxValidMove(rightOffset, topOffset, this->fox) &&
        !this->FoxValidMove(rightOffset, bottomOffset, this->fox)
    ) {
        return true;
    }

    return false;
}

void GameState::PlayWithAi(int x, int y) {
    int foxX = this->fox->getX();
    int foxY = this->fox->getY();

    if (this->IsValidMove(foxX - 1, foxY + 1, this->selectedPlayer)) {
        this->selectedPlayer->setX(x - 1);
        this->selectedPlayer->setY(y + 1);
    } else if (this->IsValidMove(foxX - 1, foxY + 1, this->selectedPlayer)) {
        this->selectedPlayer->setX(x + 1);
        this->selectedPlayer->setY(y + 1);
    }
}

bool GameState::HasFoxWin() {
    int x = this->fox->getX();
    int y = this->fox->getY();

    if (y == 8 && (x == 1 || x == 3 || x == 5|| x == 7)) {
        return true;
    }

    return false;
}

void GameState::UpdatePlayer(int x, int y) {
    if (this->IsPlayerSelected(x, y)) {
        this->selectedPlayer = this->GetPlayer(x, y);
    } else if(this->selectedPlayer != NULL) {
        if (this->IsValidMove(x, y, this->selectedPlayer)) {
            this->selectedPlayer->setX(x);
            this->selectedPlayer->setY(y);

            if (this->turn == PLAYER_1 && this->HasFoxWin()) {
                this->gameEnd = true;
                this->winner = PLAYER_1;
                cout << "Fox has Win" << endl;
            } else if (this->turn == PLAYER_1 && this->HasDogsWin()) {
                this->gameEnd = true;
                this->winner = PLAYER_2;
                cout << "Dogs has win" << endl;
             }

            this->NextTurn();
            this->selectedPlayer = NULL;
        }
    }
}
