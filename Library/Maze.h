#ifndef Maze_h
#define Maze_h
#include <fstream>
#include "Position.h"

class Invalid{};

class Maze
{
private:
	static const int dimRow=9;
	static const int dimColumn=9;
	char m[dimRow][dimColumn];
    
public:
	explicit Maze(std::ifstream& f);
	bool isWall(int row, int column) const;
	position getPositionStart() const;
	bool isExit(int row, int column) const;
    std::string getString() const;
    std::string getStringWithRobot(position r) const;
};

std::ostream& operator<<(std::ostream& o,const Maze& m);
#endif
