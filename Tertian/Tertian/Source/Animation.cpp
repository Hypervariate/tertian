#include "Animation.h"
FileReader Animation::m_fileReader;

Animation::Animation()
{
	m_frameRate = 0.8f;
	m_lastFrameTimeStamp = 0;
	m_frameIndex = 0;
	m_animationIsPlaying = true;
	m_behavior = REPEAT;
	m_direction = 1;
}
Animation::~Animation()
{
	ClearAnimation();
}
void Animation::ClearAnimation()
{
	for(int i = m_frames.size()-1; i > -1; i--)
		delete[] m_frames.at(i);
	m_frames.clear();
}
bool Animation::LoadAnimation(char* animation_name, Animation* animation)
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
		return false;
	else{
		//assign the fields to the animation
		for(unsigned int i = 0; i < m_fileReader.GetTotalTokens(); i++){
			if(m_fileReader.GetToken(i) == "FRAME"){
				char* frame_name = new char[MAX_PATH_LENGTH];
				strcpy(frame_name, m_fileReader.GetToken(i+1).c_str());
				animation->m_frames.push_back(frame_name);
				
			}
			if(m_fileReader.GetToken(i) == "FRAMERATE"){
				animation->m_frameRate = atof(m_fileReader.GetToken(i+1).c_str());
			}
			if(m_fileReader.GetToken(i) == "BEHAVIOR"){
				if(m_fileReader.GetToken(i+1) == "PLAY_ONCE")
					animation->m_behavior = PLAY_ONCE;
				else if(m_fileReader.GetToken(i+1) == "BOUNCE")
					animation->m_behavior = BOUNCE;
				else
					animation->m_behavior = REPEAT;
			}
		}
	}

	return true;
}
char* Animation::GetFrameName(unsigned int index)
{
	return m_frames.at(index);
}
unsigned int Animation::GetFrameCount()
{
	return m_frames.size();
}
char* Animation::UpdateAnimation(float delta_time)
{
	m_lastFrameTimeStamp += delta_time;
	
	//implement bouncing
	if(IsAnimationPlaying() && m_lastFrameTimeStamp >= m_frameRate){
		m_frameIndex = (m_frameIndex + m_direction) % GetFrameCount();
		m_lastFrameTimeStamp = 0;
	}
	
	if(m_behavior == PLAY_ONCE && m_frameIndex >= GetFrameCount() -1)
		PauseAnimation();
	if(m_behavior == BOUNCE && 
	  ((m_direction == 1 && m_frameIndex >= GetFrameCount() -1) || (m_direction == -1 && m_frameIndex <= 0)))
		m_direction *= -1;

	
	

	return GetFrameName(m_frameIndex);;

}
void Animation::PauseAnimation()
{
	m_animationIsPlaying = false;
}
void Animation::StopAnimation()
{
	m_animationIsPlaying = false;
	m_frameIndex = 0;
}
void Animation::PlayAnimation()
{
	m_animationIsPlaying = true;
}
bool Animation::IsAnimationPlaying()
{
	return m_animationIsPlaying;
}