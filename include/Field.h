#ifndef FIELD_H
#define FIELD_H
#include "GameState.h"

class Field
{
    public:
        Field();
        virtual ~Field();
        void Draw();
        static const int rows = 8;
        static const int cols = 8;
        void setDimensions(int width, int height);
        void renderGameState(GameState* gameState);
        int getFieldX(int mouseX);
        int getFieldY(int mouseY);
    private:
        void setOffsets(float rowOffset, float colOffset);
        float rowOffset;
        float colOffset;
        int width;
        int height;
};

#endif // FIELD_H
