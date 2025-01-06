/****************************************************************************
** Meta object code from reading C++ file 'filterdockwidget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../QTCreator/work_space/database/app/view/filterdockwidget.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'filterdockwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSfilterdockwidgetENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSfilterdockwidgetENDCLASS = QtMocHelpers::stringData(
    "filterdockwidget",
    "preparedCompleteSIG",
    "",
    "setInfo",
    "fields",
    "type",
    "onbuttonBoxaccepted",
    "onbuttonBoxrejected",
    "addCondition",
    "index",
    "onDateTimeChanged",
    "dateTime"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSfilterdockwidgetENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    2,   51,    2, 0x0a,    2 /* Public */,
       6,    0,   56,    2, 0x0a,    5 /* Public */,
       7,    0,   57,    2, 0x0a,    6 /* Public */,
       8,    1,   58,    2, 0x0a,    7 /* Public */,
      10,    1,   61,    2, 0x0a,    9 /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QStringList, QMetaType::Bool,    4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::QDateTime,   11,

       0        // eod
};

Q_CONSTINIT const QMetaObject filterdockwidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSfilterdockwidgetENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSfilterdockwidgetENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSfilterdockwidgetENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<filterdockwidget, std::true_type>,
        // method 'preparedCompleteSIG'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setInfo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'onbuttonBoxaccepted'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onbuttonBoxrejected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'addCondition'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'onDateTimeChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QDateTime &, std::false_type>
    >,
    nullptr
} };

void filterdockwidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<filterdockwidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->preparedCompleteSIG(); break;
        case 1: _t->setInfo((*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 2: _t->onbuttonBoxaccepted(); break;
        case 3: _t->onbuttonBoxrejected(); break;
        case 4: _t->addCondition((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->onDateTimeChanged((*reinterpret_cast< std::add_pointer_t<QDateTime>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (filterdockwidget::*)();
            if (_t _q_method = &filterdockwidget::preparedCompleteSIG; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *filterdockwidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *filterdockwidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSfilterdockwidgetENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int filterdockwidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void filterdockwidget::preparedCompleteSIG()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
