#include "mainwindow.h"
#include <QApplication>
#include <QFileDialog>
#include <QSettings>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setOrganizationName("Taiko");
    a.setApplicationName("TTSPlayer");

    if(!QSettings().contains("MediaDirectory"))
    QSettings().setValue("MediaDirectory",QFileDialog::getExistingDirectory (NULL,"Select Pinyin Tone Folder", "Select the folder that contains the pinyin tones"));

    MainWindow w;
    w.show();
    
    return a.exec();
}
