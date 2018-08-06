#ifndef PANEL_DOCTOR_H
#define PANEL_DOCTOR_H

#include "my_libs.h"
#include "doctor_repository.h"
#include "doctor.h"

class panel_doctor : public QWidget
{
    Q_OBJECT
public:
        explicit panel_doctor(QWidget* parent = 0);
        virtual ~panel_doctor();
private:
        QComboBox* le_doc_id_;
        QLineEdit* le_name_;
        QLineEdit* le_surname_;
        QLineEdit* le_specialization_;

        QPushButton* pushbut_add_;
        QPushButton* pushbut_upd_;
        QPushButton* pushbut_del_;

        QVBoxLayout* main_layout_;
        QFormLayout* form_layout_;
        QHBoxLayout* operations_layout_;

        doctor_repository* doc_rep;

        void get_doctor_ids();

signals:

public slots:
        void add_doctor();
        void update_doctor();
        void delete_doctor();
        void get_doctor(const QString& idx);
};

#endif // PANEL_DOCTOR_H
