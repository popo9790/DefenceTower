#include <allegro5/base.h>
#include <random>
#include <string>

#include "DirtyEffect.hpp"
#include "Enemy.hpp"
#include "Group.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "MoneyEarnHealthBullet.hpp"

MoneyHealth::MoneyHealth(Engine::Point position, Engine::Point forwardDirection, float rotation, Turret* parent):
    Bullet("play/bullet-4.png", 350, -2, position, forwardDirection, rotation - ALLEGRO_PI / 2, parent) {}
