#include "panel_table_2.h"

// CONSTRUCTOR --------------------------------------------------------------------------------
panel_table_2::panel_table_2(QWidget *parent) : QWidget(parent)
{
    QVector<disease_patients_number> data_sql = disease_patients_number::get_data();
    int vec_size = data_sql.size();

    table_ = new QTableWidget(vec_size, 2);
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
    header_0->setText("Diagnose / Disease");
    table_->setHorizontalHeaderItem(0, header_0);

    QTableWidgetItem* header_1 = new QTableWidgetItem();
    header_1->setText("Number of patients with that problem");
    table_->setHorizontalHeaderItem(1, header_1);
}

// FILL TABLE ---------------------------------------------------------------------------------
void panel_table_2::fill_table()
{
    QVector<disease_patients_number> data = disease_patients_number::get_data();

    for (auto i = 0; i < data.size(); ++i)
    {
        QTableWidgetItem* col1 = new QTableWidgetItem();
        col1->setText(data[i].get_disease());
        table_->setItem(i, 0, col1);

        QTableWidgetItem* col2 = new QTableWidgetItem();
        col2->setText(QString::number(data[i].get_patients_number()));
        table_->setItem(i, 1, col2);
    }
}

// DESTRUCTOR ---------------------------------------------------------------------------------
panel_table_2::~panel_table_2()
{

}





