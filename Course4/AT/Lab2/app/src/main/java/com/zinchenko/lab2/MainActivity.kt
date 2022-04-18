package com.zinchenko.lab2

import android.annotation.SuppressLint
import android.os.Bundle
import android.view.View
import android.widget.TextView
import androidx.appcompat.app.AppCompatActivity

class MainActivity : AppCompatActivity()
{
	private val calculator = Calculator()
	private var textFormulae: TextView? = null
	private var textResult: TextView? = null

	override fun onCreate(savedInstanceState: Bundle?)
	{
		super.onCreate(savedInstanceState)
		setContentView(R.layout.activity_main)
		textFormulae = findViewById(R.id.textFormulae)
		textResult = findViewById(R.id.textResult)
		findViewById<View>(R.id.button0).setOnClickListener { appendSymbol("0") }
		findViewById<View>(R.id.button1).setOnClickListener { appendSymbol("1") }
		findViewById<View>(R.id.button2).setOnClickListener { appendSymbol("2") }
		findViewById<View>(R.id.button3).setOnClickListener { appendSymbol("3") }
		findViewById<View>(R.id.button4).setOnClickListener { appendSymbol("4") }
		findViewById<View>(R.id.button5).setOnClickListener { appendSymbol("5") }
		findViewById<View>(R.id.button6).setOnClickListener { appendSymbol("6") }
		findViewById<View>(R.id.button7).setOnClickListener { appendSymbol("7") }
		findViewById<View>(R.id.button8).setOnClickListener { appendSymbol("8") }
		findViewById<View>(R.id.button9).setOnClickListener { appendSymbol("9") }
		findViewById<View>(R.id.buttonPlus).setOnClickListener { appendSymbol("+") }
		findViewById<View>(R.id.buttonMinus).setOnClickListener { appendSymbol("-") }
		findViewById<View>(R.id.buttonMultiply).setOnClickListener { appendSymbol("*") }
		findViewById<View>(R.id.buttonDivide).setOnClickListener { appendSymbol("/") }
		findViewById<View>(R.id.buttonLBracket).setOnClickListener { appendSymbol("(") }
		findViewById<View>(R.id.buttonRBracket).setOnClickListener { appendSymbol(")") }
		findViewById<View>(R.id.buttonDelete).setOnClickListener { deleteSymbol() }
		findViewById<View>(R.id.buttonClear).setOnClickListener { clearSymbols() }
		findViewById<View>(R.id.buttonEqual).setOnClickListener { calculate() }
	}

	override fun onSaveInstanceState(outState: Bundle)
	{
		super.onSaveInstanceState(outState)
		outState.putString("Formulae", textFormulae!!.text.toString())
		outState.putString("Result", textResult!!.text.toString())
	}

	override fun onRestoreInstanceState(savedInstanceState: Bundle)
	{
		super.onRestoreInstanceState(savedInstanceState)
		textFormulae!!.text = savedInstanceState.getString("Formulae")
		textResult!!.text = savedInstanceState.getString("Result")
	}

	@SuppressLint("SetTextI18n")
	private fun appendSymbol(symbol: String)
	{
		textFormulae!!.text = textFormulae!!.text.toString() + symbol
	}

	private fun deleteSymbol()
	{
		val text = textFormulae!!.text
		if (text.isNotEmpty()) textFormulae!!.text = text.subSequence(0, text.length - 1)
	}

	private fun clearSymbols()
	{
		textFormulae!!.text = ""
		textResult!!.text = "0"
	}

	private fun calculate()
	{
		try
		{
			textResult!!.text = calculator.process(textFormulae!!.text.toString())
		}
		catch (e: RuntimeException)
		{
			textResult!!.text = e.message
		}
	}
}