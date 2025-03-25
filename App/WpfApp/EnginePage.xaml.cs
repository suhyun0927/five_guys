﻿using System.Collections.Generic;
using System.Windows;
using System.Windows.Controls;

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
        }

        private void EnginePage_Loaded(object sender, RoutedEventArgs e)
        {
            TitleTextBlock.Text = $"{_carType}용 엔진 선택";

            // 더미 데이터: 차량 타입에 따라 다른 엔진들
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
        }
    }
}
