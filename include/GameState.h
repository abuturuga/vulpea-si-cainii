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
        bool HasUpdates();
        void SetHasUpdates(bool hasUpdates);
        void UpdatePlayer(int x, int y);

        bool HasFoxWin();

        bool gameEnd;
        int winner;

    private:
        bool IsPlayerSelected(int x, int y);
        bool IsValidMove(int x, int y, GameObject* player);
        GameObject *GetPlayer(int x, int y);
        void PlayWithAi(int x, int y);

        bool FoxValidMove(int x, int y, GameObject* player);
        bool DogValidMove(int x, int y, GameObject* player);
        bool HasHitPlayer(int x, int y);
        bool HasDogsWin();
        bool hasUpdates;
        int turn;

        GameObject* selectedPlayer;
        GameObject* fox;
        GameObject* dogs[4];
};

#endif // GAMESTATE_H
