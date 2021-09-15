/*
 * Создано в SharpDevelop.
 * Пользователь: Master
 * Дата: 03.11.2018
 * Время: 21:31
 * 
 * Для изменения этого шаблона используйте меню "Инструменты | Параметры | Кодирование | Стандартные заголовки".
 */
using System;
using System.Data;
using System.Windows.Forms;
using Hostel.Lab01DataSetTableAdapters;

namespace Hostel
{
	/// <summary>
	/// Description of RSForm.
	/// </summary>
	public partial class RSForm : Form
	{
		public RSForm(BindingSource bsRooms, BindingSource bsStudents)
		{
			//
			// The InitializeComponent() call is required for Windows Forms designer support.
			//
			InitializeComponent();
			
			//
			// TODO: Add constructor code after the InitializeComponent() call.
			//
			roomsBindingSource = bsRooms;
			studentsBindingSource = bsStudents;
		}
		void RSFormLoad(object sender, EventArgs e)
		{
			bindingNavigator.BindingSource = roomsBindingSource;
			textId.DataBindings.Add("Text", roomsBindingSource, "№ комнаты");
			textPrice.DataBindings.Add("Text", roomsBindingSource, "Стоимость");
			textAmount.DataBindings.Add("Text", roomsBindingSource, "Количество");
			textFloor.DataBindings.Add("Text", roomsBindingSource, "Этаж");
			textTools.DataBindings.Add("Text", roomsBindingSource, "Инвентарь");
			
			dataGridView.DataSource = studentsBindingSource;
			dataGridView.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.AllCells;
		}
		void BtnAcceptClick(object sender, EventArgs e)
		{
			if (MessageBox.Show("Are you sure you want to accept changes?", "Data changes", MessageBoxButtons.YesNo) == DialogResult.Yes)
			{
				roomsBindingSource.EndEdit();
			}
		}
	}
}
