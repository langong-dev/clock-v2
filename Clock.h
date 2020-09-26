#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Clock.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Clock; }
QT_END_NAMESPACE

class Clock : public QMainWindow
{
    Q_OBJECT

public:
    Clock(QWidget *parent = Q_NULLPTR);
    void crt();

private:
    Ui::ClockClass *ui;

public slots:
    void Start_click();
    void Stop_click();
    void Help_click();
};
