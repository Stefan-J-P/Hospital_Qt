#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "my_libs.h"
#include "panel_doctor.h"
#include "panel_patient.h"
#include "panel_visit.h"
#include "panel_table.h"
#include "doctor_how_many_patients_average_cost_of_visit.h"
#include "panel_table_2.h"
#include "doctor_patients_common_disease.h"
#include "panel_table_3.h"
#include "disease_patients_number.h"
#include "panel_table_visit_by_date.h"

//QDesktopWidget dw;
//MainWindow w;

//int x = dw.width()*0.7;
//int y = dw.height()*0.7;
//w.setFixedSize(x,y);

class my_main_window : public QMainWindow
{
    Q_OBJECT
public:
    explicit my_main_window(QWidget *parent = 0);

signals:

public slots:
    void show_panel_doctor();
    void show_panel_patient();
    void show_panel_visit();
    void show_panel_table_1();
    void show_panel_table_2();
    void show_panel_table_3();
    void show_panel_table_visit_by_date();
private:
    panel_doctor* panel_doc;
    panel_patient* panel_pat;
    panel_visit* panel_vis;
    panel_table* panel_tab_1;
    panel_table_2* panel_tab_2;
    panel_table_3* panel_tab_3;
    panel_table_visit_by_date* panel_tab_by_date;

    doctor_how_many_patients_average_cost_of_visit* query_doc_pat_cost;
    doctor_patients_common_disease* query_common_disease;
    disease_patients_number* query_dis_pat_numb;

    QStackedLayout* stacked_layout_;
    QWidget* central_widget_;

    // menu
    QMenuBar* menu_bar;
    QMenu* menu;
    QAction* doctor_panel_menu;
    QAction* patient_panel_menu;
    QAction* visit_panel_menu;
    QAction* table_1_panel_menu;
    QAction* table_2_panel_menu;
    QAction* table_3_panel_menu;
    QAction* table_vis_by_date_menu;
};

#endif // MAINWINDOW_H
