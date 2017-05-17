#include <iostream>
#include <vector> // Use the STL dynamic array (grows automatically)
#include "Factory.h"
//#include "Enemy.h"
#include <algorithm>



// Need a 'compare' function to use with std::sort.
// This MUST return a bool and take two parameters of the type 
// that is in teh vector that you are sorting.
bool myCompareFunction(Enemy *enemy1, Enemy *enemy2)
{

    //if (enemy1->health < enemy2->health)
    //{
    //    return true;
    //}
    //else
    //{
    //    return false;
    //}



    // OR!!!!

    // the standard shorthand of doing the same thing as above.
    // This will be a sort in ascending order
//    return ( enemy1->health < enemy2->health );

    // ...and this would be in descending order
    return (enemy2->health < enemy1->health);
}


int main()
{
    //---------------------------------------
    // The old 'C' way
    //---------------------------------------

    //Enemy *enemies[100];
    //int numEnemies = 0;

    //enemies[0] = new Dragon;
    //enemies[1] = new Shark;
    //enemies[2] = new Dragon;

    //numEnemies = 3;

    //for (int i = 0; i < numEnemies; i++)
    //{
    //    // Do something with 'ememies[i]'
    //}


    //---------------------------------------
    // With a dynamic array
    //---------------------------------------

    std::vector< Enemy * > enemies; // Declare a dynamic array of Enemy pointers

    // Add 3 new enemies to the end of the array
    //enemies.push_back(new Dragon);
    //enemies.push_back(new Shark);
    //enemies.push_back(new Dragon);

    // Use std::vector's 'size()' function to find out how many elements are in the array
    for (size_t i = 0; i < enemies.size(); i++)
    {
        // Do something with 'enemies[i]'
    }


    //---------------------------------------
    // With a Factory
    //---------------------------------------
    // Using a factory allows us to move all the 'new Dragon' calls (etc) 
    // to once place. Then we don't need to include "dragon.h" all over the place.

    try
    {
        // Note: an enum is just a number variable in disguise, but you use symbols with it
        EnemyTypes et = EnemyTypes::Dragon;
        if (et == EnemyTypes::Dragon)
        {
        }

        Enemy *p = Factory::makeEnemy(EnemyTypes::Dragon);
        enemies.push_back(p);

        // OR...
        enemies.push_back(Factory::makeEnemy(EnemyTypes::Dragon));
        enemies.push_back(Factory::makeEnemy(EnemyTypes::Shark));
        enemies.push_back(Factory::makeEnemy(EnemyTypes::Orc));
        enemies.push_back(Factory::makeEnemy(EnemyTypes::Orc));
        enemies.push_back(Factory::makeEnemy(EnemyTypes::Dragon));

        // Use std::vector's 'size()' function to find out how many elements are in the array
        for (size_t i = 0; i < enemies.size(); i++)
        {
            // Do something with 'enemies[i]'
        }





        // Example of a sort

        std::sort(enemies.begin(), enemies.end(), myCompareFunction);

        for (size_t i = 0; i < enemies.size(); i++)
        {
            std::cout << "Health = " << enemies[i]->health << "\n";
        }

        std::cout << "\n\nFinished\n\n";
    }
    catch (std::exception & e)
    {
        std::cout << "An exception occurred - " << e.what() << "\n\n";
    }
    catch (...) // Any other type of exception that we don't know about
    {
        std::cout << "An unhandled exception " << "\n\n";
    }
}