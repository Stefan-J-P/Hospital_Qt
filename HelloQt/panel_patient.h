#ifndef PANEL_PATIENT_H
#define PANEL_PATIENT_H

#include "my_libs.h"
#include "patient_repository.h"

class panel_patient : public QWidget
{
    Q_OBJECT
public:
    explicit panel_patient(QWidget* parent = 0);
private:
    QLineEdit* le_first_name_;
    QLineEdit* le_last_name_;
    QLineEdit* le_age_;

    QPushButton* pushbut_add_;

    QVBoxLayout* main_layout_;           // układ pionowy
    QFormLayout* form_layout_;          // formularz
    QHBoxLayout* operations_layout_;    // układ poziomy

signals:

public slots:
    void add_patient();
};
#endif // PANEL_PATIENT_H
