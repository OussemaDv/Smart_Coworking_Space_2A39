#include "arduino.h"

arduino::arduino()
{

}

int arduino::connect_arduino(){
    foreach(const QSerialPortInfo &serial_port_info, QSerialPortInfo::availablePorts()){
        if(serial_port_info.hasVendorIdentifier() && serial_port_info.hasProductIdentifier()){
            if(serial_port_info.vendorIdentifier() == arduino_uno_vendor_id && serial_port_info.productIdentifier() == arduino_uno_producy_id){
                arduino_is_available=true;
                arduino_port_name=serial_port_info.portName();
            }
        }
    }
    qDebug() << "arduino_port_name_is:" << arduino_port_name;
    if(arduino_is_available){
        serial->setPortName(arduino_port_name);
        if(serial->open(QSerialPort::ReadWrite)){
            serial->setBaudRate(QSerialPort::Baud9600); //debit
            serial->setDataBits(QSerialPort::Data8); //longeur des donnee
            serial->setParity(QSerialPort::NoParity); //1 bits de parite
            serial->setStopBits(QSerialPort::OneStop); //nombre de bits de stop
            serial->setFlowControl(QSerialPort::NoFlowControl);
            return 0;
        }
        return 1;
    }
    return -1;
}

int arduino::close_arduino(){
    if(serial->isOpen()){
        serial->close();
        return 0;
    }
    return 1;
}

QByteArray arduino::read_from_arduino()
{
    if(serial->isReadable()){
        data=serial->readAll(); //rtecuperer les donnee recus
    }
    return data;
}

void arduino::write_to_arduino(QByteArray d)
{
    if(serial->isWritable()){
        serial->write(d);
    }else{
        qDebug() <<"couldnt write to serial";
    }
}

