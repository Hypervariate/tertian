#include "LevelGrid.h"

LevelGrid::LevelGrid(unsigned int x, unsigned int y, unsigned int z)
{
	m_sizeX = x;
	m_sizeY = y;
	m_sizeZ = z;

    //  Allocate 3D Array
	m_cells = new unsigned int***[1];
	for(unsigned int i = 0; i < 1; i++)
	{
		m_cells[i] = new unsigned int**[x];
		for(unsigned int j = 0; j < x; j++)
        {
			m_cells[i][j] = new unsigned int*[y];
			for(unsigned int k = 0; k < y; k++)
			{
				m_cells[i][j][k] = new unsigned int[z];
			}
		}
    }

	for(unsigned int i = 0; i < x; i++)
		for(unsigned int j = 0; j < y; j++)
			for(unsigned int k = 0; k < z; k++)
				SetCell(i,j,k,1);

}
LevelGrid::~LevelGrid()
{
	for(unsigned int i = 0; i < 1; i++)
	{
		for(unsigned int j = 0; j < m_sizeX; j++)
		{
			for(unsigned int k = 0; k < m_sizeY; k++)
			{
				delete[] m_cells[i][j][k];
			}
			delete[] m_cells[i][j];
		}
		delete[] m_cells[i];
	}
	delete[] m_cells;
}
unsigned int LevelGrid::GetCell(unsigned int x, unsigned int y, unsigned int z)
{
	if(IndexIsValid(x,y,z))
		return m_cells[0][x][y][z];
	else
		return 0;
}
void LevelGrid::SetCell(unsigned int x, unsigned int y, unsigned int z, unsigned int value)
{
    if(IndexIsValid(x,y,z))
		m_cells[0][x][y][z] = value;
}
bool LevelGrid::IndexIsValid(unsigned int x, unsigned int y, unsigned int z)
{
	if(    x >= 0 && x < m_sizeX 
		&& y >= 0 && y < m_sizeY 
		&& z >= 0 && z < m_sizeZ)
		return true;
	else
		return false;
}
unsigned int LevelGrid::GetSizeX()
{
	return m_sizeX;
}
unsigned int LevelGrid::GetSizeY()
{
	return m_sizeY;
}
unsigned int LevelGrid::GetSizeZ()
{
	return m_sizeZ;
}