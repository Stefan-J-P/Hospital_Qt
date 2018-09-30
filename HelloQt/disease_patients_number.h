    #ifndef DISEASE_PATIENTS_NUMBER_H
#define DISEASE_PATIENTS_NUMBER_H

#include "my_libs.h"
#include "doctor.h"
#include "patient.h"
#include "visit.h"
#include "doctor_repository.h"
#include "patient_repository.h"
#include "visit_repository.h"

class disease_patients_number
{
private:
    QString disease_;
    int patients_number_;
public:
    // CONSTRUCTOR
    disease_patients_number() = default;
    disease_patients_number(const QString& dis, const int pat_num);

    // GETTERS
    QString get_disease() const;
    int get_patients_number() const;

    // METHODS
    static QVector<disease_patients_number> get_data();
};

#endif // DISEASE_PATIENTS_NUMBER_H
