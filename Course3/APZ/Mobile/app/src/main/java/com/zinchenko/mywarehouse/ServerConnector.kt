package com.zinchenko.mywarehouse

import android.util.Log
import io.ktor.client.HttpClient
import io.ktor.client.request.*
import io.ktor.http.HttpMethod
import org.json.JSONObject
import kotlin.collections.HashMap

data class Product (var id: Int, var name: String, var warehouse: String, var count: Int)
data class Category (var id: Int, var name: String)

val _server = ServerConnector()
val g_server = "http://10.0.2.2:9981"
private val g_url = "$g_server/mobile-"

class ServerConnector
{
	// public:
	suspend fun login(login: String, pass: String)
	{
		var data = "0"
		HttpClient().use {
			data = it.post("${g_url}authorize")
			{
				method = HttpMethod.Post
				HttpRequestBuilder {
					parameter("login", login)
					parameter("pass", pass)
				}
			}
		}
		if (data == "0")
			return
		_logged = true
		val jsonObject = JSONObject(data)
		_token = jsonObject.getString("token")
		_login = jsonObject.getString("login")
		_id = jsonObject.getInt("id")
	}

	fun logout()
	{
		_logged = false
	}

	fun isLogged(): Boolean
	{
		return _logged
	}

	suspend fun loadProducts()
	{
		var data = "0"
		HttpClient().use {
			data = it.post("${g_url}product-get")
			{
				method = HttpMethod.Post
				HttpRequestBuilder {
					parameter("token", _token)
				}
			}
		}
		if (data == "0")
			return
		_products.clear()
		val jsonArray = JSONObject(data)
		for (i in 0 until jsonArray.length())
		{
			val jsonObject = jsonArray.getJSONObject(i.toString())
			val product = Product(
				id = jsonObject.getInt("id"),
				name = jsonObject.getString("name"),
				warehouse = jsonObject.getString("address"),
				count = jsonObject.getInt("count")
			)
			_products[i] = product
		}
		Log.i("Size", _products.size.toString())
	}

	suspend fun addProduct(id : Int, count : Int)
	{
		HttpClient().use {
			it.post<String>("${g_url}product-add")
			{
				method = HttpMethod.Post
				HttpRequestBuilder {
					parameter("id", id)
					parameter("token", _server._token)
					parameter("count", count)
				}
			}
		}
	}

	suspend fun removeProduct(id : Int)
	{
		HttpClient().use {
			it.post<String>("${g_url}product-remove")
			{
				method = HttpMethod.Post
				HttpRequestBuilder {
					parameter("id", id)
				}
			}
		}
	}

	suspend fun loadCategories() : HashMap<Int, Category>
	{
		var result = HashMap<Int, Category>()
		var data = "0"
		HttpClient().use { data = it.get("${g_url}categories") }
		val jsonArray = JSONObject(data)
		for (i in 0 until jsonArray.length())
		{
			val jsonObject = jsonArray.getJSONObject(i.toString())
			val category = Category(
				id = jsonObject.getInt("id"),
				name = jsonObject.getString("name")
			)
			result[i] = category
		}
		return result
	}

	// private:
	val _products = HashMap<Int, Product>()
	private var _logged = false
	private var _token = ""
	private var _login = ""
	private var _id = 0
}