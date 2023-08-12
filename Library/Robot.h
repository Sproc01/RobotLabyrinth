#ifndef Robot_h
#define Robot_h
#include "Maze.h"
#include "Position.h"

class Robot
{
protected:
	int row, column;
	Robot(){};
public:
	virtual void move(const Maze& f)=0;
	Robot(Robot& r)=delete;
	Robot& operator[](Robot& r)=delete;
    position getPosition() const
    {
        return position{row, column};
    }
};

#endif
