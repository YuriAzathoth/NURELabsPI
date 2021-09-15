<template>
	<div>
		<vk-card padding=large class="uk-width-extend@m">			
			<vk-card-title>{{ $t('agriculture_add') }}</vk-card-title>
			<p><form id="formAddAgriculture" class="uk-form-stacked">
				<div>
					<label class="uk-form-label" for="name">{{ $t('agriculture_name') }}:</label>
					<input class="uk-form-controls" type="text" v-model="name" id="name" :placeholder="$t('agriculture_name')"/>
				</div>
				<div>
					<label class="uk-form-label">{{ $t('agriculture_humidity') }}:</label>
					<input class="uk-form-controls" type="number" v-model="humidityMin" :placeholder="$t('agriculture_hmin')"/>
					<input class="uk-form-controls" type="number" v-model="humidityMax" :placeholder="$t('agriculture_hmax')"/>
				</div>
				<br>
				<vk-button class="uk-form-controls" @click="addAgriculture">{{ $t('crud_create') }}</vk-button>
				<p v-if="error">{{ error }}</p>
			</form></p>
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
			name:'',
			humidityMin:0.0,
			humidityMax:0.0,
			error:''
		};
	},
	methods:
	{
		async addAgriculture()
		{
			await Store.dispatch('ADD_AGRICULTURE',
			{
				name: this.name,
				humidity_min: this.humidityMin,
				humidity_max: this.humidityMax,
				token: Store.getters.TOKEN
			});
			Router.push('agricultures');
		}
	}
}
</script>
