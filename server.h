#ifndef SERVER_H
#define SERVER_H

#include <QDialog>
#include <QString>
#include <QVector>
#include <QDataStream>
#include <QTcpSocket>
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>

QT_BEGIN_NAMESPACE
class QLabel;
class QTcpServer;
class QNetworkSession;
QT_END_NAMESPACE

class Server : public QDialog
{
    Q_OBJECT
public:
    explicit Server(QWidget *parent = nullptr);

private slots:
    void sessionOpened();
    void sendFortune();

private:
    QLabel *statusLabel = nullptr;
    QTcpServer *tcpServer = nullptr;
    QVector<QString> fortunes;
    QNetworkSession *networkSession = nullptr;
    QComboBox *hostCombo = nullptr;
    QLineEdit *portLineEdit = nullptr;
    QPushButton *connectButton = nullptr;
    QTcpSocket *tcpSocket = nullptr;  // Socket pour la connexion du client
    QDataStream in;
    QString currentFortune;
    QTextEdit *messageDisplay;  // Ajout d'un QTextEdit pour afficher les messages
    QLineEdit *sendMessageLineEdit;  // Champ de texte pour envoyer un message
    QPushButton *sendMessageButton;   // Bouton pour envoyer le message
};

#endif // SERVER_H
