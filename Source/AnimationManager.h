#ifndef ANIMATIONMANAGER_H
#define ANIMATIONMANAGER_H

#include "axmol.h"

USING_NS_AX;

class AnimationManager
{
public:
    static AnimationManager& getInstance();
    void loadAnimations();
    Animate* getAnimateAction(const std::string& key);

private:
    void loadConsumables();
    void loadPlayer();
    void loadPngAnimation(const std::string&, int frameCount, int width, int height, float rate=0.1f);

    AnimationManager()                                   = default;
    ~AnimationManager()                                  = default;
    AnimationManager(const AnimationManager&)            = delete;
    AnimationManager& operator=(const AnimationManager&) = delete;
};

#endif  // ANIMATIONMANAGER_H
