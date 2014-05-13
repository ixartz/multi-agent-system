//
//  menu.cpp
//  multi-agent-system
//
//  Created by Ixi on 12/05/14.
//
//

#include "menu.h"

Menu::Menu()
    : b_(this)
{
    setFixedSize(150, 150);
    show();

    b_.setText("Cellular");
    QObject::connect(&b_, SIGNAL(pressed()), this, SLOT(handle_cellular()));
    layout_.addWidget(&b_);

    setLayout(&layout_);
}

void Menu::keyPressEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_Escape)
    {
        QApplication::exit();
    }
}

void Menu::handle_cellular()
{
    g_.show();
}