namespace CourseProject
{
    partial class DataBaseForm
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
            this.components = new System.ComponentModel.Container();
            this.dataGridView = new System.Windows.Forms.DataGridView();
            this.btnAdd = new System.Windows.Forms.Button();
            this.btnDelete = new System.Windows.Forms.Button();
            this.bindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.filterCheckBox = new System.Windows.Forms.CheckBox();
            this.filterColumnCombo = new System.Windows.Forms.ComboBox();
            this.filterText = new System.Windows.Forms.TextBox();
            this.filterLabel = new System.Windows.Forms.Label();
            this.btnRetire = new System.Windows.Forms.Button();
            this.btnOrder = new System.Windows.Forms.Button();
            this.id = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.surname = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.name = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.fatherName = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.birthDate = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.birthPlace = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.address = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.house = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.apartment = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.passportNum = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.issueDate = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.department = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.position = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.speciality = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.education = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.salary = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.employmentDate = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.appointmentDate = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.editDate = new System.Windows.Forms.DataGridViewTextBoxColumn();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.bindingSource)).BeginInit();
            this.SuspendLayout();
            // 
            // dataGridView
            // 
            this.dataGridView.AllowUserToAddRows = false;
            this.dataGridView.AllowUserToDeleteRows = false;
            this.dataGridView.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.id,
            this.surname,
            this.name,
            this.fatherName,
            this.birthDate,
            this.birthPlace,
            this.address,
            this.house,
            this.apartment,
            this.passportNum,
            this.issueDate,
            this.department,
            this.position,
            this.speciality,
            this.education,
            this.salary,
            this.employmentDate,
            this.appointmentDate,
            this.editDate});
            this.dataGridView.Location = new System.Drawing.Point(12, 41);
            this.dataGridView.Name = "dataGridView";
            this.dataGridView.Size = new System.Drawing.Size(984, 677);
            this.dataGridView.TabIndex = 0;
            this.dataGridView.CellEndEdit += new System.Windows.Forms.DataGridViewCellEventHandler(this.dataGridView_CellEndEdit);
            // 
            // btnAdd
            // 
            this.btnAdd.Location = new System.Drawing.Point(12, 12);
            this.btnAdd.Name = "btnAdd";
            this.btnAdd.Size = new System.Drawing.Size(75, 23);
            this.btnAdd.TabIndex = 1;
            this.btnAdd.Text = "Добавить";
            this.btnAdd.UseVisualStyleBackColor = true;
            this.btnAdd.Click += new System.EventHandler(this.btnAdd_Click);
            // 
            // btnDelete
            // 
            this.btnDelete.Location = new System.Drawing.Point(93, 12);
            this.btnDelete.Name = "btnDelete";
            this.btnDelete.Size = new System.Drawing.Size(75, 23);
            this.btnDelete.TabIndex = 2;
            this.btnDelete.Text = "Уволить";
            this.btnDelete.UseVisualStyleBackColor = true;
            this.btnDelete.Click += new System.EventHandler(this.btnDelete_Click);
            // 
            // filterCheckBox
            // 
            this.filterCheckBox.AutoSize = true;
            this.filterCheckBox.Location = new System.Drawing.Point(610, 14);
            this.filterCheckBox.Name = "filterCheckBox";
            this.filterCheckBox.Size = new System.Drawing.Size(90, 17);
            this.filterCheckBox.TabIndex = 4;
            this.filterCheckBox.Text = "Фильтрация";
            this.filterCheckBox.UseVisualStyleBackColor = true;
            this.filterCheckBox.CheckedChanged += new System.EventHandler(this.filterCheckBox_CheckedChanged);
            // 
            // filterColumnCombo
            // 
            this.filterColumnCombo.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.filterColumnCombo.Items.AddRange(new object[] {
            "(отключен)",
            "Фамилия",
            "Имя",
            "Отчество",
            "Дата рождения",
            "Место рождения",
            "Адрес",
            "Дом",
            "Квартира",
            "Номер паспорта",
            "Дата выдачи",
            "Подразделение",
            "Должность",
            "Специальность",
            "Образование",
            "Оклад",
            "Дата принятия",
            "Дата посл. назначения",
            "Дата посл. редактирования"});
            this.filterColumnCombo.Location = new System.Drawing.Point(762, 12);
            this.filterColumnCombo.Name = "filterColumnCombo";
            this.filterColumnCombo.Size = new System.Drawing.Size(114, 21);
            this.filterColumnCombo.TabIndex = 5;
            this.filterColumnCombo.Visible = false;
            this.filterColumnCombo.SelectedIndexChanged += new System.EventHandler(this.filterColumnCombo_SelectedIndexChanged);
            // 
            // filterText
            // 
            this.filterText.Enabled = false;
            this.filterText.Location = new System.Drawing.Point(882, 12);
            this.filterText.Name = "filterText";
            this.filterText.Size = new System.Drawing.Size(114, 20);
            this.filterText.TabIndex = 7;
            this.filterText.Visible = false;
            this.filterText.TextChanged += new System.EventHandler(this.filterText_TextChanged);
            // 
            // filterLabel
            // 
            this.filterLabel.AutoSize = true;
            this.filterLabel.Location = new System.Drawing.Point(706, 15);
            this.filterLabel.Name = "filterLabel";
            this.filterLabel.Size = new System.Drawing.Size(50, 13);
            this.filterLabel.TabIndex = 11;
            this.filterLabel.Text = "Фильтр:";
            this.filterLabel.Visible = false;
            // 
            // btnRetire
            // 
            this.btnRetire.Location = new System.Drawing.Point(174, 12);
            this.btnRetire.Name = "btnRetire";
            this.btnRetire.Size = new System.Drawing.Size(158, 23);
            this.btnRetire.TabIndex = 15;
            this.btnRetire.Text = "Сократить по возрасту";
            this.btnRetire.UseVisualStyleBackColor = true;
            this.btnRetire.Click += new System.EventHandler(this.btnRetire_Click);
            // 
            // btnOrder
            // 
            this.btnOrder.Location = new System.Drawing.Point(338, 12);
            this.btnOrder.Name = "btnOrder";
            this.btnOrder.Size = new System.Drawing.Size(133, 23);
            this.btnOrder.TabIndex = 16;
            this.btnOrder.Text = "Формировать приказ";
            this.btnOrder.UseVisualStyleBackColor = true;
            this.btnOrder.Click += new System.EventHandler(this.btnOrder_Click);
            // 
            // id
            // 
            this.id.HeaderText = "№";
            this.id.MaxInputLength = 5;
            this.id.Name = "id";
            this.id.ReadOnly = true;
            this.id.Width = 20;
            // 
            // surname
            // 
            this.surname.HeaderText = "Фамилия";
            this.surname.MaxInputLength = 15;
            this.surname.Name = "surname";
            this.surname.Width = 80;
            // 
            // name
            // 
            this.name.HeaderText = "Имя";
            this.name.MaxInputLength = 15;
            this.name.Name = "name";
            this.name.Width = 50;
            // 
            // fatherName
            // 
            this.fatherName.HeaderText = "Отчество";
            this.fatherName.MaxInputLength = 15;
            this.fatherName.Name = "fatherName";
            this.fatherName.Width = 80;
            // 
            // birthDate
            // 
            this.birthDate.HeaderText = "Дата рождения";
            this.birthDate.MaxInputLength = 15;
            this.birthDate.Name = "birthDate";
            this.birthDate.Width = 80;
            // 
            // birthPlace
            // 
            this.birthPlace.HeaderText = "Место рождения";
            this.birthPlace.MaxInputLength = 15;
            this.birthPlace.Name = "birthPlace";
            // 
            // address
            // 
            this.address.HeaderText = "Адрес";
            this.address.MaxInputLength = 25;
            this.address.Name = "address";
            // 
            // house
            // 
            this.house.HeaderText = "Дом";
            this.house.MaxInputLength = 4;
            this.house.Name = "house";
            this.house.Width = 40;
            // 
            // apartment
            // 
            this.apartment.HeaderText = "Квартира";
            this.apartment.MaxInputLength = 4;
            this.apartment.Name = "apartment";
            this.apartment.Width = 40;
            // 
            // passportNum
            // 
            this.passportNum.HeaderText = "Номер паспорта";
            this.passportNum.MaxInputLength = 8;
            this.passportNum.Name = "passportNum";
            this.passportNum.Width = 60;
            // 
            // issueDate
            // 
            this.issueDate.HeaderText = "Дата выдачи";
            this.issueDate.MaxInputLength = 15;
            this.issueDate.Name = "issueDate";
            this.issueDate.Width = 80;
            // 
            // department
            // 
            this.department.HeaderText = "Подразделение";
            this.department.MaxInputLength = 30;
            this.department.Name = "department";
            // 
            // position
            // 
            this.position.HeaderText = "Должность";
            this.position.MaxInputLength = 60;
            this.position.Name = "position";
            // 
            // speciality
            // 
            this.speciality.HeaderText = "Специальность";
            this.speciality.MaxInputLength = 30;
            this.speciality.Name = "speciality";
            // 
            // education
            // 
            this.education.HeaderText = "Образование";
            this.education.MaxInputLength = 30;
            this.education.Name = "education";
            // 
            // salary
            // 
            this.salary.HeaderText = "Оклад";
            this.salary.MaxInputLength = 5;
            this.salary.Name = "salary";
            this.salary.Width = 50;
            // 
            // employmentDate
            // 
            this.employmentDate.HeaderText = "Дата принятия";
            this.employmentDate.MaxInputLength = 15;
            this.employmentDate.Name = "employmentDate";
            this.employmentDate.Width = 80;
            // 
            // appointmentDate
            // 
            this.appointmentDate.HeaderText = "Дата посл. назначения";
            this.appointmentDate.MaxInputLength = 15;
            this.appointmentDate.Name = "appointmentDate";
            this.appointmentDate.Width = 80;
            // 
            // editDate
            // 
            this.editDate.HeaderText = "Дата посл. редакт.";
            this.editDate.MaxInputLength = 15;
            this.editDate.Name = "editDate";
            this.editDate.ReadOnly = true;
            // 
            // DataBaseForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1008, 730);
            this.Controls.Add(this.btnOrder);
            this.Controls.Add(this.btnRetire);
            this.Controls.Add(this.filterLabel);
            this.Controls.Add(this.filterText);
            this.Controls.Add(this.filterColumnCombo);
            this.Controls.Add(this.filterCheckBox);
            this.Controls.Add(this.btnDelete);
            this.Controls.Add(this.btnAdd);
            this.Controls.Add(this.dataGridView);
            this.Name = "DataBaseForm";
            this.Text = "База сотрудников";
            this.Load += new System.EventHandler(this.DataBaseForm_Load);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.bindingSource)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.DataGridView dataGridView;
        private System.Windows.Forms.Button btnAdd;
        private System.Windows.Forms.Button btnDelete;
        private System.Windows.Forms.BindingSource bindingSource;
        private System.Windows.Forms.CheckBox filterCheckBox;
        private System.Windows.Forms.ComboBox filterColumnCombo;
        private System.Windows.Forms.TextBox filterText;
        private System.Windows.Forms.Label filterLabel;
        private System.Windows.Forms.Button btnRetire;
        private System.Windows.Forms.Button btnOrder;
        private System.Windows.Forms.DataGridViewTextBoxColumn id;
        private System.Windows.Forms.DataGridViewTextBoxColumn surname;
        private System.Windows.Forms.DataGridViewTextBoxColumn name;
        private System.Windows.Forms.DataGridViewTextBoxColumn fatherName;
        private System.Windows.Forms.DataGridViewTextBoxColumn birthDate;
        private System.Windows.Forms.DataGridViewTextBoxColumn birthPlace;
        private System.Windows.Forms.DataGridViewTextBoxColumn address;
        private System.Windows.Forms.DataGridViewTextBoxColumn house;
        private System.Windows.Forms.DataGridViewTextBoxColumn apartment;
        private System.Windows.Forms.DataGridViewTextBoxColumn passportNum;
        private System.Windows.Forms.DataGridViewTextBoxColumn issueDate;
        private System.Windows.Forms.DataGridViewTextBoxColumn department;
        private System.Windows.Forms.DataGridViewTextBoxColumn position;
        private System.Windows.Forms.DataGridViewTextBoxColumn speciality;
        private System.Windows.Forms.DataGridViewTextBoxColumn education;
        private System.Windows.Forms.DataGridViewTextBoxColumn salary;
        private System.Windows.Forms.DataGridViewTextBoxColumn employmentDate;
        private System.Windows.Forms.DataGridViewTextBoxColumn appointmentDate;
        private System.Windows.Forms.DataGridViewTextBoxColumn editDate;
    }
}