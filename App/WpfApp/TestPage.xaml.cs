using System.Collections.Generic;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media.Animation;
using System.Windows.Media;
using System.Reflection.Emit;
using System.Windows.Threading;
using System.Windows.Media.Imaging;
using System.Text;

namespace WpfApp
{
    public partial class TestPage : Page
    {
        public TestPage()
        {
            InitializeComponent();
            GenerateButtons();
        }

        private void GenerateButtons()
        {
            var actions = new List<(string label, string value)>
            {
                ("RUN", "1"),
                ("TEST", "2")
            };

            foreach (var (label, value) in actions)
            {
                var btn = new Button
                {
                    Content = label,
                    Height = 120,  // 버튼 높이를 늘려서 이미지와 텍스트가 잘 보이게 함
                    Width = 200,
                    FontSize = 18,
                    FontWeight = FontWeights.Bold,
                    Background = Brushes.White,
                    Margin = new Thickness(0, 0, 0, 15),
                    Tag = value
                };

                btn.Click += async (s, e) =>
                {
                    UdpHelper.SendMessage((string)((Button)s).Tag);

                    int euckrCodePage = 51949;
                    Encoding.RegisterProvider(CodePagesEncodingProvider.Instance); // 등록 (1회만)
                    Encoding euckr = Encoding.GetEncoding(euckrCodePage);

                    // 2. 서버 응답 수신
                    var client = UdpHelper.Client; // 공유 UdpClient
                    var result = await client.ReceiveAsync();
                    string response = euckr.GetString(result.Buffer);
                    //MessageBox.Show(response);

                    // 3. 응답 파싱 및 출력
                    var parts = response.Split('|');

                    var passOrFail = parts[0];
                    var message = parts[1];

                    if (passOrFail == "pass")
                    {
                        RunSuccessAnimation(message);
                    }
                    else if(passOrFail == "fail")
                    {
                        RunFailureAnimation(message);
                    }
                    else
                    {
                        RunSuccessAnimation(message);

                    }
                    //if (value == "1") RunSuccessAnimation();     // RUN
                    //else if (value == "2") RunFailureAnimation(); // TEST

                };

                ButtonContainer.Children.Add(btn);
            }
            // "처음화면" 버튼 추가
            var backButton = new Button
            {
                Height = 40,  // 크기 조정
                Width = 100,
                Margin = new Thickness(0, 5, 0, 0), // 상단 여백 추가
                FontSize = 18,
                Background = Brushes.LightGray,
                Content = "처음화면",
                VerticalAlignment = VerticalAlignment.Center,
                HorizontalAlignment = HorizontalAlignment.Center
            };

            backButton.Click += (s, e) =>
            {
                UdpHelper.SendMessage("0"); // UDP 메시지 전송
                NavigationService?.Navigate(new TypePage()); // TypePage로 이동
            };

            ButtonContainer.Children.Add(backButton);
        }


        private void RunSuccessAnimation(string message)
        {

            Dispatcher.InvokeAsync(() =>
            {
                // 1. 이미지 교체
                CarImage.Source = new BitmapImage(new Uri("pack://application:,,,/Assets/car.png"));

                // 2. 애니메이션 설정
                double toX = AnimationCanvas.ActualWidth - CarImage.Width - 20;

                var animation = new DoubleAnimation
                {
                    From = 0,
                    To = toX,
                    Duration = TimeSpan.FromSeconds(2),
                    EasingFunction = new CubicEase { EasingMode = EasingMode.EaseInOut }
                };

                // 3. 애니메이션 완료 후 메시지박스
                animation.Completed += (s, e) =>
                {
                    MessageBox.Show(message);
                };
                CarTransform.BeginAnimation(TranslateTransform.XProperty, animation);
                
            }, DispatcherPriority.Loaded);
        }


        private void RunFailureAnimation(string message)
        {


            Dispatcher.InvokeAsync(() =>
            {
                CarImage.Source = new BitmapImage(new Uri("pack://application:,,,/Assets/car.png"));
                double middleX = (AnimationCanvas.ActualWidth - CarImage.Width) / 2;

                var animation = new DoubleAnimation
                {
                    From = 0,
                    To = middleX,
                    Duration = TimeSpan.FromSeconds(1.5),
                    EasingFunction = new CubicEase { EasingMode = EasingMode.EaseOut }
                };

                // 애니메이션 완료 시 이미지 교체
                animation.Completed += (s, e) =>
                {
                    CarImage.Source = new BitmapImage(new Uri("pack://application:,,,/Assets/broken_car.png"));
                    MessageBox.Show(message);
                };

                CarTransform.BeginAnimation(TranslateTransform.XProperty, animation);
            }, DispatcherPriority.Loaded);
        }

    }
}
