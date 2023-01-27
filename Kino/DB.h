#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Data::SQLite;
using namespace System::Collections::Generic;

ref class DB {
private:
	static String^ dbFileName = "kino.db";
	static String^ connectionString = "Data Source=" + dbFileName;
	static SQLiteConnection^ con;

public:
	static void connect() {
		con = gcnew SQLiteConnection(connectionString);
		con->Open();
	}

	static void disconnect() {
		con->Close();
	}

	//static SQLiteDataReader^ getMovieList(DateTime sTime, DateTime eTime) {
	//	String^ query = "SELECT * FROM movies WHERE movies.id IN (SELECT movie_id FROM shows WHERE date BETWEEN @sTime AND @eTime)";
	//	SQLiteCommand^ cmd = gcnew SQLiteCommand(query, con);
	//	cmd->Parameters->AddWithValue("@sTime", sTime);
	//	cmd->Parameters->AddWithValue("@eTime", eTime);
	//	SQLiteDataReader^ reader = cmd->ExecuteReader();
	//	return reader;
	//}

	static DataTable^ getMovieListTable(DateTime sTime, DateTime eTime)
	{
		String^ query = "SELECT * FROM movies WHERE movies.id IN (SELECT movie_id FROM shows WHERE date BETWEEN @sTime AND @eTime)";
		SQLiteCommand^ cmd = gcnew SQLiteCommand(query, con);
		cmd->Parameters->AddWithValue("@sTime", sTime);
		cmd->Parameters->AddWithValue("@eTime", eTime);
		SQLiteDataReader^ reader = cmd->ExecuteReader();
		//while (reader->Read()) {
		//	MessageBox::Show(reader->GetString(1));
		//}
		DataTable^ result = gcnew DataTable;
		result->Clear();
		result->Load(reader);
		reader->Close();
		return result;
	}

	//static SQLiteDataReader^ getMovieData(String^ mId) {
	//	String^ query = "SELECT * FROM movies WHERE movies.id = @mId";
	//	SQLiteCommand^ cmd = gcnew SQLiteCommand(query, con);
	//	cmd->Parameters->AddWithValue("@mId", mId);
	//	SQLiteDataReader^ reader = cmd->ExecuteReader();
	//	return reader;
	//}	
	
	static List<String^>^ getMovieData(String^ mId) {
		String^ query = "SELECT movies.name, movies.description, movies.image FROM movies WHERE movies.id = @mId";
		SQLiteCommand^ cmd = gcnew SQLiteCommand(query, con);
		cmd->Parameters->AddWithValue("@mId", mId);
		SQLiteDataReader^ reader = cmd->ExecuteReader();
		List<String^>^ movies = gcnew List<String^>;
		if (reader->Read()) {
			for (int i = 0; i <= 2; i++) { movies->Add(reader->GetString(i)); }
		}
		reader->Close();
		return movies;
	}

	//static SQLiteDataReader^ getShowsForMovie(String^ mId, DateTime sTime, DateTime eTime) {
	//	String^ query = "SELECT shows.id, shows.date, shows.language, shows.dimension FROM shows WHERE shows.movie_id = @mId AND shows.date BETWEEN @sTime AND @eTime ORDER BY shows.date ASC";
	//	SQLiteCommand^ cmd = gcnew SQLiteCommand(query, con);
	//	cmd->Parameters->AddWithValue("@mId", mId);
	//	cmd->Parameters->AddWithValue("@sTime", sTime);
	//	cmd->Parameters->AddWithValue("@eTime", eTime);
	//	SQLiteDataReader^ reader = cmd->ExecuteReader();
	//	return reader;
	//}

	static DataTable^ getShowsForMovie(String^ mId, DateTime sTime, DateTime eTime) {
		String^ query = "SELECT shows.id, shows.date, shows.language, shows.dimension FROM shows WHERE shows.movie_id = @mId AND shows.date BETWEEN @sTime AND @eTime ORDER BY shows.date ASC";
		SQLiteCommand^ cmd = gcnew SQLiteCommand(query, con);
		cmd->Parameters->AddWithValue("@mId", mId);
		cmd->Parameters->AddWithValue("@sTime", sTime);
		cmd->Parameters->AddWithValue("@eTime", eTime);
		SQLiteDataReader^ reader = cmd->ExecuteReader();
		DataTable^ result = gcnew DataTable;
		result->Clear();
		result->Load(reader);
		reader->Close();
		return result;
	}

	//static SQLiteDataReader^ getShowData(String^ sId) {
	//	String^ query = "SELECT movies.image, movies.name AS 'movie', shows.date, shows.dimension, shows.language, rooms.name AS 'room' FROM shows JOIN movies ON shows.movie_id = movies.id JOIN rooms ON shows.room_id = rooms.id WHERE shows.id = @sId";
	//	SQLiteCommand^ cmd = gcnew SQLiteCommand(query, con);
	//	cmd->Parameters->AddWithValue("@sId", sId);
	//	SQLiteDataReader^ reader = cmd->ExecuteReader();
	//	return reader;
	//}

	static List<String^>^ getShowData(String^ sId) {
		String^ query = "SELECT movies.image, movies.name AS 'movie', shows.date, shows.dimension, shows.language, rooms.name AS 'room' FROM shows JOIN movies ON shows.movie_id = movies.id JOIN rooms ON shows.room_id = rooms.id WHERE shows.id = @sId";
		SQLiteCommand^ cmd = gcnew SQLiteCommand(query, con);
		cmd->Parameters->AddWithValue("@sId", sId);
		SQLiteDataReader^ reader = cmd->ExecuteReader();
		List<String^>^ result = gcnew List<String^>;
		if (reader->Read()) {
			for (int i = 0; i <= 5; i++)
			{
				if (i == 2) { result->Add(reader->GetDateTime(i).ToString("dd.MM.yyyy HH:mm"));
				} else { result->Add(reader->GetString(i)); }
			}
		}
		reader->Close();
		return result;
	}

	//static SQLiteDataReader^ checkSeat(String^ showId, String^ seat) {
	//	String^ query = "SELECT ticketsSeats.seat FROM ticketsSeats JOIN tickets ON ticketsSeats.id = tickets.id JOIN shows ON tickets.show_id = shows.id WHERE shows.id = @showId AND ticketsSeats.seat = @seat";
	//	SQLiteCommand^ cmd = gcnew SQLiteCommand(query, con);
	//	cmd->Parameters->AddWithValue("@showId", showId);
	//	cmd->Parameters->AddWithValue("@seat", seat);
	//	SQLiteDataReader^ reader = cmd->ExecuteReader();
	//	return reader;
	//}

	static bool checkSeat(String^ showId, String^ seat) {
		String^ query = "SELECT ticketsSeats.seat FROM ticketsSeats JOIN tickets ON ticketsSeats.id = tickets.id JOIN shows ON tickets.show_id = shows.id WHERE shows.id = @showId AND ticketsSeats.seat = @seat";
		SQLiteCommand^ cmd = gcnew SQLiteCommand(query, con);
		cmd->Parameters->AddWithValue("@showId", showId);
		cmd->Parameters->AddWithValue("@seat", seat);
		SQLiteDataReader^ reader = cmd->ExecuteReader();
		if (reader->Read()) {
			reader->Close();
			return false;
		}
		reader->Close();
		return true;
	}

	//static SQLiteDataReader^ getUserIdByLogin(String^ login) {
	//	String^ query = "SELECT id FROM accounts WHERE accounts.login = @login";
	//	SQLiteCommand^ cmd = gcnew SQLiteCommand(query, con);
	//	cmd->Parameters->AddWithValue("@login", login);
	//	SQLiteDataReader^ reader = cmd->ExecuteReader();
	//	return reader;
	//}

	static int getUserIdByLogin(String^ login) {
		String^ query = "SELECT id FROM accounts WHERE accounts.login = @login";
		SQLiteCommand^ cmd = gcnew SQLiteCommand(query, con);
		cmd->Parameters->AddWithValue("@login", login);
		SQLiteDataReader^ reader = cmd->ExecuteReader();
		int result = 0;
		if (reader->Read()) {
			result = reader->GetInt32(0);
			reader->Close();
			return result;
		}
		reader->Close();
		return -1;
	}

	static int saveTickets(int userId, String^ showId, String^ ticketCode) {
		String^ query = "INSERT INTO tickets (account_id, show_id, code) VALUES (@userId, @showId, @code) RETURNING id";
		SQLiteCommand^ cmd = gcnew SQLiteCommand(query, con);
		cmd->Parameters->AddWithValue("@userId", userId);
		cmd->Parameters->AddWithValue("@showId", showId);
		cmd->Parameters->AddWithValue("@code", ticketCode);
		SQLiteDataReader^ reader = cmd->ExecuteReader();
		reader->Read();
		int id = reader->GetInt32(0);
		reader->Close();
		return id;
	}

	static void saveTicketsSeat(int ticketId, String^ seat) {
		String^ query = "INSERT INTO ticketsSeats (id, seat) VALUES (@ticketId, @seat)";
		SQLiteCommand^ cmd = gcnew SQLiteCommand(query, con);
		cmd->Parameters->AddWithValue("@ticketId", ticketId);
		cmd->Parameters->AddWithValue("@seat", seat);
		SQLiteDataReader^ reader = cmd->ExecuteReader();
		reader->Close();
	}

	static int addLoginToDb(String^ login) {
		String^ query = "INSERT INTO accounts (login, password, permissions, isOpen) VALUES (@login, '', 0, 'n') RETURNING id";
		SQLiteCommand^ cmd = gcnew SQLiteCommand(query, con);
		cmd->Parameters->AddWithValue("@login", login);
		SQLiteDataReader^ reader = cmd->ExecuteReader();
		reader->Read();
		int id = reader->GetInt32(0);
		reader->Close();
		return id;
	}

	static int checkUserCredentials(String^ login, String^ passsword) {
		String^ query = "SELECT accounts.id FROM accounts WHERE accounts.login=@l AND accounts.password=@p AND accounts.isOpen = 'y'";
		SQLiteCommand^ cmd = gcnew SQLiteCommand(query, con);
		cmd->Parameters->AddWithValue("@l", login);
		cmd->Parameters->AddWithValue("@p", passsword);
		SQLiteDataReader^ reader = cmd->ExecuteReader();
		int userId = -1;
		if (reader->Read()) {
			userId = reader->GetInt32(0);
			reader->Close();
		}
		reader->Close();
		return userId;
	}

	static List<String^>^ getUserData(int userId) {
		String^ query = "SELECT accounts.id, accounts.login, accounts.permissions FROM accounts WHERE accounts.id=@id";
		SQLiteCommand^ cmd = gcnew SQLiteCommand(query, con);
		cmd->Parameters->AddWithValue("@id", userId);
		SQLiteDataReader^ reader = cmd->ExecuteReader();
		List<String^>^ userData = gcnew List<String^>;
		if (reader->Read()) {
			userData->Add(reader->GetInt32(0).ToString());
			userData->Add(reader->GetString(1));
			userData->Add(reader->GetInt32(2).ToString());
		}
		return userData;
	}
};