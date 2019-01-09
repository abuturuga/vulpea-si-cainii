#include "Field.h"
#include <iostream>
#include <graphics.h>
#include <winbgim.h>
#include <math.h>

using namespace std;

Field::Field()
{

}

Field::~Field()
{
    //dtor
}

void Field::Draw() {
    float x;
    float y;
    for (int rowIndex = 0; rowIndex < Field::rows; rowIndex++) {
        x = this->rowOffset * rowIndex;
        for (int colIndex = 0; colIndex < Field::cols; colIndex++) {
            y = this->colOffset * colIndex;
            line(x, y, x, this->height);
            line(x, y, this->width, y);
        }
    }
}

void Field::setDimensions(int width, int height) {
    this->width = width;
    this->height = height;

    this->setOffsets(
        this->width / Field::rows,
        this->height / Field::cols
    );
}

void Field::setOffsets(float rowOffset, float colOffset) {
    this->rowOffset = rowOffset;
    this->colOffset = colOffset;
}

void Field::renderGameState(GameState* gameState) {
    float circleRadius = this->rowOffset / 3;
    float xOffset = this->rowOffset / 2;
    float yOffset = this->colOffset / 2;

    GameObject* fox = gameState->getFox();
    float x = fox->getX() * this->rowOffset - xOffset;
    float y = fox->getY() * this->colOffset - yOffset;

    setfillstyle(SOLID_FILL, RED);
    circle(x, y, circleRadius);
    floodfill(x, y, WHITE);

    GameObject* dog;
    for(int i = 0; i < 4; i++) {
        dog = gameState->getDog(i);
        x = dog->getX() * this->rowOffset - xOffset;
        y = dog->getY() * this->colOffset - yOffset;
        setfillstyle(SOLID_FILL, GREEN);
        circle(x, y, circleRadius);
        floodfill(x, y, WHITE);
    }
}

int Field::getFieldX(int mouseX) {
    return floor(mouseX / this->rowOffset) + 1;
}

int Field::getFieldY(int mouseY) {
    return floor(mouseY / this->colOffset) + 1;
}


