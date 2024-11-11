#ifndef Maze_H
#define Maze_H

#include <vector>

class Maze
{
public:
    Maze();
    virtual Maze* Clone() const;
};

#endif