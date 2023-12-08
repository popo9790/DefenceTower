#include <allegro5/base.h>
#include <cmath>
#include <string>

#include "AudioHelper.hpp"
#include "WoodBullet.hpp"
#include "Group.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "NewTurrent.hpp"
#include "FireBullet.hpp"

const int NewTurrent::Price = 60;
NewTurrent::NewTurrent(float x, float y):
    Turret("play/tower-base.png", "play/turret-1.png", x, y, 250, Price, 2),flag("NewTurrent1")
    {Anchor.y += 8.0f / GetBitmapHeight();}

void NewTurrent::CreateBullet(){
    Engine::Point diff = Engine::Point(cos(Rotation - ALLEGRO_PI / 2), sin(Rotation - ALLEGRO_PI / 2));
    float rotation = atan2(diff.y, diff.x);
    Engine::Point normalized = diff.Normalize();
    // Change bullet position to the front of the gun barrel.
    getPlayScene()->BulletGroup->AddNewObject(new FireBullet(Position + normalized * 36, diff, rotation, this));
    AudioHelper::PlayAudio("gun.wav");
}
