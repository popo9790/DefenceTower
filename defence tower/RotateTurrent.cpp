#include <allegro5/base.h>
#include <cmath>
#include <string>

#include "AudioHelper.hpp"
#include "WoodBullet.hpp"
#include "Group.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"

#include "RotateTurrent.hpp"
#include "RotateBullet.hpp"
#include "FireBullet.hpp"

const int RotateTurrent::Price = 100;
RotateTurrent::RotateTurrent(float x, float y):
Turret("play/tower-base.png", "play/turret-3.png", x, y, 300, Price, 2),flag("RotateTurrent"),BulletNum(0)
    {Anchor.y += 8.0f / GetBitmapHeight();}

void RotateTurrent::CreateBullet(){
    // Change bullet position to the front of the gun barrel.
    getPlayScene()->BulletGroup->AddNewObject(new RotateBullet(Position + Engine::Point(0,-300),
                                                               Engine::Point(1,0), 0, this));
    getPlayScene()->BulletGroup->AddNewObject(new RotateBullet(Position + Engine::Point(300,0),
                                                               Engine::Point(0,1), 0, this));
    getPlayScene()->BulletGroup->AddNewObject(new RotateBullet(Position + Engine::Point(0,300),
                                                               Engine::Point(-1,0), 0, this));
    getPlayScene()->BulletGroup->AddNewObject(new RotateBullet(Position + Engine::Point(-300,0),
                                                               Engine::Point(0,-1), 0, this));
    BulletNum = 4;
    AudioHelper::PlayAudio("gun.wav");
}

void RotateTurrent::Update(float deltaTime){
    Sprite::Update(deltaTime);
    imgBase.Position = Position;
    imgBase.Tint = Tint;
    if (!Enabled)
        return;
    if(BulletNum <=0)
        this->CreateBullet();
}
