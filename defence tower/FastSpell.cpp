#include <allegro5/color.h>
#include <allegro5/base.h>
#include <allegro5/allegro_primitives.h>
#include <cmath>
#include <string>

#include "Enemy.hpp"
#include "Collider.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "AudioHelper.hpp"
#include "WoodBullet.hpp"
#include "Group.hpp"
#include "IScene.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"

#include "MoneyEarnHealthBullet.hpp"
#include "FastSpell.hpp"

const int FastSpell::Price = 100;
FastSpell::FastSpell(float x,float y)
    : Turret("play/tower-base.png", "play/fastspell.png", x, y, 200, Price, 2)
{Anchor.y += 8.0f / GetBitmapHeight();}

void FastSpell::CreateBullet(){}

void FastSpell::Draw() const{
    if (Preview) {
        al_draw_filled_circle(Position.x, Position.y, CollisionRadius, al_map_rgba(0, 255, 0, 50));
    }
    else
        al_draw_filled_circle(Position.x, Position.y, CollisionRadius, al_map_rgba(0, 0, 255, 50));
    imgBase.Draw();
    Sprite::Draw();
    if (PlayScene::DebugMode) {
        // Draw target radius.
        al_draw_circle(Position.x, Position.y, CollisionRadius, al_map_rgb(0, 0, 255), 2);
    }
}


void FastSpell::Update(float deltaTime){
    Sprite::Update(deltaTime);
    PlayScene* scene = getPlayScene();
    imgBase.Position = Position;
    imgBase.Tint = Tint;
    if (!Enabled)
        return;
    reload -= deltaTime;
    if (reload <= 0) {
        // shoot.
        reload = coolDown;
        getPlayScene()->EarnMoney(10);
    }
}

