#ifndef BOMBED_MAZEFACTORY_H
#define BOMBED_MAZEFACTORY_H

#include "MazeFactory.h"

class Wall;
class Room;

class BombedMazeFactory: public MazeFactory {
    Wall* MakeWall() const;
    Room* MakeRoom(int n) const;
};

#endif