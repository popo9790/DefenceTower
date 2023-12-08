#ifndef SpawnEnemy_hpp
#define SpawnEnemy_hpp

#include "Enemy.hpp"
#include "WhiteNormalEnemy.hpp"

class SpawnEnemy : public Enemy{
protected:
    virtual void OnExplode();
public:
    SpawnEnemy(int x,int y);
};

#endif /* SpawnEnemy_hpp */
