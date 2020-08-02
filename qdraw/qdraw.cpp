#include "qdraw.h"
#include "drawscene.h"
#include "drawview.h"

qdraw::qdraw(QWidget *parent)
    : QMainWindow(parent)
{
    initUI();
}

qdraw::~qdraw()
{

}

void qdraw::initUI()
{
    DrawScene *scene = new DrawScene(this);
    QRectF rc = QRectF(0 , 0 , 800, 600);
    scene->setSceneRect(rc);

    DrawView *view = new DrawView(scene);
    scene->setView(view);

    view->setRenderHint(QPainter::Antialiasing);
    view->setCacheMode(QGraphicsView::CacheBackground);
    view->setOptimizationFlags(QGraphicsView::DontSavePainterState);
    view->setViewportUpdateMode(QGraphicsView::SmartViewportUpdate);
    //view->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    view->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);

    // move orign point to leftbottom
    view->setTransform(view->transform().scale(1,-1));

    scene->setBackgroundBrush(Qt::darkGray);

    this->setCentralWidget(view);
    view->showMaximized();
}
