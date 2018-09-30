#include "my_main_window.h"

// CONSTRUCTOR -------------------------------------------------------------------
my_main_window::my_main_window(QWidget *parent) : QMainWindow(parent)
{
    resize(QDesktopWidget().availableGeometry(this).size() * 0.7);

    panel_doc = new panel_doctor();
    panel_pat = new panel_patient();
    panel_vis = new panel_visit();
    panel_tab_1 = new panel_table();
    panel_tab_2 = new panel_table_2();
    panel_tab_3 = new panel_table_3();
    panel_tab_by_date = new panel_table_visit_by_date();

    query_doc_pat_cost = new doctor_how_many_patients_average_cost_of_visit();
    query_doc_pat_cost->get_data();

    stacked_layout_ = new QStackedLayout();   
    stacked_layout_->addWidget(panel_doc);
    stacked_layout_->addWidget(panel_pat);
    stacked_layout_->addWidget(panel_vis);
    stacked_layout_->addWidget(panel_tab_1);
    stacked_layout_->addWidget(panel_tab_2);
    stacked_layout_->addWidget(panel_tab_3);
    stacked_layout_->addWidget(panel_tab_by_date);

    central_widget_ = new QWidget();
    central_widget_->setLayout(stacked_layout_);
    setCentralWidget(central_widget_);

    // menu bar
    menu_bar = new QMenuBar(this);
    menu = menu_bar->addMenu("&PANELS");

    doctor_panel_menu = new QAction("&DOCTOR", this);
    patient_panel_menu = new QAction("&PATIENT", this);
    visit_panel_menu = new QAction("&VISIT", this);
    table_1_panel_menu = new QAction("&DOCTOR - how many patients/avg cost", this);
    table_2_panel_menu = new QAction("&DIAGNOSE - number of patients by disease", this);
    table_3_panel_menu = new QAction("&DOCTOR - most common diagnose", this);
    table_vis_by_date_menu = new QAction("&VISITS BY DATE", this);

    menu->addAction(doctor_panel_menu);
    menu->addAction(patient_panel_menu);
    menu->addAction(visit_panel_menu);
    menu->addAction(table_1_panel_menu);
    menu->addAction(table_2_panel_menu);
    menu->addAction(table_3_panel_menu);
    menu->addAction(table_vis_by_date_menu);

    setMenuBar(menu_bar);

    // buttons connection
    connect(doctor_panel_menu, SIGNAL(triggered(bool)), this, SLOT(show_panel_doctor()));
    connect(patient_panel_menu, SIGNAL(triggered(bool)), this, SLOT(show_panel_patient()));
    connect(visit_panel_menu, SIGNAL(triggered(bool)), this, SLOT(show_panel_visit()));
    connect(table_1_panel_menu, SIGNAL(triggered(bool)), this, SLOT(show_panel_table_1()));
    connect(table_2_panel_menu, SIGNAL(triggered(bool)), this, SLOT(show_panel_table_2()));
    connect(table_3_panel_menu, SIGNAL(triggered(bool)), this, SLOT(show_panel_table_3()));
    connect(table_vis_by_date_menu, SIGNAL(triggered(bool)), this, SLOT(show_panel_table_visit_by_date()));
}


// SHOW PANELS -----------------------------------------------------------------------
void my_main_window::show_panel_doctor()
{
    stacked_layout_->setCurrentIndex(0);
}
//----------------------------------------
void my_main_window::show_panel_patient()
{
    stacked_layout_->setCurrentIndex(1);
}
//----------------------------------------
void my_main_window::show_panel_visit()
{
    panel_vis->refresh_data();
    stacked_layout_->setCurrentIndex(2);
}
//----------------------------------------
void my_main_window::show_panel_table_1()
{
    stacked_layout_->setCurrentIndex(3);
}
//----------------------------------------
void my_main_window::show_panel_table_2()
{
    stacked_layout_->setCurrentIndex(4);
}
//----------------------------------------
void my_main_window::show_panel_table_3()
{
    stacked_layout_->setCurrentIndex(5);
}

void my_main_window::show_panel_table_visit_by_date()
{
    stacked_layout_->setCurrentIndex(6);
}

