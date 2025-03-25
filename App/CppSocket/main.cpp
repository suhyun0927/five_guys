#include <iostream>
#include <boost/asio.hpp>

using boost::asio::ip::udp;
using namespace std;

const int PORT = 12345;
const int BUFFER_SIZE = 1024;

class Car {


    int type;
    int steer;
    int engine;


    void test()
    {
    };

};

int main()
{
    try
    {
        // io_service 대신 io_context 객체 생성
        boost::asio::io_context io_context;

        // UDP 소켓 객체 생성
        udp::socket socket(io_context, udp::endpoint(udp::v4(), PORT));
        cout << "UDP 서버 시작, 포트: " << PORT << endl;

        // 클라이언트로부터 데이터 수신
        while (true)
        {
            char buffer[BUFFER_SIZE];
            udp::endpoint client_endpoint;

            // 수신 대기
            size_t len = socket.receive_from(boost::asio::buffer(buffer), client_endpoint);
            buffer[len] = '\0';  // null-terminate the received data
            
            // SUV를 입력 받았을 대
            // return Car::test()


            cout << "수신한 메시지: " << buffer << endl;
        }
    }
    catch (const boost::system::system_error& e)
    {
        cerr << "에러: " << e.what() << endl;
    }

    return 0;
}
