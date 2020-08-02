#ifndef DRAWSCENE_H
#define DRAWSCENE_H

#include <QGraphicsScene>
#include "GridTool.h"

class DrawScene : public QGraphicsScene
{
    Q_OBJECT

public:
    DrawScene(QObject *parent);
    ~DrawScene();

    QGraphicsView * view() const { return m_view; }
    void setView(QGraphicsView * val) { m_view = val; }

protected:
    void drawBackground(QPainter *painter, const QRectF &rect) Q_DECL_OVERRIDE;

private:
    QGraphicsView * m_view;
    GridTool *m_grid;
};

#endif // DRAWSCENE_H
