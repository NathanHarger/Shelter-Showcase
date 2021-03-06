#include "animallistmodel.h"
#include "modelmanager.h"
#include "mainwindow.h"
#include "animal.h"
#include "apimanager.h"
#include "configuration.h"
#include <QGuiApplication>
#include<QtQml>
#include<QtQuick>
#include <qqmlengine.h>
#include<QtQuick/QQuickItem>
#include <QtQuick/qquickitem.h>
#include <QtQuick/qquickview.h>
#include <QQuickWidget>
#include <iostream>
#include <QTextStream>
using namespace std;

void setupUI(QList<AnimalListModel*> models, Shelter* s);


int main(int argc, char *argv[])
{

    QApplication app(argc, argv);

    // setup configuration
    Configuration c;
   ModelManager* models = new ModelManager(c.getAnimalTypes());
   Shelter* s = new Shelter();
    ApiManager am;


     am.populateAnimalModel(models, c.getShelterID(), c.getDevKey());
     am.populateShelterModel(s, c.getShelterID(), c.getDevKey());
     //qDebug() << s->getEmail();

     setupUI(models->getModels(), s);
     QTextStream out(stderr);

     // following line returns ""
    // qDebug() << s->getName();

    qDebug() << s->getAddress();

    return app.exec();
   }


void setupUI(QList<AnimalListModel*> models, Shelter* s){
   QTabWidget* w = new QTabWidget();

   QQuickWidget* aboutView = new QQuickWidget();
   aboutView->engine()->rootContext()->setContextProperty("shelterModel", s->getQStringList());
  aboutView->setSource(QUrl("qrc:/aboutShelter.qml"));
   w->addTab(aboutView, "Shelter");

    for (int i =0 ; i < models.length(); i++){

        QQuickWidget* view = new QQuickWidget();

        // add list of animals from config to qml animalTypes property
        view->engine()->rootContext()->setContextProperty("animalModel", models.at(i));
        view->engine()->rootContext()->setContextProperty("animal", QStringList());


        view->setSource(QUrl("qrc:/shelterview.qml"));

        w->addTab( view,models.at(i)->getModelName());
    }
    w->show();

}
