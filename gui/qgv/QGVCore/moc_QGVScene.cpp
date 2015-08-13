/****************************************************************************
** Meta object code from reading C++ file 'QGVScene.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "QGVScene.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QGVScene.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QGVScene[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,   10,    9,    9, 0x05,
      41,   10,    9,    9, 0x05,
      72,   67,    9,    9, 0x05,
      98,   67,    9,    9, 0x05,
     130,  124,    9,    9, 0x05,
     164,  124,    9,    9, 0x05,
     198,    9,    9,    9, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_QGVScene[] = {
    "QGVScene\0\0node\0nodeContextMenu(QGVNode*)\0"
    "nodeDoubleClick(QGVNode*)\0edge\0"
    "edgeContextMenu(QGVEdge*)\0"
    "edgeDoubleClick(QGVEdge*)\0graph\0"
    "subGraphContextMenu(QGVSubGraph*)\0"
    "subGraphDoubleClick(QGVSubGraph*)\0"
    "graphContextMenuEvent()\0"
};

void QGVScene::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QGVScene *_t = static_cast<QGVScene *>(_o);
        switch (_id) {
        case 0: _t->nodeContextMenu((*reinterpret_cast< QGVNode*(*)>(_a[1]))); break;
        case 1: _t->nodeDoubleClick((*reinterpret_cast< QGVNode*(*)>(_a[1]))); break;
        case 2: _t->edgeContextMenu((*reinterpret_cast< QGVEdge*(*)>(_a[1]))); break;
        case 3: _t->edgeDoubleClick((*reinterpret_cast< QGVEdge*(*)>(_a[1]))); break;
        case 4: _t->subGraphContextMenu((*reinterpret_cast< QGVSubGraph*(*)>(_a[1]))); break;
        case 5: _t->subGraphDoubleClick((*reinterpret_cast< QGVSubGraph*(*)>(_a[1]))); break;
        case 6: _t->graphContextMenuEvent(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QGVScene::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QGVScene::staticMetaObject = {
    { &QGraphicsScene::staticMetaObject, qt_meta_stringdata_QGVScene,
      qt_meta_data_QGVScene, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QGVScene::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QGVScene::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QGVScene::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QGVScene))
        return static_cast<void*>(const_cast< QGVScene*>(this));
    return QGraphicsScene::qt_metacast(_clname);
}

int QGVScene::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsScene::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void QGVScene::nodeContextMenu(QGVNode * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QGVScene::nodeDoubleClick(QGVNode * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QGVScene::edgeContextMenu(QGVEdge * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QGVScene::edgeDoubleClick(QGVEdge * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void QGVScene::subGraphContextMenu(QGVSubGraph * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void QGVScene::subGraphDoubleClick(QGVSubGraph * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void QGVScene::graphContextMenuEvent()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}
QT_END_MOC_NAMESPACE
