#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    int get_pic10();
    void change_pic10(int x);

signals:
    //void compute_overall();

public slots:
   void calc_overall();
   void schema_check();
   void reset();

   void fromB_toA();
   //void fromC_toA();
   void fromA_toB();
   //void fromC_toB();
   //void fromA_toC();
   //void fromB_toC();

   void calc_overall10b();
   void schema_check10b();

private:
    Ui::MainWindow *ui;
    int pic10 = 0;
};

#endif // MAINWINDOW_H
