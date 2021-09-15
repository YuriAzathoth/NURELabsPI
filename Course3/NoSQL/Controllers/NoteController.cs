using System.Collections.Generic;
using System.Linq;
using System.Security.Claims;
using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Mvc;
using NoSQLLab.Auth;
using NoSQLLab.Extensions;
using NoSQLLab.Model;
using NoSQLLab.Repositories;
using System;

namespace NoSQLLab.Repositories
{
	[ApiController]
	[Route("api/[controller]")]
	public class NoteController : Controller
	{
		private readonly NoteRepository noteRepository;

		public NoteController(NoteRepository noteRepository)
		{
			this.noteRepository = noteRepository;
		}

		[HttpPut]
		[Route("add")]
		public IActionResult Insert(NoteApiModel model)
		{
			var dbNote = noteRepository.Insert(new Note()
			{
				Title = model.Title,
				Text = model.Text
			});
			return Ok(dbNote);
		}

		[HttpPut]
		[Route("edit")]
		public IActionResult Edit([FromBody] NoteEditApiModel model)
		{
			noteRepository.Edit(new Note()
			{
				Id = model.Id,
				Title = model.Title,
				Text = model.Text
			});
			return Ok("SUCCESS!");
		}

		[HttpGet]
		[Route("search")]
		public IActionResult Search([FromBody] SearchApiModel model)
		{
			var note = noteRepository.Search(model.Query);
			return Ok(note);
		}

		[HttpDelete]
		[Route("delete")]
		public IActionResult Delete([FromBody] IdApiModel model)
		{
			noteRepository.Delete(model.Id);
			return Ok("SUCCESS!");
		}

		[HttpGet]
		[Route("get")]
		public IActionResult GetById([FromBody] IdApiModel model)
		{
			var note = noteRepository.GetById(model.Id);
			return Ok(note);
		}

		[HttpGet]
		[Route("getAll")]
		public IActionResult GetAll()
		{
			var notes = noteRepository.GetAll().Select(x => new Note
			{
				Id = x.Id,
				Title = x.Title,
				Text = x.Text,
				UserId = x.UserId,
				LastUpdate = x.LastUpdate
			});
			return Ok(notes);
		}

		[HttpDelete]
		[Route("deleteAll")]
		public IActionResult DeleteAll()
		{
			noteRepository.DeleteAll();
			return Ok("SUCCESS!");
		}
	}
}
