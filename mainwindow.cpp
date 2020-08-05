#include "mainwindow.h"
#include <memory>
using namespace std;

MainWindow::MainWindow(QWidget*parent): QMainWindow(parent)
{
   MainWidget = unique_ptr<QWidget>(new QWidget);
   MainLayout = unique_ptr<QGridLayout>(new QGridLayout);
   TextBox = unique_ptr<QPlainTextEdit>(new QPlainTextEdit);

   setCentralWidget(MainWidget.get());
   setWindowTitle(tr("Text Editor"));

   MainWidget->setLayout(MainLayout.get());

   MainLayout->setSizeConstraint(QLayout::SetMinAndMaxSize);
   MainLayout->addWidget(TextBox.get());

   TextBox->setPlainText(tr("Hola Mundo!"));
}