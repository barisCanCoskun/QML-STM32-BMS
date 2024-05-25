#ifndef SERIALMANAGER_H
#define SERIALMANAGER_H

#include <QObject>
#include <QSerialPort>
#include <QVariant>
#include <QDebug>

class SerialManager : public QObject
{
    Q_OBJECT
public:
    explicit SerialManager(QObject *parent = nullptr);
    ~SerialManager();

    // Q_INVOKABLE void connectToSerialPort();

signals:
    void notice(QVariant data);

public slots:
    void openSerialPort();
    void closeSerialPort();
    void writeData(const QByteArray &data);
    void readData();

private:
    QSerialPort m_serialPort;
    QString m_display;
    QByteArray m_RX_data;
};

#endif // SERIALMANAGER_H











