#ifndef QDRAW_H
#define QDRAW_H

#include <QtWidgets/QMainWindow>

class qdraw : public QMainWindow
{
    Q_OBJECT

public:
    qdraw(QWidget *parent = 0);
    ~qdraw();

private:
    void initUI();
};

#endif // QDRAW_H
