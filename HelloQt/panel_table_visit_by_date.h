#ifndef PANEL_TABLE_VISIT_BY_DATE_H
#define PANEL_TABLE_VISIT_BY_DATE_H
#include "my_libs.h"
#include "doctor.h"
#include "patient.h"
#include "visit.h"
#include "visit_repository.h"
#include "visits_by_date.h"
#include "doctor_repository.h"
#include "patient_repository.h"

class panel_table_visit_by_date : public QWidget
{
    Q_OBJECT
private:
    // PANELS
    QTableWidget* table_;
    QVBoxLayout* vertical_layout_;
    QVBoxLayout* vertical_layout_2_;
    QVBoxLayout* main_layout_;
    QHBoxLayout* table_layout_;
    QFormLayout* form_layout_;
    QComboBox* combo_date_from_;
    QComboBox* combo_date_to_;
    QPushButton* show_visits_;

    QCalendarWidget* calendar_1_;
    QCalendarWidget* calendar_2_;


private:
    bool is_date_correct(const visits_by_date &vis, const QDateTime &dt_1, const QDateTime &dt_2);
    //void fill_table();
    void fill_table(const QDateTime& date_from, const QDateTime& date_to);
    void set_table_headers();

public:
    // CONSTRUCTOR & DESTRUCTOR
    panel_table_visit_by_date(QWidget* parent = 0);
    virtual ~panel_table_visit_by_date();    

public slots:
    void show_date(QDate date);
    void show_visits_between_dates();
};

#endif // PANEL_TABLE_VISIT_BY_DATE_H
