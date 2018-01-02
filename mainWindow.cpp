#include "mainWindow.h"

mainTab::mainTab(QWidget *parent)
	: QWidget(parent)
{
	tabWidget = new QTabWidget;

	tabWidget->addTab(new Calculator(), tr("calculate")); //������ѡ�
	tabWidget->addTab(new RSATab(), tr("RSA"));           //RSAѡ�

	QGridLayout *mainLayout = new QGridLayout;
	mainLayout->addWidget(tabWidget);
	setLayout(mainLayout);
}
