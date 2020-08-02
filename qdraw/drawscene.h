#ifndef DRAWSCENE_H
#define DRAWSCENE_H

#include <QGraphicsScene>

class DrawScene : public QGraphicsScene
{
    Q_OBJECT

public:
    DrawScene(QObject *parent);
    ~DrawScene();

    QGraphicsView * view() const { return m_view; }
    void setView(QGraphicsView * val) { m_view = val; }

private:
    QGraphicsView * m_view;
};

#endif // DRAWSCENE_H
