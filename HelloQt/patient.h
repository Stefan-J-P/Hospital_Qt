// Created by stefan on 5/22/18.
#ifndef HELLOQT_PATIENT_H
#define HELLOQT_PATIENT_H

#include "my_libs.h"

class patient
{
private:
    int id_;
    QString first_name_;
    QString last_name_;
    int age_;
public:
    // CONSTRUCTOR
    patient()= default;
    patient(const QString& first_name, const QString& last_name, const int age);
    patient(const int id, const QString& first_name, const QString& last_name, const int age);

    // GETTERS
    int get_id() const;
    const QString &get_first_name() const;
    const QString &get_last_name() const;
    int get_age() const;
    // SETTERS
    void set_id(const int id_);
    void set_first_name(const QString &first_name_);
    void set_last_name(const QString &last_name_);
    void set_age(const int age);

    // METHODS
    QString show_patient() const;
};
#endif //HELLOQT_PATIENT_H
