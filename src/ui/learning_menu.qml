import QtCore
import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Controls.Material

import AppModule
Page {
    id: learningPage

    Material.theme : Material.Dark

    ColumnLayout {
        id: menu
        anchors.centerIn: parent

        spacing : 10

        Button {
            text: "Повторить"
            font.pixelSize : 22

            Layout.preferredWidth: 400
            Layout.preferredHeight: 50

            onClicked : {
                load("learning/repeat.qml")
            }
        }
        Button {
            text: "Учить новые слова"
            font.pixelSize : 22

            Layout.preferredWidth: 400
            Layout.preferredHeight: 50

            onClicked : {
                load("learning/new_words.qml")
            }
        }
        Button {
            text: "Помощь"
            font.pixelSize : 22

            Layout.preferredWidth: 400
            Layout.preferredHeight: 50

            onClicked : {
                load("learning/help.qml")
            }
        }
        
        Text {
            id : messageBox

            font.pixelSize : 22
            Layout.preferredWidth: 400
            Layout.preferredHeight: 50

            color: loginPagePalette.text
        }
    }
}