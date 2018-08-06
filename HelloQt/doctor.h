#ifndef HELLOQT_DOCTOR_H
#define HELLOQT_DOCTOR_H

#include "my_libs.h"


class doctor
{
private:
    int id_;
    QString name_;
    QString surname_;
    QString specialization_;
public:
    // CONSTRUCTORS
    doctor() = default;
    doctor(const QString& name, const QString& surname, const QString& specialization);
    doctor(const int id, const QString& name, const QString& surname, const QString& specialization);

    // GETTERS
    int get_id() const;
    QString get_name() const;
    QString get_surname() const;
    QString get_specialization() const;

    //SETTERS
    void set_id(const int id);
    void set_name(const QString &name);
    void set_surname(const QString &surname);
    void set_specialization(const QString &specialization);

    // METHODS
    QString show_doctor() const;

};
#endif //HELLOQT_DOCTOR_H
