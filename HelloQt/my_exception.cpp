#include "my_exception.h"

my_exception::my_exception(const QString& error_message, const QDateTime& error_date)
: error_message_(error_message), error_date_(error_date){}

QString my_exception::str() const
{
    return "ERROR: " + error_message_ + " DATE:" + error_date_.toString();
}
