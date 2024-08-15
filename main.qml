import QtQuick
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Layouts
import QAbstractListModel_Data 1.0
//import task3_to_do_list

Window
{
    //window properties
    id: program_Window
    width: 400
    height: 600
    visible: true
    color : "#333035"
    title: qsTr("To Do List")
    function update_Function()
    {
        list_View.model=test ;
        list_View.model=mydata;
    }
Rectangle
{
    id:gradient_Rectangle
    anchors.fill:parent
    radius:20
    gradient: Gradient
                {
                    GradientStop { position: 0.0; color: "#333333" }
                    GradientStop { position: 0.33; color: "#222222" }
                    GradientStop { position: 1.0; color: "#111111" }
                }
    ColumnLayout
    {
        id:first_Column
        anchors.fill:parent
        anchors.margins: 10
        RowLayout
        {
            id:first_row
            anchors.right:parent.right
            anchors.left:parent.left
            anchors.top:parent.top
            anchors.margins: 20
            //this button is for adding items to to do list view
            RoundButton
            {
                id : add_Button
                objectName: "add_Button"
                width : 80
                height : 25
                radius: 30
                font.pointSize: 15
                //anchors.top: parent.top
                anchors.right: parent.right
                anchors.left:parent.left
                anchors.leftMargin: parent.width/1.35
                text : "add"

                onClicked:
                {
                    //print(mydata.m_data);
                    //emit signal to c++

                    //insert the text into QVector data
                    //mydata.insert(textEdit.text);
                    //


                    //erase text
                    textEdit.text=""

                }

            }

            //input text
            Rectangle
            {
                id : input_Text_Frame
                objectName :"input_Text_Frame"
                width : 80
                height : 35
                radius: 30
                border.color : "white"
                color : program_Window.color
                border.width : 2
                anchors.right: add_Button.left
                anchors.rightMargin: 20
                anchors.left: parent.left
                clip:true
                TextEdit
                {
                    //onDisplayTextChanged : if(text="write your to do item") {text="1";color= "black";}
                    anchors.centerIn: parent
                    //color :"white"
                    color : focus ? "#ffffff" :"#aaaaaa"
                    id: textEdit
                    width: parent.width/1.2
                    height: parent.height/2
                    clip:true
                    font.pointSize: 9
                    property string placeholderText: "Enter text here..."
                    Text
                    {
                           text: textEdit.placeholderText
                           color: "#999"
                           visible: !textEdit.text
                           anchors.centerIn: parent
                    }
                }

            }

        }

        // list view for to do list
        Rectangle
        {
            id : list_View_Frame
            width : 80
            //height : parent.height/1.5
            border.color : "white"
            border.width : 3
            color:program_Window.color
            radius: 10
            anchors.top: first_row.bottom
            anchors.right: parent.right
            anchors.left: parent.left
            anchors.bottom: parent.bottom
            anchors.margins:20

            ListView
            {
                //new property
                //property int clicked_Index: -1
                //the dumbest solution possible
                //ToDoData {id:test}
                id:list_View
                anchors.fill : parent
                anchors.leftMargin: 10
                anchors.topMargin: 10
                clip:true                
                model : ToDoData //list_Model
                {
                    id : mydata
                    /*
                    onToDoDataChanged:
                    {
                        //print("xx");
                        //print(mydata.m_data);
                        update_Function();
                        //add_Button.text=add_Button.text;
                    }
                    */
                }
                delegate : Rectangle
                {
                    //anchors.left:list_View_Frame.right
                    width : 50
                    height : 30
                    color:"#00000000" //make transparent
                    CheckBox
                    {
                        id:check_Box
                        checked:model.ischecked
                        /*
                        onClicked:
                        if (check_Box.checkState===Qt.Checked)
                        {
                            //add_Button.text="test"
                            //check_Box.checked=true
                            {
                                //call remove function to delete from qvector
                                mydata.remove(index);
                                //list_View.clicked_Index=index;
                                //print(list_View.count-1)
                                //call update js function to refresh listView
                                update_Function();
                                //mark the last element as checked
                            }
                        }
                        */

                        MouseArea
                        {
                            anchors.fill: parent
                            //visible: false
                            acceptedButtons: Qt.LeftButton
                            onClicked:
                            {
                                //if (mouse.button === Qt.LeftButton & check_Box.checkState===Qt.Unchecked)
                                //{
                                    //add_Button.text="test"
                                //check_Box.checked=true
                                //if(check_Box.checked===true)
                                //{
                                //    list_View.clicked_Index=index;
                                //}
                                mydata.remove(model.index);
                                //}
                                //else if(mouse.button === Qt.LeftButton &check_Box.checkState===Qt.Checked )
                                //{
                                //    check_Box.checked=false
                                //}
                            }
                        }

                        Text
                        {
                                id:delegate_text
                                anchors.left:parent.right
                                anchors.top:parent.top
                                text: model.name //model.name
                                color: check_Box.checked ?"#888888":"#ffffff"  //"white"
                                //color:(index===list_View.clicked_Index)?"#555555":"#ffffff"
                                font.pixelSize: 15
                        }                        
                    }
                }
            }
        }
    }
}
}
