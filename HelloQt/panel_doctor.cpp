
#include "panel_doctor.h"

panel_doctor::panel_doctor(QWidget* parent): QWidget(parent)
{
    le_name_ = new QLineEdit();
    le_specialization_ = new QLineEdit();

    pushbut_add_ = new QPushButton("ADD");

    form_layout_ = new QFormLayout();   // formularz
    form_layout_->addRow("NAME:", le_name_);
    form_layout_->addRow("SPECIALIZATION:", le_specialization_);

    operations_layout_ = new QHBoxLayout(); // poziom
    operations_layout_->addWidget(pushbut_add_);

    main_layout_ = new QVBoxLayout();   // pion
    main_layout_->addLayout(form_layout_);
    main_layout_->addLayout(operations_layout_);

    setLayout(main_layout_);

    // laczenie przyciskow
    connect(pushbut_add_, SIGNAL(clicked(bool)), this, SLOT(add_doctor()));

}


void panel_doctor::add_doctor()
{
    doctor_repository* doc_rep = new doctor_repository();
    doc_rep->add_doctor(doctor{le_name_->text(), le_specialization_->text()});

    if(doc_rep)
    {
        delete doc_rep;
    }
}

