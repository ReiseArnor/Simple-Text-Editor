#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtWidgets>

class MainWindow : public QMainWindow
{
public:
    MainWindow(QWidget* parent=0);
    ~MainWindow();

public slots:

private:
    QWidget* MainWidget = nullptr;
    QPlainTextEdit* TextBox = nullptr;
    QGridLayout* MainLayout = nullptr;
};
  
#endif // MAINWINDOW_H