package com.zinchenko.lab3;

import android.util.Log;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.List;
import java.util.StringTokenizer;

public final class Calculator
{
	private final String operators = "+-*/^";
	private final String delimiters = "() " + operators;

	public final String process(String input) throws RuntimeException
	{
		Log.i("Test", input + " -> " + parse(input).toString() + " = " + calculate(parse(input)));
		return String.valueOf(calculate(parse(input)));
	}

	private List<String> parse(String infix) throws RuntimeException
	{
		List<String> postfix = new ArrayList<>();
		Deque<String> stack = new ArrayDeque<>();
		StringTokenizer tokenizer = new StringTokenizer(infix, delimiters, true);
		String prev = "";
		String curr = "";

		while (tokenizer.hasMoreTokens())
		{
			curr = tokenizer.nextToken();
			if (!tokenizer.hasMoreTokens() && isOperator(curr))
				throw new RuntimeException("Некорректное выражение: " + infix);

			if (curr.equals(" "))
				continue;

			if (isDelimiter(curr))
			{
				if (curr.equals("("))
					stack.push(curr);
				else if (curr.equals(")"))
				{
					while (!stack.peek().equals("("))
					{
						postfix.add(stack.pop());
						if (stack.isEmpty())
							throw new RuntimeException("Скобки не согласованы: " + infix);
					}
					stack.pop();
				}
				else
				{
					if (curr.equals("-") && (prev.equals("") || (isDelimiter(prev) && !prev.equals(")"))))
						curr = "u-";
					else
						while (!stack.isEmpty() && (getPriority(curr) <= getPriority(stack.peek())))
							postfix.add(stack.pop());
					stack.push(curr);
				}
			}
			else
				postfix.add(curr);
			prev = curr;
		}

		while (!stack.isEmpty())
			if (isOperator(stack.peek()))
				postfix.add(stack.pop());
			else
				throw new RuntimeException("Скобки не согласованы: " + infix);

		return postfix;
	}

	private double calculate(List<String> postfix)
	{
		Deque<Double> stack = new ArrayDeque<>();
		Double a;
		Double b;

		for (String str : postfix)
		{
			switch (str)
			{
				case "+":
					b = stack.pop();
					a = stack.pop();
					stack.push(a + b);
					break;
				case "-":
					b = stack.pop();
					a = stack.pop();
					stack.push(a - b);
					break;
				case "*":
					b = stack.pop();
					a = stack.pop();
					stack.push(a * b);
					break;
				case "/":
					b = stack.pop();
					a = stack.pop();
					stack.push(a / b);
					break;
				case "^":
					b = stack.pop();
					a = stack.pop();
					stack.push(Math.pow(a, b));
					break;
				case "u-":
					a = stack.pop();
					stack.push(-a);
					break;
				default:
					stack.push(Double.valueOf(str));
			}
		}
		return stack.pop();
	}

	private boolean isDelimiter(String token)
	{
		if (token.length() != 1)
			return false;
		else
			return delimiters.indexOf(token.charAt(0)) != -1;
	}

	private boolean isOperator(String token)
	{
		if (token.equals("u-"))
			return true;
		else
			return operators.indexOf(token.charAt(0)) != -1;
	}

	private byte getPriority(String token)
	{
		switch (token.charAt(0))
		{
			case '(':
				return 1;
			case '+':
			case '-':
				return 2;
			case '*':
			case '/':
				return 3;
			case '^':
				return 4;
			default:
				return 5;
		}
	}
}
