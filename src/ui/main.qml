import QtCore
import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Controls.Material 2.12

import AppModule
ApplicationWindow {
    id: root

    visible: true

    width: 600
    height: 1000

    // width: Screen.desktopAvailableWidth
    // height: Screen.desktopAvailableHeight

    Material.accent : Material.DeepPurple
    Material.roundedScale : Material.SmallScale
    Material.primary : Material.Cyan

    palette.highlight : "#9520f5"
    palette.placeholderText : "#7a7a7a"
    palette.text : "white"
    palette.buttonText : "white"
    palette.alternateBase : "#a7d4c9"

    property string state : "create"

    Loader {
        id: viewLoader

        anchors.fill : parent

        source: "qrc:/AppModule/src/ui/start_menu.qml";
    }

    function load(src) {
        viewLoader.source = qsTr("qrc:/AppModule/src/ui/%1").arg(src);
    }

    function setState(state) {
        root.state = state
    }

    Component.onDestruction : {

    }
}