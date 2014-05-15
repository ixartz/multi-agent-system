//
//  cell.cpp
//  multi-agent-system
//
//  Created by Ixi on 08/05/14.
//
//

#include "cell.h"

Cell::Cell()
{
    if (rand() % 2)
        state_ = alive;
    else
        state_ = dead;
}

void Cell::inverse_state()
{
    if (state_ == alive)
        state_ = dead;
    else
        state_ = alive;
}

void Cell::change_state()
{
    long nb = count(neighbor_state.begin(), neighbor_state.end(), alive);

    if (nb < 2)
    {
        state_ = dead;
    }
    else if (nb > 3)
    {
        state_ = dead;
    }
    else if (nb == 3)
    {
        state_ = alive;
    }
}

std::vector<Cell::state>& Cell::get_neighbor_state()
{
    return neighbor_state;
}

Cell::state Cell::get_state()
{
    return state_;
}