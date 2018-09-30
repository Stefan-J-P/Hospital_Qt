#ifndef DOCTOR_PATIENTS_COMMON_DISEASE_H
#define DOCTOR_PATIENTS_COMMON_DISEASE_H

#include "my_libs.h"
#include "doctor.h"
#include "doctor_repository.h"
#include "patient.h"
#include "patient_repository.h"

class doctor_patients_common_disease
{
private:
    QString doc_name_;
    QString doc_surname_;
    QString disease_;
    doctor_repository* doc_rep_;
public:
    // CONSTRUCTOR
    doctor_patients_common_disease() = default;
    doctor_patients_common_disease(const QString& doc_name, const QString& doc_surname, const QString& disease, doctor_repository* doc_rep);

    // GETTERS
    QString get_doc_name() const;
    QString get_doc_surname() const;
    QString get_disease() const;

    // METHODS
    QVector<doctor_patients_common_disease> get_data();
    doctor_patients_common_disease find_data_for_doctor(const int id);



};

#endif // DOCTOR_PATIENTS_COMMON_DISEASE_H
