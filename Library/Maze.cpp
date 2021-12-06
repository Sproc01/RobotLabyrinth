#include "Maze.h"
#include <fstream>
#include "Position.h"
#include "Robot.h"

using namespace std;

Maze::Maze(ifstream& f)
{
	if(f.is_open())
			for(int i=0;i<dimRow;i++)
			{
				for(int j=0;j<dimColumn;j++)
					m[i][j]=f.get();
                if(f.peek()=='\n')
                    f.get();
			}
}

bool Maze::isWall(int row, int column) const
{
	if(m[row][column]=='*')
		return true;
	else
		return false;
}

position Maze::getPositionStart() const
{
    position p{};
	for(int i=0;i<dimRow;i++)
		for(int j=0;j<dimColumn;j++)
			if(m[i][j]=='S')
			{
                p.row=i;
                p.column=j;
			}
	return p;
}

bool Maze::isExit(int row, int column) const
{
	if(m[row][column]=='E')
		return true;
	else
		return false;
}

string Maze::getString() const
{
    string p="";
    p+="  012345678\n";
    for(int i=0; i<dimRow; i++)
    {
        p+=to_string(i)+"|";
        for(int j=0; j<dimColumn; j++)
            p+=m[i][j];
        p+="\n";
    }
    return p;
}

string Maze::getStringWithRobot(position r) const
{
    string p="";
    p+=" |012345678\n";
    p+="___________\n";
    for(int i=0; i<dimRow; i++)
    {
        p+=to_string(i)+"|";
        for(int j=0; j<dimColumn; j++)
            if(j==r.column && i==r.row)
                p+='R';
            else
                p+=m[i][j];
        p+="\n";
    }
    return p;
}

ostream& operator<<(ostream& o,const Maze& m)
{
    o<<m.getString();
    return o;
}
