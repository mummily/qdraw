#include "drawscene.h"

DrawScene::DrawScene(QObject *parent)
    : QGraphicsScene(parent)
{
    m_view = nullptr;
    m_grid = new GridTool();
}

DrawScene::~DrawScene()
{
    delete m_grid;
}

void DrawScene::drawBackground(QPainter *painter, const QRectF &rect)
{
    QGraphicsScene::drawBackground(painter,rect);
    painter->fillRect(sceneRect(),Qt::white);
    if( m_grid ){
        m_grid->paintGrid(painter,sceneRect().toRect());
    }
}
