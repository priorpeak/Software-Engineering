#ifndef GAMECOMMAND_H
#define GAMECOMMAND_H

#include "Pokemon.h"
#include "Model.h"
// #include "View.h"

void DoMoveCommand(Model&, int, Point2D);
void DoMoveToCenterCommand(Model&, int, int);
void DoMoveToGymCommand(Model&, int, int);
void DoStopCommand(Model&, int);
void DoTrainInGymCommand(Model&, int, unsigned int);
void DoRecoverInCenterCommand(Model&, int, unsigned int);
// void DoGoCommand(Model&, View&);
// void DoRunCommand(Model&, View&); 

#endif