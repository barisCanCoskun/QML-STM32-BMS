import QtQuick
import QtQuick.Controls

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("QML Serial Port Example")

    Connections{
        target: serialManager // our C++ obj on the root context
        onNotice: {
            console.log("Slot called from C++")
            lblStatus.text = data   // get this from the signal
        }
    }

    Column{
        id: column
        width: 200
        height: 268
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: 20

        Label{
            id: lblTitle
            text: qsTr("Connecting to Serial Port")
            color: "red"
            anchors.horizontalCenter: lblStatus.horizontalCenter
        }

        Label{
            id: lblStatus
            text: qsTr("Status")
            font.pointSize: 25
            font.bold: true
            color: "blue"
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Row{
            id: row1
            width: 200
            height: 30
            spacing: 25

            Button{
                id: btnStart
                text: qsTr("Start")

                // Call a slot
                onClicked: serialManager.openSerialPort()
            }

            Button{
                id: btnStop
                text: qsTr("Stop")

                // Call a slot
                onClicked: serialManager.closeSerialPort()
            }
        }

        Row{
            id: row2
            width: 200
            height: 30
            spacing: 25

            Button{
                id: btnSoC
                text: qsTr("SoC")

                // Call a slot
                onClicked: serialManager.writeData("SoC\r")
            }

            Button{
                id: btnSoH
                text: qsTr("SoH")

                // Call a slot
                onClicked: serialManager.writeData("SoH\r")
            }
        }

        Row{
            id: row3
            width: 200
            height: 30
            spacing: 25

            Button{
                id: btnVoltage
                text: qsTr("Voltage")

                // Call a slot
                onClicked: serialManager.writeData("Voltage\r")
            }

            Button{
                id: btnCurrent
                text: qsTr("Current")

                // Call a slot
                onClicked: serialManager.writeData("Current\r")
            }

            Button{
                id: btnTemp
                text: qsTr("Temperature")

                // Call a slot
                onClicked: serialManager.writeData("Temp\r")
            }
        }

    }
}









