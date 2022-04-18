package com.zinchenko.pz1

import java.util.*
import kotlin.collections.ArrayDeque
import kotlin.math.pow

class Calculator
{
	fun process(input: String): String
	{
		return calculate(parse(input)).toString()
	}

	private fun parse(infix: String): List<String>
	{
		val postfix = ArrayList<String>()
		val stack = ArrayDeque<String>()
		val tokenizer = StringTokenizer(infix, delimiters, true)
		var prev = String()
		var curr: String

		while (tokenizer.hasMoreTokens())
		{
			curr = tokenizer.nextToken()

			if (!tokenizer.hasMoreTokens() && isOperator(curr)) throw RuntimeException("Недопустимое выражение: $infix")

			if (curr == " ") continue

			if (isDelimiter(curr))
			{
				when (curr)
				{
					"(" -> stack.addLast(curr)
					")" ->
					{
						while (stack.last() != ")")
						{
							postfix.add(stack.last())
							stack.removeLast()
							if (stack.isEmpty()) throw RuntimeException("Скобки не согласованы: $infix")
						}
						stack.removeLast()
					}
					else ->
					{
						if (curr == "-" && (prev == "" || (isDelimiter(prev) && prev != ")"))) curr =
							"u-"
						else while (!stack.isEmpty() && (getPriority(curr) <= getPriority(stack.last())))
						{
							postfix.add(
								stack.last()
							)
							stack.removeLast()
						}
						stack.addLast(curr)
					}
				}
			}
			else postfix.add(curr)
			prev = curr
		}

		while (!stack.isEmpty())
		{
			if (isOperator(stack.last()))
			{
				postfix.add(stack.last())
				stack.removeLast()
			}
			else throw RuntimeException("Скобки не согласованы: $infix")
		}
		return postfix
	}

	private fun calculate(postfix: List<String>): Double
	{
		val stack = ArrayDeque<Double>()
		var a: Double
		var b: Double
		for (str in postfix)
		{
			when (str)
			{
				"+" ->
				{
					b = stack.last()
					stack.removeLast()
					a = stack.last()
					stack.removeLast()
					stack.addLast(a + b)
				}
				"-" ->
				{
					b = stack.last()
					stack.removeLast()
					a = stack.last()
					stack.removeLast()
					stack.addLast(a - b)
				}
				"*" ->
				{
					b = stack.last()
					stack.removeLast()
					a = stack.last()
					stack.removeLast()
					stack.addLast(a * b)
				}
				"/" ->
				{
					b = stack.last()
					stack.removeLast()
					a = stack.last()
					stack.removeLast()
					stack.addLast(a / b)
				}
				"^" ->
				{
					b = stack.last()
					stack.removeLast()
					a = stack.last()
					stack.removeLast()
					stack.addLast(a.pow(b))
				}
				"u-" ->
				{
					a = stack.last()
					stack.removeLast()
					stack.addLast(-a)
				}
				else -> stack.addLast(str.toDouble())
			}
		}
		return stack.last()
	}

	private fun isDelimiter(token: String): Boolean
	{
		if (token.length != 1) return false
		return delimiters.indexOf(token[0]) != -1
	}

	private fun isOperator(token: String): Boolean
	{
		if (token == "u-") return true
		return operators.indexOf(token[0]) != -1
	}

	private fun getPriority(token: String): Byte
	{
		return when (token[0])
		{
			'(' -> 0
			'+' -> 1
			'-' -> 1
			'*' -> 2
			'/' -> 2
			'^' -> 2
			else -> 4
		}
	}

	private val operators = "+-*/^"
	private val delimiters = "() $operators"
}
