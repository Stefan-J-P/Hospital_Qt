// Created by stefan on 5/22/18.

#include "patient.h"

// CONSTRUCTORS -----------------------------------------------------------------------
patient::patient(const QString &first_name, const QString &last_name, const int age)
: first_name_(first_name), last_name_(last_name), age_(age) {};

patient::patient(const int id, const QString &first_name, const QString &last_name, const int age)
: id_(id), first_name_(first_name), last_name_(last_name), age_(age){};

// GETTERS ---------------------------------------------------------------------------
int patient::get_id() const
{
    return id_;
}

const QString &patient::get_first_name() const
{
    return first_name_;
}

const QString &patient::get_last_name() const
{
    return last_name_;
}

int patient::get_age() const
{
    return age_;
}

// SETTERS --------------------------------------------------------------------------
void patient::set_id(const int id_)
{
    patient::id_ = id_;
}

void patient::set_first_name(const QString &first_name_)
{
    patient::first_name_ = first_name_;
}

void patient::set_last_name(const QString &last_name_)
{
    patient::last_name_ = last_name_;
}

void patient::set_age(const int age)
{
    patient::age_ = age;
}

// SHOW PATIENT -----------------------------------------------------------------------
QString patient::show_patient() const
{
    return QString::number(id_) + " " + first_name_ + " " + last_name_ + " " + QString::number(age_);
}
