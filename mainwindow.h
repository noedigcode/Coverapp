#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QBasicTimer>
#include <QCursor>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionActivate_triggered();

private:
    Ui::MainWindow *ui;

    bool active = false;
    bool rolledup = false;

    QRect origPos;

    void rolldown();
    void rollup();

    QBasicTimer timer;
    void timerEvent(QTimerEvent *event);
};

#endif // MAINWINDOW_H
