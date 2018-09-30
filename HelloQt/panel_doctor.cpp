
#include "panel_doctor.h"

// CONSTRUCTOR ---------------------------------------------------------------------
panel_doctor::panel_doctor(QWidget* parent): QWidget(parent)
{
    le_doc_id_ = new QComboBox();
    le_name_ = new QLineEdit();
    le_surname_ = new QLineEdit();
    le_specialization_ = new QLineEdit();

    get_doctor_ids();

    pushbut_add_ = new QPushButton("ADD");  // parent , delete object
    pushbut_upd_ = new QPushButton("UPDATE");
    pushbut_del_ = new QPushButton("DELETE");

    form_layout_ = new QFormLayout();   // form
    form_layout_->addRow("ID:", le_doc_id_);
    form_layout_->addRow("NAME:", le_name_);
    form_layout_->addRow("SURNAME:", le_surname_);
    form_layout_->addRow("SPECIALIZATION:", le_specialization_);

    doc_rep = new doctor_repository();


    //form_layout_->addItem(QString::number((dr.get_id)));

    operations_layout_ = new QHBoxLayout(); // horizontal
    operations_layout_->addWidget(pushbut_add_);
    operations_layout_->addWidget(pushbut_upd_);
    operations_layout_->addWidget(pushbut_del_);

    main_layout_ = new QVBoxLayout();   // vertical
    main_layout_->addLayout(form_layout_);
    main_layout_->addLayout(operations_layout_);

    setLayout(main_layout_);

    // connecting buttons
    connect(pushbut_add_, SIGNAL(clicked(bool)), this, SLOT(add_doctor()));
    connect(pushbut_upd_, SIGNAL(clicked(bool)), this, SLOT(update_doctor()));
    connect(pushbut_del_, SIGNAL(clicked(bool)), this, SLOT(delete_doctor()));
    connect(le_doc_id_,SIGNAL(currentIndexChanged(QString)),this,SLOT(get_doctor(const QString&)));

}

// ADD ----------------------------------------------------------------------------
void panel_doctor::add_doctor()
{
    doc_rep->add_doctor(doctor{le_name_->text(), le_surname_->text(), le_specialization_->text()});
    le_doc_id_->clear();
    get_doctor_ids();

    QMessageBox* info = new QMessageBox(this);
    info->setText("NEW ROW IN DOCTOR TABLE ADDED SUCCESSFULLY");
    info->show();
}

// UPDATE --------------------------------------------------------------------------
void panel_doctor::update_doctor()
{    
    doc_rep->update_doctor(doctor{le_doc_id_->currentText().toInt(), le_name_->text(), le_surname_->text(), le_specialization_->text()});
    le_doc_id_->clear();
    get_doctor_ids();

    QMessageBox* info = new QMessageBox(this);
    info->setText("ROW IN DOCTOR TABLE UPDATED SUCCESSFULLY");
    info->show();
}

// DELETE --------------------------------------------------------------------------
void panel_doctor::delete_doctor()
{
    doc_rep->delete_doctor(le_doc_id_->currentText().toInt());
    le_doc_id_->clear();
    get_doctor_ids();


    QMessageBox* info = new QMessageBox(this);
    info->setText("ROW IN DOCTOR TABLE DELETED SUCCESSFULLY");
    info->show();
}

// GET_DOCTOR ----------------------------------------------------------------------
void panel_doctor::get_doctor(const QString& idx) {
    boost::optional<doctor> op_doc = doc_rep->find_one_doctor_by_id(idx.toInt());

    if (op_doc) {
        doctor doc = *op_doc;
        le_name_->setText(doc.get_name());
        le_surname_->setText(doc.get_surname());
        le_specialization_->setText(doc.get_specialization());
    }
}

// GET ALL IDS FROM DOCTOR TABLE --------------------------------------------------
void panel_doctor::get_doctor_ids()
{
    QVector<doctor> doctors = doc_rep->find_all_doctors();

    for (const auto& d : doctors)
    {
        le_doc_id_->addItem(QString::number(d.get_id()));
    }
}

// DESTRUCTOR ---------------------------------------------------------------------
panel_doctor::~panel_doctor() {
//    if (doc_rep){delete doc_rep;}   // if dla kazdego obiektu ? Krotszy zapis ?

//    delete le_doc_id_;
//    delete le_name_;
//    delete le_surname_;
//    delete le_specialization_;

//    delete pushbut_add_;
//    delete pushbut_upd_;
//    delete pushbut_del_;

//    delete form_layout_;
//    delete operations_layout_;
//    delete main_layout_;
}



