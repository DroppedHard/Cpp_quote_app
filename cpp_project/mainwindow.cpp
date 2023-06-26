#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

using namespace std;

const char *fetchUrl = "https://api.api-ninjas.com/v1/quotes";

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::QuoteApp)
    , m_speech(new QTextToSpeech(nullptr))
    , net_manager(new QNetworkAccessManager(nullptr))
{
    ui->setupUi(this);
    connect(ui->fetchProverb, &QPushButton::pressed, this, &MainWindow::fetchProverb);
    connect(ui->sayProverb, &QPushButton::pressed, this, &MainWindow::sayProverb);
    connect(&this->net_manager, &QNetworkAccessManager::finished, this, &MainWindow::response);

    proverb = "Please fetch proverb.";
    author = "";
    int idx = 156;  //152 - whisper
    QVoice it = m_speech.availableVoices()[idx];
    m_speech.setVoice(m_speech.availableVoices()[idx]);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::fetchProverb()
{// no api key for you :)
    QNetworkRequest *req = new QNetworkRequest(QUrl(fetchUrl));
    req->setRawHeader("X-Api-Key", "not this time :)");
    net_manager.get(*req);

//    cout << "get run" << endl;
}

void MainWindow::sayProverb()
{
    m_speech.say(proverb + ". Quote by" + author);
}

void MainWindow::response(QNetworkReply *reply)
{
    if (reply->error()) {
        qDebug() << reply->errorString();
        return;
    }

    QJsonDocument jsonResponse = QJsonDocument::fromJson(reply->readAll());
    QJsonObject jsonObject = jsonResponse.array().first().toObject();

    proverb = jsonObject.take("quote").toString();
    author = jsonObject.take("author").toString();
    category = jsonObject.take("category").toString();

    ui->proverbField->setText(proverb);
    ui->additionalField->setText("~ "+author+"\nQuote category: "+category);

//    qDebug() << jsonObject;
}
