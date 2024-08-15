#ifndef QABSTRACTLISTMODEL_DATA_H
#define QABSTRACTLISTMODEL_DATA_H

#include <QtCore>
#include <QtGui>
#include <QtQml>
#include <QByteArray>
#include <QTimer>
#include <QDebug>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <QFile>
#include <QTextStream>

struct QVectorData {
    QVectorData() {}
    QVectorData( QString Name, bool IsChecked )
        : Name(Name), IsChecked(IsChecked) {}
    QString Name;
    bool IsChecked;

};
class QAbstractListModel_Data : public QAbstractListModel
{
    Q_OBJECT
    QML_ELEMENT

public:
    enum Roles {
        NameRole = Qt::UserRole,
        IsCheckedRole
    };

public:
    explicit QAbstractListModel_Data(QObject *parent = 0);
    ~QAbstractListModel_Data();

    //Q_PROPERTY(QAbstractListModel_Data* hold MEMBER mHold CONSTANT ) ;
    virtual int rowCount(const QModelIndex &parent) const;
    virtual QVariant data(const QModelIndex &index, int role) const;
    QHash<int, QByteArray> roleNames() const override;

signals:
    //void test(QString message,QList<QString> m_data);
    //void toDoDataChanged();
public slots:
    void insert(QString item);
    void toggleChecked(int row);
    void remove(int row);
    //void markUnchecked(int row);
public:
    QList<QVectorData> m_data;
};

#endif // QABSTRACTLISTMODEL_DATA_H
