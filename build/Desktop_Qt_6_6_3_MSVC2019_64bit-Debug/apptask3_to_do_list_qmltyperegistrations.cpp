/****************************************************************************
** Generated QML type registration code
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <QtQml/qqml.h>
#include <QtQml/qqmlmoduleregistration.h>

#include <qabstractlistmodel_data.h>


#if !defined(QT_STATIC)
#define Q_QMLTYPE_EXPORT Q_DECL_EXPORT
#else
#define Q_QMLTYPE_EXPORT
#endif
Q_QMLTYPE_EXPORT void qml_register_types_task3_to_do_list()
{
    qmlRegisterTypesAndRevisions<QAbstractListModel_Data>("task3_to_do_list", 1);
    qmlRegisterAnonymousType<QAbstractItemModel, 254>("task3_to_do_list", 1);
    qmlRegisterModule("task3_to_do_list", 1, 0);
}

static const QQmlModuleRegistration registration("task3_to_do_list", qml_register_types_task3_to_do_list);
