#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QHttp>
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void downloadFinished(bool);
    
private:
    Ui::MainWindow *ui;
    QHttp * http;
};

#endif // MAINWINDOW_H
