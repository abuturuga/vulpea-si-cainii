#ifndef GAMESTATE_H
#define GAMESTATE_H
#include "GameObject.h"

class GameState
{
    public:
        GameState();
        virtual ~GameState();
        void setFox(int x, int y);
        GameObject* getFox();
        GameObject* getDog(int index);
        int GetTurn();
        void NextTurn();

    private:
        int turn;
        GameObject* fox;
        GameObject* dogs[4];
};

#endif // GAMESTATE_H
