/*
 * Создано в SharpDevelop.
 * User: Yuri Zinchenko
 * Дата: 08.11.2018
 * Время: 14:41
 */
namespace Variant01
{
	partial class SingleServiceForm
	{
		/// <summary>
		/// Designer variable used to keep track of non-visual components.
		/// </summary>
		private System.ComponentModel.IContainer components = null;
		private System.Windows.Forms.Button btnSaveTarif;
		private System.Windows.Forms.Label label9;
		private System.Data.DataSet dataSet;
		private System.Windows.Forms.BindingSource bindingSource;
		private System.Windows.Forms.DataGridView dataGridView;
		private System.Windows.Forms.GroupBox groupBox1;
		private System.Windows.Forms.Label label16;
		private System.Windows.Forms.TextBox textClLicNumber;
		private System.Windows.Forms.Label label7;
		private System.Windows.Forms.Label label8;
		private System.Windows.Forms.TextBox textClPeopleNum;
		private System.Windows.Forms.Label label6;
		private System.Windows.Forms.Label label5;
		private System.Windows.Forms.TextBox textClArea;
		private System.Windows.Forms.Label label4;
		private System.Windows.Forms.TextBox textClAddress;
		private System.Windows.Forms.Label label3;
		private System.Windows.Forms.TextBox textClName;
		private System.Windows.Forms.TextBox textSum;
		private System.Windows.Forms.Button btnSend;
		private System.Windows.Forms.TextBox textNum;
		private System.Windows.Forms.Label label1;
		private System.Windows.Forms.Label label2;
		private System.Windows.Forms.DateTimePicker dateMonth;
		
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
			this.btnSaveTarif = new System.Windows.Forms.Button();
			this.label9 = new System.Windows.Forms.Label();
			this.dataSet = new System.Data.DataSet();
			this.bindingSource = new System.Windows.Forms.BindingSource(this.components);
			this.dataGridView = new System.Windows.Forms.DataGridView();
			this.groupBox1 = new System.Windows.Forms.GroupBox();
			this.label16 = new System.Windows.Forms.Label();
			this.textClLicNumber = new System.Windows.Forms.TextBox();
			this.label7 = new System.Windows.Forms.Label();
			this.label8 = new System.Windows.Forms.Label();
			this.textClPeopleNum = new System.Windows.Forms.TextBox();
			this.label6 = new System.Windows.Forms.Label();
			this.label5 = new System.Windows.Forms.Label();
			this.textClArea = new System.Windows.Forms.TextBox();
			this.label4 = new System.Windows.Forms.Label();
			this.textClAddress = new System.Windows.Forms.TextBox();
			this.label3 = new System.Windows.Forms.Label();
			this.textClName = new System.Windows.Forms.TextBox();
			this.textSum = new System.Windows.Forms.TextBox();
			this.btnSend = new System.Windows.Forms.Button();
			this.textNum = new System.Windows.Forms.TextBox();
			this.label1 = new System.Windows.Forms.Label();
			this.label2 = new System.Windows.Forms.Label();
			this.dateMonth = new System.Windows.Forms.DateTimePicker();
			((System.ComponentModel.ISupportInitialize)(this.dataSet)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.bindingSource)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.dataGridView)).BeginInit();
			this.groupBox1.SuspendLayout();
			this.SuspendLayout();
			// 
			// btnSaveTarif
			// 
			this.btnSaveTarif.Location = new System.Drawing.Point(819, 217);
			this.btnSaveTarif.Name = "btnSaveTarif";
			this.btnSaveTarif.Size = new System.Drawing.Size(119, 34);
			this.btnSaveTarif.TabIndex = 37;
			this.btnSaveTarif.Text = "Сохранить тариф";
			this.btnSaveTarif.UseVisualStyleBackColor = true;
			this.btnSaveTarif.Click += new System.EventHandler(this.BtnSaveTarifClick);
			// 
			// label9
			// 
			this.label9.Location = new System.Drawing.Point(360, 220);
			this.label9.Name = "label9";
			this.label9.Size = new System.Drawing.Size(59, 16);
			this.label9.TabIndex = 29;
			this.label9.Text = "К оплате";
			// 
			// dataSet
			// 
			this.dataSet.DataSetName = "NewDataSet";
			// 
			// dataGridView
			// 
			this.dataGridView.AllowUserToAddRows = false;
			this.dataGridView.AllowUserToDeleteRows = false;
			this.dataGridView.AutoSizeColumnsMode = System.Windows.Forms.DataGridViewAutoSizeColumnsMode.AllCells;
			this.dataGridView.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
			this.dataGridView.Location = new System.Drawing.Point(360, 12);
			this.dataGridView.Name = "dataGridView";
			this.dataGridView.Size = new System.Drawing.Size(578, 199);
			this.dataGridView.TabIndex = 36;
			this.dataGridView.CellEndEdit += new System.Windows.Forms.DataGridViewCellEventHandler(this.DataGridViewCellEndEdit);
			// 
			// groupBox1
			// 
			this.groupBox1.Controls.Add(this.label16);
			this.groupBox1.Controls.Add(this.textClLicNumber);
			this.groupBox1.Controls.Add(this.label7);
			this.groupBox1.Controls.Add(this.label8);
			this.groupBox1.Controls.Add(this.textClPeopleNum);
			this.groupBox1.Controls.Add(this.label6);
			this.groupBox1.Controls.Add(this.label5);
			this.groupBox1.Controls.Add(this.textClArea);
			this.groupBox1.Controls.Add(this.label4);
			this.groupBox1.Controls.Add(this.textClAddress);
			this.groupBox1.Controls.Add(this.label3);
			this.groupBox1.Controls.Add(this.textClName);
			this.groupBox1.Location = new System.Drawing.Point(12, 64);
			this.groupBox1.Name = "groupBox1";
			this.groupBox1.Size = new System.Drawing.Size(342, 147);
			this.groupBox1.TabIndex = 34;
			this.groupBox1.TabStop = false;
			this.groupBox1.Text = "Сведения о плательщике";
			// 
			// label16
			// 
			this.label16.Location = new System.Drawing.Point(6, 23);
			this.label16.Name = "label16";
			this.label16.Size = new System.Drawing.Size(132, 16);
			this.label16.TabIndex = 13;
			this.label16.Text = "Лицевой счёт";
			// 
			// textClLicNumber
			// 
			this.textClLicNumber.Location = new System.Drawing.Point(144, 19);
			this.textClLicNumber.Name = "textClLicNumber";
			this.textClLicNumber.Size = new System.Drawing.Size(192, 20);
			this.textClLicNumber.TabIndex = 12;
			// 
			// label7
			// 
			this.label7.Location = new System.Drawing.Point(285, 123);
			this.label7.Name = "label7";
			this.label7.Size = new System.Drawing.Size(51, 16);
			this.label7.TabIndex = 11;
			this.label7.Text = "человек";
			// 
			// label8
			// 
			this.label8.Location = new System.Drawing.Point(6, 123);
			this.label8.Name = "label8";
			this.label8.Size = new System.Drawing.Size(132, 16);
			this.label8.TabIndex = 10;
			this.label8.Text = "Количество прожив.";
			// 
			// textClPeopleNum
			// 
			this.textClPeopleNum.Location = new System.Drawing.Point(144, 120);
			this.textClPeopleNum.Name = "textClPeopleNum";
			this.textClPeopleNum.Size = new System.Drawing.Size(135, 20);
			this.textClPeopleNum.TabIndex = 9;
			// 
			// label6
			// 
			this.label6.Location = new System.Drawing.Point(285, 97);
			this.label6.Name = "label6";
			this.label6.Size = new System.Drawing.Size(51, 16);
			this.label6.TabIndex = 8;
			this.label6.Text = "кв. м";
			// 
			// label5
			// 
			this.label5.Location = new System.Drawing.Point(6, 97);
			this.label5.Name = "label5";
			this.label5.Size = new System.Drawing.Size(132, 16);
			this.label5.TabIndex = 7;
			this.label5.Text = "Площадь помещения";
			// 
			// textClArea
			// 
			this.textClArea.Location = new System.Drawing.Point(144, 94);
			this.textClArea.Name = "textClArea";
			this.textClArea.Size = new System.Drawing.Size(135, 20);
			this.textClArea.TabIndex = 6;
			// 
			// label4
			// 
			this.label4.Location = new System.Drawing.Point(6, 71);
			this.label4.Name = "label4";
			this.label4.Size = new System.Drawing.Size(132, 16);
			this.label4.TabIndex = 5;
			this.label4.Text = "Адрес помещения";
			// 
			// textClAddress
			// 
			this.textClAddress.Location = new System.Drawing.Point(144, 68);
			this.textClAddress.Name = "textClAddress";
			this.textClAddress.Size = new System.Drawing.Size(192, 20);
			this.textClAddress.TabIndex = 4;
			// 
			// label3
			// 
			this.label3.Location = new System.Drawing.Point(6, 45);
			this.label3.Name = "label3";
			this.label3.Size = new System.Drawing.Size(132, 16);
			this.label3.TabIndex = 3;
			this.label3.Text = "ФИО плательщика";
			// 
			// textClName
			// 
			this.textClName.Location = new System.Drawing.Point(144, 42);
			this.textClName.Name = "textClName";
			this.textClName.Size = new System.Drawing.Size(192, 20);
			this.textClName.TabIndex = 2;
			// 
			// textSum
			// 
			this.textSum.Location = new System.Drawing.Point(441, 217);
			this.textSum.Name = "textSum";
			this.textSum.ReadOnly = true;
			this.textSum.Size = new System.Drawing.Size(143, 20);
			this.textSum.TabIndex = 28;
			this.textSum.Text = "0";
			// 
			// btnSend
			// 
			this.btnSend.Location = new System.Drawing.Point(590, 217);
			this.btnSend.Name = "btnSend";
			this.btnSend.Size = new System.Drawing.Size(223, 34);
			this.btnSend.TabIndex = 35;
			this.btnSend.Text = "Отправить";
			this.btnSend.UseVisualStyleBackColor = true;
			this.btnSend.Click += new System.EventHandler(this.BtnSendClick);
			// 
			// textNum
			// 
			this.textNum.Location = new System.Drawing.Point(155, 12);
			this.textNum.Name = "textNum";
			this.textNum.Size = new System.Drawing.Size(199, 20);
			this.textNum.TabIndex = 32;
			// 
			// label1
			// 
			this.label1.Location = new System.Drawing.Point(12, 15);
			this.label1.Name = "label1";
			this.label1.Size = new System.Drawing.Size(138, 16);
			this.label1.TabIndex = 30;
			this.label1.Text = "Платёжный документ №";
			// 
			// label2
			// 
			this.label2.Location = new System.Drawing.Point(12, 42);
			this.label2.Name = "label2";
			this.label2.Size = new System.Drawing.Size(132, 16);
			this.label2.TabIndex = 33;
			this.label2.Text = "За месяц";
			// 
			// dateMonth
			// 
			this.dateMonth.Format = System.Windows.Forms.DateTimePickerFormat.Custom;
			this.dateMonth.Location = new System.Drawing.Point(156, 38);
			this.dateMonth.Name = "dateMonth";
			this.dateMonth.Size = new System.Drawing.Size(198, 20);
			this.dateMonth.TabIndex = 31;
			// 
			// SingleServiceForm
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(950, 263);
			this.Controls.Add(this.btnSaveTarif);
			this.Controls.Add(this.label9);
			this.Controls.Add(this.dataGridView);
			this.Controls.Add(this.groupBox1);
			this.Controls.Add(this.textSum);
			this.Controls.Add(this.btnSend);
			this.Controls.Add(this.textNum);
			this.Controls.Add(this.label1);
			this.Controls.Add(this.label2);
			this.Controls.Add(this.dateMonth);
			this.Name = "SingleServiceForm";
			this.Text = "Один исполнитель услуг";
			this.Load += new System.EventHandler(this.SingleServiceFormLoad);
			((System.ComponentModel.ISupportInitialize)(this.dataSet)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.bindingSource)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.dataGridView)).EndInit();
			this.groupBox1.ResumeLayout(false);
			this.groupBox1.PerformLayout();
			this.ResumeLayout(false);
			this.PerformLayout();

		}
	}
}
