#include "principal.h"

Principal::Principal(QWidget *parent)
    : QGraphicsView(parent)
{
    setUpGui();

}

void::Principal::setUpGui(){

    scene = new QGraphicsScene(this);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);

    this->setRenderHint(QPainter::Antialiasing);
    this->setMinimumSize(400,400);
    this->setWindowTitle(appTitle);
    this->setScene(scene);
}

void Principal::mousePressEvent(QMouseEvent *event){

    if(event->button() == Qt::LeftButton){
        createLine(event);
    }

}

void Principal::createLine(QMouseEvent *ev){

    QPointF pointMap = this->mapToScene(ev->pos());

    if(isFirstTimeDrawing){

        lastPosition = pointMap.x();
        newPosition = pointMap.y();

        isFirstTimeDrawing = !isFirstTimeDrawing;

    }else{
        itemToDraw = new QGraphicsLineItem();;
        itemToDraw->setPen(QPen(Qt::blue, 3, Qt::SolidLine));
        itemToDraw->setLine(lastPosition, newPosition, pointMap.x(), pointMap.y());

        scene->addItem(itemToDraw);

        lastPosition = pointMap.x();
        newPosition = pointMap.y();
    }



}
