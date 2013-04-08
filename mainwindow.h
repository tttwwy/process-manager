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
    
private slots:
    void on_pushButton_clicked();
    void showTask();
    void on_action_triggered();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    QDir dir;
    QFile file;


};

#endif // MAINWINDOW_H
