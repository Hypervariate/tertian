#ifndef ANIMATIONCOLLECTION_H_
#define ANIMATIONCOLLECTION_H_

#include "Animation.h"
#include <map>

#include <string>
using namespace std;

class AnimationCollection{
public:
	AnimationCollection();
	~AnimationCollection();

	bool InsertAnimation(string animation_name);
	
	void StopActiveAnimation();
	void PauseActiveAnimation();
	void PlayActiveAnimation();

	void SetActiveAnimation(string active_animation);
	string UpdateActiveAnimation(float delta_time);

private:
	Animation* GetActiveAnimation();
	map<string, Animation> m_animationMap;
	string m_activeAnimationName;
};

#endif