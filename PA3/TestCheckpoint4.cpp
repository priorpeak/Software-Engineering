#include "Pokemon.h"
#include "GameCommand.h"

int main() {
    char command;

    int id, id1, id2, x, y;
    unsigned int stamina_amount, unit_amount;

    Model mainModel = Model();

    do {
        cout << "Please enter a command character: ";
        cin >> command;
        switch (command) {
            case 'm':
                cout << "Input move paramters <Pokemon ID> <X Coordinate> <Y Coordinate>: ";
                cin >> id >> x >> y;
                DoMoveCommand(mainModel, id, Point2D(x, y));
                break;
            case 'g':
                cout << "Input move to Pokemon Gym parameters <Pokemon ID> <Gym ID>: ";
                cin >> id1 >> id2;
                DoMoveToGymCommand(mainModel, id1, id2);
                break;
            case 'c':
                cout << "Input move to Pokemon Center parameters <Pokemon ID> <Center ID>: ";
                cin >> id1 >> id2;
                DoMoveToCenterCommand(mainModel, id1, id2);
                break;
            case 's':
                cout << "Input a Pokemon's ID to stop it: ";
                cin >> id;
                DoStopCommand(mainModel, id);
                break;
            case 'r':
                cout << "Input recover at Pokemon Center parameters <Pokemon ID> <stamina_amount>: ";
                cin >> id1 >> stamina_amount;
                DoRecoverInCenterCommand(mainModel, id1, stamina_amount);
                break;
            case 't':
                cout << "Input training at Pokemon Gym parameters <Pokemon ID> <unit_amount>: ";
                cin >> id >> unit_amount;
                DoTrainInGymCommand(mainModel, id, unit_amount);
                break;
            // case 'v':
            //     DoGoCommand(mainModel, mainView);
            //     break;
            case 'x':
                if (!mainModel.Update()) {
                    for (int i = 0; i < 6; i++) {
                        // PLACEHOLDER
                    }
                }
                break;
            default:
                break;
        }
    } while (command != 'q');

    if (command == 'q') {
        mainModel.~Model();
        exit(0);
    }

    return 0;
}