#include "exercise3.h"

Exercise3::Exercise3(QWidget *parent)
    : QWidget(parent)
{
    setupLayout();
}

void Exercise3::setupLayout()
{
    mainLayout = new QHBoxLayout(this);
    mainLayout->setContentsMargins(15, 15, 15, 15);
    mainLayout->setSpacing(15);

    // Lewy panel
    panelBox = new QGroupBox("PŁYTA CZOŁOWA STANOWISKA", this);
    panelBox->setFixedWidth(420);
    panelBox->setStyleSheet(
        "QGroupBox {"
        "   border: 2px solid #3e3e42;"
        "   border-radius: 8px;"
        "   margin-top: 10px;"
        "   font-weight: bold;"
        "   color: #569cd6;"
        "}"
        "QGroupBox::title {"
        "   subcontrol-origin: margin;"
        "   left: 15px;"
        "   padding: 0 5px;"
        "}"
    );

    // Prawy panel
    chartBox = new QGroupBox("OBSZAR POMIAROWY (OSCYLOSKOP)", this);
    chartBox->setStyleSheet(
        "QGroupBox {"
        "   border: 2px solid #3e3e42;"
        "   border-radius: 8px;"
        "   margin-top: 10px;"
        "   font-weight: bold;"
        "   color: #4ec9b0;"
        "}"
        "QGroupBox::title {"
        "   subcontrol-origin: margin;"
        "   left: 15px;"
        "   padding: 0 5px;"
        "}"
    );

    mainLayout->addWidget(panelBox);
    mainLayout->addWidget(chartBox);
}