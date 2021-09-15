/*
 * Создано в SharpDevelop.
 * Пользователь: Master
 * Дата: 04.11.2018
 * Время: 17:14
 * 
 * Для изменения этого шаблона используйте меню "Инструменты | Параметры | Кодирование | Стандартные заголовки".
 */
namespace Hostel
{
	partial class QueryEdit
	{
		/// <summary>
		/// Designer variable used to keep track of non-visual components.
		/// </summary>
		private System.ComponentModel.IContainer components = null;
		private System.Windows.Forms.RichTextBox richCmd;
		private System.Windows.Forms.Button btnDo;
		private System.Windows.Forms.Button btnClear;
		private System.Windows.Forms.Button btnExit;
		private System.Windows.Forms.DataGridView dataGridView;
		
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
			this.richCmd = new System.Windows.Forms.RichTextBox();
			this.btnDo = new System.Windows.Forms.Button();
			this.btnClear = new System.Windows.Forms.Button();
			this.btnExit = new System.Windows.Forms.Button();
			this.dataGridView = new System.Windows.Forms.DataGridView();
			((System.ComponentModel.ISupportInitialize)(this.dataGridView)).BeginInit();
			this.SuspendLayout();
			// 
			// richCmd
			// 
			this.richCmd.Location = new System.Drawing.Point(12, 12);
			this.richCmd.Name = "richCmd";
			this.richCmd.Size = new System.Drawing.Size(716, 111);
			this.richCmd.TabIndex = 0;
			this.richCmd.Text = "SELECT ";
			// 
			// btnDo
			// 
			this.btnDo.Location = new System.Drawing.Point(734, 12);
			this.btnDo.Name = "btnDo";
			this.btnDo.Size = new System.Drawing.Size(107, 33);
			this.btnDo.TabIndex = 1;
			this.btnDo.Text = "Do SQL";
			this.btnDo.UseVisualStyleBackColor = true;
			this.btnDo.Click += new System.EventHandler(this.BtnDoClick);
			// 
			// btnClear
			// 
			this.btnClear.Location = new System.Drawing.Point(734, 51);
			this.btnClear.Name = "btnClear";
			this.btnClear.Size = new System.Drawing.Size(107, 33);
			this.btnClear.TabIndex = 2;
			this.btnClear.Text = "Clear";
			this.btnClear.UseVisualStyleBackColor = true;
			this.btnClear.Click += new System.EventHandler(this.BtnClearClick);
			// 
			// btnExit
			// 
			this.btnExit.Location = new System.Drawing.Point(734, 90);
			this.btnExit.Name = "btnExit";
			this.btnExit.Size = new System.Drawing.Size(107, 33);
			this.btnExit.TabIndex = 3;
			this.btnExit.Text = "Exit";
			this.btnExit.UseVisualStyleBackColor = true;
			this.btnExit.Click += new System.EventHandler(this.BtnExitClick);
			// 
			// dataGridView
			// 
			this.dataGridView.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
			this.dataGridView.Location = new System.Drawing.Point(12, 129);
			this.dataGridView.Name = "dataGridView";
			this.dataGridView.RowTemplate.Height = 28;
			this.dataGridView.Size = new System.Drawing.Size(829, 439);
			this.dataGridView.TabIndex = 4;
			// 
			// QueryEdit
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(853, 580);
			this.Controls.Add(this.dataGridView);
			this.Controls.Add(this.btnExit);
			this.Controls.Add(this.btnClear);
			this.Controls.Add(this.btnDo);
			this.Controls.Add(this.richCmd);
			this.Name = "QueryEdit";
			this.Text = "QueryEdit";
			((System.ComponentModel.ISupportInitialize)(this.dataGridView)).EndInit();
			this.ResumeLayout(false);

		}
	}
}
