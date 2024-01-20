#include <iostream>
#include <string>

#include "NetworkData.h"

// NetworkData implementation

// destructor
// 1. same name as the class
// 2. preceded by a tilde (~)
// 3. no return type
NetworkData::~NetworkData() {
    if (m_connected) {
        sendData();
        disconnectFromServer();
    }
}

void NetworkData::connectToServer() {
    // connect to server
    m_connected = true;
    std::cout << "Connected to server" << '\n';
}

void NetworkData::disconnectFromServer() {
    // disconnect from server
    m_connected = false;
    std::cout << "Disconnected from server" << '\n';
}

void NetworkData::addData(const std::string& data) {
    if (!m_connected) {
        connectToServer();
    }
    m_data += data;
    std::cout << "Added data to buffer" << '\n';
}

void NetworkData::sendData() {
    // send data to server
    std::cout << "Sending data to server" << '\n';
}

int main() {
    NetworkData networkData{"localhost", 8080};
    networkData.addData("Hello world!");

    return 0;
}
