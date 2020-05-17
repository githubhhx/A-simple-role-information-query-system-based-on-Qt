#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <iostream>
#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QTreeWidget>
#include <QDebug>
#include <QString>

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QLineEdit *searchLineEdit;


};

#endif // MAINWINDOW_H
