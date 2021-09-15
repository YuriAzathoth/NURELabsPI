package com.example.farmingcontrol

import io.ktor.client.HttpClient
import io.ktor.client.request.*
import io.ktor.http.HttpMethod
import kotlin.collections.HashMap
import org.json.JSONObject

data class User(
	val token: String,
	val surname: String,
	val name: String,
	val email: String
)

data class Agriculture(
	val id: Int,
	val name: String,
	val humidityMin: Short,
	val humidityMax: Short
)

data class Field(
	val id: Int,
	val cadastral: String,
	val agriculture: Agriculture,
	val area: Short
)

data class IrrigationRecord(
    val date: String,
    val humidity: Short,
    val decission: Short,
    val count: Short
)

val g_api = ServerConnector()

class ServerConnector
{
	suspend fun login(email: String, pass: String)
	{
        var data = ""

		HttpClient().use {
			data = it.post("${host}user/login")
			{
				method = HttpMethod.Post
                body = "{\"email\":\"${email}\",\"password\":\"${pass}\"}"
			}
		}

		val jsonObject = JSONObject(data)
		if (!jsonObject.has("token"))
            return

        user = User(
            email = jsonObject.getString("email"),
            name = jsonObject.getString("name"),
            surname = jsonObject.getString("surname"),
            token = jsonObject.getString("token")
        )

        loadAgricultures()
        loadFields()
	}

    suspend fun addField(field: Field)
    {
        HttpClient().use {
            it.post<String>("${host}field/create")
            {
                method = HttpMethod.Post
                body = "{\"cadastral\":\"${field.cadastral}\",\"agriculture\":${field.agriculture.id},\"area\":${field.area},\"token\":\"${user!!.token}\"}"
            }
        }
    }

    suspend fun editField(field: Field)
    {
        HttpClient().use {
            it.post<String>("${host}field/update")
            {
                method = HttpMethod.Post
                body = "{\"agriculture\":${field.agriculture.id},\"area\":${field.area},\"id\":${field.id},\"token\":\"${user!!.token}\"}"
            }
        }
    }

	suspend fun removeField(id : Int)
	{
		HttpClient().use {
			it.post<String>("${host}field/delete")
			{
				method = HttpMethod.Post
				body = "{\"id\":${id},\"token\":\"${user!!.token}\"}"
			}
		}
	}

    suspend fun loadIrrigationLog(fieldId : Int)
    {
        var data = ""

        HttpClient().use {
            data = it.post("${host}field/read")
            {
                method = HttpMethod.Post
                body = "{\"id\":${fieldId},\"token\":\"${user!!.token}\"}"
            }
        }

        val jsonObject = JSONObject(data)
        if (!jsonObject.has("id"))
            return

        irrigationLog.clear()

        val jsonArray = jsonObject.getJSONArray("irrlog")
        for (i in 0 until jsonArray.length())
        {
            val jsonRecord = jsonArray.getJSONObject(i)
            val record = IrrigationRecord(
                date = jsonRecord.getString("time"),
                humidity = jsonRecord.getInt("humidity").toShort(),
                decission = jsonRecord.getInt("decission").toShort(),
                count = jsonRecord.getInt("count").toShort()
            )
            irrigationLog[record.date] = record
        }
    }

    suspend fun reload()
    {
        agricultures.clear()
        fields.clear()
        loadAgricultures()
        loadFields()
    }

	fun logout()
	{
        fields.clear()
        agricultures.clear()
		user = null
	}

    fun setCurrentField(id: Int)
    {
        currId = id
    }

    fun getCurrentField() : Field
    {
        return fields[currId]!!
    }

	fun isLogged(): Boolean
	{
		return user != null
	}

    fun getAgriculturesTable() : HashMap<Int, Agriculture>
    {
        return agricultures
    }

	fun getFieldsTable() : HashMap<Int, Field>
	{
		return fields
	}

    fun getIrrigationLog() : HashMap<String, IrrigationRecord>
    {
        return irrigationLog
    }

    private suspend fun loadAgricultures()
    {
        var data = ""

        HttpClient().use {
            data = it.post("${host}agriculture/table")
            {
                method = HttpMethod.Post
                body = "{\"token\":\"${user!!.token}\"}"
            }
        }

        val jsonObject = JSONObject(data)
        if (!jsonObject.has("table"))
            return

        val jsonTable = jsonObject.getJSONArray("table")
        for (i in 0 until jsonTable.length())
        {
            val jsonRecord = jsonTable.getJSONObject(i)
            val id = jsonRecord.getInt("id")
            val agriculture = Agriculture (
                id = id,
                name = jsonRecord.getString("name"),
                humidityMin = jsonRecord.getInt("humidity_min").toShort(),
                humidityMax = jsonRecord.getInt("humidity_max").toShort()
            )
            agricultures[id] = agriculture
        }
    }

    private suspend fun loadFields()
    {
        var data = ""

        HttpClient().use {
            data = it.post("${host}field/table")
            {
                method = HttpMethod.Post
                body = "{\"token\":\"${user!!.token}\"}"
            }
        }

        val jsonObject = JSONObject(data)
        if (!jsonObject.has("table"))
            return

        val jsonTable = jsonObject.getJSONArray("table")
        for (i in 0 until jsonTable.length())
        {
            val jsonRecord = jsonTable.getJSONObject(i)
            val id = jsonRecord.getInt("id")
            val field = Field (
                id = id,
                cadastral = jsonRecord.getString("cadastral"),
                agriculture = agricultures[jsonRecord.getJSONObject("agriculture").getInt("id")]!!,
                area = jsonRecord.getInt("area").toShort()
            )
            fields[id] = field
        }
    }

	private var user: User? = null
	private var agricultures = HashMap<Int, Agriculture>()
	private var fields = HashMap<Int, Field>()
    private var irrigationLog = HashMap<String, IrrigationRecord>()
    private var currId = -1

	private val host = "http://192.168.0.101:8020/api/"
}
