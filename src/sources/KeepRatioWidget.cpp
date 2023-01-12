#include "KeepRatioWidget.h"

KeepRatioWidget::KeepRatioWidget(QWidget *parent)
	: QWidget(parent)
{
}

KeepRatioWidget::~KeepRatioWidget()
{}

void KeepRatioWidget::setRatio(int width, int height)
{
	this->widthRatio = width;
	this->heightRatio = width;
}

void KeepRatioWidget::resizeEvent(QResizeEvent * ev)
{
	QSize old = ev->size();
	QSize now = ev->size();
	QWidget* child = this->findChild<QWidget*>("ResizeChild");
	if (child != nullptr)
	{

		if (now.width() < widthRatio * now.height() / heightRatio) {
			//��Ȳ��㣬���Կ��������
			now.setHeight(heightRatio * now.width() / widthRatio);
			//��ֱ�������
			child->move(0, (old.height() - now.height()) / 2);

		}
		else {
			//�����Ը߶�������
			now.setWidth(widthRatio * now.height() / heightRatio);
			//ˮƽ�������
			child->move((old.width() - now.width()) / 2, 0);

		}

		child->resize(now);
	}
}
