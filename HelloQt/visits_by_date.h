#ifndef VISITS_BY_DATE_H
#define VISITS_BY_DATE_H
#include "my_libs.h"
#include "visit.h"
#include "visit_repository.h"
#include "qt_time_diff.h"   // time span QDateTime

class visits_by_date
{
private:
    int visit_id_;
    QDateTime visit_date_time_;
    int doctor_id_;
    int patient_id_;
    double visit_cost_;

public:
    visits_by_date() = default;
    visits_by_date(const int vis, const QDateTime& vdt, const int doc_id, const int pat_id, const double vc);
    static QVector<visits_by_date> find_all_visits_asc();
    static bool is_date_correct(const visits_by_date& vis, const QDateTime& dt_1, const QDateTime& dt_2);
    static QVector<visits_by_date> validate_visits(const QDateTime &dt_1, const QDateTime &dt_2);

    // GETTERS
    int get_visit_id() const;
    QDateTime get_visit_date_time() const;
    int get_doctor_id() const;
    int get_patient_id() const;
    double get_visit_cost() const;
};

#endif // VISITS_BY_DATE_H
