#ifndef QABSTRACTLISTMODEL_DATA_H
#define QABSTRACTLISTMODEL_DATA_H

#include <QtCore>
#include <QtGui>
#include <QtQml>


class QAbstractListModel_Data : public QAbstractListModel
{
    Q_OBJECT
    QML_ELEMENT
public:
    explicit QAbstractListModel_Data(QObject *parent = 0);
    ~QAbstractListModel_Data();

    //Q_PROPERTY(QAbstractListModel_Data* hold MEMBER mHold CONSTANT ) ;
    virtual int rowCount(const QModelIndex &parent) const;
    virtual QVariant data(const QModelIndex &index, int role) const;

signals:
    void test(QString message,QList<QString> m_data);
    void toDoDataChanged();
public slots:
    void insert(QString item);
    void remove(int item_index);
public:
    QList<QString> m_data;
};

#endif // QABSTRACTLISTMODEL_DATA_H
