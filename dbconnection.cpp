#include "dbconnection.h"

DbConnection::DbConnection(QObject *parent)
    : QObject{parent}
{
    qInfo()<<"Obj created";
}
