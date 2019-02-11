#include "principal.h"
#include <QPainterPath>

Principal::Principal(QWidget *parent)
    : QGraphicsView(parent)
{
    setUpGui();
}

Principal::~Principal()
{
    delete itemToDraw;
}

void::Principal::setUpGui()
{
    isFirstTimeDrawing = true;
    appTitle = "Canvas - Line Drawer";

    scene = new QGraphicsScene(this);

    QRectF rect(QPointF(0, 0), QSize(1024, 768));
    scene->setSceneRect(rect);

    this->setRenderHint(QPainter::Antialiasing);
    this->setWindowTitle(appTitle);
    this->setScene(scene);
}

void Principal::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton){
        QPointF pointMap = this->mapToScene(event->pos());
        createLine(pointMap);
    }

}

void Principal::createLine(QPointF pointMap)
{
    if (isFirstTimeDrawing){
        isFirstTimeDrawing = false;
        itemToDraw = new QGraphicsPathItem;
        itemToDraw->setPen(QPen(Qt::blue, 3, Qt::SolidLine));

        QPainterPath path;
        path.moveTo(pointMap);
        itemToDraw->setPath(path);
        scene->addItem(itemToDraw);
    } else {
        QPainterPath path = itemToDraw->path();
        path.cubicTo(pointMap, pointMap, pointMap);
        itemToDraw->setPath(path);
    }
}
