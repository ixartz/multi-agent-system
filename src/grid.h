//
//  grid.h
//  multi-agent-system
//
//  Created by Ixi on 08/05/14.
//
//

#ifndef __multi_agent_system__grid__
#define __multi_agent_system__grid__

#include <iostream>
#include <vector>
#include "cell.h"

class Grid
{
public:
    static constexpr unsigned short kgrid_size = 30;
    static constexpr unsigned short kcell_size = 25;
    static constexpr unsigned short kwindows_size = kgrid_size * kcell_size;

    Grid();
    void next_state();
    void print();

private:
    void calculate_neighbour(Cell& c, int x, int y);
    std::vector<std::vector<Cell>> grid_;
};

#endif /* defined(__multi_agent_system__grid__) */
