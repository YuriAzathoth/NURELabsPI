/*
 * Создано в SharpDevelop.
 * Пользователь: Master
 * Дата: 04.11.2018
 * Время: 17:33
 * 
 * Для изменения этого шаблона используйте меню "Инструменты | Параметры | Кодирование | Стандартные заголовки".
 */
namespace Hostel
{
	partial class EditForm
	{
		/// <summary>
		/// Designer variable used to keep track of non-visual components.
		/// </summary>
		private System.ComponentModel.IContainer components = null;
		private System.Windows.Forms.TextBox textName;
		private System.Windows.Forms.Label label1;
		private System.Windows.Forms.ComboBox comboGender;
		private System.Windows.Forms.Label label3;
		private System.Windows.Forms.TextBox textAddress;
		private System.Windows.Forms.Label label4;
		private System.Windows.Forms.TextBox textGroup;
		private System.Windows.Forms.Label label5;
		private System.Windows.Forms.ComboBox comboBenefit;
		private System.Windows.Forms.Label label6;
		private System.Windows.Forms.BindingSource benefitsBindingSource;
		private System.Windows.Forms.Label label7;
		private System.Windows.Forms.MaskedTextBox textPassport;
		private System.Windows.Forms.ComboBox comboRoom;
		private System.Windows.Forms.Label label8;
		private System.Windows.Forms.Button btnOk;
		private System.Windows.Forms.Button btnCancel;
		private System.Windows.Forms.BindingSource roomsBindingSource;
		private System.Windows.Forms.BindingSource studentsBindingSource;
		private System.Windows.Forms.Label label9;
		private System.Windows.Forms.TextBox textBirthYear;
		private System.Windows.Forms.DateTimePicker dateSettle;
		private System.Windows.Forms.Label label2;
		
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
			this.textName = new System.Windows.Forms.TextBox();
			this.label1 = new System.Windows.Forms.Label();
			this.comboGender = new System.Windows.Forms.ComboBox();
			this.label3 = new System.Windows.Forms.Label();
			this.textAddress = new System.Windows.Forms.TextBox();
			this.label4 = new System.Windows.Forms.Label();
			this.textGroup = new System.Windows.Forms.TextBox();
			this.label5 = new System.Windows.Forms.Label();
			this.comboBenefit = new System.Windows.Forms.ComboBox();
			this.label6 = new System.Windows.Forms.Label();
			this.benefitsBindingSource = new System.Windows.Forms.BindingSource(this.components);
			this.label7 = new System.Windows.Forms.Label();
			this.comboRoom = new System.Windows.Forms.ComboBox();
			this.label8 = new System.Windows.Forms.Label();
			this.btnOk = new System.Windows.Forms.Button();
			this.btnCancel = new System.Windows.Forms.Button();
			this.roomsBindingSource = new System.Windows.Forms.BindingSource(this.components);
			this.studentsBindingSource = new System.Windows.Forms.BindingSource(this.components);
			this.label9 = new System.Windows.Forms.Label();
			this.textBirthYear = new System.Windows.Forms.TextBox();
			this.dateSettle = new System.Windows.Forms.DateTimePicker();
			this.label2 = new System.Windows.Forms.Label();
			this.textPassport = new System.Windows.Forms.MaskedTextBox();
			((System.ComponentModel.ISupportInitialize)(this.benefitsBindingSource)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.roomsBindingSource)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.studentsBindingSource)).BeginInit();
			this.SuspendLayout();
			// 
			// textName
			// 
			this.textName.Location = new System.Drawing.Point(156, 12);
			this.textName.Name = "textName";
			this.textName.Size = new System.Drawing.Size(276, 26);
			this.textName.TabIndex = 0;
			// 
			// label1
			// 
			this.label1.Location = new System.Drawing.Point(12, 15);
			this.label1.Name = "label1";
			this.label1.Size = new System.Drawing.Size(138, 23);
			this.label1.TabIndex = 1;
			this.label1.Text = "Фио";
			// 
			// comboGender
			// 
			this.comboGender.FormattingEnabled = true;
			this.comboGender.Items.AddRange(new object[] {
			"Мужской",
			"Женский"});
			this.comboGender.Location = new System.Drawing.Point(156, 76);
			this.comboGender.Name = "comboGender";
			this.comboGender.Size = new System.Drawing.Size(276, 28);
			this.comboGender.TabIndex = 4;
			// 
			// label3
			// 
			this.label3.Location = new System.Drawing.Point(12, 81);
			this.label3.Name = "label3";
			this.label3.Size = new System.Drawing.Size(138, 23);
			this.label3.TabIndex = 5;
			this.label3.Text = "Пол";
			// 
			// textAddress
			// 
			this.textAddress.Location = new System.Drawing.Point(156, 110);
			this.textAddress.Name = "textAddress";
			this.textAddress.Size = new System.Drawing.Size(276, 26);
			this.textAddress.TabIndex = 6;
			// 
			// label4
			// 
			this.label4.Location = new System.Drawing.Point(12, 113);
			this.label4.Name = "label4";
			this.label4.Size = new System.Drawing.Size(138, 23);
			this.label4.TabIndex = 7;
			this.label4.Text = "Адрес";
			// 
			// textGroup
			// 
			this.textGroup.Location = new System.Drawing.Point(156, 142);
			this.textGroup.Name = "textGroup";
			this.textGroup.Size = new System.Drawing.Size(276, 26);
			this.textGroup.TabIndex = 8;
			// 
			// label5
			// 
			this.label5.Location = new System.Drawing.Point(12, 145);
			this.label5.Name = "label5";
			this.label5.Size = new System.Drawing.Size(138, 23);
			this.label5.TabIndex = 9;
			this.label5.Text = "Группа";
			// 
			// comboBenefit
			// 
			this.comboBenefit.FormattingEnabled = true;
			this.comboBenefit.Location = new System.Drawing.Point(156, 174);
			this.comboBenefit.Name = "comboBenefit";
			this.comboBenefit.Size = new System.Drawing.Size(276, 28);
			this.comboBenefit.TabIndex = 10;
			// 
			// label6
			// 
			this.label6.Location = new System.Drawing.Point(12, 177);
			this.label6.Name = "label6";
			this.label6.Size = new System.Drawing.Size(138, 23);
			this.label6.TabIndex = 11;
			this.label6.Text = "Тип льготы";
			// 
			// label7
			// 
			this.label7.Location = new System.Drawing.Point(12, 211);
			this.label7.Name = "label7";
			this.label7.Size = new System.Drawing.Size(138, 23);
			this.label7.TabIndex = 13;
			this.label7.Text = "Паспорт";
			// 
			// comboRoom
			// 
			this.comboRoom.DisplayMember = "Комнаты.№ комнаты";
			this.comboRoom.FormattingEnabled = true;
			this.comboRoom.Location = new System.Drawing.Point(156, 240);
			this.comboRoom.Name = "comboRoom";
			this.comboRoom.Size = new System.Drawing.Size(276, 28);
			this.comboRoom.TabIndex = 14;
			this.comboRoom.ValueMember = "Комнаты.№ комнаты";
			// 
			// label8
			// 
			this.label8.Location = new System.Drawing.Point(12, 243);
			this.label8.Name = "label8";
			this.label8.Size = new System.Drawing.Size(138, 23);
			this.label8.TabIndex = 15;
			this.label8.Text = "Комната";
			// 
			// btnOk
			// 
			this.btnOk.Location = new System.Drawing.Point(12, 316);
			this.btnOk.Name = "btnOk";
			this.btnOk.Size = new System.Drawing.Size(201, 36);
			this.btnOk.TabIndex = 16;
			this.btnOk.Text = "OK";
			this.btnOk.UseVisualStyleBackColor = true;
			this.btnOk.Click += new System.EventHandler(this.BtnOkClick);
			// 
			// btnCancel
			// 
			this.btnCancel.Location = new System.Drawing.Point(219, 316);
			this.btnCancel.Name = "btnCancel";
			this.btnCancel.Size = new System.Drawing.Size(213, 36);
			this.btnCancel.TabIndex = 17;
			this.btnCancel.Text = "Отмена";
			this.btnCancel.UseVisualStyleBackColor = true;
			this.btnCancel.Click += new System.EventHandler(this.BtnCancelClick);
			// 
			// label9
			// 
			this.label9.Location = new System.Drawing.Point(12, 44);
			this.label9.Name = "label9";
			this.label9.Size = new System.Drawing.Size(138, 23);
			this.label9.TabIndex = 19;
			this.label9.Text = "Год рождения";
			// 
			// textBirthYear
			// 
			this.textBirthYear.Location = new System.Drawing.Point(156, 44);
			this.textBirthYear.Name = "textBirthYear";
			this.textBirthYear.Size = new System.Drawing.Size(276, 26);
			this.textBirthYear.TabIndex = 20;
			// 
			// dateSettle
			// 
			this.dateSettle.Location = new System.Drawing.Point(156, 274);
			this.dateSettle.Name = "dateSettle";
			this.dateSettle.Size = new System.Drawing.Size(276, 26);
			this.dateSettle.TabIndex = 21;
			// 
			// label2
			// 
			this.label2.Location = new System.Drawing.Point(12, 274);
			this.label2.Name = "label2";
			this.label2.Size = new System.Drawing.Size(138, 23);
			this.label2.TabIndex = 22;
			this.label2.Text = "Дата заселения";
			// 
			// textPassport
			// 
			this.textPassport.Location = new System.Drawing.Point(156, 208);
			this.textPassport.Mask = "AA000000";
			this.textPassport.Name = "textPassport";
			this.textPassport.Size = new System.Drawing.Size(276, 26);
			this.textPassport.TabIndex = 23;
			// 
			// EditForm
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(444, 365);
			this.Controls.Add(this.textPassport);
			this.Controls.Add(this.label2);
			this.Controls.Add(this.dateSettle);
			this.Controls.Add(this.textBirthYear);
			this.Controls.Add(this.label9);
			this.Controls.Add(this.btnCancel);
			this.Controls.Add(this.btnOk);
			this.Controls.Add(this.label8);
			this.Controls.Add(this.comboRoom);
			this.Controls.Add(this.label7);
			this.Controls.Add(this.label6);
			this.Controls.Add(this.comboBenefit);
			this.Controls.Add(this.label5);
			this.Controls.Add(this.textGroup);
			this.Controls.Add(this.label4);
			this.Controls.Add(this.textAddress);
			this.Controls.Add(this.label3);
			this.Controls.Add(this.comboGender);
			this.Controls.Add(this.label1);
			this.Controls.Add(this.textName);
			this.Name = "EditForm";
			this.Text = "EditForm";
			this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.EditFormFormClosing);
			this.Load += new System.EventHandler(this.EditFormLoad);
			((System.ComponentModel.ISupportInitialize)(this.benefitsBindingSource)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.roomsBindingSource)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.studentsBindingSource)).EndInit();
			this.ResumeLayout(false);
			this.PerformLayout();

		}
	}
}
