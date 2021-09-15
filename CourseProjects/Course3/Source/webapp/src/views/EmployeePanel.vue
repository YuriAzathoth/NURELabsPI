<template>
	<div>
		<vk-grid class="uk-child-width-auto@m" gutter="small" divided matched>
			<div>
				<vk-card padding=large class="uk-width-auto@m">
					<vk-nav>
						<vk-nav-item-header :title="$t('user_panel')"></vk-nav-item-header>
						<li><router-link to="/employee/tasks">{{ $t('tasks') }}</router-link></li>
						<li><router-link to="/employee/profile">{{ $t('profile') }}</router-link></li>
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
export default
{
	name: 'EmployeePanel'
}
</script>
