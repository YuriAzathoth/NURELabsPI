/*
 * Created by SharpDevelop.
 * User: Master
 * Date: 30.03.2020
 * Time: 1:30
 * 
 * To change this template use Tools | Options | Coding | Edit Standard Headers.
 */

using System;
using System.IO;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Windows.Forms;
using System.Xml;

using OpenSSL.Core;
using OpenSSL.Crypto;

namespace Lab2Client
{
	/// <summary>
	/// Description of MainForm.
	/// </summary>

	public partial class MainForm : Form
	{
		public MainForm()
		{
			InitializeComponent();
			m_btnSend.Click += new System.EventHandler(this.OnClickSend);

			client.Connect(endPoint);
			SendRequest("init");
		}
		
		void OnClickSend(Object sender, EventArgs e)
		{
			SendRequest(WriteFormXml(m_txtLogin.Text, m_txtPass.Text, ReadKeyXml(ReceiveResponse())));
		}
		
		String EncryptData(String bytesToEncrypt, RSA rsa)
		{	
			return Convert.ToBase64String(rsa.PublicEncrypt(Encoding.ASCII.GetBytes(bytesToEncrypt), RSA.Padding.OAEP));
		}
		
		String ReadKeyXml(String xml)
		{
			var xmlKey = new XmlDocument();
			xmlKey.LoadXml(xml);
			return xmlKey.GetElementsByTagName("key")[0].Attributes["value"].Value;
		}
		
		String WriteFormXml(String login, String password, String pemKey)
		{
			var rsa = RSA.FromPublicKey(new BIO(pemKey));

			var xmlForm = new XmlDocument();
			var xmlDecl = xmlForm.CreateXmlDeclaration("1.0", "UTF-8", null);
			xmlForm.AppendChild(xmlDecl);
			
			var xmlRoot = xmlForm.CreateElement("form");
			xmlForm.AppendChild(xmlRoot);

			var xmlLogin = xmlForm.CreateElement("login");
			xmlRoot.AppendChild(xmlLogin);
			xmlLogin.SetAttribute("value", EncryptData(login, rsa));

			var xmlPass = xmlForm.CreateElement("pass");
			xmlRoot.AppendChild(xmlPass);
			xmlPass.SetAttribute("value", EncryptData(password, rsa));

			using (var strWriter = new StringWriter())
				using (var xmlWriter = new XmlTextWriter(strWriter))
			{
				xmlForm.WriteTo(xmlWriter);
				return strWriter.ToString();
			}
		}
		
		void SendRequest(String request)
		{
			client.Send(Encoding.ASCII.GetBytes(request), request.Length);
		}
		
		String ReceiveResponse()
		{
			return Encoding.ASCII.GetString(client.Receive(ref endPoint));
		}

		const string IpAddress = "127.0.0.1";
		const int Port = 2345;

		IPEndPoint endPoint = new IPEndPoint(IPAddress.Parse(IpAddress), Port);
		UdpClient client = new UdpClient();
	}
}
