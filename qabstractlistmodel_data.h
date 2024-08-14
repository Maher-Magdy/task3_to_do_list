#ifndef QABSTRACTLISTMODEL_DATA_H
#define QABSTRACTLISTMODEL_DATA_H

#include <QtCore>
#include <QtGui>
#include <QtQml>


class QAbstractListModel_Data : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit QAbstractListModel_Data(QObject *parent = 0);
    ~QAbstractListModel_Data();

public: // QAbstractItemModel interface
    virtual int rowCount(const QModelIndex &parent) const;
    virtual QVariant data(const QModelIndex &index, int role) const;
signals:
    void test(QString message,QList<QString> m_data);
public slots:
     void insert(QString item);
public:
    QList<QString> m_data;
};

#endif // QABSTRACTLISTMODEL_DATA_H
