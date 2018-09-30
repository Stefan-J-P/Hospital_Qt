//
// Created by stefan on 6/10/18.
//

#include "qt_time_diff.h"

qint64 qt_time_diff::in_minutes(const QDateTime& q1, const QDateTime& q2)
{
    qint64 time_diff = q2.secsTo(q1);
    qint64 time_diff_minutes = time_diff / 60;
    return time_diff_minutes;
}

qint64 qt_time_diff::in_hours(const QDateTime &q1, const QDateTime &q2)
{
    qint64 time_diff = q2.secsTo(q1);
    qint64 minutes = time_diff / 60;
    qint64 hours = minutes / 60;
    return hours;
}

QString qt_time_diff::in_hours_minutes(const QDateTime &q1, const QDateTime &q2)
{
    qint64 time_diff = q2.secsTo(q1);
    qint64 minutes = time_diff / 60;
    qint64 hours = minutes / 60;
    qint64 extra_minutes = minutes % 60;
    QString qstr = QString::number(hours) + ":" + QString::number(extra_minutes);

    return qstr;
}

QString qt_time_diff::split_QString(const QString &qstr, const int n)
{
    QStringList list = qstr.split(':');
    QString qstr1 = list.at(n);
    return qstr1;
}
