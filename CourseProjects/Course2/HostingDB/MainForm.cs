/*
 * Создано в SharpDevelop.
 * Пользователь: Yuri Zinchenko
 * Дата: 06.12.2018
 * Время: 15:03
*/
using System;
using System.Collections.Generic;
using System.Data;
using System.IO;
using System.Windows.Forms;

namespace HostingDB
{
	/// <summary>
	/// Description of MainForm.
	/// </summary>
	public partial class MainForm : Form
	{
		public MainForm()
		{
			//
			// The InitializeComponent() call is required for Windows Forms designer support.
			//
			InitializeComponent();
			
			dbProxy = new DBProxy();
			
			dgvMain.AutoGenerateColumns = true;
			dgvQuery.AutoGenerateColumns = true;
			dgvAuto.AutoGenerateColumns = true;
			
			LoadNames();
			listTables.SelectedIndex = 0;
		}
		
		// --------------------------------------------------------------------------------------------------------------
		// Отладка
		// --------------------------------------------------------------------------------------------------------------
		public static void ExceptionMessage(Exception e)
		{
			MessageBox.Show(e.Message, "Произошло исключение!", MessageBoxButtons.OK, MessageBoxIcon.Error);
		}
		
		public static void DebugMessage(string msg)
		{
			MessageBox.Show(msg, "Debug message", MessageBoxButtons.OK, MessageBoxIcon.Information);
		}
		
		// --------------------------------------------------------------------------------------------------------------
		// Таблицы
		// --------------------------------------------------------------------------------------------------------------		
		void Query(string sql)
		{
			dbProxy.DoQuery(sql);
			UpdateDataSources();
		}
		
		void ReQuery(bool defsql = true)
		{
			if (chkSQL.Checked)
			{
				if (defsql)
					SetDefaultQuery();
				Query(txtSQL.Text);
			}
			else
				LoadTable();
		}
		
		void LoadTable(string table)
		{
			dbProxy.LoadTable(table);
			UpdateDataSources();
		}
		
		void LoadTable()		{ LoadTable(GetCurrTable()); }
		string GetCurrTable()	{ return listTables.SelectedItem.ToString(); }
		void LoadNames()		{ foreach (string name in dbProxy.DbNames) listTables.Items.Add(name); }
		
		void UpdateDataSources()
		{
			if (modeAdd) modeAdd = false;
			
			if (tabMain.SelectedIndex == 0)
			{
				if (!chkSQL.Checked)
					dbProxy.LoadTable(GetCurrTable());
				bsrcMain.DataSource = dbProxy.DbTable;
			}
			else if (bsrcMain.DataSource != null)
				bsrcMain.DataSource = null;
			
			if (tabMain.SelectedIndex == 1)
				bsrcQuery.DataSource = dbProxy.DbTable;
			else if (bsrcQuery.DataSource != null)
				bsrcQuery.DataSource = null;
			
			if (tabMain.SelectedIndex == 2)
				bsrcAuto.DataSource = dbProxy.DbTable;
			else if (bsrcAuto.DataSource != null)
				bsrcAuto.DataSource = null;
		}
		
		// --------------------------------------------------------------------------------------------------------------
		// Интерфейс
		// --------------------------------------------------------------------------------------------------------------	
		void SetSqlMode()
		{
			bool mode = chkSQL.Checked;
			txtSQL.Visible = mode;
			btnDoSql.Visible = mode;
			btnClearSql.Visible = mode;
			SetDataGridSize();
			ReQuery();
		}
		
		void SetDefaultQuery()
		{
			if (chkSQL.Checked)
				txtSQL.Text = string.Format("SELECT * FROM {0};", listTables.SelectedItem.ToString());
		}
		
		void SetDataGridSize()
		{
			dgvMain.Top = chkSQL.Checked ? 91 : 33;
			dgvMain.Height = chkSQL.Checked ? 497 : 461;
		}
		
		// --------------------------------------------------------------------------------------------------------------
		// Редактирование данных
		// --------------------------------------------------------------------------------------------------------------
		void AddData()
		{
			try
			{
				if (!modeAdd)
				{
					modeAdd = true;
					btnAdd.Text = "Сохранить";
					
					var row = dbProxy.DbTable.Rows.Add();
					row[0] = GetMaxId() + 1;
				}
				else
				{
					modeAdd = false;
					btnAdd.Text = "Добавить";
					
					string table = GetCurrTable();
					string cells = string.Empty;
					foreach (DataGridViewCell cell in dgvMain.Rows[dgvMain.Rows.Count - 1].Cells)
					{
						cells += string.Format("'{0}'", cell.Value);
						if (cell.ColumnIndex < dgvMain.Columns.Count - 1)
							cells += ",";
					}
					
					string sql = string.Format("INSERT INTO {0} VALUES ({1});", table, cells);
					Query(sql);
					ReQuery();
				}
			} catch (Exception e) { ExceptionMessage(e); }
		}
		
		void RemoveData()
		{
			if (dgvMain.SelectedRows.Count < 1)
			{
				MessageBox.Show("Выберите строки, которые хотите удалить", "Не выбраны строки для удаления", MessageBoxButtons.OK, MessageBoxIcon.Information);
				return;
			}
			DialogResult dlgres = MessageBox.Show(string.Format("Вы уверены, что хотите удалить эти {0} строк?", dgvMain.SelectedRows.Count), "Подтверждение удаления", MessageBoxButtons.YesNo, MessageBoxIcon.Question);
			if (dlgres != DialogResult.Yes)
				return;

			try
			{
				string table = GetCurrTable();
				string idname = GetIdName();
				
				var sqllist = new List<string>(dgvMain.SelectedRows.Count);
				foreach (DataGridViewRow row in dgvMain.SelectedRows)
					sqllist.Add(string.Format("DELETE FROM {0} WHERE [{1}]={2};", table, idname, GetId(row.Index)));
				foreach (string sql in sqllist)
					Query(sql);
				ReQuery();
			} catch (Exception e) { ExceptionMessage(e); }
		}

		void EditData(int rowId, int columnId)
		{
			if (modeAdd) return;
			try
			{
				string table = GetCurrTable();
				string param = GetParamName(columnId);
				string value = GetValue(rowId, columnId);
				string idname = GetIdName();
				string id = GetId(rowId);
				string sql = string.Format("UPDATE {0} SET [{1}] = '{2}' WHERE [{3}] = {4};", table, param, value, idname, id);
				Query(sql);
				ReQuery();
			} catch (Exception e) { ExceptionMessage(e); }
		}
		
		int GetMaxId()
		{
			if (dgvMain.Rows.Count - 1 < 1)
				return 0;

			string idname = dgvMain.Columns[0].Name;
			string exp = string.Format("[{0}] = MAX([{0}])", idname);
			return Convert.ToInt32(dbProxy.DbTable.Select(exp)[0][0]);
		}
		
		string GetParamName(int columnId)			{ return dgvMain.Columns[columnId].Name; }
		string GetValue(int rowId, int columnId)	{ return dgvMain.Rows[rowId].Cells[columnId].Value.ToString(); }
		string GetIdName()							{ return dgvMain.Columns[0].Name; }
		string GetId(int rowId)						{ return dgvMain.Rows[rowId].Cells[0].Value.ToString(); }

		DBProxy dbProxy;
		bool modeAdd = false;
		
		// --------------------------------------------------------------------------------------------------------------
		// Запросы
		// --------------------------------------------------------------------------------------------------------------
		void QueryServChr()
		{
			Query("SELECT Код_компьютера, Модель_CPU, Частота, Количество_ядер, Архитектура, Тип_ОС, Редакция_ОС, Версия_ОС, ОЗУ " +
			      "FROM Компьютеры AS C, Процессоры AS P, ОС AS O " +
			      "WHERE C.Код_процессора=P.Код_процессора AND C.Код_ОС=O.Код_ОС " +
			      "ORDER BY Код_компьютера");
		}
		
		void QueryWorkingSrv()
		{
			Query("SELECT Код_компьютера, Модель_CPU, Тип_ОС, Редакция_ОС, ОЗУ " +
			      "FROM Компьютеры AS C, Процессоры AS P, ОС AS O " +
			      "WHERE C.Код_процессора=P.Код_процессора AND C.Код_ОС=O.Код_ОС AND Работает=True " +
			      "ORDER BY Код_компьютера");
		}
		
		void QueryContracts()
		{
			Query("SELECT Код_контракта, ФИО, Название_тарифа, Код_компьютера, Домен, Дата_подписания, Цена " +
			      "FROM Контракты AS K, Клиенты AS C, Тарифы AS T, Домены AS D " +
			      "WHERE K.Код_тарифа=T.Код_тарифа AND K.Код_клиента=C.Код_клиента AND K.Код_домена=D.Код_домена " +
			      "ORDER BY ФИО");
		}
		
		void QueryNotPaid()
		{
			Query("SELECT O.Код_контракта, ФИО, Название_тарифа, Дата_оплаты, " +
			      "(NOW()-CDATE(Дата_оплаты))-(Оплачено_за*Длительность) AS Просрочено_дней " +
			      "FROM Контракты AS K, Оплата AS O, Тарифы AS T, Клиенты AS C " +
			      "WHERE K.Код_тарифа=T.Код_тарифа AND K.Код_клиента=C.Код_клиента AND K.Код_контракта=O.Код_контракта " +
			      "AND (NOW()-CDATE(Дата_оплаты))-(Оплачено_за*Длительность) > 0;");
		}
		
		// --------------------------------------------------------------------------------------------------------------
		// Отчёты
		// --------------------------------------------------------------------------------------------------------------
		void MakeChecks()
		{
			Query("SELECT ФИО, Название_тарифа, Цена, Длительность " +
			      "(NOW()-CDATE(Дата_оплаты))-(Оплачено_за*Длительность) AS Просрочено_дней " +
			      "FROM Контракты AS K, Клиенты AS C, Тарифы AS T " +
			      "WHERE K.Код_тарифа=T.Код_тарифа AND K.Код_клиента=C.Код_клиента");
			WriteFile("Квитанции на оплату");
		}
		
		void MakeAccounts()
		{
			Query("SELECT EMail, Логин, Пароль FROM Клиенты");
			WriteFile("Аккаунты");
		}
		
		void WriteFile(string title)
		{
			try
			{
				var dlg = new SaveFileDialog();
				dlg.DefaultExt = "html";
				dlg.AddExtension = true;
				if (dlg.ShowDialog() != DialogResult.OK)
					return;
				
				var sw = new StreamWriter(dlg.FileName);
				
				sw.WriteLine("<html>");
				sw.WriteLine(string.Format("<head><title>{0}</title></head>", title));
				sw.WriteLine("<table>");
				sw.WriteLine("<tr>");
				foreach (DataGridViewColumn column in dgvQuery.Columns)
					sw.WriteLine(string.Format("<th>{0}</th>", column.Name));
				sw.WriteLine("</tr>");
				foreach (DataGridViewRow row in dgvQuery.Rows)
				{
					sw.WriteLine("<tr>");
					foreach (DataGridViewCell cell in row.Cells)
						sw.WriteLine(string.Format("<td>{0}</td>", cell.Value.ToString()));
					sw.WriteLine("</tr>");
				}
				sw.WriteLine("</table>");
				sw.WriteLine("</html>");
				
				sw.Close();
			} catch (Exception e) { ExceptionMessage(e); }
		}
		
		// --------------------------------------------------------------------------------------------------------------
		// Автоматизация
		// --------------------------------------------------------------------------------------------------------------
		void ClearNotPaid()
		{
			if (dgvAuto.Rows.Count - 1 < 1) return;
			
			if (MessageBox.Show(string.Format("Вы уверены, что хотите удалить эти {0} строк?", dgvMain.SelectedRows.Count),
			                    "Подтверждение удаления",
			                    MessageBoxButtons.YesNo,
			                    MessageBoxIcon.Question) != DialogResult.Yes)
				return;
		
			try
			{	
				var sqllist = new List<string>(dgvAuto.Rows.Count);
				foreach (DataGridViewRow row in dgvAuto.Rows)
					sqllist.Add(string.Format("DELETE FROM {0} WHERE [{1}]={2};", "Контракты", "Код_контракта", row.Cells[0].Value.ToString()));
				foreach (string sql in sqllist)
					Query(sql);
				ReQuery();
			}  catch (Exception e) { ExceptionMessage(e); }
		}
		
		// --------------------------------------------------------------------------------------------------------------
		// События
		// --------------------------------------------------------------------------------------------------------------
		// Глобальные события
		void TabMainSelectedIndexChanged(object sender, EventArgs e)		{ UpdateDataSources(); }
		void MainFormLoad(object sender, EventArgs e)						{ LoadTable(); }
		void CmbTableSelectedIndexChanged(object sender, EventArgs e)		{ ReQuery(); }
		void ListTablesSelectedIndexChanged(object sender, EventArgs e)		{ ReQuery(); }
		// Режим запросов SQL
		void ChkSQLCheckedChanged(object sender, EventArgs e)				{ SetSqlMode(); }
		void BtnDoSqlClick(object sender, EventArgs e)						{ ReQuery(false); }
		void BtnClearSqlClick(object sender, EventArgs e)					{ SetDefaultQuery(); ReQuery(); }
		// Редактирование данных
		void DgvMainCellEndEdit(object sender, DataGridViewCellEventArgs e)	{ EditData(e.RowIndex, e.ColumnIndex); }
		void BtnAddClick(object sender, EventArgs e)						{ AddData(); }
		void BtnDeleteClick(object sender, EventArgs e)						{ RemoveData(); }
		// Запросы
		void BtnSrvChrClick(object sender, EventArgs e)						{ QueryServChr(); }
		void BtnWorkingSrvClick(object sender, EventArgs e)					{ QueryWorkingSrv(); }
		void BtnClContractsClick(object sender, EventArgs e)				{ QueryContracts(); }
		void BtnNotPaidClick(object sender, EventArgs e)					{ QueryNotPaid(); }
		// Отчёты
		void BtnChecksClick(object sender, EventArgs e)						{ MakeChecks(); }
		void BtnAccountsClick(object sender, EventArgs e)					{ MakeAccounts(); }
		// Автоматизация
		void BtnCalcMinusClick(object sender, EventArgs e)					{ QueryNotPaid(); }
		void BtnClearMinusClick(object sender, EventArgs e)					{ ClearNotPaid(); }
	}
}
