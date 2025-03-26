using System;
using System.Net.Sockets;
using System.Text;

public static class UdpHelper
{
    public static void SendMessage(string message, string ip = "127.0.0.1", int port = 12345)
    {
        using (UdpClient udpClient = new UdpClient())
        {
            try
            {
                byte[] sendBytes = Encoding.UTF8.GetBytes(message);
                udpClient.Send(sendBytes, sendBytes.Length, ip, port);
            }
            catch (Exception ex)
            {
                System.Windows.MessageBox.Show($"UDP 전송 오류: {ex.Message}");
            }
        }
    }
}
