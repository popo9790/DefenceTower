#ifndef RotateTurrent_hpp
#define RotateTurrent_hpp

#include "Turret.hpp"
#include <string>

class RotateTurrent:public Turret{
public:
    std::string flag;
    static const int Price;
    int BulletNum;
    RotateTurrent(float x, float y);
    void CreateBullet() override;
    void Update(float deltaTime) override;
};

#endif /* RotateTurrent_hpp */
