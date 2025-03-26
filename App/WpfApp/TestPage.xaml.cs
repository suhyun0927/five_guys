using System.Collections.Generic;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media.Animation;
using System.Windows.Media;
using System.Reflection.Emit;
using System.Windows.Threading;
using System.Windows.Media.Imaging;

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
                    Margin = new Thickness(0, 0, 0, 15),
                    Tag = value
                };

                btn.Click += (s, e) =>
                {
                    UdpHelper.SendMessage((string)((Button)s).Tag);
                    MessageBox.Show($"{label} 명령이 전송되었습니다.");
                    
                    if (value == "1") RunSuccessAnimation();     // RUN
                    else if (value == "2") RunFailureAnimation(); // TEST
                    
                };

                ButtonContainer.Children.Add(btn);
            }
        }


        private void RunSuccessAnimation()
        {

            Dispatcher.InvokeAsync(() =>
            {
                // 1. 이미지 교체
                CarImage.Source = new BitmapImage(new Uri("pack://application:,,,/Assets/car.jpg"));

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
                    MessageBox.Show("자동차가 동작됩니다.");
                };
                CarTransform.BeginAnimation(TranslateTransform.XProperty, animation);
                
            }, DispatcherPriority.Loaded);
        }


        private void RunFailureAnimation()
        {


            Dispatcher.InvokeAsync(() =>
            {
                CarImage.Source = new BitmapImage(new Uri("pack://application:,,,/Assets/car.jpg"));
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
                    MessageBox.Show("엔진이 고장났습니다. 자동차가 움직이지 않습니다.");
                };

                CarTransform.BeginAnimation(TranslateTransform.XProperty, animation);
            }, DispatcherPriority.Loaded);
        }

    }
}
