using System.Collections.Generic;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;
using System.Windows.Media.Imaging;

namespace WpfApp
{
    public partial class EnginePage : Page
    {
        public EnginePage()
        {
            InitializeComponent();
            GenerateButtons();
        }

        private void GenerateButtons()
        {
            var engines = new List<(string label, string value)>
            {
                ("GM", "1"),
                ("TOYOTA", "2"),
                ("WIA", "3"),
                ("BROKEN", "4")
            };

            foreach (var (label, value) in engines)
            {
                var btn = new Button
                {
                    Height = 120, // 버튼 높이를 늘려서 이미지와 텍스트가 잘 보이게 함
                    Width = 200,
                    Margin = new Thickness(0, 0, 0, 15),
                    FontSize = 18,
                    Background = Brushes.White,
                    Tag = value,
                    VerticalAlignment = VerticalAlignment.Center, // 버튼 내에서 수직 중앙 정렬
                    HorizontalAlignment = HorizontalAlignment.Center // 버튼 내에서 수평 중앙 정렬
                };

                // 이미지 추가
                Image engineImage = new Image
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
                stackPanel.Children.Add(engineImage);
                stackPanel.Children.Add(textBlock);

                // 버튼에 StackPanel 추가
                btn.Content = stackPanel;

                btn.Click += (s, e) =>
                {
                    UdpHelper.SendMessage((string)((Button)s).Tag);
                    NavigationService?.Navigate(new BrakePage());
                };

                ButtonContainer.Children.Add(btn);
            }
        }
    }
}
