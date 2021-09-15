using System;
using System.Collections.Generic;
using System.Windows.Forms;

namespace CourseProject
{
    // Класс окна сокращения по достижению пенсионного и/или предпенсионного возраста.
    public partial class RetireForm : Form
    {
        // Ссылка на объект класса DataBase, которые создал объект этого класса.
        private DataBase parentDb;
        // Ссылка на DataGridView родительского окна DataBaseForm.
        private DataGridView parentGridView;
        // Список имён "сокращаемых" сотрудников, которые достигли выбранного возраста.
        private List<string> employeeNames;
        // Список ссылок на строки DataGridView сокращаемых сотрудников.
        private List<DataGridViewRow> toRetire;

        // Конструктор класса.
        public RetireForm(DataBase _parentDb, DataGridView _parentGridView)
        {
            parentDb = _parentDb;
            parentGridView = _parentGridView;
            InitializeComponent();
        }

        // Загружаем данные по возрасту, в зависимости от выбранных критериев (с помощью RadioButton).
        private void loadData()
        {
            if (retirementAgeRadioButton.Checked)
                checkEmployees(60);
            else
                checkEmployees(50);
        }

        // Метод, который помещает списки employeeNames и toRetire по очереди всех сотрудников, достигших возраста retireAge.
        private void checkEmployees(int retireAge)
        {
            // Очищаем ListBox.
            employeesList.Items.Clear();
            // Узнаём текущую дату.
            DateTime now = DateTime.Now;
            // Создаём список имён сотрудников и ссылки на строки DataSet с данными сотрудников,
            // достигших указанного возраста.
            employeeNames = new List<string>();
            toRetire = new List<DataGridViewRow>();

            // Устанавливаем максимальную дату рождения,
            // при которой сотрудник считается достигшим указанного возраста retireAge.
            DateTime retirement = new DateTime(now.Year - retireAge, now.Month, now.Day);
            // Обходим все строки DataGridView главного окна.
            foreach (DataGridViewRow row in parentGridView.Rows)
            {
                // Получаем дату рождения текущего сотрудника.
                DateTime emplBirthDate = DateTime.ParseExact(row.Cells[4].Value.ToString(), "dd.mm.yyyy", null);
                // Если дата рождения раньше, чем максимальная дата рождения, то помещаем данные о нём в список.
                if (emplBirthDate <= retirement)
                {
                    // Добавляем ссылку на строку DataGridView, где находятся данные о текущем сотруднике.
                    toRetire.Add(row);
                    // Добавляем в список фамилию, имя и отчество текущего сотрудника.
                    employeeNames.Add(row.Cells[1].Value.ToString() + " " + row.Cells[2].Value.ToString() +
                        " " + row.Cells[3].Value.ToString());
                    // Дабавляем в ListBox текстовые данные о текущем сотруднике в формате:
                    // (фамилия имя отчество (возраст) дожность отдела "отдел".
                    employeesList.Items.Add(row.Cells[1].Value.ToString() + " " + row.Cells[2].Value.ToString() +
                        " " + row.Cells[3].Value.ToString() + " (" + (now.Year - emplBirthDate.Year).ToString() + "), " +
                        " " + row.Cells[12].Value.ToString() + " отдела \"" + row.Cells[11].Value.ToString() + "\"");
                }
            }
        }

        // Метод, который апускает процесс формирования приказа на увольнение.
        private bool retireOrder(List<string> employees)
        {
            Order order = new Order(employees);
            return order.Retire();
        }

        // Событие, вызываемое при инициализации этого окна.
        private void RetireForm_Load(object sender, EventArgs e)
        {
            loadData();
        }

        // События, вызываемое при переключении критерия сокращения (RadioButton).
        private void retirementAgeRadioButton_CheckedChanged(object sender, EventArgs e)
        {
            loadData();
        }
        private void preRetirementAgeRadioButton_CheckedChanged(object sender, EventArgs e)
        {
            loadData();
        }

        // Событие, вызываемое при нажатии на кнопку "Сократить".
        private void btnRetire_Click(object sender, EventArgs e)
        {
            DialogResult answer = MessageBox.Show(
                "Вы уверены что хотите сократить данных сотрудников?", "Подтверждение сокращения",
                MessageBoxButtons.YesNo, MessageBoxIcon.Question);
            if (answer == DialogResult.Yes)
            {
                // Формируем приказ. Если приказ сформирован, то сокращаем.
                if (retireOrder(employeeNames))
                {
                    // Удаляем строки toRetire из DataGridView главного окна.
                    foreach (DataGridViewRow row in toRetire)
                        parentGridView.Rows.Remove(row);
                    // Сохраняем базу данных.
                    parentDb.SaveData();
                    // Закрываем это окно.
                    Close();
                }
            }
        }

        // Событие, вызываемое при нажатии на кнопку "Удалить из списка"
        private void btnRemove_Click(object sender, EventArgs e)
        {
            if (employeesList.SelectedIndex == -1)
                MessageBox.Show("Пожалуйста, выберите сотрудников, которых хотите исключить из списка на сокращение",
                    "Ошибка удаления", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
            else
            {
                // Получаем порядковый номер выбраной строки в ListBox.
                int toRemoveId = employeesList.SelectedIndex;
                // Исключаем имя выбранного сотрудника из ListBox.
                employeesList.Items.RemoveAt(toRemoveId);
                // Удаляем ссылку на строку выбранного сотрудника в DataGridView главного окна.
                toRetire.RemoveAt(toRemoveId);
                // Удаляем имя выбранного сотрудника из списка имён сотрудников.
                employeeNames.RemoveAt(toRemoveId);
            }
        }
    }
}
