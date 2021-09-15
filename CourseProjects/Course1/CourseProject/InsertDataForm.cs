using System;
using System.Collections.Generic;
using System.Text.RegularExpressions;
using System.Windows.Forms;

namespace CourseProject
{
    // Класс окна добавления новых сотрудников в базу.
    public partial class InsertDataForm : Form
    {
        // Ссылка на объект класса DataBase, которые создал объект этого класса.
        public DataBase parentDb { get; private set; }

        // Конструктор класса.
        public InsertDataForm(DataBase _parentDb)
        {
            parentDb = _parentDb;
            InitializeComponent();
            setBorders();
        }

        // Метод, устанавливающий мин и макс значения для элементов умравления этого окна.
        private void setBorders()
        {
            // Ставим ограничения на даты.
            DateTime now = DateTime.Now;
            birthDatePicker.MinDate = new DateTime(now.Year - 70, now.Month, now.Day);
            birthDatePicker.MaxDate = new DateTime(now.Year - 18, now.Month, now.Day);
            issueDatePicker.MinDate = new DateTime(now.Year - 54, now.Month, now.Day);
            issueDatePicker.MaxDate = new DateTime(now.Year - 2, now.Month, now.Day);
            employmentDatePicker.MinDate = new DateTime(2000, 2, 12);
            employmentDatePicker.MaxDate = new DateTime(now.Year, now.Month, now.Day);
            appointmentDatePicker.MinDate = new DateTime(2000, 2, 12);
            appointmentDatePicker.MaxDate = new DateTime(now.Year, now.Month, now.Day);
            // Ставим минимальные и максимальные ограничения на зарплату.
            salaryNumeric.Minimum = 4000;
            salaryNumeric.Maximum = 25000;
        }

        // Мотод, который проверяет строку data по регулярному выражению, и возвращает true, если проверка успешна, иначе false.
        private bool checkDataByMask(string mask, string data)
        {
            Regex regex = new Regex(mask);
            return regex.Match(data).Success;
        }

        // Метод, который проверяет правильность вводимых данных по регулярным выражениям.
        private string checkData()
        {
            if (surnameText.Text == string.Empty)
                return "Поле \"Фамилия\" пустое";
            if (nameText.Text == string.Empty)
                return "Поле \"Имя\" пустое";
            if (fatherNameText.Text == string.Empty)
                return "Поле \"Отчество\" пустое";
            if (birthPlaceText.Text == string.Empty)
                return "Поле \"Место рождения\" пустое";
            if (addressText.Text == string.Empty)
                return "Поле \"Домашний адрес\" пустое";
            if (houseText.Text == string.Empty)
                return "Поле \"Номер дома\" пустое";
            if (passportNumText.Text == string.Empty)
                return "Поле \"Номер паспорта\" пустое";
            if (!checkDataByMask("^[А-Я]{1}[а-я]{2,14}$", surnameText.Text))
                return "Неправильно введена Фамилия";
            if (!checkDataByMask("^[А-Я]{1}[а-я]{2,14}$", nameText.Text))
                return "Неправильно введено Имя";
            if (!checkDataByMask("^[А-Я]{1}[а-я]{2,14}$", fatherNameText.Text))
                return "Неправильно введено Отчество";
            if (!checkDataByMask("^[0-9]{1,3}[а-я]{0,1}$", houseText.Text))
                return "Неправильно введен Номер дома";
            if (!checkDataByMask("^[0-9]{0,4}$", apartmentText.Text))
                return "Неправильно введен Номер квартиры";
            return string.Empty;
        }

        // Событие, вызываемое при нажатии на кнопку "Добавить".
        private void btnAdd_Click(object sender, EventArgs e)
        {
            // Если произошла ошибка при проверки данных, возвращаемся в окно и ничего не сохраняем.
            string errorResult = checkData();
            if (errorResult != string.Empty)
            {
                MessageBox.Show(errorResult + ". Хотите попробовать ввести эти данные снова?",
                    "Ошибка ввода данных", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
                return;
            }
            // Если всё нормально, сохраняем данные в базу.
            List<string> newRow = new List<string>(DataBase.CellsCount);
            newRow.Add(surnameText.Text.Trim());                                // Фамилия
            newRow.Add(nameText.Text.Trim());                                   // Имя
            newRow.Add(fatherNameText.Text.Trim());                             // Отчество
            newRow.Add(birthDatePicker.Value.ToShortDateString().Trim());       // Дата рождения
            newRow.Add(birthPlaceText.Text.Trim());                             // Место рождения
            newRow.Add(addressText.Text.Trim());                                // Улица
            newRow.Add(houseText.Text.Trim());                                  // Дом
            newRow.Add(apartmentText.Text.Trim());                              // Квартира
            newRow.Add(passportNumText.Text.Trim());                            // Номер паспорта
            newRow.Add(issueDatePicker.Value.ToShortDateString().Trim());       // Дата выдачи
            newRow.Add(departmentText.Text.Trim());                             // Подразделение
            newRow.Add(positionText.Text.Trim());                               // Должность
            newRow.Add(specialityText.Text.Trim());                             // Специальность
            newRow.Add(educationText.Text.Trim());                              // Образование
            newRow.Add(salaryNumeric.Value.ToString().Trim());                  // Оклад
            newRow.Add(employmentDatePicker.Value.ToShortDateString().Trim());  // Дата принятия на работу
            newRow.Add(appointmentDatePicker.Value.ToShortDateString().Trim()); // Дата назначения

            // Формируем приказ о принятии на работу.
            List<string> name = new List<string>(1);
            name.Add(newRow[0] + " " + newRow[1] + " " + newRow[2]);
            Order order = new Order(name, newRow[11], newRow[10]);
            if (order.Employ())
            {
                // Записываем новые данные в базу и закрываем окно.
                parentDb.WriteData(newRow);
                Close();
            }
        }

        // Событие, вызываемое при изменении даты в поле "Дата рождения".
        private void birthDatePicker_ValueChanged(object sender, EventArgs e)
        {
            // Меняем дату выдачи паспорта, на 16 лет позже, чем дата рождения.
            // Это сделано, чтобы облегчить заполнение даты выдачи паспорта.
            issueDatePicker.Value = new DateTime(birthDatePicker.Value.Year + 16,
                birthDatePicker.Value.Month, birthDatePicker.Value.Day);
        }
    }
}
