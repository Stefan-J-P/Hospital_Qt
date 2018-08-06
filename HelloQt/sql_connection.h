#ifndef SQL_CONNECTION_H
#define SQL_CONNECTION_H

#include "my_libs.h"
#include "my_exception.h"


class sql_connection
{
private:
    sql_connection();
    static sql_connection* instance;

    // data requierd to connect with database
    const QString HOST_NAME;
    const QString DATABASE_NAME;
    const QString USERNAME;
    const QString PASSWORD;

    // object which connect with database
    QSqlDatabase db;

    void create_tables();
public:
    static sql_connection* get_instance();
    QSqlDatabase get_db();
    void close_connection();
};
#endif // SQL_CONNECTION_H
