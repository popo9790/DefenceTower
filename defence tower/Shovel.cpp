#include <allegro5/base.h>
#include <cmath>
#include <string>

#include "Point.hpp"
#include "AudioHelper.hpp"
#include "WoodBullet.hpp"
#include "Group.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"

#include "Shovel.hpp"

const int Shovel::Price = 0;
Shovel::Shovel(float x,float y)
    : Turret("play/shovel.png", "play/shovel.png", x, y, 0, Price, 2)
{Anchor.y += 8.0f / GetBitmapHeight();}

void Shovel::CreateBullet(){}
