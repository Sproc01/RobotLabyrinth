//
//  main.cpp
//  RobotLabyrinth
//
//  Created by Michele Sprocatti on 04/12/21.
//
#include "../Library/Maze.h"
#include "../Library/Robot.h"
#include "../Library/RightHandRuleRobot.h"
#include "../Library/RandomRobot.h"
#include "../Library/Position.h"
#include <fstream>
#include <iostream>

using namespace std;
int main(int argc, const char * argv[])
{
    ifstream f{"test.txt"};
    Maze p{f};
    cout<<"Percorso:\n";
    cout<<p;
    RandomRobot r{p};
    r.move(p);
    RightHandRuleRobot rhr{p};
    while (!rhr.isAtExit(p)) {
        cout<<"---------------------------\n";
        rhr.move(p);
        cout<<p.getStringWithRobot(rhr.getPosition());
        position po=rhr.getPosition();
        cout<<"R("<<po.row<<","<<po.column<<")"<<"\n";
        
    }
    cout<<"\n";
    return 0;
}
