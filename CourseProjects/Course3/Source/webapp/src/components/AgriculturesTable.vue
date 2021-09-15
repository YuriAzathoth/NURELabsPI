<template>
	<div>
		<vk-card>
			<vk-card-title>{{ $t('agricultures') }}</vk-card-title>
			<vk-table :data="getAgricultures" striped>
				<vk-table-column :title="$t('agriculture_name')" cell="name" />
				<vk-table-column :title="$t('agriculture_hmin')" cell="humidity_min" />
				<vk-table-column :title="$t('agriculture_hmax')" cell="humidity_max" />
				<vk-table-column cell="id">
					<vk-button slot-scope="{ row }" @click="editAgriculture(row.id)">{{ $t('crud_update') }}</vk-button>
				</vk-table-column>
				<vk-table-column cell="id">
					<vk-button slot-scope="{ row }" @click="deleteAgriculture(row.id)">{{ $t('crud_delete') }}</vk-button>
				</vk-table-column>
			</vk-table>
			<router-link to="/admin/agriculture-add"><vk-button>{{ $t('crud_create') }}</vk-button></router-link>
		</vk-card>
	</div>
</template>

<script>
import Router from '@/router/index'
import Store from '@/store'

export default
{
	name: 'AgriculturesTable',
	props: {},
	mounted()
	{
		Store.dispatch('LOAD_AGRICULTURES');
	},
	computed:
	{
		getAgricultures()
		{
			return Store.getters.AGRICULTURES;
		}
	},
	methods:
	{
		async editAgriculture(id)
		{
			await Store.dispatch('SET_TEMP', {id:id});
			Router.push('agriculture-upd');
		},
		async deleteAgriculture(id)
		{
			await Store.dispatch('DEL_AGRICULTURE', {id:id});
		}
	}
}
</script>
