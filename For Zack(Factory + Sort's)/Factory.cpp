#include "Factory.h"
#include <exception>



Factory::Factory()
{
}


Factory::~Factory()
{
}

Enemy * Factory::makeEnemy(EnemyTypes type)
{
    Enemy *pEnemy = nullptr;

    switch (type)
    {
    case EnemyTypes::Dragon:
        pEnemy = new Dragon;
        break;

    case EnemyTypes::Shark:
        pEnemy = new Shark;
        break;

    case EnemyTypes::Orc:
        pEnemy = new Orc;
        break;

    default:
        // If we get to here, then we have an unknown value in 'type'
        throw std::exception("unknown enemy type!!!!");
    }

    // If we get here, then we have a valid enemy object
    pEnemy->health = rand() % 100;

    return pEnemy;

}
