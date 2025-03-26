using System.Collections.Generic;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Navigation;

namespace WpfApp
{
    public partial class BrakePage : Page
    {
        public BrakePage()
        {
            InitializeComponent();
            GenerateButtons();
        }

        private void GenerateButtons()
        {
            var brakes = new List<(string label, string value)>
            {
                ("MANDO", "1"),
                ("CONTINENTAL", "2"),
                ("BOSCH", "3")
            };

            foreach (var (label, value) in brakes)
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
                    NavigationService?.Navigate(new SteerPage());
                };

                ButtonContainer.Children.Add(btn);
            }
        }
    }
}
