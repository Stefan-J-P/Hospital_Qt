#include "panel_visit.h"

panel_visit::panel_visit(QWidget *parent) : QWidget(parent)
{
    le_visit_date_time_ = new QLineEdit();
    le_doctor_id_ = new QComboBox();
    le_patient_id_ = new QComboBox();
    le_cost_ = new QLineEdit();

    doctor_repository* doc_rep = new doctor_repository();
    QVector<doctor> doctors = doc_rep->find_all_doctors();
    for (const auto& d : doctors) {
        le_doctor_id_->addItem(QString::number(d.get_id()));
    }

    patient_repository* pat_rep = new patient_repository();
    QVector<patient> patients = pat_rep->find_all_patients();
    for (const auto& p : patients) {
        le_patient_id_->addItem(QString::number(p.get_id()));
    }

    pushbut_add_ = new QPushButton("ADD");

    form_layout_ = new QFormLayout();
    form_layout_->addRow("VISIT: ", le_visit_date_time_);
    form_layout_->addRow("DOCTOR ID: ", le_doctor_id_);
    form_layout_->addRow("PATIENT ID: ", le_patient_id_);
    form_layout_->addRow("COST: ", le_cost_);

    operations_layout_ = new QHBoxLayout();
    operations_layout_->addWidget(pushbut_add_);

    main_layout_ = new QVBoxLayout();
    main_layout_->addLayout(form_layout_);
    main_layout_->addLayout(operations_layout_);

    setLayout(main_layout_);

    // przyciski akcja
    connect(pushbut_add_, SIGNAL(clicked(bool)), this, SLOT(add_visit()));
}

void panel_visit::add_visit()
{
    visit_repository* vis_rep = new visit_repository;
    QMessageBox* msg = new QMessageBox();
    msg->setText(le_doctor_id_->currentText()/*.toInt()*/);
    msg->show();


}

