#include "panel_table_3.h"

// CONSTRUCTOR ------------------------------------------------------------------------
panel_table_3::panel_table_3(QWidget *parent) : QWidget(parent)
{
    dpcd_ = new doctor_patients_common_disease();
    QVector<doctor_patients_common_disease> data_sql = dpcd_->get_data();
    int vec_size = data_sql.size();

    table_ = new QTableWidget(vec_size, 3);
    fill_table();

    vertical_layout_ = new QVBoxLayout();
    vertical_layout_->addWidget(table_);
    setLayout(vertical_layout_);

    // strech every single column to fill 100% of the width
    for (int i = 0; i < table_->horizontalHeader()->count(); ++i)
    {
        table_->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Stretch);
    }

    // set table headers
    QTableWidgetItem* header_0 = new QTableWidgetItem();
    header_0->setText("Doctor's First Name");
    table_->setHorizontalHeaderItem(0, header_0);

    QTableWidgetItem* header_1 = new QTableWidgetItem();
    header_1->setText("Doctor's Last Name");
    table_->setHorizontalHeaderItem(1, header_1);

    QTableWidgetItem* header_2 = new QTableWidgetItem();
    header_2->setText("Most common disease");
    table_->setHorizontalHeaderItem(2, header_2);

}

// FILL TABLE ------------------------------------------------------------------------
void panel_table_3::fill_table()
{

    QVector<doctor_patients_common_disease> data = dpcd_->get_data();

    for (auto i = 0; i < data.size(); ++i)
    {
        // jeden wiersz
        QTableWidgetItem* col1 = new QTableWidgetItem();
        col1->setText(data[i].get_doc_name());
        table_->setItem(i, 0, col1);

        QTableWidgetItem* col2 = new QTableWidgetItem();
        col2->setText(data[i].get_doc_surname());
        table_->setItem(i, 1, col2);

        QTableWidgetItem* col3 = new QTableWidgetItem();
        col3->setText((data[i].get_disease()));
        table_->setItem(i, 2, col3);
    }
}


// DESTRUCTOR -------------------------------------------------------------------------
panel_table_3::~panel_table_3()
{

}


