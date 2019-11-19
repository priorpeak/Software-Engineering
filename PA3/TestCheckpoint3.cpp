#include "Pokemon.h"

int main() {
    Pokemon Poke1 = Pokemon();
    Poke1.ShowStatus();

    Pokemon Poke2 = Pokemon('A');
    Poke2.ShowStatus();

    return 0;
}