//
//  grid.h
//  multi-agent-system
//
//  Created by Ixi on 08/05/14.
//
//

#ifndef __multi_agent_system__grid_cellular__
#define __multi_agent_system__grid_cellular__

#include <iostream>
#include <vector>
#include "base/grid.h"
#include "cell.h"

class GridCellular : public Grid
{
public:
    GridCellular();
    void next_state();
    void print();
    virtual void paintEvent(QPaintEvent*);
    virtual void keyPressEvent(QKeyEvent* event);
    void mousePressEvent(QMouseEvent* event);

    virtual unsigned short get_kgrid_size();
    virtual unsigned short get_kcell_size();
    virtual unsigned short get_kwindows_size();

private:
    static constexpr unsigned short kgrid_size = 30;
    static constexpr unsigned short kcell_size = 25;

    void calculate_neighbour_(Cell& c, int x, int y);
    std::vector<std::vector<Cell>> grid_;
};

#endif /* defined(__multi_agent_system__grid_cellular__) */
