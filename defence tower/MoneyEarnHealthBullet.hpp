#ifndef MoneyEarnHealthBullet_hpp
#define MoneyEarnHealthBullet_hpp
#include "Bullet.hpp"

class Enemy;
class Turret;
namespace Engine {
    struct Point;
}  // namespace Engine

class MoneyHealth : public Bullet{
public:
    explicit MoneyHealth(Engine::Point position, Engine::Point forwardDirection, float rotation, Turret* parent);
};

#endif /* MoneyEarnHealthBullet_hpp */
