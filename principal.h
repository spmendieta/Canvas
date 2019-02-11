#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QDebug>
#include <QKeyEvent>
#include <QMainWindow>
#include <QGraphicsView>
#include<QGraphicsSceneMouseEvent>
#include <QGraphicsLineItem>

class Principal : public QGraphicsView
{
    Q_OBJECT

public:
    Principal(QWidget *parent = nullptr);

private:
    bool isFirstTimeDrawing = true;
    qreal lastPosition = 0, newPosition = 0;
    QPointF point;
    QGraphicsLineItem *itemToDraw;
    QString const appTitle = "Canvas - Line Drawer";
    QGraphicsScene *scene;

private:
    void setUpGui();
    void createLine(QMouseEvent *ev);

protected:
   void mousePressEvent(QMouseEvent * event) override;


};

#endif // PRINCIPAL_H
