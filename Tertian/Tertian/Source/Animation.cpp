#include "Animation.h"

Animation::Animation(){}
Animation::~Animation(){
	for(int i = m_frames.size()-1; i > -1; i--)
		delete[] m_frames.at(i);
	m_frames.clear();
}
int Animation::LoadAnimation(char* animation_name)
{
	char path[MAX_PATH_LENGTH];

	for(int i = 0; i < MAX_PATH_LENGTH; i++)
		path[i] = '\0';

	strcat(path, ANIMATION_DIRECTORY);
	strcat(path, animation_name);
	strcat(path, ANIMATION_EXTENSION);	

	bool success = m_fileReader.OpenFile(path);
	if(success)
		success = m_fileReader.TokenizeFile();
	if(!success)
		return -1;
	else{
		//assign the fields to the animation
		for(unsigned int i = 0; i < m_fileReader.GetTotalTokens(); i++){
			if(m_fileReader.GetToken(i) == "FRAME"){
				char* frame_name = new char[MAX_PATH_LENGTH];
				strcpy(frame_name, m_fileReader.GetToken(i+1).c_str());
				m_frames.push_back(frame_name);
				
			}
		}
	}

	return 0;
}
char* Animation::GetFrameName(unsigned int index)
{
	return m_frames.at(index);
}
unsigned int Animation::GetFrameCount()
{
	return m_frames.size();
}
bool Animation::UpdateAnimation(float delta_time)
{
	cout << delta_time << endl;
	return false;

}