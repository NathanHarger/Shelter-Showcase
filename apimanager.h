#ifndef APIMANAGER_H
#define APIMANAGER_H
#include <QApplication>
#include <animallistmodel.h>

class ApiManager
{
public:
    ApiManager();
    static void MakeApiCall();
    static AnimalListModel GetAnimals(QString shelterId, AnimalListModel::AnimalType animalType);
};

#endif // APIMANAGER_H
