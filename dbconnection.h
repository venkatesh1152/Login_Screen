#ifndef DBCONNECTION_H
#define DBCONNECTION_H

#include <QObject>

class DbConnection : public QObject
{
    Q_OBJECT
public:
    explicit DbConnection(QObject *parent = nullptr);

signals:
};

#endif // DBCONNECTION_H
