using Microsoft.AspNetCore.Authentication.JwtBearer;
using Microsoft.AspNetCore.Builder;
using Microsoft.AspNetCore.Hosting;
using Microsoft.AspNetCore.HttpsPolicy;
using Microsoft.AspNetCore.Mvc;
using Microsoft.Extensions.Configuration;
using Microsoft.Extensions.DependencyInjection;
using Microsoft.Extensions.Hosting;
using Microsoft.Extensions.Logging;
using Microsoft.IdentityModel.Tokens;
using NoSQLLab.Auth;
using NoSQLLab.Repositories;

namespace NoSQLLab
{
	public class Startup
	{
		public Startup(IConfiguration configuration)
		{
			Configuration = configuration;
		}

		public IConfiguration Configuration { get; }

		public void ConfigureServices(IServiceCollection services)
		{
			services.AddControllers();
			services.AddScoped<UserRepository>();
			services.AddScoped<NoteRepository>();
			services.AddAuthentication(JwtBearerDefaults.AuthenticationScheme).AddJwtBearer(options =>
			{
				options.RequireHttpsMetadata = false;
				options.TokenValidationParameters = new
				TokenValidationParameters
				{
					ValidateIssuer = true,
					ValidIssuer = AuthOptions.Issuer,
					ValidateAudience = true,
					ValidAudience = AuthOptions.Audience,
					ValidateLifetime = true,
					IssuerSigningKey = AuthOptions.GetSymmetricSecurityKey(),
					ValidateIssuerSigningKey = true
				};
			});
			services.BuildServiceProvider().GetRequiredService<UserRepository>().CreateIndexes();
			services.BuildServiceProvider().GetRequiredService<NoteRepository>().CreateIndexes();
		}

		public void Configure(IApplicationBuilder app, IWebHostEnvironment env)
		{
			if (env.IsDevelopment())
			{
				app.UseDeveloperExceptionPage();
			}
			else
			{
				app.UseHsts();
			}
			app.UseHttpsRedirection();
            app.UseRouting();
            app.UseAuthorization();
            app.UseEndpoints(endpoints =>
            {
                endpoints.MapControllers();
            });
		}
	}
}
