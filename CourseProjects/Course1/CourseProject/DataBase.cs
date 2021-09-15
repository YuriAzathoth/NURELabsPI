using System;
using System.Collections.Generic;
using System.Data;
using System.IO;
using System.Text.RegularExpressions;
using System.Windows.Forms;

namespace CourseProject
{
    // Класс "ядра" базы данных.
    public class DataBase
    {
        // Свойство, которое хранит в себе ссылку на базу данных сотрудников.
        public DataSet Employees { get; set; }

        // Колличество столбцов в базе
        public const int CellsCount = 19;
        // Имя XML-файла, где хранятся все данные базы данных.
        public const string DbFileName = @"\..\..\db.xml";
        // Статическое поле, возвращающее путь, где расположен скомпилированный исполняемый файл этого проекта.
        public static string CurrentDir { get; } = Directory.GetCurrentDirectory().ToString();

        // Ссылка на главное окно базы.
        private DataBaseForm mainWindow;

        // Конструктор класса
        public DataBase()
        {
            // Инициализируем главное окно базы данных.
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            mainWindow = new DataBaseForm(this);
            // Привязываем DataGridView окна к DataSet этого класса.
            mainWindow.SetDataSource(Employees);
            // Запускаем главное окно базы данных.
            Application.Run(mainWindow);
        }

        // Метод, который добавляет новые данные из списка dataList в DataSet.
        public void WriteData(List<string> dataList)
        {
            int iId = 0;
            // Если база данных пустая, то номером добавляемой строки будет 1.
            if (Employees.Tables["Employees"].Rows.Count == 0)
                iId = 1;
            // Иначе находим максимальное значение в столбце "№" и прибавляем к нему еденицу.
            else
            {
                try
                {
                    // Находим максимальное значение порядкового номера - это порядковый номер последней строки.
                    int lastRow = Employees.Tables["Employees"].Rows.Count - 1;
                    iId = Int32.Parse(Employees.Tables["Employees"].Rows[lastRow][0].ToString());
                    iId++;
                }
                catch (Exception) { }
            }
            
            // Создаём новую строку данных и добавляем в неё данные из dataList.
            DataRow newDataRow = Employees.Tables[0].NewRow();
            newDataRow[0] = iId.ToString();
            int i = 1;
            foreach (string data in dataList)
            {
                newDataRow[i] = data;
                i++;
            }

            // Сохраняем дату редактирования данных.
            newDataRow[i] = DateTime.Now.ToShortDateString().Trim();
            // Добавляем только что созданную строку newDataRow в базу DataSet.
            Employees.Tables[0].Rows.Add(newDataRow);

            // Записываем данные в файл.
            SaveData();
        }

        // Метод, который удаляет строки, находящиеся в коллекции rows из DataGridView.
        public void DeleteData(DataGridViewSelectedRowCollection rows)
        {
            // Если коллекция rows пустая, то выходим из функции ничего не удаляя.
            if (rows == null || rows.Count == 0)
                return;
            // Иначе удаляем выбранные строки данных и сохраняем оставшиеся данные в файл.
            foreach (DataGridViewRow row in rows)
                mainWindow.DataGridView.Rows.Remove(row);
            SaveData();
        }

        // Метод, который сохраняем данные из DataSet в XML-файл.
        public void SaveData()
        {
            Employees.WriteXml(CurrentDir + DbFileName, XmlWriteMode.WriteSchema);
        }

        // Метод, который закружает данные из XML-файла.
        public void LoadData()
        {
            // Загружаем данные из XML-файла.
            Employees = new DataSet();
            Employees.ReadXml(CurrentDir + DbFileName, XmlReadMode.Auto);
            // Называем только что созданную таблицу именем "Employees".
            Employees.Tables[0].TableName = "Employees";
            // Привязывает DataSet к DataGridView.
            mainWindow.SetDataSource(Employees);
        }

        // Метод, который проверяет данные на правильность и возвращает true, если всё правильно и false, если что-то неправильно.
        public bool CheckData(DataGridViewCell cell)
        {
            // Проверяем, пустая ли проверяемая ячейка.
            if (cell.Value.ToString() == string.Empty || cell.Value.ToString() == "")
            {
                MessageBox.Show("Поле не должно быть пустым", "Ошибка ввода",
                    MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
                return false;
            }
            // Еслм поле не пустое, начинаем проверку, в зависимости от индекса колонки ячейки.
            switch (cell.ColumnIndex)
            {
                case 1: // Фамилия
                    return CheckByRegex(cell.Value.ToString(), "^[А-Я]{1}[a-я]{2,14}$", "Неверна введено фамилия");
                case 2: // Имя
                    return CheckByRegex(cell.Value.ToString(), "^[А-Я]{1}[a-я]{2,14}$", "Неверно введено имя");
                case 3: // Отчество
                    return CheckByRegex(cell.Value.ToString(), "^[А-Я]{1}[a-я]{2,14}$", "Неверно введено отчество");
                case 4: // Дата рождения
                    return CheckByRegex(cell.Value.ToString(),
                        "^((0[1-9])|([1-2][0-9])|(3[0-1])).((0[1-9])|([1-9])|(1[0-2])).((19((4[8-9])|([5-9][0-9])))|(2000))$",
                        "Неверно введена дата рождения");
                case 7: // Номер дома
                    return CheckByRegex(cell.Value.ToString(), "^[1-9]{1}[0-9]{0,3}[А-Я]{0,1}", "Неверно введено номер дома");
                case 8: // Номер квартиры
                    return CheckByRegex(cell.Value.ToString(), "^[1-9]{1}[0-9]{0,3}", "Неверно введено номер квартиры", false);
                case 9: // Номер паспорта
                    return CheckByRegex(cell.Value.ToString(), "^[А-Яа-я]{2}[0-9]{6}$", "Неверно введено код паспорта");
                case 10: // Дата выдачи паспорта
                    return CheckByRegex(cell.Value.ToString(),
                        "^((0[1-9])|([1-2][0-9])|(3[0-1])).((0[1-9])|([1-9])|(1[0-2]))" +
                        ".((19((6[4-9])|([7-9][0-9])))|(20((0[0-9])|(1[1-8]))))$",
                        "Неверно введена дата выдачи паспорта");
                case 15: // Размер оклада
                    int salary = Convert.ToInt32(cell.Value.ToString());
                    // Проверяем, чтоб размер оклада был в пределе допустимых значений.
                    if (salary < 2000 || salary > 25000)
                    {
                        MessageBox.Show("Неверно введён размер оклада", "Ошибка ввода",
                            MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
                        return false;
                    }
                    break;
                case 16: // Дата принятия на работу
                    return CheckByRegex(cell.Value.ToString(),
                        "^((0[1-9])|([1-2][0-9])|(3[0-1])).((0[1-9])|([1-9])|(1[0-2])).(20((0[0-9])|(1[1-8])))",
                        "Неверно введена дата принятия");
                case 17: // Дата последнего назначения на должность
                    return CheckByRegex(cell.Value.ToString(),
                        "^((0[1-9])|([1-2][0-9])|(3[0-1])).((0[1-9])|([1-9])|(1[0-2])).(20((0[0-9])|(1[1-8])))",
                        "Неверно введена дата последнего назначения");
            }
            return true;
        }

        // Метод, который проверяем строку data по регулярному выражению mask и возвращает true, если проверка удалась, иначе false
        private bool CheckByRegex(string data, string mask, string message, bool checkEmpty = true)
        {
            Regex regex = new Regex(mask);
            if (!regex.Match(data).Success)
            {
                MessageBox.Show(message, "Ошибка ввода", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
                return false;
            }
            return true;
        }
    }
}
