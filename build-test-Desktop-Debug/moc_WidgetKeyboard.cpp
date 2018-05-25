/****************************************************************************
** Meta object code from reading C++ file 'WidgetKeyboard.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Widgetkeyboard/src/WidgetKeyboard.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'WidgetKeyboard.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_WidgetKeyboard_t {
    QByteArrayData data[21];
    char stringdata0[333];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WidgetKeyboard_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WidgetKeyboard_t qt_meta_stringdata_WidgetKeyboard = {
    {
QT_MOC_LITERAL(0, 0, 14), // "WidgetKeyboard"
QT_MOC_LITERAL(1, 15, 14), // "on_btn_clicked"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 3), // "btn"
QT_MOC_LITERAL(4, 35, 18), // "on_btnCaps_toggled"
QT_MOC_LITERAL(5, 54, 7), // "checked"
QT_MOC_LITERAL(6, 62, 23), // "on_btnShiftLeft_toggled"
QT_MOC_LITERAL(7, 86, 24), // "on_btnShiftRight_toggled"
QT_MOC_LITERAL(8, 111, 22), // "on_btnCtrlLeft_toggled"
QT_MOC_LITERAL(9, 134, 21), // "on_btnAltLeft_toggled"
QT_MOC_LITERAL(10, 156, 17), // "on_btnIns_clicked"
QT_MOC_LITERAL(11, 174, 19), // "on_btnPrint_clicked"
QT_MOC_LITERAL(12, 194, 29), // "on_sliderOpacity_valueChanged"
QT_MOC_LITERAL(13, 224, 15), // "changeTextShift"
QT_MOC_LITERAL(14, 240, 7), // "isShift"
QT_MOC_LITERAL(15, 248, 14), // "changeTextCaps"
QT_MOC_LITERAL(16, 263, 6), // "isCaps"
QT_MOC_LITERAL(17, 270, 15), // "checkNotTextKey"
QT_MOC_LITERAL(18, 286, 5), // "keyId"
QT_MOC_LITERAL(19, 292, 34), // "on_checkBoxShowNumPad_stateCh..."
QT_MOC_LITERAL(20, 327, 5) // "state"

    },
    "WidgetKeyboard\0on_btn_clicked\0\0btn\0"
    "on_btnCaps_toggled\0checked\0"
    "on_btnShiftLeft_toggled\0"
    "on_btnShiftRight_toggled\0"
    "on_btnCtrlLeft_toggled\0on_btnAltLeft_toggled\0"
    "on_btnIns_clicked\0on_btnPrint_clicked\0"
    "on_sliderOpacity_valueChanged\0"
    "changeTextShift\0isShift\0changeTextCaps\0"
    "isCaps\0checkNotTextKey\0keyId\0"
    "on_checkBoxShowNumPad_stateChanged\0"
    "state"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WidgetKeyboard[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x08 /* Private */,
       4,    1,   82,    2, 0x08 /* Private */,
       6,    1,   85,    2, 0x08 /* Private */,
       7,    1,   88,    2, 0x08 /* Private */,
       8,    1,   91,    2, 0x08 /* Private */,
       9,    1,   94,    2, 0x08 /* Private */,
      10,    0,   97,    2, 0x08 /* Private */,
      11,    0,   98,    2, 0x08 /* Private */,
      12,    1,   99,    2, 0x08 /* Private */,
      13,    1,  102,    2, 0x08 /* Private */,
      15,    1,  105,    2, 0x08 /* Private */,
      17,    1,  108,    2, 0x08 /* Private */,
      19,    1,  111,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Bool,   14,
    QMetaType::Void, QMetaType::Bool,   16,
    QMetaType::Bool, QMetaType::Int,   18,
    QMetaType::Void, QMetaType::Int,   20,

       0        // eod
};

void WidgetKeyboard::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WidgetKeyboard *_t = static_cast<WidgetKeyboard *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_btn_clicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_btnCaps_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->on_btnShiftLeft_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->on_btnShiftRight_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->on_btnCtrlLeft_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->on_btnAltLeft_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->on_btnIns_clicked(); break;
        case 7: _t->on_btnPrint_clicked(); break;
        case 8: _t->on_sliderOpacity_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->changeTextShift((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->changeTextCaps((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: { bool _r = _t->checkNotTextKey((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 12: _t->on_checkBoxShowNumPad_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject WidgetKeyboard::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_WidgetKeyboard.data,
      qt_meta_data_WidgetKeyboard,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *WidgetKeyboard::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WidgetKeyboard::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_WidgetKeyboard.stringdata0))
        return static_cast<void*>(const_cast< WidgetKeyboard*>(this));
    if (!strcmp(_clname, "Ui::WidgetKeyboard"))
        return static_cast< Ui::WidgetKeyboard*>(const_cast< WidgetKeyboard*>(this));
    return QWidget::qt_metacast(_clname);
}

int WidgetKeyboard::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
