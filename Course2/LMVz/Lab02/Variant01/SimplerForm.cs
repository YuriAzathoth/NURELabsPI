/*
 * Создано в SharpDevelop.
 * Пользователь: Yuri Zinchenko
 * Дата: 08.11.2018
 * Время: 15:51
*/
using System;
using System.Data;
using System.Windows.Forms;

namespace Variant01
{
	/// <summary>
	/// Description of SimplerForm.
	/// </summary>
	public partial class SimplerForm : Form
	{
		public SimplerForm()
		{
			InitializeComponent();
		}
		void UpdateData()
		{
			textGeneralColdWater.Text = (Convert.ToDouble(textVolumeColdWater.Text) * Convert.ToDouble(labelTarifColdWater.Text)).ToString();
			textFinalColdWater.Text = (Convert.ToDouble(textGeneralColdWater.Text) - Convert.ToDouble(textSubsidionColdWater.Text)).ToString();
			
			textGeneralHotWater.Text = (Convert.ToDouble(textVolumeHotWater.Text) * Convert.ToDouble(labelTarifHotWater.Text)).ToString();
			textFinalHotWater.Text = (Convert.ToDouble(textGeneralHotWater.Text) - Convert.ToDouble(textSubsidionHotWater.Text)).ToString();
			
			textGeneralCanal.Text = (Convert.ToDouble(textVolumeCanal.Text) * Convert.ToDouble(labelTarifCanal.Text)).ToString();
			textFinalCanal.Text = (Convert.ToDouble(textGeneralCanal.Text) - Convert.ToDouble(textSubsidionCanal.Text)).ToString();
			
			textGeneralEnergy.Text = (Convert.ToDouble(textVolumeEnergy.Text) * Convert.ToDouble(labelTarifEnergy.Text)).ToString();
			textFinalEnergy.Text = (Convert.ToDouble(textGeneralEnergy.Text) - Convert.ToDouble(textSubsidionEnergy.Text)).ToString();
			
			textGeneralGas.Text = (Convert.ToDouble(textVolumeGas.Text) * Convert.ToDouble(labelTarifGas.Text)).ToString();
			textFinalGas.Text = (Convert.ToDouble(textGeneralGas.Text) - Convert.ToDouble(textSubsidionGas.Text)).ToString();
			
			textTax.Text = (Convert.ToDouble(textFinalColdWater.Text) +
			                Convert.ToDouble(textFinalHotWater.Text) +
			                Convert.ToDouble(textFinalCanal.Text) +
			                Convert.ToDouble(textFinalEnergy.Text) +
			                Convert.ToDouble(textFinalGas.Text)).ToString();
		}
		void ClearAll()
		{
			textNum.Clear();
			textClLicNumber.Clear();
			textClName.Clear();
			textClAddress.Clear();
			textClArea.Clear();
			textClPeopleNum.Clear();
			textVolumeCanal.Text = "0,0";
			textVolumeColdWater.Text = "0,0";
			textVolumeEnergy.Text = "0,0";
			textVolumeGas.Text = "0,0";
			textVolumeHotWater.Text = "0,0";
			textSubsidionCanal.Text = "0,0";
			textSubsidionColdWater.Text = "0,0";
			textSubsidionEnergy.Text = "0,0";
			textSubsidionGas.Text = "0,0";
			textSubsidionHotWater.Text = "0,0";
			UpdateData();
		}
		
		void SimplerFormLoad(object sender, EventArgs e)
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
			
			DataRow dr;
			
			dr = dt.Rows[0];
			labelMeasColdWater.Text = dr[1].ToString();
			labelTarifColdWater.Text = dr[3].ToString();
			
			dr = dt.Rows[1];
			labelMeasHotWater.Text = dr[1].ToString();
			labelTarifHotWater.Text = dr[3].ToString();
			
			dr = dt.Rows[2];
			labelMeasCanal.Text = dr[1].ToString();
			labelTarifCanal.Text = dr[3].ToString();
			
			dr = dt.Rows[3];
			labelMeasEnergy.Text = dr[1].ToString();
			labelTarifEnergy.Text = dr[3].ToString();
			
			dr = dt.Rows[4];
			labelMeasGas.Text = dr[1].ToString();
			labelTarifGas.Text = dr[3].ToString();
		}
		void TextVolumeColdWaterTextChanged(object sender, EventArgs e)
		{
			UpdateData();
		}
		void TextVolumeHotWaterTextChanged(object sender, EventArgs e)
		{
			UpdateData();
		}
		void TextVolumeCanalTextChanged(object sender, EventArgs e)
		{
			UpdateData();
		}
		void TextBox3TextChanged(object sender, EventArgs e)
		{
			UpdateData();
		}
		void TextVolumeEnergyTextChanged(object sender, EventArgs e)
		{
			UpdateData();
		}
		void TextSubsidionColdWaterTextChanged(object sender, EventArgs e)
		{
			UpdateData();
		}
		void TextSubsidionHotWaterTextChanged(object sender, EventArgs e)
		{
			UpdateData();
		}
		void TextSubsidionCanalTextChanged(object sender, EventArgs e)
		{
			UpdateData();
		}
		void TextSubsidionEnergyTextChanged(object sender, EventArgs e)
		{
			UpdateData();
		}
		void TextSubsidionGasTextChanged(object sender, EventArgs e)
		{
			UpdateData();
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
	}
}
