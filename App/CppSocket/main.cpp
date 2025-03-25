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
        // io_service ��� io_context ��ü ����
        boost::asio::io_context io_context;

        // UDP ���� ��ü ����
        udp::socket socket(io_context, udp::endpoint(udp::v4(), PORT));
        cout << "UDP ���� ����, ��Ʈ: " << PORT << endl;

        // Ŭ���̾�Ʈ�κ��� ������ ����
        while (true)
        {
            char buffer[BUFFER_SIZE];
            udp::endpoint client_endpoint;

            // ���� ���
            size_t len = socket.receive_from(boost::asio::buffer(buffer), client_endpoint);
            buffer[len] = '\0';  // null-terminate the received data
            
            // SUV�� �Է� �޾��� ��
            // return Car::test()


            cout << "������ �޽���: " << buffer << endl;
        }
    }
    catch (const boost::system::system_error& e)
    {
        cerr << "����: " << e.what() << endl;
    }

    return 0;
}
