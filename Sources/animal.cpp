#include "../Headers/animal.h"
#include <QApplication>
  const QString Animal::animalTypeString[] = {"cat", "dog"};
Animal::Animal(QString name)
{

this->animalName = name;
}


QString Animal::getName() const{
    return this->animalName;
}

QString Animal::getImage() const{

}
