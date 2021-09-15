/*
 * Создано в SharpDevelop.
 * Пользователь: Yuri Zinchenko
 * Дата: 08.11.2018
 * Время: 15:05
*/
using System;
using System.Drawing;
using System.Windows.Forms;

namespace Variant01
{
	/// <summary>
	/// Description of MainForm.
	/// </summary>
	public partial class MainForm : Form
	{
		public MainForm()
		{
			InitializeComponent();
		}
		void BtnGeneralClick(object sender, EventArgs e)
		{
			var form = new GeneralForm();
			form.Show();
		}
		void BtnConcreteClick(object sender, EventArgs e)
		{
			var form = new SingleServiceForm();
			form.Show();
		}
		void BtnEasyClick(object sender, EventArgs e)
		{
			var form = new SimplerForm();
			form.Show();
		}
		void BtnOneServiceClick(object sender, EventArgs e)
		{
			var form = new OneServiceForm();
			form.Show();
		}
	}
}
