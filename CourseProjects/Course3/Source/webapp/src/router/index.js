import Vue from 'vue'
import VueRouter from 'vue-router'

import AddAgriculture from '@/views/AddAgriculture.vue'
import AddField from '@/views/AddField.vue'
import AdminPanel from '@/views/AdminPanel.vue'
import EmployeePanel from '@/views/EmployeePanel.vue'
import Home from '@/views/Home.vue'
import LogIn from '@/views/LogIn.vue'
import SignUp from '@/views/SignUp.vue'
import UpdateAgriculture from '@/views/UpdateAgriculture.vue'
import UpdateField from '@/views/UpdateField.vue'
import UserPanel from '@/views/UserPanel.vue'

import AgriculturesTable from '@/components/AgriculturesTable.vue'
import FieldsTable from '@/components/FieldsTable.vue'
import TasksTable from '@/components/TasksTable.vue'
import UserProfile from '@/components/UserProfile.vue'

Vue.use(VueRouter)

const routes =
[
	{
		path: '/login',
		name: 'LogIn',
		component: LogIn
	},
	{
		path: '/signup',
		name: 'SignUp',
		component: SignUp
	},
	{
		path: '/user',
		name: 'User',
		component: UserPanel,
		children:
		[
			{
				path: 'fields',
				component: FieldsTable
			},
			{
				path: 'field-add',
				component: AddField
			},
			{
				path: 'field-upd',
				component: UpdateField
			},
			{
				path: 'profile',
				component: UserProfile
			}
		]
	},
	{
		path: '/employee',
		name: 'Employee',
		component: EmployeePanel,
		children:
		[
			{
				path: 'tasks',
				component: TasksTable
			},
			{
				path: 'profile',
				component: UserProfile
			}
		]
	},
	{
		path: '/admin',
		name: 'Admin',
		component: AdminPanel,
		children:
		[
			{
				path: 'agricultures',
				component: AgriculturesTable
			},
			{
				path: 'agriculture-add',
				component: AddAgriculture
			},
			{
				path: 'agriculture-upd',
				component: UpdateAgriculture
			},
			{
				path: 'fields',
				component: FieldsTable
			},
			{
				path: 'field-add',
				component: AddField
			},
			{
				path: 'field-upd',
				component: UpdateField
			},
			{
				path: 'tasks',
				component: TasksTable
			}
		]
	}
]

const router = new VueRouter(
{
	mode: 'history',
	base: process.env.BASE_URL,
	routes
})

export default router
