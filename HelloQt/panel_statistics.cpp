#include "panel_statistics.h"

// CONSTRUCTOR -----------------------------------------------------------------------------------
panel_statistics::panel_statistics(QWidget *parent) : QWidget(parent)
{
    table_ = new QTableWidget(4, 4);
    vertical_layout_ = new QVBoxLayout();
    vertical_layout_->addWidget(table_);
    setLayout(vertical_layout_);


}

// DEESTRUCTOR ----------------------------------------------------------------------------------
panel_statistics::~panel_statistics()
{

}
/*
panel_statistics::fill_table()
{
    QString sql;


}   */



/*
 * OSOBNY PANEL
 * - zrobic tabele w ktorej mamy wizyty uporzadkowane wedlug daty, dodatkowo pod albo nad panelem
 * zrobic dwa comboboxy, jeden zawiera date "od" a drugi zawiera date "do" i mozesz po wybraniu dat
 * wypisywac tylko te wizyty ktore sa w przedziale.
 *
 * Wizyty powinny sie wypisywac kiedy od razu wybierzesz date.
 * Powinna byc walidacja daty czy czasem data od nie jest wieksza niz data do i wtedy
 * message z bledem
 *
 */













