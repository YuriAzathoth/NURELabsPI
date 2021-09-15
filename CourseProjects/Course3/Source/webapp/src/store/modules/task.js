import Api from '@/services/Api'
import Store from '@/store/index'

const state =
{
	tasks:[]
};

const getters =
{
	TASKS: state => { return state.tasks; }
};

const mutations =
{
	SET_TASKS: (state, tasks) => { state.tasks = tasks; },
};

const actions =
{
	LOAD_TASKS: async (context) =>
	{
		await Api().post('/api/task/get',
		{
			token: Store.getters.TOKEN
		})
		.then(response =>
		{
			context.commit('SET_TASKS', response.data.table);
		})
		.catch(error =>
		{
			console.log(error);
		});
	},
	GEN_TASKS: async (context) =>
	{
		await Api().post('/api/task/create',
		{
			token: Store.getters.TOKEN
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
