#include "drawview.h"

DrawView::DrawView(QGraphicsScene *scene)
    :QGraphicsView(scene)
{
    m_hruler = new QtRuleBar(Qt::Horizontal,this,this);
    m_vruler = new QtRuleBar(Qt::Vertical,this,this);
    box = new QtCornerBox(this);
    setViewport(new QWidget);

    setAttribute(Qt::WA_DeleteOnClose);
}

DrawView::~DrawView()
{

}

void DrawView::updateRuler()
{
    if ( scene() == 0) return;
    QRectF viewbox = this->rect();
    QPointF offset = mapFromScene(scene()->sceneRect().topLeft());
    double factor =  1./transform().m11();
    double lower_x = factor * ( viewbox.left()  - offset.x() );
    double upper_x = factor * ( viewbox.right() -RULER_SIZE- offset.x()  );
    m_hruler->setRange(lower_x,upper_x,upper_x - lower_x );
    m_hruler->update();

    double lower_y = factor * ( viewbox.top() - offset.y()) * -1;
    double upper_y = factor * ( viewbox.bottom() - RULER_SIZE - offset.y() ) * -1;

    m_vruler->setRange(lower_y,upper_y,upper_y - lower_y );
    m_vruler->update();

}

void DrawView::mouseMoveEvent(QMouseEvent * event)
{
    QPointF pt = mapToScene(event->pos());
    m_hruler->updatePosition(event->pos());
    m_vruler->updatePosition(event->pos());
    emit positionChanged( pt.x() , pt.y() );
    QGraphicsView::mouseMoveEvent(event);
}

void DrawView::resizeEvent(QResizeEvent *event)
{
    QGraphicsView::resizeEvent(event);

    this->setViewportMargins(RULER_SIZE-1,RULER_SIZE-1,0,0);
    m_hruler->resize(this->size().width()- RULER_SIZE - 1,RULER_SIZE);
    m_hruler->move(RULER_SIZE,0);
    m_vruler->resize(RULER_SIZE,this->size().height() - RULER_SIZE - 1);
    m_vruler->move(0,RULER_SIZE);

    box->resize(RULER_SIZE,RULER_SIZE);
    box->move(0,0);
    updateRuler();
}
