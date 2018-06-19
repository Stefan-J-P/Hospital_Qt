// Created by stefan on 5/22/18.
#ifndef HELLOQT_DOCTOR_REPOSITORY_H
#define HELLOQT_DOCTOR_REPOSITORY_H

#include "my_libs.h"
#include "doctor.h"

class doctor_repository
{
public:
    void add_doctor(const doctor& d);
    void update_doctor(const doctor& d);
    void delete_doctor(const int id);
    QVector<doctor> find_all_doctors();
    boost::optional<doctor> find_one_doctor_by_id(const int id);
};
#endif //HELLOQT_DOCTOR_REPOSITORY_H
