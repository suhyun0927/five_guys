using System.Collections.Generic;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;
using System.Windows.Media.Imaging;

namespace WpfApp
{
    public partial class SteerPage : Page
    {
        public SteerPage()
        {
            InitializeComponent();
            GenerateButtons();
        }

        private void GenerateButtons()
        {
            var steerings = new List<(string label, string value)>
            {
                ("BOSCH", "1"),
                ("MOBIS", "2")
            };

            foreach (var (label, value) in steerings)
            {
                var btn = new Button
                {
                    Height = 120,  // 버튼 높이를 늘려서 이미지와 텍스트가 잘 보이게 함
                    Width = 200,
                    Margin = new Thickness(0, 0, 0, 15),
                    FontSize = 18,
                    Background = Brushes.White,
                    Tag = value,
                    VerticalAlignment = VerticalAlignment.Center, // 버튼 내에서 수직 중앙 정렬
                    HorizontalAlignment = HorizontalAlignment.Center // 버튼 내에서 수평 중앙 정렬
                };

                // 이미지 추가
                Image steeringImage = new Image
                {
                    Source = new BitmapImage(new Uri($"pack://application:,,,/Assets/{label.ToLower()}.png")), // 이미지 경로
                    Width = 50,
                    Height = 50,
                    Margin = new Thickness(5)
                };

                // 텍스트 추가
                TextBlock textBlock = new TextBlock
                {
                    Text = label,
                    VerticalAlignment = VerticalAlignment.Center,
                    FontSize = 18,
                    FontWeight = FontWeights.Bold,
                    TextAlignment = TextAlignment.Center  // 텍스트 가운데 정렬
                };

                // StackPanel을 사용하여 수직 배치
                StackPanel stackPanel = new StackPanel
                {
                    Orientation = Orientation.Vertical,
                    VerticalAlignment = VerticalAlignment.Center, // StackPanel 내에서 수직 중앙 정렬
                    HorizontalAlignment = HorizontalAlignment.Center // StackPanel 내에서 수평 중앙 정렬
                };
                stackPanel.Children.Add(steeringImage);
                stackPanel.Children.Add(textBlock);

                // 버튼에 StackPanel 추가
                btn.Content = stackPanel;

                btn.Click += (s, e) =>
                {
                    UdpHelper.SendMessage((string)((Button)s).Tag);
                    NavigationService?.Navigate(new TestPage()); // ✅ TestPage로 이동
                };

                ButtonContainer.Children.Add(btn);
            }
            // "뒤로가기" 버튼 추가
            var backButton = new Button
            {
                Height = 40,  // 크기 조정
                Width = 100,
                Margin = new Thickness(0, 5, 0, 0), // 상단 여백 추가
                FontSize = 18,
                Background = Brushes.LightGray,
                Content = "뒤로가기",
                VerticalAlignment = VerticalAlignment.Center,
                HorizontalAlignment = HorizontalAlignment.Center
            };

            backButton.Click += (s, e) =>
            {
                UdpHelper.SendMessage("0"); // UDP 메시지 전송
                NavigationService?.GoBack(); // 이전 페이지로 이동
            };

            ButtonContainer.Children.Add(backButton);
        }
    }
}
