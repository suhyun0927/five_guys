using System.Collections.Generic;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Navigation;

namespace WpfApp
{
    public partial class EnginePage : Page
    {
        private string _carType;

        public EnginePage(string carType)
        {
            InitializeComponent();
            _carType = carType;

            Loaded += EnginePage_Loaded;
            Unloaded += EnginePage_Unloaded; // 이벤트 해제
        }
        
        private void EnginePage_Loaded(object sender, RoutedEventArgs e)
        {
            TitleTextBlock.Text = $"{_carType}용 엔진 선택";

            var dummyEngineMap = new Dictionary<string, List<string>>
            {
                { "SUV", new List<string> { "GM", "TOYOTA", "WIA" } },
                { "Sedan", new List<string> { "GM", "TOYOTA", "WIA" } },
                { "Truck", new List<string> { "GM", "TOYOTA", "WIA" } }
            };

            var engines = dummyEngineMap.ContainsKey(_carType)
                ? dummyEngineMap[_carType]
                : new List<string>();

            foreach (var engine in engines)
            {
                var button = new Button
                {
                    Content = engine,
                    Height = 50,
                    Margin = new Thickness(0, 0, 0, 15),
                    FontSize = 18
                };

                button.Click += (s, e2) =>
                {
                    NavigationService?.Navigate(new BreakPage(engine));
                };

                EngineButtonContainer.Children.Add(button);
            }

            // 🔹 뒤로 가기 이벤트 추가
            if (NavigationService != null)
            {
                NavigationService.Navigating += NavigationService_Navigating;
            }
        }

        // 🔹 뒤로 가기 이벤트 핸들러
        private void NavigationService_Navigating(object sender, NavigatingCancelEventArgs e)
        {
            if (e.NavigationMode == NavigationMode.Back)
            {
                // 소켓으로 0 전달
            }
        }

        // 🔹 페이지 언로드 시 이벤트 해제
        private void EnginePage_Unloaded(object sender, RoutedEventArgs e)
        {
            if (NavigationService != null)
            {
                NavigationService.Navigating -= NavigationService_Navigating;
            }
        }
    }
}
