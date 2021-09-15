import Api from '@/services/Api'
import Store from '@/store/index'

const state =
{
	fields:[],
};

const getters =
{
	FIELDS: state => { return state.fields; },
};

const mutations =
{
	SET_FIELDS:		(state, fields)		=> { state.fields = fields; },
	ADD_FIELD:		(state, field)		=> { state.fields.push(field); },
	DEL_FIELD:		(state, field)		=> { state.fields = state.fields.filter(item => item.id !== field.id); }
};

const actions =
{
	LOAD_FIELDS: async (context) =>
	{
		await Api().post('/api/field/table',
		{
			token:Store.getters.TOKEN
		})
		.then(response =>
		{
			context.commit('SET_FIELDS', response.data.table);
		})
		.catch(error =>
		{
			console.log(error);
		});
	},
	ADD_FIELD: async (context, payload) =>
	{
		await Api().post('/api/field/create', payload)
		.then(response =>
		{
			Store.dispatch('LOAD_FIELDS');
		})
		.catch(error =>
		{
			console.log(error);
		});
	},
	DEL_FIELD: async (context, payload) =>
	{
		await Api().post('/api/field/delete',
		{
			id:payload.id,
			token:Store.getters.TOKEN
		})
		.then(response =>
		{
			Store.dispatch('LOAD_FIELDS');
		})
		.catch(error =>
		{
			console.log(error);
		});
	},
	UPD_FIELD: async (context, payload) =>
	{
		payload.token = Store.getters.TOKEN;
		await Api().post('/api/field/update', payload)
		.then(response =>
		{
			Store.dispatch('LOAD_FIELDS');
		})
		.catch(error =>
		{
			console.log(error);
		});
	}
};

export default
{
	state,
	getters,
	mutations,
	actions,
};
