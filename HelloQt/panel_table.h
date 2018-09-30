#ifndef PANEL_TABLE_H
#define PANEL_TABLE_H

#include "my_libs.h"
#include "panel_statistics.h"
#include "doctor_how_many_patients_average_cost_of_visit.h"

class panel_table : public QWidget
{
    Q_OBJECT
public:
    explicit panel_table(QWidget* parent = 0);
    virtual ~panel_table();
private:
    QTableWidget* table_;
    QVBoxLayout* vertical_layout_;
    QVBoxLayout* main_layout_;
    QHBoxLayout* table_layout_;


    void fill_table();

signals:
public slots:

};

#endif // PANEL_TABLE_H
