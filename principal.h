#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QDebug>
#include <QMouseEvent>
#include <QGraphicsView>
#include <QGraphicsPathItem>

class Principal : public QGraphicsView
{
    Q_OBJECT

public:
    Principal(QWidget *parent = nullptr);
    ~Principal();


protected:
    void mousePressEvent(QMouseEvent * event) override;

private:
    void setUpGui();
    void createLine(QPointF point);

    bool isFirstTimeDrawing;
    QGraphicsPathItem *itemToDraw;
    QString appTitle;
    QGraphicsScene *scene;
    QPainterPath path;
};

#endif // PRINCIPAL_H
