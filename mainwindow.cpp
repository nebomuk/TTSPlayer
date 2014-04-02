#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QFile>
#include <QFileInfo>
#include <QSettings>
#include <QStandardItemModel>
#include <QTextStream>
#include <QDir>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this); 

    this->setWindowTitle(qApp->applicationName());

    clipboard = QApplication::clipboard();

    tts.setVoice("zh-CN"); // set text to speech voice to thai

    QSettings settings(qApp->organizationName(),qApp->applicationName());
    this->restoreGeometry(settings.value("geometry",QByteArray()).toByteArray());

    Qt::CheckState checkState = static_cast<Qt::CheckState>(settings.value("checkBox", Qt::Checked).toInt());
    ui->checkBox->setCheckState(checkState);
    this->checkBoxStateChanged(checkState); // the corresponding signal is not automatically called

    this->connect(ui->checkBox,SIGNAL(stateChanged(int)),this,SLOT(checkBoxStateChanged(int)));

    this->connect(ui->playButton,SIGNAL(clicked()),this,SLOT(onPlayButtonClicked()));

    ui->lineEdit->setFocus();
}

/**
 * the text is either directly send to updateView when the clipboard mode is active or send via a signal from
 *  the lineEdit when the clipboard mode is disabled
 **/
void MainWindow::checkBoxStateChanged(int state)
{
    if(state == Qt::Checked)
    {
        connect(clipboard,SIGNAL(changed(QClipboard::Mode)),this,SLOT(clipboardChanged(QClipboard::Mode)));
    }
    else
    {
        disconnect(clipboard,SIGNAL(changed(QClipboard::Mode)),this,SLOT(clipboardChanged(QClipboard::Mode)));
    }
}

/**
 * @brief MainWindow::play
 *
 * selects the selected row's first column's entry and sends a http download reqest to google translate's tts engine
 */
void MainWindow::onPlayButtonClicked()
{
    tts.play(ui->lineEdit->text());
}

void MainWindow::clipboardChanged(QClipboard::Mode mode)
{
    if(mode != QClipboard::Selection)
        return;
    QString text = clipboard->text(QClipboard::Selection).trimmed();
    ui->lineEdit->setText(text);
}

void MainWindow::closeEvent(QCloseEvent *event)
 {
     QSettings settings(qApp->organizationName(),qApp->applicationName());
     settings.setValue("geometry", saveGeometry());
     settings.setValue("checkBox", ui->checkBox->checkState());
     QMainWindow::closeEvent(event);
 }

MainWindow::~MainWindow()
{
    delete ui;
}
