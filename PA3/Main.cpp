#include "Pokemon.h"
#include "GameCommand.h"
#include "View.h"

int main() {
    char command;

    int id, id1, id2, x, y;
    unsigned int stamina_amount, unit_amount;

    Model mainModel = Model();
    View mainView = View();

    // mainModel.ShowStatus();    Got another segfault from running this, troubleshot for days but could not figure it out. It worked before implementing the Model and View classes :(

    cout << endl << "EC327: Introduction to Software Engineering" << endl;
    cout << "Fall 2019" << endl;
    cout << "Programming Assignment 3" << endl << endl;

    do {
        cout << "Please enter a command character: ";
        cin >> command;
        switch (command) {
            case 'm':
                cout << "Input move paramters <Pokemon ID> <X Coordinate> <Y Coordinate>: ";
                cin >> id >> x >> y;
                DoMoveCommand(mainModel, id, Point2D(x, y));
                
                // Could not get the Plot() portion of mainModel.Display() to work :( (Seg fault, something to do with my pointers, I tried troubleshooting for days and was not able to reach a solution :(
                
                // mainModel.Display(mainView);
                break;
            case 'g':
                cout << "Input move to Pokemon Gym parameters <Pokemon ID> <Gym ID>: ";
                cin >> id1 >> id2;
                DoMoveToGymCommand(mainModel, id1, id2);
                // mainModel.Display(mainView);
                break;
            case 'c':
                cout << "Input move to Pokemon Center parameters <Pokemon ID> <Center ID>: ";
                cin >> id1 >> id2;
                DoMoveToCenterCommand(mainModel, id1, id2);
                // mainModel.Display(mainView);
                break;
            case 's':
                cout << "Input a Pokemon's ID to stop it: ";
                cin >> id;
                DoStopCommand(mainModel, id);
                // mainModel.Display(mainView);
                break;
            case 'r':
                cout << "Input recover at Pokemon Center parameters <Pokemon ID> <stamina_amount>: ";
                cin >> id1 >> stamina_amount;
                DoRecoverInCenterCommand(mainModel, id1, stamina_amount);
                // mainModel.Display(mainView);
                break;
            case 't':
                cout << "Input training at Pokemon Gym parameters <Pokemon ID> <unit_amount>: ";
                cin >> id >> unit_amount;
                DoTrainInGymCommand(mainModel, id, unit_amount);
                // mainModel.Display(mainView);
                break;
            case 'v':
                DoGoCommand(mainModel, mainView);
                // mainModel.Display(mainView);
                break;
            case 'x':
                DoRunCommand(mainModel, mainView);
                // mainModel.Display(mainView);
                break;
            default:
                break;
        }

        if (mainModel.Update())
            mainModel.ShowStatus();
    } while (command != 'q');

    if (command == 'q') {
        mainModel.~Model();
        exit(0);
    }

    return 0;
}