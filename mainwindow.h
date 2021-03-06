#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtWidgets>
#include <memory>
#include <vector>

class MainWindow : public QMainWindow
{
public:
    MainWindow(QWidget* parent=0);
    ~MainWindow(){};

public slots:
    void NewFile();
    void LoadFile();
    void SaveFile();
    void SaveFileAs();
    void Copy();
    void Cut();
    void Paste();
    void Undo();
    void Redo();
    void SelectAll();
    void About();

private:
    void CreateActions();
    void CreateMenus();
    QString FileName;

    std::unique_ptr<QWidget> MainWidget;
    std::unique_ptr<QPlainTextEdit> TextBox;
    std::unique_ptr<QGridLayout> MainLayout;
    std::unique_ptr<QMenu> MenuFile;
    std::unique_ptr<QMenu> MenuEdit;
    std::unique_ptr<QMenu> MenuAbout;

    std::unique_ptr<QAction> ActNewFile;
    std::unique_ptr<QAction> ActLoadFile;
    std::unique_ptr<QAction> ActSaveFile;
    std::unique_ptr<QAction> ActSaveFileAs;
    std::unique_ptr<QAction> ActExit;
    std::unique_ptr<QAction> ActCopy;
    std::unique_ptr<QAction> ActCut;
    std::unique_ptr<QAction> ActPaste;
    std::unique_ptr<QAction> ActUndo;
    std::unique_ptr<QAction> ActRedo;
    std::unique_ptr<QAction> ActSelectAll;
    std::unique_ptr<QAction> ActAbout;
};

#endif // MAINWINDOW_H
