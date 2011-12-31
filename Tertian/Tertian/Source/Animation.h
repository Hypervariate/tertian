#ifndef ANIMATION_H_
#define ANIMATION_H_

#include "FileReader.h"
#include "Utilities/GlobalDefines.h"

#define ANIMATION_DIRECTORY "Data/Animations/"
#define ANIMATION_EXTENSION ".txt"

class Animation{
public:
	Animation();
	~Animation();

	int LoadAnimation(char* animation_name);
	char* GetFrameName(unsigned int index);
	unsigned int GetFrameCount();

private:
	vector<char*> m_frames;
	FileReader m_fileReader;
};

#endif