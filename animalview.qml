import QtQuick 2.0

GridView {
    id :grid
    anchors.fill:parent
    cellWidth: 80; cellHeight: 80;
    model: AnimalListModel
    delegate: Item{
        Image{
        source: animalImage; anchors.horizontalCenter: parent.horizontalCenter;
        }
        Text{
        text:animalName
        }
    }


    focus: true
}
