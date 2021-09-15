/*
 * Создано в SharpDevelop.
 * Пользователь: Yuri Zinchenko
 * Дата: 08.11.2018
 * Время: 20:28
*/
using System;
using System.Data;
using System.Windows.Forms;

namespace Variant01
{
	/// <summary>
	/// Description of OneServiceForm.
	/// </summary>
	public partial class OneServiceForm : Form
	{
		public OneServiceForm()
		{
			InitializeComponent();
		}
		void UpdateData()
		{
			textSum.Text = (Convert.ToDouble(textSvVolume.Text) * Convert.ToDouble(textTarif.Text) - Convert.ToDouble(textSubsidion.Text)).ToString();
		}
		
		void OneServiceFormLoad(object sender, EventArgs e)
		{
			DataTable dt = dataSet.Tables.Add("Услуги");
			
			dt.Columns.Add("Вид услуги");
			dt.Columns.Add("Ед. изм.");
			dt.Columns.Add("Объём услуг");
			dt.Columns.Add("Тариф");
			dt.Columns.Add("Сумма");
			dt.Columns.Add("Субсидии");
			dt.Columns.Add("Итого");
			
			dt.ReadXml("tarif.xml");
			
			dateMonth.CustomFormat = "MMMM yyyy";
			
			foreach (DataRow dr in dt.Rows)
				comboSvType.Items.Add(dr[0]);
		}
		void ComboSvTypeSelectedIndexChanged(object sender, EventArgs e)
		{
			textTarif.Text = dataSet.Tables["Услуги"].Rows[comboSvType.SelectedIndex][3].ToString();
			UpdateData();
		}
		void BtnSendClick(object sender, EventArgs e)
		{
			DialogResult res = MessageBox.Show(
				"Отправить данные?",
				"Отправление данных",
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
				comboSvType.Text = "";
				textSvVolume.Text = "0";
				textSubsidion.Text = "0";
				textSum.Text = "0";
			}
		}
		void TextSvVolumeTextChanged(object sender, EventArgs e)
		{
			UpdateData();
		}
		void TextSubsidionTextChanged(object sender, EventArgs e)
		{
			UpdateData();
		}
	}
}
