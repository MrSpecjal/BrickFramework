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
using System.Windows.Shapes;

namespace MapEditor
{
    /// <summary>
    /// Interaction logic for CreatingMapWindow.xaml
    /// </summary>
    public partial class CreatingMapWindow : Window
    {
        int width;
        int height;
        int gridSize;

        public CreatingMapWindow()
        {
            InitializeComponent();
        }

        private void Create(object sender, RoutedEventArgs e)
        {
            width = int.Parse(mapWidth.Text);
            height = int.Parse(mapHeight.Text);
            gridSize = int.Parse(mapGridSize.Text);
            ((MainWindow)this.Owner).SetUpMap(width, height, gridSize);
            this.Close();
        }
    }
}
