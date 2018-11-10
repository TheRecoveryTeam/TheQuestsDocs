import QtQuick 2.11

Text {
    id: cardDescriptionText

    FontLoader {
        id: robotoSlabBold
        source: 'qrc:/media/Exo2-Regular.ttf'
        name: 'Exo2-Regular'
    }

    anchors.fill: parent
    wrapMode: Text.Wrap
    color: 'white'
    horizontalAlignment: Text.AlignHCenter
    verticalAlignment: Text.AlignVCenter
    font {
        family: robotoSlabBold.name
        letterSpacing: 4
    }
    lineHeight: 1.3
}
