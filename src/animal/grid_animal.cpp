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
    int x;
    int y;

    for (int j = 0; j < get_kgrid_size(); ++j)
    {
        for (int i = 0; i < get_kgrid_size(); ++i)
        {
            grid_[j].push_back(Grass(i, j));
        }
    }

    for (int j = 0; j < get_kgrid_size(); ++j)
    {
        for (int i = 0; i < get_kgrid_size(); ++i)
        {
            calculate_neighbour_(grid_[j][i], i, j);
        }
    }

    for (int i = 0; i < knb_sheep; ++i)
    {
        x = rand() % get_kgrid_size();
        y = rand() % get_kgrid_size();

        animal_vec_.push_back(Sheep(&grid_[y][x]));
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

    for (int i = 0; i < knb_sheep; ++i)
    {
        animal_vec_[i].move();
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

    for (int i = 0; i < knb_sheep; ++i)
    {
        paint_cell(painter, animal_vec_[i].get_pos()->get_x(),
                   animal_vec_[i].get_pos()->get_y(),
                   Qt::red);
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

void GridAnimal::calculate_neighbour_(Grass& c, int x, int y)
{
    if (is_valid_neighbour_(x - 1, y))
        c.get_neighbor().push_back(&grid_[y][x - 1]);

    if (is_valid_neighbour_(x, y - 1))
        c.get_neighbor().push_back(&grid_[y - 1][x]);

    if (is_valid_neighbour_(x, y + 1))
        c.get_neighbor().push_back(&grid_[y + 1][x ]);

    if (is_valid_neighbour_(x + 1, y))
        c.get_neighbor().push_back(&grid_[y][x + 1]);
}

bool GridAnimal::is_valid_neighbour_(int x, int y)
{
    return (x >= 0 && x < get_kgrid_size() &&
            y >= 0 && y < get_kgrid_size());
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