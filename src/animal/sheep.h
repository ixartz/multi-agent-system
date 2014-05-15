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

    void move();
    void eat();
    void reproduce();

    Grass* get_pos();

private:
    Grass* pos_;
};

#endif /* defined(__multi_agent_system__sheep__) */
