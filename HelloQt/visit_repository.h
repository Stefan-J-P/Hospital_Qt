// Created by stefan on 5/27/18.
#ifndef HELLOQT_VISIT_REPOSITORY_H
#define HELLOQT_VISIT_REPOSITORY_H
#include "my_libs.h"
#include "doctor.h"
#include "patient.h"
#include "visit.h"

class visit_repository
{
public:
void add_visit(const visit& v);
void update_visit(const visit& v);
void delete_visit(const int id);
QVector<visit> find_all_visits();
boost::optional<visit> find_one_visit_by_id(const int id);
};
#endif //HELLOQT_VISIT_REPOSITORY_H
