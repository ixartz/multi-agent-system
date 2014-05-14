//
//  menu.cpp
//  multi-agent-system
//
//  Created by Ixi on 12/05/14.
//
//

#include "menu.h"

Menu::Menu()
    : b_cellular_(this)
{
    setFixedSize(150, 150);
    show();

    b_cellular_.setText("Cellular");
    QObject::connect(&b_cellular_, SIGNAL(pressed()),
                     this, SLOT(handle_cellular()));
    layout_.addWidget(&b_cellular_);

    b_animal_.setText("Animal");
    QObject::connect(&b_animal_, SIGNAL(pressed()),
                     this, SLOT(handle_animal()));
    layout_.addWidget(&b_animal_);

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
    g_cellular_.show();
}

void Menu::handle_animal()
{
    g_animal_.show();
}