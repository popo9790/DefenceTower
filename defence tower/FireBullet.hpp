#ifndef FireBullet_hpp
#define FireBullet_hpp

#include "Bullet.hpp"

class Enemy;
class Turret;
namespace Engine {
    struct Point;
}  // namespace Engine

class FireBullet : public Bullet{
public:
    explicit FireBullet(Engine::Point position, Engine::Point forwardDirection, float rotation, Turret* parent);
    void OnExplode(Enemy* enemy) override;
};

#endif /* FireBullet_hpp */
