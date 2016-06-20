#include "animallistmodel.h"
#include "modelmanager.h"
#include "mainwindow.h"
#include "animal.h"
#include "configuration.h"
#include <QGuiApplication>
#include<QtQml>
#include<QtQuick>
#include <qqmlengine.h>
#include<QtQuick/QQuickItem>
#include <QtQuick/qquickitem.h>
#include <QtQuick/qquickview.h>
#include <QQuickWidget>

void setupUI(QList<AnimalListModel*> models);


int main(int argc, char *argv[])
{

    QApplication app(argc, argv);

    // setup configuration
    Configuration c;


   ModelManager* models = new ModelManager(c.getAnimalTypes());


   models->addAnimal( Animal("Cheese Pizza"),"cat");
   models->addAnimal( Animal("C1"),"cat");
   models->addAnimal( Animal("3"),"cat");
   models->addAnimal( Animal("C4za"),"cat");

    setupUI(models->getModels());


    return app.exec();
   }
http://doc.qt.io/qt-5/qqmlcomponent.html
void setupUI(QList<AnimalListModel*> models){
   QTabWidget* w = new QTabWidget();

    for (int i =0 ; i < models.length(); i++){
        //QQuickView view;
        QQuickView* view = new QQuickView();
		QQmlEngine *engine = new QQmlEngine;
		QQmlComponent component(engine, QUrl("qrc:/animalview.qml")
		
		QObject *myObject = component.create();
		QQuickItem *item = qobject_cast<QQickItem*>(myObject);

        view->engine()->rootContext()->setContextProperty("animalModel", models.at(i));

        view->setSource(QUrl("qrc:/animalview.qml"));
        // add list of animals from config to qml animalTypes property


        w->addTab( view,models.at(i)->getModelName());

        //w->show();
       //view->show();

    }
    w->show();

}
