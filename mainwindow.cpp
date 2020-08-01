#include "mainwindow.h"

MainWindow::MainWindow(QWidget*parent): QMainWindow(parent)
{
   MainWidget = new QWidget();
   MainLayout = new QGridLayout();
   TextBox = new QPlainTextEdit();

   setCentralWidget(MainWidget);
   setWindowTitle(tr("Text Editor"));

   MainWidget->setLayout(MainLayout);

   MainLayout->setSizeConstraint(QLayout::SetMinAndMaxSize);
   MainLayout->addWidget(TextBox);

   TextBox->setPlainText(tr("Hola Mundo!"));
}

MainWindow::~MainWindow()
{
    delete MainWidget;
    delete MainLayout;
    delete TextBox;
}