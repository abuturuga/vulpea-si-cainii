#include "GameObject.h"

GameObject::GameObject()
{
}

GameObject::GameObject(int x, int y)
{
    this->x = x;
    this->y = y;
}

GameObject::~GameObject()
{
    //dtor
}

void GameObject::setX(int x) {
    this->x = x;
}

void GameObject::setY(int y) {
    this->y = y;
}

int GameObject::getX() {
    return this->x;
}

int GameObject::getY() {
    return this->y;
}
