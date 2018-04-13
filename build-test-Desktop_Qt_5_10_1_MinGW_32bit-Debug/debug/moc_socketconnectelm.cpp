/****************************************************************************
** Meta object code from reading C++ file 'socketconnectelm.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../test/socketconnectelm.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'socketconnectelm.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SocketConnectELM_t {
    QByteArrayData data[8];
    char stringdata0[83];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SocketConnectELM_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SocketConnectELM_t qt_meta_stringdata_SocketConnectELM = {
    {
QT_MOC_LITERAL(0, 0, 16), // "SocketConnectELM"
QT_MOC_LITERAL(1, 17, 9), // "connected"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 12), // "disconnected"
QT_MOC_LITERAL(4, 41, 12), // "bytesWritten"
QT_MOC_LITERAL(5, 54, 5), // "bytes"
QT_MOC_LITERAL(6, 60, 9), // "readyRead"
QT_MOC_LITERAL(7, 70, 12) // "statusReader"

    },
    "SocketConnectELM\0connected\0\0disconnected\0"
    "bytesWritten\0bytes\0readyRead\0statusReader"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SocketConnectELM[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x0a /* Public */,
       3,    0,   40,    2, 0x0a /* Public */,
       4,    1,   41,    2, 0x0a /* Public */,
       6,    0,   44,    2, 0x0a /* Public */,
       7,    0,   45,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong,    5,
    QMetaType::Void,
    QMetaType::Bool,

       0        // eod
};

void SocketConnectELM::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SocketConnectELM *_t = static_cast<SocketConnectELM *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->connected(); break;
        case 1: _t->disconnected(); break;
        case 2: _t->bytesWritten((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 3: _t->readyRead(); break;
        case 4: { bool _r = _t->statusReader();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SocketConnectELM::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_SocketConnectELM.data,
      qt_meta_data_SocketConnectELM,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SocketConnectELM::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SocketConnectELM::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SocketConnectELM.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int SocketConnectELM::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
