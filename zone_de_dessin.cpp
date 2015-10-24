#include "zone_de_dessin.h"
#include "ui_zone_de_dessin.h"

Zone_de_dessin::Zone_de_dessin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Zone_de_dessin)
{
    ui->setupUi(this);
}

Zone_de_dessin::~Zone_de_dessin()
{
    delete ui;
}
