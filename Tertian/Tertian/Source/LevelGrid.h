#ifndef LEVELGRID_H_
#define LEVELGRID_H_

#include "CubeGrid.h"
#include "Graphics.h"
#include <map>
#include <string>

class LevelGrid{

public:
	LevelGrid();
	~LevelGrid();

	bool LoadLevelGrid();
	bool UnloadLevelGrid();

	void RenderLevelGrid();

private:
	CubeGrid m_cubeGrid;
	unsigned int m_blockSize;

	//static xml file reader member to optionally read from files

	map<int, string> m_tileMap;	//map of tiles corresponding to the image names of the tiles

};

#endif