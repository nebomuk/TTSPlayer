#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QClipboard>
#include "tts.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
protected:
    void closeEvent(QCloseEvent *event);
private slots:
    void clipboardChanged(QClipboard::Mode mode);
    void checkBoxStateChanged(int state);
    void onPlayButtonClicked();

private:
    TTS tts;
    Ui::MainWindow *ui;
    QClipboard *clipboard;

};

#endif // MAINWINDOW_H
