#include "doctor_how_many_patients_average_cost_of_visit.h"

// CONSTRUCTOR ----------------------------------------------------------------------------------------------------------------
doctor_how_many_patients_average_cost_of_visit::doctor_how_many_patients_average_cost_of_visit(const QString &doc_name, const QString &doc_surname, const int &patients, const double &average_cost)
: doc_name_(doc_name), doc_surname_(doc_surname), patients_(patients), average_cost_(average_cost){}


// GET DATA --------------------------------------------------------------------------------------------------------------------
QVector<doctor_how_many_patients_average_cost_of_visit> doctor_how_many_patients_average_cost_of_visit::get_data()
{
    QString sql = "SELECT d.name, d.surname, count(p.id), avg(v.cost) FROM doctor d join visit v on d.id = v.doctor_id join patient p on p.id = v.patient_id group by d.id;";
    QVector <doctor_how_many_patients_average_cost_of_visit> data;
    doctor_how_many_patients_average_cost_of_visit doc;
    QSqlQuery query;
    query.exec(sql);   

    while(query.next())
    {
        doc.doc_name_ = query.value(0).toString();
        doc.doc_surname_ = query.value(1).toString(),
        doc.patients_ = query.value(2).toInt(),
        doc.average_cost_ = query.value(3).toDouble();
        data.push_back(doc);
    }
    return data;
}


    QString doctor_how_many_patients_average_cost_of_visit::get_doc_name() const
    {
        return doc_name_;
    }


    QString doctor_how_many_patients_average_cost_of_visit::get_doc_surname() const
    {
        return doc_surname_;
    }


    int doctor_how_many_patients_average_cost_of_visit::get_patients() const
    {
        return patients_;
    }


    double doctor_how_many_patients_average_cost_of_visit::get_average_cost() const
    {
        return average_cost_;
    }





