using System.Collections.Generic;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Navigation;

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
                    Content = label,
                    Height = 50,
                    FontSize = 18,
                    Margin = new Thickness(0, 0, 0, 15),
                    Tag = value
                };

                btn.Click += (s, e) =>
                {
                    UdpHelper.SendMessage((string)((Button)s).Tag);
                    NavigationService?.Navigate(new TestPage()); // ✅ 여기서 TestPage로 이동
                };

                ButtonContainer.Children.Add(btn);
            }
        }
    }
}
