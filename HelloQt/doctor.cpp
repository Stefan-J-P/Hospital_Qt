// Created by stefan on 5/22/18.
#include "doctor.h"

// CONSTRUCTORS ----------------------------------------------------------------------
doctor::doctor(const QString& name, const QString& specialization)
: name_(name), specialization_(specialization){};

doctor::doctor(const int id, const QString& name, const QString& specialization)
: id_(id), name_(name), specialization_(specialization){};


// GETTERS ---------------------------------------------------------------------------
int doctor::get_id() const
{
    return id_;
}

QString doctor::get_name() const
{
    return name_;
}

QString doctor::get_specialization() const
{
    return specialization_;
}


// SETTERS --------------------------------------------------------------------------
void doctor::set_id(const int id)
{
    id_ = id;
}

void doctor::set_name(const QString &name)
{
    name_= std::regex_match(name.toStdString(), std::regex("[A-Z ]+")) ? QString(name) : "DOCTOR";
}

void doctor::set_specialization(const QString &specialization)
{
    specialization_= std::regex_match(specialization.toStdString(), std::regex("[A-Z ]+")) ? QString(specialization) : "DOCTOR";
}

// METHODS -------------------------------------------------------------------------
QString doctor::show_doctor() const
{
    return QString::number(id_) + " " + name_ + " " + specialization_;
}

