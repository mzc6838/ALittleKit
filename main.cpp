#include "mainWindow.h"
#include "qtextcodec.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QTextCodec *codec = QTextCodec::codecForName("utf8");
	QTextCodec::setCodecForLocale(codec);

	QApplication a(argc, argv);
	mainTab w;
	w.setWindowTitle("little kit");
	w.show();
	return a.exec();
}
