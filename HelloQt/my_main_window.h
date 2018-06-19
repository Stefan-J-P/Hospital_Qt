#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <my_libs.h>
#include <panel_doctor.h>
#include <panel_patient.h>
#include <panel_visit.h>


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
private:
    panel_doctor* panel_doc;
    panel_patient* panel_pat;
    panel_visit* panel_vis;

    QStackedLayout* stacked_layout_;
    QWidget* central_widget_;

    // menu
    QMenuBar* menu_bar;
    QMenu* menu;
    QAction* doctor_panel_menu;
    QAction* patient_panel_menu;
    QAction* visit_panel_menu;
};

#endif // MAINWINDOW_H
