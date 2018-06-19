#ifndef PANEL_VISIT_H
#define PANEL_VISIT_H

#include <QWidget>
#include "my_libs.h"
#include "visit_repository.h"
#include "doctor_repository.h"
#include "patient_repository.h"

class panel_visit : public QWidget
{
    Q_OBJECT
public:
    explicit panel_visit(QWidget *parent = 0);
private:
    QLineEdit* le_visit_date_time_;
    QComboBox* le_doctor_id_;
    QComboBox* le_patient_id_;
    QLineEdit* le_cost_;

    QPushButton* pushbut_add_;

    QVBoxLayout* main_layout_;
    QFormLayout* form_layout_;
    QHBoxLayout* operations_layout_;
signals:

public slots:
    void add_visit();
};

#endif // PANEL_VISIT_H
