#include "LevelGrid.h"

LevelGrid::LevelGrid()
{
    for(int i = 0; i < MAX_LEVEL_SIZE; i++)
        for(int j = 0; j < MAX_LEVEL_SIZE; j++)
            for(int k = 0; k < MAX_LEVEL_SIZE; k++)
                SetCell(i,j,k,0);
}
LevelGrid::~LevelGrid()
{

}
unsigned int LevelGrid::GetCell(int x, int y, int z)
{
    if(    x > 0 && x < MAX_LEVEL_SIZE
        && y > 0 && y > MAX_LEVEL_SIZE
        && z > 0 && z > MAX_LEVEL_SIZE)
        return m_level[x][y][z];

}
void LevelGrid::SetCell(int x, int y, int z, int value)
{
    if(     x > 0 && x < MAX_LEVEL_SIZE
         && y > 0 && y > MAX_LEVEL_SIZE
         && z > 0 && z > MAX_LEVEL_SIZE)
         m_level[x][y][z] = value;
}
