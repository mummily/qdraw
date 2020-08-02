#ifndef DRAWVIEW_H
#define DRAWVIEW_H

#include <QGraphicsView>
#include "rulebar.h"

class DrawView : public QGraphicsView
{
    Q_OBJECT

public:
    DrawView(QGraphicsScene *scene);
    ~DrawView();

    void mouseMoveEvent(QMouseEvent * event) Q_DECL_OVERRIDE;
    void resizeEvent(QResizeEvent *event) Q_DECL_OVERRIDE;

signals:
    void positionChanged(int x , int y );
protected:
    void updateRuler();
    QtRuleBar *m_hruler;
    QtRuleBar *m_vruler;
    QtCornerBox * box;

private:
};

#endif // DRAWVIEW_H
