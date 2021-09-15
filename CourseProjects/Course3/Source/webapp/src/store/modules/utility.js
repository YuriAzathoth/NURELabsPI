import Api from '@/services/Api'

const state =
{
	errors:[],
	temp:[]
};

const getters =
{
	ERRORS:	state => { return state.errors; },
	TEMP:	state => { return state.temp; }
};

const mutations =
{
	ERROR: (state, error) => { state.errors.push(error); },
	CLEAR_ERRORS: (state) => { state.errors = []; },
	SET_TEMP: (state, temp) => { state.temp = temp; }
};

const actions =
{
	SET_TEMP: async (context, payload) =>
	{
		await context.commit('SET_TEMP', payload);
	}
};

export default
{
	state,
	getters,
	mutations,
	actions,
};
