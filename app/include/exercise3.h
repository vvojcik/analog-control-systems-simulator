#ifndef EXERCISE3_H
#define EXERCISE3_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGroupBox>

class Exercise3 : public QWidget
{
    Q_OBJECT

public:
    explicit Exercise3(QWidget *parent = nullptr);

private:
    QHBoxLayout *mainLayout;
    QGroupBox *panelBox;
    QGroupBox *chartBox;

    void setupLayout();
};

#endif