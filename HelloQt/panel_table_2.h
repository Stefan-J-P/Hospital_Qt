#ifndef PANEL_TABLE_2_H
#define PANEL_TABLE_2_H
#include "my_libs.h"
#include "disease_patients_number.h"

class panel_table_2 : public QWidget
{
    Q_OBJECT
public:
    explicit panel_table_2(QWidget* parent = 0);
    virtual ~panel_table_2();
private:
    QTableWidget* table_;
    QVBoxLayout* vertical_layout_;
    QVBoxLayout* main_layout_;
    QHBoxLayout* table_layout_;

    void fill_table();
};

#endif // PANEL_TABLE_2_H
