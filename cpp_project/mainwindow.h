#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextToSpeech>
#include <QVoice>
#include <QProgressDialog>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QUrl>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

QT_BEGIN_NAMESPACE
namespace Ui { class QuoteApp; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::QuoteApp *ui;
    QTextToSpeech m_speech;
    QString proverb;
    QString author;
    QString category;
    QNetworkAccessManager net_manager;

private slots:
    void fetchProverb();
    void sayProverb();
    void response(QNetworkReply *reply);

};
#endif // MAINWINDOW_H
