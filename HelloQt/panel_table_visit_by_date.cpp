#include "panel_table_visit_by_date.h"

// CONSTRUCTOR --------------------------------------------------------------------------------
panel_table_visit_by_date::panel_table_visit_by_date(QWidget *parent)
{
    QVector<visits_by_date> data_all_visits = visits_by_date::find_all_visits_asc();

    table_ = new QTableWidget(data_all_visits.size(), 5);
    data_all_visits.clear();
    set_table_headers();
    show_visits_ = new QPushButton("SHOW VISITS");
    calendar_1_ = new QCalendarWidget();
    calendar_2_ = new QCalendarWidget();

    // strech every single column to fill 100% of the width
    for (int i = 0; i < table_->horizontalHeader()->count(); ++i)   {table_->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Stretch);}

    vertical_layout_ = new QVBoxLayout();
    vertical_layout_->addWidget(table_);    
    vertical_layout_2_ = new QVBoxLayout();
    vertical_layout_2_->addWidget(show_visits_);

    form_layout_ = new QFormLayout();    
    form_layout_->addRow("DATE FROM:", calendar_1_);
    form_layout_->addRow("DATE TO:", calendar_2_);

    main_layout_ = new QVBoxLayout();
    main_layout_->addLayout(vertical_layout_);
    main_layout_->addLayout(form_layout_);
    main_layout_->addLayout(vertical_layout_2_);

    setLayout(main_layout_);



    connect(calendar_1_, SIGNAL(clicked(QDate)), this, SLOT(show_date(QDate)));
    connect(calendar_2_, SIGNAL(clicked(QDate)), this, SLOT(show_date(QDate)));
    connect(show_visits_, SIGNAL(clicked(bool)), this, SLOT(show_visits_between_dates()));
}


// IS DATE CORRECT -----------------------------------------------------------------------------
bool panel_table_visit_by_date::is_date_correct(const visits_by_date &vis, const QDateTime &dt_1, const QDateTime &dt_2)
{
    return vis.get_visit_date_time() >= dt_1 && vis.get_visit_date_time() <= dt_2;
}


//FILL TABLE ------ NO arguments --------------------------------------------------------------
/*
void panel_table_visit_by_date::fill_table()
{
    QVector<visits_by_date> data = visits_by_date::find_all_visits_desc();

    doctor_repository doc_rep;
    patient_repository pat_rep;
    boost::optional<doctor> doc;
    boost::optional<patient> pat;
    doctor d;
    patient p;

    // browse vector with data from data base ---> and fill every column
    for(auto i = 0; i < data.size(); ++i)
    {
        QTableWidgetItem* col_1 = new QTableWidgetItem();
        col_1->setText(QString::number(data[i].get_visit_id()));
        table_->setItem(i, 0, col_1);

        QTableWidgetItem* col_2 = new QTableWidgetItem();
        col_2->setText(data[i].get_visit_date_time().toString());
        table_->setItem(i, 1, col_2);

        QTableWidgetItem* col_3 = new QTableWidgetItem();
        doc = doc_rep.find_one_doctor_by_id(data[i].get_doctor_id());
        d = *doc;   // find doctor name by id
        col_3->setText(d.get_name() + " " + d.get_surname());
        table_->setItem(i, 2, col_3);

        QTableWidgetItem* col_4 = new QTableWidgetItem();
        pat = pat_rep.find_one_patient_by_id(data[i].get_patient_id());
        p = *pat;   // find patient name by id
        col_4->setText(p.get_first_name() + " " + p.get_last_name());
        table_->setItem(i, 3, col_4);

        QTableWidgetItem* col_5 = new QTableWidgetItem();
        col_5->setText(QString::number(data[i].get_visit_cost()));
        table_->setItem(i, 4, col_5);
    }
}       */

// FILL TABLE ------ WITH arguments ------------------------------------------------------------
void panel_table_visit_by_date::fill_table(const QDateTime& date_from, const QDateTime& date_to)
{
    QVector<visits_by_date> data_all = visits_by_date::find_all_visits_asc();
    QVector<visits_by_date> data_filter;

    for(auto i = 0; i < data_all.size(); ++i )
    {
        if (is_date_correct(data_all[i], date_from, date_to))
        {
            data_filter.push_back(data_all[i]);
        }
    }

    if (data_filter.isEmpty())
    {
        QMessageBox* msg = new QMessageBox();
        msg->setText("VECTOR IS EMPTY");
        msg->show();
        return;
    }

    table_->setRowCount(data_filter.size());


    doctor_repository doc_rep;
    patient_repository pat_rep;
    boost::optional<doctor> doc;
    boost::optional<patient> pat;
    doctor d;
    patient p;

    // browse vector with data from data base ---> and fill every column
    for(auto i = 0; i < data_filter.size(); ++i)
    {
        QTableWidgetItem* col_1 = new QTableWidgetItem();
        col_1->setText(QString::number(data_filter[i].get_visit_id()));
        table_->setItem(i, 0, col_1);

        QTableWidgetItem* col_2 = new QTableWidgetItem();
        col_2->setText(data_filter[i].get_visit_date_time().toString());
        table_->setItem(i, 1, col_2);

        QTableWidgetItem* col_3 = new QTableWidgetItem();
        doc = doc_rep.find_one_doctor_by_id(data_filter[i].get_doctor_id());
        d = *doc;   // find doctor name by id
        col_3->setText(d.get_name() + " " + d.get_surname());
        table_->setItem(i, 2, col_3);

        QTableWidgetItem* col_4 = new QTableWidgetItem();
        pat = pat_rep.find_one_patient_by_id(data_filter[i].get_patient_id());
        p = *pat;   // find patient name by id
        col_4->setText(p.get_first_name() + " " + p.get_last_name());
        table_->setItem(i, 3, col_4);

        QTableWidgetItem* col_5 = new QTableWidgetItem();
        col_5->setText(QString::number(data_filter[i].get_visit_cost()));
        table_->setItem(i, 4, col_5);
    }
}

// SET TABLE HEADERS ----------------------------------------------------------------------
void panel_table_visit_by_date::set_table_headers()
{
    // set table headers
    QTableWidgetItem* header_0 = new QTableWidgetItem();
    header_0->setText("VISIT ID");
    table_->setHorizontalHeaderItem(0, header_0);

    QTableWidgetItem* header_1 = new QTableWidgetItem();
    header_1->setText("VISIT DATE");
    table_->setHorizontalHeaderItem(1, header_1);

    QTableWidgetItem* header_2 = new QTableWidgetItem();
    header_2->setText("DOCTOR");
    table_->setHorizontalHeaderItem(2, header_2);

    QTableWidgetItem* header_3 = new QTableWidgetItem();
    header_3->setText("PATIENT");
    table_->setHorizontalHeaderItem(3, header_3);

    QTableWidgetItem* header_4 = new QTableWidgetItem();
    header_4->setText("COST OF VISIT");
    table_->setHorizontalHeaderItem(4, header_4);
}

// SHOW DATE ------------------------------------------------------------------------------
void panel_table_visit_by_date::show_date(QDate date)
{
    // QMessageBox* msg = new QMessageBox();
    // msg->setText(QString::number(date.year()) + " " + QString::number(date.month()) + " " + QString::number(date.day()));
    // msg->show();
}

// SHOW VISITS BETWEEN DATES --------------------------------------------------------------
void panel_table_visit_by_date::show_visits_between_dates()
{
    QDate date1 = calendar_1_->selectedDate();
    QDate date2 = calendar_2_->selectedDate();

    if (date1 > date2) {
        QMessageBox* msg = new QMessageBox();
        msg->setText("'DATE FROM' MUST BE LESS THAN 'DATE TO'");
        msg->show();
    }
    fill_table(QDateTime { date1 }, QDateTime { date2 });
}


// DESTRUCTOR ---------------------------------------------------------------------
panel_table_visit_by_date::~panel_table_visit_by_date()
{

}

