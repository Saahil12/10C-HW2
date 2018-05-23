#include "grade_calculator.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->spinBox,SIGNAL(valueChanged(int)),
                     this,SLOT(update_overall(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::update_overall(int unused){
    // double score = 31.4;
    double score = static_cast<double>(unused);

    ui -> horizontalSlider -> setValue(unused);
    ui->label_14->setText(QString::number(score));

    return;
}
