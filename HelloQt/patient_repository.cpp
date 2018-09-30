// Created by stefan on 5/27/18.
#include "patient_repository.h"
#include "sql_connection.h"

// ADD PATIENT ------------------------------------------------------------------------
void patient_repository::add_patient(const patient &p)
{
    QString sql = "insert into patient "
                  "(first_name, last_name, age, symptoms, diagnose)"
                  "values (:first_name, :last_name, :age, :symptoms, :diagnose);";

    QSqlQuery query;
    query.prepare(sql);
    query.bindValue(":first_name", p.get_first_name());
    query.bindValue(":last_name", p.get_last_name());
    query.bindValue(":age", p.get_age());
    query.bindValue(":symptoms", p.get_symptoms());
    query.bindValue(":diagnose", p.get_diagnose());

    if(query.exec())
    {
        qDebug() << "New row into patient's table inserted!\n";
    } else
    {
        qDebug() << sql_connection::get_instance()->get_db().lastError().text() << "\n";
        qDebug() << "Error while inserting in patient table\n";
    }
}

// UPDATE PATIENT --------------------------------------------------------------------
void patient_repository::update_patient(const patient &p)
{
    QString sql = "update patient "
                  "set first_name = :first_name, last_name = :last_name, age = age, :symptoms = symptoms, :diagnose = diagnose"
                  "where id = :id;";
    QSqlQuery query;
    query.prepare(sql);
    query.bindValue(":first_name", p.get_first_name());
    query.bindValue(":last_name", p.get_last_name());
    query.bindValue(":age", p.get_age());
    query.bindValue(":symptoms", p.get_symptoms());
    query.bindValue(":diagnose", p.get_diagnose());
    query.bindValue(":id", p.get_id());

    if(query.exec())
    {
        qDebug() << "Patient in the table updated!\n";
    } else
    {
        qDebug() << sql_connection::get_instance()->get_db().lastError().text() << "\n";
        qDebug() << "Error while updating patient in table\n";
    }

}

// DELETE PATIENT---------------------------------------------------------------------
void patient_repository::delete_patient(const int id)
{
    QString sql = "delete from patient where id = :id";
    QSqlQuery query;
    query.prepare(sql);
    query.bindValue(":id", id);

    if(query.exec())
    {
        qDebug() << "Patient row with id = " << id << " successfully deleted!\n";
    } else
    {
        qDebug() << sql_connection::get_instance()->get_db().lastError().text() << "\n";
        qDebug() << "Error while deleting in patient table\n";
    }
}

// FIND ALL PATIENTS -----------------------------------------------------------------
QVector<patient> patient_repository::find_all_patients()
{
    QVector<patient> patients;
    QString sql = "select id, first_name, last_name, age, symptoms, diagnose from patient";
    QSqlQuery query;
    query.exec(sql);

    while(query.next())
    {
        patients.push_back(patient{
            query.value(0).toInt(),
            query.value(1).toString(),
            query.value(2).toString(),
            query.value(3).toInt(),
            query.value(4).toString(),
            query.value(5).toString()
        });
    }
    return patients;
}

// FIND ONE PATIENT BY ID ------------------------------------------------------------
boost::optional<patient> patient_repository::find_one_patient_by_id(const int id)
{
    QString sql = "select id, first_name, last_name, age, symptoms, diagnose from patient where id = :id";
    QSqlQuery query;
    query.prepare(sql);
    query.bindValue(":id", id);

    if(query.exec())
    {
        if(query.next())
        {
            return boost::optional<patient>{
                patient{
                    query.value(0).toInt(),
                    query.value(1).toString(),
                    query.value(2).toString(),
                    query.value(3).toInt(),
                    query.value(4).toString(),
                    query.value(5).toString()
                }
            };
        }
        else
        {
            qDebug() << "Error while selecting one doctor from table\n";
        }
    }
    return boost::optional<patient>();
}

