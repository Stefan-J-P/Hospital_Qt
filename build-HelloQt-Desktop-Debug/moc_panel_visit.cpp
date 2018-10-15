/****************************************************************************
** Meta object code from reading C++ file 'panel_visit.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../HelloQt/panel_visit.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'panel_visit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_panel_visit_t {
    QByteArrayData data[14];
    char stringdata0[139];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_panel_visit_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_panel_visit_t qt_meta_stringdata_panel_visit = {
    {
QT_MOC_LITERAL(0, 0, 11), // "panel_visit"
QT_MOC_LITERAL(1, 12, 9), // "add_visit"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 12), // "update_visit"
QT_MOC_LITERAL(4, 36, 12), // "delete_visit"
QT_MOC_LITERAL(5, 49, 9), // "get_visit"
QT_MOC_LITERAL(6, 59, 3), // "idx"
QT_MOC_LITERAL(7, 63, 13), // "get_doctor_id"
QT_MOC_LITERAL(8, 77, 1), // "d"
QT_MOC_LITERAL(9, 79, 14), // "get_patient_id"
QT_MOC_LITERAL(10, 94, 1), // "p"
QT_MOC_LITERAL(11, 96, 12), // "refresh_data"
QT_MOC_LITERAL(12, 109, 14), // "refresh_doc_id"
QT_MOC_LITERAL(13, 124, 14) // "refresh_pat_id"

    },
    "panel_visit\0add_visit\0\0update_visit\0"
    "delete_visit\0get_visit\0idx\0get_doctor_id\0"
    "d\0get_patient_id\0p\0refresh_data\0"
    "refresh_doc_id\0refresh_pat_id"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_panel_visit[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x0a /* Public */,
       3,    0,   60,    2, 0x0a /* Public */,
       4,    0,   61,    2, 0x0a /* Public */,
       5,    1,   62,    2, 0x0a /* Public */,
       7,    1,   65,    2, 0x0a /* Public */,
       9,    1,   68,    2, 0x0a /* Public */,
      11,    0,   71,    2, 0x0a /* Public */,
      12,    0,   72,    2, 0x0a /* Public */,
      13,    0,   73,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Int, QMetaType::QString,    8,
    QMetaType::Int, QMetaType::QString,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void panel_visit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        panel_visit *_t = static_cast<panel_visit *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->add_visit(); break;
        case 1: _t->update_visit(); break;
        case 2: _t->delete_visit(); break;
        case 3: _t->get_visit((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: { int _r = _t->get_doctor_id((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 5: { int _r = _t->get_patient_id((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 6: _t->refresh_data(); break;
        case 7: _t->refresh_doc_id(); break;
        case 8: _t->refresh_pat_id(); break;
        default: ;
        }
    }
}

const QMetaObject panel_visit::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_panel_visit.data,
      qt_meta_data_panel_visit,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *panel_visit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *panel_visit::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_panel_visit.stringdata0))
        return static_cast<void*>(const_cast< panel_visit*>(this));
    return QWidget::qt_metacast(_clname);
}

int panel_visit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
