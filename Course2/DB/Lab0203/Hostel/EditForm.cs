/*
 * Создано в SharpDevelop.
 * Пользователь: Master
 * Дата: 04.11.2018
 * Время: 17:33
 * 
 * Для изменения этого шаблона используйте меню "Инструменты | Параметры | Кодирование | Стандартные заголовки".
 */
using System;
using System.Data;
using System.Windows.Forms;

namespace Hostel
{
	/// <summary>
	/// Description of EditForm.
	/// </summary>
	public partial class EditForm : Form
	{
		public EditForm(BindingSource bsBenefits, BindingSource bsRooms, BindingSource bsStudents)
		{
			//
			// The InitializeComponent() call is required for Windows Forms designer support.
			//
			InitializeComponent();
			
			//
			// TODO: Add constructor code after the InitializeComponent() call.
			//
			benefitsBindingSource = bsBenefits;
			roomsBindingSource = bsRooms;
			
			AddMode = false;
		}
		public void ModeAdd(BindingSource bindingSource)
		{
			AddMode = true;
			bSrc = bindingSource;
		}
		public void ModeEdit(DataGridView dataGridView)
		{
			AddMode = false;
			dgView = dataGridView;
		}
		void EditFormLoad(object sender, EventArgs e)
		{
			comboBenefit.DataSource = benefitsBindingSource;
			comboBenefit.DisplayMember = "Код льготы";
			comboBenefit.ValueMember = "Код льготы";
			
			comboRoom.DataSource = roomsBindingSource;
			comboRoom.DisplayMember = "№ комнаты";
			comboRoom.ValueMember = "№ комнаты";

			if (AddMode == false)
			{
				textName.Text = dgView.SelectedRows[0].Cells[1].Value.ToString();
				textBirthYear.Text = dgView.SelectedRows[0].Cells[2].Value.ToString();
				comboGender.Text = dgView.SelectedRows[0].Cells[3].Value.ToString();
				textAddress.Text = dgView.SelectedRows[0].Cells[4].Value.ToString();
				textGroup.Text = dgView.SelectedRows[0].Cells[5].Value.ToString();
				comboBenefit.Text = dgView.SelectedRows[0].Cells[6].Value.ToString();
				textPassport.Text = dgView.SelectedRows[0].Cells[7].Value.ToString();
				comboRoom.Text = dgView.SelectedRows[0].Cells[8].Value.ToString();
				dateSettle.Text = dgView.SelectedRows[0].Cells[9].Value.ToString();
			}
		}
		void EditFormFormClosing(object sender, FormClosingEventArgs e)
		{
		}
		private DataGridView dgView;
		private DataRow row;
		private BindingSource bSrc;
		private bool AddMode;
		void BtnCancelClick(object sender, EventArgs e)
		{
			Close();
		}
		void BtnOkClick(object sender, EventArgs e)
		{
			if (AddMode)
			{
				row = (DataRow)((DataRowView)bSrc.AddNew()).Row;
				row[0] = "0";
				row[1] = textName.Text;
				row[2] = Convert.ToUInt16(textBirthYear.Text);
				row[3] = comboGender.Text;
				row[4] = textAddress.Text;
				row[5] = textGroup.Text;
				row[6] = Convert.ToUInt16(comboBenefit.Text);
				row[7] = textPassport.Text;
				row[8] = Convert.ToUInt16(comboRoom.Text);
				row[9] = Convert.ToDateTime(dateSettle.Text);
				bSrc.EndEdit();
			}
			else
			{
				dgView.SelectedRows[0].Cells[1].Value = textName.Text;
				dgView.SelectedRows[0].Cells[2].Value = Convert.ToUInt16(textBirthYear.Text);
				dgView.SelectedRows[0].Cells[3].Value = comboGender.Text;
				dgView.SelectedRows[0].Cells[4].Value = textAddress.Text;
				dgView.SelectedRows[0].Cells[5].Value = textGroup.Text;
				dgView.SelectedRows[0].Cells[6].Value = Convert.ToUInt16(comboBenefit.Text);
				dgView.SelectedRows[0].Cells[7].Value = textPassport.Text;
				dgView.SelectedRows[0].Cells[8].Value = Convert.ToUInt16(comboRoom.Text);
				dgView.SelectedRows[0].Cells[9].Value = Convert.ToDateTime(dateSettle.Text);
			}
			Close();
		}
	}
}
