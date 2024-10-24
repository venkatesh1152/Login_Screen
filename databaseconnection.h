#ifndef DATABASECONNECTION_H
#define DATABASECONNECTION_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

class databaseConnection : public QObject
{
    Q_OBJECT
public:
    explicit databaseConnection(QObject *parent = nullptr);

    Q_PROPERTY(QString userName READ userName WRITE setUserName NOTIFY userNameChanged FINAL);
    Q_PROPERTY(QString password READ password WRITE setPassword NOTIFY passwordChanged FINAL);

    Q_INVOKABLE bool login();

    QString userName() const;
    void setUserName(const QString &newUserName);

    QString password() const;
    void setPassword(const QString &newPassword);

signals:

    void userNameChanged();

    void passwordChanged();

private:
    QSqlDatabase db;
    QString m_userName;
    QString m_password;
};

#endif // DATABASECONNECTION_H
