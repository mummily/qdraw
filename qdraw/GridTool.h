#pragma once
#include "QSize"
#include "QPainter"

class GridTool
{
public:
    GridTool(const QSize &grid = QSize(3200,2400) , const QSize & space = QSize(20,20) );
    void paintGrid(QPainter *painter,const QRect & rect );
protected:
    QSize m_sizeGrid;
    QSize m_sizeGridSpace;
};

