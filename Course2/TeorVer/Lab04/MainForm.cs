/*
 * Создано в SharpDevelop.
 * Пользователь: Yuri Zinchenko
 * Дата: 21.12.2018
 * Время: 3:01
*/
using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Windows.Forms;
using System.Windows.Forms.DataVisualization.Charting;

namespace Lab04
{		
	/// <summary>
	/// Description of MainForm.
	/// </summary>
	public partial class MainForm : Form
	{
		public MainForm()
		{
			//
			// The InitializeComponent() call is required for Windows Forms designer support.
			//
			InitializeComponent();
			
			rnd = new Random();
		}
		
		public struct LineParam
		{
			public double B;
			public double K;
		}
		
		void BuildCharts()
		{
			double x1, y1, x2, y2;
			const int Count = 50;
			const double MaxX = 20;
			const double MinX = 10;
			const double MaxY = 25;
			const double MinY = 20;

            List<double> X;
            List<double> Y;
            double meanX;
            double meanY;
            double dispersionX;
            double stdDeviationX;
            double dispersionY;
            double stdDeviationY;
            double covariation;
            double coefCorr;
            LineParam coefLine;
            double error;
            double coefDet;
            
            MainChart.ChartAreas.Clear();
            MainChart.Series.Clear();

            var MyChartArea = new ChartArea("Func");
            MainChart.ChartAreas.Add(MyChartArea);

            MyChartArea.AxisX.Interval = Math.Round(MaxX / 10, 2);
            MyChartArea.AxisY.Interval = Math.Round((MaxY + 5) / 10, 2);

            MyChartArea.AxisX.Maximum = MaxX + 3;
            MyChartArea.AxisX.Minimum = MinX - 3;
            MyChartArea.AxisY.Maximum = MaxY + 3;
            MyChartArea.AxisY.Minimum = MinY - 3;

            X = Uniform(MinX, MaxX, Count);
            Y = Uniform(MinY, MaxY, Count);

            meanX = Average(X);
            meanY = Average(Y);

            dispersionX = Dispersion(X, meanX);
            stdDeviationX = Math.Sqrt(dispersionX);
            dispersionY = Dispersion(Y, meanY);
            stdDeviationY = Math.Sqrt(dispersionY);

            covariation = Covariation(X, Y, meanX, meanY);
            coefCorr = covariation / (stdDeviationX * stdDeviationY);

            coefLine = LineCoeff(meanX, meanY, dispersionX, covariation);
            coefDet = Math.Pow(coefCorr, 2);
            
            RemnantTestResult(X, Y, coefLine);
            
            error = 5.0 * stdDeviationY / Math.Sqrt(X.Count);
                    
            #region Draw Dots
            var series1 = new Series("Data");
            series1.XAxisType = AxisType.Primary;
            series1.YAxisType = AxisType.Primary;
            series1.ChartType = SeriesChartType.Point;
            series1.ChartArea = "Func";
            series1.Color = Color.Blue;
            series1.MarkerStyle = MarkerStyle.Circle;
            for (int i = 0; i < X.Count; i++)
                series1.Points.AddXY(X[i], Y[i]);
            MainChart.Series.Add(series1);
            #endregion

            #region Draw Approximate Line
            var series2 = new Series("Approximation Line");
            series2.XAxisType = AxisType.Primary;
            series2.YAxisType = AxisType.Primary;
            series2.ChartType = SeriesChartType.Line;
            series2.ChartArea = "Func";
            x1 = (int)(MinX);
            y1 = coefLine.B + coefLine.K * x1;
            x2 = (int)(MaxX);
            y2 = coefLine.B + coefLine.K * x2;
            series2.Points.AddXY(x1, y1);
            series2.Points.AddXY(x2, y2);
            MainChart.Series.Add(series2);
            #endregion
		}
		
		List<double> Uniform(double a, double b, int count)
		{
			var res = new List<double>();
			for (int i = 0; i < count; i++)
			{
				double val = (rnd.NextDouble() * (b - a)) + a;
				res.Add(val);
			}
			return res;
		}
		
		List<double> UniformDistribution(double a, double b, List<double> valarr)
		{
			var res = new List<double>();
			for (int i = 0; i < valarr.Count; i++)
				res.Add((valarr[i] - a) / (b - a));
			return res;
		}
		
		double Average(List<double> valarr)
		{
			double sum = valarr.Sum(x => x);
			return sum / valarr.Count;
		}
		
		double Dispersion(List<double> valarr, double avg)
		{
			double sum = 0;
			for (int i = 0; i < valarr.Count; i++)
				sum += Math.Pow(valarr[i] - avg, 2);
			return sum / valarr.Count;
		}
		
		double Covariation(List<double> valarrx, List<double> valarry, double avgx, double avgy)
		{
			double sum = 0;
			for (int i = 0; i < valarrx.Count; i++)
				sum += (valarrx[i] - avgx) * (valarry[i] - avgy);
			return sum / valarrx.Count;
		}
		
		LineParam LineCoeff(double avgx, double avgy, double dispx, double covar)
		{
			var res = new LineParam();
			res.K = covar / dispx;
			res.B = avgy - res.K * avgx;
			return res;
		}
		
		bool RemnantTestResult(List<double> valarrx, List<double> valarry, LineParam lp)
		{
			var remnant = new List<double>();
			for (int i = 0; i < valarrx.Count; i++)
				remnant.Add(valarry[i] - (lp.K * valarrx[i] + lp.B));
			double avgr = Average(remnant);
			return HasNormalDistr(remnant) && avgr < Math.Pow(10, -14);
		}
		
		bool HasNormalDistr(List<double> remnant)
		{
			double avgr = Average(remnant);
			double dispr = Dispersion(remnant, avgr);
			double stddevr = Math.Sqrt(dispr);
			
			double b = 0;
			remnant.Sort();
			for (int i = 0; i < remnant.Count; i++)
			{
				double z = (remnant[i] - avgr) / stddevr;
				b += Math.Abs(0.5 + 0.5 * (double)Erf(z / Math.Sqrt(2)) - (i - 0.5) / remnant.Count);
			}
			b /= Math.Sqrt(remnant.Count);
			Chart1.Series.Clear();
			
			var series = new Series("Норм. распр. остат.");
			series["PointWidth"] = "0.7";
			series.Color = Color.Blue;
			series.ChartArea = "ChartArea1";
			series.Legend = "Legend1";
			
			var norm = new List<double>();
			for (int i = 0; i < remnant.Count; i++)
				norm.Add(Quantile(remnant[i]));
			
			double[] diag = CreateHistogram(norm, 5, -5.0, 5.0);
			for (int i = 0; i < diag.Length; i++)
				series.Points.AddXY(i, diag[i]);
			
			Chart1.Series.Add(series);
			return true;
		}
		
		static double Quantile(double a) { return Math.Tan(Math.PI * (a - 0.5)); }
		
		static double[] CreateHistogram(IEnumerable<double> data, int buckets, double min, double max)
		{
			var results = new int[buckets];
			var res = new double[buckets];
			double mult = buckets / (max - min);
			foreach (double val in data)
			{
				double i = (val - min) * mult;
				if (0.0 <= i && i < buckets)
					results[(int)i] += 1;
			}
			int sum = results.Sum();
			for (int i = 0; i < buckets; i++)
				res[i] = Convert.ToDouble(results[i]) / Convert.ToDouble(sum);
			return res;
		}
		
		static double Erf(double x)
		{
			const double a1 = 0.254829592;
			const double a2 = -0.284496736;
			const double a3 = 1.421413741;
			const double a4 = -1.453152027;
			const double a5 = 1.061405429;
			const double p = 0.3275911;
		    
		    int sign = 1;
		    if (x < 0)
		        sign = -1;
		    x = Math.Abs(x);
		 
		    double t = 1.0 / (1.0 + p*x);
		    double y = 1.0 - (((((a5*t + a4)*t) + a3)*t + a2)*t + a1)*t*Math.Exp(-x*x);
		 
		    return sign*y;
		}
		
		Random rnd;
		
		void MainFormPaint(object sender, PaintEventArgs e) { BuildCharts(); }
		void BtnUpdateClick(object sender, EventArgs e) { Refresh(); }
	}
}
