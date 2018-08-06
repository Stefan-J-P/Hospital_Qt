// Created by stefan on 5/22/18.

#include "patient.h"

// CONSTRUCTORS -----------------------------------------------------------------------
patient::patient(const QString &first_name, const QString &last_name, const int age, const QString &symptoms, const QSrting &diagnose)
: first_name(first_name), last_name(last_name), age_(age), symptoms_(symptoms), diagnose_(diagnose) {}

patient::patient(const int id, const QString &first_name, const QString &last_name, const int age, const QString &symptoms, const QSrting &diagnose)
: id_(id), first_name(first_name), last_name(last_name), age_(age), symptoms_(symptoms), diagnose_(diagnose) {}

// GETTERS ---------------------------------------------------------------------------
int patient::get_id() const
{
    return id_;
}

const QString &patient::get_first_name() const
{
    return first_name;
}

const QString &patient::get_last_name() const
{
    return last_name;
}

int patient::get_age() const
{
    return age_;
}

const QString &patient::get_symptoms() const
{
    return symptoms_;
}

const QString &patient::get_diagnose() const
{
    return diagnose_;
}

// SETTERS --------------------------------------------------------------------------
void patient::set_id(const int id_)
{
    patient::id_ = id_;
}

void patient::set_first_name(const QString &first_name_)
{
    patient::first_name = first_name_;
}

void patient::set_last_name(const QString &last_name_)
{
    patient::last_name = last_name_;
}

void patient::set_age(const int age)
{
    patient::age_ = age;
}

void patient::set_symptoms(const QString &symptoms)
{
    patient::symptoms_= symptoms;
}

void patient::set_diagnose(const QString &diagnose)
{
    patient::diagnose_= diagnose;
}

// SHOW PATIENT -----------------------------------------------------------------------
QString patient::show_patient() const
{
    return QString::number(id_) + " " + first_name + " " + last_name + " " +
    QString::number(age_) + " " + symptoms_ + " " + diagnose_;
}
