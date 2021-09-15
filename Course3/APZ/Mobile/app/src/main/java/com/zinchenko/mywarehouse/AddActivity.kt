package com.zinchenko.mywarehouse

import android.content.Intent
import android.os.Bundle
import android.widget.AdapterView
import android.widget.ArrayAdapter
import androidx.appcompat.app.AppCompatActivity
import kotlinx.android.synthetic.main.activity_add.*
import kotlinx.coroutines.GlobalScope
import kotlinx.coroutines.launch
import kotlinx.coroutines.runBlocking

class AddActivity : AppCompatActivity()
{
	// public:
	override fun onCreate(savedInstanceState: Bundle?)
	{
		super.onCreate(savedInstanceState)
		setContentView(R.layout.activity_add)
		runBlocking { _categories = _server.loadCategories() }

		var categories = Array<String>(_categories.size) { "" }
		for (i in 0 until _categories.size)
			categories[i] = _categories[i]!!.name
		val adapterCategories = ArrayAdapter(this, android.R.layout.simple_spinner_item, categories)
		cmbProducts.adapter = adapterCategories
		btnStore.setOnClickListener()
		{
			GlobalScope.launch {
				val id = _categories[cmbProducts.selectedItemId.toInt()]!!.id
				val count = numCount.text.toString().toInt()
				_server.addProduct(id, count)
			}
			returnBack()
		}
		btnCancel.setOnClickListener()
		{
			returnBack()
		}
	}

	// private:
	private fun returnBack()
	{
		val intent = Intent(this, TableActivity::class.java)
		startActivity(intent)
	}

	private var _categories = HashMap<Int, Category>()
}