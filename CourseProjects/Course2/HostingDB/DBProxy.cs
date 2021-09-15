/*
 * Создано в SharpDevelop.
 * Пользователь: Yuri Zinchenko
 * Дата: 06.12.2018
 * Время: 15:04
*/
using System;
using System.Collections.Generic;
using System.Data;
using System.Data.OleDb;

namespace HostingDB
{
	/// <summary>
	/// Description of DBProxy.
	/// </summary>
	public class DBProxy
	{
		public DBProxy() { LoadTablesNames(); }
		
		public void DoQuery(string sql)
		{
			try
			{
				dbTable = new DataTable();
				
				var conn = ConnectionOpen();
				var oda = new OleDbDataAdapter(sql, conn);
				oda.Fill(dbTable);
				ConnectionClose(conn);
			} catch (Exception e) { MainForm.ExceptionMessage(e); }
		}
		
		public void LoadTable(string table) { DoQuery(string.Format("SELECT * FROM {0};", table)); }
		
		void LoadTablesNames()
		{
		  	var conn = ConnectionOpen();
		  	
			dbNames = new List<string>();
		  	var restrictions = new string[4];
		  	restrictions[3] = "Table";
		  	var tables = conn.GetSchema("Tables", restrictions);
		  	
		  	for (int i=0; i < tables.Rows.Count; i++)
		  		dbNames.Add(tables.Rows[i][2].ToString());
		  	
		  	ConnectionClose(conn);
		}
		
		static OleDbConnection ConnectionOpen()
		{
			try
			{
				var conn = new OleDbConnection(connectionString);
				conn.Open();
				return conn;
			}
			catch (Exception e)
			{
				MainForm.ExceptionMessage(e);
				return null;
			}
		}
		
		static void ConnectionClose(OleDbConnection conn) { conn.Close(); }
		
		DataTable dbTable;
		public DataTable DbTable { get { return dbTable; } }
		
		List<string> dbNames;
		public List<string> DbNames { get { return dbNames; } }
		
		const String connectionString = @"Provider=Microsoft.ACE.OLEDB.12.0;Data Source=|DataDirectory|\hosting.accdb";
	}
}
