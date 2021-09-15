<template>
	<div id="app">
		<vk-navbar>
			<vk-navbar-nav>
				<vk-navbar-item title="Home"><router-link to="/">{{ $t('nav_home') }}</router-link></vk-navbar-item>
				<vk-navbar-item title="Mobile"><a href="/farming_control.apk">{{ $t('nav_mobile') }}</a></vk-navbar-item>
			</vk-navbar-nav>
			<vk-navbar-nav slot="right">
				<button>{{ i18n }}</button>
				<vk-dropdown>
					<vk-nav-dropdown>
						<vk-nav-item title="ua" @click="setLocale('ua')"/>
						<vk-nav-item title="en" @click="setLocale('en')"/>
					</vk-nav-dropdown>
				</vk-dropdown>
				<template v-if="!isLoggedIn">
					<vk-navbar-item title="Log In"><router-link to="/login">{{ $t('user_login') }}</router-link></vk-navbar-item>
					<vk-navbar-item title="Sign Up"><router-link to="/signup">{{ $t('user_signup') }}</router-link></vk-navbar-item>
				</template>
				<template v-else>
					<vk-navbar-item>{{ $t('user_hello') }}, {{ this.$store.getters.NAME }} {{ this.$store.getters.SURNAME }}</vk-navbar-item>
					<template v-if="isAdmin">
						<vk-navbar-item title="Admin Panel"><router-link to="/admin">{{ $t('user_admin') }}</router-link></vk-navbar-item>
					</template>
					<template v-else><template v-if="isEmployee">
						<vk-navbar-item title="Admin Panel"><router-link to="/employee">{{ $t('user_employee') }}</router-link></vk-navbar-item>
					</template>
					<template v-else>
						<vk-navbar-item title="Fields"><router-link to="/user/fields">{{ $t('user_panel') }}</router-link></vk-navbar-item>
					</template></template>
					<vk-navbar-item title="Log Out"><a @click="logout">{{ $t('user_logout') }}</a></vk-navbar-item>
				</template>
			</vk-navbar-nav>
		</vk-navbar>
		<router-view></router-view>
	</div>
</template>

<script>
import Cookies from 'vue-cookies'
import Router from '@/router/index'
import Store from '@/store/index'
import VueI18n from '@/i18n'

export default
{
	mounted ()
	{
		if (Cookies.isKey('user'))
			Store.commit('SET_USER', Cookies.get('user'));
	},
	computed:
	{
		isLoggedIn()
		{
			return Store.getters.TOKEN;
		},
		isAdmin()
		{
			return Store.getters.ROLE == 0;
		},
		isEmployee()
		{
			return Store.getters.ROLE == 2;
		},
		i18n()
		{
			return VueI18n.locale;
		}
	},
	methods:
	{
		setLocale(locale)
		{
			VueI18n.locale = locale;
		},
		async logout()
		{
			await Store.dispatch('LOGOUT');
			Router.push('/login');
		}
	}
}
</script>
