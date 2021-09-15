<template>
	<div>
		<vk-grid class="uk-child-width-auto@m" gutter="small" divided matched>
			<div>
				<vk-card padding=large class="uk-width-auto@m">
					<vk-nav>
						<vk-nav-item-header :title="$t('user_admin')"></vk-nav-item-header>
						<li class=""><router-link to="/admin/agricultures">{{ $t('agricultures') }}</router-link></li>
						<li class=""><router-link to="/admin/fields">{{ $t('fields') }}</router-link></li>
						<li class=""><router-link to="/admin/tasks">{{ $t('tasks') }}</router-link></li>
						<vk-nav-item href="#" :title="$t('tasks_generate')" @click="createTask">{{ $t('tasks_generate') }}</vk-nav-item>
					</vk-nav>
				</vk-card>
			</div>
			<div>
				<router-view />
			</div>
		</vk-grid>
	</div>
</template>

<script>
import AgriculturesTable from '@/components/AgriculturesTable.vue'
import Store from '@/store'

export default
{
	name: 'AdminPanel',
	components:
	{
		AgriculturesTable
	},
	methods:
	{
		async createTask()
		{
			await Store.dispatch('GEN_TASKS');
		}
	}
}
</script>
