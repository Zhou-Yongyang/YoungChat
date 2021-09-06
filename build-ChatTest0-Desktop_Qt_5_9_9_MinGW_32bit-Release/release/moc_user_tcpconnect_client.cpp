/****************************************************************************
** Meta object code from reading C++ file 'user_tcpconnect_client.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../YoungChat-Client/user_tcpconnect_client.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'user_tcpconnect_client.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_User_TcpConnect_Client_t {
    QByteArrayData data[13];
    char stringdata0[210];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_User_TcpConnect_Client_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_User_TcpConnect_Client_t qt_meta_stringdata_User_TcpConnect_Client = {
    {
QT_MOC_LITERAL(0, 0, 22), // "User_TcpConnect_Client"
QT_MOC_LITERAL(1, 23, 9), // "sig_login"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 4), // "flag"
QT_MOC_LITERAL(4, 39, 16), // "sig_loginSuccess"
QT_MOC_LITERAL(5, 56, 15), // "sig_loginFailed"
QT_MOC_LITERAL(6, 72, 17), // "sig_signupSuccess"
QT_MOC_LITERAL(7, 90, 16), // "sig_signupFailed"
QT_MOC_LITERAL(8, 107, 19), // "sig_resetPswSuccess"
QT_MOC_LITERAL(9, 127, 18), // "sig_resetPswFailed"
QT_MOC_LITERAL(10, 146, 21), // "sig_makeFriReqSuccess"
QT_MOC_LITERAL(11, 168, 20), // "sig_makeFriReqFailed"
QT_MOC_LITERAL(12, 189, 20) // "slot_recevierMessage"

    },
    "User_TcpConnect_Client\0sig_login\0\0"
    "flag\0sig_loginSuccess\0sig_loginFailed\0"
    "sig_signupSuccess\0sig_signupFailed\0"
    "sig_resetPswSuccess\0sig_resetPswFailed\0"
    "sig_makeFriReqSuccess\0sig_makeFriReqFailed\0"
    "slot_recevierMessage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_User_TcpConnect_Client[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       4,    0,   67,    2, 0x06 /* Public */,
       5,    0,   68,    2, 0x06 /* Public */,
       6,    0,   69,    2, 0x06 /* Public */,
       7,    0,   70,    2, 0x06 /* Public */,
       8,    0,   71,    2, 0x06 /* Public */,
       9,    0,   72,    2, 0x06 /* Public */,
      10,    0,   73,    2, 0x06 /* Public */,
      11,    0,   74,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    0,   75,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void User_TcpConnect_Client::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        User_TcpConnect_Client *_t = static_cast<User_TcpConnect_Client *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sig_login((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->sig_loginSuccess(); break;
        case 2: _t->sig_loginFailed(); break;
        case 3: _t->sig_signupSuccess(); break;
        case 4: _t->sig_signupFailed(); break;
        case 5: _t->sig_resetPswSuccess(); break;
        case 6: _t->sig_resetPswFailed(); break;
        case 7: _t->sig_makeFriReqSuccess(); break;
        case 8: _t->sig_makeFriReqFailed(); break;
        case 9: _t->slot_recevierMessage(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (User_TcpConnect_Client::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&User_TcpConnect_Client::sig_login)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (User_TcpConnect_Client::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&User_TcpConnect_Client::sig_loginSuccess)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (User_TcpConnect_Client::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&User_TcpConnect_Client::sig_loginFailed)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (User_TcpConnect_Client::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&User_TcpConnect_Client::sig_signupSuccess)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (User_TcpConnect_Client::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&User_TcpConnect_Client::sig_signupFailed)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (User_TcpConnect_Client::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&User_TcpConnect_Client::sig_resetPswSuccess)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (User_TcpConnect_Client::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&User_TcpConnect_Client::sig_resetPswFailed)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (User_TcpConnect_Client::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&User_TcpConnect_Client::sig_makeFriReqSuccess)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (User_TcpConnect_Client::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&User_TcpConnect_Client::sig_makeFriReqFailed)) {
                *result = 8;
                return;
            }
        }
    }
}

const QMetaObject User_TcpConnect_Client::staticMetaObject = {
    { &User_TcpConnect::staticMetaObject, qt_meta_stringdata_User_TcpConnect_Client.data,
      qt_meta_data_User_TcpConnect_Client,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *User_TcpConnect_Client::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *User_TcpConnect_Client::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_User_TcpConnect_Client.stringdata0))
        return static_cast<void*>(this);
    return User_TcpConnect::qt_metacast(_clname);
}

int User_TcpConnect_Client::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = User_TcpConnect::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void User_TcpConnect_Client::sig_login(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void User_TcpConnect_Client::sig_loginSuccess()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void User_TcpConnect_Client::sig_loginFailed()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void User_TcpConnect_Client::sig_signupSuccess()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void User_TcpConnect_Client::sig_signupFailed()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void User_TcpConnect_Client::sig_resetPswSuccess()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void User_TcpConnect_Client::sig_resetPswFailed()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void User_TcpConnect_Client::sig_makeFriReqSuccess()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void User_TcpConnect_Client::sig_makeFriReqFailed()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
