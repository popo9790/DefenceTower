#ifndef Shifter_hpp
#define Shifter_hpp

#include "Turret.hpp"

class Shifter : public Turret{
public:
    static const int Price;
    Shifter(float x, float y);
    void CreateBullet() override;
};

#endif /* Shifter_hpp */
