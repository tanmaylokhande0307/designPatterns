#ifndef Maze_H
#define Maze_H

#include <vector>
#include "Room.h"

class Maze
{
public:
    Maze();
    virtual Maze *Clone() const;
    Room *RoomNo(int n) const;
    void AddRoom(Room *room);

private:
    std::vector<Room *> *mRoomVec;
};

#endif