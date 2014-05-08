//
//  cell.h
//  multi-agent-system
//
//  Created by Ixi on 08/05/14.
//
//

#ifndef __multi_agent_system__cell__
#define __multi_agent_system__cell__

#include <iostream>
#include <algorithm>
#include <vector>

class Cell
{
public:
    enum state
    {
        dead, alive
    };

    Cell();
    void change_state();
    std::vector<Cell::state>& get_neighbor();
    Cell::state get_state();

private:
    std::vector<Cell::state> neighbor_;
    state state_;
};

#endif /* defined(__multi_agent_system__cell__) */
