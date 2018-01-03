/****************************************************************************
** Meta object code from reading C++ file 'mainWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mainWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_mainTab_t {
    QByteArrayData data[1];
    char stringdata0[8];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_mainTab_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_mainTab_t qt_meta_stringdata_mainTab = {
    {
QT_MOC_LITERAL(0, 0, 7) // "mainTab"

    },
    "mainTab"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_mainTab[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void mainTab::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject mainTab::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_mainTab.data,
      qt_meta_data_mainTab,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *mainTab::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *mainTab::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_mainTab.stringdata0))
        return static_cast<void*>(const_cast< mainTab*>(this));
    return QWidget::qt_metacast(_clname);
}

int mainTab::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
struct qt_meta_stringdata_Calculator_t {
    QByteArrayData data[25];
    char stringdata0[320];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Calculator_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Calculator_t qt_meta_stringdata_Calculator = {
    {
QT_MOC_LITERAL(0, 0, 10), // "Calculator"
QT_MOC_LITERAL(1, 11, 11), // "zeroClicked"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 10), // "oneClicked"
QT_MOC_LITERAL(4, 35, 10), // "twoClicked"
QT_MOC_LITERAL(5, 46, 12), // "threeClicked"
QT_MOC_LITERAL(6, 59, 11), // "fourClicked"
QT_MOC_LITERAL(7, 71, 11), // "fiveClicked"
QT_MOC_LITERAL(8, 83, 10), // "sixClicked"
QT_MOC_LITERAL(9, 94, 12), // "sevenClicked"
QT_MOC_LITERAL(10, 107, 12), // "eightClicked"
QT_MOC_LITERAL(11, 120, 11), // "nineClicked"
QT_MOC_LITERAL(12, 132, 10), // "addClicked"
QT_MOC_LITERAL(13, 143, 10), // "subClicked"
QT_MOC_LITERAL(14, 154, 10), // "mulClicked"
QT_MOC_LITERAL(15, 165, 10), // "divClicked"
QT_MOC_LITERAL(16, 176, 10), // "equClicked"
QT_MOC_LITERAL(17, 187, 17), // "leftBucketClicked"
QT_MOC_LITERAL(18, 205, 18), // "rightBucketClicked"
QT_MOC_LITERAL(19, 224, 9), // "ACClicked"
QT_MOC_LITERAL(20, 234, 9), // "CEClicked"
QT_MOC_LITERAL(21, 244, 12), // "createBehind"
QT_MOC_LITERAL(22, 257, 25), // "std::vector<NumOrSymbol>&"
QT_MOC_LITERAL(23, 283, 11), // "solveBehind"
QT_MOC_LITERAL(24, 295, 24) // "std::vector<NumOrSymbol>"

    },
    "Calculator\0zeroClicked\0\0oneClicked\0"
    "twoClicked\0threeClicked\0fourClicked\0"
    "fiveClicked\0sixClicked\0sevenClicked\0"
    "eightClicked\0nineClicked\0addClicked\0"
    "subClicked\0mulClicked\0divClicked\0"
    "equClicked\0leftBucketClicked\0"
    "rightBucketClicked\0ACClicked\0CEClicked\0"
    "createBehind\0std::vector<NumOrSymbol>&\0"
    "solveBehind\0std::vector<NumOrSymbol>"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Calculator[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      21,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  119,    2, 0x08 /* Private */,
       3,    0,  120,    2, 0x08 /* Private */,
       4,    0,  121,    2, 0x08 /* Private */,
       5,    0,  122,    2, 0x08 /* Private */,
       6,    0,  123,    2, 0x08 /* Private */,
       7,    0,  124,    2, 0x08 /* Private */,
       8,    0,  125,    2, 0x08 /* Private */,
       9,    0,  126,    2, 0x08 /* Private */,
      10,    0,  127,    2, 0x08 /* Private */,
      11,    0,  128,    2, 0x08 /* Private */,
      12,    0,  129,    2, 0x08 /* Private */,
      13,    0,  130,    2, 0x08 /* Private */,
      14,    0,  131,    2, 0x08 /* Private */,
      15,    0,  132,    2, 0x08 /* Private */,
      16,    0,  133,    2, 0x08 /* Private */,
      17,    0,  134,    2, 0x08 /* Private */,
      18,    0,  135,    2, 0x08 /* Private */,
      19,    0,  136,    2, 0x08 /* Private */,
      20,    0,  137,    2, 0x08 /* Private */,
      21,    2,  138,    2, 0x08 /* Private */,
      23,    1,  143,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QString, 0x80000000 | 22,    2,    2,
    QMetaType::QString, 0x80000000 | 24,    2,

       0        // eod
};

void Calculator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Calculator *_t = static_cast<Calculator *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->zeroClicked(); break;
        case 1: _t->oneClicked(); break;
        case 2: _t->twoClicked(); break;
        case 3: _t->threeClicked(); break;
        case 4: _t->fourClicked(); break;
        case 5: _t->fiveClicked(); break;
        case 6: _t->sixClicked(); break;
        case 7: _t->sevenClicked(); break;
        case 8: _t->eightClicked(); break;
        case 9: _t->nineClicked(); break;
        case 10: _t->addClicked(); break;
        case 11: _t->subClicked(); break;
        case 12: _t->mulClicked(); break;
        case 13: _t->divClicked(); break;
        case 14: _t->equClicked(); break;
        case 15: _t->leftBucketClicked(); break;
        case 16: _t->rightBucketClicked(); break;
        case 17: _t->ACClicked(); break;
        case 18: _t->CEClicked(); break;
        case 19: { bool _r = _t->createBehind((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< std::vector<NumOrSymbol>(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 20: { QString _r = _t->solveBehind((*reinterpret_cast< std::vector<NumOrSymbol>(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObject Calculator::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Calculator.data,
      qt_meta_data_Calculator,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Calculator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Calculator::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Calculator.stringdata0))
        return static_cast<void*>(const_cast< Calculator*>(this));
    return QWidget::qt_metacast(_clname);
}

int Calculator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 21)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 21;
    }
    return _id;
}
struct qt_meta_stringdata_RSATab_t {
    QByteArrayData data[7];
    char stringdata0[90];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RSATab_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RSATab_t qt_meta_stringdata_RSATab = {
    {
QT_MOC_LITERAL(0, 0, 6), // "RSATab"
QT_MOC_LITERAL(1, 7, 11), // "initClicked"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 14), // "encryptClicked"
QT_MOC_LITERAL(4, 35, 14), // "decryptClicked"
QT_MOC_LITERAL(5, 50, 17), // "selectFileClicked"
QT_MOC_LITERAL(6, 68, 21) // "getKeyFromFileClicked"

    },
    "RSATab\0initClicked\0\0encryptClicked\0"
    "decryptClicked\0selectFileClicked\0"
    "getKeyFromFileClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RSATab[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    0,   41,    2, 0x08 /* Private */,
       5,    0,   42,    2, 0x08 /* Private */,
       6,    0,   43,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void RSATab::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RSATab *_t = static_cast<RSATab *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->initClicked(); break;
        case 1: _t->encryptClicked(); break;
        case 2: _t->decryptClicked(); break;
        case 3: _t->selectFileClicked(); break;
        case 4: _t->getKeyFromFileClicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject RSATab::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_RSATab.data,
      qt_meta_data_RSATab,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *RSATab::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RSATab::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_RSATab.stringdata0))
        return static_cast<void*>(const_cast< RSATab*>(this));
    return QWidget::qt_metacast(_clname);
}

int RSATab::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
struct qt_meta_stringdata_GetMouse_t {
    QByteArrayData data[1];
    char stringdata0[9];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GetMouse_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GetMouse_t qt_meta_stringdata_GetMouse = {
    {
QT_MOC_LITERAL(0, 0, 8) // "GetMouse"

    },
    "GetMouse"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GetMouse[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void GetMouse::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject GetMouse::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_GetMouse.data,
      qt_meta_data_GetMouse,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *GetMouse::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GetMouse::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_GetMouse.stringdata0))
        return static_cast<void*>(const_cast< GetMouse*>(this));
    return QDialog::qt_metacast(_clname);
}

int GetMouse::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
