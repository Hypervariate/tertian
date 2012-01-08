#include "AnimationCollection.h"

AnimationCollection::AnimationCollection()
{
	SetActiveAnimation("");
	m_animationMap.clear();
}
AnimationCollection::~AnimationCollection()
{
	map<string, Animation*>::iterator it;
	for ( it=m_animationMap.begin() ; it != m_animationMap.end(); it++ )
	{
		Animation* animation = it->second;
        delete animation;
        animation = NULL;
    }
	m_animationMap.clear();
}

bool AnimationCollection::InsertAnimation(string animation_name)
{
	Animation* animation = new Animation();
	bool success = Animation::LoadAnimation((char*)animation_name.c_str(), animation);
	if(success){
		m_animationMap.insert(pair<string,Animation*>(animation_name,animation));
		SetActiveAnimation(animation_name);
	}
	else
		delete animation;

	return success;
}
void AnimationCollection::StopActiveAnimation()
{
	Animation* animation = GetActiveAnimation();
	animation->StopAnimation();
}
void AnimationCollection::PauseActiveAnimation()
{
	Animation* animation = GetActiveAnimation();
	animation->PauseAnimation();
}
void AnimationCollection::PlayActiveAnimation()
{
	Animation* animation = GetActiveAnimation();
	animation->PlayAnimation();
}
void AnimationCollection::SetActiveAnimation(string active_animation_name)
{
	m_activeAnimationName = active_animation_name;
}
string AnimationCollection::UpdateActiveAnimation(float delta_time)
{
	string frame_name = "";
	Animation* animation = GetActiveAnimation();
	frame_name = animation->UpdateAnimation(delta_time);
	return frame_name;
}
Animation* AnimationCollection::GetActiveAnimation()
{
	return m_animationMap[m_activeAnimationName];
}