#ifndef PANEL_DOCTOR_H
#define PANEL_DOCTOR_H

#include "my_libs.h"
#include "doctor_repository.h"

class panel_doctor : public QWidget
{
    Q_OBJECT
public:
        explicit panel_doctor(QWidget* parent = 0);
private:
        // pola tekstowe - wstawianie danych
        QLineEdit* le_name_;
        QLineEdit* le_specialization_;

        // przyciski
        QPushButton* pushbut_add_;

        // obiekty, ktore pozwola ukladac elementy w odpowiednie layouty
        QVBoxLayout* main_layout_; // uklada elementy w pionie
        QFormLayout* form_layout_; // uklada elelementy w formularz
        QHBoxLayout* operations_layout_; // uklada elementy w poziomie

signals:

public slots:
        void add_doctor();
};

#endif // PANEL_DOCTOR_H
