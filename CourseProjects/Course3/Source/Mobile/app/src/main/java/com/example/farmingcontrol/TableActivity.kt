package com.example.farmingcontrol

import android.content.Intent
import android.os.Bundle
import android.widget.Button
import android.widget.TableRow
import android.widget.TextView
import androidx.appcompat.app.AppCompatActivity
import kotlinx.android.synthetic.main.activity_main.*
import kotlinx.coroutines.runBlocking

class TableActivity : AppCompatActivity()
{
	override fun onCreate(savedInstanceState: Bundle?)
	{
		if (!g_api.isLogged())
			showLoginForm()

		super.onCreate(savedInstanceState)
		setContentView(R.layout.activity_main)

		btnAdd.setOnClickListener() { showAddFieldForm() }
		btnUpdate.setOnClickListener() { update() }
		btnLogout.setOnClickListener()
		{
			g_api.logout()
			showLoginForm()
		}

		runBlocking { g_api.reload() }
		loadFieldsTable()
	}

	private fun loadFieldsTable()
	{
		addTableRow("Cadastral", "Agriculture", "Area")

		val fields = g_api.getFieldsTable()
		for (i in fields.keys)
		{
			val field = fields[i]!!
			val row = addTableRow(field)

			val logButton = Button(this)
			logButton.textSize = g_fontSize
			logButton.text = "Log"
			row.addView(logButton)
			logButton.setOnClickListener()
			{
				runBlocking { g_api.loadIrrigationLog(field.id) }
				showIrrigationLogForm()
			}

			val editButton = Button(this)
			editButton.textSize = g_fontSize
			editButton.text = "Edit"
			row.addView(editButton)
			editButton.setOnClickListener()
			{
				g_api.setCurrentField(field.id)
				showEditFieldForm()
			}

			val removeButton = Button(this)
			removeButton.textSize = g_fontSize
			removeButton.text = "Remove"
			row.addView(removeButton)
			removeButton.setOnClickListener()
			{
				runBlocking { g_api.removeField(field.id) }
				update()
			}
		}
	}

	private fun addTableRow(record: Field) : TableRow
	{
		return addTableRow(
			record.cadastral,
			record.agriculture.name,
			record.area.toString()
		)
	}

	private fun addTableRow(cadastral : String, agriculture : String, area : String) : TableRow
	{
		val row = TableRow(this)
		tableController.addView(row)
		addTableCell(row, cadastral)
		addTableCell(row, agriculture)
		addTableCell(row, area)
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

	private fun update()
	{
		startActivity(Intent(this, TableActivity::class.java))
	}

	private fun showLoginForm()
	{
		startActivity(Intent(this, LoginActivity::class.java))
	}

	private fun showAddFieldForm()
	{
		startActivity(Intent(this, AddActivity::class.java))
	}

	private fun showEditFieldForm()
	{
		startActivity(Intent(this, EditActivity::class.java))
	}

	private fun showIrrigationLogForm()
	{
		startActivity(Intent(this, IrrigationLogActivity::class.java))
	}
}