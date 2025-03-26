using System.Collections.Generic;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Navigation;

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
                    Content = label,
                    Height = 50,
                    FontSize = 18,
                    Margin = new Thickness(0, 0, 0, 15),
                    Tag = value
                };

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
