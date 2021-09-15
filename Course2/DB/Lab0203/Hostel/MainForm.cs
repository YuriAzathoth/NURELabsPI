using System;
using System.Data;
using System.Windows.Forms;

namespace Hostel
{
    public partial class MainForm : Form
    {
        public MainForm()
        {
            InitializeComponent();
        }

        private void MainForm_Load(object sender, EventArgs e)
        {
        	dataGridView.AutoGenerateColumns = true;
        	dataGridView.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.AllCells;
			
            // TODO: данная строка кода позволяет загрузить данные в таблицу "lab01DataSet.Льготы". При необходимости она может быть перемещена или удалена.
            this.льготыTableAdapter.Fill(this.lab01DataSet.Льготы);
            // TODO: данная строка кода позволяет загрузить данные в таблицу "lab01DataSet.Студенты". При необходимости она может быть перемещена или удалена.
            this.студентыTableAdapter.Fill(this.lab01DataSet.Студенты);
            // TODO: данная строка кода позволяет загрузить данные в таблицу "lab01DataSet.Комнаты". При необходимости она может быть перемещена или удалена.
            this.комнатыTableAdapter.Fill(this.lab01DataSet.Комнаты);
        }

        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }
        private void UpdateData()
        {
            комнатыTableAdapter.Update(lab01DataSet);
            льготыTableAdapter.Update(lab01DataSet);
            студентыTableAdapter.Update(lab01DataSet);
        }
        private void MainForm_FormClosing(object sender, FormClosingEventArgs e)
        {
        	UpdateData();
        }
		void RoomsToolStripMenuItemClick(object sender, EventArgs e)
		{
			bindingNavigator.BindingSource = комнатыBindingSource;
			dataGridView.DataSource = комнатыBindingSource;
			labelTable.Text = "Rooms";
		}
		void StudentsToolStripMenuItemClick(object sender, EventArgs e)
		{
			bindingNavigator.BindingSource = студентыBindingSource;
			dataGridView.DataSource = студентыBindingSource;
			labelTable.Text = "Students";
		}
		void BenefitsToolStripMenuItemClick(object sender, EventArgs e)
		{
			bindingNavigator.BindingSource = льготыBindingSource;
			dataGridView.DataSource = льготыBindingSource;
			labelTable.Text = "Benefits";
		}
		void ResettlementToolStripMenuItemClick(object sender, EventArgs e)
		{
			RSForm rs = new RSForm(комнатыBindingSource, студентыBindingSource);
			rs.ShowDialog();
		}
		void QueryEditToolStripMenuItemClick(object sender, EventArgs e)
		{
		}
		void AddToolStripMenuItemClick(object sender, EventArgs e)
		{
			if (labelTable.Text == "Students")
			{
				EditForm ef = new EditForm(льготыBindingSource, комнатыBindingSource, студентыBindingSource);
				ef.ModeAdd(студентыBindingSource);
				ef.Show();
    	    	UpdateData();
			}
			else
				MessageBox.Show("You can use the edit tools only with Students table!", "Wrong using", MessageBoxButtons.OK, MessageBoxIcon.Information);
		}
		void UpdateToolStripMenuItemClick(object sender, EventArgs e)
		{
			if (labelTable.Text != "Students")
			{
				MessageBox.Show("You can use the edit tools only with Students table!", "Wrong using", MessageBoxButtons.OK, MessageBoxIcon.Information);
				return;
			}
			if (dataGridView.SelectedRows.Count <= 0)
				MessageBox.Show("Select a row to edit", "Wrong action", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
			else if (dataGridView.SelectedRows.Count > 1)
				MessageBox.Show("You can edit only ONE row atthe same time", "Wron action", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
			else
			{
				EditForm ef = new EditForm(льготыBindingSource, комнатыBindingSource, студентыBindingSource);
				ef.ModeEdit(dataGridView);
				ef.Show();
				UpdateData();
			}
		}
		void DeleteToolStripMenuItemClick(object sender, EventArgs e)
		{
			if (MessageBox.Show("Are you sure you want to delete selected row?", "Delete confirmation", MessageBoxButtons.YesNo, MessageBoxIcon.Question) == DialogResult.Yes)
			{
				dataGridView.Rows.Remove(dataGridView.SelectedRows[0]);
        		UpdateData();
			}
		}
		void EditQueryToolStripMenuItemClick(object sender, EventArgs e)
		{
			QueryEdit qe = new QueryEdit();
			qe.Show();
		}
    }
}
