/*
 * Создано в SharpDevelop.
 * Пользователь: Yuri Zinchenko
 * Дата: 08.11.2018
 * Время: 14:41
 */
using System;
using System.Data;
using System.Windows.Forms;

namespace Variant01
{
	/// <summary>
	/// Description of SingleServiceForm.
	/// </summary>
	public partial class SingleServiceForm : Form
	{
		public SingleServiceForm()
		{
			InitializeComponent();
		}

		void InitTable()
		{
			DataTable dt = dataSet.Tables["Услуги"];
			dt.ReadXml("tarif.xml");
			
			dateMonth.CustomFormat = "MMMM yyyy";

/*			DataRow dr;
			
			dt.Rows.Add();
			dr = dt.Rows[dt.Rows.Count - 1];
			dr[0] = "Холодная вода";
			dr[1] = "м3";
			
			dt.Rows.Add();
			dr = dt.Rows[dt.Rows.Count - 1];
			dr[0] = "Горячая вода";
			dr[1] = "м3";
			
			dt.Rows.Add();
			dr = dt.Rows[dt.Rows.Count - 1];
			dr[0] = "Канализация";
			dr[1] = "м3";
			
			dt.Rows.Add();
			dr = dt.Rows[dt.Rows.Count - 1];
			dr[0] = "Электроэнергия";
			dr[1] = "квт/ч";
			
			dt.Rows.Add();
			dr = dt.Rows[dt.Rows.Count - 1];
			dr[0] = "Газ";
			dr[1] = "м3";*/
		}
		
		void SingleServiceFormLoad(object sender, EventArgs e)
		{
			DataTable dt = dataSet.Tables.Add("Услуги");
			
			dt.Columns.Add("Вид услуги");
			dt.Columns.Add("Ед. изм.");
			dt.Columns.Add("Объём услуг");
			dt.Columns.Add("Тариф");
			dt.Columns.Add("Сумма");
			dt.Columns.Add("Субсидии");
			dt.Columns.Add("Итого");
			
			dt.Columns[2].DefaultValue = "0,0";
			dt.Columns[3].DefaultValue = "0,0";
			dt.Columns[4].DefaultValue = "0,0";
			dt.Columns[5].DefaultValue = "0,0";
			dt.Columns[6].DefaultValue = "0,0";
			
			bindingSource.DataSource = dt;
			dataGridView.DataSource = bindingSource;

			InitTable();
		}
		void DataGridViewCellEndEdit(object sender, DataGridViewCellEventArgs e)
		{
			DataGridViewRow row = dataGridView.Rows[e.RowIndex];

			row.Cells[4].Value = (Convert.ToDouble(row.Cells[2].Value) * Convert.ToDouble(row.Cells[3].Value)).ToString();
			row.Cells[6].Value = (Convert.ToDouble(row.Cells[4].Value) - Convert.ToDouble(row.Cells[5].Value)).ToString();

			DataTable dt = dataSet.Tables["Услуги"];
			double dSum = 0;
			
			foreach (DataRow dr in dt.Rows)
				if (dr[6].ToString() != "")
					dSum += Convert.ToDouble(dr[6].ToString());
			
			textSum.Text = dSum.ToString();
		}
		void BtnSendClick(object sender, EventArgs e)
		{
			DialogResult res = MessageBox.Show(
				"Вы уверены что внесли все данные верно?",
				"Проверка данных",
				MessageBoxButtons.YesNo,
				MessageBoxIcon.Question,
				MessageBoxDefaultButton.Button1);
			if (res == DialogResult.Yes)
			{
				MessageBox.Show("Данные об оплате успешно отправлены", "Успех", MessageBoxButtons.OK, MessageBoxIcon.Information, MessageBoxDefaultButton.Button1);
				
				textNum.Clear();
				textClLicNumber.Clear();
				textClName.Clear();
				textClAddress.Clear();
				textClArea.Clear();
				textClPeopleNum.Clear();
				
				dataSet.Tables["Услуги"].Clear();
				InitTable();
			}
		}
		void BtnSaveTarifClick(object sender, EventArgs e)
		{
			DialogResult res = MessageBox.Show(
				"Изменить тариф?\nВсе введённые данные кроме тарифов будут обнулены",
				"Изменение тарифа",
				MessageBoxButtons.YesNo,
				MessageBoxIcon.Question,
				MessageBoxDefaultButton.Button1);
			if (res == DialogResult.Yes)
			{
				MessageBox.Show("Тариф сохранён", "Успех", MessageBoxButtons.OK, MessageBoxIcon.Information, MessageBoxDefaultButton.Button1);
				
				DataTable dt = dataSet.Tables["Услуги"];		
				foreach(DataRow dr in dt.Rows)
				{
					dr[2] = "0,0";
					dr[4] = "0,0";
					dr[5] = "0,0";
					dr[6] = "0,0";
				}		
				dt.WriteXml("tarif.xml", true);
			}
		}
	}
}
