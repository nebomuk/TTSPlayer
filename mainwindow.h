#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QClipboard>
#include <QFile>
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
    Phonon::MediaObject *mediaObject;
    Phonon::AudioOutput *audioOutput;
    TTS tts;
    Ui::MainWindow *ui;
    QClipboard *clipboard;
    QFile * file;
};

#endif // MAINWINDOW_H
