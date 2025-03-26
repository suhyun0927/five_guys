#pragma once
#include <string>

class UdpReceiver {
public:
    std::string receive(unsigned short port = 12345);
};
