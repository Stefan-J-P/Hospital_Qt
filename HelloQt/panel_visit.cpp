#include "panel_visit.h"

panel_visit::panel_visit(QWidget *parent) : QWidget(parent)
{
    le_visit_id_ = new QComboBox();
    le_visit_date_time_ = new QLineEdit();
    le_doctor_id_ = new QComboBox();    
    le_patient_id_ = new QComboBox();
    le_cost_ = new QLineEdit();

    //get_visit_ids();

    vis_rep = new visit_repository();
    QVector<visit> visits = vis_rep->find_all_visits();
    for(const auto& v : visits) {
        le_visit_id_->addItem(QString::number(v.get_id()));
    }

    refresh_doc_id();   // refresh output on screen
    refresh_pat_id();

    pushbut_add_ = new QPushButton("ADD");
    pushbut_upd_ = new QPushButton("UPDATE");
    pushbut_del_ = new QPushButton("DELETE");

    form_layout_ = new QFormLayout();
    form_layout_->addRow("VISIT ID:", le_visit_id_);
    form_layout_->addRow("DATE: ", le_visit_date_time_);
    form_layout_->addRow("DOCTOR ID: ", le_doctor_id_);
    form_layout_->addRow("PATIENT ID: ", le_patient_id_);
    form_layout_->addRow("COST: ", le_cost_);

    operations_layout_ = new QHBoxLayout();
    operations_layout_->addWidget(pushbut_add_);
    operations_layout_->addWidget(pushbut_upd_);
    operations_layout_->addWidget(pushbut_del_);

    main_layout_ = new QVBoxLayout();
    main_layout_->addLayout(form_layout_);
    main_layout_->addLayout(operations_layout_);

    setLayout(main_layout_);

    // buttons connection
    connect(pushbut_add_, SIGNAL(clicked(bool)), this, SLOT(add_visit()));
    connect(pushbut_upd_, SIGNAL(clicked(bool)), this, SLOT(update_visit()));
    connect(pushbut_del_, SIGNAL(clicked(bool)), this, SLOT(delete_visit()));
    connect(le_visit_id_,SIGNAL(currentIndexChanged(QString)),this,SLOT(get_visit(const QString&)));   

}

// DESTRUCTOR ------------------------------------------------------------------
panel_visit::~panel_visit()
{
//    if(vis_rep){delete vis_rep;}
//    if(doc_rep){delete doc_rep;}
//    if(pat_rep){delete pat_rep;}

//    delete le_visit_id_;
//    delete le_visit_date_time_;
//    delete le_doctor_id_;
//    delete le_patient_id_;
//    delete le_cost_;

//    delete pushbut_add_;
//    delete pushbut_upd_;
//    delete pushbut_del_;

//    delete form_layout_;
//    delete operations_layout_;
//    delete main_layout_;
}

// GET VISIT IDS ----------------------------------------------------------------
void panel_visit::get_visit_ids()
{
    le_visit_id_->clear();
    QVector<visit> visits = vis_rep->find_all_visits();
    for(const auto& v : visits)
    {
        le_visit_id_->addItem(QString::number(v.get_id()));
    }
}

// ADD VISIT --------------------------------------------------------------------
void panel_visit::add_visit()
{
    QDateTime dateTime = QDateTime::fromString(le_visit_date_time_->text(), QString("yyyy-MM-dd HH:mm"));

    vis_rep->add_visit(visit{dateTime, le_doctor_id_->currentText().toInt(), le_patient_id_->currentText().toInt(), le_cost_->text().toInt()});
    get_visit_ids();

    QMessageBox* msg = new QMessageBox();
    msg->setText("NEW ROW IN VISIT TABLE ADDED SUCCESSFULLY");
    msg->show();
}

// UPDATE VISIT -----------------------------------------------------------------
void panel_visit::update_visit()
{

    QDateTime dateTime = QDateTime::fromString(le_visit_date_time_->text(), QString("yyyy-MM-dd HH:mm"));

    QMessageBox* info2 = new QMessageBox(this);
    info2->setText(le_visit_id_->currentText());
    info2->show();

    vis_rep->update_visit(visit{le_visit_id_->currentText().toInt(), dateTime, le_doctor_id_->currentText().toInt(), le_patient_id_->currentText().toInt(), le_cost_->text().toInt()});

}

// DELETE VISIT -----------------------------------------------------------------
void panel_visit::delete_visit()
{
    vis_rep->delete_visit(le_visit_id_->currentText().toInt());
    get_visit_ids();

    QMessageBox* info = new QMessageBox(this);
    info->setText("ROW IN VISIT TABLE DELETED SUCCESSFULLY");
    info->show();
}

// GET VISIT -------------------------------------------------------------------
void panel_visit::get_visit(const QString &idx)
{
    boost::optional<visit> op_vis = vis_rep->find_one_visit_by_id(idx.toInt());


    doctor_repository doc_rep;
    patient_repository pat_rep;


    if(op_vis)
    {
        visit vis = *op_vis;
        doctor doc = *doc_rep.find_one_doctor_by_id(vis.get_doctor_id());
        patient pat = *pat_rep.find_one_patient_by_id(vis.get_patient_id());

        le_visit_date_time_->setText(vis.get_visit_date_time().toString(QString("yyyy-MM-dd HH:mm")));
        le_cost_->setText(QString::number(vis.get_cost()));

        le_doctor_id_->setCurrentText(QString::number(vis.get_doctor_id()));
        //le_doctor_id_->setCurrentText(doc.get_name() + " " + doc.get_surname());
        //le_doctor_id_->setCurrentText(*doc_rep.find_one_doctor_by_id(vis.get_doctor_id()));

        le_patient_id_->setCurrentText(QString::number(vis.get_patient_id()));
        //le_patient_id_->setCurrentText(pat.get_first_name() + " " + pat.get_last_name());
        //le_patient_id_->setCurrentText(*pat_rep.find_one_patient_by_id(vis.get_patient_id()));
    }
}

// REFRESH OUTPUT -------------------------------------------------------------
void panel_visit::refresh_data()
{
    refresh_doc_id();
    refresh_pat_id();
}

void panel_visit::refresh_doc_id()
{
    le_doctor_id_->clear();
    QVector<doctor> doctors = doc_rep->find_all_doctors();
    for (const auto& d : doctors)
    {
        le_doctor_id_->addItem(QString::number(d.get_id()));
        //le_doctor_id_->addItem(d.get_name() + " " + d.get_surname());
    }
}

void panel_visit::refresh_pat_id()
{
    le_patient_id_->clear();
    QVector<patient> patients = pat_rep->find_all_patients();
    for (const auto& p : patients)
    {
        le_patient_id_->addItem(QString::number(p.get_id()));
        //le_patient_id_->addItem(p.get_first_name() + " " + p.get_last_name());
    }
}

