#include "visits_by_date.h"

// CONSTRUCTOR ---------------------------------------------------------------------------
visits_by_date::visits_by_date(const int vis, const QDateTime& vdt, const int doc_id, const int pat_id, const double vc)
{

}

// FIND ALL VISITS -----------------------------------------------------------------------
QVector<visits_by_date> visits_by_date::find_all_visits_asc()
{
    QVector<visits_by_date> data;
    visits_by_date vbd;
    QString sql = "select id, visit_date_time, doctor_id, patient_id, cost from visit order by visit_date_time asc;";
    QSqlQuery query;
    query.exec(sql);

    while(query.next())
    {
        vbd.visit_id_ = query.value(0).toInt();
        vbd.visit_date_time_ = query.value(1).toDateTime(),
        vbd.doctor_id_ = query.value(2).toInt(),
        vbd.patient_id_ = query.value(3).toInt(),
        vbd.visit_cost_ = query.value(4).toDouble();
        data.push_back(vbd);
    }

    return data;
}

// IS DATE CORRECT -----------------------------------------------------------------------------
bool visits_by_date::is_date_correct(const visits_by_date &vis, const QDateTime &dt_1, const QDateTime &dt_2)
{
    return vis.get_visit_date_time() >= dt_1 && vis.get_visit_date_time() <= dt_2;
}

// VALIDATE VISITS ----------------------------------------------------------------------------
QVector<visits_by_date> visits_by_date::validate_visits(const QDateTime &dt_1, const QDateTime &dt_2)
{
    QVector<visits_by_date> data = visits_by_date::find_all_visits_asc();

    QVector<visits_by_date> result;
    for(auto i = 0; i < data.size(); ++i )
    {
        if (is_date_correct(data[i], dt_1, dt_2))
        {
            result.push_back(data[i]);
        }
    }
    return result;
}

// GETTERS -------------------------------------------------------------------------------------
int visits_by_date::get_visit_id() const
{
    return visit_id_;
}

QDateTime visits_by_date::get_visit_date_time() const
{
    return visit_date_time_;
}

int visits_by_date::get_doctor_id() const
{
    return doctor_id_;
}

int visits_by_date::get_patient_id() const
{
    return patient_id_;
}

double visits_by_date::get_visit_cost() const
{
    return visit_cost_;
}

