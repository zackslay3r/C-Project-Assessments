#pragma once

#include "Enemy.h"


// En enum is a number that can only assume certain values, or types.
enum class EnemyTypes {Dragon, Shark, Orc};

class Factory
{
public:
    Factory();
    virtual ~Factory();

    // Creates a new object of the specified type and returns
    // a pointer to the new object.
    // 'static' means that ths function is global, which means that
    // there is only one copy of this function.
    static Enemy *makeEnemy(EnemyTypes);
};

