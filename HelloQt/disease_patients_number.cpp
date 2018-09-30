#include "disease_patients_number.h"

// CONSTRUCTOR --------------------------------------------------------------------------------
disease_patients_number::disease_patients_number(const QString& dis, const int pat_num)
: disease_(dis), patients_number_(pat_num) {}


// GETTERS ------------------------------------------------------------------------------------
QString disease_patients_number::get_disease() const
{
    return disease_;
}

int disease_patients_number::get_patients_number() const
{
    return patients_number_;
}

// GET DATA -----------------------------------------------------------------------------------
QVector<disease_patients_number> disease_patients_number::get_data()
{
    QString sql = "select p.diagnose, count(p.id) from patient p group by p.diagnose ;";
    // #select count(p.diagnose) from patient p group by diagnose ;
    // #select p.diagnose from patient p;

    QVector<disease_patients_number> data;
    disease_patients_number dpn;

    QSqlQuery query;
    query.exec(sql);

    while(query.next())
    {
        dpn.disease_ = query.value(0).toString(),
        dpn.patients_number_ = query.value(1).toInt();
        data.push_back(dpn);
    }
    return data;
}

