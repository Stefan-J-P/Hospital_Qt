#ifndef PANEL_PATIENT_H
#define PANEL_PATIENT_H

#include "my_libs.h"
#include "patient_repository.h"
#include "patient.h"

class panel_patient : public QWidget
{
    Q_OBJECT
public:
    explicit panel_patient(QWidget* parent = 0);
    virtual ~panel_patient();
private:
    QComboBox* le_pat_id_;
    QLineEdit* le_first_name_;
    QLineEdit* le_last_name_;
    QLineEdit* le_age_;
    QLineEdit* le_symptoms_;
    QLineEdit* le_diagnose_;

    QPushButton* pushbut_add_;
    QPushButton* pushbut_upd_;
    QPushButton* pushbut_del_;

    QVBoxLayout* main_layout_;           // vertical layout
    QFormLayout* form_layout_;          // form layout
    QHBoxLayout* operations_layout_;    // horizontal layout

    patient_repository* pat_rep;
    void get_patients_ids();
signals:

public slots:
    void add_patient();
    void update_patient();
    void delete_patient();
    void get_patient(const QString& idx);
};
#endif // PANEL_PATIENT_H
