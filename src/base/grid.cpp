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

void Grid::paint_cell(QPainter& painter, int i, int j, QBrush&& c)
{
    painter.fillRect(get_kcell_size() * i, get_kcell_size() * j,
                     get_kcell_size() - 1, get_kcell_size() - 1,
                     c);
}

void Grid::draw_line(QPainter& painter)
{
    for (int i = 1; i < get_kgrid_size(); ++i)
    {
        painter.fillRect(get_kcell_size() * i - 1, 0,
                         1, get_kwindows_size(), Qt::black);
    }

    for (int j = 1; j < get_kgrid_size(); ++j)
    {
        painter.fillRect(0, get_kcell_size() * j - 1,
                         get_kwindows_size(), 1, Qt::black);
    }
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