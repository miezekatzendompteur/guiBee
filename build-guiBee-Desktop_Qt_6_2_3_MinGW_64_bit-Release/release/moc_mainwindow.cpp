/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../guiBee/mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QScreen>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    const uint offsetsAndSize[22];
    char stringdata0[209];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 10), // "MainWindow"
QT_MOC_LITERAL(11, 11), // "setEditText"
QT_MOC_LITERAL(23, 0), // ""
QT_MOC_LITERAL(24, 16), // "realtimeDataSlot"
QT_MOC_LITERAL(41, 12), // "setInterface"
QT_MOC_LITERAL(54, 23), // "on_actionFile_triggered"
QT_MOC_LITERAL(78, 24), // "on_actionStart_triggered"
QT_MOC_LITERAL(103, 23), // "on_actionStop_triggered"
QT_MOC_LITERAL(127, 33), // "on_actionFind_Interface_trigg..."
QT_MOC_LITERAL(161, 23), // "on_actionInfo_triggered"
QT_MOC_LITERAL(185, 23) // "on_actionExit_triggered"

    },
    "MainWindow\0setEditText\0\0realtimeDataSlot\0"
    "setInterface\0on_actionFile_triggered\0"
    "on_actionStart_triggered\0"
    "on_actionStop_triggered\0"
    "on_actionFind_Interface_triggered\0"
    "on_actionInfo_triggered\0on_actionExit_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   68,    2, 0x08,    1 /* Private */,
       3,    0,   71,    2, 0x08,    3 /* Private */,
       4,    1,   72,    2, 0x08,    4 /* Private */,
       5,    0,   75,    2, 0x08,    6 /* Private */,
       6,    0,   76,    2, 0x08,    7 /* Private */,
       7,    0,   77,    2, 0x08,    8 /* Private */,
       8,    0,   78,    2, 0x08,    9 /* Private */,
       9,    0,   79,    2, 0x08,   10 /* Private */,
      10,    0,   80,    2, 0x08,   11 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QByteArray,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->setEditText((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 1: _t->realtimeDataSlot(); break;
        case 2: _t->setInterface((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_actionFile_triggered(); break;
        case 4: _t->on_actionStart_triggered(); break;
        case 5: _t->on_actionStop_triggered(); break;
        case 6: _t->on_actionFind_Interface_triggered(); break;
        case 7: _t->on_actionInfo_triggered(); break;
        case 8: _t->on_actionExit_triggered(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSize,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t
, QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QByteArray &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
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
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
