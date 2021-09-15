using System;
using System.Collections.Generic;
using System.IO;
using System.Windows.Forms;

namespace CourseProject
{
    // Класс, формирующий приказы.
    public class Order
    {
        // Список имён сотрудников.
        private List<string> subjects;
        // Вспомогательный список, который хранит, например, причину, основание и т.д.
        private List<string> data;

        // Основной конструктор класса.
        public Order(List<string> names)
        {
            subjects = names;
            // Создаём вспомогательный список, и заполняем его четырьмя нулевыми объектами.
            data = new List<string>(4);
            for (int i = 0; i < 4; i++)
                data.Add(string.Empty);
        }

        // Конструктор класса для формирования приказа "о принятии на работу".
        public Order(List<string> names, string position, string department)
        {
            subjects = names;
            data = new List<string>(2);
            for (int i = 0; i < 4; i++)
                data.Add(string.Empty);
            data.Add(position);
            data.Add(department);
        }

        // Конструктор класса для формирования настраеваемого приказа.
        public Order(ListBox.ObjectCollection names, string action, string description, string reason, string cause)
        {
            // Создаём список имён сотрудников и заполняем его именами из names.
            subjects = new List<string>(names.Count);
            foreach (string name in names)
                subjects.Add(name);

            // Создаём вспомогательный класс и заполняем его уточняющими данными.
            data = new List<string>(4);
            data.Add(action);
            data.Add(description);
            data.Add(reason);
            data.Add(cause);
        }

        // Статический метод, который возвращает последний номер приказа из файла LastOrder.txt + 1.
        // Если bOverride = true, то позволяет методу перезаписывать значение в файле новым значением.
        public static string GetOrgerNum(bool bOverride = false)
        {
            StreamReader reader = new StreamReader(DataBase.CurrentDir + @"\..\..\LastOrder.txt");
            string num = reader.ReadLine();
            reader.Close();
            if (bOverride)
            {
                StreamWriter writer = new StreamWriter(DataBase.CurrentDir + @"\..\..\LastOrder.txt");
                int iNum = Convert.ToInt32(num);
                writer.WriteLine(iNum + 1);
                writer.Close();
            }
            return num;
        }

        // Метод, который формирует приказ о принятии на работу.
        public bool Employ()
        {
            return make(Action.Employ);
        }

        // Метод, который формирует приказ об увольнении.
        public bool Dismiss()
        {
            return make(Action.Dismiss);
        }

        // Метод, который формирует приказ о сокращении.
        public bool Retire()
        {
            return make(Action.Retire);
        }

        // Метод, который формирует настраеваемый приказ.
        public void MakeCustom()
        {
            SaveFileDialog saveToDlg = new SaveFileDialog();
            saveToDlg.Filter = "Файлы txt|*.txt";
            if (saveToDlg.ShowDialog() == DialogResult.OK)
            {
                StreamWriter writer = new StreamWriter(saveToDlg.FileName);
                makeOrder(writer);
                writer.Close();
            }
            else
                MessageBox.Show("Не выбрано место сохранения файла приказа.", "Файл не выбран",
                    MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
        }

        // Перечислитель встроенных типов приказов.
        private enum Action
        {
            Employ,
            Dismiss,
            Retire
        }

        // Метод, который записывает текст приказа в файл.
        private void makeOrder(StreamWriter writer)
        {
            writer.WriteLine("\t\tОбщество с ограниченной ответственностью \"Новый Софт\"");
            writer.WriteLine();
            writer.WriteLine();
            writer.WriteLine("\t\t\t\t\tПРИКАЗ");
            writer.WriteLine();
            writer.WriteLine();
            writer.WriteLine("\t\t\t\t\t№ " + GetOrgerNum(true) + "");
            writer.WriteLine();
            writer.WriteLine();
            writer.WriteLine("\t\t\t\tот " + DateTime.Now.ToShortDateString() + " г. Харькова");
            writer.WriteLine();
            writer.WriteLine();
            writer.WriteLine(data[0] + ":");
            writer.WriteLine();
            writer.WriteLine();
            
            int i = 0;
            foreach (string name in subjects)
            {
                string id = (i + 1).ToString();
                writer.WriteLine(id + ". " + subjects[i] + " " + data[1] + ", с " +
                    DateTime.Now.ToShortDateString() + " " + data[2]);
                writer.WriteLine();
                i++;
            }

            writer.WriteLine();
            writer.WriteLine();
            writer.WriteLine("Основание: " + data[3] + ".");
            writer.WriteLine();
            writer.WriteLine();
            writer.WriteLine("Директор __________ С. В. Малышко.");
            writer.WriteLine();
            writer.WriteLine();

            foreach (string name in subjects)
            {
                writer.WriteLine("С приказом ознакомлен: " + DateTime.Now.ToShortDateString() + " ________ " + name);
                writer.WriteLine();
                writer.WriteLine();
            }
        }

        // Метод, который формирует один из трёх встроенных приказов в зависимости от значения action.
        private bool make(Action action)
        {
            SaveFileDialog saveToDlg = new SaveFileDialog();
            saveToDlg.Filter = "Файлы txt|*.txt";
            if (saveToDlg.ShowDialog() == DialogResult.OK)
            {
                if (action == Action.Employ)
                    data[0] = "Принять на работу";
                else
                    data[0] = "Уволить";

                if (action == Action.Employ)
                {
                    data[1] = "на должность " + data[4] + " в отдел " + data[5];
                    data[2] = "по его собственному заявлению";
                    data[3] = "заключение договора о приёме на работу с компанией";
                }
                else
                {
                    if (action == Action.Retire)
                    {
                        data[2] = "по пенсионному возрасту";
                        data[3] = "достижение пенсионного возраста";
                    }
                    else
                    {
                        data[2] = "по собственному желанию";
                        data[3] = "заявление об увольнении по собственному желанию";
                    }
                }

                StreamWriter writer = new StreamWriter(saveToDlg.FileName);
                makeOrder(writer);
                writer.Close();
                return true;
            }
            else
            {
                DialogResult answer = MessageBox.Show("Приказ не сохранён\n" +
                    "\"Да\" - заново выбрать, куда сохранить приказ\n" +
                    "\"Нет\" - продолжить без сохранения\n" +
                    "\"Отмена\" - вернуться к редактированию данных",
                    "Ошибка сохранения приказа", MessageBoxButtons.YesNoCancel, MessageBoxIcon.Exclamation);
                switch (answer)
                {
                    case DialogResult.Yes:
                        make(action);
                        break;
                    case DialogResult.No:
                        return true;
                    default:
                        return false;
                }
            }
            return false;
        }
    }
}
