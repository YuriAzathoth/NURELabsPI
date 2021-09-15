/*
 * Created by SharpDevelop.
 * User: Master
 * Date: 30.03.2020
 * Time: 1:30
 * 
 * To change this template use Tools | Options | Coding | Edit Standard Headers.
 */
namespace Lab2Client
{
	partial class MainForm
	{
		/// <summary>
		/// Designer variable used to keep track of non-visual components.
		/// </summary>
		private System.ComponentModel.IContainer components = null;
		
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
			this.label1 = new System.Windows.Forms.Label();
			this.label2 = new System.Windows.Forms.Label();
			this.m_txtLogin = new System.Windows.Forms.TextBox();
			this.m_txtPass = new System.Windows.Forms.TextBox();
			this.m_btnSend = new System.Windows.Forms.Button();
			this.SuspendLayout();
			// 
			// label1
			// 
			this.label1.Location = new System.Drawing.Point(12, 9);
			this.label1.Name = "label1";
			this.label1.Size = new System.Drawing.Size(60, 17);
			this.label1.TabIndex = 0;
			this.label1.Text = "Login";
			// 
			// label2
			// 
			this.label2.Location = new System.Drawing.Point(12, 38);
			this.label2.Name = "label2";
			this.label2.Size = new System.Drawing.Size(60, 17);
			this.label2.TabIndex = 1;
			this.label2.Text = "Password";
			// 
			// m_txtLogin
			// 
			this.m_txtLogin.Location = new System.Drawing.Point(78, 6);
			this.m_txtLogin.Name = "m_txtLogin";
			this.m_txtLogin.Size = new System.Drawing.Size(156, 20);
			this.m_txtLogin.TabIndex = 2;
			// 
			// m_txtPass
			// 
			this.m_txtPass.Location = new System.Drawing.Point(78, 35);
			this.m_txtPass.Name = "m_txtPass";
			this.m_txtPass.Size = new System.Drawing.Size(156, 20);
			this.m_txtPass.TabIndex = 3;
			// 
			// m_btnSend
			// 
			this.m_btnSend.Location = new System.Drawing.Point(12, 61);
			this.m_btnSend.Name = "m_btnSend";
			this.m_btnSend.Size = new System.Drawing.Size(222, 30);
			this.m_btnSend.TabIndex = 4;
			this.m_btnSend.Text = "Send";
			this.m_btnSend.UseVisualStyleBackColor = true;
			// 
			// MainForm
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(246, 103);
			this.Controls.Add(this.m_btnSend);
			this.Controls.Add(this.m_txtPass);
			this.Controls.Add(this.m_txtLogin);
			this.Controls.Add(this.label2);
			this.Controls.Add(this.label1);
			this.Name = "MainForm";
			this.Text = "Lab2Client";
			this.ResumeLayout(false);
			this.PerformLayout();

		}
		protected System.Windows.Forms.Button m_btnSend;
		private System.Windows.Forms.TextBox m_txtPass;
		private System.Windows.Forms.TextBox m_txtLogin;
		private System.Windows.Forms.Label label2;
		private System.Windows.Forms.Label label1;
	}
}
