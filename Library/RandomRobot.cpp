#include "RandomRobot.h"
#include "Maze.h"
#include "Robot.h"
#include "Position.h"

RandomRobot::RandomRobot(const Maze& f)
{
    position p=f.getPositionStart();
	row=p.row;
	column=p.column;
}

void RandomRobot::move(const Maze& f)
{
	int r=0;
	int c=0;
	do
	{
		r=rand()%3;
		c=rand()%3;
        if(r==2)
            r=-1;
        if(c==2)
            c=-1;
    }while(f.isWall(row+r,column+c));
    row+=r;
    column+=c;
    
}
