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
    showInfo();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    showTask();
}

void MainWindow::on_pushButton_2_clicked()
{
    killTask();
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
        int k;
        for (k = 0;k < pid.size();k++)
        {
            if (pid.at(k) <'0' || pid.at(k) > '9')
                break;
        }
        if (k < pid.size())
            continue;
        QString name,state,priority,memory;

        file.setFileName("/proc/" + pid +"/stat");
        qDebug() << file.fileName();
        if (!file.open(QIODevice::ReadOnly))
        {
            qDebug() << "文件打开失败！";

        }
        else
        {
            //获取名称
            QString line = file.readLine();
            name = line;
            int a = name.indexOf("(");
            int b = name.indexOf(")");
            name = name.mid(a+1, b-a-1);
            name.trimmed(); //删除两端的空格



            //获取状态
            state = line.section(" ",2,2);
            priority = line.section(" ",17,17);
            memory = line.section(" ",23,23);
            int number = memory.toInt();
            number /= 256;
            memory = QString::number(number);
            memory += "MB";





            temp.clear();
            temp << pid << name << state << priority << memory;
            QTreeWidgetItem *item = new QTreeWidgetItem(ui->treeWidget,temp);
            ui->treeWidget->addTopLevelItem(item);
            ui->treeWidget->show();
            file.close();

        }
    }

}
void MainWindow::killTask()
{
    QTreeWidgetItem *item = ui->treeWidget->currentItem();


    QString pro = item->text(0);
    system("kill " + pro.toLatin1());
//    QMessageBox::warning(this, tr("kill"), QString::fromUtf8("该进程已被杀死!"), QMessageBox::Yes);
    //回到进程信息tab表
    showTask();
}


void MainWindow::showInfo()
{
    qDebug() << "This is ";
    int i, a, b;
    QString info_line;


    /* ----- 物理内存(MB) ----- */

    /* 总数 */
    cpu_file.setFileName("/proc/meminfo");
    if (!cpu_file.open(QIODevice::ReadOnly)) {
        qDebug() << "文件打开失败！";
    }
    else {
        qDebug() << "文件打开Success!";
    }
    for (i = 0; i < 1; ++i)
        info_line = cpu_file.readLine();
    a = info_line.indexOf(":");
    b = info_line.size();
    info_line = info_line.mid(a+2, b-a-1);
    info_line.trimmed(); //删除两端的空格
    ui->label_15->setText(info_line);
    cpu_file.close();
    /* 已缓存 */
    /*  */
    /*  */



    /* ----- 核心内存(MB) ----- */
    /*  */
    /*  */

    /* ----- 系统 ----- */
    /*  */
    /*  */
    /*  */
    /*  */
    /*  */
    /* ----- CPU info ----- */
    /* vendor */
    cpu_file.setFileName("/proc/cpuinfo");
    if (!cpu_file.open(QIODevice::ReadOnly)) {
        qDebug() << "文件打开失败！";
    }
    else {
        qDebug() << "文件打开Success!";
    }
    for (i = 0; i < 2; ++i)
        info_line = cpu_file.readLine();
    a = info_line.indexOf(":");
    b = info_line.size();
    info_line = info_line.mid(a+2, b-a-1);
    info_line.trimmed(); //删除两端的空格
    ui->label_25->setText(info_line);
    cpu_file.close();
    /* MHZ */
    cpu_file.setFileName("/proc/cpuinfo");
    if (!cpu_file.open(QIODevice::ReadOnly)) {
        qDebug() << "文件打开失败！";
    }
    else {
        qDebug() << "文件打开Success!";
    }
    for (i = 0; i < 7; ++i)
        info_line = cpu_file.readLine();
    a = info_line.indexOf(":");
    b = info_line.size();
    info_line = info_line.mid(a+2, b-a-1) + QString("MHz");
    info_line.trimmed(); //删除两端的空格
    ui->label_26->setText(info_line);
    cpu_file.close();
    /* Cache */
    cpu_file.setFileName("/proc/cpuinfo");
    if (!cpu_file.open(QIODevice::ReadOnly)) {
        qDebug() << "文件打开失败！";
    }
    else {
        qDebug() << "文件打开Success!";
    }
    for (i = 0; i < 8; ++i)
        info_line = cpu_file.readLine();
    a = info_line.indexOf(":");
    b = info_line.size();
    info_line = info_line.mid(a+2, b-a-1);
    info_line.trimmed(); //删除两端的空格
    ui->label_27->setText(info_line);
    cpu_file.close();
    /* address */
    cpu_file.setFileName("/proc/cpuinfo");
    if (!cpu_file.open(QIODevice::ReadOnly)) {
        qDebug() << "文件打开失败！";
    }
    else {
        qDebug() << "文件打开Success!";
    }
    for (i = 0; i < 21; ++i)
        info_line = cpu_file.readLine();
    a = info_line.indexOf(":");
    b = info_line.size();
    info_line = info_line.mid(a+2, b-a-1);
    info_line.trimmed(); //删除两端的空格
    ui->label_30->setText(info_line);
    cpu_file.close();
    /* info */
    cpu_file.setFileName("/proc/cpuinfo");
    if (!cpu_file.open(QIODevice::ReadOnly)) {
        qDebug() << "文件打开失败！";
    }
    else {
        qDebug() << "文件打开Success!";
    }
    for (i = 0; i < 5; ++i)
        info_line = cpu_file.readLine();
    a = info_line.indexOf(":");
    b = info_line.size();
    info_line = info_line.mid(a+2, b-a-1);
    info_line.trimmed(); //删除两端的空格
    ui->label_28->setText(info_line);
    cpu_file.close();

    /* Operating System */
    cpu_file.setFileName("/proc/version");
    if (!cpu_file.open(QIODevice::ReadOnly)) {
        qDebug() << "文件打开失败！";
    }
    else {
        qDebug() << "文件打开Success!";
    }
    for (i = 0; i < 1; ++i)
        info_line = cpu_file.readLine();
    info_line.trimmed(); //删除两端的空格
    ui->textBrowser->setText(info_line);
    cpu_file.close();
}

void MainWindow::on_action_triggered()
{
    close();
}
