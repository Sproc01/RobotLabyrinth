#ifndef RandomRobot_h
#define RandomRobot_h
#include "Robot.h"
#include "Maze.h"

class RandomRobot:public Robot
{
public:
	RandomRobot(const Maze& f);
	void move(const Maze& f) override;
};

#endif
