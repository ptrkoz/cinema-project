#pragma once
#include <math.h>
#include "DB.h"
#include "User.h"
#include "PickShow.h"

namespace Kino {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SQLite;
	//using namespace System::Data::SqlClient;
	//using namespace System::Data::Odbc;

	/// <summary>
	/// Podsumowanie informacji o PickDateForm
	/// </summary>
	public ref class PickDateForm : public System::Windows::Forms::Form
	{
	public:
		PickDateForm(void)
		{
			InitializeComponent();
		}

		PickDateForm(Form^ prevForm)
		{
			InitializeComponent();
			this->prevForm = prevForm;
		}

		PickDateForm(Form^ prevForm, User^ user)
		{
			InitializeComponent();
			this->prevForm = prevForm;
			this->user = user;
		}

	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~PickDateForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: Form^ prevForm;
	private: User^ user = nullptr;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker1;
	private: System::Windows::Forms::Button^ nextDayBtn;
	private: System::Windows::Forms::Button^ prevDayBtn;
	

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ prevMoviesBtn;
	private: System::Windows::Forms::Button^ nextMoviesBtn;
	private: System::Windows::Forms::Label^ MovieID1;
	private: System::Windows::Forms::Label^ MovieID2;
	private: System::Windows::Forms::Label^ MovieID3;
	private: System::Windows::Forms::Label^ noShowsLabel;
	private: System::Windows::Forms::Button^ goBackBtn;



	protected:

	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metoda wymagana do obs³ugi projektanta — nie nale¿y modyfikowaæ
		/// jej zawartoœci w edytorze kodu.
		/// </summary>
		void InitializeComponent(void)
		{
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->nextDayBtn = (gcnew System::Windows::Forms::Button());
			this->prevDayBtn = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->prevMoviesBtn = (gcnew System::Windows::Forms::Button());
			this->nextMoviesBtn = (gcnew System::Windows::Forms::Button());
			this->MovieID1 = (gcnew System::Windows::Forms::Label());
			this->MovieID2 = (gcnew System::Windows::Forms::Label());
			this->MovieID3 = (gcnew System::Windows::Forms::Label());
			this->noShowsLabel = (gcnew System::Windows::Forms::Label());
			this->goBackBtn = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			this->SuspendLayout();
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Location = System::Drawing::Point(202, 28);
			this->dateTimePicker1->MaxDate = System::DateTime(2100, 12, 31, 0, 0, 0, 0);
			this->dateTimePicker1->MinDate = System::DateTime(2000, 1, 1, 0, 0, 0, 0);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(200, 20);
			this->dateTimePicker1->TabIndex = 0;
			this->dateTimePicker1->ValueChanged += gcnew System::EventHandler(this, &PickDateForm::dateTimePicker1_ValueChanged);
			// 
			// nextDayBtn
			// 
			this->nextDayBtn->Location = System::Drawing::Point(411, 26);
			this->nextDayBtn->Name = L"nextDayBtn";
			this->nextDayBtn->Size = System::Drawing::Size(28, 23);
			this->nextDayBtn->TabIndex = 1;
			this->nextDayBtn->Text = L">";
			this->nextDayBtn->UseVisualStyleBackColor = true;
			this->nextDayBtn->Click += gcnew System::EventHandler(this, &PickDateForm::nextDayBtn_Click);
			// 
			// prevDayBtn
			// 
			this->prevDayBtn->Location = System::Drawing::Point(170, 26);
			this->prevDayBtn->Name = L"prevDayBtn";
			this->prevDayBtn->Size = System::Drawing::Size(26, 23);
			this->prevDayBtn->TabIndex = 2;
			this->prevDayBtn->Text = L"<";
			this->prevDayBtn->UseVisualStyleBackColor = true;
			this->prevDayBtn->Click += gcnew System::EventHandler(this, &PickDateForm::prevDayBtn_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->label1->Location = System::Drawing::Point(59, 291);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"label1";
			this->label1->Click += gcnew System::EventHandler(this, &PickDateForm::label1_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox1->Location = System::Drawing::Point(62, 73);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(140, 212);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 4;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &PickDateForm::pictureBox1_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox2->Location = System::Drawing::Point(243, 73);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(140, 212);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 5;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Click += gcnew System::EventHandler(this, &PickDateForm::pictureBox2_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->label2->Location = System::Drawing::Point(240, 291);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(35, 13);
			this->label2->TabIndex = 6;
			this->label2->Text = L"label2";
			this->label2->Click += gcnew System::EventHandler(this, &PickDateForm::label2_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(535, 2);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 62;
			this->dataGridView1->Size = System::Drawing::Size(90, 82);
			this->dataGridView1->TabIndex = 7;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &PickDateForm::dataGridView1_CellContentClick);
			// 
			// pictureBox3
			// 
			this->pictureBox3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox3->Location = System::Drawing::Point(428, 73);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(140, 212);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox3->TabIndex = 8;
			this->pictureBox3->TabStop = false;
			this->pictureBox3->Click += gcnew System::EventHandler(this, &PickDateForm::pictureBox3_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->label3->Location = System::Drawing::Point(425, 291);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(35, 13);
			this->label3->TabIndex = 9;
			this->label3->Text = L"label3";
			this->label3->Click += gcnew System::EventHandler(this, &PickDateForm::label3_Click);
			// 
			// prevMoviesBtn
			// 
			this->prevMoviesBtn->Location = System::Drawing::Point(12, 175);
			this->prevMoviesBtn->Name = L"prevMoviesBtn";
			this->prevMoviesBtn->Size = System::Drawing::Size(33, 23);
			this->prevMoviesBtn->TabIndex = 10;
			this->prevMoviesBtn->Text = L"<-";
			this->prevMoviesBtn->UseVisualStyleBackColor = true;
			this->prevMoviesBtn->Click += gcnew System::EventHandler(this, &PickDateForm::prevMoviesBtn_Click);
			// 
			// nextMoviesBtn
			// 
			this->nextMoviesBtn->Location = System::Drawing::Point(574, 175);
			this->nextMoviesBtn->Name = L"nextMoviesBtn";
			this->nextMoviesBtn->Size = System::Drawing::Size(33, 23);
			this->nextMoviesBtn->TabIndex = 11;
			this->nextMoviesBtn->Text = L"->";
			this->nextMoviesBtn->UseVisualStyleBackColor = true;
			this->nextMoviesBtn->Click += gcnew System::EventHandler(this, &PickDateForm::nextMoviesBtn_Click);
			// 
			// MovieID1
			// 
			this->MovieID1->AutoSize = true;
			this->MovieID1->Location = System::Drawing::Point(96, 330);
			this->MovieID1->Name = L"MovieID1";
			this->MovieID1->Size = System::Drawing::Size(53, 13);
			this->MovieID1->TabIndex = 12;
			this->MovieID1->Text = L"MovieID1";
			this->MovieID1->Visible = false;
			// 
			// MovieID2
			// 
			this->MovieID2->AutoSize = true;
			this->MovieID2->Location = System::Drawing::Point(283, 330);
			this->MovieID2->Name = L"MovieID2";
			this->MovieID2->Size = System::Drawing::Size(53, 13);
			this->MovieID2->TabIndex = 13;
			this->MovieID2->Text = L"MovieID2";
			this->MovieID2->Visible = false;
			// 
			// MovieID3
			// 
			this->MovieID3->AutoSize = true;
			this->MovieID3->Location = System::Drawing::Point(475, 330);
			this->MovieID3->Name = L"MovieID3";
			this->MovieID3->Size = System::Drawing::Size(53, 13);
			this->MovieID3->TabIndex = 14;
			this->MovieID3->Text = L"MovieID3";
			this->MovieID3->Visible = false;
			// 
			// noShowsLabel
			// 
			this->noShowsLabel->AutoSize = true;
			this->noShowsLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->noShowsLabel->Location = System::Drawing::Point(57, 166);
			this->noShowsLabel->Name = L"noShowsLabel";
			this->noShowsLabel->Size = System::Drawing::Size(512, 39);
			this->noShowsLabel->TabIndex = 15;
			this->noShowsLabel->Text = L"Brak seansów w wybranym dniu";
			// 
			// goBackBtn
			// 
			this->goBackBtn->Location = System::Drawing::Point(12, 12);
			this->goBackBtn->Name = L"goBackBtn";
			this->goBackBtn->Size = System::Drawing::Size(75, 23);
			this->goBackBtn->TabIndex = 16;
			this->goBackBtn->Text = L"<- powrót";
			this->goBackBtn->UseVisualStyleBackColor = true;
			this->goBackBtn->Click += gcnew System::EventHandler(this, &PickDateForm::goBackBtn_Click);
			// 
			// PickDateForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(628, 364);
			this->Controls->Add(this->goBackBtn);
			this->Controls->Add(this->noShowsLabel);
			this->Controls->Add(this->MovieID3);
			this->Controls->Add(this->MovieID2);
			this->Controls->Add(this->MovieID1);
			this->Controls->Add(this->nextMoviesBtn);
			this->Controls->Add(this->prevMoviesBtn);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->prevDayBtn);
			this->Controls->Add(this->nextDayBtn);
			this->Controls->Add(this->dateTimePicker1);
			this->Name = L"PickDateForm";
			this->Text = L"PickDateForm";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &PickDateForm::onFormClosed);
			this->Load += gcnew System::EventHandler(this, &PickDateForm::onFormLoad);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	
	private: DataTable^ DT = gcnew DataTable;

	private: System::Void onFormLoad(System::Object^ sender, System::EventArgs^ e) {
		this->CenterToScreen();
		this->dateTimePicker1->Value = this->dateTimePicker1->Value.Date; // usuniecie liczby godzin, minut i sekund z daty
		this->dateTimePicker1->MinDate = this->dateTimePicker1->Value;
		this->checkIfToday();

		//ustawienie zrodla dla niewidocznego dataGridView
		this->dataGridView1->Columns->Clear();
		this->dataGridView1->DataSource = this->DT;
		
		this->loadMovieList();

	}

	private: System::Void onFormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
		Application::Exit();
	}

	private: int moviesNumber;
	private: int pagesNumber;
	private: int currentPage;
	private: String^ imagesPath = "\images/posters/";

	private: void hideMoviesGui() {
		this->MovieID1->Text = "";
		this->label1->Visible = false;
		this->label1->Text = "";
		this->pictureBox1->Visible = false;
		this->pictureBox1->ImageLocation = "";

		this->MovieID2->Text = "";
		this->label2->Visible = false;
		this->label2->Text = "";
		this->pictureBox2->Visible = false;
		this->pictureBox2->ImageLocation = "";

		this->MovieID3->Text = "";
		this->label3->Visible = false;
		this->label3->Text = "";
		this->pictureBox3->Visible = false;
		this->pictureBox3->ImageLocation = "";

		this->prevMoviesBtn->Visible = false;
		this->nextMoviesBtn->Visible = false;

		this->noShowsLabel->Visible = false;
	}
	private: void viewMovies() {

		this->hideMoviesGui();

		// ustawienie widocznosci przyciskow do przewijania filmow
		if (this->pagesNumber != 1) {
			if (this->currentPage >= this->pagesNumber) { this->prevMoviesBtn->Visible = true; }
			if (this->currentPage < this->pagesNumber) { this->nextMoviesBtn->Visible = true; }
		}

		// ustawienie labeli z tytulami i okladek
		int firstMovieIndex = (this->currentPage * 3) - 3;
		int secondMovieIndex = (this->currentPage * 3) - 2;
		int thirdMovieIndex = (this->currentPage * 3) - 1;

		if ((firstMovieIndex + 1) <= moviesNumber) {
			this->MovieID1->Text = this->dataGridView1[0, firstMovieIndex]->Value->ToString();
			this->label1->Text = this->dataGridView1[1, firstMovieIndex]->Value->ToString();
			String^ imgPath = this->imagesPath + this->dataGridView1[3, firstMovieIndex]->Value->ToString();
			this->pictureBox1->ImageLocation = imgPath;
			
			this->pictureBox1->Visible = true;
			this->label1->Visible = true;
		}
		if ((secondMovieIndex + 1) <= moviesNumber) {
			this->MovieID2->Text = this->dataGridView1[0, secondMovieIndex]->Value->ToString();
			this->label2->Text = this->dataGridView1[1, secondMovieIndex]->Value->ToString();
			String^ imgPath = this->imagesPath + this->dataGridView1[3, secondMovieIndex]->Value->ToString();
			this->pictureBox2->ImageLocation = imgPath;

			this->pictureBox2->Visible = true;
			this->label2->Visible = true;
		}
		if ((thirdMovieIndex + 1) <= moviesNumber) {
			this->MovieID3->Text = this->dataGridView1[0, thirdMovieIndex]->Value->ToString();
			this->label3->Text = this->dataGridView1[1, thirdMovieIndex]->Value->ToString();
			String^ imgPath = this->imagesPath + this->dataGridView1[3, thirdMovieIndex]->Value->ToString();
			this->pictureBox3->ImageLocation = imgPath;

			this->pictureBox3->Visible = true;
			this->label3->Visible = true;
		}
	}
	private: void loadMovieList() {

		this->hideMoviesGui();

		DateTime startTime = this->dateTimePicker1->Value;
		DateTime endTime = startTime.AddSeconds(86400); //TODO change to AddDay(1)
		try {
			this->dataGridView1->DataSource = DB::getMovieListTable(startTime, endTime);
		}
		catch (Exception^ e) {
			MessageBox::Show(e->ToString());
		}

		// ustawienie liczby filmow i liczby stron do przewijania
		this->moviesNumber = this->dataGridView1->RowCount - 1;
		if (this->moviesNumber > 0) {
			float tmpPagesNumber = this->moviesNumber / static_cast<float>(3);
			this->pagesNumber = ceil(tmpPagesNumber);
			if (this->pagesNumber == 0) { this->pagesNumber = 1; }
			this->currentPage = 1;
			this->viewMovies();
		} else {
			this->noShowsLabel->Visible = true;
		}

	}

	private: System::Void dateTimePicker1_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
		this->loadMovieList();
		this->checkIfToday();
	}
	
	private: void checkIfToday() {
		if (this->dateTimePicker1->Value == this->dateTimePicker1->MinDate) {
			this->prevDayBtn->Visible = false;
		}
		else {
			this->prevDayBtn->Visible = true;
		}
	}

	private: System::Void nextDayBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		DateTime date = this->dateTimePicker1->Value;
		date = date.AddDays(1);
		this->dateTimePicker1->Value = date;
	}

	private: System::Void prevDayBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		DateTime date = this->dateTimePicker1->Value;
		date = date.AddDays(-1);
		this->dateTimePicker1->Value = date;
	}

	private: System::Void nextMoviesBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		this->currentPage += 1;
		this->viewMovies();
	}

	private: System::Void prevMoviesBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		this->currentPage -= 1;
		this->viewMovies();
	}

	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {

	}

	private: void displayPickShowForm(String^ movieId) {
		DateTime date = this->dateTimePicker1->Value;
		PickShow^ pickShowForm = gcnew PickShow(this, movieId, date, this->user);
		this->Hide();
		pickShowForm->Show();
	}

	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
		displayPickShowForm(this->MovieID1->Text->ToString());
	}

	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
		displayPickShowForm(this->MovieID1->Text->ToString());
	}

	private: System::Void pictureBox2_Click(System::Object^ sender, System::EventArgs^ e) {
		displayPickShowForm(this->MovieID2->Text->ToString());
	}

	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
		displayPickShowForm(this->MovieID2->Text->ToString());
	}

	private: System::Void pictureBox3_Click(System::Object^ sender, System::EventArgs^ e) {
		displayPickShowForm(this->MovieID3->Text->ToString());
	}

	private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
		displayPickShowForm(this->MovieID3->Text->ToString());
	}

	private: System::Void goBackBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		this->prevForm->Show();
	}
};
}
