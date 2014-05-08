//
//  cell.h
//  multi-agent-system
//
//  Created by Ixi on 08/05/14.
//
//

#include <iostream>
#include <QtGui/QApplication>
#include "grid.h"

int main()
{
    Grid g;
    g.print();

    while (getchar() != 27)
    {
        g.next_state();
        g.print();
    }

    return 0;
}