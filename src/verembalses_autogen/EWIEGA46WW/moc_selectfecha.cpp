/****************************************************************************
** Meta object code from reading C++ file 'selectfecha.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../selectfecha.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'selectfecha.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DlgSelectFecha_t {
    QByteArrayData data[5];
    char stringdata0[67];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DlgSelectFecha_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DlgSelectFecha_t qt_meta_stringdata_DlgSelectFecha = {
    {
QT_MOC_LITERAL(0, 0, 14), // "DlgSelectFecha"
QT_MOC_LITERAL(1, 15, 20), // "cmbZonasIndexChanged"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 5), // "index"
QT_MOC_LITERAL(4, 43, 23) // "cmbEmbalsesIndexChanged"

    },
    "DlgSelectFecha\0cmbZonasIndexChanged\0"
    "\0index\0cmbEmbalsesIndexChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DlgSelectFecha[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x08 /* Private */,
       4,    1,   27,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,

       0        // eod
};

void DlgSelectFecha::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DlgSelectFecha *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->cmbZonasIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->cmbEmbalsesIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DlgSelectFecha::staticMetaObject = { {
    QMetaObject::SuperData::link<QtDialogWindow::staticMetaObject>(),
    qt_meta_stringdata_DlgSelectFecha.data,
    qt_meta_data_DlgSelectFecha,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DlgSelectFecha::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DlgSelectFecha::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DlgSelectFecha.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui::DialogSelectFecha"))
        return static_cast< Ui::DialogSelectFecha*>(this);
    return QtDialogWindow::qt_metacast(_clname);
}

int DlgSelectFecha::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QtDialogWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
