/****************************************************************************
** Meta object code from reading C++ file 'controlmesin.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../test/controlmesin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'controlmesin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ControlMesin_t {
    QByteArrayData data[7];
    char stringdata0[127];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ControlMesin_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ControlMesin_t qt_meta_stringdata_ControlMesin = {
    {
QT_MOC_LITERAL(0, 0, 12), // "ControlMesin"
QT_MOC_LITERAL(1, 13, 27), // "on_listNomerMesin_activated"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 4), // "arg1"
QT_MOC_LITERAL(4, 47, 23), // "on_pushButton_3_clicked"
QT_MOC_LITERAL(5, 71, 28), // "on_pushButton_kering_clicked"
QT_MOC_LITERAL(6, 100, 26) // "on_pushButton_cuci_clicked"

    },
    "ControlMesin\0on_listNomerMesin_activated\0"
    "\0arg1\0on_pushButton_3_clicked\0"
    "on_pushButton_kering_clicked\0"
    "on_pushButton_cuci_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ControlMesin[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x08 /* Private */,
       4,    0,   37,    2, 0x08 /* Private */,
       5,    0,   38,    2, 0x08 /* Private */,
       6,    0,   39,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ControlMesin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ControlMesin *_t = static_cast<ControlMesin *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_listNomerMesin_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->on_pushButton_3_clicked(); break;
        case 2: _t->on_pushButton_kering_clicked(); break;
        case 3: _t->on_pushButton_cuci_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ControlMesin::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ControlMesin.data,
      qt_meta_data_ControlMesin,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ControlMesin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ControlMesin::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ControlMesin.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int ControlMesin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
