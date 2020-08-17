#include "mainwindow.h"
#include <memory>
using namespace std;

MainWindow::MainWindow(QWidget*parent): QMainWindow(parent)
{
   MainWidget = unique_ptr<QWidget>(new QWidget);
   MainLayout = unique_ptr<QGridLayout>(new QGridLayout);
   TextBox = unique_ptr<QPlainTextEdit>(new QPlainTextEdit);
   FileName = "untitled";

   setCentralWidget(MainWidget.get());
   setWindowTitle(tr("Text Editor"));
   MainWidget->setLayout(MainLayout.get());
   MainLayout->setSizeConstraint(QLayout::SetMinAndMaxSize);

   CreateActions();
   CreateMenus();
   
   MainLayout->addWidget(TextBox.get());
   TextBox->setPlainText(tr("Hola Mundo!"));
}

void MainWindow::CreateActions()
{
   ActNewFile = unique_ptr<QAction>(new QAction(tr("&New"), this));
   ActNewFile->setStatusTip(tr("Create a new file"));
   connect(ActNewFile.get(), &QAction::triggered, this, &MainWindow::NewFile);

   ActLoadFile = unique_ptr<QAction>(new QAction(tr("&Load"), this));
   ActLoadFile->setStatusTip(tr("Load a file"));
   connect(ActLoadFile.get(), &QAction::triggered, this, &MainWindow::LoadFile);

   ActSaveFile = unique_ptr<QAction>(new QAction(tr("&Save"), this));
   ActSaveFile->setStatusTip(tr("Save file"));
   connect(ActSaveFile.get(), &QAction::triggered, this, &MainWindow::SaveFile);

   ActExit = unique_ptr<QAction>(new QAction(tr("&Exit"), this));
   ActExit->setStatusTip(tr("Exit the program"));
   connect(ActExit.get(), &QAction::triggered, this, &MainWindow::close);
}

void MainWindow::CreateMenus()
{
   MenuFile = unique_ptr<QMenu>(menuBar()->addMenu(tr("&File")));
   MenuFile->addAction(ActNewFile.get());
   MenuFile->addAction(ActLoadFile.get());
   MenuFile->addAction(ActSaveFile.get());
   MenuFile->addAction(ActExit.get());

   //TODO
   //MenuEdit = unique_ptr<QMenu>(menuBar()->addMenu(tr("&Edit")));
   //MenuAbout = unique_ptr<QMenu>(menuBar()->addMenu(tr("&About")));
}

void MainWindow::NewFile()
{
   FileName = "untitled";
   TextBox->setPlainText("");
}

void MainWindow::LoadFile()
{
   FileName = QFileDialog::getOpenFileName(this, "Open the file");
   QFile file(FileName);
   if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
      QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
      return;
   }
   setWindowTitle(FileName);
   QTextStream in(&file);
   TextBox->setPlainText(in.readAll());
   file.close();
}

void MainWindow::SaveFile()
{
   QFile file(FileName);
   if (!file.open(QIODevice::WriteOnly | QFile::Text)) {
      QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
      return;
   }
   setWindowTitle(FileName);
   QTextStream out(&file);
   out << TextBox->toPlainText();
   file.close();
}