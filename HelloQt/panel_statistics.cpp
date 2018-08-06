#include "panel_statistics.h"

panel_statistics::panel_statistics(QWidget *parent) : QWidget(parent)
{
    table1_ = new QTableWidget(1, 2, this);

    table_layout1_ = new QHBoxLayout();
    //table_layout1_->addWidget(table1);

    QTableWidgetItem *cubesHeaderItem1 = new QTableWidgetItem("Cubes");
    QTableWidgetItem *cubesHeaderItem2 = new QTableWidgetItem("Squares");
    //cubesHeaderItem->setIcon(QIcon(QPixmap(":/Images/cubed.png")));
    //cubesHeaderItem->setTextAlignment(Qt::AlignVCenter);
    table1_->setItem(0,0,cubesHeaderItem1);
    table1_->setItem(0,1,cubesHeaderItem1);

    main_layout_ = new QVBoxLayout();
    main_layout_->addLayout(table_layout1_);

    setLayout(main_layout_);
}

