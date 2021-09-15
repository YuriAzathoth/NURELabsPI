namespace Hostel
{
    partial class MainForm
    {
        /// <summary>
        /// Обязательная переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
        	this.components = new System.ComponentModel.Container();
        	System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(MainForm));
        	this.dataGridView = new System.Windows.Forms.DataGridView();
        	this.комнатыDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
        	this.стоимостьDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
        	this.количествоDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
        	this.инвентарьDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
        	this.этажDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
        	this.комнатыBindingSource = new System.Windows.Forms.BindingSource(this.components);
        	this.bindingSource = new System.Windows.Forms.BindingSource(this.components);
        	this.lab01DataSet = new Hostel.Lab01DataSet();
        	this.студентыBindingSource = new System.Windows.Forms.BindingSource(this.components);
        	this.льготыBindingSource = new System.Windows.Forms.BindingSource(this.components);
        	this.menuStrip1 = new System.Windows.Forms.MenuStrip();
        	this.fileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
        	this.exitToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
        	this.editToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
        	this.addToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
        	this.updateToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
        	this.deleteToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
        	this.viewToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
        	this.resettlementToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
        	this.databaseToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
        	this.roomsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
        	this.studentsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
        	this.benefitsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
        	this.queryEditToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
        	this.bindingNavigator = new System.Windows.Forms.BindingNavigator(this.components);
        	this.bindingNavigatorAddNewItem = new System.Windows.Forms.ToolStripButton();
        	this.bindingNavigatorCountItem = new System.Windows.Forms.ToolStripLabel();
        	this.bindingNavigatorDeleteItem = new System.Windows.Forms.ToolStripButton();
        	this.bindingNavigatorMoveFirstItem = new System.Windows.Forms.ToolStripButton();
        	this.bindingNavigatorMovePreviousItem = new System.Windows.Forms.ToolStripButton();
        	this.bindingNavigatorSeparator = new System.Windows.Forms.ToolStripSeparator();
        	this.bindingNavigatorPositionItem = new System.Windows.Forms.ToolStripTextBox();
        	this.bindingNavigatorSeparator1 = new System.Windows.Forms.ToolStripSeparator();
        	this.bindingNavigatorMoveNextItem = new System.Windows.Forms.ToolStripButton();
        	this.bindingNavigatorMoveLastItem = new System.Windows.Forms.ToolStripButton();
        	this.bindingNavigatorSeparator2 = new System.Windows.Forms.ToolStripSeparator();
        	this.комнатыTableAdapter = new Hostel.Lab01DataSetTableAdapters.КомнатыTableAdapter();
        	this.студентыTableAdapter = new Hostel.Lab01DataSetTableAdapters.СтудентыTableAdapter();
        	this.льготыTableAdapter = new Hostel.Lab01DataSetTableAdapters.ЛьготыTableAdapter();
        	this.labelTable = new System.Windows.Forms.Label();
        	this.editQueryToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
        	((System.ComponentModel.ISupportInitialize)(this.dataGridView)).BeginInit();
        	((System.ComponentModel.ISupportInitialize)(this.комнатыBindingSource)).BeginInit();
        	((System.ComponentModel.ISupportInitialize)(this.bindingSource)).BeginInit();
        	((System.ComponentModel.ISupportInitialize)(this.lab01DataSet)).BeginInit();
        	((System.ComponentModel.ISupportInitialize)(this.студентыBindingSource)).BeginInit();
        	((System.ComponentModel.ISupportInitialize)(this.льготыBindingSource)).BeginInit();
        	this.menuStrip1.SuspendLayout();
        	((System.ComponentModel.ISupportInitialize)(this.bindingNavigator)).BeginInit();
        	this.bindingNavigator.SuspendLayout();
        	this.SuspendLayout();
        	// 
        	// dataGridView
        	// 
        	this.dataGridView.AutoGenerateColumns = false;
        	this.dataGridView.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
        	this.dataGridView.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
			this.комнатыDataGridViewTextBoxColumn,
			this.стоимостьDataGridViewTextBoxColumn,
			this.количествоDataGridViewTextBoxColumn,
			this.инвентарьDataGridViewTextBoxColumn,
			this.этажDataGridViewTextBoxColumn});
        	this.dataGridView.DataSource = this.комнатыBindingSource;
        	this.dataGridView.Location = new System.Drawing.Point(12, 63);
        	this.dataGridView.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
        	this.dataGridView.Name = "dataGridView";
        	this.dataGridView.Size = new System.Drawing.Size(881, 532);
        	this.dataGridView.TabIndex = 0;
        	// 
        	// комнатыDataGridViewTextBoxColumn
        	// 
        	this.комнатыDataGridViewTextBoxColumn.DataPropertyName = "№ комнаты";
        	this.комнатыDataGridViewTextBoxColumn.HeaderText = "№ комнаты";
        	this.комнатыDataGridViewTextBoxColumn.Name = "комнатыDataGridViewTextBoxColumn";
        	// 
        	// стоимостьDataGridViewTextBoxColumn
        	// 
        	this.стоимостьDataGridViewTextBoxColumn.DataPropertyName = "Стоимость";
        	this.стоимостьDataGridViewTextBoxColumn.HeaderText = "Стоимость";
        	this.стоимостьDataGridViewTextBoxColumn.Name = "стоимостьDataGridViewTextBoxColumn";
        	// 
        	// количествоDataGridViewTextBoxColumn
        	// 
        	this.количествоDataGridViewTextBoxColumn.DataPropertyName = "Количество";
        	this.количествоDataGridViewTextBoxColumn.HeaderText = "Количество";
        	this.количествоDataGridViewTextBoxColumn.Name = "количествоDataGridViewTextBoxColumn";
        	// 
        	// инвентарьDataGridViewTextBoxColumn
        	// 
        	this.инвентарьDataGridViewTextBoxColumn.DataPropertyName = "Инвентарь";
        	this.инвентарьDataGridViewTextBoxColumn.HeaderText = "Инвентарь";
        	this.инвентарьDataGridViewTextBoxColumn.Name = "инвентарьDataGridViewTextBoxColumn";
        	// 
        	// этажDataGridViewTextBoxColumn
        	// 
        	this.этажDataGridViewTextBoxColumn.DataPropertyName = "Этаж";
        	this.этажDataGridViewTextBoxColumn.HeaderText = "Этаж";
        	this.этажDataGridViewTextBoxColumn.Name = "этажDataGridViewTextBoxColumn";
        	// 
        	// комнатыBindingSource
        	// 
        	this.комнатыBindingSource.DataMember = "Комнаты";
        	this.комнатыBindingSource.DataSource = this.bindingSource;
        	// 
        	// bindingSource
        	// 
        	this.bindingSource.DataSource = this.lab01DataSet;
        	this.bindingSource.Position = 0;
        	// 
        	// lab01DataSet
        	// 
        	this.lab01DataSet.DataSetName = "Lab01DataSet";
        	this.lab01DataSet.Namespace = "http://tempuri.org/Lab01DataSet.xsd";
        	this.lab01DataSet.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
        	// 
        	// студентыBindingSource
        	// 
        	this.студентыBindingSource.DataMember = "Студенты";
        	this.студентыBindingSource.DataSource = this.bindingSource;
        	// 
        	// льготыBindingSource
        	// 
        	this.льготыBindingSource.DataMember = "Льготы";
        	this.льготыBindingSource.DataSource = this.bindingSource;
        	// 
        	// menuStrip1
        	// 
        	this.menuStrip1.ImageScalingSize = new System.Drawing.Size(24, 24);
        	this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
			this.fileToolStripMenuItem,
			this.editToolStripMenuItem,
			this.viewToolStripMenuItem,
			this.databaseToolStripMenuItem});
        	this.menuStrip1.Location = new System.Drawing.Point(0, 0);
        	this.menuStrip1.Name = "menuStrip1";
        	this.menuStrip1.Padding = new System.Windows.Forms.Padding(9, 3, 0, 3);
        	this.menuStrip1.Size = new System.Drawing.Size(906, 35);
        	this.menuStrip1.TabIndex = 3;
        	this.menuStrip1.Text = "menuStrip1";
        	// 
        	// fileToolStripMenuItem
        	// 
        	this.fileToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
			this.exitToolStripMenuItem});
        	this.fileToolStripMenuItem.Name = "fileToolStripMenuItem";
        	this.fileToolStripMenuItem.Size = new System.Drawing.Size(50, 29);
        	this.fileToolStripMenuItem.Text = "&File";
        	// 
        	// exitToolStripMenuItem
        	// 
        	this.exitToolStripMenuItem.Name = "exitToolStripMenuItem";
        	this.exitToolStripMenuItem.Size = new System.Drawing.Size(123, 30);
        	this.exitToolStripMenuItem.Text = "E&xit";
        	this.exitToolStripMenuItem.Click += new System.EventHandler(this.exitToolStripMenuItem_Click);
        	// 
        	// editToolStripMenuItem
        	// 
        	this.editToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
			this.addToolStripMenuItem,
			this.updateToolStripMenuItem,
			this.deleteToolStripMenuItem});
        	this.editToolStripMenuItem.Name = "editToolStripMenuItem";
        	this.editToolStripMenuItem.Size = new System.Drawing.Size(54, 29);
        	this.editToolStripMenuItem.Text = "&Edit";
        	// 
        	// addToolStripMenuItem
        	// 
        	this.addToolStripMenuItem.Name = "addToolStripMenuItem";
        	this.addToolStripMenuItem.Size = new System.Drawing.Size(154, 30);
        	this.addToolStripMenuItem.Text = "&Add";
        	this.addToolStripMenuItem.Click += new System.EventHandler(this.AddToolStripMenuItemClick);
        	// 
        	// updateToolStripMenuItem
        	// 
        	this.updateToolStripMenuItem.Name = "updateToolStripMenuItem";
        	this.updateToolStripMenuItem.Size = new System.Drawing.Size(154, 30);
        	this.updateToolStripMenuItem.Text = "&Update";
        	this.updateToolStripMenuItem.Click += new System.EventHandler(this.UpdateToolStripMenuItemClick);
        	// 
        	// deleteToolStripMenuItem
        	// 
        	this.deleteToolStripMenuItem.Name = "deleteToolStripMenuItem";
        	this.deleteToolStripMenuItem.Size = new System.Drawing.Size(154, 30);
        	this.deleteToolStripMenuItem.Text = "&Delete";
        	this.deleteToolStripMenuItem.Click += new System.EventHandler(this.DeleteToolStripMenuItemClick);
        	// 
        	// viewToolStripMenuItem
        	// 
        	this.viewToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
			this.resettlementToolStripMenuItem,
			this.editQueryToolStripMenuItem});
        	this.viewToolStripMenuItem.Name = "viewToolStripMenuItem";
        	this.viewToolStripMenuItem.Size = new System.Drawing.Size(61, 29);
        	this.viewToolStripMenuItem.Text = "&View";
        	// 
        	// resettlementToolStripMenuItem
        	// 
        	this.resettlementToolStripMenuItem.Name = "resettlementToolStripMenuItem";
        	this.resettlementToolStripMenuItem.Size = new System.Drawing.Size(210, 30);
        	this.resettlementToolStripMenuItem.Text = "&Resettlement";
        	this.resettlementToolStripMenuItem.Click += new System.EventHandler(this.ResettlementToolStripMenuItemClick);
        	// 
        	// databaseToolStripMenuItem
        	// 
        	this.databaseToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
			this.roomsToolStripMenuItem,
			this.studentsToolStripMenuItem,
			this.benefitsToolStripMenuItem});
        	this.databaseToolStripMenuItem.Name = "databaseToolStripMenuItem";
        	this.databaseToolStripMenuItem.Size = new System.Drawing.Size(98, 29);
        	this.databaseToolStripMenuItem.Text = "&Database";
        	// 
        	// roomsToolStripMenuItem
        	// 
        	this.roomsToolStripMenuItem.Name = "roomsToolStripMenuItem";
        	this.roomsToolStripMenuItem.Size = new System.Drawing.Size(166, 30);
        	this.roomsToolStripMenuItem.Text = "&Rooms";
        	this.roomsToolStripMenuItem.Click += new System.EventHandler(this.RoomsToolStripMenuItemClick);
        	// 
        	// studentsToolStripMenuItem
        	// 
        	this.studentsToolStripMenuItem.Name = "studentsToolStripMenuItem";
        	this.studentsToolStripMenuItem.Size = new System.Drawing.Size(166, 30);
        	this.studentsToolStripMenuItem.Text = "&Students";
        	this.studentsToolStripMenuItem.Click += new System.EventHandler(this.StudentsToolStripMenuItemClick);
        	// 
        	// benefitsToolStripMenuItem
        	// 
        	this.benefitsToolStripMenuItem.Name = "benefitsToolStripMenuItem";
        	this.benefitsToolStripMenuItem.Size = new System.Drawing.Size(166, 30);
        	this.benefitsToolStripMenuItem.Text = "&Benefits";
        	this.benefitsToolStripMenuItem.Click += new System.EventHandler(this.BenefitsToolStripMenuItemClick);
        	// 
        	// queryEditToolStripMenuItem
        	// 
        	this.queryEditToolStripMenuItem.Name = "queryEditToolStripMenuItem";
        	this.queryEditToolStripMenuItem.Size = new System.Drawing.Size(199, 30);
        	this.queryEditToolStripMenuItem.Text = "&QueryEdit";
        	this.queryEditToolStripMenuItem.Click += new System.EventHandler(this.QueryEditToolStripMenuItemClick);
        	// 
        	// bindingNavigator
        	// 
        	this.bindingNavigator.AddNewItem = this.bindingNavigatorAddNewItem;
        	this.bindingNavigator.BindingSource = this.комнатыBindingSource;
        	this.bindingNavigator.CountItem = this.bindingNavigatorCountItem;
        	this.bindingNavigator.DeleteItem = this.bindingNavigatorDeleteItem;
        	this.bindingNavigator.Dock = System.Windows.Forms.DockStyle.None;
        	this.bindingNavigator.ImageScalingSize = new System.Drawing.Size(24, 24);
        	this.bindingNavigator.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
			this.bindingNavigatorMoveFirstItem,
			this.bindingNavigatorMovePreviousItem,
			this.bindingNavigatorSeparator,
			this.bindingNavigatorPositionItem,
			this.bindingNavigatorCountItem,
			this.bindingNavigatorSeparator1,
			this.bindingNavigatorMoveNextItem,
			this.bindingNavigatorMoveLastItem,
			this.bindingNavigatorSeparator2,
			this.bindingNavigatorAddNewItem,
			this.bindingNavigatorDeleteItem});
        	this.bindingNavigator.Location = new System.Drawing.Point(268, 600);
        	this.bindingNavigator.MoveFirstItem = this.bindingNavigatorMoveFirstItem;
        	this.bindingNavigator.MoveLastItem = this.bindingNavigatorMoveLastItem;
        	this.bindingNavigator.MoveNextItem = this.bindingNavigatorMoveNextItem;
        	this.bindingNavigator.MovePreviousItem = this.bindingNavigatorMovePreviousItem;
        	this.bindingNavigator.Name = "bindingNavigator";
        	this.bindingNavigator.Padding = new System.Windows.Forms.Padding(0, 0, 2, 0);
        	this.bindingNavigator.PositionItem = this.bindingNavigatorPositionItem;
        	this.bindingNavigator.Size = new System.Drawing.Size(339, 31);
        	this.bindingNavigator.TabIndex = 4;
        	this.bindingNavigator.Text = "bindingNavigator1";
        	// 
        	// bindingNavigatorAddNewItem
        	// 
        	this.bindingNavigatorAddNewItem.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
        	this.bindingNavigatorAddNewItem.Image = ((System.Drawing.Image)(resources.GetObject("bindingNavigatorAddNewItem.Image")));
        	this.bindingNavigatorAddNewItem.Name = "bindingNavigatorAddNewItem";
        	this.bindingNavigatorAddNewItem.RightToLeftAutoMirrorImage = true;
        	this.bindingNavigatorAddNewItem.Size = new System.Drawing.Size(28, 28);
        	this.bindingNavigatorAddNewItem.Text = "Добавить";
        	// 
        	// bindingNavigatorCountItem
        	// 
        	this.bindingNavigatorCountItem.Name = "bindingNavigatorCountItem";
        	this.bindingNavigatorCountItem.Size = new System.Drawing.Size(65, 28);
        	this.bindingNavigatorCountItem.Text = "для {0}";
        	this.bindingNavigatorCountItem.ToolTipText = "Общее число элементов";
        	// 
        	// bindingNavigatorDeleteItem
        	// 
        	this.bindingNavigatorDeleteItem.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
        	this.bindingNavigatorDeleteItem.Image = ((System.Drawing.Image)(resources.GetObject("bindingNavigatorDeleteItem.Image")));
        	this.bindingNavigatorDeleteItem.Name = "bindingNavigatorDeleteItem";
        	this.bindingNavigatorDeleteItem.RightToLeftAutoMirrorImage = true;
        	this.bindingNavigatorDeleteItem.Size = new System.Drawing.Size(28, 28);
        	this.bindingNavigatorDeleteItem.Text = "Удалить";
        	// 
        	// bindingNavigatorMoveFirstItem
        	// 
        	this.bindingNavigatorMoveFirstItem.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
        	this.bindingNavigatorMoveFirstItem.Image = ((System.Drawing.Image)(resources.GetObject("bindingNavigatorMoveFirstItem.Image")));
        	this.bindingNavigatorMoveFirstItem.Name = "bindingNavigatorMoveFirstItem";
        	this.bindingNavigatorMoveFirstItem.RightToLeftAutoMirrorImage = true;
        	this.bindingNavigatorMoveFirstItem.Size = new System.Drawing.Size(28, 28);
        	this.bindingNavigatorMoveFirstItem.Text = "Переместить в начало";
        	// 
        	// bindingNavigatorMovePreviousItem
        	// 
        	this.bindingNavigatorMovePreviousItem.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
        	this.bindingNavigatorMovePreviousItem.Image = ((System.Drawing.Image)(resources.GetObject("bindingNavigatorMovePreviousItem.Image")));
        	this.bindingNavigatorMovePreviousItem.Name = "bindingNavigatorMovePreviousItem";
        	this.bindingNavigatorMovePreviousItem.RightToLeftAutoMirrorImage = true;
        	this.bindingNavigatorMovePreviousItem.Size = new System.Drawing.Size(28, 28);
        	this.bindingNavigatorMovePreviousItem.Text = "Переместить назад";
        	// 
        	// bindingNavigatorSeparator
        	// 
        	this.bindingNavigatorSeparator.Name = "bindingNavigatorSeparator";
        	this.bindingNavigatorSeparator.Size = new System.Drawing.Size(6, 31);
        	// 
        	// bindingNavigatorPositionItem
        	// 
        	this.bindingNavigatorPositionItem.AccessibleName = "Положение";
        	this.bindingNavigatorPositionItem.AutoSize = false;
        	this.bindingNavigatorPositionItem.Name = "bindingNavigatorPositionItem";
        	this.bindingNavigatorPositionItem.Size = new System.Drawing.Size(73, 31);
        	this.bindingNavigatorPositionItem.Text = "0";
        	this.bindingNavigatorPositionItem.ToolTipText = "Текущее положение";
        	// 
        	// bindingNavigatorSeparator1
        	// 
        	this.bindingNavigatorSeparator1.Name = "bindingNavigatorSeparator1";
        	this.bindingNavigatorSeparator1.Size = new System.Drawing.Size(6, 31);
        	// 
        	// bindingNavigatorMoveNextItem
        	// 
        	this.bindingNavigatorMoveNextItem.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
        	this.bindingNavigatorMoveNextItem.Image = ((System.Drawing.Image)(resources.GetObject("bindingNavigatorMoveNextItem.Image")));
        	this.bindingNavigatorMoveNextItem.Name = "bindingNavigatorMoveNextItem";
        	this.bindingNavigatorMoveNextItem.RightToLeftAutoMirrorImage = true;
        	this.bindingNavigatorMoveNextItem.Size = new System.Drawing.Size(28, 28);
        	this.bindingNavigatorMoveNextItem.Text = "Переместить вперед";
        	// 
        	// bindingNavigatorMoveLastItem
        	// 
        	this.bindingNavigatorMoveLastItem.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
        	this.bindingNavigatorMoveLastItem.Image = ((System.Drawing.Image)(resources.GetObject("bindingNavigatorMoveLastItem.Image")));
        	this.bindingNavigatorMoveLastItem.Name = "bindingNavigatorMoveLastItem";
        	this.bindingNavigatorMoveLastItem.RightToLeftAutoMirrorImage = true;
        	this.bindingNavigatorMoveLastItem.Size = new System.Drawing.Size(28, 28);
        	this.bindingNavigatorMoveLastItem.Text = "Переместить в конец";
        	// 
        	// bindingNavigatorSeparator2
        	// 
        	this.bindingNavigatorSeparator2.Name = "bindingNavigatorSeparator2";
        	this.bindingNavigatorSeparator2.Size = new System.Drawing.Size(6, 31);
        	// 
        	// комнатыTableAdapter
        	// 
        	this.комнатыTableAdapter.ClearBeforeFill = true;
        	// 
        	// студентыTableAdapter
        	// 
        	this.студентыTableAdapter.ClearBeforeFill = true;
        	// 
        	// льготыTableAdapter
        	// 
        	this.льготыTableAdapter.ClearBeforeFill = true;
        	// 
        	// labelTable
        	// 
        	this.labelTable.Location = new System.Drawing.Point(12, 35);
        	this.labelTable.Name = "labelTable";
        	this.labelTable.Size = new System.Drawing.Size(100, 23);
        	this.labelTable.TabIndex = 5;
        	this.labelTable.Text = "Room";
        	// 
        	// editQueryToolStripMenuItem
        	// 
        	this.editQueryToolStripMenuItem.Name = "editQueryToolStripMenuItem";
        	this.editQueryToolStripMenuItem.Size = new System.Drawing.Size(210, 30);
        	this.editQueryToolStripMenuItem.Text = "&EditQuery";
        	this.editQueryToolStripMenuItem.Click += new System.EventHandler(this.EditQueryToolStripMenuItemClick);
        	// 
        	// MainForm
        	// 
        	this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
        	this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
        	this.ClientSize = new System.Drawing.Size(906, 640);
        	this.Controls.Add(this.labelTable);
        	this.Controls.Add(this.bindingNavigator);
        	this.Controls.Add(this.dataGridView);
        	this.Controls.Add(this.menuStrip1);
        	this.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
        	this.Name = "MainForm";
        	this.Text = "MainForm";
        	this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.MainForm_FormClosing);
        	this.Load += new System.EventHandler(this.MainForm_Load);
        	((System.ComponentModel.ISupportInitialize)(this.dataGridView)).EndInit();
        	((System.ComponentModel.ISupportInitialize)(this.комнатыBindingSource)).EndInit();
        	((System.ComponentModel.ISupportInitialize)(this.bindingSource)).EndInit();
        	((System.ComponentModel.ISupportInitialize)(this.lab01DataSet)).EndInit();
        	((System.ComponentModel.ISupportInitialize)(this.студентыBindingSource)).EndInit();
        	((System.ComponentModel.ISupportInitialize)(this.льготыBindingSource)).EndInit();
        	this.menuStrip1.ResumeLayout(false);
        	this.menuStrip1.PerformLayout();
        	((System.ComponentModel.ISupportInitialize)(this.bindingNavigator)).EndInit();
        	this.bindingNavigator.ResumeLayout(false);
        	this.bindingNavigator.PerformLayout();
        	this.ResumeLayout(false);
        	this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.BindingSource bindingSource;
        private Lab01DataSet lab01DataSet;
        private System.Windows.Forms.DataGridView dataGridView;
        private System.Windows.Forms.BindingSource комнатыBindingSource;
        private Lab01DataSetTableAdapters.КомнатыTableAdapter комнатыTableAdapter;
        private System.Windows.Forms.DataGridViewTextBoxColumn комнатыDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn стоимостьDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn количествоDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn инвентарьDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn этажDataGridViewTextBoxColumn;
        private System.Windows.Forms.BindingSource студентыBindingSource;
        private Lab01DataSetTableAdapters.СтудентыTableAdapter студентыTableAdapter;
        private System.Windows.Forms.BindingSource льготыBindingSource;
        private Lab01DataSetTableAdapters.ЛьготыTableAdapter льготыTableAdapter;
        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem fileToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem exitToolStripMenuItem;
        private System.Windows.Forms.BindingNavigator bindingNavigator;
        private System.Windows.Forms.ToolStripButton bindingNavigatorAddNewItem;
        private System.Windows.Forms.ToolStripLabel bindingNavigatorCountItem;
        private System.Windows.Forms.ToolStripButton bindingNavigatorDeleteItem;
        private System.Windows.Forms.ToolStripButton bindingNavigatorMoveFirstItem;
        private System.Windows.Forms.ToolStripButton bindingNavigatorMovePreviousItem;
        private System.Windows.Forms.ToolStripSeparator bindingNavigatorSeparator;
        private System.Windows.Forms.ToolStripTextBox bindingNavigatorPositionItem;
        private System.Windows.Forms.ToolStripSeparator bindingNavigatorSeparator1;
        private System.Windows.Forms.ToolStripButton bindingNavigatorMoveNextItem;
        private System.Windows.Forms.ToolStripButton bindingNavigatorMoveLastItem;
        private System.Windows.Forms.ToolStripSeparator bindingNavigatorSeparator2;
        private System.Windows.Forms.Label labelTable;
        private System.Windows.Forms.ToolStripMenuItem databaseToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem roomsToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem studentsToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem benefitsToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem viewToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem resettlementToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem queryEditToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem editToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem addToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem updateToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem deleteToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem editQueryToolStripMenuItem;
    }
}

