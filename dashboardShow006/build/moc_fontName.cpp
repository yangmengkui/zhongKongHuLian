/****************************************************************************
** Meta object code from reading C++ file 'fontName.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/include/fontName.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fontName.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MFontName_t {
    QByteArrayData data[14];
    char stringdata[301];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MFontName_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MFontName_t qt_meta_stringdata_MFontName = {
    {
QT_MOC_LITERAL(0, 0, 9),
QT_MOC_LITERAL(1, 10, 32),
QT_MOC_LITERAL(2, 43, 0),
QT_MOC_LITERAL(3, 44, 28),
QT_MOC_LITERAL(4, 73, 26),
QT_MOC_LITERAL(5, 100, 24),
QT_MOC_LITERAL(6, 125, 23),
QT_MOC_LITERAL(7, 149, 27),
QT_MOC_LITERAL(8, 177, 25),
QT_MOC_LITERAL(9, 203, 21),
QT_MOC_LITERAL(10, 225, 19),
QT_MOC_LITERAL(11, 245, 17),
QT_MOC_LITERAL(12, 263, 16),
QT_MOC_LITERAL(13, 280, 20)
    },
    "MFontName\0fontCurrentMicroSoftYaheiChanged\0"
    "\0fontCurrentBombardierChanged\0"
    "fontCurrentOutlinesChanged\0"
    "fontCurrentIMPACTChanged\0"
    "fontCurrentarialChanged\0"
    "fontCurrentBebasNeueChanged\0"
    "fontCurrentMicroSoftYahei\0"
    "fontCurrentBombardier\0fontCurrentOutlines\0"
    "fontCurrentIMPACT\0fontCurrentarial\0"
    "fontCurrentBebasNeue"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MFontName[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       6,   62, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       3,    1,   47,    2, 0x06 /* Public */,
       4,    1,   50,    2, 0x06 /* Public */,
       5,    1,   53,    2, 0x06 /* Public */,
       6,    1,   56,    2, 0x06 /* Public */,
       7,    1,   59,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // properties: name, type, flags
       8, QMetaType::QString, 0x00495001,
       9, QMetaType::QString, 0x00495001,
      10, QMetaType::QString, 0x00495001,
      11, QMetaType::QString, 0x00495001,
      12, QMetaType::QString, 0x00495001,
      13, QMetaType::QString, 0x00495001,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,
       4,
       5,

       0        // eod
};

void MFontName::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MFontName *_t = static_cast<MFontName *>(_o);
        switch (_id) {
        case 0: _t->fontCurrentMicroSoftYaheiChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->fontCurrentBombardierChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->fontCurrentOutlinesChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->fontCurrentIMPACTChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->fontCurrentarialChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->fontCurrentBebasNeueChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MFontName::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MFontName::fontCurrentMicroSoftYaheiChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (MFontName::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MFontName::fontCurrentBombardierChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (MFontName::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MFontName::fontCurrentOutlinesChanged)) {
                *result = 2;
            }
        }
        {
            typedef void (MFontName::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MFontName::fontCurrentIMPACTChanged)) {
                *result = 3;
            }
        }
        {
            typedef void (MFontName::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MFontName::fontCurrentarialChanged)) {
                *result = 4;
            }
        }
        {
            typedef void (MFontName::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MFontName::fontCurrentBebasNeueChanged)) {
                *result = 5;
            }
        }
    }
}

const QMetaObject MFontName::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MFontName.data,
      qt_meta_data_MFontName,  qt_static_metacall, 0, 0}
};


const QMetaObject *MFontName::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MFontName::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MFontName.stringdata))
        return static_cast<void*>(const_cast< MFontName*>(this));
    return QObject::qt_metacast(_clname);
}

int MFontName::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = fontCurrentMicroSoftYahei(); break;
        case 1: *reinterpret_cast< QString*>(_v) = fontCurrentBombardier(); break;
        case 2: *reinterpret_cast< QString*>(_v) = fontCurrentOutlines(); break;
        case 3: *reinterpret_cast< QString*>(_v) = fontCurrentIMPACT(); break;
        case 4: *reinterpret_cast< QString*>(_v) = fontCurrentarial(); break;
        case 5: *reinterpret_cast< QString*>(_v) = fontCurrentBebasNeue(); break;
        default: break;
        }
        _id -= 6;
    } else if (_c == QMetaObject::WriteProperty) {
        _id -= 6;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 6;
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void MFontName::fontCurrentMicroSoftYaheiChanged(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MFontName::fontCurrentBombardierChanged(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MFontName::fontCurrentOutlinesChanged(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MFontName::fontCurrentIMPACTChanged(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MFontName::fontCurrentarialChanged(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MFontName::fontCurrentBebasNeueChanged(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_END_MOC_NAMESPACE
