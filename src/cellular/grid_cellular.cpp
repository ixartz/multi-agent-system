//
//  grid.cpp
//  multi-agent-system
//
//  Created by Ixi on 08/05/14.
//
//

#include "grid_cellular.h"

GridCellular::GridCellular()
    : grid_(GridCellular::kgrid_size)
{
    for (int j = 0; j < GridCellular::kgrid_size; ++j)
    {
        for (int i = 0; i < GridCellular::kgrid_size; ++i)
        {
            grid_[j].push_back(Cell());
        }
    }

    setFixedSize(GridCellular::kwindows_size,
                 GridCellular::kwindows_size);
}

void GridCellular::next_state()
{
    for (int j = 0; j < GridCellular::kgrid_size; ++j)
    {
        for (int i = 0; i < GridCellular::kgrid_size; ++i)
        {
            calculate_neighbour(grid_[j][i], i, j);
        }
    }

    for (int j = 0; j < GridCellular::kgrid_size; ++j)
    {
        for (int i = 0; i < GridCellular::kgrid_size; ++i)
        {
            grid_[j][i].change_state();
        }
    }
}

void GridCellular::calculate_neighbour(Cell& c, int x, int y)
{
    c.get_neighbor().clear();

    for (int j = -1; j <= 1; ++j)
    {
        for (int i = -1; i <= 1; ++i)
        {
            if ((j != 0 || i != 0) &&
                (x + i >= 0 && x + i < GridCellular::kgrid_size &&
                 y + j >= 0 && y + j < GridCellular::kgrid_size))
            {
                c.get_neighbor().push_back(grid_[y + j][x + i].get_state());
            }
        }
    }
}

void GridCellular::print()
{
    for (int j = 0; j < GridCellular::kgrid_size; ++j)
    {
        std::cout << "|";

        for (int i = 0; i < GridCellular::kgrid_size; ++i)
        {
            if (grid_[j][i].get_state() == Cell::alive)
            {
                std::cout << "O";
            }
            else
            {
                std::cout << " ";
            }

            std::cout << "|";
        }

        std::cout << std::endl;
    }

    std::cout << std::endl;
}

void GridCellular::paintEvent(QPaintEvent*)
{
    QPainter painter(this);

    for (int i = 1; i < GridCellular::kgrid_size; ++i)
    {
        painter.fillRect(GridCellular::kcell_size * i - 1, 0,
                         1, kwindows_size, Qt::black);
    }

    for (int j = 1; j < GridCellular::kgrid_size; ++j)
    {
        painter.fillRect(0, GridCellular::kcell_size * j - 1,
                         kwindows_size, 1, Qt::black);
    }

    for (int j = 0; j < GridCellular::kgrid_size; ++j)
    {
        for (int i = 0; i < GridCellular::kgrid_size; ++i)
        {
            if (grid_[j][i].get_state() == Cell::alive)
                paint_cell(painter, i, j, Qt::green);
            else
                paint_cell(painter, i, j, Qt::darkGreen);
        }
    }
}

void GridCellular::keyPressEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_Escape)
    {
        close();
    }
    else
    {
        next_state();
        update();
    }
}

void GridCellular::mousePressEvent(QMouseEvent* event)
{
    if (event->buttons() == Qt::LeftButton)
    {
        int i = event->pos().x() / kcell_size;
        int j = event->pos().y() / kcell_size;
        grid_[j][i].inverse_state();
        update();
    }
}

void GridCellular::paint_cell(QPainter& painter, int i, int j, Qt::GlobalColor c)
{
    painter.fillRect(kcell_size * i, kcell_size * j,
                     kcell_size - 1, kcell_size - 1,
                     c);
}