
#include "Clock.h"
#include "ui_Clock.h"

#include <QTime>
#include <QApplication>
#include <QMessageBox>


int num, minute, second;


Clock::Clock(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ClockClass)
{
    ui->setupUi(this);
}

void Clock::Start_click()
{
    minute = ui->min->value();
    second = ui->sec->value();
    num = second + minute * 60;
    if (num < 0)
    {
        ui->show->display("Error");
    }
    QString display_string = QString::number(minute) + ":" + QString::number(second);
    if (minute < 10)
        display_string = "0";
    display_string += QString::number(minute) + ":";
    if (second < 10)
        display_string += "0";
    display_string += QString::number(second);
    ui->show->display(display_string);
    while (num-- > 0)
    {
        if (second == 0)
        {
            minute--, second = 59;
        }
        else
        {
            second--;
        }
        QTime _Timer = QTime::currentTime().addMSecs(1000);
        while (QTime::currentTime() < _Timer)
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
        if (minute < 10)
            display_string = "0";
        display_string += QString::number(minute) + ":";
        if (second < 10)
            display_string += "0";
        display_string += QString::number(second);
        ui->show->display(display_string);
    }
    QApplication::beep();
    ui->show->display("00:00");
}

void Clock::Stop_click()
{
    num = second = minute = 0;
    crt();
}

void Clock::crt()
{
    ui->show->display("00:00");
}

void Clock::Help_click()
{
    /*QMessageBox HelpMessage(QMessageBox::Information, "Title", "Content with icon.");
    HelpMessage.setButtonText(QMessageBox::Ok, QString("Show Information"));
    HelpMessage.setButtonText(QMessageBox::No, QString("Cancel"));
    */

    //QMessageBox::StandardButton  val;
    QMessageBox Help(
        QMessageBox::NoIcon,
        "LanGong Clock Help",
        "<center><h1>Help</h1></center><h3>Usage</h3>Input minute and second on 'Set clock' input box and click 'Start' button.<br>If you want to stop this clock, you can click 'Cancel'button."
    );
    QPushButton* btnhelp_about = Help.addButton(("About LanGong"), QMessageBox::YesRole);
    QPushButton* btnhelp_cancel = Help.addButton(("Cancel"), QMessageBox::NoRole);
    Help.exec();
    if ((QPushButton*)Help.clickedButton() == btnhelp_about)
    /*if (QMessageBox::information(
            this,
            "LanGong Clock Help",
            "<center><h1>Help</h1></center><h3>Usage</h3>Input minute and second on 'Set clock' input box and click 'Start' button.<br>If you want to stop this clock, you can click 'Cancel'button.",
            tr("About LanGong"), tr("Cancel")
        )
        == 0)
    */
    {
        if (QMessageBox::information(
            this,
            "About LanGong Clock",
            "The program is made by LanGong developement team and it is made with QT5.<br><a href=\"https://github.com/langong-dev\">View our GitHub team</a> | <a href=\"https://langong-dev.github.io\">View our website</a>",
            tr("View Licence"),
            tr("Cancel")
        ) == 0)
        {
            QMessageBox::about(
                this,
                "View License",
                "<center><b>LanGong Clock is undered MIT License.</b></center><br>Copyright(c) 2020 LanGong<br>Permission is hereby granted, free of charge, to any person obtaining a copy of this softwareand associated documentation files(the \"Software\"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and /or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions :<br>The above copyright noticeand this permission notice shall be included in all copies or substantial portions of the Software.<br>THE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE."
            );
        }
    }
}