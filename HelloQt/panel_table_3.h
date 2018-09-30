#ifndef PANEL_TABLE_3_H
#define PANEL_TABLE_3_H
#include "my_libs.h"
#include "doctor_patients_common_disease.h"

class panel_table_3 : public QWidget
{
    Q_OBJECT
public:
    explicit panel_table_3(QWidget* parent = 0);
    virtual ~panel_table_3();
private:
    QTableWidget* table_;
    QVBoxLayout* vertical_layout_;
    QVBoxLayout* main_layout_;
    QHBoxLayout* table_layout_;
    doctor_patients_common_disease* dpcd_;

    void fill_table();
};

#endif // PANEL_TABLE_3_H
