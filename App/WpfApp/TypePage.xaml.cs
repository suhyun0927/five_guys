using System.Collections.Generic;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Navigation;

namespace WpfApp
{
    public partial class TypePage : Page
    {
        public TypePage()
        {
            InitializeComponent();
            GenerateButtons();
        }

        private void GenerateButtons()
        {
            var carTypes = new List<(string label, string value)>
            {
                ("Sedan", "1"),
                ("SUV", "2"),
                ("Truck", "3")
            };

            foreach (var (label, value) in carTypes)
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
                    NavigationService?.Navigate(new EnginePage());
                };

                ButtonContainer.Children.Add(btn);
            }
        }
    }
}
