#ifndef Boss_hpp
#define Boss_hpp

#include "Enemy.hpp"

class Boss : public Enemy{
private:
    float TimeCounter;
public:
    Boss(int x,int y);
    void Update(float deltaTime) override;
};
#endif /* Boss_hpp */
