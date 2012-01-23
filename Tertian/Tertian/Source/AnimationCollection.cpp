#include "AnimationCollection.h"

AnimationCollection::AnimationCollection()
{
	m_activeAnimationName = "";
}
AnimationCollection::~AnimationCollection()
{
	
}

bool AnimationCollection::InsertAnimation(string animation_name)
{
	
	Animation animation = Animation();
	bool success = Animation::LoadAnimation((char*)animation_name.c_str(), &animation);
	if(success){
		m_animationMap.insert(pair<string,Animation>(animation_name,animation));
		SetActiveAnimation(animation_name);
	}


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
    map<string, Animation>::iterator it;
    it = m_animationMap.find(active_animation_name);
    if(it != m_animationMap.end())
        m_activeAnimationName = active_animation_name;
}
string AnimationCollection::UpdateActiveAnimation(float delta_time)
{
	map<string,Animation>::iterator it;
	it = m_animationMap.find(m_activeAnimationName);
	string frame_name;
	if(it != m_animationMap.end()){
		frame_name = it->second.UpdateAnimation(delta_time);
	}
	return frame_name;
}
Animation* AnimationCollection::GetActiveAnimation()
{
	map<string, Animation>::iterator it;
    it = m_animationMap.find(m_activeAnimationName);
    return &it->second;

}