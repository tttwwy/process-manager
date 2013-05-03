#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDir>
#include <QDebug>
#include <QStringList>
#include <QFile>
#include <QTextStream>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void showTask();
    void killTask();
    void showInfo();
    
private slots:
    void on_pushButton_clicked();
    void on_action_triggered();
    /* debug */
    void on_pushButton_2_clicked();
    /* debug */

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    QDir dir;
    QFile file;
    QFile cpu_file;
    QFile network_file;
};

#endif // MAINWINDOW_H
