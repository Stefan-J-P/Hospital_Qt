#ifndef SQL_CONNECTION_H
#define SQL_CONNECTION_H

#include "my_libs.h"
#include "my_exception.h"


class sql_connection
{
private:
    sql_connection();
    static sql_connection* instance;

    // dane potrzebne do polaczenia z mysql
    const QString HOST_NAME;
    const QString DATABASE_NAME;
    const QString USERNAME;
    const QString PASSWORD;

    // obiekt laczacy sie z baza danych
    QSqlDatabase db;
    // tworzenie tabel
    void create_tables();
public:
    static sql_connection* get_instance();
    QSqlDatabase get_db();
    void close_connection();
};
#endif // SQL_CONNECTION_H
