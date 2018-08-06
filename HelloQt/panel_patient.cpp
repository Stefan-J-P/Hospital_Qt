#include "panel_patient.h"

// CONSTRUCTOR -----------------------------------------------------------------
panel_patient::panel_patient(QWidget *parent) : QWidget(parent)
{
    // Lines
    le_pat_id_ = new QComboBox();
    le_first_name_ = new QLineEdit();
    le_last_name_ = new QLineEdit();
    le_age_ = new QLineEdit();
    le_symptoms_ = new QLineEdit();
    le_diagnose_ = new QLineEdit();

    get_patients_ids();
    pat_rep = new patient_repository();

    // Buttons
    pushbut_add_ = new QPushButton("ADD");
    pushbut_upd_ = new QPushButton("UPDATE");
    pushbut_del_ = new QPushButton("DELETE");

    // Buttons layout
    form_layout_ = new QFormLayout();
    form_layout_->addRow("ID: ", le_pat_id_);
    form_layout_->addRow("FIRST NAME: ", le_first_name_);
    form_layout_->addRow("LAST NAME: ", le_last_name_);
    form_layout_->addRow("AGE: ", le_age_);
    form_layout_->addRow("SYMPTOMS", le_symptoms_);
    form_layout_->addRow("DIAGNOSE", le_diagnose_);
    // Horizontal Leyout
    operations_layout_= new QHBoxLayout();
    operations_layout_->addWidget(pushbut_add_);
    operations_layout_->addWidget(pushbut_upd_);
    operations_layout_->addWidget(pushbut_del_);
    // Vertical layout
    main_layout_= new QVBoxLayout();
    main_layout_->addLayout(form_layout_);
    main_layout_->addLayout(operations_layout_);
    // Connect buttons
    setLayout(main_layout_);
    connect(pushbut_add_, SIGNAL(clicked(bool)), this, SLOT(add_patient()));
    connect(pushbut_upd_, SIGNAL(clicked(bool)), this, SLOT(update_patient()));
    connect(pushbut_del_, SIGNAL(clicked(bool)), this, SLOT(delete_patient()));
    connect(le_pat_id_, SIGNAL(currentIndexChanged(QString)), this, SLOT(get_patient(const QString&)));
}

// ADD ------------------------------------------------------------------------
void panel_patient::add_patient()
{   // ADD OTHER WIDGETS ---> symptoms + diagnose
    pat_rep->add_patient(patient{le_first_name_->text(), le_last_name_->text(), le_age_->text().toInt()});
    le_pat_id_->clear();
    get_patients_ids();

    QMessageBox* info = new QMessageBox(this);
    info->setText("NEW ROW IN PATIENT TABLE ADDED SUCCESSFULLY");
    info->show();
}

// UPDATE ---------------------------------------------------------------------
void panel_patient::update_patient()
{
    pat_rep->update_patient(patient{le_pat_id_->currentText().toInt(), le_first_name_->text(), le_last_name_->text(), le_age_->text().toInt()});
    le_pat_id_->clear();
    get_patients_ids();

    QMessageBox* info = new QMessageBox(this);
    info->setText("ROW IN PATIENT TABLE UPDATED SUCCESSFULLY");
    info->show();
}

// DELETE ---------------------------------------------------------------------
void panel_patient::delete_patient()
{
    pat_rep->delete_patient(le_pat_id_->currentText().toInt());
    le_pat_id_->clear();
    get_patients_ids();

    QMessageBox* info = new QMessageBox(this);
    info->setText("ROW IN PATIENT TABLE DELETED SUCCESSFULLY");
    info->show();
}

// GET PATIENT ----------------------------------------------------------------
void panel_patient::get_patient(const QString &idx)
{
    boost::optional<patient> op_pat = pat_rep->find_one_patient_by_id(idx.toInt());

    if(op_pat)
    {
        patient pat = *op_pat;
        le_first_name_->setText(pat.get_first_name());
        le_last_name_->setText(pat.get_last_name());
        le_age_->setText(QString::number(pat.get_age()));
    }
}

// GET ALL IDS FROM PATIENT TABLE ---------------------------------------------
void panel_patient::get_patients_ids()
{
    QVector<patient> patients = pat_rep->find_all_patients();
    for(const auto& p : patients)
    {
        le_pat_id_->addItem(QString::number(p.get_id()));
    }
}


// DESTRUCTOR -----------------------------------------------------------------
panel_patient::~panel_patient()
{
    if(pat_rep)
    {
        delete pat_rep;
    }
}














