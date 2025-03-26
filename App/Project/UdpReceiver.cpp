#include "UdpReceiver.h"
#include <boost/asio.hpp>
#include <iostream>

using boost::asio::ip::udp;

std::string UdpReceiver::receive(unsigned short port) {
    try {
        boost::asio::io_context io_context;
        udp::socket socket(io_context, udp::endpoint(udp::v4(), port));

        char buffer[1024];
        udp::endpoint sender_endpoint;
        //std::cout << "[UDP 대기 중] 포트 " << port << "..." << std::endl;

        size_t len = socket.receive_from(boost::asio::buffer(buffer), sender_endpoint);
        buffer[len] = '\0';
        return std::string(buffer);
    }
    catch (std::exception& e) {
        //std::cerr << "UDP 수신 오류: " << e.what() << std::endl;
        return "";
    }
}
