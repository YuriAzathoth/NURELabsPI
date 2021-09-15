<template>
	<div class="uk-section uk-section-muted uk-flex uk-flex-middle uk-animation-fade" uk-height-viewport>
		<div class="uk-width-1-1">
			<div class="uk-container">
				<div class="uk-grid-margin uk-grid uk-grid-stack" uk-grid>
					<div class="uk-width-1-1@m">
						<div class="uk-margin uk-width-large uk-margin-auto uk-card uk-card-default uk-card-body uk-box-shadow-large">
							<h3 class="uk-card-title uk-text-center">{{ $t('user_signup_title') }}</h3>
							<form>
								<div class="uk-margin">
									<div class="uk-inline uk-width-1-1">
										<input class="uk-input uk-form-large" type="text" v-model="name" :placeholder="$t('user_name')" />
									</div>
								</div>
								<div class="uk-margin">
									<div class="uk-inline uk-width-1-1">
										<input class="uk-input uk-form-large" type="text" v-model="surname" :placeholder="$t('user_surname')" />
									</div>
								</div>
								<div class="uk-margin">
									<div class="uk-inline uk-width-1-1">
										<input class="uk-input uk-form-large" type="password" v-model="password" :placeholder="$t('user_password')" />
									</div>
								</div>
								<div class="uk-margin">
									<div class="uk-inline uk-width-1-1">
										<input class="uk-input uk-form-large" type="password" v-model="password2" :placeholder="$t('user_password2')" />
									</div>
								</div>
								<div class="uk-margin">
									<div class="uk-inline uk-width-1-1">
										<input class="uk-input uk-form-large" type="email" v-model="email" :placeholder="$t('user_email')" />
									</div>
								</div>
								<div class="uk-margin">
									<vk-button class="uk-button uk-button-primary uk-button-large uk-width-1-1" @click="signup">{{ $t('user_signup') }}</vk-button>
								</div>
							</form>
						</div>
					</div>
				</div>
			</div>
		</div>
	</div>
</template>

<script>
import Router from '@/router/index'
import Store from '@/store/index'

export default
{
	name: 'SignUp',
	data ()
	{
		return {
			surname:'',
			name:'',
			password:'',
			password2:'',
			email:'',
			role:1,
			roleText:this.$t('user_role_client'),
			errors:[]
		};
	},
	methods:
	{
		setRole(role)
		{
			switch (role)
			{
			case 1:
				this.roleText = this.$t('user_role_client');
				this.role = role;
				break
			case 2:
				this.roleText = this.$t('user_role_employee');
				this.role = role;
				break
			default:
			}
		},
		async signup()
		{
			await Store.dispatch('SIGNUP',
			{
				surname: this.surname,
				name: this.name,
				email: this.email,
				password: this.password,
				role: this.role
			});
			this.errors = Store.getters.ERRORS;
			await Store.commit('CLEAR_ERRORS');
			Router.push('/user');
		}
	}
}
</script>
