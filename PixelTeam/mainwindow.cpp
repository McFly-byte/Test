#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "snakewidget.h"
#include <QPainter>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->snakeBtn->setFont(QFont("Ink Free", 12 , 1 ) );
    connect( ui->snakeBtn , &QPushButton::clicked , [=](){
        SnakeWidget * snake = new SnakeWidget;
        this->hide();
        snake->show();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *e)
{
    Q_UNUSED( e );
    QPainter qpainter(this);
    QPixmap qpix;
    qpix.load(":/image/background.png");                                                  //需要背景图路径
    qpainter.drawPixmap(0,0,this->width(),this->height(),qpix);
}
