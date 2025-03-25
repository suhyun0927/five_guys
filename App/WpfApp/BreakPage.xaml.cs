using System.Collections.Generic;
using System.Windows;
using System.Windows.Controls;

namespace WpfApp
{
    public partial class BreakPage : Page
    {
        private string _engine;

        public BreakPage(string engine)
        {
            InitializeComponent();
            _engine = engine;

            Loaded += BreakPage_Loaded;
        }

        private void BreakPage_Loaded(object sender, RoutedEventArgs e)
        {
            TitleTextBlock.Text = $"{_engine}용 브레이크 선택";

            // 더미 데이터: 엔진에 따른 브레이크 옵션
            var dummyBreakMap = new Dictionary<string, List<string>>
            {
                { "엔진 A", new List<string> { "MANDO", "Bosch", "Continental" } },
                { "엔진 B", new List<string> { "Brembo", "Bosch" } },
                { "엔진 C", new List<string> { "Hyundai Brake", "MANDO" } }
                // ... 추가 가능
            };

            var breaks = dummyBreakMap.ContainsKey(_engine)
                ? dummyBreakMap[_engine]
                : new List<string> { "MANDO", "Continental", "Bosch" }; // fallback

            foreach (var brake in breaks)
            {
                var button = new Button
                {
                    Content = brake,
                    Height = 50,
                    Margin = new Thickness(0, 0, 0, 15),
                    FontSize = 18
                };

                button.Click += (s, e2) =>
                {
                    NavigationService?.Navigate(new SteerPage(brake));
                };

                BreakButtonContainer.Children.Add(button);
            }
        }
    }
}
