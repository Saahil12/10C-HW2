#include "grade_calculator.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QObject>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //setting range 0-100
    ui->horizontalSlider->setRange(0,100);
    ui->horizontalSlider_2->setRange(0,100);
    ui->horizontalSlider_3->setRange(0,100);
    ui->horizontalSlider_4->setRange(0,100);
    ui->horizontalSlider_5->setRange(0,100);
    ui->horizontalSlider_6->setRange(0,100);
    ui->horizontalSlider_7->setRange(0,100);
    ui->horizontalSlider_8->setRange(0,100);
    ui->horizontalSlider_9->setRange(0,100);
    ui->horizontalSlider_10->setRange(0,100);
    ui->horizontalSlider_11->setRange(0,100);

    ui->spinBox->setRange(0,100);
    ui->spinBox_2->setRange(0,100);
    ui->spinBox_3->setRange(0,100);
    ui->spinBox_4->setRange(0,100);
    ui->spinBox_5->setRange(0,100);
    ui->spinBox_6->setRange(0,100);
    ui->spinBox_7->setRange(0,100);
    ui->spinBox_8->setRange(0,100);
    ui->spinBox_9->setRange(0,100);
    ui->spinBox_10->setRange(0,100);
    ui->spinBox_11->setRange(0,100);

    //conncting horizontalSliders to SpinBoxes
    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)), ui->spinBox, SLOT(setValue(int)));
    connect(ui->horizontalSlider_2, SIGNAL(valueChanged(int)), ui->spinBox_2, SLOT(setValue(int)));
    connect(ui->horizontalSlider_3, SIGNAL(valueChanged(int)), ui->spinBox_3, SLOT(setValue(int)));
    connect(ui->horizontalSlider_4, SIGNAL(valueChanged(int)), ui->spinBox_4, SLOT(setValue(int)));
    connect(ui->horizontalSlider_5, SIGNAL(valueChanged(int)), ui->spinBox_5, SLOT(setValue(int)));
    connect(ui->horizontalSlider_6, SIGNAL(valueChanged(int)), ui->spinBox_6, SLOT(setValue(int)));
    connect(ui->horizontalSlider_7, SIGNAL(valueChanged(int)), ui->spinBox_7, SLOT(setValue(int)));
    connect(ui->horizontalSlider_8, SIGNAL(valueChanged(int)), ui->spinBox_8, SLOT(setValue(int)));
    connect(ui->horizontalSlider_9, SIGNAL(valueChanged(int)), ui->spinBox_9, SLOT(setValue(int)));
    connect(ui->horizontalSlider_10, SIGNAL(valueChanged(int)), ui->spinBox_10, SLOT(setValue(int)));
    connect(ui->horizontalSlider_11, SIGNAL(valueChanged(int)), ui->spinBox_11, SLOT(setValue(int)));

    //connecting SpinBoxes to horizontalSliders
    connect(ui->spinBox, SIGNAL(valueChanged(int)), ui->horizontalSlider, SLOT(setValue(int)));
    connect(ui->spinBox_2, SIGNAL(valueChanged(int)), ui->horizontalSlider_2, SLOT(setValue(int)));
    connect(ui->spinBox_3, SIGNAL(valueChanged(int)), ui->horizontalSlider_3, SLOT(setValue(int)));
    connect(ui->spinBox_4, SIGNAL(valueChanged(int)), ui->horizontalSlider_4, SLOT(setValue(int)));
    connect(ui->spinBox_5, SIGNAL(valueChanged(int)), ui->horizontalSlider_5, SLOT(setValue(int)));
    connect(ui->spinBox_6, SIGNAL(valueChanged(int)), ui->horizontalSlider_6, SLOT(setValue(int)));
    connect(ui->spinBox_7, SIGNAL(valueChanged(int)), ui->horizontalSlider_7, SLOT(setValue(int)));
    connect(ui->spinBox_8, SIGNAL(valueChanged(int)), ui->horizontalSlider_8, SLOT(setValue(int)));
    connect(ui->spinBox_9, SIGNAL(valueChanged(int)), ui->horizontalSlider_9, SLOT(setValue(int)));
    connect(ui->spinBox_10, SIGNAL(valueChanged(int)), ui->horizontalSlider_10, SLOT(setValue(int)));
    connect(ui->spinBox_11, SIGNAL(valueChanged(int)), ui->horizontalSlider_11, SLOT(setValue(int)));

    //calulate overall everytime spinBoxes values are changed
    connect(ui->spinBox, SIGNAL(valueChanged(int)), this, SLOT(calc_overall()));
    connect(ui->spinBox_2, SIGNAL(valueChanged(int)), this, SLOT(calc_overall()));
    connect(ui->spinBox_3, SIGNAL(valueChanged(int)), this, SLOT(calc_overall()));
    connect(ui->spinBox_4, SIGNAL(valueChanged(int)), this, SLOT(calc_overall()));
    connect(ui->spinBox_5, SIGNAL(valueChanged(int)), this, SLOT(calc_overall()));
    connect(ui->spinBox_6, SIGNAL(valueChanged(int)), this, SLOT(calc_overall()));
    connect(ui->spinBox_7, SIGNAL(valueChanged(int)), this, SLOT(calc_overall()));
    connect(ui->spinBox_8, SIGNAL(valueChanged(int)), this, SLOT(calc_overall()));
    connect(ui->spinBox_9, SIGNAL(valueChanged(int)), this, SLOT(calc_overall()));
    connect(ui->spinBox_10, SIGNAL(valueChanged(int)), this, SLOT(calc_overall()));
    connect(ui->spinBox_11, SIGNAL(valueChanged(int)), this, SLOT(calc_overall()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::calc_overall()
{
    double hw_score = 0;
    double midterm1 = 0;
    double midterm2 = 0;
    double final = 0;
    double overall_score = 0;

    std::vector <double> total;
    total.push_back(ui->spinBox->value());
    total.push_back(ui->spinBox_2->value());
    total.push_back(ui->spinBox_3->value());
    total.push_back(ui->spinBox_4->value());
    total.push_back(ui->spinBox_5->value());
    total.push_back(ui->spinBox_6->value());
    total.push_back(ui->spinBox_7->value());
    total.push_back(ui->spinBox_8->value());
    total.push_back(ui->spinBox_9->value());
    total.push_back(ui->spinBox_10->value());
    total.push_back(ui->spinBox_11->value());

    for (int i=0; i<=7; i++)
    {
        hw_score +=  total[i];
    }

    hw_score = hw_score/8;
    qDebug() << hw_score << endl;
    midterm1 = total[8];
    midterm2 = total[9];
    final = total[10];

    double final_grade_scheme1 = .25*hw_score + .20*midterm1 + .20*midterm2 + .35*final;

    ui->label_14->setText(QString::number(final_grade_scheme1));

}


