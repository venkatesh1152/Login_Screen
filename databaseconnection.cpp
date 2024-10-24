#include "databaseconnection.h"

databaseConnection::databaseConnection(QObject *parent)
    : QObject{parent}
{
    qInfo()<<" Object is created";
    qInfo()<<"Drivers :"<<QSqlDatabase::drivers();
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("mydatabase");
    db.setUserName("root");
    db.setPassword("root");
    if(!db.open()){
        qInfo()<< "Db connection fail";
    } else {
        qInfo()<< "Db connection success";
    }
}

bool databaseConnection::login()
{

}

QString databaseConnection::userName() const
{
    return m_userName;
}

void databaseConnection::setUserName(const QString &newUserName)
{
    if (m_userName == newUserName)
        return;
    m_userName = newUserName;
    emit userNameChanged();
}

QString databaseConnection::password() const
{
    return m_password;
}

void databaseConnection::setPassword(const QString &newPassword)
{
    if (m_password == newPassword)
        return;
    m_password = newPassword;
    emit passwordChanged();
}
