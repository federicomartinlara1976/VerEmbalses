/****************************************************************************
** Meta object code from reading C++ file 'verembalses.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../verembalses.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'verembalses.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_VerEmbalses_t {
    QByteArrayData data[8];
    char stringdata0[116];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VerEmbalses_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VerEmbalses_t qt_meta_stringdata_VerEmbalses = {
    {
QT_MOC_LITERAL(0, 0, 11), // "VerEmbalses"
QT_MOC_LITERAL(1, 12, 20), // "cmbZonasIndexChanged"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 5), // "index"
QT_MOC_LITERAL(4, 40, 23), // "cmbEmbalsesIndexChanged"
QT_MOC_LITERAL(5, 64, 18), // "showGraphicClicked"
QT_MOC_LITERAL(6, 83, 16), // "showExcelClicked"
QT_MOC_LITERAL(7, 100, 15) // "buscarPorFechas"

    },
    "VerEmbalses\0cmbZonasIndexChanged\0\0"
    "index\0cmbEmbalsesIndexChanged\0"
    "showGraphicClicked\0showExcelClicked\0"
    "buscarPorFechas"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VerEmbalses[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x08 /* Private */,
       4,    1,   42,    2, 0x08 /* Private */,
       5,    0,   45,    2, 0x08 /* Private */,
       6,    0,   46,    2, 0x08 /* Private */,
       7,    0,   47,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void VerEmbalses::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<VerEmbalses *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->cmbZonasIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->cmbEmbalsesIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->showGraphicClicked(); break;
        case 3: _t->showExcelClicked(); break;
        case 4: _t->buscarPorFechas(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject VerEmbalses::staticMetaObject = { {
    QMetaObject::SuperData::link<QtWindow::staticMetaObject>(),
    qt_meta_stringdata_VerEmbalses.data,
    qt_meta_data_VerEmbalses,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *VerEmbalses::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VerEmbalses::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_VerEmbalses.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui::MainWindow"))
        return static_cast< Ui::MainWindow*>(this);
    return QtWindow::qt_metacast(_clname);
}

int VerEmbalses::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QtWindow::qt_metacall(_c, _id, _a);
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
