#include "qabstractlistmodel_data.h"
//for linker error
//QList<QString> QAbstractListModel_Data::m_data;
//construtor
QAbstractListModel_Data::QAbstractListModel_Data(QObject *parent)
    : QAbstractListModel(parent)
{
    // initialize our data (QList<QString>)
    //m_data.push_back("test");m_data.push_back("test");m_data.push_back("test");

}
//destructor
QAbstractListModel_Data::~QAbstractListModel_Data()
{
}

int QAbstractListModel_Data::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    // return our data count
    return m_data.count();
}

QVariant QAbstractListModel_Data::data(const QModelIndex &index, int role) const
{

    // the index returns the requested row and column information.
    // we ignore the column and only use the row information
    int row = index.row();

    // boundary check for the row
    if(row < 0 || row >= m_data.count()) {
        return QVariant();
    }

    // A model can return data for different roles.
    // The default role is the display role.
    // it can be accesses in QML with "model.display"
    switch(role) {
    case Qt::DisplayRole:
        // Return the color name for the particular row
        // Qt automatically converts it to the QVariant type
        return m_data.value(row);
    }

    // The view asked for other data, just return an empty QVariant
    return QVariant();
}
   void QAbstractListModel_Data::insert(QString item)
{
    if(item!="")
    {
        m_data.push_back(item);
        //emit dataChanged(QModelIndex(),QModelIndex());
        emit toDoDataChanged();
        //test(item,m_data);
    }


}
void QAbstractListModel_Data::remove(int item_index)
{
    //make sure index is not out of range
    if(item_index<m_data.size())
    {
        //save a copy from the data in a string
        QString saved_copy=m_data[item_index];
        //remove the item from the data vector/list
        m_data.remove(item_index);
        //push the completed item to the end of the stack
        m_data.push_back(saved_copy);

    }



}
