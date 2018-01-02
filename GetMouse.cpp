#include "mainWindow.h"

GetMouse::GetMouse(QWidget *parent)
	: QDialog(parent)
{
	_seed = 0;
	clickTime = 10;
	GMWindow = new QGridLayout;

	this->setFixedHeight(300);
	this->setFixedWidth(500);

	this->setWindowTitle("random machine");

	information = new QLabel("<html>" + tr("To create key") + "</html>" 
		+ "<html>" + "<br>" + tr("Please click this Dialog ") + QString::number(clickTime) + tr(" times randomly") + "</html>");

	information->setAlignment(Qt::AlignCenter);
	QFont ft;
	ft.setPointSize(18);
	information->setFont(ft);

	GMWindow->addWidget(information);

	setLayout(GMWindow);
}

void GetMouse::mousePressEvent(QMouseEvent *m)
{
	if (m->button() == Qt::LeftButton && clickTime != 1)
	{
		_seed += m->x();
		_seed += (m->y() * 10);
		clickTime--;
		information->setText("<html>" + tr("To create key") + "</html>" 
			+ "<html>" + "<br>" + tr("Please click this Dialog ") + QString::number(clickTime) + tr(" times randomly") + "</html>");

	}
	else if (clickTime == 1)
	{
		QDialog *notice = new QDialog;
		QPushButton *exitD = new QPushButton("yes");

		notice->setFixedHeight(100);
		notice->setFixedWidth(250);

		QLabel *success = new QLabel("Success!");
		success->setAlignment(Qt::AlignCenter);
		
		QFont ft;
		ft.setPointSize(18);
		success->setFont(ft);

		QGridLayout *successLay = new QGridLayout;
		successLay->addWidget(success, 0, 0);
		successLay->addWidget(exitD, 1, 1);

		connect(exitD, SIGNAL(clicked()), notice, SLOT(accept()));
		connect(exitD, SIGNAL(clicked()), this, SLOT(accept()));

		notice->setLayout(successLay);
		notice->exec();

		this->accept();
	}
}