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
};
#endif //HELLOQT_PATIENT_REPOSITORY_H
