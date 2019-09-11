#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer.start(0, this);
    this->setWindowFlags(this->windowFlags() | Qt::WindowStaysOnTopHint);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::rolldown()
{
    QRect rect = this->geometry();
    rect.setHeight(origPos.height());
    this->setGeometry(rect);
    rolledup = false;
}

void MainWindow::rollup()
{
    QRect rect = this->geometry();
    rect.setHeight(0);
    this->setGeometry(rect);
    rolledup = true;
}

void MainWindow::timerEvent(QTimerEvent* /*event*/)
{
    QPoint pos = QCursor::pos();
    QRect checkPos = this->geometry();
    checkPos.setHeight(origPos.height());
    if (checkPos.contains(pos)) {
        this->setWindowTitle("Hello!");
        if (active) {
            if (!rolledup) {
                rollup();
            }
        }
    } else {
        this->setWindowTitle("Application");
        if (active) {
            if (rolledup) {
                rolldown();
            }
        }
    }
}

void MainWindow::on_actionActivate_triggered()
{
    if (active) {
        active = false;
        rolldown();
    } else {
        active = true;
        origPos = this->geometry();
    }
}
