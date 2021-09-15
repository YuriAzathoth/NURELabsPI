/*
 * Создано в SharpDevelop.
 * Пользователь: Yuri Zinchenko
 * Дата: 08.11.2018
 * Время: 15:05
*/
namespace Variant01
{
	partial class MainForm
	{
		/// <summary>
		/// Designer variable used to keep track of non-visual components.
		/// </summary>
		private System.ComponentModel.IContainer components = null;
		private System.Windows.Forms.Button btnGeneral;
		private System.Windows.Forms.Button btnConcrete;
		private System.Windows.Forms.Button btnEasy;
		private System.Windows.Forms.Button btnOneService;
		
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
			this.btnGeneral = new System.Windows.Forms.Button();
			this.btnConcrete = new System.Windows.Forms.Button();
			this.btnEasy = new System.Windows.Forms.Button();
			this.btnOneService = new System.Windows.Forms.Button();
			this.SuspendLayout();
			// 
			// btnGeneral
			// 
			this.btnGeneral.Location = new System.Drawing.Point(12, 12);
			this.btnGeneral.Name = "btnGeneral";
			this.btnGeneral.Size = new System.Drawing.Size(178, 23);
			this.btnGeneral.TabIndex = 0;
			this.btnGeneral.Text = "Общий";
			this.btnGeneral.UseVisualStyleBackColor = true;
			this.btnGeneral.Click += new System.EventHandler(this.BtnGeneralClick);
			// 
			// btnConcrete
			// 
			this.btnConcrete.Location = new System.Drawing.Point(12, 41);
			this.btnConcrete.Name = "btnConcrete";
			this.btnConcrete.Size = new System.Drawing.Size(178, 23);
			this.btnConcrete.TabIndex = 1;
			this.btnConcrete.Text = "Один комунальный";
			this.btnConcrete.UseVisualStyleBackColor = true;
			this.btnConcrete.Click += new System.EventHandler(this.BtnConcreteClick);
			// 
			// btnEasy
			// 
			this.btnEasy.Location = new System.Drawing.Point(12, 70);
			this.btnEasy.Name = "btnEasy";
			this.btnEasy.Size = new System.Drawing.Size(178, 23);
			this.btnEasy.TabIndex = 2;
			this.btnEasy.Text = "Упрощённый";
			this.btnEasy.UseVisualStyleBackColor = true;
			this.btnEasy.Click += new System.EventHandler(this.BtnEasyClick);
			// 
			// btnOneService
			// 
			this.btnOneService.Location = new System.Drawing.Point(12, 99);
			this.btnOneService.Name = "btnOneService";
			this.btnOneService.Size = new System.Drawing.Size(178, 23);
			this.btnOneService.TabIndex = 3;
			this.btnOneService.Text = "Одна услуга";
			this.btnOneService.UseVisualStyleBackColor = true;
			this.btnOneService.Click += new System.EventHandler(this.BtnOneServiceClick);
			// 
			// MainForm
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(202, 134);
			this.Controls.Add(this.btnOneService);
			this.Controls.Add(this.btnEasy);
			this.Controls.Add(this.btnConcrete);
			this.Controls.Add(this.btnGeneral);
			this.Name = "MainForm";
			this.Text = "Комунальные услуги";
			this.ResumeLayout(false);

		}
	}
}
