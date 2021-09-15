/*
 * Создано в SharpDevelop.
 * Пользователь: Master
 * Дата: 03.11.2018
 * Время: 21:31
 * 
 * Для изменения этого шаблона используйте меню "Инструменты | Параметры | Кодирование | Стандартные заголовки".
 */
namespace Hostel
{
	partial class RSForm
	{
		/// <summary>
		/// Designer variable used to keep track of non-visual components.
		/// </summary>
		private System.ComponentModel.IContainer components = null;
		private System.Windows.Forms.BindingSource roomsBindingSource;
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
		private System.Windows.Forms.TextBox textId;
		private System.Windows.Forms.Label label1;
		private System.Windows.Forms.TextBox textPrice;
		private System.Windows.Forms.TextBox textAmount;
		private System.Windows.Forms.TextBox textFloor;
		private System.Windows.Forms.TextBox textTools;
		private System.Windows.Forms.Label label2;
		private System.Windows.Forms.Label label3;
		private System.Windows.Forms.Label label4;
		private System.Windows.Forms.Label label5;
		private System.Windows.Forms.Button btnAccept;
		private System.Windows.Forms.DataGridView dataGridView;
		private System.Windows.Forms.BindingSource studentsBindingSource;
		private System.Windows.Forms.DataGrid dataGrid1;
		private System.Windows.Forms.DataGrid dataGrid2;
		private Hostel.Lab01DataSet lab01DataSet;
		
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
			System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(RSForm));
			this.roomsBindingSource = new System.Windows.Forms.BindingSource(this.components);
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
			this.textId = new System.Windows.Forms.TextBox();
			this.label1 = new System.Windows.Forms.Label();
			this.textPrice = new System.Windows.Forms.TextBox();
			this.textAmount = new System.Windows.Forms.TextBox();
			this.textFloor = new System.Windows.Forms.TextBox();
			this.textTools = new System.Windows.Forms.TextBox();
			this.label2 = new System.Windows.Forms.Label();
			this.label3 = new System.Windows.Forms.Label();
			this.label4 = new System.Windows.Forms.Label();
			this.label5 = new System.Windows.Forms.Label();
			this.btnAccept = new System.Windows.Forms.Button();
			this.dataGridView = new System.Windows.Forms.DataGridView();
			this.studentsBindingSource = new System.Windows.Forms.BindingSource(this.components);
			this.dataGrid1 = new System.Windows.Forms.DataGrid();
			this.dataGrid2 = new System.Windows.Forms.DataGrid();
			this.lab01DataSet = new Hostel.Lab01DataSet();
			((System.ComponentModel.ISupportInitialize)(this.roomsBindingSource)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.bindingNavigator)).BeginInit();
			this.bindingNavigator.SuspendLayout();
			((System.ComponentModel.ISupportInitialize)(this.dataGridView)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.studentsBindingSource)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.dataGrid1)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.dataGrid2)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.lab01DataSet)).BeginInit();
			this.SuspendLayout();
			// 
			// bindingNavigator
			// 
			this.bindingNavigator.AddNewItem = this.bindingNavigatorAddNewItem;
			this.bindingNavigator.CountItem = this.bindingNavigatorCountItem;
			this.bindingNavigator.DeleteItem = this.bindingNavigatorDeleteItem;
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
			this.bindingNavigator.Location = new System.Drawing.Point(0, 0);
			this.bindingNavigator.MoveFirstItem = this.bindingNavigatorMoveFirstItem;
			this.bindingNavigator.MoveLastItem = this.bindingNavigatorMoveLastItem;
			this.bindingNavigator.MoveNextItem = this.bindingNavigatorMoveNextItem;
			this.bindingNavigator.MovePreviousItem = this.bindingNavigatorMovePreviousItem;
			this.bindingNavigator.Name = "bindingNavigator";
			this.bindingNavigator.PositionItem = this.bindingNavigatorPositionItem;
			this.bindingNavigator.Size = new System.Drawing.Size(1029, 31);
			this.bindingNavigator.TabIndex = 2;
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
			this.bindingNavigatorPositionItem.Size = new System.Drawing.Size(50, 31);
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
			// textId
			// 
			this.textId.Location = new System.Drawing.Point(118, 39);
			this.textId.Name = "textId";
			this.textId.Size = new System.Drawing.Size(289, 26);
			this.textId.TabIndex = 3;
			// 
			// label1
			// 
			this.label1.Location = new System.Drawing.Point(12, 39);
			this.label1.Name = "label1";
			this.label1.Size = new System.Drawing.Size(100, 23);
			this.label1.TabIndex = 4;
			this.label1.Text = "Id:";
			// 
			// textPrice
			// 
			this.textPrice.Location = new System.Drawing.Point(118, 71);
			this.textPrice.Name = "textPrice";
			this.textPrice.Size = new System.Drawing.Size(289, 26);
			this.textPrice.TabIndex = 5;
			// 
			// textAmount
			// 
			this.textAmount.Location = new System.Drawing.Point(118, 103);
			this.textAmount.Name = "textAmount";
			this.textAmount.Size = new System.Drawing.Size(289, 26);
			this.textAmount.TabIndex = 6;
			// 
			// textFloor
			// 
			this.textFloor.Location = new System.Drawing.Point(118, 135);
			this.textFloor.Name = "textFloor";
			this.textFloor.Size = new System.Drawing.Size(289, 26);
			this.textFloor.TabIndex = 7;
			// 
			// textTools
			// 
			this.textTools.Location = new System.Drawing.Point(118, 167);
			this.textTools.Name = "textTools";
			this.textTools.Size = new System.Drawing.Size(289, 26);
			this.textTools.TabIndex = 8;
			// 
			// label2
			// 
			this.label2.Location = new System.Drawing.Point(12, 74);
			this.label2.Name = "label2";
			this.label2.Size = new System.Drawing.Size(100, 23);
			this.label2.TabIndex = 9;
			this.label2.Text = "Price:";
			// 
			// label3
			// 
			this.label3.Location = new System.Drawing.Point(12, 106);
			this.label3.Name = "label3";
			this.label3.Size = new System.Drawing.Size(100, 23);
			this.label3.TabIndex = 10;
			this.label3.Text = "Amount:";
			// 
			// label4
			// 
			this.label4.Location = new System.Drawing.Point(12, 138);
			this.label4.Name = "label4";
			this.label4.Size = new System.Drawing.Size(100, 23);
			this.label4.TabIndex = 11;
			this.label4.Text = "Floor:";
			// 
			// label5
			// 
			this.label5.Location = new System.Drawing.Point(12, 170);
			this.label5.Name = "label5";
			this.label5.Size = new System.Drawing.Size(100, 23);
			this.label5.TabIndex = 12;
			this.label5.Text = "Tools:";
			// 
			// btnAccept
			// 
			this.btnAccept.Location = new System.Drawing.Point(813, 39);
			this.btnAccept.Name = "btnAccept";
			this.btnAccept.Size = new System.Drawing.Size(204, 48);
			this.btnAccept.TabIndex = 13;
			this.btnAccept.Text = "Accept Changes";
			this.btnAccept.UseVisualStyleBackColor = true;
			this.btnAccept.Click += new System.EventHandler(this.BtnAcceptClick);
			// 
			// dataGridView
			// 
			this.dataGridView.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
			this.dataGridView.Location = new System.Drawing.Point(12, 199);
			this.dataGridView.Name = "dataGridView";
			this.dataGridView.RowTemplate.Height = 28;
			this.dataGridView.Size = new System.Drawing.Size(1005, 496);
			this.dataGridView.TabIndex = 14;
			// 
			// dataGrid1
			// 
			this.dataGrid1.DataMember = "";
			this.dataGrid1.HeaderForeColor = System.Drawing.SystemColors.ControlText;
			this.dataGrid1.Location = new System.Drawing.Point(0, 0);
			this.dataGrid1.Name = "dataGrid1";
			this.dataGrid1.Size = new System.Drawing.Size(130, 80);
			this.dataGrid1.TabIndex = 0;
			// 
			// dataGrid2
			// 
			this.dataGrid2.DataMember = "";
			this.dataGrid2.HeaderForeColor = System.Drawing.SystemColors.ControlText;
			this.dataGrid2.Location = new System.Drawing.Point(0, 0);
			this.dataGrid2.Name = "dataGrid2";
			this.dataGrid2.Size = new System.Drawing.Size(130, 80);
			this.dataGrid2.TabIndex = 0;
			// 
			// lab01DataSet
			// 
			this.lab01DataSet.DataSetName = "Lab01DataSet";
			this.lab01DataSet.Namespace = "http://tempuri.org/Lab01DataSet.xsd";
			this.lab01DataSet.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
			// 
			// RSForm
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(1029, 707);
			this.Controls.Add(this.dataGridView);
			this.Controls.Add(this.btnAccept);
			this.Controls.Add(this.label5);
			this.Controls.Add(this.label4);
			this.Controls.Add(this.label3);
			this.Controls.Add(this.label2);
			this.Controls.Add(this.textTools);
			this.Controls.Add(this.textFloor);
			this.Controls.Add(this.textAmount);
			this.Controls.Add(this.textPrice);
			this.Controls.Add(this.label1);
			this.Controls.Add(this.textId);
			this.Controls.Add(this.bindingNavigator);
			this.Name = "RSForm";
			this.Text = "Settlement";
			this.Load += new System.EventHandler(this.RSFormLoad);
			((System.ComponentModel.ISupportInitialize)(this.roomsBindingSource)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.bindingNavigator)).EndInit();
			this.bindingNavigator.ResumeLayout(false);
			this.bindingNavigator.PerformLayout();
			((System.ComponentModel.ISupportInitialize)(this.dataGridView)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.studentsBindingSource)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.dataGrid1)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.dataGrid2)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.lab01DataSet)).EndInit();
			this.ResumeLayout(false);
			this.PerformLayout();

		}
	}
}
