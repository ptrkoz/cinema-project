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

	//dodaje login bez tworzenia konta
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

	static int addUser(String^ login, String^ password) {
		String^ query = "INSERT INTO accounts (login, password, permissions, isOpen) VALUES (@login,@password, 0, 'y') RETURNING id";
		SQLiteCommand^ cmd = gcnew SQLiteCommand(query, con);
		cmd->Parameters->AddWithValue("@login", login);
		cmd->Parameters->AddWithValue("@password", password);
		SQLiteDataReader^ reader = cmd->ExecuteReader();
		int resultId = -1;
		if (reader->Read()) {
			resultId = reader->GetInt32(0);
		}
		return resultId;
	}

	static DataTable^ getMyTicketsList(int userId) {
		String^ query = "SELECT movies.image, movies.name, shows.date, tickets.id, COUNT(ticketsSeats.id) FROM tickets JOIN shows ON tickets.show_id = shows.id JOIN movies ON shows.movie_id = movies.id JOIN ticketsSeats ON tickets.id = ticketsSeats.id WHERE account_id = @userId GROUP BY ticketsSeats.id ORDER BY shows.date DESC";
		SQLiteCommand^ cmd = gcnew SQLiteCommand(query, con);
		cmd->Parameters->AddWithValue("@userId", userId);
		SQLiteDataReader^ reader = cmd->ExecuteReader();
		DataTable^ myTickets = gcnew DataTable;
		myTickets->Clear();
		myTickets->Load(reader);
		reader->Close();
		return myTickets;
	}

	static void returnTicket(int ticketId) {
		String^ query = "DELETE FROM tickets WHERE tickets.id = @ticketId";
		SQLiteCommand^ cmd = gcnew SQLiteCommand(query, con);
		cmd->Parameters->AddWithValue("@ticketId", ticketId);
		SQLiteDataReader^ reader = cmd->ExecuteReader();
		reader->Close();

		String^ query2 = "DELETE FROM ticketsSeats WHERE ticketsSeats.id = @ticketId";
		SQLiteCommand^ cmd2 = gcnew SQLiteCommand(query2, con);
		cmd2->Parameters->AddWithValue("@ticketId", ticketId);
		SQLiteDataReader^ reader2 = cmd2->ExecuteReader();
		reader2->Close();
	}

	static List<String^>^ getTicketData(int ticketId) {
		String^ query = "SELECT movies.image, movies.name, shows.date, shows.dimension, shows.language, rooms.name, tickets.code FROM tickets JOIN shows ON tickets.show_id = shows.id JOIN rooms ON shows.room_id = rooms.id JOIN movies ON shows.movie_id = movies.id WHERE tickets.id = @ticketId";
		SQLiteCommand^ cmd = gcnew SQLiteCommand(query, con);
		cmd->Parameters->AddWithValue("@ticketId", ticketId);
		SQLiteDataReader^ reader = cmd->ExecuteReader();
		List<String^>^ ticketData = gcnew List<String^>;
		if (reader->Read()) {
			ticketData->Add(reader->GetString(0));
			ticketData->Add(reader->GetString(1));
			ticketData->Add(reader->GetDateTime(2).ToString("dd.MM.yyyy HH:mm"));
			String^ lang = reader->GetString(4);
			if (lang == "sub") {
				lang = "napisy";
			} else if (lang == "dub") {
				lang = "dubbing";
			}
			String^ showVersion = reader->GetString(3) + ", " + lang;
			ticketData->Add(showVersion);
			ticketData->Add(reader->GetString(5));
			ticketData->Add(reader->GetString(6));
		}
		return ticketData;
	}

	static List<String^>^ getTicketSeats(int ticketId) {
		String^ query = "SELECT ticketsSeats.seat FROM ticketsSeats WHERE ticketsSeats.id = @ticketId";
		SQLiteCommand^ cmd = gcnew SQLiteCommand(query, con);
		cmd->Parameters->AddWithValue("@ticketId", ticketId);
		SQLiteDataReader^ reader = cmd->ExecuteReader();
		List<String^>^ ticketSeats = gcnew List<String^>;
		while (reader->Read()) {
			ticketSeats->Add(reader["seat"]->ToString());
		}
		return ticketSeats;
	}

	static DataTable^ getMovies() {
		String^ query = "SELECT movies.id, movies.name, movies.image FROM movies ORDER BY movies.id DESC";
		SQLiteCommand^ cmd = gcnew SQLiteCommand(query, con);
		SQLiteDataReader^ reader = cmd->ExecuteReader();
		DataTable^ result = gcnew DataTable;
		result->Clear();
		result->Load(reader);
		reader->Close();
		return result;
	}

	static DataTable^ getRooms() {
		String^ query = "SELECT rooms.id, rooms.name FROM rooms WHERE rooms.isActive = 'y'";
		SQLiteCommand^ cmd = gcnew SQLiteCommand(query, con);
		SQLiteDataReader^ reader = cmd->ExecuteReader();
		DataTable^ result = gcnew DataTable;
		result->Clear();
		result->Load(reader);
		reader->Close();
		return result;
	}

	static bool isShowOfTheMovie(int movieId) {
		String^ query = "SELECT shows.movie_id FROM shows WHERE shows.movie_id = @movieId";
		SQLiteCommand^ cmd = gcnew SQLiteCommand(query, con);
		cmd->Parameters->AddWithValue("@movieId", movieId);
		SQLiteDataReader^ reader = cmd->ExecuteReader();
		if (reader->Read()) {
			reader->Close();
			return true;
		}
		reader->Close();
		return false;
	}

	static void deleteMovie(int movieId) {
		String^ query = "DELETE FROM movies WHERE movies.id = @movieId";
		SQLiteCommand^ cmd = gcnew SQLiteCommand(query, con);
		cmd->Parameters->AddWithValue("@movieId", movieId);
		SQLiteDataReader^ reader = cmd->ExecuteReader();
		reader->Close();
	}

	static void updateMovie(int movieId, String^ movieName, String^ movieDesc, String^ posterFileName) {
		String^ query = "UPDATE movies SET name = @movieName, description = @movieDesc, image = @posterFileName WHERE id = @movieId";
		SQLiteCommand^ cmd = gcnew SQLiteCommand(query, con);
		cmd->Parameters->AddWithValue("@movieId", movieId);
		cmd->Parameters->AddWithValue("@movieName", movieName);
		cmd->Parameters->AddWithValue("@movieDesc", movieDesc);
		cmd->Parameters->AddWithValue("@posterFileName", posterFileName);
		SQLiteDataReader^ reader = cmd->ExecuteReader();
		reader->Close();
	}

	static void addMovie(String^ movieName, String^ movieDesc, String^ posterFileName) {
		String^ query = "INSERT INTO movies (name, description, image) VALUES (@movieName, @movieDesc, @posterFileName)";
		SQLiteCommand^ cmd = gcnew SQLiteCommand(query, con);
		cmd->Parameters->AddWithValue("@movieName", movieName);
		cmd->Parameters->AddWithValue("@movieDesc", movieDesc);
		cmd->Parameters->AddWithValue("@posterFileName", posterFileName);
		SQLiteDataReader^ reader = cmd->ExecuteReader();
		reader->Close();
	}

	static DataTable^ getShows() {
		String^ query = "SELECT shows.id, movies.name, movies.image, rooms.name, shows.date, shows.language, shows.dimension FROM shows JOIN movies ON shows.movie_id = movies.id JOIN rooms ON shows.room_id = rooms.id ORDER BY shows.date DESC";
		SQLiteCommand^ cmd = gcnew SQLiteCommand(query, con);
		SQLiteDataReader^ reader = cmd->ExecuteReader();
		DataTable^ result = gcnew DataTable;
		result->Clear();
		result->Load(reader);
		reader->Close();
		return result;
	}

	static bool areTicketsSoldForShow(int showId) {
		String^ query = "SELECT tickets.show_id FROM tickets WHERE show_id = @showId";
		SQLiteCommand^ cmd = gcnew SQLiteCommand(query, con);
		cmd->Parameters->AddWithValue("@showId", showId);
		SQLiteDataReader^ reader = cmd->ExecuteReader();
		if (reader->Read()) {
			reader->Close();
			return true;
		}
		reader->Close();
		return false;
	}

	static void deleteShow(int showId) {
		String^ query = "DELETE FROM shows WHERE shows.id = @showId";
		SQLiteCommand^ cmd = gcnew SQLiteCommand(query, con);
		cmd->Parameters->AddWithValue("@showId", showId);
		SQLiteDataReader^ reader = cmd->ExecuteReader();
		reader->Close();
	}

	static List<String^>^ getShowDataForEdit(int showId) {
		String^ query = "SELECT shows.movie_id, shows.room_id, shows.date, shows.language, shows.dimension FROM shows WHERE shows.id = @showId";
		SQLiteCommand^ cmd = gcnew SQLiteCommand(query, con);
		cmd->Parameters->AddWithValue("@showId", showId);
		SQLiteDataReader^ reader = cmd->ExecuteReader();
		List<String^>^ result = gcnew List<String^>;
		if (reader->Read()) {
			result->Add(reader->GetInt32(0).ToString());
			result->Add(reader->GetInt32(1).ToString());
			result->Add(reader->GetDateTime(2).ToString("dd.MM.yyyy HH:mm"));
			result->Add(reader->GetString(3));
			result->Add(reader->GetString(4));
		}
		reader->Close();
		return result;
	}

	static void addShow(int movieId, int roomId, String^ showDate, String^ showLang, String^ showDim) {
		String^ query = "INSERT INTO shows (movie_id, room_id, date, language, dimension) VALUES (@movieId, @roomId, @showDate, @showLang, @showDim)";
		SQLiteCommand^ cmd = gcnew SQLiteCommand(query, con);
		cmd->Parameters->AddWithValue("@movieId", movieId);
		cmd->Parameters->AddWithValue("@roomId", roomId);
		cmd->Parameters->AddWithValue("@showDate", showDate);
		cmd->Parameters->AddWithValue("@showLang", showLang);
		cmd->Parameters->AddWithValue("@showDim", showDim);
		SQLiteDataReader^ reader = cmd->ExecuteReader();
		reader->Close();
	}

	static void updateShow(int showId, int movieId, int roomId, String^ showDate, String^ showLang, String^ showDim) {
		String^ query = "UPDATE shows SET movie_id = @movieId, room_id = @roomId, date = @showDate, language = @showLang, dimension = @showDim WHERE id = @showId";
		SQLiteCommand^ cmd = gcnew SQLiteCommand(query, con);
		cmd->Parameters->AddWithValue("@showId", showId);
		cmd->Parameters->AddWithValue("@movieId", movieId);
		cmd->Parameters->AddWithValue("@roomId", roomId);
		cmd->Parameters->AddWithValue("@showDate", showDate);
		cmd->Parameters->AddWithValue("@showLang", showLang);
		cmd->Parameters->AddWithValue("@showDim", showDim);
		SQLiteDataReader^ reader = cmd->ExecuteReader();
		reader->Close();
	}

	static String^ getRoomName(int roomId) {
		String^ query = "SELECT rooms.name FROM rooms WHERE rooms.id = @roomId";
		SQLiteCommand^ cmd = gcnew SQLiteCommand(query, con);
		cmd->Parameters->AddWithValue("@roomId", roomId);
		SQLiteDataReader^ reader = cmd->ExecuteReader();
		String^ result = "";
		if (reader->Read()) {
			result = reader->GetString(0);
		}
		reader->Close();
		return result;
	}

	static void addRoom(String^ roomName) {
		String^ query = "INSERT INTO rooms (name, width, height, isActive) VALUES (@roomName, 1, 1, 'y')";
		SQLiteCommand^ cmd = gcnew SQLiteCommand(query, con);
		cmd->Parameters->AddWithValue("@roomName", roomName);
		SQLiteDataReader^ reader = cmd->ExecuteReader();
		reader->Close();
	}

	static void editRoom(int roomId, String^ roomName) {
		String^ query = "UPDATE rooms SET name = @roomName WHERE id = @roomId";
		SQLiteCommand^ cmd = gcnew SQLiteCommand(query, con);
		cmd->Parameters->AddWithValue("@roomId", roomId);
		cmd->Parameters->AddWithValue("@roomName", roomName);
		SQLiteDataReader^ reader = cmd->ExecuteReader();
		reader->Close();
	}

	static void deleteRoom(int roomId) {
		String^ query = "UPDATE rooms SET isActive = 'n' WHERE id = @roomId";
		SQLiteCommand^ cmd = gcnew SQLiteCommand(query, con);
		cmd->Parameters->AddWithValue("@roomId", roomId);
		SQLiteDataReader^ reader = cmd->ExecuteReader();
		reader->Close();
	}

	static bool willBeAShowInRoom(int roomId) {
		DateTime now = DateTime::Now;
		String^ query = "SELECT shows.date FROM shows WHERE shows.room_id = @roomId";
		SQLiteCommand^ cmd = gcnew SQLiteCommand(query, con);
		cmd->Parameters->AddWithValue("@roomId", roomId);
		SQLiteDataReader^ reader = cmd->ExecuteReader();
		while (reader->Read()) {
			DateTime showDate = reader->GetDateTime(0);
			if (DateTime::Compare(now, showDate) < 0) {
				return true;
			}
		}
		return false;
	}
};