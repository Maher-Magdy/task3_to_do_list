#include "qabstractlistmodel_data.h"
//for linker error
//QList<QString> QAbstractListModel_Data::m_data;
//construtor
QAbstractListModel_Data::QAbstractListModel_Data(QObject *parent)
    : QAbstractListModel(parent)
{


    //read from file at startup
    //first check in two locations for the saved to do list . txt file
    //it could be next to source code or next to .exe
    QFile file("saved to do list.txt");
    bool file_found=file.open(QIODevice::ReadOnly);
    if(!file_found)
    {
        file.setFileName("../../saved to do list.txt");
        file.open(QIODevice::ReadOnly);
    }
    //now load data from file
    QTextStream stream(&file);
    while ( !stream.atEnd() )
    {
        QString data;
        QString checked;
        //read lines alternatively where the first line is an item and the second is its checked state
        data= stream.readLine();;
        checked= stream.readLine();;
        // append d to some list;
        QVectorData Qdata(data,checked.toInt());
        m_data.push_back(Qdata);
    }






    // initialize our data (QList<QString>)
    //mHold=new QAbstractListModel_Data;
    //m_data<<QVectorData("",true);
    //m_data.push_back("test");m_data.push_back("test");m_data.push_back("test");
    //for testing
    /*
    QVectorData test0("test0",false);
    QVectorData test1("test1",0);
    QVectorData test2("test2",false);

    m_data.push_back(test1);
    m_data.push_back(test2);
    */
}
//destructor
QAbstractListModel_Data::~QAbstractListModel_Data()
{    
    //write all items to the file at destructor
    const QString qPath("saved to do list.txt");
    QFile file(qPath);
    if (file.open(QIODevice::WriteOnly))
    {
        QTextStream out(&file);
        for(int i=0;i<m_data.size();i++)
        {
            out <<m_data[i].Name<<"\n"<<m_data[i].IsChecked;
            if(i!=m_data.count()-1)
            {out<<"\n";}
        }
        file.close();
    }
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
    const QVectorData &data = m_data.at(index.row());
    if ( role == NameRole ){
        return data.Name;
    }
    else if ( role == IsCheckedRole )
        return data.IsChecked;

    else
        // The view asked for other data, just return an empty QVariant
        return QVariant();

}

QHash<int, QByteArray> QAbstractListModel_Data::roleNames() const
{
    static QHash<int, QByteArray> mapping {
        {NameRole, "name"},
        {IsCheckedRole, "ischecked"},

    };
    return mapping;
}





void QAbstractListModel_Data::toggleChecked(int row)
{
    //check boundaries
    if (row < 0 || row >= m_data.count())
        return;


    beginResetModel();
    //beginRemoveRows(QModelIndex(), row, row);
    //store a copy at the end of the vector
    //QVectorData itemCopy=m_data[row];
    m_data[row].IsChecked=!m_data[row].IsChecked;
    //itemCopy.IsChecked=true;
    //m_data.push_back(itemCopy);
    //remove the vector
    //m_data.removeAt(row);
    //endRemoveRows();
    endResetModel();
}



void QAbstractListModel_Data::remove(int row)
{
    //check boundaries
    if (row < 0 || row >= m_data.count())
        return;


    beginResetModel();
    //beginRemoveRows(QModelIndex(), row, row);
    //store a copy at the end of the vector
    //QVectorData itemCopy=m_data[row];
    //m_data[row].IsChecked=!m_data[row].IsChecked;
    //itemCopy.IsChecked=true;
    //m_data.push_back(itemCopy);
    //remove the vector
    m_data.removeAt(row);
    //endRemoveRows();
    endResetModel();
}


void QAbstractListModel_Data::insert(QString item)
{
    beginResetModel();
    QVectorData newitem(item,false);
    m_data.push_back(newitem);
    endResetModel();

}
/*
 *
 * void QAbstractListModel_Data::markUnchecked(int row)
{
    //check boundaries
    if (row < 0 || row >= m_data.count())
        return;


    beginResetModel();
    //beginRemoveRows(QModelIndex(), row, row);
    //store a copy at the end of the vector
    //QVectorData itemCopy=m_data[row];
    m_data[row].IsChecked=false;
    //itemCopy.IsChecked=true;
    //m_data.push_back(itemCopy);
    //remove the vector
    //m_data.removeAt(row);
    //endRemoveRows();
    endResetModel();
}


   void QAbstractListModel_Data::insert(QString item)
{
    if(item!="")
    {
        QVector myitem(item,true);
        m_data.push_back(myitem);
        emit toDoDataChanged();
        //emit dataChanged(QModelIndex(),QModelIndex());
        //QModelIndex myindex = createIndex(0,0);
        //emit dataChanged(myindex,myindex,{0});
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
*/
