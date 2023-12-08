#include <allegro5/base.h>
#include <random>
#include <string>

#include "DirtyEffect.hpp"
#include "Enemy.hpp"
#include "Group.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "Collider.hpp"

#include "RotateTurrent.hpp"
#include "RotateBullet.hpp"

class Turret;

RotateBullet::RotateBullet(Engine::Point position, Engine::Point forwardDirection, float rotation, Turret* parent) :
    Bullet("play/bullet-10.png", 300, 12, position, forwardDirection, rotation - ALLEGRO_PI / 2, parent) {
    // TODO 3 (2/5): You can imitate the 2 files: 'WoodBullet.hpp', 'WoodBullet.cpp' to create a new bullet.
}
void RotateBullet::OnExplode(Enemy* enemy) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(2, 5);
    getPlayScene()->GroundEffectGroup->AddNewObject(new DirtyEffect("play/dirty-1.png", dist(rng), enemy->Position.x, enemy->Position.y));
}

void RotateBullet::Update(float deltaTime){
    Sprite::Update(deltaTime);
    PlayScene* scene = getPlayScene();
    // Can be improved by Spatial Hash, Quad Tree, ...
    // However simply loop through all enemies is enough for this program.
    RotateTurrent* ptr = dynamic_cast<RotateTurrent*>(parent);
    
    Engine::Point ToCircleDir = Position - ptr->Position;
    float DeltaAcc_magnitude = Velocity.MagnitudeSquared() / ToCircleDir.Magnitude();
    
    ToCircleDir = ToCircleDir * -1;
    ToCircleDir = ToCircleDir.Normalize();
    
    Engine::Point DeltaAcc = DeltaAcc_magnitude * ToCircleDir;
    Engine::Point DeltaVelocity = DeltaAcc * deltaTime;
    
    Velocity = Velocity + DeltaVelocity;
    
    for (auto& it : scene->EnemyGroup->GetObjects()) {
        Enemy* enemy = dynamic_cast<Enemy*>(it);
        if (!enemy->Visible)
            continue;
        if (Engine::Collider::IsCircleOverlap(Position, CollisionRadius, enemy->Position, enemy->CollisionRadius)) {
            OnExplode(enemy);
            enemy->Hit(damage);
            getPlayScene()->BulletGroup->RemoveObject(objectIterator);
            ptr->BulletNum--;
            return;
        }
    }
    // Check if out of boundary.
    if (!Engine::Collider::IsRectOverlap(Position - Size / 2, Position + Size / 2,
                                         Engine::Point(0, 0), PlayScene::GetClientSize())){
        getPlayScene()->BulletGroup->RemoveObject(objectIterator);
        ptr->BulletNum--;
    }
}
