// Created by stefan on 5/22/18.

#include "visit.h"

// CONSTRUCTORS --------------------------------------------------------------------
visit::visit(const QDateTime &dt, const int doc_id, const int pat_id, const double &cost)
: visit_date_time_(dt), doctor_id_(doc_id), patient_id_(pat_id), cost_(cost) {}

visit::visit(const int id, const QDateTime &dt, const int doc_id, const int pat_id, const double &cost)
: id_(id), visit_date_time_(dt), doctor_id_(doc_id), patient_id_(pat_id), cost_(cost) {}


// GETTERS -------------------------------------------------------------------------
int visit::get_id() const
{
    return id_;
}

const QDateTime &visit::get_visit_date_time() const
{
    return visit_date_time_;
}

int visit::get_doctor_id() const
{
    return doctor_id_;
}

int visit::get_patient_id() const
{
    return patient_id_;
}

double visit::get_cost() const
{
    return cost_;
}


// SETTERS -------------------------------------------------------------------------
void visit::set_id(int id_)
{
    visit::id_ = id_;
}

void visit::set_visit_date_time(const QDateTime &visit_date_time_)
{
    visit::visit_date_time_ = visit_date_time_;
}

void visit::set_doctor_id(int doctor_id_)
{
    visit::doctor_id_ = doctor_id_;
}

void visit::set_patient_id(int patient_id_)
{
    visit::patient_id_ = patient_id_;
}

void visit::set_cost(double cost_)
{
    visit::cost_ = cost_;
}

// SHOW VISIT -----------------------------------------------------------------------------
QString visit::show_visit() const
{
    return "VIS_id: " + QString::number(id_) + ", " +
    visit_date_time_.toString() + ", " +
    "DOC_id: " + QString::number(doctor_id_) + ", " +
    "PAT_id: " + QString::number(patient_id_) + ", " +
    "COST: " + QString::number(cost_);
}




