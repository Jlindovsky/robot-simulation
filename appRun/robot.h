#include <QGraphicsEllipseItem>

class Robot : public QGraphicsEllipseItem{
    private:
    int circumference;
    public:
        Robot();
        void move();
};