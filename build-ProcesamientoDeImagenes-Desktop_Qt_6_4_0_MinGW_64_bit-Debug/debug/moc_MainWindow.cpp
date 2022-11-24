/****************************************************************************
** Meta object code from reading C++ file 'MainWindow.hpp'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../ProcesamientoDeImagenes/src/MainWindow.hpp"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainWindow.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_MainWindow_t {
    uint offsetsAndSizes[20];
    char stringdata0[11];
    char stringdata1[29];
    char stringdata2[1];
    char stringdata3[22];
    char stringdata4[30];
    char stringdata5[15];
    char stringdata6[25];
    char stringdata7[25];
    char stringdata8[36];
    char stringdata9[26];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_MainWindow_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 28),  // "on_BotonAjusteBrillo_clicked"
        QT_MOC_LITERAL(40, 0),  // ""
        QT_MOC_LITERAL(41, 21),  // "on_BotonSalir_clicked"
        QT_MOC_LITERAL(63, 29),  // "on_buton_elegirImagen_clicked"
        QT_MOC_LITERAL(93, 14),  // "inicializacion"
        QT_MOC_LITERAL(108, 24),  // "on_BotonNegativo_clicked"
        QT_MOC_LITERAL(133, 24),  // "on_BotonEscalado_clicked"
        QT_MOC_LITERAL(158, 35),  // "on_Button_Disminucionbrillo_c..."
        QT_MOC_LITERAL(194, 25)   // "on_BotonContraste_clicked"
    },
    "MainWindow",
    "on_BotonAjusteBrillo_clicked",
    "",
    "on_BotonSalir_clicked",
    "on_buton_elegirImagen_clicked",
    "inicializacion",
    "on_BotonNegativo_clicked",
    "on_BotonEscalado_clicked",
    "on_Button_Disminucionbrillo_clicked",
    "on_BotonContraste_clicked"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   62,    2, 0x08,    1 /* Private */,
       3,    0,   63,    2, 0x08,    2 /* Private */,
       4,    0,   64,    2, 0x08,    3 /* Private */,
       5,    0,   65,    2, 0x08,    4 /* Private */,
       6,    0,   66,    2, 0x08,    5 /* Private */,
       7,    0,   67,    2, 0x08,    6 /* Private */,
       8,    0,   68,    2, 0x08,    7 /* Private */,
       9,    0,   69,    2, 0x08,    8 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSizes,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'on_BotonAjusteBrillo_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_BotonSalir_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_buton_elegirImagen_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'inicializacion'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_BotonNegativo_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_BotonEscalado_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Button_Disminucionbrillo_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_BotonContraste_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_BotonAjusteBrillo_clicked(); break;
        case 1: _t->on_BotonSalir_clicked(); break;
        case 2: _t->on_buton_elegirImagen_clicked(); break;
        case 3: _t->inicializacion(); break;
        case 4: _t->on_BotonNegativo_clicked(); break;
        case 5: _t->on_BotonEscalado_clicked(); break;
        case 6: _t->on_Button_Disminucionbrillo_clicked(); break;
        case 7: _t->on_BotonContraste_clicked(); break;
        default: ;
        }
    }
    (void)_a;
}

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
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
