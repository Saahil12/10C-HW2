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
    ui->horizontalSlider_12->setRange(0,100);
    ui->horizontalSlider_13->setRange(0,100);


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
    ui->spinBox_12->setRange(0,100);
    ui->spinBox_13->setRange(0,100);

    //connecting horizontalSliders to SpinBoxes
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
    connect(ui->horizontalSlider_12, SIGNAL(valueChanged(int)), ui->spinBox_12, SLOT(setValue(int)));
    connect(ui->horizontalSlider_13, SIGNAL(valueChanged(int)), ui->spinBox_13, SLOT(setValue(int)));

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
    connect(ui->spinBox_12, SIGNAL(valueChanged(int)), ui->horizontalSlider_12, SLOT(setValue(int)));
    connect(ui->spinBox_13, SIGNAL(valueChanged(int)), ui->horizontalSlider_13, SLOT(setValue(int)));

    //calculate overall everytime spinBoxes values are changed or radioButtons are clicked
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
    connect(ui->spinBox_12, SIGNAL(valueChanged(int)), this, SLOT(calc_overall()));
    connect(ui->spinBox_13, SIGNAL(valueChanged(int)), this, SLOT(calc_overall()));

    //click correct schema depending on midterm and final scores
    connect(ui->spinBox_11, SIGNAL(valueChanged(int)), this, SLOT(schema_check()));
    connect(ui->spinBox_12, SIGNAL(valueChanged(int)), this, SLOT(schema_check()));
    connect(ui->spinBox_13, SIGNAL(valueChanged(int)), this, SLOT(schema_check()));

    //reset() if comboBox changed
    connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(reset()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::get_pic10()
{
    return pic10;
}

void MainWindow::change_pic10(int x)
{
    pic10 = x;
}

void MainWindow::calc_overall()
{
    double hw_score = 0;
    double midterm1 = 0;
    double midterm2 = 0;
    double final = 0;

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
    total.push_back(ui->spinBox_12->value());
    total.push_back(ui->spinBox_13->value());


    for (int i=0; i<=9; i++)
    {
        hw_score +=  total[i];
    }

    hw_score = hw_score/10;
    midterm1 = total[10];
    midterm2 = total[11];
    final = total[12];

    //calculate both grade_schemes
    double final_grade_scheme1 = .25*hw_score + .20*midterm1 + .20*midterm2 + .35*final;

    double final_grade_scheme2 = 0;
    if (midterm1 > midterm2)
        {
            final_grade_scheme2 = .25*hw_score + .30*midterm1 + .44*final;
        }
    else
        {
            final_grade_scheme2 = .25*hw_score + .30*midterm2 + .44*final;
        }

    //display correct score
    /*
    if(ui->radioButton->isChecked())
        {
            ui->label_14->setText(QString::number(final_grade_scheme1));
        }
    else if(ui ->radioButton_2 ->isChecked())
        {
            ui->label_14->setText(QString::number(final_grade_scheme2));
        }
*/
    if(final_grade_scheme1 >= final_grade_scheme2)
        {
            ui->label_14->setText(QString::number(final_grade_scheme1));
        }
    else if(final_grade_scheme2 > final_grade_scheme1)
        {
            ui->label_14->setText(QString::number(final_grade_scheme2));
        }

}

void MainWindow::schema_check()
{
    double midterm1 = 0;
    double midterm2 = 0;
    double final_exam = 0;
    double highest_midterm = 0;

    midterm1 = ui->spinBox_11->value();
    midterm2 = ui->spinBox_12->value();
    final_exam = ui->spinBox_13->value();

    if(midterm1 > midterm2)
        {
            highest_midterm = midterm1;
        }
    else
        {
            highest_midterm = midterm2;
        }

    double schema1_total = .20*midterm1 + .20*midterm2 + .35*final_exam;
    double schema2_total = .30*highest_midterm + .44*final_exam;

    if(schema1_total > schema2_total)
        {
            ui->radioButton->click();
            ui->radioButton->setChecked(true);
            ui->radioButton_2->setDisabled(true);
            ui->radioButton_2->setChecked(false);

        }
    else if (schema2_total > schema1_total)
        {
            ui->radioButton_2->click();
            ui->radioButton_2->setChecked(true);
            ui->radioButton->setDisabled(true);
            ui->radioButton->setChecked(false);
        }

}

void MainWindow::reset()
{
    ui->horizontalSlider->setValue(0);
    ui->horizontalSlider_2->setValue(0);
    ui->horizontalSlider_3->setValue(0);
    ui->horizontalSlider_4->setValue(0);
    ui->horizontalSlider_5->setValue(0);
    ui->horizontalSlider_6->setValue(0);
    ui->horizontalSlider_7->setValue(0);
    ui->horizontalSlider_8->setValue(0);
    ui->horizontalSlider_9->setValue(0);
    ui->horizontalSlider_10->setValue(0);
    ui->horizontalSlider_11->setValue(0);
    ui->horizontalSlider_12->setValue(0);
    ui->horizontalSlider_13->setValue(0);
    ui->label_14 -> setText("0");

    //spinBoxes are connected to horizontalSliders so no need to manually reset them

    ui->radioButton->setChecked(false);
    ui->radioButton->setEnabled(true);
    ui->radioButton_2->setChecked(false);
    ui->radioButton_2->setEnabled(true);

    int classLevel = ui->comboBox->currentIndex();

    if(get_pic10()==1 && classLevel==0)
        {
            fromB_toA();
        }

    else if(get_pic10()==2 && classLevel==0)
        {
            fromC_toA();
        }

    else if(get_pic10()==0 && classLevel==1)
        {
            fromA_toB();
        }

    else if(get_pic10()==2 && classLevel==1)
        {
            fromC_toB();
        }

    else if(get_pic10()==0 && classLevel==2)
        {
            fromA_toC();
        }

    else if(get_pic10()==1 && classLevel==2)
        {
            fromB_toC();
        }
}

void MainWindow::fromB_toA()
{
    //change pic10 to 0
    change_pic10(0);

    ui->horizontalSlider_9->show();
    ui->horizontalSlider_10->show();
    ui->spinBox_9->show();
    ui->spinBox_10->show();
    ui->label_9->show();
    ui->label_10->show();

    //disconnect from B slots
    disconnect(ui->spinBox, SIGNAL(valueChanged(int)), this, SLOT(calc_overall10b()));
    disconnect(ui->spinBox_2, SIGNAL(valueChanged(int)), this, SLOT(calc_overall10b()));
    disconnect(ui->spinBox_3, SIGNAL(valueChanged(int)), this, SLOT(calc_overall10b()));
    disconnect(ui->spinBox_4, SIGNAL(valueChanged(int)), this, SLOT(calc_overall10b()));
    disconnect(ui->spinBox_5, SIGNAL(valueChanged(int)), this, SLOT(calc_overall10b()));
    disconnect(ui->spinBox_6, SIGNAL(valueChanged(int)), this, SLOT(calc_overall10b()));
    disconnect(ui->spinBox_7, SIGNAL(valueChanged(int)), this, SLOT(calc_overall10b()));
    disconnect(ui->spinBox_8, SIGNAL(valueChanged(int)), this, SLOT(calc_overall10b()));
    disconnect(ui->spinBox_11, SIGNAL(valueChanged(int)), this, SLOT(calc_overall10b()));
    disconnect(ui->spinBox_12, SIGNAL(valueChanged(int)), this, SLOT(calc_overall10b()));
    disconnect(ui->spinBox_13, SIGNAL(valueChanged(int)), this, SLOT(calc_overall10b()));

    //disconnect from B slots
    disconnect(ui->spinBox_11, SIGNAL(valueChanged(int)), this, SLOT(schema_check10b()));
    disconnect(ui->spinBox_12, SIGNAL(valueChanged(int)), this, SLOT(schema_check10b()));
    disconnect(ui->spinBox_13, SIGNAL(valueChanged(int)), this, SLOT(schema_check10b()));

    //connect to A slots
    //calulate overall everytime spinBoxes values are changed or radioButtons are clicked
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
    connect(ui->spinBox_12, SIGNAL(valueChanged(int)), this, SLOT(calc_overall()));
    connect(ui->spinBox_13, SIGNAL(valueChanged(int)), this, SLOT(calc_overall()));

    //click correct schema depending on midterm and final scores
    connect(ui->spinBox_11, SIGNAL(valueChanged(int)), this, SLOT(schema_check()));
    connect(ui->spinBox_12, SIGNAL(valueChanged(int)), this, SLOT(schema_check()));
    connect(ui->spinBox_13, SIGNAL(valueChanged(int)), this, SLOT(schema_check()));

    connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(reset()));
}

void MainWindow::fromC_toA()
{
    //change pic10 to 0
    change_pic10(0);

    //disconect C slots
    disconnect(ui->spinBox, SIGNAL(valueChanged(int)), this, SLOT(calc_overall10c()));
    disconnect(ui->spinBox_2, SIGNAL(valueChanged(int)), this, SLOT(calc_overall10c()));
    disconnect(ui->spinBox_3, SIGNAL(valueChanged(int)), this, SLOT(calc_overall10c()));
    disconnect(ui->spinBox_4, SIGNAL(valueChanged(int)), this, SLOT(calc_overall10c()));

    //disconnect C slots
    disconnect(ui->spinBox_11, SIGNAL(valueChanged(int)), this, SLOT(schema_check10c()));
    disconnect(ui->spinBox_12, SIGNAL(valueChanged(int)), this, SLOT(schema_check10c()));

    //rename and reappear needed objects
    ui->label_4-> setText("Hw 4");
    ui->label_12-> setText("Midterm 2");

    ui->horizontalSlider_5->show();
    ui->horizontalSlider_6->show();
    ui->horizontalSlider_7->show();
    ui->horizontalSlider_8->show();
    ui->horizontalSlider_9->show();
    ui->horizontalSlider_10->show();
    ui->horizontalSlider_13->show();

    ui->spinBox_5->show();
    ui->spinBox_6->show();
    ui->spinBox_7->show();
    ui->spinBox_8->show();
    ui->spinBox_9->show();
    ui->spinBox_10->show();
    ui->spinBox_13->show();

    ui->label_5->show();
    ui->label_6->show();
    ui->label_7->show();
    ui->label_8->show();
    ui->label_9->show();
    ui->label_10->show();
    ui->label_13->show();

    //calculate overall everytime spinBoxes values are changed or radioButtons are clicked
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
    connect(ui->spinBox_12, SIGNAL(valueChanged(int)), this, SLOT(calc_overall()));
    connect(ui->spinBox_13, SIGNAL(valueChanged(int)), this, SLOT(calc_overall()));

    //click correct schema depending on midterm and final scores
    connect(ui->spinBox_11, SIGNAL(valueChanged(int)), this, SLOT(schema_check()));
    connect(ui->spinBox_12, SIGNAL(valueChanged(int)), this, SLOT(schema_check()));
    connect(ui->spinBox_13, SIGNAL(valueChanged(int)), this, SLOT(schema_check()));

    connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(reset()));
}

void MainWindow::calc_overall10b()
{
    double hw_score = 0;
    double midterm1 = 0;
    double midterm2 = 0;
    double final = 0;
    std::vector<double>scores;

    scores.push_back(ui->spinBox->value());
    scores.push_back(ui->spinBox_2->value());
    scores.push_back(ui->spinBox_3->value());
    scores.push_back(ui->spinBox_4->value());
    scores.push_back(ui->spinBox_5->value());
    scores.push_back(ui->spinBox_6->value());
    scores.push_back(ui->spinBox_7->value());
    scores.push_back(ui->spinBox_8->value());

    int smallest_index = 0;
    int temp_smallest = scores[0];
    for(size_t i=0; i<=7; i++)
    {
        if (scores[i] < temp_smallest)
            {
                temp_smallest=scores[i];
                smallest_index = i;
            }
    }

    //set lowest score to 0 since it will be ignored
    scores[smallest_index] = 0;

    for(size_t x=0; x<=7; x++)
    {
        hw_score += scores[x];
    }

    //divide by 7 since lowest score is ignored
    hw_score = hw_score/7;

    midterm1 = ui->spinBox_11->value();
    midterm2 = ui->spinBox_12->value();
    final = ui->spinBox_13->value();

    double final_grade_scheme1 = .25*hw_score + .20*midterm1 + .20*midterm2 + .35*final;

    double final_grade_scheme2 = 0;
    if (midterm1 > midterm2)
        {
            final_grade_scheme2 = .25*hw_score + .30*midterm1 + .44*final;
        }
    else
        {
            final_grade_scheme2 = .25*hw_score + .30*midterm2 + .44*final;
        }

    if(final_grade_scheme1 >= final_grade_scheme2)
        {
            ui->label_14->setText(QString::number(final_grade_scheme1));
        }
    else if(final_grade_scheme2 > final_grade_scheme1)
        {
            ui->label_14->setText(QString::number(final_grade_scheme2));
        }

}

void MainWindow::schema_check10b()
{
    double midterm1 = 0;
    double midterm2 = 0;
    double final_exam = 0;
    double highest_midterm = 0;

    midterm1 = ui->spinBox_11->value();
    midterm2 = ui->spinBox_12->value();
    final_exam = ui->spinBox_13->value();

    if(midterm1 > midterm2)
        {
            highest_midterm = midterm1;
        }
    else
        {
            highest_midterm = midterm2;
        }

    double schema1_total = .20*midterm1 + .20*midterm2 + .35*final_exam;
    double schema2_total = .30*highest_midterm + .44*final_exam;

    if(schema1_total > schema2_total)
        {
            ui->radioButton->click();
            ui->radioButton->setChecked(true);
            ui->radioButton_2->setDisabled(true);
            ui->radioButton_2->setChecked(false);

        }
    else if (schema2_total > schema1_total)
        {
            ui->radioButton_2->click();
            ui->radioButton_2->setChecked(true);
            ui->radioButton->setDisabled(true);
            ui->radioButton->setChecked(false);
        }

}

void MainWindow::calc_overall10c()
{
    double hw_score = 0;
    double midterm = 0;
    double project = 0;
    double final = 0;
    std::vector <double> scores;

    scores.push_back(ui->spinBox->value());
    scores.push_back(ui->spinBox_2->value());
    scores.push_back(ui->spinBox_3->value());

    for (size_t i=0; i<=2; i++)
    {
        hw_score += scores[i];
    }

    hw_score = hw_score/3;
    project = ui->spinBox_4->value();
    midterm = ui->spinBox_11->value();
    final = ui->spinBox_12->value();

    //calculate both grade_schemes
    double final_grade_scheme1 = .15*hw_score + .25*midterm + .35*project + .30*final;
    double final_grade_scheme2 = .15*hw_score + .35*project + .50*final;

    if(final_grade_scheme1 >= final_grade_scheme2)
        {
            ui->label_14->setText(QString::number(final_grade_scheme1));
        }
    else if(final_grade_scheme2 > final_grade_scheme1)
        {
            ui->label_14->setText(QString::number(final_grade_scheme2));
    }
}

void MainWindow::schema_check10c()
{
        double hw_score = 0;
        double midterm = 0;
        double project = 0;
        double final = 0;
        std::vector <double> scores;

        scores.push_back(ui->spinBox->value());
        scores.push_back(ui->spinBox_2->value());
        scores.push_back(ui->spinBox_3->value());

        for (size_t i=0; i<=2; i++)
        {
            hw_score += scores[i];
        }

        hw_score = hw_score/3;
        project = ui->spinBox_4->value();
        midterm = ui->spinBox_11->value();
        final = ui->spinBox_12->value();

        //calculate both grade_schemes
        double schema1_total = .15*hw_score + .25*midterm + .35*project + .30*final;
        double schema2_total = .15*hw_score + .35*project + .50*final;

        if(schema1_total > schema2_total)
            {
                ui->radioButton->click();
                ui->radioButton->setChecked(true);
                ui->radioButton_2->setDisabled(true);
                ui->radioButton_2->setChecked(false);

            }
        else if (schema2_total > schema1_total)
            {
                ui->radioButton_2->click();
                ui->radioButton_2->setChecked(true);
                ui->radioButton->setDisabled(true);
                ui->radioButton->setChecked(false);
            }
}


void MainWindow::fromA_toB()
{
    //change pic10 t0 1
    change_pic10(1);

    ui->horizontalSlider_9->hide();
    ui->horizontalSlider_10->hide();
    ui->spinBox_9->hide();
    ui->spinBox_10->hide();
    ui->label_9->hide();
    ui->label_10->hide();

    //disconnect from A slots
    disconnect(ui->spinBox, SIGNAL(valueChanged(int)), this, SLOT(calc_overall()));
    disconnect(ui->spinBox_2, SIGNAL(valueChanged(int)), this, SLOT(calc_overall()));
    disconnect(ui->spinBox_3, SIGNAL(valueChanged(int)), this, SLOT(calc_overall()));
    disconnect(ui->spinBox_4, SIGNAL(valueChanged(int)), this, SLOT(calc_overall()));
    disconnect(ui->spinBox_5, SIGNAL(valueChanged(int)), this, SLOT(calc_overall()));
    disconnect(ui->spinBox_6, SIGNAL(valueChanged(int)), this, SLOT(calc_overall()));
    disconnect(ui->spinBox_7, SIGNAL(valueChanged(int)), this, SLOT(calc_overall()));
    disconnect(ui->spinBox_8, SIGNAL(valueChanged(int)), this, SLOT(calc_overall()));
    disconnect(ui->spinBox_9, SIGNAL(valueChanged(int)), this, SLOT(calc_overall()));
    disconnect(ui->spinBox_10, SIGNAL(valueChanged(int)), this, SLOT(calc_overall()));
    disconnect(ui->spinBox_11, SIGNAL(valueChanged(int)), this, SLOT(calc_overall()));
    disconnect(ui->spinBox_12, SIGNAL(valueChanged(int)), this, SLOT(calc_overall()));
    disconnect(ui->spinBox_13, SIGNAL(valueChanged(int)), this, SLOT(calc_overall()));

    //disconnect from A slots
    disconnect(ui->spinBox_11, SIGNAL(valueChanged(int)), this, SLOT(schema_check()));
    disconnect(ui->spinBox_12, SIGNAL(valueChanged(int)), this, SLOT(schema_check()));
    disconnect(ui->spinBox_13, SIGNAL(valueChanged(int)), this, SLOT(schema_check()));

    //calulate overall everytime spinBoxes values are changed or radioButtons are clicked
    connect(ui->spinBox, SIGNAL(valueChanged(int)), this, SLOT(calc_overall10b()));
    connect(ui->spinBox_2, SIGNAL(valueChanged(int)), this, SLOT(calc_overall10b()));
    connect(ui->spinBox_3, SIGNAL(valueChanged(int)), this, SLOT(calc_overall10b()));
    connect(ui->spinBox_4, SIGNAL(valueChanged(int)), this, SLOT(calc_overall10b()));
    connect(ui->spinBox_5, SIGNAL(valueChanged(int)), this, SLOT(calc_overall10b()));
    connect(ui->spinBox_6, SIGNAL(valueChanged(int)), this, SLOT(calc_overall10b()));
    connect(ui->spinBox_7, SIGNAL(valueChanged(int)), this, SLOT(calc_overall10b()));
    connect(ui->spinBox_8, SIGNAL(valueChanged(int)), this, SLOT(calc_overall10b()));
    connect(ui->spinBox_11, SIGNAL(valueChanged(int)), this, SLOT(calc_overall10b()));
    connect(ui->spinBox_12, SIGNAL(valueChanged(int)), this, SLOT(calc_overall10b()));
    connect(ui->spinBox_13, SIGNAL(valueChanged(int)), this, SLOT(calc_overall10b()));

    //click correct schema depending on midterm and final scores
    connect(ui->spinBox_11, SIGNAL(valueChanged(int)), this, SLOT(schema_check10b()));
    connect(ui->spinBox_12, SIGNAL(valueChanged(int)), this, SLOT(schema_check10b()));
    connect(ui->spinBox_13, SIGNAL(valueChanged(int)), this, SLOT(schema_check10b()));

    //reset if comboBox changed
    connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(reset()));

}

void MainWindow::fromC_toB()
{
    fromC_toA();
    fromA_toB();

    //change pic10 to 2
    change_pic10(1);

    //reset if comboBox changed
    connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(reset()));
}


void MainWindow::fromA_toC()
{
    //change pic10 to 2
    change_pic10(2);

    //disconnect from A slots
    disconnect(ui->spinBox, SIGNAL(valueChanged(int)), this, SLOT(calc_overall()));
    disconnect(ui->spinBox_2, SIGNAL(valueChanged(int)), this, SLOT(calc_overall()));
    disconnect(ui->spinBox_3, SIGNAL(valueChanged(int)), this, SLOT(calc_overall()));
    disconnect(ui->spinBox_4, SIGNAL(valueChanged(int)), this, SLOT(calc_overall()));
    disconnect(ui->spinBox_5, SIGNAL(valueChanged(int)), this, SLOT(calc_overall()));
    disconnect(ui->spinBox_6, SIGNAL(valueChanged(int)), this, SLOT(calc_overall()));
    disconnect(ui->spinBox_7, SIGNAL(valueChanged(int)), this, SLOT(calc_overall()));
    disconnect(ui->spinBox_8, SIGNAL(valueChanged(int)), this, SLOT(calc_overall()));
    disconnect(ui->spinBox_9, SIGNAL(valueChanged(int)), this, SLOT(calc_overall()));
    disconnect(ui->spinBox_10, SIGNAL(valueChanged(int)), this, SLOT(calc_overall()));
    disconnect(ui->spinBox_11, SIGNAL(valueChanged(int)), this, SLOT(calc_overall()));
    disconnect(ui->spinBox_12, SIGNAL(valueChanged(int)), this, SLOT(calc_overall()));
    disconnect(ui->spinBox_13, SIGNAL(valueChanged(int)), this, SLOT(calc_overall()));

    //disconnect from A slots
    disconnect(ui->spinBox_11, SIGNAL(valueChanged(int)), this, SLOT(schema_check()));
    disconnect(ui->spinBox_12, SIGNAL(valueChanged(int)), this, SLOT(schema_check()));
    disconnect(ui->spinBox_13, SIGNAL(valueChanged(int)), this, SLOT(schema_check()));

    //hide or rename unneeded objects from A
    ui->label_4-> setText("Project");
    ui->label_12-> setText("Final Exam");

    ui->horizontalSlider_5->hide();
    ui->horizontalSlider_6->hide();
    ui->horizontalSlider_7->hide();
    ui->horizontalSlider_8->hide();
    ui->horizontalSlider_9->hide();
    ui->horizontalSlider_10->hide();
    ui->horizontalSlider_13->hide();

    ui->spinBox_5->hide();
    ui->spinBox_6->hide();
    ui->spinBox_7->hide();
    ui->spinBox_8->hide();
    ui->spinBox_9->hide();
    ui->spinBox_10->hide();
    ui->spinBox_13->hide();

    ui->label_5->hide();
    ui->label_6->hide();
    ui->label_7->hide();
    ui->label_8->hide();
    ui->label_9->hide();
    ui->label_10->hide();
    ui->label_13->hide();

    //calculate overall everytime spinBoxes values are changed or radioButtons are clicked
    connect(ui->spinBox, SIGNAL(valueChanged(int)), this, SLOT(calc_overall10c()));
    connect(ui->spinBox_2, SIGNAL(valueChanged(int)), this, SLOT(calc_overall10c()));
    connect(ui->spinBox_3, SIGNAL(valueChanged(int)), this, SLOT(calc_overall10c()));
    connect(ui->spinBox_4, SIGNAL(valueChanged(int)), this, SLOT(calc_overall10c()));
    connect(ui->spinBox_11, SIGNAL(valueChanged(int)), this, SLOT(calc_overall10c()));
    connect(ui->spinBox_12, SIGNAL(valueChanged(int)), this, SLOT(calc_overall10c()));

    //click correct schema depending on midterm and final scores
    connect(ui->spinBox_11, SIGNAL(valueChanged(int)), this, SLOT(schema_check10c()));
    connect(ui->spinBox_12, SIGNAL(valueChanged(int)), this, SLOT(schema_check10c()));

    //reset if comboBox changed
    connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(reset()));
}

void MainWindow::fromB_toC()
{
    fromB_toA();
    fromA_toC();

    //change pic10 to 2
    change_pic10(2);

    //reset if comboBox changed
    connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(reset()));
}




