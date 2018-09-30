// Created by stefan on 5/27/18.
#include "visit_repository.h"
#include "sql_connection.h"
#include "my_libs.h"

// ADD VISIT -----------------------------------------------------------------------
void visit_repository::add_visit(const visit &v)
{
    QString sql = "insert into visit "
                  "(visit_date_time, doctor_id, patient_id, cost)"
                  "values (:visit_date_time, :doctor_id, :patient_id, :cost);";
    QSqlQuery query;
    query.prepare(sql);
    query.bindValue(":visit_date_time", v.get_visit_date_time());
    query.bindValue(":doctor_id", v.get_doctor_id());
    query.bindValue(":patient_id", v.get_patient_id());
    query.bindValue(":cost", v.get_cost());

    if(query.exec())
    {
        qDebug() << "New row into visit table inserted!\n";
    }
    else
    {
        qDebug() << sql_connection::get_instance()->get_db().lastError().text() << "\n";
        qDebug() << "Error while inserting in visit table\n";
    }
}

// UPDATE VISIT ------------------------------------------------------------------
void visit_repository::update_visit(const visit &v)
{
    QMessageBox* msg = new QMessageBox();
    msg->setText(QString::number(v.get_id()) + " " + QString::number(v.get_cost()));
    msg->show();
    QString sql = "update visit "
                  "set visit_date_time = :visit_date_time, doctor_id = :doctor_id, patient_id = :patient_id, cost = :cost "
                  "where id = :id;";
    //
    QSqlQuery query;
    query.prepare(sql);
    query.bindValue(":visit_date_time", v.get_visit_date_time());
    query.bindValue(":doctor_id", v.get_doctor_id());
    query.bindValue(":patient_id", v.get_patient_id());
    query.bindValue(":cost", v.get_cost());
    query.bindValue(":id", v.get_id());

    if(query.exec())
    {
        qDebug() << "Visit row with id = " << v.get_id() << " successfully updated!\n";
    }
    else
    {
        qDebug() << sql_connection::get_instance()->get_db().lastError().text() << "\n";
        qDebug() << "Error while updating in visit table\n";
    }
}

// DELETE VISIT --------------------------------------------------------------------
void visit_repository::delete_visit(const int id)
{
    QString sql = "delete from visit where id = :id";
    QSqlQuery query;
    query.prepare(sql);
    query.bindValue(":id", id);

    if (query.exec())
    {
        qDebug() << "Visit row with id = " << id << " successfully deleted!\n";
    }
    else
    {
        qDebug() << sql_connection::get_instance()->get_db().lastError().text() << "\n";
        qDebug() << "Error while deleting in visit table\n";
    }
}

// FIND ALL VISITS ------------------------------------------------------------------
QVector<visit> visit_repository::find_all_visits()
{
    QVector<visit> visits;
    QString sql = "select id, visit_date_time, doctor_id, patient_id, cost from visit";
    QSqlQuery query;
    query.exec(sql);

    while(query.next())
    {
        visits.push_back(visit{
                query.value(0).toInt(),
                query.value(1).toDateTime(),
                query.value(2).toInt(),
                query.value(3).toInt(),
                query.value(4).toDouble()});
    }
    return visits;
}

// FIND ONE VISIT BY ID -------------------------------------------------------------
boost::optional<visit> visit_repository::find_one_visit_by_id(const int id)
{
    QString sql = "select id, visit_date_time, doctor_id, patient_id, cost from visit where id = :id";
    QSqlQuery query;
    query.prepare(sql);
    query.bindValue(":id", id);

    if(query.exec())
    {
        if(query.next())
        {
            return boost::optional<visit>{visit{
            query.value(0).toInt(),
            query.value(1).toDateTime(),
            query.value(2).toInt(),
            query.value(3).toInt(),
            query.value(4).toDouble()
            }};
        }
    }
    else
    {
        qDebug() << "Error while selecting one visit from table\n";
    }

    return boost::optional<visit>{};
}

