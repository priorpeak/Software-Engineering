#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Point2D.h"

class GameObject {
    protected:
        Point2D location;
        int id_num;
        char display_code;
        char state;

    public:
        GameObject(char);
        GameObject(Point2D, int, char);
        virtual ~GameObject();
        Point2D GetLocation();
        int GetId();
        char GetState();
        virtual void ShowStatus();
        virtual bool ShouldBeVisible() = 0;
        virtual bool Update() = 0;
        void DrawSelf(char*);
};

#endif