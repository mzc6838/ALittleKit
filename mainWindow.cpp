#include "mainWindow.h"

mainTab::mainTab(QWidget *parent)
	: QWidget(parent)
{
	tabWidget = new QTabWidget;

	tabWidget->addTab(new Calculator(), tr("calculate")); //计算器选项卡
	tabWidget->addTab(new RSATab(), tr("RSA"));           //RSA选项卡

	QGridLayout *mainLayout = new QGridLayout;
	mainLayout->addWidget(tabWidget);
	setLayout(mainLayout);
}
