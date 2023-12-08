#ifndef NewTurrentLevel2_hpp
#define NewTurrentLevel2_hpp

#include "Turret.hpp"

class NewTurrentLevel2 : public Turret{
public:
    std::string flag;
    static const int Price;
    NewTurrentLevel2(float x, float y);
    void CreateBullet() override;
};

#endif /* NewTurrentLevel2_hpp */
