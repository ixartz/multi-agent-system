//
//  grid_animal.cpp
//  multi-agent-system
//
//  Created by Ixi on 13/05/14.
//
//

#include "grid_animal.h"

GridAnimal::GridAnimal()
{
    setFixedSize(get_kwindows_size(),
                 get_kwindows_size());
}

void GridAnimal::paintEvent(QPaintEvent*)
{
    QPainter painter(this);

    draw_line(painter);

    for (int j = 0; j < get_kgrid_size(); ++j)
    {
        for (int i = 0; i < get_kgrid_size(); ++i)
        {
            paint_cell(painter, i, j, Qt::gray);
        }
    }
}

unsigned short GridAnimal::get_kgrid_size()
{
    return kgrid_size;
}

unsigned short GridAnimal::get_kcell_size()
{
    return kcell_size;
}

unsigned short GridAnimal::get_kwindows_size()
{
    return kgrid_size * kcell_size;
}