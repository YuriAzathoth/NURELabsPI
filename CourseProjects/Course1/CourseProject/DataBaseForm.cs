using System;
using System.Collections.Generic;
using System.Data;
using System.Windows.Forms;

namespace CourseProject
{
    // Класс главного окна базы данных.
    public partial class DataBaseForm : Form
    {
        // Свойство, возвращающее ссылку на DataGridView этого окна.
        public DataGridView DataGridView { get { return dataGridView; } }

        // Ссыла на объект класса DataBase, который создал объект класса DataBaseForm.
        private DataBase parentDb;
        // Словарь индекс_колонки - имя_колонки (не отображаемое название, а кодовое имя).
        private Dictionary<int, string> indexToColumn;

        // Конструктор класса.
        public DataBaseForm(DataBase _parentDb)
        {
            parentDb = _parentDb;
            initDictionary();
            InitializeComponent();
        }

        public void SetDataSource(DataSet _dataSource)
        {
            // Привязываем базу данных к таблице.
            bindingSource.DataSource = _dataSource;
            bindingSource.DataMember = "Employees";
            // Отключаем автоматическую генерацию столбцов по DataSet (мы их создаём вручную и вручную привязываем).
            dataGridView.AutoGenerateColumns = false;
            dataGridView.DataSource = bindingSource;

            // Привязываем к колонкам таблицы соответствующие значения из базы данных.
            for (int i = 0; i < DataBase.CellsCount; i++)
                dataGridView.Columns[i].DataPropertyName = indexToColumn[i];
        }

        // Метод, применяющий фильтрацию (или "поиск") к DataGridView.
        private void setFilter()
        {
            // Если Фильтр="(отключен)", обнуляем фильтрацию (показываем все строки).
            if (filterColumnCombo.SelectedIndex == 0)
                bindingSource.Filter = "";
            // Иначе применяем фильтрацию в формате имя_колонки LIKE '%фрагмент_текста%'.
            else
            bindingSource.Filter = string.Format("{0} LIKE '%{1}%'",
                indexToColumn[filterColumnCombo.SelectedIndex], filterText.Text);
        }

        // Метод, инициализирующий словарь индекс_столбца-имя_столбца.
        private void initDictionary()
        {
            indexToColumn = new Dictionary<int, string>();
            indexToColumn.Add(0, "id");
            indexToColumn.Add(1, "surname");
            indexToColumn.Add(2, "name");
            indexToColumn.Add(3, "fathername");
            indexToColumn.Add(4, "birthdate");
            indexToColumn.Add(5, "birthplace");
            indexToColumn.Add(6, "address");
            indexToColumn.Add(7, "house");
            indexToColumn.Add(8, "apartment");
            indexToColumn.Add(9, "passportnum");
            indexToColumn.Add(10, "issuedate");
            indexToColumn.Add(11, "department");
            indexToColumn.Add(12, "position");
            indexToColumn.Add(13, "speciality");
            indexToColumn.Add(14, "education");
            indexToColumn.Add(15, "salary");
            indexToColumn.Add(16, "employment");
            indexToColumn.Add(17, "appointment");
            indexToColumn.Add(18, "editdate");
        }

        // Событие, вызываемое при загрузки этого окна.
        private void DataBaseForm_Load(object sender, EventArgs e)
        {
            // Настраиваем DataGridView.
            dataGridView.AllowUserToAddRows = false;
            dataGridView.AllowUserToDeleteRows = false;
            parentDb.LoadData();
            // Выбираем тип фильтра как "(отключен)".
            filterColumnCombo.SelectedIndex = 0;
        }

        // Событие, вызываемое при нажатии на кнопку "Добавить".
        private void btnAdd_Click(object sender, EventArgs e)
        {
            // Запускаем окно добавления данных.
            InsertDataForm wndInsertData = new InsertDataForm(parentDb);
            wndInsertData.Show();
        }

        // Событие, вызываемое при нажатии на кнопку "Уволить".
        private void btnDelete_Click(object sender, EventArgs e)
        {
            // Сохраняем массив выделенных строк и ячеек в память.
            DataGridViewSelectedRowCollection selectedRows = dataGridView.SelectedRows;
            DataGridViewSelectedCellCollection selectedCells = dataGridView.SelectedCells;
            // Если выбраны строки, то начинаем "процедуру увольнения".
            if (selectedRows.Count != 0)
            {
                DialogResult answer = MessageBox.Show("Уволить этих сотрудников?",
                    "Подтверждение увольнения", MessageBoxButtons.YesNo, MessageBoxIcon.Warning);
                if (answer == DialogResult.Yes)
                {
                    // Сохраняем имена увольняемых сотрудников в список names.
                    List<string> names = new List<string>();
                    foreach (DataGridViewRow row in dataGridView.SelectedRows)
                        names.Add(row.Cells[1].Value.ToString() + " " + row.Cells[2].Value.ToString() + " " +
                            row.Cells[3].Value.ToString());
                    // Формируем приказ на увольнение.
                    Order order = new Order(names);
                    if (order.Dismiss())
                        parentDb.DeleteData(dataGridView.SelectedRows);
                }
            }
            // Если ничего не выбрано, то ничего не трогаем.
            else
                MessageBox.Show("Выберите строки или ячейки для удаления", "Нечего удалять",
                    MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
        }

        // Событие, вызываемое при завершении редактирования ячейки DataGridView.
        private void dataGridView_CellEndEdit(object sender, DataGridViewCellEventArgs e)
        {
            // Проверяем все данные, если всё нормально - сохраняем.
            if (parentDb.CheckData(dataGridView.Rows[e.RowIndex].Cells[e.ColumnIndex]))
                parentDb.SaveData();
        }

        // Событие, вызываемое при изменении состояния чекбокса "Фильтр".
        private void filterCheckBox_CheckedChanged(object sender, EventArgs e)
        {
            // Если пользователь поставил галочку, отображаем элементы управления фильтра.
            if (filterCheckBox.Checked)
            {
                filterLabel.Visible = true;
                filterColumnCombo.Visible = true;
                filterText.Visible = true;
                setFilter();
            }
            // Если снял - прячем.
            else
            {
                filterLabel.Visible = false;
                filterColumnCombo.Visible = false;
                filterText.Visible = false;
                bindingSource.Filter = null;
            }
        }

        // Событие, вызываемое при изменении состояния комбобокса "Тип фильтра"
        private void filterColumnCombo_SelectedIndexChanged(object sender, EventArgs e)
        {
            // Если пользователь выбрал пункт "(отключено)", делаем поле фильтра неактивным.
            if (filterColumnCombo.SelectedIndex == 0)
                filterText.Enabled = false;
            // В противном случае включаем поле фильтра.
            else
                filterText.Enabled = true;
            // Устанавливаем фильтрацию.
            setFilter();
        }

        // Событие, вызываемое при изменении текста поля фильтра.
        private void filterText_TextChanged(object sender, EventArgs e)
        {
            setFilter();
        }

        // Событие, вызываемое при нажатии на кнопку "Сократить".
        private void btnRetire_Click(object sender, EventArgs e)
        {
            RetireForm wndRetireForm = new RetireForm(parentDb, dataGridView);
            wndRetireForm.Show();
        }

        // Событие, возникаемое при нажатии на кнопку "Приказ".
        private void btnOrder_Click(object sender, EventArgs e)
        {
            if (dataGridView.SelectedRows.Count == 0)
                MessageBox.Show("Выберите сотрудников", "Не выбраны сотрудники", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
            else
            {
                // Открываем окно приказа.
                OrderForm orderForm = new OrderForm(dataGridView);
                try
                {
                    orderForm.Show();
                }
                catch (Exception) {};
            }
        }
    }
}
