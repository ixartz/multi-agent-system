//
//  sheep.h
//  multi-agent-system
//
//  Created by Ixi on 13/05/14.
//
//

#ifndef __multi_agent_system__sheep__
#define __multi_agent_system__sheep__

#include <iostream>
#include "animal/grass.h"

class Sheep
{
public:
    Sheep(Grass* pos);

    bool move();
    void eat();
    void reproduce();
    void add_energy(int value);

    Grass* get_pos();

private:
    static constexpr unsigned short kmax_energy = 10;

    Grass* pos_;
    int energy_ = kmax_energy;
};

#endif /* defined(__multi_agent_system__sheep__) */
