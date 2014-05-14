//
//  grass.cpp
//  multi-agent-system
//
//  Created by Ixi on 14/05/14.
//
//

#include "grass.h"

Grass::Grass()
{
    life_ = rand() % 10;
}

void Grass::change_state()
{
    if (life_ < 10)
        ++life_;
}

unsigned int Grass::get_life()
{
    return life_;
}