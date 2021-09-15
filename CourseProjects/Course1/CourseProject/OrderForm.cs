using System;
using System.Collections.Generic;
using System.IO;
using System.Windows.Forms;

namespace CourseProject
{
    public partial class OrderForm : Form
    {
        private static string orderTemplatesDir
        {
            get
            {
                return DataBase.CurrentDir + "/../../OrderTemplates.txt";
            }
        }

        private string num;
        private string date;
        private Dictionary<string, string> actToDesc;

        public OrderForm(DataGridView dataGridView)
        {
            num = Order.GetOrgerNum();
            date = DateTime.Now.ToShortDateString();
            actToDesc = new Dictionary<string, string>();

            InitializeComponent();

            foreach (DataGridViewRow row in dataGridView.SelectedRows)
                selectedEmployeesList.Items.Add(
                    row.Cells[1].Value.ToString() + " " + row.Cells[2].Value.ToString() + " " +
                    row.Cells[3].Value.ToString());

            orderNumLabel.Text = num;
            dateLabel.Text = date;

            updateOrderTypes();
        }

        private void updateOrderTypes()
        {
            actionCombo.Items.Clear();
            actToDesc.Clear();
            StreamReader reader = new StreamReader(orderTemplatesDir);
            while (!reader.EndOfStream)
            {
                string type = reader.ReadLine();
                string data = reader.ReadLine();
                if (!actToDesc.ContainsKey(type))
                    actToDesc.Add(type, data);
                if (reader.ReadLine() != "========")
                {
                    MessageBox.Show("Файл OrderTemplates.txt повреждён!", "Ошибка формата файла",
                        MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
                    Close();
                    continue;
                }
                actionCombo.Items.Add(type);
            }
            reader.Close();

            actionCombo.SelectedIndex = actionCombo.Items.Count - 1;
        }

        private void btnForm_Click(object sender, EventArgs e)
        {
            Order order = new Order(selectedEmployeesList.Items,
                actionCombo.Text, descriptionText.Text, reasonText.Text, causeText.Text);
            order.MakeCustom();
            Close();
        }

        private void btnDelete_Click(object sender, EventArgs e)
        {
            if (selectedEmployeesList.Items.Count > 1)
                selectedEmployeesList.Items.Remove(selectedEmployeesList.SelectedItem);
            else
                MessageBox.Show("Нельзя удалить последнего сотрудника из списка", "Ошибка удаления",
                    MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
        }

        private void actionCombo_SelectedIndexChanged(object sender, EventArgs e)
        {
            descriptionText.Text = actToDesc[actionCombo.Text];
        }

        private void btnRemember_Click(object sender, EventArgs e)
        {
            bool bTypeFound = false;
            StreamReader reader = new StreamReader(orderTemplatesDir);
            while (!reader.EndOfStream)
            {
                string str = reader.ReadLine();
                reader.ReadLine();
                reader.ReadLine();

                if (str == actionCombo.Text)
                    bTypeFound = true;
            }
            reader.Close();

            if (!bTypeFound)
            {
                StreamWriter writer = new StreamWriter(orderTemplatesDir, true);
                writer.WriteLine(actionCombo.Text);
                writer.WriteLine(descriptionText.Text);
                writer.WriteLine("========");
                writer.Close();
                updateOrderTypes();
            }

            if (bTypeFound)
                MessageBox.Show("Выбранный тип приказа уже существует", "Неудача",
                    MessageBoxButtons.OK, MessageBoxIcon.Warning);
            else
                MessageBox.Show("Тип приказа успешно добавлен", "Успех",
                    MessageBoxButtons.OK, MessageBoxIcon.Information);
        }

        private void btnRemoveOrderType_Click(object sender, EventArgs e)
        {
            DialogResult answer = MessageBox.Show(
                "Удалить текущий шаблон приказа?", "Подтверждение удаления",
                MessageBoxButtons.YesNo, MessageBoxIcon.Question);

            if (answer == DialogResult.Yes)
            {
                StreamWriter writer = new StreamWriter(orderTemplatesDir);
                foreach (KeyValuePair<string, string> pair in actToDesc)
                {
                    if (actionCombo.Text != pair.Key)
                    {
                        writer.WriteLine(pair.Key);
                        writer.WriteLine(pair.Value);
                        writer.WriteLine("========");
                    }
                }
                writer.Close();
                updateOrderTypes();
            }
        }
    }
}
