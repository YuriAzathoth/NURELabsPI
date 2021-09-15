import Vue from 'vue'
import VueCookies from 'vue-cookies'
import Vuikit from 'vuikit'
import VuikitIcons from '@vuikit/icons'
import '@vuikit/theme'

import App from './App.vue'
import router from '@/router'
import store from '@/store'
import i18n from '@/i18n'

Vue.use(VueCookies)
Vue.use(Vuikit)
Vue.use(VuikitIcons)
Vue.config.productionTip = false

Vue.use(async (req, res, next) =>
{
	res.setHeader('Access-Control-Allow-Origin', '*');
	res.setHeader("Access-Control-Allow-Methods", "GET, PUT, POST, DELETE");
	res.setHeader("Access-Control-Allow-Headers", "Origin, X-Requested-With, Content-Type, Accept, Authorization");
	next();
});

new Vue(
{
	router,
	store,
	i18n,
	render: function (h) { return h(App) }
}).$mount('#app')
