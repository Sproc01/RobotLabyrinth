#ifndef RightHandRuleRobot_h
#define RightHandRuleRobot_h
#include "Robot.h"
#include "Maze.h"
#include "Position.h"
enum Direction
{high=0, right, left, low,};

class RightHandRuleRobot:public Robot
{
private:
    void randomMove(const Maze& f);
    Direction d;
    void leftMove();
    void rightMove();
    void highMove();
    void lowMove();
    void diagRightHighMove();
    void diagLeftHighMove();
    void diagRightLowMove();
    void diagLeftLowMove();
public:
    RightHandRuleRobot(const Maze& f);
	void move(const Maze& f) override;
    bool isAtExit(const Maze& f) const;
};

#endif
