#ifndef NewTurrent_hpp
#define NewTurrent_hpp

#include "Turret.hpp"
#include <string>

class NewTurrent:public Turret{
public:
    std::string flag;
    static const int Price;
    NewTurrent(float x, float y);
    void CreateBullet() override;
};

#endif /* NewTurrent_hpp */
