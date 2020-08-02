#include "drawscene.h"

DrawScene::DrawScene(QObject *parent)
    : QGraphicsScene(parent)
{
    m_view = nullptr;
}

DrawScene::~DrawScene()
{

}
