#ifndef FastSpell_hpp
#define FastSpell_hpp

#include "Turret.hpp"

class FastSpell : public Turret{
public:
    static const int Price;
    FastSpell(float x, float y);
    void CreateBullet() override;
    void Update(float deltaTime) override;
    void Draw() const override;
};

#endif /* FastSpell_hpp */
