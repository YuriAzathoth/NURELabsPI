/*
 * Создано в SharpDevelop.
 * Пользователь: Yuri Zinchenko
 * Дата: 06.12.2018
 * Время: 15:03
*/
namespace HostingDB
{
	partial class MainForm
	{
		/// <summary>
		/// Designer variable used to keep track of non-visual components.
		/// </summary>
		private System.ComponentModel.IContainer components = null;
		private System.Windows.Forms.BindingSource bsrcMain;
		private System.Windows.Forms.DataGridView dgvMain;
		private System.Windows.Forms.TabControl tabMain;
		private System.Windows.Forms.TabPage tabTables;
		private System.Windows.Forms.Label label1;
		private System.Windows.Forms.TabPage tabQuery;
		private System.Windows.Forms.CheckBox chkSQL;
		private System.Windows.Forms.Button btnClearSql;
		private System.Windows.Forms.Button btnDoSql;
		private System.Windows.Forms.RichTextBox txtSQL;
		private System.Windows.Forms.Button btnAdd;
		private System.Windows.Forms.Button btnDelete;
		private System.Windows.Forms.ListBox listTables;
		private System.Windows.Forms.TabPage tabAuto;
		private System.Windows.Forms.DataGridView dgvQuery;
		private System.Windows.Forms.BindingSource bsrcQuery;
		private System.Windows.Forms.Button btnSrvChr;
		private System.Windows.Forms.Button btnWorkingSrv;
		private System.Windows.Forms.Button btnClContracts;
		private System.Windows.Forms.GroupBox groupBox2;
		private System.Windows.Forms.GroupBox groupBox1;
		private System.Windows.Forms.Button btnAccounts;
		private System.Windows.Forms.Button btnChecks;
		private System.Windows.Forms.Button btnNotPaid;
		private System.Windows.Forms.Button btnClearMinus;
		private System.Windows.Forms.Button btnCalcMinus;
		private System.Windows.Forms.DataGridView dgvAuto;
		private System.Windows.Forms.BindingSource bsrcAuto;
		
		/// <summary>
		/// Disposes resources used by the form.
		/// </summary>
		/// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
		protected override void Dispose(bool disposing)
		{
			if (disposing) {
				if (components != null) {
					components.Dispose();
				}
			}
			base.Dispose(disposing);
		}
		
		/// <summary>
		/// This method is required for Windows Forms designer support.
		/// Do not change the method contents inside the source code editor. The Forms designer might
		/// not be able to load this method if it was changed manually.
		/// </summary>
		private void InitializeComponent()
		{
			this.components = new System.ComponentModel.Container();
			this.bsrcMain = new System.Windows.Forms.BindingSource(this.components);
			this.dgvMain = new System.Windows.Forms.DataGridView();
			this.tabMain = new System.Windows.Forms.TabControl();
			this.tabTables = new System.Windows.Forms.TabPage();
			this.listTables = new System.Windows.Forms.ListBox();
			this.btnDelete = new System.Windows.Forms.Button();
			this.btnAdd = new System.Windows.Forms.Button();
			this.btnClearSql = new System.Windows.Forms.Button();
			this.btnDoSql = new System.Windows.Forms.Button();
			this.txtSQL = new System.Windows.Forms.RichTextBox();
			this.chkSQL = new System.Windows.Forms.CheckBox();
			this.label1 = new System.Windows.Forms.Label();
			this.tabQuery = new System.Windows.Forms.TabPage();
			this.groupBox2 = new System.Windows.Forms.GroupBox();
			this.btnNotPaid = new System.Windows.Forms.Button();
			this.btnSrvChr = new System.Windows.Forms.Button();
			this.btnWorkingSrv = new System.Windows.Forms.Button();
			this.btnClContracts = new System.Windows.Forms.Button();
			this.groupBox1 = new System.Windows.Forms.GroupBox();
			this.btnAccounts = new System.Windows.Forms.Button();
			this.btnChecks = new System.Windows.Forms.Button();
			this.dgvQuery = new System.Windows.Forms.DataGridView();
			this.bsrcQuery = new System.Windows.Forms.BindingSource(this.components);
			this.tabAuto = new System.Windows.Forms.TabPage();
			this.btnCalcMinus = new System.Windows.Forms.Button();
			this.dgvAuto = new System.Windows.Forms.DataGridView();
			this.bsrcAuto = new System.Windows.Forms.BindingSource(this.components);
			this.btnClearMinus = new System.Windows.Forms.Button();
			((System.ComponentModel.ISupportInitialize)(this.bsrcMain)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.dgvMain)).BeginInit();
			this.tabMain.SuspendLayout();
			this.tabTables.SuspendLayout();
			this.tabQuery.SuspendLayout();
			this.groupBox2.SuspendLayout();
			this.groupBox1.SuspendLayout();
			((System.ComponentModel.ISupportInitialize)(this.dgvQuery)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.bsrcQuery)).BeginInit();
			this.tabAuto.SuspendLayout();
			((System.ComponentModel.ISupportInitialize)(this.dgvAuto)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.bsrcAuto)).BeginInit();
			this.SuspendLayout();
			// 
			// dgvMain
			// 
			this.dgvMain.AllowUserToAddRows = false;
			this.dgvMain.AllowUserToDeleteRows = false;
			this.dgvMain.AutoGenerateColumns = false;
			this.dgvMain.AutoSizeColumnsMode = System.Windows.Forms.DataGridViewAutoSizeColumnsMode.AllCells;
			this.dgvMain.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
			this.dgvMain.DataSource = this.bsrcMain;
			this.dgvMain.Location = new System.Drawing.Point(6, 33);
			this.dgvMain.Name = "dgvMain";
			this.dgvMain.Size = new System.Drawing.Size(811, 473);
			this.dgvMain.TabIndex = 0;
			this.dgvMain.CellEndEdit += new System.Windows.Forms.DataGridViewCellEventHandler(this.DgvMainCellEndEdit);
			// 
			// tabMain
			// 
			this.tabMain.Controls.Add(this.tabTables);
			this.tabMain.Controls.Add(this.tabQuery);
			this.tabMain.Controls.Add(this.tabAuto);
			this.tabMain.Location = new System.Drawing.Point(12, 12);
			this.tabMain.Name = "tabMain";
			this.tabMain.SelectedIndex = 0;
			this.tabMain.Size = new System.Drawing.Size(960, 538);
			this.tabMain.TabIndex = 1;
			this.tabMain.SelectedIndexChanged += new System.EventHandler(this.TabMainSelectedIndexChanged);
			// 
			// tabTables
			// 
			this.tabTables.Controls.Add(this.listTables);
			this.tabTables.Controls.Add(this.btnDelete);
			this.tabTables.Controls.Add(this.btnAdd);
			this.tabTables.Controls.Add(this.btnClearSql);
			this.tabTables.Controls.Add(this.btnDoSql);
			this.tabTables.Controls.Add(this.txtSQL);
			this.tabTables.Controls.Add(this.chkSQL);
			this.tabTables.Controls.Add(this.label1);
			this.tabTables.Controls.Add(this.dgvMain);
			this.tabTables.Location = new System.Drawing.Point(4, 22);
			this.tabTables.Name = "tabTables";
			this.tabTables.Padding = new System.Windows.Forms.Padding(3);
			this.tabTables.Size = new System.Drawing.Size(952, 512);
			this.tabTables.TabIndex = 0;
			this.tabTables.Text = "Таблицы";
			this.tabTables.UseVisualStyleBackColor = true;
			// 
			// listTables
			// 
			this.listTables.FormattingEnabled = true;
			this.listTables.Location = new System.Drawing.Point(823, 54);
			this.listTables.Name = "listTables";
			this.listTables.Size = new System.Drawing.Size(123, 147);
			this.listTables.TabIndex = 9;
			this.listTables.SelectedIndexChanged += new System.EventHandler(this.ListTablesSelectedIndexChanged);
			// 
			// btnDelete
			// 
			this.btnDelete.Location = new System.Drawing.Point(296, 4);
			this.btnDelete.Name = "btnDelete";
			this.btnDelete.Size = new System.Drawing.Size(93, 23);
			this.btnDelete.TabIndex = 8;
			this.btnDelete.Text = "Удалить";
			this.btnDelete.UseVisualStyleBackColor = true;
			this.btnDelete.Click += new System.EventHandler(this.BtnDeleteClick);
			// 
			// btnAdd
			// 
			this.btnAdd.Location = new System.Drawing.Point(197, 4);
			this.btnAdd.Name = "btnAdd";
			this.btnAdd.Size = new System.Drawing.Size(93, 23);
			this.btnAdd.TabIndex = 7;
			this.btnAdd.Text = "Добавить";
			this.btnAdd.UseVisualStyleBackColor = true;
			this.btnAdd.Click += new System.EventHandler(this.BtnAddClick);
			// 
			// btnClearSql
			// 
			this.btnClearSql.Location = new System.Drawing.Point(724, 62);
			this.btnClearSql.Name = "btnClearSql";
			this.btnClearSql.Size = new System.Drawing.Size(93, 23);
			this.btnClearSql.TabIndex = 6;
			this.btnClearSql.Text = "Очистить";
			this.btnClearSql.UseVisualStyleBackColor = true;
			this.btnClearSql.Visible = false;
			this.btnClearSql.Click += new System.EventHandler(this.BtnClearSqlClick);
			// 
			// btnDoSql
			// 
			this.btnDoSql.Location = new System.Drawing.Point(724, 33);
			this.btnDoSql.Name = "btnDoSql";
			this.btnDoSql.Size = new System.Drawing.Size(93, 23);
			this.btnDoSql.TabIndex = 5;
			this.btnDoSql.Text = "Выполнить";
			this.btnDoSql.UseVisualStyleBackColor = true;
			this.btnDoSql.Visible = false;
			this.btnDoSql.Click += new System.EventHandler(this.BtnDoSqlClick);
			// 
			// txtSQL
			// 
			this.txtSQL.Location = new System.Drawing.Point(6, 33);
			this.txtSQL.Name = "txtSQL";
			this.txtSQL.Size = new System.Drawing.Size(712, 52);
			this.txtSQL.TabIndex = 4;
			this.txtSQL.Text = "";
			this.txtSQL.Visible = false;
			// 
			// chkSQL
			// 
			this.chkSQL.Location = new System.Drawing.Point(6, 6);
			this.chkSQL.Name = "chkSQL";
			this.chkSQL.Size = new System.Drawing.Size(87, 21);
			this.chkSQL.TabIndex = 3;
			this.chkSQL.Text = "SQL запрос";
			this.chkSQL.UseVisualStyleBackColor = true;
			this.chkSQL.CheckedChanged += new System.EventHandler(this.ChkSQLCheckedChanged);
			// 
			// label1
			// 
			this.label1.Location = new System.Drawing.Point(823, 36);
			this.label1.Name = "label1";
			this.label1.Size = new System.Drawing.Size(56, 15);
			this.label1.TabIndex = 2;
			this.label1.Text = "Таблицы";
			// 
			// tabQuery
			// 
			this.tabQuery.Controls.Add(this.groupBox2);
			this.tabQuery.Controls.Add(this.groupBox1);
			this.tabQuery.Controls.Add(this.dgvQuery);
			this.tabQuery.Location = new System.Drawing.Point(4, 22);
			this.tabQuery.Name = "tabQuery";
			this.tabQuery.Size = new System.Drawing.Size(952, 512);
			this.tabQuery.TabIndex = 2;
			this.tabQuery.Text = "Запросы и отчёты";
			this.tabQuery.UseVisualStyleBackColor = true;
			// 
			// groupBox2
			// 
			this.groupBox2.Controls.Add(this.btnNotPaid);
			this.groupBox2.Controls.Add(this.btnSrvChr);
			this.groupBox2.Controls.Add(this.btnWorkingSrv);
			this.groupBox2.Controls.Add(this.btnClContracts);
			this.groupBox2.Location = new System.Drawing.Point(3, 3);
			this.groupBox2.Name = "groupBox2";
			this.groupBox2.Size = new System.Drawing.Size(614, 63);
			this.groupBox2.TabIndex = 7;
			this.groupBox2.TabStop = false;
			this.groupBox2.Text = "Запросы";
			// 
			// btnNotPaid
			// 
			this.btnNotPaid.Location = new System.Drawing.Point(474, 19);
			this.btnNotPaid.Name = "btnNotPaid";
			this.btnNotPaid.Size = new System.Drawing.Size(134, 38);
			this.btnNotPaid.TabIndex = 6;
			this.btnNotPaid.Text = "Неуплачено";
			this.btnNotPaid.UseVisualStyleBackColor = true;
			this.btnNotPaid.Click += new System.EventHandler(this.BtnNotPaidClick);
			// 
			// btnSrvChr
			// 
			this.btnSrvChr.Location = new System.Drawing.Point(6, 19);
			this.btnSrvChr.Name = "btnSrvChr";
			this.btnSrvChr.Size = new System.Drawing.Size(150, 38);
			this.btnSrvChr.TabIndex = 3;
			this.btnSrvChr.Text = "Хар-ка серверов";
			this.btnSrvChr.UseVisualStyleBackColor = true;
			this.btnSrvChr.Click += new System.EventHandler(this.BtnSrvChrClick);
			// 
			// btnWorkingSrv
			// 
			this.btnWorkingSrv.Location = new System.Drawing.Point(162, 19);
			this.btnWorkingSrv.Name = "btnWorkingSrv";
			this.btnWorkingSrv.Size = new System.Drawing.Size(150, 38);
			this.btnWorkingSrv.TabIndex = 4;
			this.btnWorkingSrv.Text = "Работающие сервера";
			this.btnWorkingSrv.UseVisualStyleBackColor = true;
			this.btnWorkingSrv.Click += new System.EventHandler(this.BtnWorkingSrvClick);
			// 
			// btnClContracts
			// 
			this.btnClContracts.Location = new System.Drawing.Point(318, 19);
			this.btnClContracts.Name = "btnClContracts";
			this.btnClContracts.Size = new System.Drawing.Size(150, 38);
			this.btnClContracts.TabIndex = 5;
			this.btnClContracts.Text = "Договора с клиентами";
			this.btnClContracts.UseVisualStyleBackColor = true;
			this.btnClContracts.Click += new System.EventHandler(this.BtnClContractsClick);
			// 
			// groupBox1
			// 
			this.groupBox1.Controls.Add(this.btnAccounts);
			this.groupBox1.Controls.Add(this.btnChecks);
			this.groupBox1.Location = new System.Drawing.Point(623, 3);
			this.groupBox1.Name = "groupBox1";
			this.groupBox1.Size = new System.Drawing.Size(326, 63);
			this.groupBox1.TabIndex = 6;
			this.groupBox1.TabStop = false;
			this.groupBox1.Text = "Отчёты";
			// 
			// btnAccounts
			// 
			this.btnAccounts.Location = new System.Drawing.Point(170, 19);
			this.btnAccounts.Name = "btnAccounts";
			this.btnAccounts.Size = new System.Drawing.Size(150, 38);
			this.btnAccounts.TabIndex = 5;
			this.btnAccounts.Text = "Аккаунты";
			this.btnAccounts.UseVisualStyleBackColor = true;
			this.btnAccounts.Click += new System.EventHandler(this.BtnAccountsClick);
			// 
			// btnChecks
			// 
			this.btnChecks.Location = new System.Drawing.Point(6, 19);
			this.btnChecks.Name = "btnChecks";
			this.btnChecks.Size = new System.Drawing.Size(158, 38);
			this.btnChecks.TabIndex = 4;
			this.btnChecks.Text = "Квитанции";
			this.btnChecks.UseVisualStyleBackColor = true;
			this.btnChecks.Click += new System.EventHandler(this.BtnChecksClick);
			// 
			// dgvQuery
			// 
			this.dgvQuery.AllowUserToAddRows = false;
			this.dgvQuery.AllowUserToDeleteRows = false;
			this.dgvQuery.AllowUserToResizeColumns = false;
			this.dgvQuery.AllowUserToResizeRows = false;
			this.dgvQuery.AutoGenerateColumns = false;
			this.dgvQuery.AutoSizeColumnsMode = System.Windows.Forms.DataGridViewAutoSizeColumnsMode.AllCells;
			this.dgvQuery.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
			this.dgvQuery.DataSource = this.bsrcQuery;
			this.dgvQuery.Location = new System.Drawing.Point(3, 72);
			this.dgvQuery.MultiSelect = false;
			this.dgvQuery.Name = "dgvQuery";
			this.dgvQuery.ReadOnly = true;
			this.dgvQuery.Size = new System.Drawing.Size(946, 437);
			this.dgvQuery.TabIndex = 1;
			// 
			// tabAuto
			// 
			this.tabAuto.Controls.Add(this.btnCalcMinus);
			this.tabAuto.Controls.Add(this.dgvAuto);
			this.tabAuto.Controls.Add(this.btnClearMinus);
			this.tabAuto.Location = new System.Drawing.Point(4, 22);
			this.tabAuto.Name = "tabAuto";
			this.tabAuto.Size = new System.Drawing.Size(952, 512);
			this.tabAuto.TabIndex = 4;
			this.tabAuto.Text = "Автоматизация";
			this.tabAuto.UseVisualStyleBackColor = true;
			// 
			// btnCalcMinus
			// 
			this.btnCalcMinus.Location = new System.Drawing.Point(3, 0);
			this.btnCalcMinus.Name = "btnCalcMinus";
			this.btnCalcMinus.Size = new System.Drawing.Size(258, 47);
			this.btnCalcMinus.TabIndex = 2;
			this.btnCalcMinus.Text = "Вычислить всех просрочивщих платёж";
			this.btnCalcMinus.UseVisualStyleBackColor = true;
			this.btnCalcMinus.Click += new System.EventHandler(this.BtnCalcMinusClick);
			// 
			// dgvAuto
			// 
			this.dgvAuto.AllowUserToAddRows = false;
			this.dgvAuto.AllowUserToDeleteRows = false;
			this.dgvAuto.AutoGenerateColumns = false;
			this.dgvAuto.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
			this.dgvAuto.DataSource = this.bsrcAuto;
			this.dgvAuto.Location = new System.Drawing.Point(3, 106);
			this.dgvAuto.Name = "dgvAuto";
			this.dgvAuto.ReadOnly = true;
			this.dgvAuto.Size = new System.Drawing.Size(946, 403);
			this.dgvAuto.TabIndex = 1;
			// 
			// btnClearMinus
			// 
			this.btnClearMinus.Location = new System.Drawing.Point(3, 53);
			this.btnClearMinus.Name = "btnClearMinus";
			this.btnClearMinus.Size = new System.Drawing.Size(258, 47);
			this.btnClearMinus.TabIndex = 0;
			this.btnClearMinus.Text = "Удалить всех просрочивщих платёж";
			this.btnClearMinus.UseVisualStyleBackColor = true;
			this.btnClearMinus.Click += new System.EventHandler(this.BtnClearMinusClick);
			// 
			// MainForm
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(984, 562);
			this.Controls.Add(this.tabMain);
			this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
			this.MaximizeBox = false;
			this.Name = "MainForm";
			this.Text = "HostingDB";
			this.Load += new System.EventHandler(this.MainFormLoad);
			((System.ComponentModel.ISupportInitialize)(this.bsrcMain)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.dgvMain)).EndInit();
			this.tabMain.ResumeLayout(false);
			this.tabTables.ResumeLayout(false);
			this.tabQuery.ResumeLayout(false);
			this.groupBox2.ResumeLayout(false);
			this.groupBox1.ResumeLayout(false);
			((System.ComponentModel.ISupportInitialize)(this.dgvQuery)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.bsrcQuery)).EndInit();
			this.tabAuto.ResumeLayout(false);
			((System.ComponentModel.ISupportInitialize)(this.dgvAuto)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.bsrcAuto)).EndInit();
			this.ResumeLayout(false);

		}
	}
}	