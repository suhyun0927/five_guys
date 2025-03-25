using System.Net;
using System.Net.Sockets;
using System.Text;

namespace UdpCli
{
    class Program
    {
        static void Main(string[] args)
        {
            UdpClient udpClient = new UdpClient();
            try
            {
                udpClient.Connect("127.0.0.1", 8080);

                // Send
                string sendData = "is anybody there?";
                Byte[] sendBytes = Encoding.ASCII.GetBytes(sendData);
                udpClient.Send(sendBytes, sendBytes.Length);
                Console.WriteLine("Client : " + sendData.ToString());

                //IPEndPoint (allow 모든 IP)
                IPEndPoint RemoteIpEndPoint = new IPEndPoint(IPAddress.Any, 0);

                // Blocks until a message returns on this socket from a remote host.
                Byte[] receiveBytes = udpClient.Receive(ref RemoteIpEndPoint);
                string returnData = Encoding.ASCII.GetString(receiveBytes);
                Console.WriteLine("Server : " + returnData.ToString());

                udpClient.Close();
            }
            catch (Exception e)
            {
                Console.WriteLine(e.ToString());
            }
        }
    }
}