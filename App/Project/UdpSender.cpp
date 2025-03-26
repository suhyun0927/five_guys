#include "UdpSender.h"
#include <boost/asio.hpp>
#include <boost/asio/ip/address.hpp>
#include <boost/asio/ip/basic_endpoint.hpp>
#include <boost/asio/ip/udp.hpp>
#include <iostream>

using boost::asio::ip::udp;

void UdpSender::sendTo(const std::string& message, const std::string& ip, unsigned short port) {
    try {
        boost::asio::io_context io_context;
        udp::socket socket(io_context);
        socket.open(udp::v4());

        udp::endpoint receiver_endpoint(boost::asio::ip::make_address(ip), port);
        socket.send_to(boost::asio::buffer(message), receiver_endpoint);
    }
    catch (std::exception& e) {
        std::cerr << "UDP 전송 오류: " << e.what() << std::endl;
    }
}