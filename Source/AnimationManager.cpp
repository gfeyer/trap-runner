#include "AnimationManager.h"
#include "Constants.h"

AnimationManager& AnimationManager::getInstance()
{
    static AnimationManager instance;
    return instance;
}

void AnimationManager::loadAnimations() {
    loadConsumables();
}
void AnimationManager::loadConsumables() {

    // Load Copper Coin
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Content/res/animations/copper_coin.plist",
                                                             "Content/res/sprites/copper_coin.png");
    // Create and cache animations
    Vector<SpriteFrame*> coinFrames;
    coinFrames.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("copper_coin1.png"));
    coinFrames.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("copper_coin2.png"));
    coinFrames.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("copper_coin3.png"));
    coinFrames.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("copper_coin4.png"));

    auto coinAnimation = Animation::createWithSpriteFrames(coinFrames, 0.1f);  // 0.1 seconds per frame
    AnimationCache::getInstance()->addAnimation(coinAnimation, kAnimationKeys::COPPER_COIN);

    // Load ....

    // Load ...
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

