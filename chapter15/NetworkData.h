#ifndef NETWORKDATA_H
#define NETWORKDATA_H

#include <iostream>
#include <string>
#include <string_view>

class NetworkData {
   private:
    std::string m_serverName{};
    int m_port{};
    bool m_connected{};
    std::string m_data{};

   public:
    NetworkData(std::string_view serverName, int port)
        : m_serverName(serverName), m_port(port) {}

    ~NetworkData();

    void connectToServer();

    void disconnectFromServer();

    void addData(const std::string& data);

    void sendData();
};

#endif  // NETWORKDATA_H
