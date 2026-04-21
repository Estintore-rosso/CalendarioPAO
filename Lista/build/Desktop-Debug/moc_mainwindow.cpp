/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.13)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.13. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[19];
    char stringdata0[387];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 34), // "on_listaAttivita_currentRowCh..."
QT_MOC_LITERAL(2, 46, 0), // ""
QT_MOC_LITERAL(3, 47, 10), // "currentRow"
QT_MOC_LITERAL(4, 58, 19), // "on_btnNuovo_clicked"
QT_MOC_LITERAL(5, 78, 22), // "on_btnModifica_clicked"
QT_MOC_LITERAL(6, 101, 21), // "on_btnElimina_clicked"
QT_MOC_LITERAL(7, 123, 19), // "on_btnSalva_clicked"
QT_MOC_LITERAL(8, 143, 21), // "on_btnAnnulla_clicked"
QT_MOC_LITERAL(9, 165, 32), // "on_comboTipo_currentIndexChanged"
QT_MOC_LITERAL(10, 198, 5), // "index"
QT_MOC_LITERAL(11, 204, 21), // "on_btnEsporta_clicked"
QT_MOC_LITERAL(12, 226, 21), // "on_btnImporta_clicked"
QT_MOC_LITERAL(13, 248, 24), // "on_checkSuperato_toggled"
QT_MOC_LITERAL(14, 273, 7), // "checked"
QT_MOC_LITERAL(15, 281, 26), // "on_editRicerca_textChanged"
QT_MOC_LITERAL(16, 308, 4), // "arg1"
QT_MOC_LITERAL(17, 313, 38), // "on_comboFiltroTipo_currentInd..."
QT_MOC_LITERAL(18, 352, 34) // "on_checkFiltroUrgente_stateCh..."

    },
    "MainWindow\0on_listaAttivita_currentRowChanged\0"
    "\0currentRow\0on_btnNuovo_clicked\0"
    "on_btnModifica_clicked\0on_btnElimina_clicked\0"
    "on_btnSalva_clicked\0on_btnAnnulla_clicked\0"
    "on_comboTipo_currentIndexChanged\0index\0"
    "on_btnEsporta_clicked\0on_btnImporta_clicked\0"
    "on_checkSuperato_toggled\0checked\0"
    "on_editRicerca_textChanged\0arg1\0"
    "on_comboFiltroTipo_currentIndexChanged\0"
    "on_checkFiltroUrgente_stateChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
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
       4,    0,   82,    2, 0x08 /* Private */,
       5,    0,   83,    2, 0x08 /* Private */,
       6,    0,   84,    2, 0x08 /* Private */,
       7,    0,   85,    2, 0x08 /* Private */,
       8,    0,   86,    2, 0x08 /* Private */,
       9,    1,   87,    2, 0x08 /* Private */,
      11,    0,   90,    2, 0x08 /* Private */,
      12,    0,   91,    2, 0x08 /* Private */,
      13,    1,   92,    2, 0x08 /* Private */,
      15,    1,   95,    2, 0x08 /* Private */,
      17,    1,   98,    2, 0x08 /* Private */,
      18,    1,  101,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   14,
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   16,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_listaAttivita_currentRowChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_btnNuovo_clicked(); break;
        case 2: _t->on_btnModifica_clicked(); break;
        case 3: _t->on_btnElimina_clicked(); break;
        case 4: _t->on_btnSalva_clicked(); break;
        case 5: _t->on_btnAnnulla_clicked(); break;
        case 6: _t->on_comboTipo_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_btnEsporta_clicked(); break;
        case 8: _t->on_btnImporta_clicked(); break;
        case 9: _t->on_checkSuperato_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->on_editRicerca_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: _t->on_comboFiltroTipo_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->on_checkFiltroUrgente_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
