namespace CourseProject
{
    partial class RetireForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.employeesList = new System.Windows.Forms.ListBox();
            this.label1 = new System.Windows.Forms.Label();
            this.ageGroupBox = new System.Windows.Forms.GroupBox();
            this.preRetirementAgeRadioButton = new System.Windows.Forms.RadioButton();
            this.retirementAgeRadioButton = new System.Windows.Forms.RadioButton();
            this.btnRetire = new System.Windows.Forms.Button();
            this.btnRemove = new System.Windows.Forms.Button();
            this.ageGroupBox.SuspendLayout();
            this.SuspendLayout();
            // 
            // employeesList
            // 
            this.employeesList.FormattingEnabled = true;
            this.employeesList.Location = new System.Drawing.Point(12, 25);
            this.employeesList.Name = "employeesList";
            this.employeesList.Size = new System.Drawing.Size(686, 251);
            this.employeesList.TabIndex = 0;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(12, 9);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(321, 13);
            this.label1.TabIndex = 1;
            this.label1.Text = "Следующие объекты будут уволены и отправлены на пенсию:";
            // 
            // ageGroupBox
            // 
            this.ageGroupBox.Controls.Add(this.preRetirementAgeRadioButton);
            this.ageGroupBox.Controls.Add(this.retirementAgeRadioButton);
            this.ageGroupBox.Location = new System.Drawing.Point(12, 282);
            this.ageGroupBox.Name = "ageGroupBox";
            this.ageGroupBox.Size = new System.Drawing.Size(196, 69);
            this.ageGroupBox.TabIndex = 2;
            this.ageGroupBox.TabStop = false;
            this.ageGroupBox.Text = "Возраст:";
            // 
            // preRetirementAgeRadioButton
            // 
            this.preRetirementAgeRadioButton.AutoSize = true;
            this.preRetirementAgeRadioButton.Location = new System.Drawing.Point(6, 42);
            this.preRetirementAgeRadioButton.Name = "preRetirementAgeRadioButton";
            this.preRetirementAgeRadioButton.Size = new System.Drawing.Size(187, 17);
            this.preRetirementAgeRadioButton.TabIndex = 1;
            this.preRetirementAgeRadioButton.Text = "Пенсионный + предпенсионный";
            this.preRetirementAgeRadioButton.UseVisualStyleBackColor = true;
            this.preRetirementAgeRadioButton.CheckedChanged += new System.EventHandler(this.preRetirementAgeRadioButton_CheckedChanged);
            // 
            // retirementAgeRadioButton
            // 
            this.retirementAgeRadioButton.AutoSize = true;
            this.retirementAgeRadioButton.Checked = true;
            this.retirementAgeRadioButton.Location = new System.Drawing.Point(6, 19);
            this.retirementAgeRadioButton.Name = "retirementAgeRadioButton";
            this.retirementAgeRadioButton.Size = new System.Drawing.Size(89, 17);
            this.retirementAgeRadioButton.TabIndex = 0;
            this.retirementAgeRadioButton.TabStop = true;
            this.retirementAgeRadioButton.Text = "Пенсионный";
            this.retirementAgeRadioButton.UseVisualStyleBackColor = true;
            this.retirementAgeRadioButton.CheckedChanged += new System.EventHandler(this.retirementAgeRadioButton_CheckedChanged);
            // 
            // btnRetire
            // 
            this.btnRetire.Location = new System.Drawing.Point(335, 295);
            this.btnRetire.Name = "btnRetire";
            this.btnRetire.Size = new System.Drawing.Size(72, 23);
            this.btnRetire.TabIndex = 3;
            this.btnRetire.Text = "Сократить";
            this.btnRetire.UseVisualStyleBackColor = true;
            this.btnRetire.Click += new System.EventHandler(this.btnRetire_Click);
            // 
            // btnRemove
            // 
            this.btnRemove.Location = new System.Drawing.Point(214, 295);
            this.btnRemove.Name = "btnRemove";
            this.btnRemove.Size = new System.Drawing.Size(115, 23);
            this.btnRemove.TabIndex = 4;
            this.btnRemove.Text = "Удалить из списка";
            this.btnRemove.UseVisualStyleBackColor = true;
            this.btnRemove.Click += new System.EventHandler(this.btnRemove_Click);
            // 
            // RetireForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(710, 362);
            this.Controls.Add(this.btnRemove);
            this.Controls.Add(this.btnRetire);
            this.Controls.Add(this.ageGroupBox);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.employeesList);
            this.Name = "RetireForm";
            this.Text = "RetireForm";
            this.Load += new System.EventHandler(this.RetireForm_Load);
            this.ageGroupBox.ResumeLayout(false);
            this.ageGroupBox.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ListBox employeesList;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.GroupBox ageGroupBox;
        private System.Windows.Forms.RadioButton preRetirementAgeRadioButton;
        private System.Windows.Forms.RadioButton retirementAgeRadioButton;
        private System.Windows.Forms.Button btnRetire;
        private System.Windows.Forms.Button btnRemove;
    }
}