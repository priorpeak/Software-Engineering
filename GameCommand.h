#ifndef GAMECOMMAND_H
#define GAMECOMMAND_H

#include "Pokemon.h"
#include "Model.h"

void DoMoveCommand(Model&, int, Point2D);
void DoMoveToCenterCommand(Model&, int, int);
void DoMoveToArenaCommand(Model&, int, int);
void DoMoveToGymCommand(Model&, int, int);
void DoStopCommand(Model&, int);
void DoTrainInGymCommand(Model&, int, unsigned int);
void DoRecoverInCenterCommand(Model&, int, unsigned int);
void DoGoCommand(Model&, View&);
void DoRunCommand(Model&, View&); 
void DoStartBattle(Model&, int, int);

#endif