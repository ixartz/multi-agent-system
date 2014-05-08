//
//  grid.cpp
//  multi-agent-system
//
//  Created by Ixi on 08/05/14.
//
//

#include "grid.h"

Grid::Grid()
    : grid_(Grid::kgrid_size)
{
    for (int j = 0; j < Grid::kgrid_size; ++j)
    {
        for (int i = 0; i < Grid::kgrid_size; ++i)
        {
            grid_[j].push_back(Cell());
        }
    }
}

void Grid::next_state()
{
    for (int j = 0; j < Grid::kgrid_size; ++j)
    {
        for (int i = 0; i < Grid::kgrid_size; ++i)
        {
            calculate_neighbour(grid_[j][i], i, j);
        }
    }

    for (int j = 0; j < Grid::kgrid_size; ++j)
    {
        for (int i = 0; i < Grid::kgrid_size; ++i)
        {
            grid_[j][i].change_state();
        }
    }
}

void Grid::calculate_neighbour(Cell& c, int x, int y)
{
    c.get_neighbor().clear();

    for (int j = -1; j <= 1; ++j)
    {
        for (int i = -1; i <= 1; ++i)
        {
            if ((j != 0 || i != 0) &&
                (x + i >= 0 && x + i < Grid::kgrid_size &&
                 y + j >= 0 && y + j < Grid::kgrid_size))
            {
                c.get_neighbor().push_back(grid_[y + j][x + i].get_state());
            }
        }
    }
}

void Grid::print()
{
    for (int j = 0; j < Grid::kgrid_size; ++j)
    {
        std::cout << "|";

        for (int i = 0; i < Grid::kgrid_size; ++i)
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