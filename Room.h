#ifndef ROOM_H
#define ROOM_H

#include "MapSite.h"
#include "MazeParts.h"

class Room : MapSite
{
public:
    Room(int n = 0);
    virtual Room *Clone() const;
    void SetSide(Direction direction, MapSite *ms);
    int GetRoomNo();
    virtual void Enter();

private:
    MapSite *_sides[4];
    int _roomNo;
};

#endif