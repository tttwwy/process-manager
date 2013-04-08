#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->treeWidget->setSortingEnabled(true);
    dir.setCurrent("/proc");
    showTask();

}


MainWindow::~MainWindow()
{
    delete ui;

}







void MainWindow::on_pushButton_clicked()
{

showTask();
}

void MainWindow::showTask()
{
    ui->treeWidget->clear();
    QStringList list,temp;
    dir.setCurrent("/proc");


    list = dir.entryList();

    for (int i = 0;i < list.size();i++)
    {

        QString pid = list[i];
        int i;
//        for (i = 0;i < pid.size();i++)
//        {
//            if (pid[i] < '0' || pid[i] > '9')
//                break;
//        }

//        if (i < pid.size())
//            break;
        QString name,name1,name2;

        file.setFileName("/proc/" + pid +"/status");
        qDebug() << file.fileName();
        if (!file.open(QIODevice::ReadOnly))
        {
            qDebug() << "文件打开失败！";

        }
        else
        {
            name = file.readLine();
            int a = name.indexOf(":");
            int b = name.size();
            name1 = name.mid(a+2, b-a-1);
            name1.trimmed(); //删除两端的空格


            temp.clear();
            temp << pid << name1;
            QTreeWidgetItem *item = new QTreeWidgetItem(ui->treeWidget,temp);
            ui->treeWidget->addTopLevelItem(item);
            ui->treeWidget->show();
            file.close();

        }
    }

}

void MainWindow::on_action_triggered()
{
    close();
}
