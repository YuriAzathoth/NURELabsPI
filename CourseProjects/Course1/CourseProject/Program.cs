using System;

namespace CourseProject
{
    static class Program
    {
        [STAThread]
        static void Main()
        {
            // Создаём объект класса ядра базы данных, и автоматически запускаем его
            DataBase dataBase = new DataBase();
        }
    }
}
