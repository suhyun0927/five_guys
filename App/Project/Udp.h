#pragma once
#include <string>
#include <boost/asio.hpp>

class Udp {
public:
    Udp(unsigned short port = 12345);

    std::string receive(); // 메시지 수신
    void sendTo(const std::string& message, const std::string& ip, unsigned short port);
    void sendBack(const std::string& message);

    std::string getLastSenderIP() const;
    unsigned short getLastSenderPort() const;

private:
    boost::asio::io_context io_context;
    boost::asio::ip::udp::socket socket;
    boost::asio::ip::udp::endpoint lastSenderEndpoint;
};
