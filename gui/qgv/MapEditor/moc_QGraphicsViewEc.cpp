/****************************************************************************
** Meta object code from reading C++ file 'QGraphicsViewEc.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "QGraphicsViewEc.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QGraphicsViewEc.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QGraphicsViewEc[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      26,   17,   16,   16, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_QGraphicsViewEc[] = {
    "QGraphicsViewEc\0\0position\0"
    "doubleClick(QPointF)\0"
};

void QGraphicsViewEc::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QGraphicsViewEc *_t = static_cast<QGraphicsViewEc *>(_o);
        switch (_id) {
        case 0: _t->doubleClick((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QGraphicsViewEc::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QGraphicsViewEc::staticMetaObject = {
    { &QGraphicsView::staticMetaObject, qt_meta_stringdata_QGraphicsViewEc,
      qt_meta_data_QGraphicsViewEc, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QGraphicsViewEc::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QGraphicsViewEc::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QGraphicsViewEc::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QGraphicsViewEc))
        return static_cast<void*>(const_cast< QGraphicsViewEc*>(this));
    return QGraphicsView::qt_metacast(_clname);
}

int QGraphicsViewEc::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void QGraphicsViewEc::doubleClick(QPointF _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
