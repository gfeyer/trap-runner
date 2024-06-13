#include "AnimationManager.h"
#include "Constants.h"

#include <vector>
#include <string>
using namespace std;

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
    loadPngAnimation(kAnimationKeys::LUDIC_ATTACK, 10, 426, 512);
    loadPngAnimation(kAnimationKeys::LUDIC_DEATH, 10, 596, 517);
    loadPngAnimation(kAnimationKeys::LUDIC_IDLE, 10, 198, 500);
    loadPngAnimation(kAnimationKeys::LUDIC_JUMP, 10, 367, 512);
    loadPngAnimation(kAnimationKeys::LUDIC_RUN, 10, 450, 514);
    loadPngAnimation(kAnimationKeys::LUDIC_SLIDE, 10, 457, 284);
    loadPngAnimation(kAnimationKeys::LUDIC_WALK, 10, 223, 517);
    loadPngAnimation(kAnimationKeys::SPATTER, 10, 128, 128, 0.05f);
}

void AnimationManager::loadPngAnimation(const std::string& animationName, int frameCount, int width, int height, float rate) {

    // Create a vector to hold the sprite frames
    Vector<SpriteFrame*> frames;
    
    for (int i = 0; i < frameCount; ++i)
    {
        stringstream ss;
        ss << animationName << "_" << i << ".png";
        string frameName = ss.str();
        
        std::string framePath = StringUtils::format("Content/res/sprites/%s", frameName.c_str());
        SpriteFrameCache::getInstance()->addSpriteFrame(SpriteFrame::create(framePath, Rect(0, 0, width, height)),
                                                        frameName);
        // Load each frame from the SpriteFrameCache
        auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(frameName);
        frames.pushBack(frame);
    }
    
    // Create the animation from the frames
    auto animation = Animation::createWithSpriteFrames(frames, rate);  // 0.1 seconds per frame
    AnimationCache::getInstance()->addAnimation(animation, animationName);
    
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

