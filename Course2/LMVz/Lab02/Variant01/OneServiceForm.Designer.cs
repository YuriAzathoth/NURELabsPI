/*
 * Создано в SharpDevelop.
 * Пользователь: Yuri Zinchenko
 * Дата: 08.11.2018
 * Время: 20:28
*/
namespace Variant01
{
	partial class OneServiceForm
	{
		/// <summary>
		/// Designer variable used to keep track of non-visual components.
		/// </summary>
		private System.ComponentModel.IContainer components = null;
		private System.Windows.Forms.Button btnSend;
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
		private System.Windows.Forms.Label labelMeasure;
		private System.Windows.Forms.ComboBox comboSvType;
		private System.Windows.Forms.Label label9;
		private System.Windows.Forms.Label label11;
		private System.Windows.Forms.TextBox textSum;
		private System.Windows.Forms.Label label14;
		private System.Windows.Forms.TextBox textSubsidion;
		private System.Windows.Forms.Label label15;
		private System.Windows.Forms.TextBox textSvVolume;
		private System.Windows.Forms.Label label17;
		private System.Windows.Forms.TextBox textTarif;
		private System.Windows.Forms.GroupBox groupBox2;
		private System.Windows.Forms.TextBox textNum;
		private System.Windows.Forms.Label label1;
		private System.Windows.Forms.Label label2;
		private System.Data.DataSet dataSet;
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
			this.btnSend = new System.Windows.Forms.Button();
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
			this.labelMeasure = new System.Windows.Forms.Label();
			this.comboSvType = new System.Windows.Forms.ComboBox();
			this.label9 = new System.Windows.Forms.Label();
			this.label11 = new System.Windows.Forms.Label();
			this.textSum = new System.Windows.Forms.TextBox();
			this.label14 = new System.Windows.Forms.Label();
			this.textSubsidion = new System.Windows.Forms.TextBox();
			this.label15 = new System.Windows.Forms.Label();
			this.textSvVolume = new System.Windows.Forms.TextBox();
			this.label17 = new System.Windows.Forms.Label();
			this.textTarif = new System.Windows.Forms.TextBox();
			this.groupBox2 = new System.Windows.Forms.GroupBox();
			this.textNum = new System.Windows.Forms.TextBox();
			this.label1 = new System.Windows.Forms.Label();
			this.label2 = new System.Windows.Forms.Label();
			this.dataSet = new System.Data.DataSet();
			this.dateMonth = new System.Windows.Forms.DateTimePicker();
			this.groupBox1.SuspendLayout();
			this.groupBox2.SuspendLayout();
			((System.ComponentModel.ISupportInitialize)(this.dataSet)).BeginInit();
			this.SuspendLayout();
			// 
			// btnSend
			// 
			this.btnSend.Location = new System.Drawing.Point(12, 370);
			this.btnSend.Name = "btnSend";
			this.btnSend.Size = new System.Drawing.Size(345, 40);
			this.btnSend.TabIndex = 50;
			this.btnSend.Text = "Отпраить";
			this.btnSend.UseVisualStyleBackColor = true;
			this.btnSend.Click += new System.EventHandler(this.BtnSendClick);
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
			this.groupBox1.TabIndex = 48;
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
			// labelMeasure
			// 
			this.labelMeasure.Location = new System.Drawing.Point(285, 71);
			this.labelMeasure.Name = "labelMeasure";
			this.labelMeasure.Size = new System.Drawing.Size(54, 16);
			this.labelMeasure.TabIndex = 15;
			// 
			// comboSvType
			// 
			this.comboSvType.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
			this.comboSvType.FormattingEnabled = true;
			this.comboSvType.Location = new System.Drawing.Point(144, 15);
			this.comboSvType.Name = "comboSvType";
			this.comboSvType.Size = new System.Drawing.Size(192, 21);
			this.comboSvType.TabIndex = 14;
			this.comboSvType.SelectedIndexChanged += new System.EventHandler(this.ComboSvTypeSelectedIndexChanged);
			// 
			// label9
			// 
			this.label9.Location = new System.Drawing.Point(6, 18);
			this.label9.Name = "label9";
			this.label9.Size = new System.Drawing.Size(132, 16);
			this.label9.TabIndex = 13;
			this.label9.Text = "Вид услуги";
			// 
			// label11
			// 
			this.label11.Location = new System.Drawing.Point(6, 123);
			this.label11.Name = "label11";
			this.label11.Size = new System.Drawing.Size(132, 16);
			this.label11.TabIndex = 10;
			this.label11.Text = "К оплате:";
			// 
			// textSum
			// 
			this.textSum.Location = new System.Drawing.Point(144, 120);
			this.textSum.Name = "textSum";
			this.textSum.ReadOnly = true;
			this.textSum.Size = new System.Drawing.Size(192, 20);
			this.textSum.TabIndex = 9;
			this.textSum.Text = "0";
			// 
			// label14
			// 
			this.label14.Location = new System.Drawing.Point(6, 97);
			this.label14.Name = "label14";
			this.label14.Size = new System.Drawing.Size(132, 16);
			this.label14.TabIndex = 7;
			this.label14.Text = "Субсидии";
			// 
			// textSubsidion
			// 
			this.textSubsidion.Location = new System.Drawing.Point(144, 94);
			this.textSubsidion.Name = "textSubsidion";
			this.textSubsidion.Size = new System.Drawing.Size(192, 20);
			this.textSubsidion.TabIndex = 6;
			this.textSubsidion.Text = "0";
			this.textSubsidion.TextChanged += new System.EventHandler(this.TextSubsidionTextChanged);
			// 
			// label15
			// 
			this.label15.Location = new System.Drawing.Point(6, 71);
			this.label15.Name = "label15";
			this.label15.Size = new System.Drawing.Size(132, 16);
			this.label15.TabIndex = 5;
			this.label15.Text = "Объём коммун. услуг";
			// 
			// textSvVolume
			// 
			this.textSvVolume.Location = new System.Drawing.Point(144, 68);
			this.textSvVolume.Name = "textSvVolume";
			this.textSvVolume.Size = new System.Drawing.Size(135, 20);
			this.textSvVolume.TabIndex = 4;
			this.textSvVolume.Text = "0";
			this.textSvVolume.TextChanged += new System.EventHandler(this.TextSvVolumeTextChanged);
			// 
			// label17
			// 
			this.label17.Location = new System.Drawing.Point(6, 45);
			this.label17.Name = "label17";
			this.label17.Size = new System.Drawing.Size(132, 16);
			this.label17.TabIndex = 3;
			this.label17.Text = "Тариф";
			// 
			// textTarif
			// 
			this.textTarif.Location = new System.Drawing.Point(144, 42);
			this.textTarif.Name = "textTarif";
			this.textTarif.ReadOnly = true;
			this.textTarif.Size = new System.Drawing.Size(192, 20);
			this.textTarif.TabIndex = 2;
			this.textTarif.Text = "0";
			// 
			// groupBox2
			// 
			this.groupBox2.Controls.Add(this.labelMeasure);
			this.groupBox2.Controls.Add(this.comboSvType);
			this.groupBox2.Controls.Add(this.label9);
			this.groupBox2.Controls.Add(this.label11);
			this.groupBox2.Controls.Add(this.textSum);
			this.groupBox2.Controls.Add(this.label14);
			this.groupBox2.Controls.Add(this.textSubsidion);
			this.groupBox2.Controls.Add(this.label15);
			this.groupBox2.Controls.Add(this.textSvVolume);
			this.groupBox2.Controls.Add(this.label17);
			this.groupBox2.Controls.Add(this.textTarif);
			this.groupBox2.Location = new System.Drawing.Point(12, 217);
			this.groupBox2.Name = "groupBox2";
			this.groupBox2.Size = new System.Drawing.Size(345, 147);
			this.groupBox2.TabIndex = 49;
			this.groupBox2.TabStop = false;
			this.groupBox2.Text = "Сведения об услуге";
			// 
			// textNum
			// 
			this.textNum.Location = new System.Drawing.Point(158, 12);
			this.textNum.Name = "textNum";
			this.textNum.Size = new System.Drawing.Size(199, 20);
			this.textNum.TabIndex = 46;
			// 
			// label1
			// 
			this.label1.Location = new System.Drawing.Point(12, 15);
			this.label1.Name = "label1";
			this.label1.Size = new System.Drawing.Size(138, 16);
			this.label1.TabIndex = 44;
			this.label1.Text = "Платёжный документ №";
			// 
			// label2
			// 
			this.label2.Location = new System.Drawing.Point(12, 42);
			this.label2.Name = "label2";
			this.label2.Size = new System.Drawing.Size(132, 16);
			this.label2.TabIndex = 47;
			this.label2.Text = "За месяц";
			// 
			// dataSet
			// 
			this.dataSet.DataSetName = "NewDataSet";
			// 
			// dateMonth
			// 
			this.dateMonth.Format = System.Windows.Forms.DateTimePickerFormat.Custom;
			this.dateMonth.Location = new System.Drawing.Point(158, 38);
			this.dateMonth.Name = "dateMonth";
			this.dateMonth.Size = new System.Drawing.Size(198, 20);
			this.dateMonth.TabIndex = 45;
			// 
			// OneServiceForm
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(367, 421);
			this.Controls.Add(this.btnSend);
			this.Controls.Add(this.groupBox1);
			this.Controls.Add(this.groupBox2);
			this.Controls.Add(this.textNum);
			this.Controls.Add(this.label1);
			this.Controls.Add(this.label2);
			this.Controls.Add(this.dateMonth);
			this.Name = "OneServiceForm";
			this.Text = "Одна услуга";
			this.Load += new System.EventHandler(this.OneServiceFormLoad);
			this.groupBox1.ResumeLayout(false);
			this.groupBox1.PerformLayout();
			this.groupBox2.ResumeLayout(false);
			this.groupBox2.PerformLayout();
			((System.ComponentModel.ISupportInitialize)(this.dataSet)).EndInit();
			this.ResumeLayout(false);
			this.PerformLayout();

		}
	}
}
