package com.example.farmingcontrol

import android.content.Intent
import android.net.Uri
import android.os.Bundle
import androidx.appcompat.app.AppCompatActivity
import kotlinx.android.synthetic.main.activity_login.*
import kotlinx.coroutines.runBlocking

const val g_fontSize = 12f
const val g_columnSize = 180

class LoginActivity : AppCompatActivity()
{
	override fun onCreate(savedInstanceState: Bundle?)
	{
		super.onCreate(savedInstanceState)
		setContentView(R.layout.activity_login)

        btnLogin.setOnClickListener()
		{
			runBlocking {
                g_api.login(
                    txtEmail.text.toString(),
                    txtPassword.text.toString()
                )
            }
			showMainForm()
		}

		btnRegister.setOnClickListener()
		{
			openRegisterPage()
		}
	}

	private fun showMainForm()
	{
		val intent = Intent(this, TableActivity::class.java)
		startActivity(intent)
	}

	private fun openRegisterPage()
	{
		val intent = Intent(android.content.Intent.ACTION_VIEW)
		intent.data = Uri.parse("https://192.168.0.101:8080/user/signup")
		startActivity(intent)
	}
}
