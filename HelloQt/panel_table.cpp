#include "panel_table.h"

// CONSTRUCTOR ----------------------------------------------------------------------------------------
panel_table::panel_table(QWidget* parent) : QWidget(parent)
{

    QVector<doctor_how_many_patients_average_cost_of_visit> data_sql = doctor_how_many_patients_average_cost_of_visit::get_data();
    int vec_size = data_sql.size();

    table_ = new QTableWidget(vec_size, 4);
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
    header_0->setText("Doctor's' First Name");
    table_->setHorizontalHeaderItem(0, header_0);

    QTableWidgetItem* header_1 = new QTableWidgetItem();
    header_1->setText("Doctor's Last Name");
    table_->setHorizontalHeaderItem(1, header_1);

    QTableWidgetItem* header_2 = new QTableWidgetItem();
    header_2->setText("How many patients doctor has");
    table_->setHorizontalHeaderItem(2, header_2);

    QTableWidgetItem* header_3 = new QTableWidgetItem();
    header_3->setText("Average cost of visit");
    table_->setHorizontalHeaderItem(3, header_3);
}

// FILL TABLE -----------------------------------------------------------------------------------------
void panel_table::fill_table()
{
        QVector<doctor_how_many_patients_average_cost_of_visit> data = doctor_how_many_patients_average_cost_of_visit::get_data();

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
        col3->setText(QString::number(data[i].get_patients()));
        table_->setItem(i, 2, col3);

        QTableWidgetItem* col4 = new QTableWidgetItem();
        col4->setText(QString::number(data[i].get_average_cost()));
        table_->setItem(i, 3, col4);
    }
}


// DESTRUCTOR -----------------------------------------------------------------------------------------
panel_table::~panel_table()
{

}
