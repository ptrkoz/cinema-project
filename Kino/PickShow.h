#pragma once
#include "DB.h"
#include "User.h"
#include "PickSeat.h"
#include "LoginForm.h"
#include "RegisterForm.h"
#include "loginQ.h"

namespace Kino {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SQLite;

	public ref class PickShow : public System::Windows::Forms::Form
	{
	public:
		PickShow(void)
		{
			InitializeComponent();
		}

		PickShow(Form^ prevForm, String^ MovieID, DateTime selectedDate)
		{
			InitializeComponent();
			this->prevForm = prevForm;
			this->MovieID = MovieID;
			this->selectedDate = selectedDate;
		}

		PickShow(Form^ prevForm, String^ MovieID, DateTime selectedDate, User^ user)
		{
			InitializeComponent();
			this->prevForm = prevForm;
			this->MovieID = MovieID;
			this->selectedDate = selectedDate;
			this->user = user;
		}

	protected:
		~PickShow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	protected:
	private: Form^ prevForm;
	private: String^ MovieID;
	private: DateTime selectedDate;
	private: User^ user = nullptr;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Button^ goBackBtn;

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(PickShow::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->goBackBtn = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(119, 45);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(141, 210);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Corbel", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->Location = System::Drawing::Point(273, 53);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(74, 29);
			this->label1->TabIndex = 1;
			this->label1->Text = L"label1";
			this->label1->Click += gcnew System::EventHandler(this, &PickShow::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(546, 448);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(35, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"label2";
			this->label2->Visible = false;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label3->Location = System::Drawing::Point(12, 272);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(113, 20);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Seanse w dniu";
			// 
			// richTextBox1
			// 
			this->richTextBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->richTextBox1->Location = System::Drawing::Point(278, 91);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->ReadOnly = true;
			this->richTextBox1->Size = System::Drawing::Size(263, 159);
			this->richTextBox1->TabIndex = 4;
			this->richTextBox1->TabStop = false;
			this->richTextBox1->Text = L"";
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(526, 12);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 62;
			this->dataGridView1->Size = System::Drawing::Size(55, 44);
			this->dataGridView1->TabIndex = 5;
			this->dataGridView1->Visible = false;
			// 
			// goBackBtn
			// 
			this->goBackBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->goBackBtn->Font = (gcnew System::Drawing::Font(L"Corbel", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->goBackBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"goBackBtn.Image")));
			this->goBackBtn->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->goBackBtn->Location = System::Drawing::Point(12, 12);
			this->goBackBtn->Name = L"goBackBtn";
			this->goBackBtn->Size = System::Drawing::Size(101, 39);
			this->goBackBtn->TabIndex = 6;
			this->goBackBtn->Text = L"       powrót";
			this->goBackBtn->UseVisualStyleBackColor = true;
			this->goBackBtn->Click += gcnew System::EventHandler(this, &PickShow::goBackBtn_Click);
			// 
			// PickShow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(593, 470);
			this->Controls->Add(this->goBackBtn);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"PickShow";
			this->Text = L"Wybierz seans - Kino";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &PickShow::onFormClosed);
			this->Load += gcnew System::EventHandler(this, &PickShow::PickShow_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: String^ imagesPath = "\images/posters/";
	private: DataTable^ DTshows = gcnew DataTable;
	private: String^ movieName = "";
	private: String^ movieDesc = "";
	private: String^ movieImage = "";

	private: System::Void PickShow_Load(System::Object^ sender, System::EventArgs^ e) {
		this->CenterToScreen();
		this->dataGridView1->Columns->Clear();
		this->dataGridView1->DataSource = this->DTshows;
		this->label3->Text = "Seanse w dniu " + this->selectedDate.ToString("dd.MM.yyyy");
		this->displayMovieData(this->MovieID);
	}

	private: System::Void onFormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
		Application::Exit();
	}
	
	private: void displayMovieData(String^ id) {
		DateTime startDate = this->selectedDate;
		DateTime endDate = startDate.AddDays(1);

		try {
			List<String^>^ movieData = DB::getMovieData(id);
			this->label1->Text = movieData[0];
			this->richTextBox1->Text = movieData[1];
			String^ imgPath = this->imagesPath + movieData[2];
			this->pictureBox1->ImageLocation = imgPath;

			this->dataGridView1->DataSource = DB::getShowsForMovie(id, startDate, endDate);			this->DTshows->Clear();
			
		}
		catch (Exception^ e) {
			MessageBox::Show(e->ToString());
		}

		int numberOfShows = this->dataGridView1->RowCount - 1;
		for (int i = 0; i < numberOfShows; i++)
		{
			Button^ showBtn = gcnew Button();
			showBtn->Location = System::Drawing::Point(10 + (85 * i), 300);
			showBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			String^ showId = this->dataGridView1[0, i]->Value->ToString();
			String^ btnName = "showBtn" + showId;
			showBtn->Name = btnName;
			showBtn->Size = System::Drawing::Size(80, 60);
			showBtn->TabIndex = 10 + i;

			DateTime^ showDate = DateTime::Parse(this->dataGridView1[1, i]->Value->ToString());
			String^ showDim = this->dataGridView1[3, i]->Value->ToString();
			String^ showLangDB = this->dataGridView1[2, i]->Value->ToString();
			String^ showLang = "";
			if (showLangDB == "sub") { showLang = "napisy"; }
			else if (showLangDB == "dub") { showLang = "dubbing"; }

			String^ textToSet = showDate->ToString("HH:mm") + "\n" + showDim + ", " + showLang;
			showBtn->Text = textToSet;

			showBtn->UseVisualStyleBackColor = true;
			showBtn->Click += gcnew System::EventHandler(this, &PickShow::displayPickSeat);
			this->Controls->Add(showBtn);
		}
	}

	private: System::Void displayPickSeat(System::Object^ sender, System::EventArgs^ e) {
		Button^ clickedBtn = (Button^)sender;
		String^ btnName = clickedBtn->Name;
		String^ showId = btnName->Substring(7);
		if (this->user == nullptr) { // uzytkownik niezalogowany
			LoginQ^ loginQ = gcnew LoginQ;
			loginQ->ShowDialog();
			if (loginQ->choice == 1) { // kontynuj bez konta
				PickSeat^ pickSeatForm = gcnew PickSeat(this, showId, this->user);
				this->Hide();
				pickSeatForm->Show();
			} else if (loginQ->choice == 2) { // zaloguj sie
				LoginForm^ loginForm = gcnew LoginForm(this);
				this->Hide();
				loginForm->ShowDialog();
				if (loginForm->getUser() != nullptr) {
					PickSeat^ pickSeatForm = gcnew PickSeat(this, showId, loginForm->getUser());
					this->Hide();
					pickSeatForm->Show();
				} else {
					this->Show();
				}
			} else if (loginQ->choice == 3) { // zarejstruj sie //todo
				RegisterForm^ registerForm = gcnew RegisterForm(this);
				this->Hide();
				registerForm->ShowDialog();
				if (registerForm->getUser() != nullptr) {
					PickSeat^ pickSeatForm = gcnew PickSeat(this, showId, registerForm->getUser());
					this->Hide();
					pickSeatForm->Show();
				}
				else {
					this->Show();
				}
			}
		} else { // uzytkownik zalogowany
			PickSeat^ pickSeatForm = gcnew PickSeat(this, showId, this->user);
			this->Hide();
			pickSeatForm->Show();
		}
	}

	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {

	}

	private: System::Void goBackBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		this->prevForm->Show();
	}
};
}
