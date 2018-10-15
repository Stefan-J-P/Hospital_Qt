// Created by stefan on 5/27/18.
#ifndef HELLOQT_PATIENT_REPOSITORY_H
#define HELLOQT_PATIENT_REPOSITORY_H

#include "my_libs.h"
#include "patient.h"

class patient_repository
{
public:
    void add_patient(const patient& p);
    void update_patient(const patient& p);
    void delete_patient(const int id);

    QVector<patient> find_all_patients();
    boost::optional<patient> find_one_patient_by_id(const int id);
    boost::optional<patient> get_patient_id_by_name_surname_age(const QString& name, const QString& surname, const int age/*, const QString& sympt, const QString& diag*/);
};
#endif //HELLOQT_PATIENT_REPOSITORY_H
