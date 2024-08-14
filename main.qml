import QtQuick
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Layouts
import task3_to_do_list
import ORG.Data 1.0
Window
{
    //window properties
    id: program_Window
    width: 400
    height: 600
    visible: true
    color : "#444060"
    title: qsTr("To Do List")
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
            anchors.margins: 20
            //this button is for adding items to to do list view
            RoundButton
            {
                id : add_Button
                objectName: "add_Button"
                text : "add"
                width : 80
                height : 25
                radius: 30
                font.pointSize: 15
                //anchors.top: parent.top
                anchors.right: parent.right
                anchors.left:parent.left
                anchors.leftMargin: parent.width/1.35
                //anchors.left:parent.left
                //anchors.leftMargin: parent.width/1.35
                //anchors.rightMargin: parent.width/18
                //anchors.topMargin: parent.height/60
                //when button is pressed delete everything then update on release
                //onPressed: update_Elements()

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
                //anchors.top: parent.top
                anchors.right: add_Button.left
                anchors.rightMargin: 20
                anchors.left: parent.left
                //anchors.rightMargin: parent.width/18
                //anchors.leftMargin: parent.width/18
                //anchors.topMargin: parent.height/60
                clip:true
                TextEdit
                {
                    //onDisplayTextChanged : if(text="write your to do item") {text="1";color= "black";}
                    anchors.centerIn: parent
                    color :"white"
                    id: textEdit
                    width: parent.width/1.2
                    height: parent.height/2
                    clip:true
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
            //anchors.rightMargin: parent.width/18
            //anchors.leftMargin: parent.width/18
            //anchors.topMargin: parent.height/8
            //anchors.bottomMargin: parent.height/8
            ListView
            {
                ListModel
                {
                    //for testing
                    id : list_Model
                    ListElement{name:"test"}
                    ListElement{name:"test"}
                    ListElement{name:"test_______________________________________"}
                    ListElement{name:"test"}
                }
                anchors.fill : parent
                anchors.leftMargin: 10
                anchors.topMargin: 10
                clip:true
                model : QAbstractListModel_Data {}
                delegate : Rectangle
                {
                    //anchors.left:list_View_Frame.right
                    width : 50
                    height : 30
                    color:"#00000000" //make transparent
                    CheckBox
                    {
                        id:check_Box

                        Text {
                                anchors.left:parent.right
                                anchors.top:parent.top
                                text: model.name
                                color: "white"
                                font.pixelSize: 16
                            }
                        //this can be used as html
                        //text :"<font color=\"white\">"+model.name+"</font>"

                    }

                }
            }
        }
    }


}
