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
#include <QApplication>
#include "cellular/grid_cellular.h"
#include "animal/grid_animal.h"

class Menu : public QWidget
{
    Q_OBJECT
public:
    Menu();
    void keyPressEvent(QKeyEvent* event);

public slots:
    void handle_cellular();
    void handle_animal();

private:
    QPushButton b_cellular_;
    QPushButton b_animal_;
    QVBoxLayout layout_;
    GridCellular g_cellular_;
    GridAnimal g_animal_;
};

#endif /* defined(__multi_agent_system__menu__) */
