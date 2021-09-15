/*
 * Создано в SharpDevelop.
 * Пользователь: Yuri Zinchenko
 * Дата: 08.11.2018
 * Время: 14:53
*/
using System;
using System.Data;
using System.Windows.Forms;

namespace Variant01
{
	/// <summary>
	/// Description of GeneralForm.
	/// </summary>
	public partial class GeneralForm : Form
	{
		public GeneralForm()
		{
			InitializeComponent();
		}

		void CalculateSum()
		{
			DataTable dt = dataSet.Tables["Услуги"];
			double dSum = 0;
			
			foreach (DataRow dr in dt.Rows)
				if (dr[6].ToString() != "")
					dSum += Convert.ToDouble(dr[6].ToString());
			
			textSum.Text = dSum.ToString();
		}
		void CalculatePrice(DataGridViewRow row)
		{
			row.Cells[4].Value = (Convert.ToDouble(row.Cells[2].Value) * Convert.ToDouble(row.Cells[3].Value)).ToString();
		}
		void CalculateBenefit(DataGridViewRow row)
		{
			row.Cells[6].Value = (Convert.ToDouble(row.Cells[4].Value) - Convert.ToDouble(row.Cells[5].Value)).ToString();
		}
		void ClearAll()
		{
			textNum.Clear();
			
			textClLicNumber.Clear();
			textClName.Clear();
			textClAddress.Clear();
			textClArea.Clear();
			
			textSvName.Clear();
			textSvCity.Clear();
			textSvAddress.Clear();
			textSvNumber.Clear();
			
			textSum.Text = "0";
			
			textBankName.Clear();
			textChechNo.Clear();
			
			dataSet.Clear();
		}

		void GeneralFormLoad(object sender, EventArgs e)
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
			
			dateMonth.CustomFormat = "MMMM yyyy";
		}
		void BtnAddCommonClick(object sender, EventArgs e)
		{
			DataTable dt = dataSet.Tables["Услуги"];
			DataRow dr;
			
			if (dt.Rows.Count > 0)
			{
				DialogResult res = MessageBox.Show(
					"В даблице есть данные. Стереть их при добавлении общих услуг?",
					"Перезапись данных",
					MessageBoxButtons.YesNoCancel,
					MessageBoxIcon.Question,
					MessageBoxDefaultButton.Button1);
				switch(res)
				{
					case DialogResult.Yes:
						dataSet.Tables["Услуги"].Clear();
						break;
					case DialogResult.No:
						break;
					default:
						return;
				}
			}
			
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
			dr[1] = "м3";
		}
		void BtnClearClick(object sender, EventArgs e)
		{
			dataSet.Tables["Услуги"].Clear();
		}
		void DataGridViewCellEndEdit(object sender, DataGridViewCellEventArgs e)
		{
			if (e.ColumnIndex >= 2)
			{
				CalculatePrice(dataGridView.Rows[e.RowIndex]);
				CalculateBenefit(dataGridView.Rows[e.RowIndex]);
				CalculateSum();
			}
		}
		void BtnAddClick(object sender, EventArgs e)
		{
			DataTable dt = dataSet.Tables["Услуги"];
			DataRow row = dt.Rows.Add();
		}
		void BtnDeleteClick(object sender, EventArgs e)
		{
			if (dataGridView.SelectedRows.Count > 0)
			{
				DialogResult res = MessageBox.Show(
					"Удалить выбранные строки?",
					"Удаление данных",
					MessageBoxButtons.YesNo,
					MessageBoxIcon.Question,
					MessageBoxDefaultButton.Button1);
				if (res == DialogResult.Yes)
					foreach (DataGridViewRow row in dataGridView.SelectedRows)
						dataSet.Tables["Услуги"].Rows.RemoveAt(row.Index);
			}	
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
				ClearAll();
			}
		}
		void BtnClearAllClick(object sender, EventArgs e)
		{
			DialogResult res = MessageBox.Show(
				"Вы уверены что очистить всю текущую информацию?",
				"Очистка данных",
				MessageBoxButtons.YesNo,
				MessageBoxIcon.Question,
				MessageBoxDefaultButton.Button1);
			if (res == DialogResult.Yes)
			{
				MessageBox.Show("Данные успешно очищены", "Успех", MessageBoxButtons.OK, MessageBoxIcon.Information, MessageBoxDefaultButton.Button1);
				ClearAll();
			}
		}
	}
}
