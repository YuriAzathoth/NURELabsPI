<template>
	<div>
		<vk-card padding=large class="uk-width-extend@m">			
			<vk-card-title>{{ $t('field_add') }}</vk-card-title>
			<form id="formAddField" class="uk-form-stacked">
				<div>
					<label class="uk-form-label" for="cadastral">{{ $t('field_cadastral') }}:</label>
					<input class="uk-form-controls" type="text" v-model="cadastral" id="cadastral" :placeholder="$t('field_cadastral')"/>
				</div>
				<div>
					<label class="uk-form-label" for="agriculture">{{ $t('field_agriculture') }}:</label>
					<input class="uk-form-controls" type="text" v-model="agricultureText" id="agriculture" :placeholder="$t('field_agriculture')" readonly/>
					<vk-dropdown class="uk-form-controls">
						<vk-nav-dropdown>
							<vk-nav-item v-for="item in getAgricultures" :key="item.name" :title="item.name" @click="setAgriculture(item.id)"/>
						</vk-nav-dropdown>
					</vk-dropdown>
				</div>
				<div>
					<label class="uk-form-label" for="area">{{ $t('field_area') }}:</label>
					<input class="uk-form-controls" type="number" v-model="area" id="area" :placeholder="$t('field_area')"/>
				</div>
				<br>
				<vk-button class="uk-form-controls" @click="addField">{{ $t('crud_create') }}</vk-button>
				<p v-if="error">{{ error }}</p>
			</form>
		</vk-card>
	</div>
</template>

<script>
import Router from '@/router/index'
import Store from '@/store'

export default
{
	name: 'AddAgriculture',
	data ()
	{
		return {
			cadastral:'',
			agriculture:0,
			agricultureText:'',
			area:0,
			error:''
		};
	},
	mounted ()
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
		setAgriculture(id)
		{
			const found = Store.getters.AGRICULTURES.find(item => item.id === id);
			this.agriculture = found.id;
			this.agricultureText = found.name;
		},
		async addField()
		{
			await Store.dispatch('ADD_FIELD',
			{
				cadastral: this.cadastral,
				agriculture: this.agriculture,
				area: this.area,
				token: Store.getters.TOKEN
			});
			Router.push('/user/fields');
		}
	}
}
</script>
