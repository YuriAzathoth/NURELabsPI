<template>
	<div>
		<vk-card>
			<vk-card-title>{{ $t('tasks') }}</vk-card-title>
			<vk-table :data="getTasks" striped>
				<vk-table-column :title="$t('tasks_field')" cell="field.cadastral" />
				<vk-table-column :title="$t('tasks_user')" cell="employee.surname" />
				<vk-table-column cell="employee.email" />
				<vk-table-column :title="$t('tasks_status')" cell="status" />
			</vk-table>
		</vk-card>
	</div>
</template>

<script>
import Router from '@/router/index'
import Store from '@/store'

export default
{
	name: 'TasksTable',
	props: {},
	mounted()
	{
		Store.dispatch('LOAD_TASKS');
	},
	computed:
	{
		getTasks()
		{
			return Store.getters.TASKS;
		}
	}
}
</script>
