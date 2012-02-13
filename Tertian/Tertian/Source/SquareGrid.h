#ifndef SQUAREGRID_H_
#define SQUAREGRID_H_

#include <vector>
using namespace std;

class SquareGrid{

public:
	SquareGrid();
    SquareGrid(unsigned int w, unsigned int h);
    ~SquareGrid();


	void AllocateSquareGrid(unsigned int w, unsigned int h);
    unsigned int GetCell(unsigned int x, unsigned int y);
    void SetCell(unsigned int x, unsigned int y, unsigned int value);
	unsigned int GetIndexFromCoordinate(unsigned int x, unsigned int y);
	bool IndexIsValid(unsigned int index);

	unsigned int GetSizeX();
	unsigned int GetSizeY();


private:
    vector<unsigned int> m_cells;
	unsigned int m_sizeX;
	unsigned int m_sizeY;

};

#endif