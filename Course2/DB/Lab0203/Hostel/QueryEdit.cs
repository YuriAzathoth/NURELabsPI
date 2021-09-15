/*
 * Создано в SharpDevelop.
 * Пользователь: Master
 * Дата: 04.11.2018
 * Время: 17:14
 * 
 * Для изменения этого шаблона используйте меню "Инструменты | Параметры | Кодирование | Стандартные заголовки".
 */
using System;
using System.Data;
using System.Data.OleDb;
using System.Windows.Forms;

namespace Hostel
{
	/// <summary>
	/// Description of QueryEdit.
	/// </summary>
	public partial class QueryEdit : Form
	{
		public QueryEdit()
		{
			//
			// The InitializeComponent() call is required for Windows Forms designer support.
			//
			InitializeComponent();
			
			//
			// TODO: Add constructor code after the InitializeComponent() call.
			//
		}
		private const string ConnectionStr = @"Provider=Microsoft.ACE.OLEDB.12.0;Data Source=|DataDirectory|\Lab01.accdb";
		void BtnDoClick(object sender, EventArgs e)
		{
			try
			{
				OleDbConnection oleconn = new OleDbConnection(ConnectionStr);
				oleconn.Open();
				OleDbDataAdapter oda = new OleDbDataAdapter(richCmd.Text, oleconn);
				DataTable dt = new DataTable();
				oda.Fill(dt);
				dataGridView.DataSource = dt;
				oleconn.Close();
			}
			catch (Exception ex)
			{
				MessageBox.Show(ex.Message, "An exception has occured!", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
			}
		}
		void BtnClearClick(object sender, EventArgs e)
		{
			richCmd.Clear();
			richCmd.Text = "SELECT ";
		}
		void BtnExitClick(object sender, EventArgs e)
		{
			Close();
		}
	}
}
