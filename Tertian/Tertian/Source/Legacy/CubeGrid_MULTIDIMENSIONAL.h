#ifndef CUBEGRID_H_
#define CUBEGRID_H_

class CubeGrid{

public:
	CubeGrid();
    CubeGrid(unsigned int x, unsigned int y, unsigned int z);
    ~CubeGrid();
	void AllocateCubeGrid(unsigned int x, unsigned int y, unsigned int z);
	void DeallocateCubeGrid();

public:
    unsigned int GetCell(unsigned int x, unsigned int y, unsigned int z);
    void SetCell(unsigned int x, unsigned int y, unsigned int z, unsigned int value);
	bool CubeGrid::IndexIsValid(unsigned int x, unsigned int y, unsigned int z);

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