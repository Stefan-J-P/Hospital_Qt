#include "my_main_window.h"
#include <QApplication>
#include "my_libs.h"
#include "panel_doctor.h"

#include "sql_connection.h"
#include "my_exception.h"

#include "doctor_repository.h"
#include "patient_repository.h"
#include "visit_repository.h"

int main(int argc, char* argv[])
{

    // -------------------------------------------------------------------
    // ----------------- APLIKACJA KONSOLOWA -----------------------------
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







/*        doc_rep.add_doctor(doctor{"MAREK", "GINEKOLOG"});
        doc_rep.add_doctor(doctor{"TOMASZ", "ANESTEZJOLOG"});
        doc_rep.add_doctor(doctor{"ZYGMUNT", "CHIRURG"});
        doc_rep.add_doctor(doctor{"HALINA", "ONKOLOG"});
        doc_rep.update_doctor(doctor{4, "ZOFIA", "DERMATOLOG"});
        doc_rep.delete_doctor(4);   */

/*        pat_rep.add_patient(patient{"ZYGMUNT", "HAJZER", 66});
        pat_rep.add_patient(patient{"MATEUSZ", "OJCIEC", 45});
        pat_rep.add_patient(patient{"JAROSLAW", "KACZYNSKI", 68});
        pat_rep.add_patient(patient{"BEATA", "SZYDLO", 55});
        pat_rep.update_patient(patient{4, "TINA", "TURNER", 75});
        pat_rep.delete_patient(4);*/

/*        vis_rep.add_visit(visit{QDateTime::currentDateTime(), 3, 3, 150});
        vis_rep.add_visit(visit{QDateTime::currentDateTime(), 1, 2, 320});
        vis_rep.add_visit(visit{QDateTime::currentDateTime(), 3, 2, 150});
        vis_rep.add_visit(visit{QDateTime::currentDateTime(), 2, 3, 200});
        vis_rep.update_visit(visit{4, QDateTime::currentDateTime(), 3, 4, 170});
        vis_rep.delete_visit(4);*/
















