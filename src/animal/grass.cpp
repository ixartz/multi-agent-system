//
//  grass.cpp
//  multi-agent-system
//
//  Created by Ixi on 14/05/14.
//
//

#include "grass.h"

Grass::Grass(int x, int y)
    : x_(x), y_(y)
{
    life_ = rand() % 10;
}

void Grass::change_state()
{
    /* Grass grow up one time out of five */
    if (life_ < 10 && !(rand() % 2))
        ++life_;
}

unsigned int Grass::get_life()
{
    return life_;
}

bool Grass::is_eaten()
{
    if (life_ == 10)
    {
        life_ = 0;
        return true;
    }
    else
    {
        return false;
    }
}

std::vector<Grass*>& Grass::get_neighbor()
{
    return neighbor_;
}

int Grass::get_x()
{
    return x_;
}

int Grass::get_y()
{
    return y_;
}