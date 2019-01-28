using System;
using System.Collections.Generic;
using System.IO;
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

namespace MapEditor
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {               
        int currentMapWidth = 0;
        int currentMapHeight = 0;
        int currentGridSize = 0;
        string defaultTilesetPath;
        string defaultTilesetFolderName = "tilesSets";
        string currentTile;
        public List<MyCategory> CategorisedImages { get; set; }

        MyImage _SelectedImage;
        public MyImage SelectedImage
        {
            get
            {
                return _SelectedImage;
            }
            set
            {
                if (_SelectedImage != value)
                {
                    _SelectedImage = value;
                    if (value != null)
                    {
                        currentTile = _SelectedImage.ImagePath;
                    }
                }
            }
        }

        public MainWindow()
        {
            InitializeComponent();
            Init();
            DisplayGrid(0, 0, 0);

            //string[] filePaths = Directory.GetFiles(defaultTilesetPath, "*.png");

            CategorisedImages = new List<MyCategory>
            {
                new MyCategory { CategoryId=0, Name="Default Tileset", Images = new List<MyImage>
                    {
                        new MyImage { ImageId=0, ImagePath= string.Format("{0}/default/blank.png", defaultTilesetPath) },
                        new MyImage { ImageId=1, ImagePath= string.Format("{0}/default/grass.png", defaultTilesetPath) },
                        new MyImage { ImageId=2, ImagePath= string.Format("{0}/default/dirt.png", defaultTilesetPath) },
                        new MyImage { ImageId=3, ImagePath= string.Format("{0}/default/spikes.png", defaultTilesetPath) },
                        new MyImage { ImageId=4, ImagePath= string.Format("{0}/default/cup.png", defaultTilesetPath) },
                        new MyImage { ImageId=5, ImagePath= string.Format("{0}/default/crystal.png", defaultTilesetPath) },
                        new MyImage { ImageId=6, ImagePath= string.Format("{0}/default/spawner.png", defaultTilesetPath) }
                    }
                }
            };

            /*List<MyImage> list = new List<MyImage>();
            for (int i = 0; i < filePaths.Length; i++)
            {
                list.Add(new MyImage { ImageId = (i+1), ImagePath = string.Format("{0}/minecraft/{1}", defaultTilesetPath, filePaths[i]) });
            }
            MyCategory myCategory = new MyCategory();
            myCategory.CategoryId = 2;
            myCategory.Name = "Minecraft Tileset";
            myCategory.Images = list;            
            CategorisedImages.Add(myCategory); */
            DataContext = this;
        }

        void Init()
        {
            defaultTilesetPath = Path.Combine(Path.GetDirectoryName(System.Reflection.Assembly.GetExecutingAssembly().GetName().CodeBase), defaultTilesetFolderName);
        }

        public void SetUpMap(int width, int height, int size)
        {
            mapDisplay.Height = (height * size + height);
            mapDisplay.Width = (width * size + width);
            DisplayGrid(width, height, size);
        }

        private void DisplayGrid(int width, int height, int size)
        {
            currentMapWidth = width;
            currentMapHeight = height;
            currentGridSize = size;
            mapDisplay.Children.Clear();

            int top = 0;
            int left = 0;

            for (int row = 0; row < height; row++)
            {
                for (int col = 0; col < width; col++)
                {
                    System.Windows.Shapes.Rectangle rect = new System.Windows.Shapes.Rectangle();
                    rect.Width = size; rect.Height = size;
                    rect.Fill = Brushes.Gray;

                    Canvas.SetTop(rect, top);
                    Canvas.SetLeft(rect, left);
                    mapDisplay.Children.Add(rect);

                    left += (size + 1);
                }

                left = 0;
                top += (size + 1);
            }
        }

        private void OnMouseLeftButtonDown(object sender, MouseButtonEventArgs e)
        {
            Point pt = e.GetPosition((UIElement)sender);
            HitTestResult result = VisualTreeHelper.HitTest(mapDisplay, pt);

            if (result != null)
            {
                System.Windows.Shapes.Rectangle rect = (System.Windows.Shapes.Rectangle)result.VisualHit;
                rect.Fill = new ImageBrush(new BitmapImage(new Uri(currentTile)));
            }
        }
        private void OnMouseRightButtonDown(object sender, MouseButtonEventArgs e)
        {
            Point pt = e.GetPosition((UIElement)sender);
            HitTestResult result = VisualTreeHelper.HitTest(mapDisplay, pt);

            if (result != null)
            {
                System.Windows.Shapes.Rectangle rect = (System.Windows.Shapes.Rectangle)result.VisualHit;
                rect.Fill = Brushes.Gray;
            }
        }
        #region MenuFile
        private void Menu_NewMap(object sender, RoutedEventArgs e)
        {
            CreatingMapWindow creatingMapWindow = new CreatingMapWindow();
            creatingMapWindow.Owner = this;
            creatingMapWindow.Show();
        }
        private void Menu_Preferences(object sender, RoutedEventArgs e)
        {
            PreferencesWindow preferencesWindow = new PreferencesWindow();
            preferencesWindow.Owner = this;
            preferencesWindow.Show();
        }

        private void Menu_ClearMap(object sender, RoutedEventArgs e)
        {
            DisplayGrid(currentMapWidth, currentMapHeight, currentGridSize);
        }
        private void NewCommand_CanExecute(object sender, CanExecuteRoutedEventArgs e)
        {
            e.CanExecute = true;
        }

        private void NewCommand_Executed(object sender, ExecutedRoutedEventArgs e)
        {
            Menu_NewMap(sender, e);
        }
        private void ClearCommand_CanExecute(object sender, CanExecuteRoutedEventArgs e)
        {
            e.CanExecute = true;
        }

        private void ClearCommand_Executed(object sender, ExecutedRoutedEventArgs e)
        {
            Menu_ClearMap(sender, e);
        }
        #endregion

        public class MyCategory
        {
            public int CategoryId { get; set; }
            public string Name { get; set; }
            public List<MyImage> Images { get; set; }
        }

        public class MyImage
        {
            public int ImageId { get; set; }
            public string ImagePath { get; set; }
        }
    }
}