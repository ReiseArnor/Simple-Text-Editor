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
   // file menu actions
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

   // edit menu actions
   ActCut = unique_ptr<QAction>(new QAction(tr("&Cut"), this));
   ActCut->setStatusTip(tr("Cut the selected text"));
   connect(ActCut.get(), &QAction::triggered, this, &MainWindow::Cut);

   ActCopy = unique_ptr<QAction>(new QAction(tr("&Copy"), this));
   ActCopy->setStatusTip(tr("Copy the selected text"));
   connect(ActCopy.get(), &QAction::triggered, this, &MainWindow::Copy);

   ActPaste = unique_ptr<QAction>(new QAction(tr("&Paste"), this));
   ActPaste->setStatusTip(tr("Paste the text"));
   connect(ActPaste.get(), &QAction::triggered, this, &MainWindow::Paste);

   ActUndo = unique_ptr<QAction>(new QAction(tr("&Undo"), this));
   ActUndo->setStatusTip(tr("Undo action"));
   connect(ActUndo.get(), &QAction::triggered, this, &MainWindow::Undo);

   ActRedo = unique_ptr<QAction>(new QAction(tr("&Redo"), this));
   ActRedo->setStatusTip(tr("Redo action"));
   connect(ActRedo.get(), &QAction::triggered, this, &MainWindow::Redo);

   ActSelectAll = unique_ptr<QAction>(new QAction(tr("&Select all"), this));
   ActSelectAll->setStatusTip(tr("Select all the text"));
   connect(ActSelectAll.get(), &QAction::triggered, this, &MainWindow::SelectAll);
}

void MainWindow::CreateMenus()
{
   MenuFile = unique_ptr<QMenu>(menuBar()->addMenu(tr("&File")));
   MenuFile->addAction(ActNewFile.get());
   MenuFile->addAction(ActLoadFile.get());
   MenuFile->addAction(ActSaveFile.get());
   MenuFile->addAction(ActExit.get());

   MenuEdit = unique_ptr<QMenu>(menuBar()->addMenu(tr("&Edit")));
   MenuEdit->addAction(ActCut.get());
   MenuEdit->addAction(ActCopy.get());
   MenuEdit->addAction(ActPaste.get());
   MenuEdit->addAction(ActUndo.get());
   MenuEdit->addAction(ActRedo.get());
   MenuEdit->addAction(ActSelectAll.get());

   //TODO
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

void MainWindow::Copy()
{
   TextBox->copy();
}

void MainWindow::Cut()
{
   TextBox->cut();
}

void MainWindow::Paste()
{
   TextBox->paste();
}

void MainWindow::Undo()
{
   TextBox->undo();
}

void MainWindow::Redo()
{
   TextBox->redo();
}

void MainWindow::SelectAll()
{
   TextBox->selectAll();
}