#ifndef LEVELGRID_H_
#define LEVELGRID_H_

#include <vector>
using namespace std;

#define MAX_LEVEL_SIZE 256

class LevelGrid{

public:
    LevelGrid();
    ~LevelGrid();

public:
    unsigned int GetCell(int x = 0, int y = 0, int z = 0);
    void SetCell(int x, int y, int z, int value);

private:
    int m_level[MAX_LEVEL_SIZE][MAX_LEVEL_SIZE][MAX_LEVEL_SIZE];
};

#endif