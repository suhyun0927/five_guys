using System.Collections.Generic;
using System.Windows;
using System.Windows.Controls;

namespace WpfApp
{
    public partial class SteerPage : Page
    {
        private string _brake;

        public SteerPage(string brake)
        {
            InitializeComponent();
            _brake = brake;

            Loaded += SteerPage_Loaded;
        }

        private void SteerPage_Loaded(object sender, RoutedEventArgs e)
        {
            TitleTextBlock.Text = $"{_brake} 브레이크 선택됨 — 스티어링 선택";

            List<string> steerOptions = new List<string> { "Bosch", "HYUNDAI" };

            foreach (var steer in steerOptions)
            {
                var button = new Button
                {
                    Content = steer,
                    Height = 50,
                    Margin = new Thickness(0, 0, 0, 15),
                    FontSize = 18
                };

                button.Click += (s, e2) =>
                {
                    MessageBox.Show($"{steer} 스티어링 선택됨");
                    // TODO: 결과 페이지로 이동 가능
                };

                SteeringButtonContainer.Children.Add(button);
            }
        }
    }
}
