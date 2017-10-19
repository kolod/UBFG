#include "fontview.h"

FontView::FontView(QWidget *parent) : QWidget(parent)
{
	scale = 1;
}


void FontView::paintEvent(QPaintEvent * /* event */)
{
	QPainter painter(this);
	painter.fillRect(rect(), Qt::magenta);
	this->setMinimumSize(texture.width()*scale, texture.height()*scale);
	painter.drawPixmap(0, 0, this->width(), this->height(), texture);
}


void FontView::updatePixmap(const QImage &image)
{
	texture = QPixmap::fromImage(image);
	this->setMinimumSize(texture.width(), texture.height());
	update();
}


void FontView::rescale(int index)
{
	if (index < 4) scale = 1 << index;
	this->update();
}
