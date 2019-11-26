#ifndef BUILDING_H
#define BUILDING_H

#include "GameObject.h"

class Building : public GameObject {
    public:
        Building();
        Building(char, int, Point2D);
        void AddOnePokemon();
        void RemoveOnePokemon();
        void ShowStatus();
        bool ShouldBeVisible();
    private:
        unsigned int pokemon_count;
};

#endif