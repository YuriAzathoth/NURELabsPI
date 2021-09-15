<template>
	<div>
		<vk-grid class="uk-child-width-expand@m" gutter="small" divided matched>
			<div>
				<vk-card>
					</vk-card-title>{{ $t('user_profile_title') }}</vk-card-title>
					<form id="formOldData">
						<input class="uk-form-controls" type="password" v-model="oldPassword" :placeholder="$t('user_password')"/>
					</form>
						<input class="uk-form-controls" type="text" v-model="surname" :placeholder="$t('user_surname')"/>
						<input class="uk-form-controls" type="text" v-model="name" :placeholder="$t('user_name')"/>
						<input class="uk-form-controls" type="password" v-model="password" :placeholder="$t('user_password')"/>
						<input class="uk-form-controls" type="password" v-model="password2" :placeholder="$t('user_password2')"/>
						<input class="uk-form-controls" type="email" v-model="email" :placeholder="$t('user_email')"/>
						<vk-button class="uk-form-controls" @click="edit">{{ $t('user_edit') }}</vk-button>
					<form id="formNewData">
					</form>
				</vk-card>
			</div>
		</vk-grid>
	</div>
</template>

<script>
import Store from '@/store/index'

export default
{
	name: 'UserProfile',
	data ()
	{
		return {
			oldPassword:'',
			surname:'',
			name:'',
			password:'',
			password2:'',
			email:'',
			errors:[]
		};
	},
	methods:
	{
		async edit()
		{
			await Store.dispatch('EDIT',
			{
				login:
				{
					password: this.oldPassword
				},
				edit:
				{
					name: this.name,
					surname: this.surname,
					password: this.password,
					email: this.email
				}
			});
			this.errors = Store.getters.ERRORS;
			await Store.commit('CLEAR_ERRORS');
		}
	}
}
</script>
