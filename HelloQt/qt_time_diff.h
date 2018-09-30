// Created by stefan on 6/10/18.
#ifndef QDATETIME_QT_TIME_DIFF_H
#define QDATETIME_QT_TIME_DIFF_H

#include "my_libs.h"

class qt_time_diff
{
public:
    qt_time_diff() = default;
    static qint64 in_minutes(const QDateTime& q1, const QDateTime& q2);
    static qint64 in_hours(const QDateTime& q1, const QDateTime& q2);
    static QString in_hours_minutes(const QDateTime& q1, const QDateTime& q2);

    static QString split_QString(const QString& qstr, const int n);

};


#endif //QDATETIME_QT_TIME_DIFF_H
