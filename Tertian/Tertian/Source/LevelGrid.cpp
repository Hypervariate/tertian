#include "LevelGrid.h"

LevelGrid::LevelGrid(unsigned int x, unsigned int y, unsigned int z)
{
	m_sizeX = x;
	m_sizeY = y;
	m_sizeZ = z;

    //  Allocate 3D Array
	array3D = new unsigned int**[x];

	for(unsigned int i = 0; i < x; i++)
	{
		array3D[i] = new unsigned int*[y];
		for(unsigned int j = 0; j < y; j++)
        {
			array3D[i][j] = new unsigned int[z];
		}
    }

	for(unsigned int i = 0; i < x; i++)
		for(unsigned int j = 0; j < y; j++)
			for(unsigned int k = 0; k < z; k++)
				array3D[i][j][k] = (i * y * z) + (j * z) + k;

}
LevelGrid::~LevelGrid()
{
	//  Deallocate 3D array
	for(unsigned int i = 0; i < m_sizeX; i++)
	{
		for(unsigned int j = 0; j < m_sizeY; j++)
        {
			delete[] array3D[i][j];
        }
		delete[] array3D[i];
	}
	delete[] array3D;

}
unsigned int LevelGrid::GetCell(unsigned int x, unsigned int y, unsigned int z)
{
	if(IndexIsValid(x,y,z))
		return array3D[x][y][z];
	else
		return 0;
}
void LevelGrid::SetCell(unsigned int x, unsigned int y, unsigned int z, unsigned int value)
{
    if(IndexIsValid(x,y,z))
		array3D[x][y][z] = value;
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