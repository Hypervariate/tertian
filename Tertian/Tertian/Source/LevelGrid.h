#ifndef LEVELGRID_H_
#define LEVELGRID_H_


#define MAX_LEVEL_SIZE 256

class LevelGrid{

public:
    LevelGrid(unsigned int x, unsigned int y, unsigned int z);
    ~LevelGrid();

public:
    unsigned int GetCell(unsigned int x, unsigned int y, unsigned int z);
    void SetCell(unsigned int x, unsigned int y, unsigned int z, unsigned int value);
	bool LevelGrid::IndexIsValid(unsigned int x, unsigned int y, unsigned int z);


	unsigned int GetSizeX();
	unsigned int GetSizeY();
	unsigned int GetSizeZ();

private:
    unsigned int ***array3D;
	unsigned int m_sizeX;
	unsigned int m_sizeY;
	unsigned int m_sizeZ;
};

#endif