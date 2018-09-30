#ifndef DOCTOR_HOW_MANY_PATIENTS_AVERAGE_COST_OF_VISIT_H
#define DOCTOR_HOW_MANY_PATIENTS_AVERAGE_COST_OF_VISIT_H

#include "my_libs.h"
#include "doctor.h"
#include "patient.h"
#include "visit.h"
#include "doctor_repository.h"
#include "patient_repository.h"
#include "visit_repository.h"

class doctor_how_many_patients_average_cost_of_visit
{
private:
    QString doc_name_;
    QString doc_surname_;
    int patients_;
    double average_cost_;
public:
    // CONSTRUCTOR
    doctor_how_many_patients_average_cost_of_visit() = default;
    doctor_how_many_patients_average_cost_of_visit(const QString& doc_name, const QString& doc_surname, const int& patients, const double& average_cost);


    // GETTERS
    QString get_doc_name() const;
    QString get_doc_surname() const;
    int get_patients() const;
    double get_average_cost() const;

    // METHODS
    static QVector<doctor_how_many_patients_average_cost_of_visit> get_data();
};

#endif // DOCTOR_HOW_MANY_PATIENTS_AVERAGE_COST_OF_VISIT_H
