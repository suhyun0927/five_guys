using System.Collections.Generic;
using System.Windows;
using System.Windows.Controls;

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
                    Height = 50,
                    FontSize = 18,
                    Margin = new Thickness(0, 0, 0, 15),
                    Tag = value
                };

                btn.Click += (s, e) =>
                {
                    UdpHelper.SendMessage((string)((Button)s).Tag);
                    MessageBox.Show($"{label} 명령이 전송되었습니다.");
                };

                ButtonContainer.Children.Add(btn);
            }
        }
    }
}
