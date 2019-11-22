#include "Pokemon.h"

int main () {

    PokemonCenter C1(1, Point2D(6, 6));     

    PokemonGym G1(10, 1, 1.6, 5, 1, Point2D(4, 7));

    Pokemon squishy("Squishy", 1, 'P', 1, Point2D(2, 1));

    C1.ShowStatus();
    PokemonCenter* pC1 = &C1;

    G1.ShowStatus();
    PokemonGym* pG1 = &G1;

    squishy.ShowStatus(); // stopped

    squishy.StartMovingToGym(pG1);
    squishy.Update();
    squishy.Update();
    squishy.Update();
    squishy.Update();
    squishy.Update();
    squishy.Update(); // squishy has reached G1
    squishy.StartMovingToGym(pG1);

    squishy.StartTraining(4);
    squishy.Update();
    squishy.Update();

    squishy.StartTraining(10);
    squishy.Update();
    squishy.Update();

    squishy.StartTraining(3);
    squishy.Update();
    squishy.Update();

    G1.Update();
    G1.ShowStatus();

    squishy.StartMovingToCenter(pC1);
    G1.Update();
    G1.ShowStatus();
    squishy.Update();
    squishy.Update(); // squishy has reached C1
    squishy.StartMovingToCenter(pC1);

    C1.Update();
    C1.ShowStatus();

    squishy.StartRecoveringStamina(17);
    squishy.Update();
    squishy.Update();

    C1.Update();
    C1.ShowStatus();

    squishy.StartRecoveringStamina(17);
    squishy.Update();
    squishy.Update();

    return 0;
}