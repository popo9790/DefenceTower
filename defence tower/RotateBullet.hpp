#ifndef RotateBullet_hpp
#define RotateBullet_hpp

#include "Bullet.hpp"

class Enemy;
class Turret;
namespace Engine {
    struct Point;
}  // namespace Engine

class RotateBullet : public Bullet {
public:
    explicit RotateBullet(Engine::Point position, Engine::Point forwardDirection, float rotation, Turret* parent);
    void OnExplode(Enemy* enemy) override;
    void Update(float deltaTime) override;
};

#endif /* RotateBullet_hpp */
