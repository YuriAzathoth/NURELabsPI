<template>
	<div class="uk-section uk-section-muted uk-flex uk-flex-middle uk-animation-fade" uk-height-viewport>
		<div class="uk-width-1-1">
			<div class="uk-container">
				<div class="uk-grid-margin uk-grid uk-grid-stack" uk-grid>
					<div class="uk-width-1-1@m">
						<div class="uk-margin uk-width-large uk-margin-auto uk-card uk-card-default uk-card-body uk-box-shadow-large">
							<h3 class="uk-card-title uk-text-center">{{ $t('user_login_title') }}</h3>
							<form>
								<div class="uk-margin">
									<div class="uk-inline uk-width-1-1">
										<span class="uk-form-icon" uk-icon="icon: mail" />
										<input class="uk-input uk-form-large" type="email" v-model="email" :placeholder="$t('user_email')" />
									</div>
								</div>
								<div class="uk-margin">
									<div class="uk-inline uk-width-1-1">
										<span class="uk-form-icon" uk-icon="icon: lock" />
										<input class="uk-input uk-form-large" type="password" v-model="password" :placeholder="$t('user_password')" />
									</div>
								</div>
								<div class="uk-margin">
									<vk-button class="uk-button uk-button-primary uk-button-large uk-width-1-1" @click="login">{{ $t('user_login') }}</vk-button>
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
	name: 'LogIn',
	data ()
	{
		return {
			email:'',
			password:'',
			errors:[]
		};
	},
	methods:
	{
		async login()
		{
			await Store.dispatch('LOGIN',
			{
				email: this.email,
				password: this.password
			});
			this.errors = Store.getters.ERRORS;
			await Store.commit('CLEAR_ERRORS');
			Router.push('/user');
		}
	}
}
</script>
