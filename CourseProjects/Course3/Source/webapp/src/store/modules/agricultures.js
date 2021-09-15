import Api from '@/services/Api'
import Store from '@/store/index'

const state =
{
	agricultures:[]
};

const getters =
{
	AGRICULTURES: state => { return state.agricultures; }
};

const mutations =
{
	SET_AGRICULTURES:	(state, agricultures)	=> { state.agricultures = agricultures; },
	ADD_AGRICULTURE:	(state, agriculture)	=> { state.agricultures.push(agriculture); },
	DEL_AGRICULTURE:	(state, agriculture)	=> { state.agricultures = state.agricultures.filter(item => item.id !== agriculture.id); }
};

const actions =
{
	LOAD_AGRICULTURES: async (context) =>
	{
		await Api().post('/api/agriculture/table')
		.then(response =>
		{
			context.commit('SET_AGRICULTURES', response.data.table);
		})
		.catch(error =>
		{
			console.log(error);
		});
	},
	ADD_AGRICULTURE: async (context, payload) =>
	{
		await Api().post('/api/agriculture/create', payload)
		.then(response =>
		{
			Store.dispatch('LOAD_AGRICULTURES');
		})
		.catch(error =>
		{
			console.log(error);
		});
	},
	DEL_AGRICULTURE: async (context, payload) =>
	{
		await Api().post('/api/agriculture/delete',
		{
			id:payload.id,
			token:Store.getters.TOKEN
		})
		.then(response =>
		{
			Store.dispatch('LOAD_AGRICULTURES');
		})
		.catch(error =>
		{
			console.log(error);
		});
	},
	UPD_AGRICULTURE: async (context, payload) =>
	{
		await Api().post('/api/agriculture/update', payload)
		.then(response =>
		{
			Store.dispatch('LOAD_AGRICULTURES');
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
