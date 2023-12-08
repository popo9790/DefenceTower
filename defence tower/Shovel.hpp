#ifndef Shovel_hpp
#define Shovel_hpp

#include "Turret.hpp"

class Shovel : public Turret{
public:
    static const int Price;
    Shovel(float x, float y);
    void CreateBullet() override;
};

#endif /* Shovel_hpp */
