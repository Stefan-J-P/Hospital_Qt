// Created by stefan on 5/22/18.
#ifndef HELLOQT_VISIT_H
#define HELLOQT_VISIT_H
#include "my_libs.h"
#include "doctor.h"
#include "patient.h"


class visit
{
private:
    int id_;
    QDateTime visit_date_time_;
    int doctor_id_;
    int patient_id_;
    double cost_;
public:
    // CONSTRUCTORS
    visit() = default;
    visit(const QDateTime& dt, const int doc_id, const int pat_id, const double& cost);
    visit(const int id, const QDateTime& dt, const int doc_id, const int pat_id, const double& cost);

    // GETTERS
    int get_id() const;
    const QDateTime &get_visit_date_time() const;
    int get_doctor_id() const;
    int get_patient_id() const;
    double get_cost() const;

    // SETTERS
    void set_id(int id_);
    void set_visit_date_time(const QDateTime &visit_date_time_);
    void set_doctor_id(int doctor_id_);
    void set_patient_id(int patient_id_);
    void set_cost(double cost_);

    QString show_visit() const;
};
#endif //HELLOQT_VISIT_H
