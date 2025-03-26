#pragma once
#include <string>

class UdpSender {
public:
    void sendTo(const std::string& message, const std::string& ip, unsigned short port);
};
