#-------------------------------------------------
#
# Project created by QtCreator 2018-06-15T18:44:43
#
#-------------------------------------------------

CONFIG += c++11
QT       += core gui
QT      += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HelloQt
TEMPLATE = app

SOURCES +=\
    panel_doctor.cpp \
    my_main_window.cpp \
    sql_connection.cpp \
    my_exception.cpp \
    doctor.cpp \
    patient.cpp \
    visit.cpp \
    doctor_repository.cpp \
    patient_repository.cpp \
    visit_repository.cpp \
    _MAIN.cpp \
    panel_patient.cpp \
    panel_visit.cpp \
    doctor_how_many_patients_average_cost_of_visit.cpp \
    panel_table.cpp \
    disease_patients_number.cpp \
    doctor_patients_common_disease.cpp \
    panel_table_2.cpp \
    panel_table_3.cpp \
    panel_table_visit_by_date.cpp \
    visits_by_date.cpp \
    my_calendar.cpp

HEADERS  += \
    panel_doctor.h \
    my_main_window.h \
    my_libs.h \
    sql_connection.h \
    my_exception.h \
    doctor.h \
    patient.h \
    visit.h \
    doctor_repository.h \
    patient_repository.h \
    visit_repository.h \
    panel_patient.h \
    panel_visit.h \
    doctor_how_many_patients_average_cost_of_visit.h \
    panel_table.h \
    disease_patients_number.h \
    doctor_patients_common_disease.h \
    panel_table_2.h \
    panel_table_3.h \
    panel_table_visit_by_date.h \
    visits_by_date.h \
    my_calendar.h

FORMS    += mainwindow.ui
