#include <cmath>
#include <string>

#include "GameEngine.hpp"
#include "Group.hpp"
#include "IScene.hpp"
#include "PlayScene.hpp"
#include "Resources.hpp"
#include "ShootEffect.hpp"

PlayScene* ShootEffect::getPlayScene() {
    return dynamic_cast<PlayScene*>(Engine::GameEngine::GetInstance().GetActiveScene());
}

ShootEffect::ShootEffect(float x, float y, float rotation) :
    Sprite("play/shoot-1.png", x + Size.x * 2, y + Size.y * 2),
    timeTicks(0) {
    for (int i = 1; i <= 4; i++) {
        bmps.push_back(Engine::Resources::GetInstance().GetBitmap("play/shoot-" + std::to_string(i) + ".png"));
    }
}

void ShootEffect::Update(float deltaTime) {
    timeTicks += deltaTime;
    if (timeTicks >= timeSpan) {
        getPlayScene()->EffectGroup->RemoveObject(objectIterator);
        return;
    }
    int phase = floor(timeTicks / timeSpan * bmps.size());
    bmp = bmps[phase];
    Sprite::Update(deltaTime);
}
