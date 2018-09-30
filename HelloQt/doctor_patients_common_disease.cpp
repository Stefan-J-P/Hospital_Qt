#include "doctor_patients_common_disease.h"

// CONSTRUCTOR -------------------------------------------------------------------------------
doctor_patients_common_disease::doctor_patients_common_disease(const QString &doc_name, const QString &doc_surname, const QString &disease, doctor_repository* doc_rep)
: doc_name_(doc_name), doc_surname_(doc_surname), disease_(disease), doc_rep_(doc_rep) {}

// GETTERS -----------------------------------------------------------------------------------
QString doctor_patients_common_disease::get_doc_name() const
{
    return doc_name_;
}

QString doctor_patients_common_disease::get_doc_surname() const
{
    return doc_surname_;
}

QString doctor_patients_common_disease::get_disease() const
{
    return disease_;
}

// GET DATA ----------------------------------------------------------------------------------
QVector<doctor_patients_common_disease> doctor_patients_common_disease::get_data()
{

    QVector<doctor> all_doctors = doc_rep_->find_all_doctors();
    QVector <doctor_patients_common_disease> data;

    for (const auto& doc : all_doctors)
    {
        data.push_back(find_data_for_doctor(doc.get_id()));
    }


    return data;
}

doctor_patients_common_disease doctor_patients_common_disease::find_data_for_doctor(const int doc_id)
{
    QString sql = "select d.name, d.surname, p.diagnose from doctor d join visit v on d.id = v.doctor_id join patient p on v.patient_id = p.id where d.id = :id group by p.diagnose order by count(p.diagnose) desc, diagnose limit 1;";
    doctor_patients_common_disease dpcd;
    QSqlQuery query(sql);

    query.prepare(sql);
    query.bindValue(":id", doc_id);

    if (query.exec())
    {
        if (query.next())
        {
            dpcd.doc_name_ = query.value(0).toString(),
            dpcd.doc_surname_ = query.value(1).toString(),
            dpcd.disease_ = query.value(2).toString();
        }
    }

    return dpcd;
}




