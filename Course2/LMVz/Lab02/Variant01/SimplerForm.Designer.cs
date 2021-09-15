/*
 * Создано в SharpDevelop.
 * Пользователь: Yuri Zinchenko
 * Дата: 08.11.2018
 * Время: 15:51
*/
namespace Variant01
{
	partial class SimplerForm
	{
		/// <summary>
		/// Designer variable used to keep track of non-visual components.
		/// </summary>
		private System.ComponentModel.IContainer components = null;
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
		private System.Windows.Forms.TextBox textNum;
		private System.Windows.Forms.Label label1;
		private System.Windows.Forms.Label label2;
		private System.Windows.Forms.DateTimePicker dateMonth;
		private System.Windows.Forms.GroupBox groupBox2;
		private System.Data.DataSet dataSet;
		private System.Windows.Forms.Label label10;
		private System.Windows.Forms.Label label9;
		private System.Windows.Forms.Label label13;
		private System.Windows.Forms.Label label11;
		private System.Windows.Forms.Label label14;
		private System.Windows.Forms.TextBox textSubsidionGas;
		private System.Windows.Forms.TextBox textSubsidionEnergy;
		private System.Windows.Forms.TextBox textSubsidionCanal;
		private System.Windows.Forms.TextBox textSubsidionHotWater;
		private System.Windows.Forms.TextBox textSubsidionColdWater;
		private System.Windows.Forms.Label label20;
		private System.Windows.Forms.TextBox textVolumeGas;
		private System.Windows.Forms.TextBox textVolumeEnergy;
		private System.Windows.Forms.TextBox textVolumeCanal;
		private System.Windows.Forms.TextBox textVolumeHotWater;
		private System.Windows.Forms.TextBox textVolumeColdWater;
		private System.Windows.Forms.Label label19;
		private System.Windows.Forms.Label label18;
		private System.Windows.Forms.Label label17;
		private System.Windows.Forms.Label label15;
		private System.Windows.Forms.Label labelTarifGas;
		private System.Windows.Forms.Label labelTarifEnergy;
		private System.Windows.Forms.Label labelTarifCanal;
		private System.Windows.Forms.Label labelTarifHotWater;
		private System.Windows.Forms.Label labelTarifColdWater;
		private System.Windows.Forms.Label labelMeasGas;
		private System.Windows.Forms.Label labelMeasEnergy;
		private System.Windows.Forms.Label labelMeasCanal;
		private System.Windows.Forms.Label labelMeasHotWater;
		private System.Windows.Forms.Label labelMeasColdWater;
		private System.Windows.Forms.TextBox textGeneralGas;
		private System.Windows.Forms.TextBox textGeneralCanal;
		private System.Windows.Forms.TextBox textGeneralHotWater;
		private System.Windows.Forms.TextBox textGeneralEnergy;
		private System.Windows.Forms.TextBox textGeneralColdWater;
		private System.Windows.Forms.Label label21;
		private System.Windows.Forms.Label label22;
		private System.Windows.Forms.TextBox textFinalGas;
		private System.Windows.Forms.TextBox textFinalCanal;
		private System.Windows.Forms.TextBox textFinalHotWater;
		private System.Windows.Forms.TextBox textFinalEnergy;
		private System.Windows.Forms.TextBox textFinalColdWater;
		private System.Windows.Forms.Label label23;
		private System.Windows.Forms.TextBox textTax;
		private System.Windows.Forms.Button btnSend;
		
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
			this.textNum = new System.Windows.Forms.TextBox();
			this.label1 = new System.Windows.Forms.Label();
			this.label2 = new System.Windows.Forms.Label();
			this.dateMonth = new System.Windows.Forms.DateTimePicker();
			this.groupBox2 = new System.Windows.Forms.GroupBox();
			this.label23 = new System.Windows.Forms.Label();
			this.textTax = new System.Windows.Forms.TextBox();
			this.label22 = new System.Windows.Forms.Label();
			this.textFinalGas = new System.Windows.Forms.TextBox();
			this.textFinalCanal = new System.Windows.Forms.TextBox();
			this.textFinalHotWater = new System.Windows.Forms.TextBox();
			this.textFinalEnergy = new System.Windows.Forms.TextBox();
			this.textFinalColdWater = new System.Windows.Forms.TextBox();
			this.label21 = new System.Windows.Forms.Label();
			this.textGeneralGas = new System.Windows.Forms.TextBox();
			this.textGeneralCanal = new System.Windows.Forms.TextBox();
			this.textGeneralHotWater = new System.Windows.Forms.TextBox();
			this.textGeneralEnergy = new System.Windows.Forms.TextBox();
			this.textGeneralColdWater = new System.Windows.Forms.TextBox();
			this.labelTarifGas = new System.Windows.Forms.Label();
			this.labelTarifEnergy = new System.Windows.Forms.Label();
			this.labelTarifCanal = new System.Windows.Forms.Label();
			this.labelTarifHotWater = new System.Windows.Forms.Label();
			this.labelTarifColdWater = new System.Windows.Forms.Label();
			this.labelMeasGas = new System.Windows.Forms.Label();
			this.labelMeasEnergy = new System.Windows.Forms.Label();
			this.labelMeasCanal = new System.Windows.Forms.Label();
			this.labelMeasHotWater = new System.Windows.Forms.Label();
			this.labelMeasColdWater = new System.Windows.Forms.Label();
			this.textSubsidionGas = new System.Windows.Forms.TextBox();
			this.textSubsidionEnergy = new System.Windows.Forms.TextBox();
			this.textSubsidionCanal = new System.Windows.Forms.TextBox();
			this.textSubsidionHotWater = new System.Windows.Forms.TextBox();
			this.textSubsidionColdWater = new System.Windows.Forms.TextBox();
			this.label20 = new System.Windows.Forms.Label();
			this.textVolumeGas = new System.Windows.Forms.TextBox();
			this.textVolumeEnergy = new System.Windows.Forms.TextBox();
			this.textVolumeCanal = new System.Windows.Forms.TextBox();
			this.textVolumeHotWater = new System.Windows.Forms.TextBox();
			this.textVolumeColdWater = new System.Windows.Forms.TextBox();
			this.label19 = new System.Windows.Forms.Label();
			this.label18 = new System.Windows.Forms.Label();
			this.label17 = new System.Windows.Forms.Label();
			this.label15 = new System.Windows.Forms.Label();
			this.label14 = new System.Windows.Forms.Label();
			this.label13 = new System.Windows.Forms.Label();
			this.label11 = new System.Windows.Forms.Label();
			this.label10 = new System.Windows.Forms.Label();
			this.label9 = new System.Windows.Forms.Label();
			this.dataSet = new System.Data.DataSet();
			this.btnSend = new System.Windows.Forms.Button();
			this.groupBox1.SuspendLayout();
			this.groupBox2.SuspendLayout();
			((System.ComponentModel.ISupportInitialize)(this.dataSet)).BeginInit();
			this.SuspendLayout();
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
			this.groupBox1.TabIndex = 41;
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
			// textNum
			// 
			this.textNum.Location = new System.Drawing.Point(156, 12);
			this.textNum.Name = "textNum";
			this.textNum.Size = new System.Drawing.Size(198, 20);
			this.textNum.TabIndex = 39;
			// 
			// label1
			// 
			this.label1.Location = new System.Drawing.Point(18, 16);
			this.label1.Name = "label1";
			this.label1.Size = new System.Drawing.Size(132, 16);
			this.label1.TabIndex = 37;
			this.label1.Text = "Платёжный документ №";
			// 
			// label2
			// 
			this.label2.Location = new System.Drawing.Point(18, 38);
			this.label2.Name = "label2";
			this.label2.Size = new System.Drawing.Size(126, 16);
			this.label2.TabIndex = 40;
			this.label2.Text = "За месяц";
			// 
			// dateMonth
			// 
			this.dateMonth.Format = System.Windows.Forms.DateTimePickerFormat.Custom;
			this.dateMonth.Location = new System.Drawing.Point(156, 38);
			this.dateMonth.Name = "dateMonth";
			this.dateMonth.Size = new System.Drawing.Size(198, 20);
			this.dateMonth.TabIndex = 38;
			// 
			// groupBox2
			// 
			this.groupBox2.Controls.Add(this.label23);
			this.groupBox2.Controls.Add(this.textTax);
			this.groupBox2.Controls.Add(this.label22);
			this.groupBox2.Controls.Add(this.textFinalGas);
			this.groupBox2.Controls.Add(this.textFinalCanal);
			this.groupBox2.Controls.Add(this.textFinalHotWater);
			this.groupBox2.Controls.Add(this.textFinalEnergy);
			this.groupBox2.Controls.Add(this.textFinalColdWater);
			this.groupBox2.Controls.Add(this.label21);
			this.groupBox2.Controls.Add(this.textGeneralGas);
			this.groupBox2.Controls.Add(this.textGeneralCanal);
			this.groupBox2.Controls.Add(this.textGeneralHotWater);
			this.groupBox2.Controls.Add(this.textGeneralEnergy);
			this.groupBox2.Controls.Add(this.textGeneralColdWater);
			this.groupBox2.Controls.Add(this.labelTarifGas);
			this.groupBox2.Controls.Add(this.labelTarifEnergy);
			this.groupBox2.Controls.Add(this.labelTarifCanal);
			this.groupBox2.Controls.Add(this.labelTarifHotWater);
			this.groupBox2.Controls.Add(this.labelTarifColdWater);
			this.groupBox2.Controls.Add(this.labelMeasGas);
			this.groupBox2.Controls.Add(this.labelMeasEnergy);
			this.groupBox2.Controls.Add(this.labelMeasCanal);
			this.groupBox2.Controls.Add(this.labelMeasHotWater);
			this.groupBox2.Controls.Add(this.labelMeasColdWater);
			this.groupBox2.Controls.Add(this.textSubsidionGas);
			this.groupBox2.Controls.Add(this.textSubsidionEnergy);
			this.groupBox2.Controls.Add(this.textSubsidionCanal);
			this.groupBox2.Controls.Add(this.textSubsidionHotWater);
			this.groupBox2.Controls.Add(this.textSubsidionColdWater);
			this.groupBox2.Controls.Add(this.label20);
			this.groupBox2.Controls.Add(this.textVolumeGas);
			this.groupBox2.Controls.Add(this.textVolumeEnergy);
			this.groupBox2.Controls.Add(this.textVolumeCanal);
			this.groupBox2.Controls.Add(this.textVolumeHotWater);
			this.groupBox2.Controls.Add(this.textVolumeColdWater);
			this.groupBox2.Controls.Add(this.label19);
			this.groupBox2.Controls.Add(this.label18);
			this.groupBox2.Controls.Add(this.label17);
			this.groupBox2.Controls.Add(this.label15);
			this.groupBox2.Controls.Add(this.label14);
			this.groupBox2.Controls.Add(this.label13);
			this.groupBox2.Controls.Add(this.label11);
			this.groupBox2.Controls.Add(this.label10);
			this.groupBox2.Controls.Add(this.label9);
			this.groupBox2.Location = new System.Drawing.Point(12, 217);
			this.groupBox2.Name = "groupBox2";
			this.groupBox2.Size = new System.Drawing.Size(588, 193);
			this.groupBox2.TabIndex = 42;
			this.groupBox2.TabStop = false;
			this.groupBox2.Text = "Расчёт размера платы";
			// 
			// label23
			// 
			this.label23.Location = new System.Drawing.Point(235, 167);
			this.label23.Name = "label23";
			this.label23.Size = new System.Drawing.Size(74, 16);
			this.label23.TabIndex = 85;
			this.label23.Text = "К оплате:";
			// 
			// textTax
			// 
			this.textTax.Location = new System.Drawing.Point(315, 164);
			this.textTax.Name = "textTax";
			this.textTax.ReadOnly = true;
			this.textTax.Size = new System.Drawing.Size(267, 20);
			this.textTax.TabIndex = 84;
			this.textTax.Text = "0,0";
			// 
			// label22
			// 
			this.label22.Location = new System.Drawing.Point(487, 16);
			this.label22.Name = "label22";
			this.label22.Size = new System.Drawing.Size(95, 16);
			this.label22.TabIndex = 83;
			this.label22.Text = "ИТОГ";
			// 
			// textFinalGas
			// 
			this.textFinalGas.Location = new System.Drawing.Point(487, 138);
			this.textFinalGas.Name = "textFinalGas";
			this.textFinalGas.ReadOnly = true;
			this.textFinalGas.Size = new System.Drawing.Size(95, 20);
			this.textFinalGas.TabIndex = 82;
			this.textFinalGas.Text = "0,0";
			// 
			// textFinalCanal
			// 
			this.textFinalCanal.Location = new System.Drawing.Point(487, 87);
			this.textFinalCanal.Name = "textFinalCanal";
			this.textFinalCanal.ReadOnly = true;
			this.textFinalCanal.Size = new System.Drawing.Size(95, 20);
			this.textFinalCanal.TabIndex = 81;
			this.textFinalCanal.Text = "0,0";
			// 
			// textFinalHotWater
			// 
			this.textFinalHotWater.Location = new System.Drawing.Point(487, 61);
			this.textFinalHotWater.Name = "textFinalHotWater";
			this.textFinalHotWater.ReadOnly = true;
			this.textFinalHotWater.Size = new System.Drawing.Size(95, 20);
			this.textFinalHotWater.TabIndex = 79;
			this.textFinalHotWater.Text = "0,0";
			// 
			// textFinalEnergy
			// 
			this.textFinalEnergy.Location = new System.Drawing.Point(487, 112);
			this.textFinalEnergy.Name = "textFinalEnergy";
			this.textFinalEnergy.ReadOnly = true;
			this.textFinalEnergy.Size = new System.Drawing.Size(95, 20);
			this.textFinalEnergy.TabIndex = 80;
			this.textFinalEnergy.Text = "0,0";
			// 
			// textFinalColdWater
			// 
			this.textFinalColdWater.Location = new System.Drawing.Point(487, 35);
			this.textFinalColdWater.Name = "textFinalColdWater";
			this.textFinalColdWater.ReadOnly = true;
			this.textFinalColdWater.Size = new System.Drawing.Size(95, 20);
			this.textFinalColdWater.TabIndex = 78;
			this.textFinalColdWater.Text = "0,0";
			// 
			// label21
			// 
			this.label21.Location = new System.Drawing.Point(315, 16);
			this.label21.Name = "label21";
			this.label21.Size = new System.Drawing.Size(86, 16);
			this.label21.TabIndex = 77;
			this.label21.Text = "СУММА";
			// 
			// textGeneralGas
			// 
			this.textGeneralGas.Location = new System.Drawing.Point(315, 138);
			this.textGeneralGas.Name = "textGeneralGas";
			this.textGeneralGas.ReadOnly = true;
			this.textGeneralGas.Size = new System.Drawing.Size(86, 20);
			this.textGeneralGas.TabIndex = 76;
			this.textGeneralGas.Text = "0,0";
			// 
			// textGeneralCanal
			// 
			this.textGeneralCanal.Location = new System.Drawing.Point(315, 87);
			this.textGeneralCanal.Name = "textGeneralCanal";
			this.textGeneralCanal.ReadOnly = true;
			this.textGeneralCanal.Size = new System.Drawing.Size(86, 20);
			this.textGeneralCanal.TabIndex = 75;
			this.textGeneralCanal.Text = "0,0";
			// 
			// textGeneralHotWater
			// 
			this.textGeneralHotWater.Location = new System.Drawing.Point(315, 61);
			this.textGeneralHotWater.Name = "textGeneralHotWater";
			this.textGeneralHotWater.ReadOnly = true;
			this.textGeneralHotWater.Size = new System.Drawing.Size(86, 20);
			this.textGeneralHotWater.TabIndex = 74;
			this.textGeneralHotWater.Text = "0,0";
			// 
			// textGeneralEnergy
			// 
			this.textGeneralEnergy.Location = new System.Drawing.Point(315, 112);
			this.textGeneralEnergy.Name = "textGeneralEnergy";
			this.textGeneralEnergy.ReadOnly = true;
			this.textGeneralEnergy.Size = new System.Drawing.Size(86, 20);
			this.textGeneralEnergy.TabIndex = 74;
			this.textGeneralEnergy.Text = "0,0";
			// 
			// textGeneralColdWater
			// 
			this.textGeneralColdWater.Location = new System.Drawing.Point(315, 35);
			this.textGeneralColdWater.Name = "textGeneralColdWater";
			this.textGeneralColdWater.ReadOnly = true;
			this.textGeneralColdWater.Size = new System.Drawing.Size(86, 20);
			this.textGeneralColdWater.TabIndex = 73;
			this.textGeneralColdWater.Text = "0,0";
			// 
			// labelTarifGas
			// 
			this.labelTarifGas.Location = new System.Drawing.Point(164, 142);
			this.labelTarifGas.Name = "labelTarifGas";
			this.labelTarifGas.Size = new System.Drawing.Size(53, 16);
			this.labelTarifGas.TabIndex = 72;
			this.labelTarifGas.Text = "0,0";
			// 
			// labelTarifEnergy
			// 
			this.labelTarifEnergy.Location = new System.Drawing.Point(164, 116);
			this.labelTarifEnergy.Name = "labelTarifEnergy";
			this.labelTarifEnergy.Size = new System.Drawing.Size(53, 16);
			this.labelTarifEnergy.TabIndex = 71;
			this.labelTarifEnergy.Text = "0,0";
			// 
			// labelTarifCanal
			// 
			this.labelTarifCanal.Location = new System.Drawing.Point(164, 89);
			this.labelTarifCanal.Name = "labelTarifCanal";
			this.labelTarifCanal.Size = new System.Drawing.Size(53, 16);
			this.labelTarifCanal.TabIndex = 70;
			this.labelTarifCanal.Text = "0,0";
			// 
			// labelTarifHotWater
			// 
			this.labelTarifHotWater.Location = new System.Drawing.Point(164, 63);
			this.labelTarifHotWater.Name = "labelTarifHotWater";
			this.labelTarifHotWater.Size = new System.Drawing.Size(53, 16);
			this.labelTarifHotWater.TabIndex = 69;
			this.labelTarifHotWater.Text = "0,0";
			// 
			// labelTarifColdWater
			// 
			this.labelTarifColdWater.Location = new System.Drawing.Point(164, 37);
			this.labelTarifColdWater.Name = "labelTarifColdWater";
			this.labelTarifColdWater.Size = new System.Drawing.Size(53, 16);
			this.labelTarifColdWater.TabIndex = 68;
			this.labelTarifColdWater.Text = "0,0";
			// 
			// labelMeasGas
			// 
			this.labelMeasGas.Location = new System.Drawing.Point(105, 142);
			this.labelMeasGas.Name = "labelMeasGas";
			this.labelMeasGas.Size = new System.Drawing.Size(53, 16);
			this.labelMeasGas.TabIndex = 67;
			this.labelMeasGas.Text = "0,0";
			// 
			// labelMeasEnergy
			// 
			this.labelMeasEnergy.Location = new System.Drawing.Point(105, 116);
			this.labelMeasEnergy.Name = "labelMeasEnergy";
			this.labelMeasEnergy.Size = new System.Drawing.Size(53, 16);
			this.labelMeasEnergy.TabIndex = 66;
			this.labelMeasEnergy.Text = "0,0";
			// 
			// labelMeasCanal
			// 
			this.labelMeasCanal.Location = new System.Drawing.Point(105, 89);
			this.labelMeasCanal.Name = "labelMeasCanal";
			this.labelMeasCanal.Size = new System.Drawing.Size(53, 16);
			this.labelMeasCanal.TabIndex = 65;
			this.labelMeasCanal.Text = "0,0";
			// 
			// labelMeasHotWater
			// 
			this.labelMeasHotWater.Location = new System.Drawing.Point(105, 63);
			this.labelMeasHotWater.Name = "labelMeasHotWater";
			this.labelMeasHotWater.Size = new System.Drawing.Size(53, 16);
			this.labelMeasHotWater.TabIndex = 64;
			this.labelMeasHotWater.Text = "0,0";
			// 
			// labelMeasColdWater
			// 
			this.labelMeasColdWater.Location = new System.Drawing.Point(105, 37);
			this.labelMeasColdWater.Name = "labelMeasColdWater";
			this.labelMeasColdWater.Size = new System.Drawing.Size(53, 16);
			this.labelMeasColdWater.TabIndex = 63;
			this.labelMeasColdWater.Text = "0,0";
			// 
			// textSubsidionGas
			// 
			this.textSubsidionGas.Location = new System.Drawing.Point(407, 139);
			this.textSubsidionGas.Name = "textSubsidionGas";
			this.textSubsidionGas.Size = new System.Drawing.Size(74, 20);
			this.textSubsidionGas.TabIndex = 62;
			this.textSubsidionGas.Text = "0,0";
			this.textSubsidionGas.TextChanged += new System.EventHandler(this.TextSubsidionGasTextChanged);
			// 
			// textSubsidionEnergy
			// 
			this.textSubsidionEnergy.Location = new System.Drawing.Point(407, 113);
			this.textSubsidionEnergy.Name = "textSubsidionEnergy";
			this.textSubsidionEnergy.Size = new System.Drawing.Size(74, 20);
			this.textSubsidionEnergy.TabIndex = 61;
			this.textSubsidionEnergy.Text = "0,0";
			this.textSubsidionEnergy.TextChanged += new System.EventHandler(this.TextSubsidionEnergyTextChanged);
			// 
			// textSubsidionCanal
			// 
			this.textSubsidionCanal.Location = new System.Drawing.Point(407, 87);
			this.textSubsidionCanal.Name = "textSubsidionCanal";
			this.textSubsidionCanal.Size = new System.Drawing.Size(74, 20);
			this.textSubsidionCanal.TabIndex = 60;
			this.textSubsidionCanal.Text = "0,0";
			this.textSubsidionCanal.TextChanged += new System.EventHandler(this.TextSubsidionCanalTextChanged);
			// 
			// textSubsidionHotWater
			// 
			this.textSubsidionHotWater.Location = new System.Drawing.Point(407, 61);
			this.textSubsidionHotWater.Name = "textSubsidionHotWater";
			this.textSubsidionHotWater.Size = new System.Drawing.Size(74, 20);
			this.textSubsidionHotWater.TabIndex = 59;
			this.textSubsidionHotWater.Text = "0,0";
			this.textSubsidionHotWater.TextChanged += new System.EventHandler(this.TextSubsidionHotWaterTextChanged);
			// 
			// textSubsidionColdWater
			// 
			this.textSubsidionColdWater.Location = new System.Drawing.Point(407, 35);
			this.textSubsidionColdWater.Name = "textSubsidionColdWater";
			this.textSubsidionColdWater.Size = new System.Drawing.Size(74, 20);
			this.textSubsidionColdWater.TabIndex = 58;
			this.textSubsidionColdWater.Text = "0,0";
			this.textSubsidionColdWater.TextChanged += new System.EventHandler(this.TextSubsidionColdWaterTextChanged);
			// 
			// label20
			// 
			this.label20.Location = new System.Drawing.Point(407, 17);
			this.label20.Name = "label20";
			this.label20.Size = new System.Drawing.Size(74, 16);
			this.label20.TabIndex = 57;
			this.label20.Text = "СУБСИДИЯ";
			// 
			// textVolumeGas
			// 
			this.textVolumeGas.Location = new System.Drawing.Point(223, 139);
			this.textVolumeGas.Name = "textVolumeGas";
			this.textVolumeGas.Size = new System.Drawing.Size(86, 20);
			this.textVolumeGas.TabIndex = 56;
			this.textVolumeGas.Text = "0,0";
			this.textVolumeGas.TextChanged += new System.EventHandler(this.TextVolumeEnergyTextChanged);
			// 
			// textVolumeEnergy
			// 
			this.textVolumeEnergy.Location = new System.Drawing.Point(223, 113);
			this.textVolumeEnergy.Name = "textVolumeEnergy";
			this.textVolumeEnergy.Size = new System.Drawing.Size(86, 20);
			this.textVolumeEnergy.TabIndex = 55;
			this.textVolumeEnergy.Text = "0,0";
			this.textVolumeEnergy.TextChanged += new System.EventHandler(this.TextBox3TextChanged);
			// 
			// textVolumeCanal
			// 
			this.textVolumeCanal.Location = new System.Drawing.Point(223, 87);
			this.textVolumeCanal.Name = "textVolumeCanal";
			this.textVolumeCanal.Size = new System.Drawing.Size(86, 20);
			this.textVolumeCanal.TabIndex = 54;
			this.textVolumeCanal.Text = "0,0";
			this.textVolumeCanal.TextChanged += new System.EventHandler(this.TextVolumeCanalTextChanged);
			// 
			// textVolumeHotWater
			// 
			this.textVolumeHotWater.Location = new System.Drawing.Point(223, 61);
			this.textVolumeHotWater.Name = "textVolumeHotWater";
			this.textVolumeHotWater.Size = new System.Drawing.Size(86, 20);
			this.textVolumeHotWater.TabIndex = 53;
			this.textVolumeHotWater.Text = "0,0";
			this.textVolumeHotWater.TextChanged += new System.EventHandler(this.TextVolumeHotWaterTextChanged);
			// 
			// textVolumeColdWater
			// 
			this.textVolumeColdWater.Location = new System.Drawing.Point(223, 35);
			this.textVolumeColdWater.Name = "textVolumeColdWater";
			this.textVolumeColdWater.Size = new System.Drawing.Size(86, 20);
			this.textVolumeColdWater.TabIndex = 52;
			this.textVolumeColdWater.Text = "0,0";
			this.textVolumeColdWater.TextChanged += new System.EventHandler(this.TextVolumeColdWaterTextChanged);
			// 
			// label19
			// 
			this.label19.Location = new System.Drawing.Point(223, 16);
			this.label19.Name = "label19";
			this.label19.Size = new System.Drawing.Size(86, 16);
			this.label19.TabIndex = 51;
			this.label19.Text = "ОБЪЁМ УСЛУГ";
			// 
			// label18
			// 
			this.label18.Location = new System.Drawing.Point(105, 16);
			this.label18.Name = "label18";
			this.label18.Size = new System.Drawing.Size(53, 16);
			this.label18.TabIndex = 50;
			this.label18.Text = "ЕД. ИЗМ";
			// 
			// label17
			// 
			this.label17.Location = new System.Drawing.Point(164, 16);
			this.label17.Name = "label17";
			this.label17.Size = new System.Drawing.Size(53, 16);
			this.label17.TabIndex = 49;
			this.label17.Text = "ТАРИФ";
			// 
			// label15
			// 
			this.label15.Location = new System.Drawing.Point(6, 16);
			this.label15.Name = "label15";
			this.label15.Size = new System.Drawing.Size(93, 16);
			this.label15.TabIndex = 48;
			this.label15.Text = "ВИД УСЛУГИ";
			// 
			// label14
			// 
			this.label14.Location = new System.Drawing.Point(6, 141);
			this.label14.Name = "label14";
			this.label14.Size = new System.Drawing.Size(93, 16);
			this.label14.TabIndex = 47;
			this.label14.Text = "Газ";
			// 
			// label13
			// 
			this.label13.Location = new System.Drawing.Point(6, 115);
			this.label13.Name = "label13";
			this.label13.Size = new System.Drawing.Size(93, 16);
			this.label13.TabIndex = 46;
			this.label13.Text = "Электроэнергия";
			// 
			// label11
			// 
			this.label11.Location = new System.Drawing.Point(6, 90);
			this.label11.Name = "label11";
			this.label11.Size = new System.Drawing.Size(93, 16);
			this.label11.TabIndex = 45;
			this.label11.Text = "Канализация";
			// 
			// label10
			// 
			this.label10.Location = new System.Drawing.Point(6, 63);
			this.label10.Name = "label10";
			this.label10.Size = new System.Drawing.Size(93, 16);
			this.label10.TabIndex = 44;
			this.label10.Text = "Горячая вода";
			// 
			// label9
			// 
			this.label9.Location = new System.Drawing.Point(6, 37);
			this.label9.Name = "label9";
			this.label9.Size = new System.Drawing.Size(93, 16);
			this.label9.TabIndex = 43;
			this.label9.Text = "Холодная вода";
			// 
			// dataSet
			// 
			this.dataSet.DataSetName = "NewDataSet";
			// 
			// btnSend
			// 
			this.btnSend.Location = new System.Drawing.Point(176, 416);
			this.btnSend.Name = "btnSend";
			this.btnSend.Size = new System.Drawing.Size(237, 53);
			this.btnSend.TabIndex = 86;
			this.btnSend.Text = "Отправить";
			this.btnSend.UseVisualStyleBackColor = true;
			this.btnSend.Click += new System.EventHandler(this.BtnSendClick);
			// 
			// SimplerForm
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(606, 481);
			this.Controls.Add(this.btnSend);
			this.Controls.Add(this.groupBox2);
			this.Controls.Add(this.groupBox1);
			this.Controls.Add(this.textNum);
			this.Controls.Add(this.label1);
			this.Controls.Add(this.label2);
			this.Controls.Add(this.dateMonth);
			this.Name = "SimplerForm";
			this.Text = "Один исполнитель услуг (Вариант 2)";
			this.Load += new System.EventHandler(this.SimplerFormLoad);
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
