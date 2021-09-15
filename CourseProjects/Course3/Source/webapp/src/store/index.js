import Vue from 'vue'
import Vuex from 'vuex'
import Axios from 'axios'
import VueAxios from 'vue-axios'

import agricultures from '@/store/modules/agricultures';
import field from '@/store/modules/field';
import task from '@/store/modules/task';
import user from '@/store/modules/user';
import utility from '@/store/modules/utility';

Vue.use(Vuex)
Vue.use(VueAxios, Axios)

export default new Vuex.Store(
{
	state:{},
	getters:{},
	mutations:{},
	actions:{},
	modules:
	{
		agricultures,
		field,
		task,
		user,
		utility
	},
	strict: process.env.NODE_ENV !== 'production'
})
