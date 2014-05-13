//
//  menu.h
//  multi-agent-system
//
//  Created by Ixi on 12/05/14.
//
//

#ifndef __multi_agent_system__menu__
#define __multi_agent_system__menu__

#include <iostream>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include "cellular/grid_cellular.h"

class Menu : public QWidget
{
    Q_OBJECT
public:
    Menu();
    void keyPressEvent(QKeyEvent* event);

public slots:
    void handle_cellular();

private:
    QPushButton b_;
    QVBoxLayout layout_;
    GridCellular g_;
};

#endif /* defined(__multi_agent_system__menu__) */
