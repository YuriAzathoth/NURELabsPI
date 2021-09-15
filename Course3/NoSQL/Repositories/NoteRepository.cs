using Microsoft.Extensions.Configuration;
using MongoDB.Driver;
using NoSQLLab.Model;
using System;
using System.Collections.Generic;
using System.Linq;

namespace NoSQLLab.Repositories
{
	public class NoteRepository
	{
		private readonly IMongoCollection<Note> collection;

		public NoteRepository(IConfiguration configuration)
		{
			var connString = configuration.GetConnectionString("MongoDBConnection");
			collection = new MongoClient(connString).GetDatabase("notes_db").GetCollection<Note>("notes");
		}

		public Note Insert(Note note)
		{
			note.Id = Guid.NewGuid();
			collection.InsertOne(note);
			return note;
		}

		public Note Edit(Note note)
		{
			collection.ReplaceOne(x => x.Id == note.Id, note);
			return note;
		}

		public IReadOnlyCollection<Note> GetAll()
		{
			return collection.Find(x => true).ToList();
		}

		public Note GetById(Guid id)
		{
			return collection.Find(x => x.Id == id).FirstOrDefault();
		}

		public Note Search(string title)
		{
			return collection.Find(x => x.Title == title).FirstOrDefault();
		}

		public IReadOnlyCollection<Note> GetByUserId(Guid userId)
		{
			return collection.Find(x => x.UserId == userId).ToList();
		}

		public void Delete(Guid noteId)
		{
			collection.DeleteOne((x) => x.Id == noteId);
		}

		public void DeleteAll()
		{
			collection.DeleteMany(x => true);
		}

		public async void CreateIndexes()
		{
			await collection.Indexes.CreateOneAsync(new CreateIndexModel<Note>(Builders<Note>.IndexKeys.Ascending(_ => _.Id))).ConfigureAwait(false);
			await collection.Indexes.CreateOneAsync(new CreateIndexModel<Note>(Builders<Note>.IndexKeys.Ascending(_ => _.UserId))).ConfigureAwait(false);
		}
	}
}
