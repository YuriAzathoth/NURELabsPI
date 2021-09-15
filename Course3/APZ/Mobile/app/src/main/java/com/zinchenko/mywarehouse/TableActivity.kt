package com.zinchenko.mywarehouse

import android.content.Intent
import android.os.Bundle
import android.widget.Button
import android.widget.TableRow
import android.widget.TextView
import androidx.appcompat.app.AppCompatActivity
import kotlinx.android.synthetic.main.activity_main.*
import kotlinx.coroutines.GlobalScope
import kotlinx.coroutines.launch
import kotlinx.coroutines.runBlocking

class TableActivity : AppCompatActivity()
{
	// public:
	override fun onCreate(savedInstanceState: Bundle?)
	{
		if (!_server.isLogged())
			showLoginForm()
		super.onCreate(savedInstanceState)
		setContentView(R.layout.activity_main)
		btnAdd.setOnClickListener()
		{
			showAddProductForm()
		}

		btnUpdate.setOnClickListener()
		{
			update()
		}
		btnLogout.setOnClickListener()
		{
			_server.logout()
			showLoginForm()
		}
		loadProductsTable()
	}

	// private:
	private fun update()
	{
		val intent = Intent(this, TableActivity::class.java)
		startActivity(intent)
	}

	private fun showLoginForm()
	{
		val intent = Intent(this, LoginActivity::class.java)
		startActivity(intent)
	}

	private fun showAddProductForm()
	{
		val intent = Intent(this, AddActivity::class.java)
		startActivity(intent)
	}

	private fun loadProductsTable()
	{
		runBlocking { _server.loadProducts() }
		addTableRow("Name", "Warehouse", "Count")

		for (i in 0 until _server._products.size)
		{
			val product = _server._products[i]!!
			val row = addTableRow(product.name, product.warehouse, product.count.toString())

			val btnRemove = Button(this)
			btnRemove.textSize = g_fontSize
			btnRemove.text = "Remove"
			row.addView(btnRemove)
			btnRemove.setOnClickListener()
			{
				GlobalScope.launch {
					_server.removeProduct(product.id)
				}
				update()
			}
		}
	}

	private fun addTableRow(name : String, warehouse : String, count : String) : TableRow
	{
		val row = TableRow(this)
		tableProducts.addView(row)
		addTableCell(row, name)
		addTableCell(row, warehouse)
		addTableCell(row, count)
		return row
	}

	private fun addTableCell(row : TableRow, text : String)
	{
		val txtCell = TextView(this)
		txtCell.textSize = g_fontSize
		txtCell.text = text
		txtCell.width = g_columnSize
		row.addView(txtCell)
	}
}