/****************************************************************************
** Meta object code from reading C++ file 'selectplayer.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../crosswordGUI/selectplayer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'selectplayer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_selectPlayer_t {
    const uint offsetsAndSize[14];
    char stringdata0[109];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_selectPlayer_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_selectPlayer_t qt_meta_stringdata_selectPlayer = {
    {
QT_MOC_LITERAL(0, 12), // "selectPlayer"
QT_MOC_LITERAL(13, 19), // "selectPlayer_closed"
QT_MOC_LITERAL(33, 0), // ""
QT_MOC_LITERAL(34, 18), // "on_backBtn_clicked"
QT_MOC_LITERAL(53, 26), // "on_deletePlayerBtn_clicked"
QT_MOC_LITERAL(80, 18), // "on_playBtn_clicked"
QT_MOC_LITERAL(99, 9) // "on_logout"

    },
    "selectPlayer\0selectPlayer_closed\0\0"
    "on_backBtn_clicked\0on_deletePlayerBtn_clicked\0"
    "on_playBtn_clicked\0on_logout"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_selectPlayer[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   44,    2, 0x06,    0 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   45,    2, 0x08,    1 /* Private */,
       4,    0,   46,    2, 0x08,    2 /* Private */,
       5,    0,   47,    2, 0x08,    3 /* Private */,
       6,    0,   48,    2, 0x08,    4 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void selectPlayer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<selectPlayer *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->selectPlayer_closed(); break;
        case 1: _t->on_backBtn_clicked(); break;
        case 2: _t->on_deletePlayerBtn_clicked(); break;
        case 3: _t->on_playBtn_clicked(); break;
        case 4: _t->on_logout(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (selectPlayer::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&selectPlayer::selectPlayer_closed)) {
                *result = 0;
                return;
            }
        }
    }
    (void)_a;
}

const QMetaObject selectPlayer::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_selectPlayer.offsetsAndSize,
    qt_meta_data_selectPlayer,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_selectPlayer_t
, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *selectPlayer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *selectPlayer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_selectPlayer.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int selectPlayer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void selectPlayer::selectPlayer_closed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
