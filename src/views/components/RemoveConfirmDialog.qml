import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Dialog {
    id: rootDialog
    modal: true
    implicitWidth: 320
    implicitHeight: 160
    contentWidth: implicitWidth
    contentHeight: implicitHeight
    x: Math.round((mainWindow.width - width) / 2 - mainPanel.width)
    y: Math.round((mainWindow.height - height) / 2)

    property int index
    property string headerText
    property string contentText

    background: CardBox {}

    onClosed: {
        mainComponent.state = "NormalState"
    }

    onAccepted: {
        mainComponent.state = "NormalState"

        acrossGroups.removeItem(index)
    }

    onFocusChanged: {
        mainComponent.state = "NormalState"
        rootDialog.reject()
    }

    header: Rectangle {
        Label {
            text: headerText
            color: acrossConfig.textColor
            font.pixelSize: 18
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }

    contentItem: Label {
        text: contentText
        color: acrossConfig.textColor
    }

    footer: RowLayout {
        spacing: acrossConfig.itemSpacing * 2

        Item {
            Layout.fillWidth: true
        }

        ButtonBox {
            text: qsTr("Remove")

            basicState: "WarnState"
            basicColor: acrossConfig.warnColor

            onClicked: {
                rootDialog.accept()
            }
        }

        ButtonBox {
            text: qsTr("Cancel")

            onClicked: {
                rootDialog.reject()
            }
        }

        Item {
            implicitHeight: 32
            Layout.bottomMargin: 32
        }
    }
}