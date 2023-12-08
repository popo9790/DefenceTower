#include <allegro5/base.h>
#include <cmath>
#include <string>

#include "Point.hpp"
#include "AudioHelper.hpp"
#include "WoodBullet.hpp"
#include "Group.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"

#include "Shifter.hpp"

const int Shifter::Price = 0;
Shifter::Shifter(float x,float y)
    : Turret("play/shifter.png", "play/shifter.png", x, y, 0, Price, 2)
{Anchor.y += 8.0f / GetBitmapHeight();}

void Shifter::CreateBullet(){}


