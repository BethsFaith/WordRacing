import QtCore
import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Controls.Material

import AppModule
Item {
    Material.theme : Material.Dark

    SwipeView {
        id: view

        anchors.fill: parent
        wheelEnabled: true

        currentIndex: tabBar.currentIndex

        Repeater{
            model: pages
            delegate: Loader{
                source: model.page
            }
        }
    }

    ListModel {
        id: pages
        ListElement {
            index: 0
            name: qsTr("Учить");
            page: qsTr("qrc:/AppModule/src/ui/learning_menu.qml")
        }
        ListElement {
            index: 1
            name: qsTr("Словарь");
            page: qsTr("qrc:/AppModule/src/ui/dictionary.qml")
        }
    }

    TabBar {
        id: tabBar

        currentIndex: view.currentIndex

        width: parent.width
        anchors.bottom: view.bottom
        anchors.horizontalCenter: parent.horizontalCenter

        TabButton {
            id: enterButton

            anchors.bottom: parent.bottom

            text: qsTr("Учить")

            Material.background: "#363636"
            palette.buttonText: "#ffffff"
            font.pixelSize : 22
        }
        TabButton {
            id: registrationButton

            anchors.bottom: parent.bottom

            text: qsTr("Словарь")

            Material.background: "#363636"
            palette.buttonText: "#ffffff"
            font.pixelSize : 22
        }
    }
}