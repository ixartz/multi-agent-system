//
//  grid_animal.cpp
//  multi-agent-system
//
//  Created by Ixi on 13/05/14.
//
//

#include "grid_animal.h"

GridAnimal::GridAnimal()
    : grid_(get_kgrid_size())
{
    for (int j = 0; j < get_kgrid_size(); ++j)
    {
        for (int i = 0; i < get_kgrid_size(); ++i)
        {
            grid_[j].push_back(Grass());
        }
    }

    setFixedSize(get_kwindows_size(),
                 get_kwindows_size());
}

void GridAnimal::next_state()
{
    for (int j = 0; j < get_kgrid_size(); ++j)
    {
        for (int i = 0; i < get_kgrid_size(); ++i)
        {
            grid_[j][i].change_state();
        }
    }
}

void GridAnimal::paintEvent(QPaintEvent*)
{
    QPainter painter(this);

    draw_line(painter);

    for (int j = 0; j < get_kgrid_size(); ++j)
    {
        for (int i = 0; i < get_kgrid_size(); ++i)
        {
            paint_cell(painter, i, j,
                       QColor(0, 255 * grid_[j][i].get_life() / 10, 0));
        }
    }
}

void GridAnimal::keyPressEvent(QKeyEvent* event)
{
    Grid::keyPressEvent(event);

    if (event->key() != Qt::Key_Escape)
    {
        next_state();
        update();
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