#ifndef PANEL_VISIT_H
#define PANEL_VISIT_H

#include "my_libs.h"
#include "visit_repository.h"
#include "doctor_repository.h"
#include "patient_repository.h"
#include "visit.h"
#include "doctor.h"
#include "patient.h"

class panel_visit : public QWidget
{
    Q_OBJECT
public:
    explicit panel_visit(QWidget *parent = 0);
    virtual ~panel_visit();
private:
    QComboBox* le_visit_id_;
    QLineEdit* le_visit_date_time_;
    QComboBox* le_doctor_id_;
    QLineEdit* le_doctor_name_;
    QComboBox* le_patient_id_;
    QLineEdit* le_cost_;

    QPushButton* pushbut_add_;
    QPushButton* pushbut_upd_;
    QPushButton* pushbut_del_;

    QVBoxLayout* main_layout_;
    QFormLayout* form_layout_;
    QHBoxLayout* operations_layout_;
    QHBoxLayout* doctor_id_layout_;

    doctor_repository* doc_rep;
    patient_repository* pat_rep;
    visit_repository* vis_rep;
    void get_visit_ids();
signals:

public slots:
    void add_visit();
    void update_visit();
    void delete_visit();
    void get_visit(const QString& idx);
    int get_doctor_id(const QString& d);
    int get_patient_id(const QString& p);

    void refresh_data();

    void refresh_doc_id();
    void refresh_pat_id();
};

#endif // PANEL_VISIT_H
