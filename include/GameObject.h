#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H


class GameObject
{
    public:
        GameObject();
        GameObject(int x, int y);
        virtual ~GameObject();
        void setX(int x);
        void setY(int y);
        int getX();
        int getY();
    protected:

    private:
        int x;
        int y;
        int type; // 1 for fox, 0 for dog
};

#endif // GAMEOBJECT_H
