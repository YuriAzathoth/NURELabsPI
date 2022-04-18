package com.zinchenko.lab2

import java.lang.RuntimeException
import java.util.*
import kotlin.Throws
import kotlin.math.pow

class Calculator
{
	private val operators = "+-*/^"
	private val delimiters = "() $operators"

	@Throws(RuntimeException::class)
	fun process(input: String): String
	{
		return calculate(parse(input)).toString()
	}

	@Throws(RuntimeException::class)
	private fun parse(infix: String): List<String>
	{
		val postfix = ArrayList<String>()
		val stack = ArrayDeque<String>()
		val tokenizer = StringTokenizer(infix, delimiters, true)
		var prev = ""
		var curr: String

		while (tokenizer.hasMoreTokens())
		{
			curr = tokenizer.nextToken()
			if (!tokenizer.hasMoreTokens() && isOperator(curr)) throw RuntimeException("Некорректное выражение: $infix")
			if (curr == " ") continue
			if (isDelimiter(curr))
			{
				when (curr)
				{
					"(" -> stack.push(curr)
					")" ->
					{
						while (stack.peek() != "(")
						{
							postfix.add(stack.pop())
							if (stack.isEmpty()) throw RuntimeException("Скобки не согласованы: $infix")
						}
						stack.pop()
					}
					else ->
					{
						if (curr == "-" && (prev == "" || isDelimiter(prev) && prev != ")")) curr = "u-"
						else while (!stack.isEmpty() && getPriority(curr) <= getPriority(stack.last())) postfix.add(
							stack.pop()
						)
						stack.push(curr)
					}
				}
			}
			else postfix.add(curr)
			prev = curr
		}
		while (!stack.isEmpty()) if (isOperator(stack.last())) postfix.add(stack.pop())
		else throw RuntimeException(
			"Скобки не согласованы: $infix"
		)
		return postfix
	}

	private fun calculate(postfix: List<String>): Double
	{
		val stack: Deque<Double> = ArrayDeque()
		var a: Double
		var b: Double
		for (str in postfix) when (str)
		{
			"+" ->
			{
				b = stack.pop()
				a = stack.pop()
				stack.push(a + b)
			}
			"-" ->
			{
				b = stack.pop()
				a = stack.pop()
				stack.push(a - b)
			}
			"*" ->
			{
				b = stack.pop()
				a = stack.pop()
				stack.push(a * b)
			}
			"/" ->
			{
				b = stack.pop()
				a = stack.pop()
				stack.push(a / b)
			}
			"^" ->
			{
				b = stack.pop()
				a = stack.pop()
				stack.push(a.pow(b))
			}
			"u-" ->
			{
				a = stack.pop()
				stack.push(-a)
			}
			else -> stack.push(java.lang.Double.valueOf(str))
		}
		return stack.pop()
	}

	private fun isDelimiter(token: String): Boolean
	{
		return if (token.length != 1) false else delimiters.indexOf(token[0]) != -1
	}

	private fun isOperator(token: String): Boolean
	{
		return if (token == "u-") true else operators.indexOf(token[0]) != -1
	}

	private fun getPriority(token: String): Byte
	{
		return when (token[0])
		{
			'(' -> 1
			'+', '-' -> 2
			'*', '/' -> 3
			'^' -> 4
			else -> 5
		}
	}
}