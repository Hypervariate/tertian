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
	bool success = false;

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
	return "librarian_idle_0";
}
Animation* AnimationCollection::GetActiveAnimation()
{
	map<string, Animation>::iterator it;
    it = m_animationMap.find(m_activeAnimationName);
    return &it->second;

}