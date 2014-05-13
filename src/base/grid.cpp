//
//  grid.cpp
//  multi-agent-system
//
//  Created by Ixi on 13/05/14.
//
//

#include "grid.h"

void Grid::keyPressEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_Escape)
    {
        close();
    }
}

void Grid::paint_cell(QPainter& painter, int i, int j, Qt::GlobalColor c)
{
    painter.fillRect(get_kcell_size() * i, get_kcell_size() * j,
                     get_kcell_size() - 1, get_kcell_size() - 1,
                     c);
}

unsigned short Grid::get_kgrid_size()
{
    return kgrid_size;
}

unsigned short Grid::get_kcell_size()
{
    return kcell_size;
}

unsigned short Grid::get_kwindows_size()
{
    return kgrid_size * kcell_size;
}