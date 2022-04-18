package com.zinchenko.pz1

import junit.framework.TestCase.assertEquals
import org.junit.Test

class MainActivityTest
{
	@Test
	fun addInteger()
	{
		assertEquals("10.0", calc.process("2+8"))
	}

	@Test
	fun addFloat()
	{
		assertEquals("0.22", calc.process("0.2+0.02"))
	}

	@Test
	fun addZero()
	{
		assertEquals("8.0", calc.process("8+0"))
	}

	@Test
	fun addNegative()
	{
		assertEquals("-12.0", calc.process("-8+-4"))
	}

	@Test
	fun subInteger()
	{
		assertEquals("3.0", calc.process("5-2"))
	}

	@Test
	fun subFloat()
	{
		assertEquals("0.08", calc.process("0.1-0.02"))
	}

	@Test
	fun subZero()
	{
		assertEquals("4.0", calc.process("4-0"))
	}

	@Test
	fun subNegative()
	{
		assertEquals("-6.0", calc.process("-8--2"))
	}

	@Test
	fun multiplyInteger()
	{
		assertEquals("20.0", calc.process("5*4"))
	}

	@Test
	fun multiplyFloat()
	{
		assertEquals("0.1", calc.process("0.5*0.2"))
	}

	@Test
	fun multiplyZero()
	{
		assertEquals("0.0", calc.process("8*0"))
	}

	@Test
	fun multiplyNegative()
	{
		assertEquals("20.0", calc.process("-5*-4"))
	}

	@Test
	fun divideInteger()
	{
		assertEquals("2.5", calc.process("5/2"))
	}

	@Test
	fun divideFloat()
	{
		assertEquals("5.0", calc.process("0.5/0.1"))
	}

	@Test
	fun divideZero()
	{
		assertEquals("Infinity", calc.process("2/0"))
	}

	@Test
	fun divideNegative()
	{
		assertEquals("2.5", calc.process("-10/-4"))
	}

	private val calc = Calculator()
}