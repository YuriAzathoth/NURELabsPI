package com.zinchenko.pz1

import android.annotation.SuppressLint
import android.os.Bundle
import android.widget.Button
import android.widget.TextView
import androidx.appcompat.app.AppCompatActivity

class MainActivity : AppCompatActivity() {
	override fun onCreate(savedInstanceState: Bundle?) {
		super.onCreate(savedInstanceState)
		setContentView(R.layout.activity_main)

		textFormulae = findViewById(R.id.textFormulae)
		textResult = findViewById(R.id.textResult)

		findViewById<Button>(R.id.button0).setOnClickListener { appendSymbol("0") }
		findViewById<Button>(R.id.button1).setOnClickListener { appendSymbol("1") }
		findViewById<Button>(R.id.button2).setOnClickListener { appendSymbol("2") }
		findViewById<Button>(R.id.button3).setOnClickListener { appendSymbol("3") }
		findViewById<Button>(R.id.button4).setOnClickListener { appendSymbol("4") }
		findViewById<Button>(R.id.button5).setOnClickListener { appendSymbol("5") }
		findViewById<Button>(R.id.button6).setOnClickListener { appendSymbol("6") }
		findViewById<Button>(R.id.button7).setOnClickListener { appendSymbol("7") }
		findViewById<Button>(R.id.button8).setOnClickListener { appendSymbol("8") }
		findViewById<Button>(R.id.button9).setOnClickListener { appendSymbol("9") }
		findViewById<Button>(R.id.buttonPlus).setOnClickListener { appendSymbol("+") }
		findViewById<Button>(R.id.buttonMinus).setOnClickListener { appendSymbol("-") }
		findViewById<Button>(R.id.buttonMultiply).setOnClickListener { appendSymbol("*") }
		findViewById<Button>(R.id.buttonDivide).setOnClickListener { appendSymbol("/") }
		findViewById<Button>(R.id.buttonDot).setOnClickListener { appendSymbol(".") }

		findViewById<Button>(R.id.buttonEqual).setOnClickListener {
			textResult.text = calc.process(textFormulae.text.toString())
		}

		findViewById<Button>(R.id.buttonClear).setOnClickListener {
			textFormulae.text = ""
			textResult.text = "0"
		}
	}

	@SuppressLint("SetTextI18n")
	private fun appendSymbol(symbol: String) {
		textFormulae.text = textFormulae.text.toString() + symbol
	}

	private lateinit var textFormulae: TextView
	private lateinit var textResult: TextView
	private val calc = Calculator()
}