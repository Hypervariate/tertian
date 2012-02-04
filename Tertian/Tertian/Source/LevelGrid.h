#ifndef LEVELGRID_H_
#define LEVELGRID_H_

class LevelGrid{

public:
	LevelGrid();
    LevelGrid(unsigned int x, unsigned int y, unsigned int z);
    ~LevelGrid();
	void AllocateLevelGrid(unsigned int x, unsigned int y, unsigned int z);
	void DeallocateLevelGrid();

public:
    unsigned int GetCell(unsigned int x, unsigned int y, unsigned int z);
    void SetCell(unsigned int x, unsigned int y, unsigned int z, unsigned int value);
	bool LevelGrid::IndexIsValid(unsigned int x, unsigned int y, unsigned int z);

	unsigned int GetSizeX();
	unsigned int GetSizeY();
	unsigned int GetSizeZ();

private:
    unsigned int ****m_cells;
	unsigned int m_sizeX;
	unsigned int m_sizeY;
	unsigned int m_sizeZ;
};

#endif