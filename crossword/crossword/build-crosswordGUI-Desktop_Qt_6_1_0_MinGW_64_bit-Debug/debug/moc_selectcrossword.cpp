/****************************************************************************
** Meta object code from reading C++ file 'selectcrossword.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../crosswordGUI/selectcrossword.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'selectcrossword.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_selectCrossword_t {
    const uint offsetsAndSize[22];
    char stringdata0[195];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_selectCrossword_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_selectCrossword_t qt_meta_stringdata_selectCrossword = {
    {
QT_MOC_LITERAL(0, 15), // "selectCrossword"
QT_MOC_LITERAL(16, 6), // "logout"
QT_MOC_LITERAL(23, 0), // ""
QT_MOC_LITERAL(24, 20), // "on_logoutBtn_clicked"
QT_MOC_LITERAL(45, 18), // "on_playBtn_clicked"
QT_MOC_LITERAL(64, 11), // "on_game_end"
QT_MOC_LITERAL(76, 29), // "on_deletaCrosswordBtn_clicked"
QT_MOC_LITERAL(106, 26), // "on_addCrosswordBtn_clicked"
QT_MOC_LITERAL(133, 10), // "reset_list"
QT_MOC_LITERAL(144, 29), // "on_deleteCrosswordBtn_clicked"
QT_MOC_LITERAL(174, 20) // "on_deleteBtn_clicked"

    },
    "selectCrossword\0logout\0\0on_logoutBtn_clicked\0"
    "on_playBtn_clicked\0on_game_end\0"
    "on_deletaCrosswordBtn_clicked\0"
    "on_addCrosswordBtn_clicked\0reset_list\0"
    "on_deleteCrosswordBtn_clicked\0"
    "on_deleteBtn_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_selectCrossword[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   68,    2, 0x06,    0 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   69,    2, 0x08,    1 /* Private */,
       4,    0,   70,    2, 0x08,    2 /* Private */,
       5,    0,   71,    2, 0x08,    3 /* Private */,
       6,    0,   72,    2, 0x08,    4 /* Private */,
       7,    0,   73,    2, 0x08,    5 /* Private */,
       8,    0,   74,    2, 0x08,    6 /* Private */,
       9,    0,   75,    2, 0x08,    7 /* Private */,
      10,    0,   76,    2, 0x08,    8 /* Private */,

 // signals: parameters
    QMetaType::Void,

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

void selectCrossword::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<selectCrossword *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->logout(); break;
        case 1: _t->on_logoutBtn_clicked(); break;
        case 2: _t->on_playBtn_clicked(); break;
        case 3: _t->on_game_end(); break;
        case 5: _t->on_addCrosswordBtn_clicked(); break;
        case 6: _t->reset_list(); break;
        case 8: _t->on_deleteBtn_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (selectCrossword::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&selectCrossword::logout)) {
                *result = 0;
                return;
            }
        }
    }
    (void)_a;
}

const QMetaObject selectCrossword::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_selectCrossword.offsetsAndSize,
    qt_meta_data_selectCrossword,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_selectCrossword_t
, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *selectCrossword::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *selectCrossword::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_selectCrossword.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int selectCrossword::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void selectCrossword::logout()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
