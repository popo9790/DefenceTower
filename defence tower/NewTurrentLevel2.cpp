#include <allegro5/base.h>
#include <cmath>
#include <string>

#include "Point.hpp"
#include "AudioHelper.hpp"
#include "WoodBullet.hpp"
#include "Group.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "FireBullet.hpp"

#include "NewTurrentLevel2.hpp"

const int NewTurrentLevel2::Price = 120;
NewTurrentLevel2::NewTurrentLevel2(float x, float y):
    Turret("play/tower-base.png", "play/turret-2.png", x, y, 250, Price, 2),flag("NewTurrent2")
    {Anchor.y += 8.0f / GetBitmapHeight();}

void NewTurrentLevel2::CreateBullet(){
    Engine::Point diff = Engine::Point(cos(Rotation - ALLEGRO_PI / 2), sin(Rotation - ALLEGRO_PI / 2)); //子彈前行方向
    Engine::Point unitVec1 = Engine::Point(cos(Rotation - ALLEGRO_PI / 2 + ALLEGRO_PI/12),
                                          sin(Rotation - ALLEGRO_PI / 2 + ALLEGRO_PI/12));
    Engine::Point unitVec2 = Engine::Point(cos(Rotation - ALLEGRO_PI / 2 - ALLEGRO_PI/12),
                                          sin(Rotation - ALLEGRO_PI / 2 - ALLEGRO_PI/12));
    float rotation = atan2(diff.y, diff.x);
    Engine::Point normalized_1 = unitVec1.Normalize();
    Engine::Point normalized_2 = unitVec2.Normalize();
    // Change bullet position to the front of the gun barrel.
    
    
    getPlayScene()->BulletGroup->AddNewObject(new FireBullet(Position + normalized_1 * 36, diff, rotation, this));
    getPlayScene()->BulletGroup->AddNewObject(new FireBullet(Position + normalized_2 * 36, diff, rotation, this));
    AudioHelper::PlayAudio("gun.wav");
}
