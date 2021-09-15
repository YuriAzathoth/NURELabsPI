import Cookies from 'vue-cookies'
import Api from '@/services/Api'
import Store from '@/store/index'

const state =
{
	user:
	{
		name:"",
		surname:"",
		email:"",
		role:-1,
		token:""
	}
};

const getters =
{
	SURNAME:	state => { return state.user.surname; },
	NAME:		state => { return state.user.name; },
	EMAIL:		state => { return state.user.email; },
	ROLE:		state => { return state.user.role; },
	TOKEN:		state => { return state.user.token; }
};

const mutations =
{
	SET_USER: (state, user) =>
	{
		state.user = user;
		Cookies.set('user', user);
	},
	SET_USER_EMAIL: (state, email) =>
	{
		state.user.email = email;
		Cookies.set('user', user);
	},
	RESET_USER:	(state) =>
	{
		state.user = '';
		if (Cookies.isKey('user'))
			Cookies.remove('user');
	}
};

const actions =
{
	LOGIN: async (context, payload) =>
	{
		await Api().post('/api/user/login', payload)
		.then(response =>
		{
			if (!response.data.code)
				context.commit('SET_USER', response.data);
			else
				context.commit('ERROR', 'Invalid login or password');
		})
		.catch(error =>
		{
			console.log(error);
		});
	},
	SIGNUP: async (context, payload) =>
	{
		await Api().post('/api/user/signup', payload)
		.then(response =>
		{
			if (!response.data.code)
				context.commit('SET_USER', response.data);
			else
				context.commit('ERROR', response.data.message);
		})
		.catch(error =>
		{
			console.log(error);
		});
	},
	LOGOUT: async (context) =>
	{
		await context.commit('RESET_USER');
	},
	EDIT: async (context, payload) =>
	{
		payload.login.email = Store.getters.EMAIL;
		await Api().post('/api/user/edit', payload)
		.then(response =>
		{
			if (!response.data.code)
			{
				Store.dispatch('LOGIN',
				{
					email: payload.edit.email ? payload.edit.email : payload.login.email,
					password: payload.edit.password ? payload.edit.password : payload.login.password
				});
			}
			else
				context.commit('ERROR', response.data.message);
		})
		.catch(error =>
		{
			console.log(error);
		});
	},
};

export default
{
	state,
	getters,
	mutations,
	actions,
};
