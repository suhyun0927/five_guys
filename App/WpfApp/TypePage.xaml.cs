using System;
using System.Collections.Generic;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Navigation;

namespace WpfApp
{
    public partial class TypePage : Page
    {
        private const string UDP_IP = "127.0.0.1"; // C++ 서버의 IP 주소
        private const int UDP_PORT = 12345; // C++ 서버에서 수신할 포트 번호

        public TypePage()
        {
            InitializeComponent();
            GenerateDummyButtons();
        }

        private void GenerateDummyButtons()
        {
            List<string> carTypes = new List<string> { "SUV", "Sedan", "Truck" };

            foreach (var type in carTypes)
            {
                var button = new Button
                {
                    Content = type,
                    Height = 50,
                    Margin = new Thickness(0, 0, 0, 15),
                    FontSize = 18,
                    Tag = type // 다음 페이지로 넘길 때 사용
                };

                button.Click += CarTypeButton_Click;
                ButtonContainer.Children.Add(button);
            }
        }

        private void CarTypeButton_Click(object sender, RoutedEventArgs e)
        {
            if (sender is Button btn && btn.Tag is string carType)
            {
                SendUdpMessage(carType); // UDP 메시지 전송
                NavigationService?.Navigate(new EnginePage(carType));
            }
        }

        private void SendUdpMessage(string message)
        {
            using (UdpClient udpClient = new UdpClient())
            {
                try
                {
                    byte[] sendBytes = Encoding.UTF8.GetBytes(message);
                    udpClient.Send(sendBytes, sendBytes.Length, UDP_IP, UDP_PORT);
                }
                catch (Exception ex)
                {
                    MessageBox.Show($"UDP 전송 오류: {ex.Message}");
                }
            }
        }
    }
}
