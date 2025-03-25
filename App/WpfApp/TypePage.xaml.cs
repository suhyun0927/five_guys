using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

using System.Collections.Generic;


namespace WpfApp
{
    public partial class TypePage : Page
    {
        public TypePage()
        {
            InitializeComponent();
            GenerateDummyButtons();
        }

        private void GenerateDummyButtons()
        {
            List<string> carTypes = new List<string> { "SUV", "Sedan", "Truck" };

            foreach (var type in carTypes)
            {
                var button = new Button
                {
                    Content = type,
                    Height = 50,
                    Margin = new Thickness(0, 0, 0, 15),
                    FontSize = 18,
                    Tag = type // 혹시 다음 페이지로 넘길 때 쓸 수 있음
                };

                button.Click += CarTypeButton_Click;
                ButtonContainer.Children.Add(button);
            }
        }

        private void CarTypeButton_Click(object sender, RoutedEventArgs e)
        {
            if (sender is Button btn && btn.Tag is string carType)
            {
                // EnginePage로 carType 넘기면서 이동
                NavigationService?.Navigate(new EnginePage(carType));
            }
        }

    }
}
