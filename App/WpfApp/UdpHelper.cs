using System.Net.Sockets;
using System.Text;

public static class UdpHelper
{
    // 1. 재사용 가능한 UDP 클라이언트 인스턴스
    private static UdpClient _sharedClient;

    // 2. 외부에서 접근 가능한 Getter
    public static UdpClient Client
    {
        get
        {
            if (_sharedClient == null)
            {
                _sharedClient = new UdpClient(); // 필요 시 포트 지정 가능
            }
            return _sharedClient;
        }
    }

    // 3. 메시지 전송용 메서드
    public static void SendMessage(string message, string ip = "127.0.0.1", int port = 12345)
    {
        try
        {
            byte[] sendBytes = Encoding.UTF8.GetBytes(message);
            Client.Send(sendBytes, sendBytes.Length, ip, port);
        }
        catch (Exception ex)
        {
            System.Windows.MessageBox.Show($"UDP 전송 오류: {ex.Message}");
        }
    }
}
