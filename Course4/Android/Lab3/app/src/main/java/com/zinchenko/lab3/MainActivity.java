package com.zinchenko.lab3;

import android.annotation.SuppressLint;
import android.os.Bundle;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity
{
	private final Calculator calculator = new Calculator();
	private TextView textFormulae;
	private TextView textResult;

	@Override
	protected void onCreate(Bundle savedInstanceState)
	{
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		setTitle("Yurii Zinchenko PZPIz-18-1 Lab3");

		textFormulae = findViewById(R.id.textFormulae);
		textResult = findViewById(R.id.textResult);

		findViewById(R.id.button0).setOnClickListener(v ->
				appendSymbol("0"));
		findViewById(R.id.button1).setOnClickListener(v ->
				appendSymbol("1"));
		findViewById(R.id.button2).setOnClickListener(v ->
				appendSymbol("2"));
		findViewById(R.id.button3).setOnClickListener(v ->
				appendSymbol("3"));
		findViewById(R.id.button4).setOnClickListener(v ->
				appendSymbol("4"));
		findViewById(R.id.button5).setOnClickListener(v ->
				appendSymbol("5"));
		findViewById(R.id.button6).setOnClickListener(v ->
				appendSymbol("6"));
		findViewById(R.id.button7).setOnClickListener(v ->
				appendSymbol("7"));
		findViewById(R.id.button8).setOnClickListener(v ->
				appendSymbol("8"));
		findViewById(R.id.button9).setOnClickListener(v ->
				appendSymbol("9"));
		findViewById(R.id.buttonPlus).setOnClickListener(v ->
				appendSymbol("+"));
		findViewById(R.id.buttonMinus).setOnClickListener(v ->
				appendSymbol("-"));
		findViewById(R.id.buttonMultiply).setOnClickListener(v ->
				appendSymbol("*"));
		findViewById(R.id.buttonDivide).setOnClickListener(v ->
				appendSymbol("/"));
		findViewById(R.id.buttonLBracket).setOnClickListener(v ->
				appendSymbol("("));
		findViewById(R.id.buttonRBracket).setOnClickListener(v ->
				appendSymbol(")"));
		findViewById(R.id.buttonDelete).setOnClickListener(v ->
				deleteSymbol());
		findViewById(R.id.buttonClear).setOnClickListener(v ->
				clearSymbols());
		findViewById(R.id.buttonEqual).setOnClickListener(v ->
				calculate());
	}

	@Override
	protected void onSaveInstanceState(@NonNull Bundle outState)
	{
		super.onSaveInstanceState(outState);
		outState.putString("Formulae", textFormulae.getText().toString());
		outState.putString("Result", textResult.getText().toString());
	}

	@Override
	protected void onRestoreInstanceState(@NonNull Bundle savedInstanceState)
	{
		super.onRestoreInstanceState(savedInstanceState);
		textFormulae.setText(savedInstanceState.getString("Formulae"));
		textResult.setText(savedInstanceState.getString("Result"));
	}

	@SuppressLint("SetTextI18n")
	private void appendSymbol(String symbol)
	{
		textFormulae.setText(textFormulae.getText().toString() + symbol);
	}

	private void deleteSymbol()
	{
		CharSequence text = textFormulae.getText();
		if (text.length() > 0)
			textFormulae.setText(text.subSequence(0, text.length() - 1));
	}

	private void clearSymbols()
	{
		textFormulae.setText("");
		textResult.setText("0");
	}

	private void calculate()
	{
		try
		{
			textResult.setText(calculator.process(textFormulae.getText().toString()));
		} catch (RuntimeException e)
		{
			textResult.setText(e.getMessage());
		}
	}
}
