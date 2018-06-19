#ifndef MY_EXCEPTION_H
#define MY_EXCEPTION_H

#include "my_libs.h"

class my_exception : public std::exception
{
private:
    QString error_message_;
    QDateTime error_date_;
public:
    my_exception(const QString& error_message, const QDateTime& error_date);
    QString str() const;
};

#endif // MY_EXCEPTION_H
