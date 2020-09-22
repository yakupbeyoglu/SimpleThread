#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "thread.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void OnValueChanged(const int &value);



private slots:
    void on_start_clicked();

    void on_stop_clicked();

    void on_manual_clicked();

private:
    Ui::MainWindow *ui;
    Thread *thread;

};

#endif // MAINWINDOW_H
