//
//  sheep.cpp
//  multi-agent-system
//
//  Created by Ixi on 13/05/14.
//
//

#include "sheep.h"

Sheep::Sheep(Grass* pos)
    : pos_(pos)
{

}

bool Sheep::move()
{
    if (energy_ > 0)
    {
        --energy_;

        int move = rand() % pos_->get_neighbor().size();
        pos_ = pos_->get_neighbor().at(move);

        eat();

        return true;
    }
    else
    {
        return false;
    }
}

void Sheep::eat()
{
    if (pos_->is_eaten())
        add_energy(5);
}

void Sheep::reproduce()
{

}

void Sheep::add_energy(int value)
{
    energy_ += value;

    if (energy_ > kmax_energy)
        energy_ = kmax_energy;
}

Grass* Sheep::get_pos()
{
    return pos_;
}