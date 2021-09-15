package com.example.farmingcontrol

import android.content.Intent
import android.os.Bundle
import android.widget.ArrayAdapter
import androidx.appcompat.app.AppCompatActivity
import kotlinx.android.synthetic.main.activity_add.*
import kotlinx.coroutines.runBlocking

class AddActivity : AppCompatActivity()
{
	override fun onCreate(savedInstanceState: Bundle?)
	{
		super.onCreate(savedInstanceState)
		setContentView(R.layout.activity_add)

		val agriculturesTable = g_api.getAgriculturesTable()
		var agriculturesArray = Array(agriculturesTable.size) { "" }

        var j = 0
		for (i in agriculturesTable.keys)
        {
            agriculturesArray[j] = agriculturesTable[i]!!.name
            ++j
        }

        var agriculturesIds = HashMap<Int, Int>()
        j = 0
        for (i in agriculturesTable.keys)
        {
            agriculturesIds[j] = i
            ++j
        }

		cmbAgriculture.adapter = ArrayAdapter(this,  android.R.layout.simple_spinner_item, agriculturesArray)

		btnStore.setOnClickListener()
		{
			val field = Field(
				id = 0,
				cadastral = txtCadastral.text.toString(),
				agriculture = agriculturesTable[agriculturesIds[cmbAgriculture.selectedItemId.toInt()]!!]!!,
				area = numArea.text.toString().toShort()
			)
			runBlocking { g_api.addField(field) }
			returnBack()
		}

		btnCancel.setOnClickListener { returnBack() }
	}

	private fun returnBack()
	{
		val intent = Intent(this, TableActivity::class.java)
		startActivity(intent)
	}
}