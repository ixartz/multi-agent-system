//
//  grass.h
//  multi-agent-system
//
//  Created by Ixi on 14/05/14.
//
//

#ifndef __multi_agent_system__grass__
#define __multi_agent_system__grass__

#include <iostream>

class Grass
{
public:
    Grass();
    void change_state();
    unsigned int get_life();

private:
    unsigned int life_;
};

#endif /* defined(__multi_agent_system__grass__) */
