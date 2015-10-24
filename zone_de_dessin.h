#ifndef ZONE_DE_DESSIN_H
#define ZONE_DE_DESSIN_H

#include <QWidget>

namespace Ui {
class Zone_de_dessin;
}

class Zone_de_dessin : public QWidget
{
    Q_OBJECT

public:
    explicit Zone_de_dessin(QWidget *parent = 0);
    ~Zone_de_dessin();

private:
    Ui::Zone_de_dessin *ui;
};

#endif // ZONE_DE_DESSIN_H
