namespace CourseProject
{
    partial class OrderForm
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
            this.noteLabel = new System.Windows.Forms.Label();
            this.btnForm = new System.Windows.Forms.Button();
            this.selectedEmployeesList = new System.Windows.Forms.ListBox();
            this.selectedEmployeesLabel = new System.Windows.Forms.Label();
            this.btnDelete = new System.Windows.Forms.Button();
            this.panel1 = new System.Windows.Forms.Panel();
            this.btnRemoveOrderType = new System.Windows.Forms.Button();
            this.btnRemember = new System.Windows.Forms.Button();
            this.label13 = new System.Windows.Forms.Label();
            this.label12 = new System.Windows.Forms.Label();
            this.label10 = new System.Windows.Forms.Label();
            this.causeText = new System.Windows.Forms.TextBox();
            this.label11 = new System.Windows.Forms.Label();
            this.reasonText = new System.Windows.Forms.TextBox();
            this.label9 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.descriptionText = new System.Windows.Forms.TextBox();
            this.label7 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.actionCombo = new System.Windows.Forms.ComboBox();
            this.label5 = new System.Windows.Forms.Label();
            this.dateLabel = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.orderNumLabel = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.panel1.SuspendLayout();
            this.SuspendLayout();
            // 
            // noteLabel
            // 
            this.noteLabel.AutoSize = true;
            this.noteLabel.Location = new System.Drawing.Point(12, 15);
            this.noteLabel.Name = "noteLabel";
            this.noteLabel.Size = new System.Drawing.Size(266, 13);
            this.noteLabel.TabIndex = 1;
            this.noteLabel.Text = "Формировать приказ для выбранных сотрудников";
            // 
            // btnForm
            // 
            this.btnForm.Location = new System.Drawing.Point(545, 402);
            this.btnForm.Name = "btnForm";
            this.btnForm.Size = new System.Drawing.Size(100, 23);
            this.btnForm.TabIndex = 3;
            this.btnForm.Text = "Формировать";
            this.btnForm.UseVisualStyleBackColor = true;
            this.btnForm.Click += new System.EventHandler(this.btnForm_Click);
            // 
            // selectedEmployeesList
            // 
            this.selectedEmployeesList.FormattingEnabled = true;
            this.selectedEmployeesList.Location = new System.Drawing.Point(545, 28);
            this.selectedEmployeesList.Name = "selectedEmployeesList";
            this.selectedEmployeesList.Size = new System.Drawing.Size(224, 368);
            this.selectedEmployeesList.TabIndex = 4;
            // 
            // selectedEmployeesLabel
            // 
            this.selectedEmployeesLabel.AutoSize = true;
            this.selectedEmployeesLabel.Location = new System.Drawing.Point(542, 9);
            this.selectedEmployeesLabel.Name = "selectedEmployeesLabel";
            this.selectedEmployeesLabel.Size = new System.Drawing.Size(130, 13);
            this.selectedEmployeesLabel.TabIndex = 5;
            this.selectedEmployeesLabel.Text = "Выбранные сотрудники:";
            // 
            // btnDelete
            // 
            this.btnDelete.Location = new System.Drawing.Point(652, 402);
            this.btnDelete.Name = "btnDelete";
            this.btnDelete.Size = new System.Drawing.Size(118, 23);
            this.btnDelete.TabIndex = 6;
            this.btnDelete.Text = "Удалить из списка";
            this.btnDelete.UseVisualStyleBackColor = true;
            this.btnDelete.Click += new System.EventHandler(this.btnDelete_Click);
            // 
            // panel1
            // 
            this.panel1.Controls.Add(this.btnRemoveOrderType);
            this.panel1.Controls.Add(this.btnRemember);
            this.panel1.Controls.Add(this.label13);
            this.panel1.Controls.Add(this.label12);
            this.panel1.Controls.Add(this.label10);
            this.panel1.Controls.Add(this.causeText);
            this.panel1.Controls.Add(this.label11);
            this.panel1.Controls.Add(this.reasonText);
            this.panel1.Controls.Add(this.label9);
            this.panel1.Controls.Add(this.label8);
            this.panel1.Controls.Add(this.descriptionText);
            this.panel1.Controls.Add(this.label7);
            this.panel1.Controls.Add(this.label6);
            this.panel1.Controls.Add(this.actionCombo);
            this.panel1.Controls.Add(this.label5);
            this.panel1.Controls.Add(this.dateLabel);
            this.panel1.Controls.Add(this.label4);
            this.panel1.Controls.Add(this.orderNumLabel);
            this.panel1.Controls.Add(this.label3);
            this.panel1.Controls.Add(this.label2);
            this.panel1.Controls.Add(this.label1);
            this.panel1.Location = new System.Drawing.Point(15, 31);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(524, 394);
            this.panel1.TabIndex = 7;
            // 
            // btnRemoveOrderType
            // 
            this.btnRemoveOrderType.Location = new System.Drawing.Point(314, 176);
            this.btnRemoveOrderType.Name = "btnRemoveOrderType";
            this.btnRemoveOrderType.Size = new System.Drawing.Size(138, 23);
            this.btnRemoveOrderType.TabIndex = 21;
            this.btnRemoveOrderType.Text = "Удалить тип приказа";
            this.btnRemoveOrderType.UseVisualStyleBackColor = true;
            this.btnRemoveOrderType.Click += new System.EventHandler(this.btnRemoveOrderType_Click);
            // 
            // btnRemember
            // 
            this.btnRemember.Location = new System.Drawing.Point(170, 176);
            this.btnRemember.Name = "btnRemember";
            this.btnRemember.Size = new System.Drawing.Size(138, 23);
            this.btnRemember.TabIndex = 20;
            this.btnRemember.Text = "Запомнить тип приказа";
            this.btnRemember.UseVisualStyleBackColor = true;
            this.btnRemember.Click += new System.EventHandler(this.btnRemember_Click);
            // 
            // label13
            // 
            this.label13.AutoSize = true;
            this.label13.Location = new System.Drawing.Point(356, 272);
            this.label13.Name = "label13";
            this.label13.Size = new System.Drawing.Size(54, 13);
            this.label13.TabIndex = 19;
            this.label13.Text = "(причина)";
            // 
            // label12
            // 
            this.label12.AutoSize = true;
            this.label12.Location = new System.Drawing.Point(113, 272);
            this.label12.Name = "label12";
            this.label12.Size = new System.Drawing.Size(64, 13);
            this.label12.TabIndex = 18;
            this.label12.Text = "(уточнение)";
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Location = new System.Drawing.Point(28, 202);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(60, 13);
            this.label10.TabIndex = 17;
            this.label10.Text = "(действие)";
            // 
            // causeText
            // 
            this.causeText.Location = new System.Drawing.Point(75, 307);
            this.causeText.Name = "causeText";
            this.causeText.Size = new System.Drawing.Size(256, 20);
            this.causeText.TabIndex = 16;
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.Location = new System.Drawing.Point(3, 310);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(66, 13);
            this.label11.TabIndex = 15;
            this.label11.Text = "Основание:";
            // 
            // reasonText
            // 
            this.reasonText.Location = new System.Drawing.Point(240, 249);
            this.reasonText.Name = "reasonText";
            this.reasonText.Size = new System.Drawing.Size(281, 20);
            this.reasonText.TabIndex = 13;
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(3, 373);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(242, 13);
            this.label9.TabIndex = 12;
            this.label9.Text = "С приказом ознакомлен:  ____________ (имя)";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(3, 351);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(201, 13);
            this.label8.TabIndex = 11;
            this.label8.Text = "Директор __________ С. В. Малышко.";
            // 
            // descriptionText
            // 
            this.descriptionText.Location = new System.Drawing.Point(42, 249);
            this.descriptionText.Name = "descriptionText";
            this.descriptionText.Size = new System.Drawing.Size(192, 20);
            this.descriptionText.TabIndex = 10;
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(3, 252);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(33, 13);
            this.label7.TabIndex = 9;
            this.label7.Text = "(имя)";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(130, 181);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(10, 13);
            this.label6.TabIndex = 8;
            this.label6.Text = ":";
            // 
            // actionCombo
            // 
            this.actionCombo.FormattingEnabled = true;
            this.actionCombo.Location = new System.Drawing.Point(3, 178);
            this.actionCombo.Name = "actionCombo";
            this.actionCombo.Size = new System.Drawing.Size(121, 21);
            this.actionCombo.TabIndex = 7;
            this.actionCombo.SelectedIndexChanged += new System.EventHandler(this.actionCombo_SelectedIndexChanged);
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(279, 138);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(67, 13);
            this.label5.TabIndex = 6;
            this.label5.Text = "г. Харькова";
            // 
            // dateLabel
            // 
            this.dateLabel.AutoSize = true;
            this.dateLabel.Location = new System.Drawing.Point(212, 138);
            this.dateLabel.Name = "dateLabel";
            this.dateLabel.Size = new System.Drawing.Size(61, 13);
            this.dateLabel.TabIndex = 5;
            this.dateLabel.Text = "00.00.0000";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(188, 138);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(18, 13);
            this.label4.TabIndex = 4;
            this.label4.Text = "от";
            // 
            // orderNumLabel
            // 
            this.orderNumLabel.AutoSize = true;
            this.orderNumLabel.Location = new System.Drawing.Point(269, 98);
            this.orderNumLabel.Name = "orderNumLabel";
            this.orderNumLabel.Size = new System.Drawing.Size(13, 13);
            this.orderNumLabel.TabIndex = 3;
            this.orderNumLabel.Text = "0";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(242, 98);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(21, 13);
            this.label3.TabIndex = 2;
            this.label3.Text = "№ ";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(240, 50);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(51, 13);
            this.label2.TabIndex = 1;
            this.label2.Text = "ПРИКАЗ";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(113, 10);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(324, 13);
            this.label1.TabIndex = 0;
            this.label1.Text = "Общество с ограниченной ответственностью \\\"Новый Софт\\\"";
            // 
            // OrderForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(782, 437);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.btnDelete);
            this.Controls.Add(this.selectedEmployeesLabel);
            this.Controls.Add(this.selectedEmployeesList);
            this.Controls.Add(this.btnForm);
            this.Controls.Add(this.noteLabel);
            this.Name = "OrderForm";
            this.Text = "Формирование приказа";
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.Label noteLabel;
        private System.Windows.Forms.Button btnForm;
        private System.Windows.Forms.ListBox selectedEmployeesList;
        private System.Windows.Forms.Label selectedEmployeesLabel;
        private System.Windows.Forms.Button btnDelete;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label orderNumLabel;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label dateLabel;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.ComboBox actionCombo;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.TextBox descriptionText;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.TextBox reasonText;
        private System.Windows.Forms.TextBox causeText;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.Label label13;
        private System.Windows.Forms.Label label12;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.Button btnRemember;
        private System.Windows.Forms.Button btnRemoveOrderType;
    }
}