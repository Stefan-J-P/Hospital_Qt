#include "my_main_window.h"


my_main_window::my_main_window(QWidget *parent) : QMainWindow(parent)
{
    panel_doc = new panel_doctor();
    panel_pat = new panel_patient();
    panel_vis = new panel_visit();

    stacked_layout_ = new QStackedLayout();   
    stacked_layout_->addWidget(panel_doc);
    stacked_layout_->addWidget(panel_pat);
    stacked_layout_->addWidget(panel_vis);

    central_widget_ = new QWidget();
    central_widget_->setLayout(stacked_layout_);
    setCentralWidget(central_widget_);

    // menu bar
    menu_bar = new QMenuBar(this);
    menu = menu_bar->addMenu("&PANELS");

    doctor_panel_menu = new QAction("&DOCTOR", this);
    patient_panel_menu = new QAction("&PATIENT", this);
    visit_panel_menu = new QAction("&VISIT", this);

    menu->addAction(doctor_panel_menu);
    menu->addAction(patient_panel_menu);
    menu->addAction(visit_panel_menu);

    setMenuBar(menu_bar);

    // buttons connection
    connect(doctor_panel_menu, SIGNAL(triggered(bool)), this, SLOT(show_panel_doctor()));
    connect(patient_panel_menu, SIGNAL(triggered(bool)), this, SLOT(show_panel_patient()));
    connect(visit_panel_menu, SIGNAL(triggered(bool)), this, SLOT(show_panel_visit()));

}


void my_main_window::show_panel_doctor()
{
    stacked_layout_->setCurrentIndex(0);
}

void my_main_window::show_panel_patient()
{
    stacked_layout_->setCurrentIndex(1);
}

void my_main_window::show_panel_visit()
{
    stacked_layout_->setCurrentIndex(2);
}

