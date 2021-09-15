<template>
	<div>
		<vk-card padding=large class="uk-width-extend@m">			
			<vk-card-title>{{ $t('agriculture_edit') }}</vk-card-title>
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
				<vk-button class="uk-form-controls" @click="editAgriculture">{{ $t('crud_create') }}</vk-button>
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
	name: 'UpdateAgriculture',
	data ()
	{
		return {
			id:0,
			name:'',
			humidityMin:0,
			humidityMax:0,
			error:''
		};
	},
	mounted()
	{
		const id = Store.getters.TEMP.id;
		const current = Store.getters.AGRICULTURES.find(item => item.id === id);
		this.id = id;
		this.name = current.name;
		this.humidityMin = current.humidity_min;
		this.humidityMax = current.humidity_max;
	},
	methods:
	{
		async editAgriculture()
		{
			await Store.dispatch('UPD_AGRICULTURE',
			{
				id:this.id,
				name:this.name,
				humidity_min:this.humidityMin,
				humidity_max:this.humidityMax,
				token:Store.getters.TOKEN
			});
			Router.push('agricultures');
		}
	}
}
</script>
