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

void Sheep::move()
{
    int move = rand() % pos_->get_neighbor().size();
    pos_ = pos_->get_neighbor().at(move);
}

void Sheep::eat()
{

}

void Sheep::reproduce()
{

}

Grass* Sheep::get_pos()
{
    return pos_;
}