#include "Udp.h"
#include <boost/asio/ip/address.hpp>
#include <iostream>

using boost::asio::ip::udp;

Udp::Udp(unsigned short port)
    : socket(io_context, udp::endpoint(udp::v4(), port))
{
}

std::string Udp::receive() {
    try {
        char buffer[1024];
        size_t len = socket.receive_from(boost::asio::buffer(buffer), lastSenderEndpoint);
        buffer[len] = '\0';
        return std::string(buffer);
    }
    catch (std::exception& e) {
        std::cerr << "UDP 수신 오류: " << e.what() << std::endl;
        return "";
    }
}

void Udp::sendTo(const std::string& message, const std::string& ip, unsigned short port) {
    try {
        udp::endpoint receiver_endpoint(boost::asio::ip::make_address(ip), port);
        socket.send_to(boost::asio::buffer(message), receiver_endpoint);
    }
    catch (std::exception& e) {
        std::cerr << "UDP 전송 오류: " << e.what() << std::endl;
    }
}

void Udp::sendBack(const std::string& message) {
    sendTo(message, getLastSenderIP(), getLastSenderPort());
}

std::string Udp::getLastSenderIP() const {
    return lastSenderEndpoint.address().to_string();
}

unsigned short Udp::getLastSenderPort() const {
    return lastSenderEndpoint.port();
}
