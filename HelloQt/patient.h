// Created by stefan on 5/22/18.
#ifndef HELLOQT_PATIENT_H
#define HELLOQT_PATIENT_H

#include "my_libs.h"

class patient
{
private:
    int id_;
    QString first_name;
    QString last_name;
    int age_;
    QString symptoms_;
    QString diagnose_;

public:
    // CONSTRUCTOR
    patient()= default;
    patient(const QString& first_name, const QString& last_name, const int age, const QString& symptoms, const QString& diagnose);
    patient(const int id, const QString& first_name, const QString& last_name, const int age, const QString& symptoms, const QString& diagnose);

    // GETTERS
    int get_id() const;
    const QString &get_first_name() const;
    const QString &get_last_name() const;
    int get_age() const;
    const QString &get_symptoms() const;
    const QString &get_diagnose() const;
    // SETTERS
    void set_id(const int id_);
    void set_first_name(const QString &first_name);
    void set_last_name(const QString &last_name);
    void set_age(const int age);
    void set_symptoms(const QString &symptoms);
    void set_diagnose(const QString &diagnose);


    // METHODS
    QString show_patient() const;
};
#endif //HELLOQT_PATIENT_H
