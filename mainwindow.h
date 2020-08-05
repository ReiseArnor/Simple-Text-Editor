#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtWidgets>
#include <memory>

class MainWindow : public QMainWindow
{
public:
    MainWindow(QWidget* parent=0);
    ~MainWindow(){};

public slots:

private:
    std::unique_ptr<QWidget> MainWidget;
    std::unique_ptr<QPlainTextEdit> TextBox;
    std::unique_ptr<QGridLayout> MainLayout;
    
};
  
#endif // MAINWINDOW_H