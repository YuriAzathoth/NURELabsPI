package com.example.farmingcontrol

import android.content.Intent
import android.os.Bundle
import android.widget.TableRow
import android.widget.TextView
import androidx.appcompat.app.AppCompatActivity
import kotlinx.android.synthetic.main.activity_irrlog.*
import kotlinx.android.synthetic.main.activity_irrlog.tableController

class IrrigationLogActivity : AppCompatActivity()
{
    override fun onCreate(savedInstanceState: Bundle?)
    {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_irrlog)

        btnBack.setOnClickListener()
        {
            returnBack()
        }

        loadIrrigationLog()
    }

    private fun loadIrrigationLog()
    {
        addTableRow("Date", "Humidity", "Decission", "Count")

        val log = g_api.getIrrigationLog()
        for (i in log.keys)
            addTableRow(log[i]!!)
    }

    private fun addTableRow(record: IrrigationRecord) : TableRow
    {
        val decissionStringify = arrayOf("None", "Irrigate", "Drain")
        return addTableRow(
            record.date,
            record.humidity.toString(),
            decissionStringify[record.decission.toInt()],
            record.count.toString()
        )
    }

    private fun addTableRow(date : String, humidity : String, decission: String, count: String) : TableRow
    {
        val row = TableRow(this)
        tableController.addView(row)
        addTableCell(row, date)
        addTableCell(row, humidity)
        addTableCell(row, decission)
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

    private fun returnBack()
    {
        val intent = Intent(this, TableActivity::class.java)
        startActivity(intent)
    }
}