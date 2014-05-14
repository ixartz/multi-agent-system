//
//  grid_animal.h
//  multi-agent-system
//
//  Created by Ixi on 13/05/14.
//
//

#ifndef __multi_agent_system__grid_animal__
#define __multi_agent_system__grid_animal__

#include <iostream>
#include <QPaintEvent>
#include <QPainter>
#include "base/grid.h"
#include "animal/grass.h"

class GridAnimal : public Grid
{
public:
    GridAnimal();
    virtual void next_state();
    virtual void keyPressEvent(QKeyEvent* event);
    virtual void paintEvent(QPaintEvent*);

    virtual unsigned short get_kgrid_size();
    virtual unsigned short get_kcell_size();
    virtual unsigned short get_kwindows_size();

private:
    static constexpr unsigned short kgrid_size = 30;
    static constexpr unsigned short kcell_size = 25;

    std::vector<std::vector<Grass>> grid_;
};

#endif /* defined(__multi_agent_system__grid_animal__) */
