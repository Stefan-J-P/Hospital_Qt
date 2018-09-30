#ifndef PANEL_STATISTICS_H
#define PANEL_STATISTICS_H


#include "my_libs.h"
#include "doctor.h"
#include "patient.h"
#include "visit.h"
#include "doctor_repository.h"
#include "patient_repository.h"
#include "visit_repository.h"

class panel_statistics : public QWidget
{
    Q_OBJECT
public:
    explicit panel_statistics(QWidget *parent = 0);
    virtual ~panel_statistics();
signals:

public slots:

private:
    QTableWidget* table_;
    QVBoxLayout* vertical_layout_;
    QVBoxLayout* main_layout_;
    QHBoxLayout* table_layout_;



};

#endif // PANEL_STATISTICS_H
