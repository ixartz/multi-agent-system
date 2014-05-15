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
#include <vector>

class Grass
{
public:
    Grass(int x, int y);
    void change_state();
    unsigned int get_life();
    bool is_eaten();

    std::vector<Grass*>& get_neighbor();
    int get_x();
    int get_y();

private:
    unsigned int life_;
    std::vector<Grass*> neighbor_;
    int x_;
    int y_;
};

#endif /* defined(__multi_agent_system__grass__) */
