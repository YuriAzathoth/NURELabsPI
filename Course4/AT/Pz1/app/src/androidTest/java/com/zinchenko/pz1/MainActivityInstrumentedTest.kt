package com.zinchenko.pz1

import androidx.test.ext.junit.rules.activityScenarioRule
import androidx.test.espresso.Espresso.onView
import androidx.test.espresso.action.ViewActions.click
import androidx.test.espresso.assertion.ViewAssertions.matches
import androidx.test.espresso.matcher.ViewMatchers.withId
import androidx.test.espresso.matcher.ViewMatchers.withText
import androidx.test.runner.AndroidJUnit4
import org.hamcrest.core.StringContains.containsString
import org.junit.Rule
import org.junit.Test
import org.junit.runner.RunWith

@RunWith(
	AndroidJUnit4::class
)
class MainActivityInstrumentedTest
{
	@get:Rule
	val activityScenarioRule = activityScenarioRule<MainActivity>()

	@Test
	fun addInteger()
	{
		onView(withId(R.id.button2)).perform(click())
		onView(withId(R.id.button4)).perform(click())
		onView(withId(R.id.buttonPlus)).perform(click())
		onView(withId(R.id.button1)).perform(click())
		onView(withId(R.id.button2)).perform(click())
		onView(withId(R.id.buttonEqual)).perform(click())
		onView(withId(R.id.textResult)).check(matches(withText(containsString("36"))))
	}

	@Test
	fun addFloat()
	{
		onView(withId(R.id.button0)).perform(click())
		onView(withId(R.id.buttonDot)).perform(click())
		onView(withId(R.id.button5)).perform(click())
		onView(withId(R.id.buttonPlus)).perform(click())
		onView(withId(R.id.button0)).perform(click())
		onView(withId(R.id.buttonDot)).perform(click())
		onView(withId(R.id.button1)).perform(click())
		onView(withId(R.id.buttonEqual)).perform(click())
		onView(withId(R.id.textResult)).check(matches(withText(containsString("0.6"))))
	}

	@Test
	fun addZero()
	{
		onView(withId(R.id.button1)).perform(click())
		onView(withId(R.id.button2)).perform(click())
		onView(withId(R.id.buttonPlus)).perform(click())
		onView(withId(R.id.button0)).perform(click())
		onView(withId(R.id.buttonEqual)).perform(click())
		onView(withId(R.id.textResult)).check(matches(withText(containsString("12.0"))))
	}

	@Test
	fun addNegative()
	{
		onView(withId(R.id.buttonMinus)).perform(click())
		onView(withId(R.id.button2)).perform(click())
		onView(withId(R.id.button5)).perform(click())
		onView(withId(R.id.buttonPlus)).perform(click())
		onView(withId(R.id.buttonMinus)).perform(click())
		onView(withId(R.id.button1)).perform(click())
		onView(withId(R.id.button0)).perform(click())
		onView(withId(R.id.buttonEqual)).perform(click())
		onView(withId(R.id.textResult)).check(matches(withText(containsString("-35.0"))))
	}

	@Test
	fun subInteger()
	{
		onView(withId(R.id.button2)).perform(click())
		onView(withId(R.id.button8)).perform(click())
		onView(withId(R.id.buttonMinus)).perform(click())
		onView(withId(R.id.button1)).perform(click())
		onView(withId(R.id.button6)).perform(click())
		onView(withId(R.id.buttonEqual)).perform(click())
		onView(withId(R.id.textResult)).check(matches(withText(containsString("12"))))
	}

	@Test
	fun subFloat()
	{
		onView(withId(R.id.button0)).perform(click())
		onView(withId(R.id.buttonDot)).perform(click())
		onView(withId(R.id.button5)).perform(click())
		onView(withId(R.id.buttonMinus)).perform(click())
		onView(withId(R.id.button0)).perform(click())
		onView(withId(R.id.buttonDot)).perform(click())
		onView(withId(R.id.button2)).perform(click())
		onView(withId(R.id.button5)).perform(click())
		onView(withId(R.id.buttonEqual)).perform(click())
		onView(withId(R.id.textResult)).check(matches(withText(containsString("0.25"))))
	}

	@Test
	fun subZero()
	{
		onView(withId(R.id.button5)).perform(click())
		onView(withId(R.id.button0)).perform(click())
		onView(withId(R.id.buttonMinus)).perform(click())
		onView(withId(R.id.button0)).perform(click())
		onView(withId(R.id.buttonEqual)).perform(click())
		onView(withId(R.id.textResult)).check(matches(withText(containsString("0"))))
	}

	@Test
	fun subNegative()
	{
		onView(withId(R.id.buttonMinus)).perform(click())
		onView(withId(R.id.button4)).perform(click())
		onView(withId(R.id.button8)).perform(click())
		onView(withId(R.id.buttonMinus)).perform(click())
		onView(withId(R.id.buttonMinus)).perform(click())
		onView(withId(R.id.button1)).perform(click())
		onView(withId(R.id.button2)).perform(click())
		onView(withId(R.id.buttonEqual)).perform(click())
		onView(withId(R.id.textResult)).check(matches(withText(containsString("-36"))))
	}

	@Test
	fun multiplyInteger()
	{
		onView(withId(R.id.button1)).perform(click())
		onView(withId(R.id.button2)).perform(click())
		onView(withId(R.id.buttonMultiply)).perform(click())
		onView(withId(R.id.button4)).perform(click())
		onView(withId(R.id.buttonEqual)).perform(click())
		onView(withId(R.id.textResult)).check(matches(withText(containsString("48.0"))))
	}

	@Test
	fun multiplyFloat()
	{
		onView(withId(R.id.button0)).perform(click())
		onView(withId(R.id.buttonDot)).perform(click())
		onView(withId(R.id.button2)).perform(click())
		onView(withId(R.id.buttonMultiply)).perform(click())
		onView(withId(R.id.button0)).perform(click())
		onView(withId(R.id.buttonDot)).perform(click())
		onView(withId(R.id.button4)).perform(click())
		onView(withId(R.id.buttonEqual)).perform(click())
		onView(withId(R.id.textResult)).check(matches(withText(containsString("0.08"))))
	}

	@Test
	fun multiplyZero()
	{
		onView(withId(R.id.button1)).perform(click())
		onView(withId(R.id.button0)).perform(click())
		onView(withId(R.id.buttonMultiply)).perform(click())
		onView(withId(R.id.button0)).perform(click())
		onView(withId(R.id.buttonEqual)).perform(click())
		onView(withId(R.id.textResult)).check(matches(withText(containsString("0.0"))))
	}

	@Test
	fun multiplyNegative()
	{
		onView(withId(R.id.buttonMinus)).perform(click())
		onView(withId(R.id.button1)).perform(click())
		onView(withId(R.id.button2)).perform(click())
		onView(withId(R.id.buttonMultiply)).perform(click())
		onView(withId(R.id.buttonMinus)).perform(click())
		onView(withId(R.id.button8)).perform(click())
		onView(withId(R.id.buttonEqual)).perform(click())
		onView(withId(R.id.textResult)).check(matches(withText(containsString("96.0"))))
	}

	@Test
	fun divideInteger()
	{
		onView(withId(R.id.button5)).perform(click())
		onView(withId(R.id.button6)).perform(click())
		onView(withId(R.id.buttonDivide)).perform(click())
		onView(withId(R.id.button4)).perform(click())
		onView(withId(R.id.buttonEqual)).perform(click())
		onView(withId(R.id.textResult)).check(matches(withText(containsString("14.0"))))
	}

	@Test
	fun divideFloat()
	{
		onView(withId(R.id.button0)).perform(click())
		onView(withId(R.id.buttonDot)).perform(click())
		onView(withId(R.id.button8)).perform(click())
		onView(withId(R.id.buttonDivide)).perform(click())
		onView(withId(R.id.button0)).perform(click())
		onView(withId(R.id.buttonDot)).perform(click())
		onView(withId(R.id.button2)).perform(click())
		onView(withId(R.id.buttonEqual)).perform(click())
		onView(withId(R.id.textResult)).check(matches(withText(containsString("4.0"))))
	}

	@Test
	fun divideZero()
	{
		onView(withId(R.id.button1)).perform(click())
		onView(withId(R.id.button0)).perform(click())
		onView(withId(R.id.buttonDivide)).perform(click())
		onView(withId(R.id.button0)).perform(click())
		onView(withId(R.id.buttonEqual)).perform(click())
		onView(withId(R.id.textResult)).check(matches(withText(containsString("Infinity"))))
	}

	@Test
	fun divideNegative()
	{
		onView(withId(R.id.buttonMinus)).perform(click())
		onView(withId(R.id.button2)).perform(click())
		onView(withId(R.id.button5)).perform(click())
		onView(withId(R.id.buttonDivide)).perform(click())
		onView(withId(R.id.buttonMinus)).perform(click())
		onView(withId(R.id.button5)).perform(click())
		onView(withId(R.id.buttonEqual)).perform(click())
		onView(withId(R.id.textResult)).check(matches(withText(containsString("5.0"))))
	}
}
