import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

Rectangle{
    id : loginscreen

    anchors{
        fill: parent
    }

    RowLayout{
        id: loginLayout
        anchors{
            fill: parent
        }
        spacing: 0
        //Rectangle for login image
        Rectangle{
            id : loginImageArea

            Layout.fillHeight: true
            Layout.preferredWidth: loginscreen.width * 0.5
            Image {
                id: loginImage
                source: "qrc:/LoginApplication/Image/znebccin.png"
                anchors{
                    fill: parent
                }
            }
        }

        // Rectangle for login area
        Rectangle{
            id : loginArea

            Layout.fillHeight: true
            Layout.preferredWidth: loginscreen.width * 0.5

            //login column Layout
            ColumnLayout {
                implicitHeight: loginTitle.implicitHeight + userArea.implicitHeight + spacing
                implicitWidth : loginArea.width * 0.75
                spacing: 20
                anchors{
                    centerIn: parent
                }

                // Title text
                Text {
                    id: loginTitle
                    text: qsTr("My Diary")
                    font{
                        pixelSize: 24
                        bold: true
                    }
                }

                //User area
                Rectangle{
                    id: userArea

                    implicitHeight: loginArea.height * 0.05
                    implicitWidth:  parent.width

                    Text {
                        id: userText
                        text: qsTr("User Name")
                        font{
                            pixelSize: 18
                            bold: true
                        }
                        anchors{
                            verticalCenter: parent.verticalCenter
                        }
                    }
                    TextField{
                        id: userTextField

                        implicitHeight: parent.implicitHeight
                        implicitWidth:  parent.implicitWidth * 0.75
                        anchors{
                            right: parent.right
                        }
                        onTextChanged: {
                            database.userName = text
                        }
                    }
                }
                //Password area
                Rectangle{
                    id: passwordArea

                    implicitHeight: loginArea.height * 0.05
                    implicitWidth:  parent.width

                    Text {
                        id: passwordText
                        text: qsTr("Password")
                        font{
                            pixelSize: 18
                            bold: true
                        }
                        anchors{
                            verticalCenter: parent.verticalCenter
                        }
                    }
                    TextField{
                        id: passwordTextField

                        implicitHeight: parent.implicitHeight
                        implicitWidth:  parent.implicitWidth * 0.75
                        anchors{
                            right: parent.right
                        }
                        onTextChanged: {
                            database.password = text
                        }
                    }
                }

                Button{
                    id : loginbutton

                    implicitHeight: loginArea.height * 0.05
                    implicitWidth:  parent.width * 0.35
                    text: "Login"
                    anchors{
                        horizontalCenter: parent.horizontalCenter
                    }
                    background: Rectangle{
                        color: "#c3d92f"
                        radius: 2
                        border.width: 0
                    }
                    onClicked: {
                        if(database.login){
                            console.log("Valide")
                        } else {
                            console.log("Not valid")
                        }
                    }
                }
            }
        }
    }



}
