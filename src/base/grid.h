//
//  grid.h
//  multi-agent-system
//
//  Created by Ixi on 13/05/14.
//
//

#ifndef __multi_agent_system__grid__
#define __multi_agent_system__grid__

#include <iostream>
#include <QWidget>
#include <QKeyEvent>
#include <QPaintEvent>
#include <QPainter>

class Grid : public QWidget
{
public:
    virtual void paintEvent(QPaintEvent*) = 0;
    virtual void keyPressEvent(QKeyEvent* event);
    virtual void paint_cell(QPainter& painter, int i, int j, Qt::GlobalColor c);
    void draw_line(QPainter& painter);

    virtual unsigned short get_kgrid_size();
    virtual unsigned short get_kcell_size();
    virtual unsigned short get_kwindows_size();

private:
    static constexpr unsigned short kgrid_size = 10;
    static constexpr unsigned short kcell_size = 10;
};

#endif /* defined(__multi_agent_system__grid__) */
