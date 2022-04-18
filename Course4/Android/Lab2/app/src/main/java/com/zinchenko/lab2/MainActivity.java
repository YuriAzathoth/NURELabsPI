package com.zinchenko.lab2;

import android.os.Bundle;
import android.view.SurfaceView;
import android.widget.SeekBar;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;

public final class MainActivity extends AppCompatActivity
{
	private SurfaceView colorView;
	private SeekBar sliderRed;
	private SeekBar sliderGreen;
	private SeekBar sliderBlue;

	protected void onCreate(Bundle savedInstanceState)
	{
		super.onCreate(savedInstanceState);
		this.setContentView(R.layout.activity_main);
		this.setTitle("Yurii Zinchenko PZPIz-18-1 Lab2");

		colorView = findViewById(R.id.colorView);
		sliderRed = findViewById(R.id.sliderRed);
		sliderGreen = findViewById(R.id.sliderGreen);
		sliderBlue = findViewById(R.id.sliderBlue);

		SeekBar.OnSeekBarChangeListener onSeekBarChange = new SeekBar.OnSeekBarChangeListener()
		{
			@Override
			public void onStartTrackingTouch(SeekBar seekBar)
			{
			}

			@Override
			public void onStopTrackingTouch(SeekBar seekBar)
			{
			}

			@Override
			public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser)
			{
				updateColor();
			}
		};

		sliderRed.setOnSeekBarChangeListener(onSeekBarChange);
		sliderGreen.setOnSeekBarChangeListener(onSeekBarChange);
		sliderBlue.setOnSeekBarChangeListener(onSeekBarChange);
	}

	@Override
	protected void onSaveInstanceState(@NonNull Bundle outState)
	{
		super.onSaveInstanceState(outState);
		outState.putInt("Red", sliderRed.getProgress());
		outState.putInt("Green", sliderGreen.getProgress());
		outState.putInt("Blue", sliderBlue.getProgress());
	}

	@Override
	protected void onRestoreInstanceState(@NonNull Bundle savedInstanceState)
	{
		super.onRestoreInstanceState(savedInstanceState);
		sliderRed.setProgress(savedInstanceState.getInt("Red"));
		sliderGreen.setProgress(savedInstanceState.getInt("Green"));
		sliderBlue.setProgress(savedInstanceState.getInt("Blue"));
	}

	private void updateColor()
	{
		colorView.setBackgroundColor(calcBackgroundColor(sliderRed.getProgress(), sliderGreen.getProgress(), sliderBlue.getProgress()));
	}

	private int calcBackgroundColor(int r, int g, int b)
	{
		return 0xFF000000 | progressToColor(r) << 16 | progressToColor(g) << 8 | progressToColor(b);
	}

	private int progressToColor(int progress)
	{
		return (int) ((float) progress * 2.55);
	}
}
