#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QIcon>
#include <QScreen>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QStackedWidget>
#include <QFrame>
#include <QPixmap>
#include <QFont>
#include <QButtonGroup>

#include "exercise3.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/docs/app_icon.png"));

    Qt::WindowFlags flags = windowFlags();
    setWindowFlags(flags & ~Qt::WindowMinimizeButtonHint & ~Qt::WindowMaximizeButtonHint);
    QRect screenGeometry = QApplication::primaryScreen()->availableGeometry();
    this->setFixedSize(screenGeometry.width(), screenGeometry.height());

    this->setStyleSheet("QMainWindow { background-color: #1e1e1e; color: #ffffff; }");

    QWidget *centralWidget = new QWidget(this);
    this->setCentralWidget(centralWidget);
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);

    QFrame *headerFrame = new QFrame();
    headerFrame->setStyleSheet("background-color: #3e3e42; border-bottom: 1px solid #3e3e42;");
    headerFrame->setFixedHeight(80);
    QHBoxLayout *headerLayout = new QHBoxLayout(headerFrame);

    QLabel *logoLabel = new QLabel();
    QPixmap logoPixmap(":/docs/pg_transparent.png");
    if (!logoPixmap.isNull()) {
        logoLabel->setPixmap(logoPixmap.scaled(200, 60, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    } else {
        logoLabel->setText(" LOGO PG ");
        logoLabel->setStyleSheet("color: red; font-weight: bold;");
    }

    QLabel *titleLabel = new QLabel("Wirtualne Laboratorium Podstaw Automatyki");
    titleLabel->setStyleSheet("font-size: 22px; font-weight: bold; color: #ffffff; border: none;");

    headerLayout->addWidget(logoLabel);
    headerLayout->addSpacing(20);
    headerLayout->addWidget(titleLabel);
    headerLayout->addStretch();

    mainLayout->addWidget(headerFrame);

    QHBoxLayout *bodyLayout = new QHBoxLayout();
    bodyLayout->setContentsMargins(0, 0, 0, 0);
    bodyLayout->setSpacing(0);

    QFrame *sidebar = new QFrame();
    sidebar->setFixedWidth(280);
    sidebar->setStyleSheet(
        "QFrame { background-color: #2d2d30; border-right: 1px solid #3e3e42; }"
        "QPushButton {"
        "   background-color: transparent;"
        "   color: #cccccc;"
        "   padding: 15px 20px;"
        "   text-align: left;"
        "   font-size: 15px;"
        "   font-weight: bold;"
        "   border: none;"
        "}"
        "QPushButton:hover {"
        "   background-color: #3e3e42;"
        "   color: #ffffff;"
        "}"
        "QPushButton:checked {"
        "   background-color: #007acc;"
        "   color: #ffffff;"
        "   border-left: 4px solid #569cd6;"
        "}"
        );
    QVBoxLayout *sidebarLayout = new QVBoxLayout(sidebar);
    sidebarLayout->setContentsMargins(0, 20, 0, 0);
    sidebarLayout->setSpacing(5);

    QPushButton *btnHome = new QPushButton("Strona Główna");
    QPushButton *btnEx3 = new QPushButton("Ćw 3: Stabilizacja i korekcja");
    QPushButton *btnEx4 = new QPushButton("Ćw 4: Serwomechanizmy DC");
    QPushButton *btnEx5 = new QPushButton("Ćw 5: Układy przekaźnikowe");

    QButtonGroup *menuGroup = new QButtonGroup(this);
    menuGroup->setExclusive(true);

    QPushButton* buttons[] = {btnHome, btnEx3, btnEx4, btnEx5};
    for(QPushButton* btn : buttons) {
        btn->setCheckable(true);
        btn->setCursor(Qt::PointingHandCursor);
        menuGroup->addButton(btn);
        sidebarLayout->addWidget(btn);
    }
    btnHome->setChecked(true);
    sidebarLayout->addStretch();

    QStackedWidget *stackedWidget = new QStackedWidget();
    stackedWidget->setStyleSheet("background-color: #1e1e1e;");

    QLabel *pageHome = new QLabel(
        "<h1 style='color: #007acc;'>Symulator Układów Sterowania Analogowego</h1>"
        "<p style='font-size: 16px; color: #cccccc; line-height: 1.5;'>"
        "Witaj w Wirtualnym Laboratorium!<br><br>"
        "Aplikacja ta służy do symulacji, modelowania i analizy obiektów dynamicznych "
        "oraz projektowania układów sterowania automatycznego.<br><br>"
        "<b>Główne możliwości:</b><br>"
        "• Identyfikacja modeli (obiekty inercyjne, całkująco-inercyjne, dwuinercyjne).<br>"
        "• Synteza i badanie sterowników z rodziny PID.<br>"
        "• Analiza układów nieliniowych (przekaźniki dwu- i trójpołożeniowe z histerezą).<br>"
        "• Analiza na płaszczyźnie fazowej oraz wykresy w dziedzinie czasu.<br><br>"
        "<i>Wybierz ćwiczenie z panelu bocznego, aby rozpocząć pracę.</i></p>"
        );
    pageHome->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    pageHome->setMargin(40);

    Exercise3 *page3 = new Exercise3(this);

    QLabel *page4 = new QLabel("Obszar roboczy: Ćwiczenie 4 (Silnik DC)");
    page4->setAlignment(Qt::AlignCenter);
    page4->setStyleSheet("font-size: 18px; color: #555;");

    QLabel *page5 = new QLabel("Obszar roboczy: Ćwiczenie 5");
    page5->setAlignment(Qt::AlignCenter);
    page5->setStyleSheet("font-size: 18px; color: #555;");

    stackedWidget->addWidget(pageHome);
    stackedWidget->addWidget(page3); // indeks 1
    stackedWidget->addWidget(page4);
    stackedWidget->addWidget(page5);

    bodyLayout->addWidget(sidebar);
    bodyLayout->addWidget(stackedWidget);

    mainLayout->addLayout(bodyLayout);

    connect(btnHome, &QPushButton::clicked, [=](){ stackedWidget->setCurrentIndex(0); });
    connect(btnEx3, &QPushButton::clicked, [=](){ stackedWidget->setCurrentIndex(1); });
    connect(btnEx4, &QPushButton::clicked, [=](){ stackedWidget->setCurrentIndex(2); });
    connect(btnEx5, &QPushButton::clicked, [=](){ stackedWidget->setCurrentIndex(3); });
}

MainWindow::~MainWindow()
{
    delete ui;
}