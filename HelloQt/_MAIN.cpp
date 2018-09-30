#include "my_main_window.h"
#include <QApplication>
#include "my_libs.h"
#include "panel_doctor.h"

#include "sql_connection.h"
#include "my_exception.h"

#include "doctor_repository.h"
#include "patient_repository.h"
#include "visit_repository.h"

#include "doctor_how_many_patients_average_cost_of_visit.h"

int main(int argc, char* argv[])
{

    // -------------------------------------------------------------------
    // ----------------- CONSOL APPLICATION -----------------------------
    // -------------------------------------------------------------------
    /*
    QCoreApplication app(argc, argv);

    try {
        sql_connection* db = sql_connection::get_instance();
        doctor_repository doc_rep;
        patient_repository pat_rep;
        visit_repository vis_rep;

        boost::optional<doctor> doctor_op = doc_rep.find_one_doctor_by_id(3);
        //if (doctor_op) { qDebug() << doctor_op->show_doctor(); }
        QVector <doctor> doctors = doc_rep.find_all_doctors();
        for (const auto& x : doctors){qDebug() << x.show_doctor();}
        boost::optional<patient> patient_op = pat_rep.find_one_patient_by_id(4);
        //if(patient_op){qDebug() << patient_op->show_patient();}
        QVector <patient> patients = pat_rep.find_all_patients();
        for(const auto& x : patients){qDebug() << x.show_patient();}

        boost::optional<visit> visit_opt = vis_rep.find_one_visit_by_id(1);
        //if(visit_opt){qDebug() << visit_opt->show_visit();}
        QVector <visit> visits = vis_rep.find_all_visits();
        for(const auto& x : visits) {qDebug() << x.show_visit();}



        db->close_connection();
    }
    catch (const my_exception& e)
    {
        qDebug() << e.str();
    }

    return app.exec();      */



    QApplication a(argc, argv);
    sql_connection* db = sql_connection::get_instance();
    my_main_window my_window_;
    my_window_.show();




    return a.exec();

}


