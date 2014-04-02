#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QBuffer>
#include <QCryptographicHash>
#include <QDir>
#include <QFile>
#include <QHttp>
#include <QUrl>
#include <Phonon/MediaObject>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString text = QString::fromUtf8("การ");
    QString voice = "th";

    // Fetch MP3
    http = new QHttp("translate.google.com");
    this->connect(http,SIGNAL(done(bool)),this,SLOT(downloadFinished(bool)));

    QByteArray ContentData;
    ContentData += "ie=UTF-8&q=" + QUrl::toPercentEncoding(text) + "&tl=" + voice;

    QHttpRequestHeader Header;
    Header.addValue("Host", "translate.google.com");

    Header.setContentLength(ContentData.length());
    Header.setRequest("POST", "/translate_tts", 1, 1);

    http->request(Header, ContentData);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::downloadFinished(bool)
{
    QBuffer * buffer = new QBuffer(this);
    QByteArray * array = new QByteArray(http->readAll());
    buffer->setBuffer(array);
    Phonon::MediaObject *mediaObject = Phonon::createPlayer(Phonon::MusicCategory, Phonon::MediaSource(buffer));
    mediaObject->play();
}
