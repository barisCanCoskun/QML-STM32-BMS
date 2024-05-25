#include "serialmanager.h"

SerialManager::SerialManager(QObject *parent) : QObject(parent)
{
    connect(&m_serialPort, &QSerialPort::readyRead, this, &SerialManager::readData);
}

SerialManager::~SerialManager()
{
    closeSerialPort();
}

void SerialManager::openSerialPort()
{
    m_serialPort.setPortName("/dev/ttyACM0"); // Adjust the port name as per your system
    m_serialPort.setBaudRate(QSerialPort::Baud115200); // Set baud rate
    m_serialPort.setDataBits(QSerialPort::Data8); // Set data bits
    m_serialPort.setParity(QSerialPort::NoParity); // Set parity
    m_serialPort.setStopBits(QSerialPort::OneStop); // Set stop bits

    if (m_serialPort.open(QIODevice::ReadWrite)) {
        m_display = "Connected to Serial Port";
        qInfo() << m_display;
        emit notice(QVariant(m_display));
    } else {
        m_display = "Failed to connect to Serial Port";
        qInfo() << m_display;
        emit notice(QVariant(m_display));
    }
}

void SerialManager::closeSerialPort()
{
    if (m_serialPort.isOpen()){
        m_display = "Disconnected from Serial Port";
        qInfo() << m_display;
        emit notice(QVariant(m_display));
        m_serialPort.close();
    }
}

void SerialManager::writeData(const QByteArray &data)
{
    if (m_serialPort.isOpen()) {
        m_serialPort.write(data);
    } else {
        qInfo() << "Serial port is not open.";
    }
}

void SerialManager::readData()
{
    m_RX_data += m_serialPort.readAll();
    if(m_RX_data.contains("\r\n")){
        qInfo() << "Received data from STM32:" << m_RX_data;
        emit notice(QVariant(m_RX_data));
        m_RX_data.clear();
    }
}











