/*
 * Создано в SharpDevelop.
 * Пользователь: Yuri Zinchenko
 * Дата: 21.12.2018
 * Время: 3:01
*/
namespace Lab04
{
	partial class MainForm
	{
		/// <summary>
		/// Designer variable used to keep track of non-visual components.
		/// </summary>
		private System.ComponentModel.IContainer components = null;
		private System.Windows.Forms.DataVisualization.Charting.Chart Chart1;
		private System.Windows.Forms.DataVisualization.Charting.Chart MainChart;
		private System.Windows.Forms.Button btnUpdate;
		
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
			System.Windows.Forms.DataVisualization.Charting.ChartArea chartArea1 = new System.Windows.Forms.DataVisualization.Charting.ChartArea();
			System.Windows.Forms.DataVisualization.Charting.Legend legend1 = new System.Windows.Forms.DataVisualization.Charting.Legend();
			System.Windows.Forms.DataVisualization.Charting.Series series1 = new System.Windows.Forms.DataVisualization.Charting.Series();
			System.Windows.Forms.DataVisualization.Charting.ChartArea chartArea2 = new System.Windows.Forms.DataVisualization.Charting.ChartArea();
			System.Windows.Forms.DataVisualization.Charting.Legend legend2 = new System.Windows.Forms.DataVisualization.Charting.Legend();
			System.Windows.Forms.DataVisualization.Charting.Series series2 = new System.Windows.Forms.DataVisualization.Charting.Series();
			this.Chart1 = new System.Windows.Forms.DataVisualization.Charting.Chart();
			this.MainChart = new System.Windows.Forms.DataVisualization.Charting.Chart();
			this.btnUpdate = new System.Windows.Forms.Button();
			((System.ComponentModel.ISupportInitialize)(this.Chart1)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.MainChart)).BeginInit();
			this.SuspendLayout();
			// 
			// Chart1
			// 
			chartArea1.Name = "ChartArea1";
			this.Chart1.ChartAreas.Add(chartArea1);
			legend1.Name = "Legend1";
			this.Chart1.Legends.Add(legend1);
			this.Chart1.Location = new System.Drawing.Point(582, 12);
			this.Chart1.Name = "Chart1";
			series1.ChartArea = "ChartArea1";
			series1.Legend = "Legend1";
			series1.Name = "Series1";
			this.Chart1.Series.Add(series1);
			this.Chart1.Size = new System.Drawing.Size(590, 538);
			this.Chart1.TabIndex = 0;
			this.Chart1.Text = "chart1";
			// 
			// MainChart
			// 
			chartArea2.Name = "ChartArea1";
			this.MainChart.ChartAreas.Add(chartArea2);
			legend2.Name = "Legend1";
			this.MainChart.Legends.Add(legend2);
			this.MainChart.Location = new System.Drawing.Point(12, 12);
			this.MainChart.Name = "MainChart";
			series2.ChartArea = "ChartArea1";
			series2.Legend = "Legend1";
			series2.Name = "Series1";
			this.MainChart.Series.Add(series2);
			this.MainChart.Size = new System.Drawing.Size(564, 538);
			this.MainChart.TabIndex = 1;
			this.MainChart.Text = "chart1";
			// 
			// btnUpdate
			// 
			this.btnUpdate.Location = new System.Drawing.Point(12, 556);
			this.btnUpdate.Name = "btnUpdate";
			this.btnUpdate.Size = new System.Drawing.Size(186, 44);
			this.btnUpdate.TabIndex = 2;
			this.btnUpdate.Text = "Update";
			this.btnUpdate.UseVisualStyleBackColor = true;
			this.btnUpdate.Click += new System.EventHandler(this.BtnUpdateClick);
			// 
			// MainForm
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(1184, 612);
			this.Controls.Add(this.btnUpdate);
			this.Controls.Add(this.MainChart);
			this.Controls.Add(this.Chart1);
			this.Name = "MainForm";
			this.Text = "Lab04";
			this.Paint += new System.Windows.Forms.PaintEventHandler(this.MainFormPaint);
			((System.ComponentModel.ISupportInitialize)(this.Chart1)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.MainChart)).EndInit();
			this.ResumeLayout(false);

		}
	}
}
