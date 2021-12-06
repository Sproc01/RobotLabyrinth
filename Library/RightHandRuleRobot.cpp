#include "RightHandRuleRobot.h"
#include "Maze.h"
#include "Robot.h"
#include "Position.h"


RightHandRuleRobot::RightHandRuleRobot(const Maze& f)
{
    position p=f.getPositionStart();
    row=p.row;
    column=p.column;
    d=Direction::high;
}

void RightHandRuleRobot::move(const Maze& f)
{
    bool moveTrue=true;
	if(f.isWall(row-1, column) || f.isWall(row+1, column) || f.isWall(row, column+1) || f.isWall(row, column-1) || f.isWall(row-1, column-1) || f.isWall(row-1, column+1) || f.isWall(row+1, column-1) || f.isWall(row+1, column+1))
    {
        switch (d) {
            case Direction::high:
                    if(f.isWall(row, column+1) && !f.isWall(row-1, column+1) && moveTrue)
                    {
                        diagRightHighMove();
                        moveTrue=false;
                    }
                    if(f.isWall(row-1, column+1) && !f.isWall(row-1, column) && moveTrue)
                    {
                        highMove();
                        moveTrue=false;
                    }
                    if(f.isWall(row-1, column) && !f.isWall(row-1, column-1) && moveTrue)
                    {
                        diagLeftHighMove();
                        moveTrue=false;
                    }
                    if(f.isWall(row-1, column-1) && !f.isWall(row, column-1) && moveTrue)
                    {
                        leftMove();
                        moveTrue=false;
                    }
                    if(f.isWall(row, column-1) && !f.isWall(row+1, column-1) && moveTrue)
                    {
                        diagLeftLowMove();
                        moveTrue=false;
                    }
                    if(f.isWall(row+1, column-1) && !f.isWall(row+1, column) && moveTrue)
                    {
                        lowMove();
                        moveTrue=false;
                    }
                    if(f.isWall(row+1, column) && !f.isWall(row+1, column+1) && moveTrue)
                    {
                        diagRightLowMove();
                        moveTrue=false;
                    }
                    if(f.isWall(row+1, column+1) && !f.isWall(row, column+1) && moveTrue)
                    {
                        rightMove();
                        moveTrue=false;
                    }
                break;
            case Direction::low:
                if(f.isWall(row, column-1) && !f.isWall(row+1, column-1) && moveTrue)
                {
                    diagLeftLowMove();
                    moveTrue=false;
                }
                if(f.isWall(row+1, column-1) && !f.isWall(row+1, column) && moveTrue)
                {
                    lowMove();
                    moveTrue=false;
                }
                if(f.isWall(row+1, column) && !f.isWall(row+1, column+1) && moveTrue)
                {
                    diagRightLowMove();
                    moveTrue=false;
                }
                if(f.isWall(row+1, column+1) && !f.isWall(row, column+1) && moveTrue)
                {
                    rightMove();
                    moveTrue=false;
                }
                if(f.isWall(row, column+1) && !f.isWall(row-1, column+1) && moveTrue)
                {
                    diagRightHighMove();
                    moveTrue=false;
                }
                if(f.isWall(row-1, column+1) && !f.isWall(row-1, column) && moveTrue)
                {
                    highMove();
                    moveTrue=false;
                }
                if(f.isWall(row-1, column) && !f.isWall(row-1, column-1) && moveTrue)
                {
                    diagLeftHighMove();
                    moveTrue=false;
                }
                if(f.isWall(row-1, column-1) && !f.isWall(row, column-1) && moveTrue)
                {
                    leftMove();
                    moveTrue=false;
                }
                break;
            case Direction::right:
                if(f.isWall(row+1, column) && !f.isWall(row+1, column+1) && moveTrue)
                {
                    diagRightLowMove();
                    moveTrue=false;
                }
                if(f.isWall(row+1, column+1) && !f.isWall(row, column+1) && moveTrue)
                {
                    rightMove();
                    moveTrue=false;
                }
                if(f.isWall(row, column+1) && !f.isWall(row-1, column+1) && moveTrue)
                {
                    diagRightHighMove();
                    moveTrue=false;
                }
                if(f.isWall(row-1, column+1) && !f.isWall(row-1, column) && moveTrue)
                {
                    highMove();
                    moveTrue=false;
                }
                if(f.isWall(row-1, column) && !f.isWall(row-1, column-1) && moveTrue)
                {
                    diagLeftHighMove();
                    moveTrue=false;
                }
                if(f.isWall(row-1, column-1) && !f.isWall(row, column-1) && moveTrue)
                {
                    leftMove();
                    moveTrue=false;
                }
                if(f.isWall(row, column-1) && !f.isWall(row+1, column-1) && moveTrue)
                {
                    diagLeftLowMove();
                    moveTrue=false;
                }
                if(f.isWall(row+1, column-1) && !f.isWall(row+1, column) && moveTrue)
                {
                    lowMove();
                    moveTrue=false;
                }
                break;
            case Direction::left:
                if(f.isWall(row-1, column) && !f.isWall(row-1, column-1) && moveTrue)
                {
                    diagLeftHighMove();
                    moveTrue=false;
                }
                if(f.isWall(row-1, column-1) && !f.isWall(row, column-1) && moveTrue)
                {
                    leftMove();
                    moveTrue=false;
                }
                if(f.isWall(row, column-1) && !f.isWall(row+1, column-1) && moveTrue)
                {
                    diagLeftLowMove();
                    moveTrue=false;
                }
                if(f.isWall(row+1, column-1) && !f.isWall(row+1, column) && moveTrue)
                {
                    lowMove();
                    moveTrue=false;
                }
                if(f.isWall(row+1, column) && !f.isWall(row+1, column+1) && moveTrue)
                {
                    diagRightLowMove();
                    moveTrue=false;
                }
                if(f.isWall(row+1, column+1) && !f.isWall(row, column+1) && moveTrue)
                {
                    rightMove();
                    moveTrue=false;
                }
                if(f.isWall(row, column+1) && !f.isWall(row-1, column+1) && moveTrue)
                {
                    diagRightHighMove();
                    moveTrue=false;
                }
                if(f.isWall(row-1, column+1) && !f.isWall(row-1, column) && moveTrue)
                {
                    highMove();
                    moveTrue=false;
                }
                break;
        }
    }
    else
        randomMove(f);
}

void RightHandRuleRobot::randomMove(const Maze& f)
{
    int r1,r2,ro,co;
    do {
        r1=rand()%3;
        r2=rand()%3;
        ro=row;
        co=column;
        switch (r1)
        {
            case 0:
                ro--;
                break;
            case 1:
                ro++;
                break;
            case 2:
                break;
        }
        switch (r2) {
            case 0:
                co++;
                break;
            case 1:
                co--;
                break;
            case 2:
                break;
        }
    } while (f.isWall(ro, co));
    column=co;
    row=ro;
    
}

void RightHandRuleRobot::highMove()
{
    d=Direction::high;
    row--;
}

void RightHandRuleRobot::lowMove()
{
    d=Direction::low;
    row++;
}
void RightHandRuleRobot::leftMove()
{
    d=Direction::left;
    column--;
}
void RightHandRuleRobot::rightMove()
{
    d=Direction::right;
    column++;
}
void RightHandRuleRobot::diagRightHighMove()
{
    column++;
    row--;
    d=Direction::right;
}
void RightHandRuleRobot::diagLeftHighMove()
{
    column--;
    row--;
    d=Direction::high;
}
void RightHandRuleRobot::diagRightLowMove()
{
    column++;
    row++;
    d=Direction::low;
}
void RightHandRuleRobot::diagLeftLowMove()
{
    column--;
    row++;
    d=Direction::left;
}

bool RightHandRuleRobot::isAtExit(const Maze& f) const
{
    return f.isExit(row, column);
}


/*if(!f.isWall(row-1, column-1) && row-1>-1 && column-1>0)
 diagLeftHighMove();
else if(!f.isWall(row-1, column) && row-1>-1)
 highMove();
else if(!f.isWall(row-1, column+1) && row-1>-1 && column+1<9)
 diagRightHighMove();
else if(!f.isWall(row, column+1) && column+1<9)
 rightMove();
else if(!f.isWall(row+1, column+1) && row+1<9 && column+1<9)
 diagRightLowMove();
else if(!f.isWall(row+1, column) && row+1<9)
 lowMove();
else if(!f.isWall(row+1, column-1)&& row+1<9 && column-1>-1)
 diagLeftLowMove();
else if(!f.isWall(row, column-1) && column-1>-1)
 leftMove();*/
