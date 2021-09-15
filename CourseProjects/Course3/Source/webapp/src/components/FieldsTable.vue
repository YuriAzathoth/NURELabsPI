<template>
	<div>
		<vk-grid class="uk-child-width-auto@m" gutter="small" divided matched>
			<div>
				<vk-card>
					<vk-card-title>{{ $t('fields') }}</vk-card-title>
					<vk-table :data="getFields" :selected-rows.sync="currFieldId" row-selectable striped>
						<vk-table-column :title="$t('field_cadastral')" cell="cadastral" />
						<vk-table-column :title="$t('field_agriculture')" cell="agriculture.name" />
						<vk-table-column :title="$t('field_area')" cell="area" />
						<vk-table-column cell="id">
							<vk-button slot-scope="{ row }" @click="editField(row.id)">{{ $t('crud_update') }}</vk-button>
						</vk-table-column>
						<vk-table-column cell="id">
							<vk-button slot-scope="{ row }" @click="deleteField(row.id)">{{ $t('crud_delete') }}</vk-button>
						</vk-table-column>
					</vk-table>
					<router-link to="field-add"><vk-button>{{ $t('crud_create') }}</vk-button></router-link>
				</vk-card>
			</div>
			<div class="uk-width-expand@m">
				<template v-if="currFieldId.length && getLog">
					<vk-card>
						<vk-card-title>{{ $t('irrlog_title') }}</vk-card-title>
						<vk-table :data="getLog" striped>
							<vk-table-column :title="$t('irrlog_date')" cell="time" />
							<vk-table-column :title="$t('irrlog_humidity')" cell="humidity" />
							<vk-table-column :title="$t('irrlog_decission')" cell="decission" />
							<vk-table-column :title="$t('irrlog_count')" cell="count" />
						</vk-table>
					</vk-card>
				</template>
			</div>
		</vk-grid>
	</div>
</template>

<script>
import Router from '@/router/index'
import Store from '@/store'

export default
{
	name: 'FieldsTable',
	props: {},
	data ()
	{
		return {
			currFieldId:[],
			currFieldLog:[]
		}
	},
	mounted()
	{
		Store.dispatch('LOAD_FIELDS');
	},
	computed:
	{
		getFields()
		{
			return Store.getters.FIELDS;
		},
		getLog()
		{
			return Store.getters.FIELDS.find(item => item.id === this.currFieldId[0]).irrlog;
		}
	},
	methods:
	{
		async editField(id)
		{
			await Store.dispatch('SET_TEMP', {id:id});
			Router.push('field-upd');
		},
		async deleteField(id)
		{
			await Store.dispatch('DEL_FIELD', {id:id});
		}
	}
}
</script>
