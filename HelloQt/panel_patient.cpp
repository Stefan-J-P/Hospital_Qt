#include "panel_patient.h"

panel_patient::panel_patient(QWidget *parent) : QWidget(parent)
{
    le_first_name_ = new QLineEdit();
    le_last_name_ = new QLineEdit();
    le_age_ = new QLineEdit();

    pushbut_add_ = new QPushButton("ADD");

    form_layout_ = new QFormLayout();
    form_layout_->addRow("FIRST NAME: ", le_first_name_);
    form_layout_->addRow("LAST NAME: ", le_last_name_);
    form_layout_->addRow("AGE: ", le_age_);

    operations_layout_= new QHBoxLayout();
    operations_layout_->addWidget(pushbut_add_);

    main_layout_= new QVBoxLayout();
    main_layout_->addLayout(form_layout_);
    main_layout_->addLayout(operations_layout_);

    setLayout(main_layout_);
    connect(pushbut_add_, SIGNAL(clicked(bool)), this, SLOT(add_patient()));
}

void panel_patient::add_patient()
{
    patient_repository* pat_rep = new patient_repository;
    pat_rep->add_patient(patient{le_first_name_->text(), le_last_name_->text(), le_age_->text().toInt()});

    if (pat_rep)
    {
        delete pat_rep;
    }
}
