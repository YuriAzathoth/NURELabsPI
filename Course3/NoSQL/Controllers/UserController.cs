using System.Collections.Generic;
using System.Linq;
using System.Security.Claims;
using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Mvc;
using NoSQLLab.Auth;
using NoSQLLab.Extensions;
using NoSQLLab.Model;
using NoSQLLab.Repositories;

namespace NoSQLLab.Controllers
{
	[ApiController]
	[Route("api/[controller]")]
	public class UserController : Controller
	{
		private readonly UserRepository userRepository;

		public UserController(UserRepository userRepository)
		{
			this.userRepository = userRepository;
		}

		[HttpPost]
		[Route("register")]
		public IActionResult Register(UserApiModel model)
		{
			var existing = userRepository.GetByUsername(model.Username);
			if (existing != null)
				return BadRequest(new { Error = "User already exist" });

			var dbUser = userRepository.Insert(new User()
			{
				UserName = model.Username,
				Password = model.Password
			});

			return Ok(new UserResponseModel { Id = dbUser.Id, Username = dbUser.UserName });
		}

		[HttpGet]
		[Route("getAll")]
		public IActionResult GetAll()
		{
			var users = userRepository.GetAll().Select(x => new UserResponseModel
			{
				Id = x.Id,
				Username = x.UserName
			});
			return Ok(users);
		}

		[HttpPost]
		[Route("login")]
		public IActionResult Login([FromBody] UserApiModel model)
		{
			var user = userRepository.GetByUsernameAndPassword(model.Username, model.Password);
			if (user == null)
				return BadRequest(new { Error = "User not exists" });

			var identity = GetIdentity(user.UserName, "User");
			var token = JWTTokenizer.GetEncodedJWT(identity, AuthOptions.Lifetime);

			return new JsonResult(new { JWT = token });
		}

		[HttpPut]
		[Route("changePassword")]
		public IActionResult Login([FromBody] UserChangePasswordApipModel model)
		{
			var user = userRepository.GetByUsernameAndPassword(model.Username, model.OldPassword);
			if (user == null)
				return BadRequest(new { Error = "Invalid password" });

			userRepository.ChangePassword(model.Username, model.OldPassword, model.NewPassword);
			
			return Ok(user);
		}

		private ClaimsIdentity GetIdentity(string login, string role)
		{
			var claims = new List<Claim>
			{
				new Claim(ClaimsIdentity.DefaultNameClaimType, login),
				new Claim(ClaimsIdentity.DefaultRoleClaimType, role)
			};

			ClaimsIdentity claimsIdentity = new ClaimsIdentity(claims, "Token", ClaimsIdentity.DefaultNameClaimType, ClaimsIdentity.DefaultRoleClaimType);
			return claimsIdentity;
		}
	}
}
