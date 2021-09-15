namespace CourseProject
{
    partial class InsertDataForm
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
            this.passportDataGroupBox = new System.Windows.Forms.GroupBox();
            this.apartmentText = new System.Windows.Forms.MaskedTextBox();
            this.passportNumLabel = new System.Windows.Forms.Label();
            this.issueDateLabel = new System.Windows.Forms.Label();
            this.passportNumText = new System.Windows.Forms.MaskedTextBox();
            this.issueDatePicker = new System.Windows.Forms.DateTimePicker();
            this.apartmentLabel = new System.Windows.Forms.Label();
            this.houseText = new System.Windows.Forms.TextBox();
            this.houseLabel = new System.Windows.Forms.Label();
            this.adressLabel = new System.Windows.Forms.Label();
            this.addressText = new System.Windows.Forms.TextBox();
            this.birthPlaceLabel = new System.Windows.Forms.Label();
            this.birthPlaceText = new System.Windows.Forms.TextBox();
            this.birthDatePicker = new System.Windows.Forms.DateTimePicker();
            this.birthDateLabel = new System.Windows.Forms.Label();
            this.fatherNameLabel = new System.Windows.Forms.Label();
            this.fatherNameText = new System.Windows.Forms.TextBox();
            this.nameLabel = new System.Windows.Forms.Label();
            this.nameText = new System.Windows.Forms.TextBox();
            this.surnameLabel = new System.Windows.Forms.Label();
            this.surnameText = new System.Windows.Forms.TextBox();
            this.employeeInfoGroupBox = new System.Windows.Forms.GroupBox();
            this.salaryLabel = new System.Windows.Forms.Label();
            this.salaryNumeric = new System.Windows.Forms.NumericUpDown();
            this.appointmentDateLabel = new System.Windows.Forms.Label();
            this.appointmentDatePicker = new System.Windows.Forms.DateTimePicker();
            this.employmentDateLabel = new System.Windows.Forms.Label();
            this.employmentDatePicker = new System.Windows.Forms.DateTimePicker();
            this.educationLabel = new System.Windows.Forms.Label();
            this.educationText = new System.Windows.Forms.TextBox();
            this.specialityLabel = new System.Windows.Forms.Label();
            this.specialityText = new System.Windows.Forms.TextBox();
            this.positionLabel = new System.Windows.Forms.Label();
            this.positionText = new System.Windows.Forms.TextBox();
            this.departmentLabel = new System.Windows.Forms.Label();
            this.departmentText = new System.Windows.Forms.TextBox();
            this.btnAdd = new System.Windows.Forms.Button();
            this.passportDataGroupBox.SuspendLayout();
            this.employeeInfoGroupBox.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.salaryNumeric)).BeginInit();
            this.SuspendLayout();
            // 
            // passportDataGroupBox
            // 
            this.passportDataGroupBox.Controls.Add(this.apartmentText);
            this.passportDataGroupBox.Controls.Add(this.passportNumLabel);
            this.passportDataGroupBox.Controls.Add(this.issueDateLabel);
            this.passportDataGroupBox.Controls.Add(this.passportNumText);
            this.passportDataGroupBox.Controls.Add(this.issueDatePicker);
            this.passportDataGroupBox.Controls.Add(this.apartmentLabel);
            this.passportDataGroupBox.Controls.Add(this.houseText);
            this.passportDataGroupBox.Controls.Add(this.houseLabel);
            this.passportDataGroupBox.Controls.Add(this.adressLabel);
            this.passportDataGroupBox.Controls.Add(this.addressText);
            this.passportDataGroupBox.Controls.Add(this.birthPlaceLabel);
            this.passportDataGroupBox.Controls.Add(this.birthPlaceText);
            this.passportDataGroupBox.Controls.Add(this.birthDatePicker);
            this.passportDataGroupBox.Controls.Add(this.birthDateLabel);
            this.passportDataGroupBox.Controls.Add(this.fatherNameLabel);
            this.passportDataGroupBox.Controls.Add(this.fatherNameText);
            this.passportDataGroupBox.Controls.Add(this.nameLabel);
            this.passportDataGroupBox.Controls.Add(this.nameText);
            this.passportDataGroupBox.Controls.Add(this.surnameLabel);
            this.passportDataGroupBox.Controls.Add(this.surnameText);
            this.passportDataGroupBox.Location = new System.Drawing.Point(12, 12);
            this.passportDataGroupBox.Name = "passportDataGroupBox";
            this.passportDataGroupBox.Size = new System.Drawing.Size(303, 284);
            this.passportDataGroupBox.TabIndex = 0;
            this.passportDataGroupBox.TabStop = false;
            this.passportDataGroupBox.Text = "Паспортные данные";
            // 
            // apartmentText
            // 
            this.apartmentText.Location = new System.Drawing.Point(107, 201);
            this.apartmentText.Mask = "0000";
            this.apartmentText.Name = "apartmentText";
            this.apartmentText.Size = new System.Drawing.Size(190, 20);
            this.apartmentText.TabIndex = 21;
            // 
            // passportNumLabel
            // 
            this.passportNumLabel.AutoSize = true;
            this.passportNumLabel.Location = new System.Drawing.Point(6, 230);
            this.passportNumLabel.Name = "passportNumLabel";
            this.passportNumLabel.Size = new System.Drawing.Size(94, 13);
            this.passportNumLabel.TabIndex = 20;
            this.passportNumLabel.Text = "Номер паспорта:";
            // 
            // issueDateLabel
            // 
            this.issueDateLabel.AutoSize = true;
            this.issueDateLabel.Location = new System.Drawing.Point(6, 253);
            this.issueDateLabel.Name = "issueDateLabel";
            this.issueDateLabel.Size = new System.Drawing.Size(76, 13);
            this.issueDateLabel.TabIndex = 18;
            this.issueDateLabel.Text = "Дата выдачи:";
            // 
            // passportNumText
            // 
            this.passportNumText.Location = new System.Drawing.Point(107, 227);
            this.passportNumText.Mask = "AA000000";
            this.passportNumText.Name = "passportNumText";
            this.passportNumText.Size = new System.Drawing.Size(190, 20);
            this.passportNumText.TabIndex = 19;
            // 
            // issueDatePicker
            // 
            this.issueDatePicker.Location = new System.Drawing.Point(107, 253);
            this.issueDatePicker.Name = "issueDatePicker";
            this.issueDatePicker.Size = new System.Drawing.Size(190, 20);
            this.issueDatePicker.TabIndex = 17;
            // 
            // apartmentLabel
            // 
            this.apartmentLabel.AutoSize = true;
            this.apartmentLabel.Location = new System.Drawing.Point(6, 204);
            this.apartmentLabel.Name = "apartmentLabel";
            this.apartmentLabel.Size = new System.Drawing.Size(58, 13);
            this.apartmentLabel.TabIndex = 16;
            this.apartmentLabel.Text = "Квартира:";
            // 
            // houseText
            // 
            this.houseText.Location = new System.Drawing.Point(107, 175);
            this.houseText.MaxLength = 4;
            this.houseText.Name = "houseText";
            this.houseText.Size = new System.Drawing.Size(190, 20);
            this.houseText.TabIndex = 14;
            // 
            // houseLabel
            // 
            this.houseLabel.AutoSize = true;
            this.houseLabel.Location = new System.Drawing.Point(6, 178);
            this.houseLabel.Name = "houseLabel";
            this.houseLabel.Size = new System.Drawing.Size(33, 13);
            this.houseLabel.TabIndex = 13;
            this.houseLabel.Text = "Дом:";
            // 
            // adressLabel
            // 
            this.adressLabel.AutoSize = true;
            this.adressLabel.Location = new System.Drawing.Point(6, 152);
            this.adressLabel.Name = "adressLabel";
            this.adressLabel.Size = new System.Drawing.Size(98, 13);
            this.adressLabel.TabIndex = 11;
            this.adressLabel.Text = "Домашний адрес:";
            // 
            // addressText
            // 
            this.addressText.Location = new System.Drawing.Point(107, 149);
            this.addressText.MaxLength = 30;
            this.addressText.Name = "addressText";
            this.addressText.Size = new System.Drawing.Size(190, 20);
            this.addressText.TabIndex = 10;
            // 
            // birthPlaceLabel
            // 
            this.birthPlaceLabel.AutoSize = true;
            this.birthPlaceLabel.Location = new System.Drawing.Point(6, 126);
            this.birthPlaceLabel.Name = "birthPlaceLabel";
            this.birthPlaceLabel.Size = new System.Drawing.Size(95, 13);
            this.birthPlaceLabel.TabIndex = 9;
            this.birthPlaceLabel.Text = "Место рождения:";
            // 
            // birthPlaceText
            // 
            this.birthPlaceText.Location = new System.Drawing.Point(107, 123);
            this.birthPlaceText.MaxLength = 20;
            this.birthPlaceText.Name = "birthPlaceText";
            this.birthPlaceText.Size = new System.Drawing.Size(190, 20);
            this.birthPlaceText.TabIndex = 8;
            // 
            // birthDatePicker
            // 
            this.birthDatePicker.Location = new System.Drawing.Point(107, 97);
            this.birthDatePicker.Name = "birthDatePicker";
            this.birthDatePicker.Size = new System.Drawing.Size(190, 20);
            this.birthDatePicker.TabIndex = 7;
            this.birthDatePicker.ValueChanged += new System.EventHandler(this.birthDatePicker_ValueChanged);
            // 
            // birthDateLabel
            // 
            this.birthDateLabel.AutoSize = true;
            this.birthDateLabel.Location = new System.Drawing.Point(6, 100);
            this.birthDateLabel.Name = "birthDateLabel";
            this.birthDateLabel.Size = new System.Drawing.Size(89, 13);
            this.birthDateLabel.TabIndex = 6;
            this.birthDateLabel.Text = "Дата рождения:";
            // 
            // fatherNameLabel
            // 
            this.fatherNameLabel.AutoSize = true;
            this.fatherNameLabel.Location = new System.Drawing.Point(6, 74);
            this.fatherNameLabel.Name = "fatherNameLabel";
            this.fatherNameLabel.Size = new System.Drawing.Size(57, 13);
            this.fatherNameLabel.TabIndex = 4;
            this.fatherNameLabel.Text = "Отчество:";
            // 
            // fatherNameText
            // 
            this.fatherNameText.Location = new System.Drawing.Point(107, 71);
            this.fatherNameText.MaxLength = 15;
            this.fatherNameText.Name = "fatherNameText";
            this.fatherNameText.Size = new System.Drawing.Size(190, 20);
            this.fatherNameText.TabIndex = 3;
            // 
            // nameLabel
            // 
            this.nameLabel.AutoSize = true;
            this.nameLabel.Location = new System.Drawing.Point(6, 48);
            this.nameLabel.Name = "nameLabel";
            this.nameLabel.Size = new System.Drawing.Size(32, 13);
            this.nameLabel.TabIndex = 2;
            this.nameLabel.Text = "Имя:";
            // 
            // nameText
            // 
            this.nameText.Location = new System.Drawing.Point(107, 45);
            this.nameText.MaxLength = 15;
            this.nameText.Name = "nameText";
            this.nameText.Size = new System.Drawing.Size(190, 20);
            this.nameText.TabIndex = 1;
            // 
            // surnameLabel
            // 
            this.surnameLabel.AutoSize = true;
            this.surnameLabel.Location = new System.Drawing.Point(6, 22);
            this.surnameLabel.Name = "surnameLabel";
            this.surnameLabel.Size = new System.Drawing.Size(59, 13);
            this.surnameLabel.TabIndex = 1;
            this.surnameLabel.Text = "Фамилия:";
            // 
            // surnameText
            // 
            this.surnameText.Location = new System.Drawing.Point(107, 19);
            this.surnameText.MaxLength = 15;
            this.surnameText.Name = "surnameText";
            this.surnameText.Size = new System.Drawing.Size(190, 20);
            this.surnameText.TabIndex = 0;
            // 
            // employeeInfoGroupBox
            // 
            this.employeeInfoGroupBox.Controls.Add(this.salaryLabel);
            this.employeeInfoGroupBox.Controls.Add(this.salaryNumeric);
            this.employeeInfoGroupBox.Controls.Add(this.appointmentDateLabel);
            this.employeeInfoGroupBox.Controls.Add(this.appointmentDatePicker);
            this.employeeInfoGroupBox.Controls.Add(this.employmentDateLabel);
            this.employeeInfoGroupBox.Controls.Add(this.employmentDatePicker);
            this.employeeInfoGroupBox.Controls.Add(this.educationLabel);
            this.employeeInfoGroupBox.Controls.Add(this.educationText);
            this.employeeInfoGroupBox.Controls.Add(this.specialityLabel);
            this.employeeInfoGroupBox.Controls.Add(this.specialityText);
            this.employeeInfoGroupBox.Controls.Add(this.positionLabel);
            this.employeeInfoGroupBox.Controls.Add(this.positionText);
            this.employeeInfoGroupBox.Controls.Add(this.departmentLabel);
            this.employeeInfoGroupBox.Controls.Add(this.departmentText);
            this.employeeInfoGroupBox.Location = new System.Drawing.Point(321, 12);
            this.employeeInfoGroupBox.Name = "employeeInfoGroupBox";
            this.employeeInfoGroupBox.Size = new System.Drawing.Size(303, 204);
            this.employeeInfoGroupBox.TabIndex = 19;
            this.employeeInfoGroupBox.TabStop = false;
            this.employeeInfoGroupBox.Text = "Сведения о сотруднике";
            // 
            // salaryLabel
            // 
            this.salaryLabel.AutoSize = true;
            this.salaryLabel.Location = new System.Drawing.Point(6, 125);
            this.salaryLabel.Name = "salaryLabel";
            this.salaryLabel.Size = new System.Drawing.Size(42, 13);
            this.salaryLabel.TabIndex = 24;
            this.salaryLabel.Text = "Оклад:";
            // 
            // salaryNumeric
            // 
            this.salaryNumeric.Increment = new decimal(new int[] {
            100,
            0,
            0,
            0});
            this.salaryNumeric.Location = new System.Drawing.Point(107, 123);
            this.salaryNumeric.Maximum = new decimal(new int[] {
            25000,
            0,
            0,
            0});
            this.salaryNumeric.Minimum = new decimal(new int[] {
            2000,
            0,
            0,
            0});
            this.salaryNumeric.Name = "salaryNumeric";
            this.salaryNumeric.Size = new System.Drawing.Size(190, 20);
            this.salaryNumeric.TabIndex = 23;
            this.salaryNumeric.Value = new decimal(new int[] {
            2000,
            0,
            0,
            0});
            // 
            // appointmentDateLabel
            // 
            this.appointmentDateLabel.AutoSize = true;
            this.appointmentDateLabel.Location = new System.Drawing.Point(6, 178);
            this.appointmentDateLabel.Name = "appointmentDateLabel";
            this.appointmentDateLabel.Size = new System.Drawing.Size(98, 13);
            this.appointmentDateLabel.TabIndex = 22;
            this.appointmentDateLabel.Text = "Дата назначения:";
            // 
            // appointmentDatePicker
            // 
            this.appointmentDatePicker.Location = new System.Drawing.Point(107, 175);
            this.appointmentDatePicker.Name = "appointmentDatePicker";
            this.appointmentDatePicker.Size = new System.Drawing.Size(190, 20);
            this.appointmentDatePicker.TabIndex = 21;
            // 
            // employmentDateLabel
            // 
            this.employmentDateLabel.AutoSize = true;
            this.employmentDateLabel.Location = new System.Drawing.Point(6, 152);
            this.employmentDateLabel.Name = "employmentDateLabel";
            this.employmentDateLabel.Size = new System.Drawing.Size(86, 13);
            this.employmentDateLabel.TabIndex = 20;
            this.employmentDateLabel.Text = "Дата принятия:";
            // 
            // employmentDatePicker
            // 
            this.employmentDatePicker.Location = new System.Drawing.Point(107, 149);
            this.employmentDatePicker.Name = "employmentDatePicker";
            this.employmentDatePicker.Size = new System.Drawing.Size(190, 20);
            this.employmentDatePicker.TabIndex = 19;
            // 
            // educationLabel
            // 
            this.educationLabel.AutoSize = true;
            this.educationLabel.Location = new System.Drawing.Point(6, 100);
            this.educationLabel.Name = "educationLabel";
            this.educationLabel.Size = new System.Drawing.Size(78, 13);
            this.educationLabel.TabIndex = 7;
            this.educationLabel.Text = "Образование:";
            // 
            // educationText
            // 
            this.educationText.Location = new System.Drawing.Point(107, 97);
            this.educationText.MaxLength = 15;
            this.educationText.Name = "educationText";
            this.educationText.Size = new System.Drawing.Size(190, 20);
            this.educationText.TabIndex = 6;
            // 
            // specialityLabel
            // 
            this.specialityLabel.AutoSize = true;
            this.specialityLabel.Location = new System.Drawing.Point(6, 74);
            this.specialityLabel.Name = "specialityLabel";
            this.specialityLabel.Size = new System.Drawing.Size(88, 13);
            this.specialityLabel.TabIndex = 5;
            this.specialityLabel.Text = "Специальность:";
            // 
            // specialityText
            // 
            this.specialityText.Location = new System.Drawing.Point(107, 71);
            this.specialityText.MaxLength = 30;
            this.specialityText.Name = "specialityText";
            this.specialityText.Size = new System.Drawing.Size(190, 20);
            this.specialityText.TabIndex = 4;
            // 
            // positionLabel
            // 
            this.positionLabel.AutoSize = true;
            this.positionLabel.Location = new System.Drawing.Point(6, 48);
            this.positionLabel.Name = "positionLabel";
            this.positionLabel.Size = new System.Drawing.Size(68, 13);
            this.positionLabel.TabIndex = 3;
            this.positionLabel.Text = "Должность:";
            // 
            // positionText
            // 
            this.positionText.Location = new System.Drawing.Point(107, 45);
            this.positionText.MaxLength = 60;
            this.positionText.Name = "positionText";
            this.positionText.Size = new System.Drawing.Size(190, 20);
            this.positionText.TabIndex = 2;
            // 
            // departmentLabel
            // 
            this.departmentLabel.AutoSize = true;
            this.departmentLabel.Location = new System.Drawing.Point(6, 22);
            this.departmentLabel.Name = "departmentLabel";
            this.departmentLabel.Size = new System.Drawing.Size(90, 13);
            this.departmentLabel.TabIndex = 1;
            this.departmentLabel.Text = "Подразделение:";
            // 
            // departmentText
            // 
            this.departmentText.Location = new System.Drawing.Point(107, 19);
            this.departmentText.MaxLength = 30;
            this.departmentText.Name = "departmentText";
            this.departmentText.Size = new System.Drawing.Size(190, 20);
            this.departmentText.TabIndex = 0;
            // 
            // btnAdd
            // 
            this.btnAdd.Location = new System.Drawing.Point(321, 222);
            this.btnAdd.Name = "btnAdd";
            this.btnAdd.Size = new System.Drawing.Size(75, 23);
            this.btnAdd.TabIndex = 20;
            this.btnAdd.Text = "Добавить";
            this.btnAdd.UseVisualStyleBackColor = true;
            this.btnAdd.Click += new System.EventHandler(this.btnAdd_Click);
            // 
            // InsertDataForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(632, 300);
            this.Controls.Add(this.btnAdd);
            this.Controls.Add(this.employeeInfoGroupBox);
            this.Controls.Add(this.passportDataGroupBox);
            this.Name = "InsertDataForm";
            this.Text = "Добавить данные";
            this.passportDataGroupBox.ResumeLayout(false);
            this.passportDataGroupBox.PerformLayout();
            this.employeeInfoGroupBox.ResumeLayout(false);
            this.employeeInfoGroupBox.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.salaryNumeric)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox passportDataGroupBox;
        private System.Windows.Forms.Label surnameLabel;
        private System.Windows.Forms.TextBox surnameText;
        private System.Windows.Forms.Label birthPlaceLabel;
        private System.Windows.Forms.TextBox birthPlaceText;
        private System.Windows.Forms.DateTimePicker birthDatePicker;
        private System.Windows.Forms.Label birthDateLabel;
        private System.Windows.Forms.Label fatherNameLabel;
        private System.Windows.Forms.TextBox fatherNameText;
        private System.Windows.Forms.Label nameLabel;
        private System.Windows.Forms.TextBox nameText;
        private System.Windows.Forms.TextBox addressText;
        private System.Windows.Forms.TextBox houseText;
        private System.Windows.Forms.Label houseLabel;
        private System.Windows.Forms.Label adressLabel;
        private System.Windows.Forms.Label apartmentLabel;
        private System.Windows.Forms.Label issueDateLabel;
        private System.Windows.Forms.DateTimePicker issueDatePicker;
        private System.Windows.Forms.GroupBox employeeInfoGroupBox;
        private System.Windows.Forms.Label positionLabel;
        private System.Windows.Forms.TextBox positionText;
        private System.Windows.Forms.Label departmentLabel;
        private System.Windows.Forms.TextBox departmentText;
        private System.Windows.Forms.TextBox educationText;
        private System.Windows.Forms.Label specialityLabel;
        private System.Windows.Forms.TextBox specialityText;
        private System.Windows.Forms.DateTimePicker employmentDatePicker;
        private System.Windows.Forms.Label educationLabel;
        private System.Windows.Forms.Label employmentDateLabel;
        private System.Windows.Forms.Label appointmentDateLabel;
        private System.Windows.Forms.DateTimePicker appointmentDatePicker;
        private System.Windows.Forms.Button btnAdd;
        private System.Windows.Forms.Label passportNumLabel;
        private System.Windows.Forms.MaskedTextBox passportNumText;
        private System.Windows.Forms.Label salaryLabel;
        private System.Windows.Forms.NumericUpDown salaryNumeric;
        private System.Windows.Forms.MaskedTextBox apartmentText;
    }
}