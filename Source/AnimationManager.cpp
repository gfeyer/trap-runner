#include "AnimationManager.h"
#include "Constants.h"

// Use: https://ezgif.com/sprite-cutter

AnimationManager& AnimationManager::getInstance()
{
    static AnimationManager instance;
    return instance;
}

void AnimationManager::loadAnimations() {
    loadConsumables();
    loadPlayer();
}
void AnimationManager::loadConsumables() {

    // Load Copper Coin
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Content/res/animations/copper_coin.plist",
                                                             "Content/res/sprites/copper_coin.png");
    // Create and cache animations
    Vector<SpriteFrame*> frames;
    for (int i = 1; i <= 4; ++i)
    {
        auto frameName = StringUtils::format("copper_coin%d.png", i);
        frames.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName(frameName));
    }

    auto animation = Animation::createWithSpriteFrames(frames, 0.1f);  // 0.1 seconds per frame
    AnimationCache::getInstance()->addAnimation(animation, kAnimationKeys::COPPER_COIN);

    // Load ....

    // Load ...
}

void AnimationManager::loadPlayer() {
      // idle
    // Add individual PNG files to the SpriteFrameCache
    for (int i = 0; i < 10; ++i)
    {
        std::string frameName = StringUtils::format("ludic_idle_%d.png", i);
        std::string framePath = StringUtils::format("Content/res/sprites/%s", frameName.c_str());
        SpriteFrameCache::getInstance()->addSpriteFrame(SpriteFrame::create(framePath, Rect(0, 0, 198, 500)),
                                                        frameName);
    }

    // Create a vector to hold the sprite frames
    Vector<SpriteFrame*> frames;

    // Load each frame from the SpriteFrameCache
    for (int i = 0; i < 10; ++i)
    {
        std::string frameName = StringUtils::format("ludic_idle_%d.png", i);
        auto frame            = SpriteFrameCache::getInstance()->getSpriteFrameByName(frameName);
        frames.pushBack(frame);
    }

    // Create the animation from the frames
    auto animation = Animation::createWithSpriteFrames(frames, 0.1f);  // 0.1 seconds per frame
    AnimationCache::getInstance()->addAnimation(animation, kAnimationKeys::LUDIC_IDLE);


}

Animate* AnimationManager::getAnimateAction(const std::string& key)
{
    auto animation = AnimationCache::getInstance()->getAnimation(key);
    if (animation)
    {
        return ax::Animate::create(animation);
    }
    return nullptr;
}

