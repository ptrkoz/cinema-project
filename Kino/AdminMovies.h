#pragma once
#include "DB.h"
#include "EditMovie.h"

namespace Kino {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o AdminMovies
	/// </summary>
	public ref class AdminMovies : public System::Windows::Forms::Form
	{
	public:
		AdminMovies(void)
		{
			InitializeComponent();
		}

		AdminMovies(Form^ prevForm)
		{
			InitializeComponent();
			this->prevForm = prevForm;
		}
	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~AdminMovies()
		{
			if (components)
			{
				delete components;
			}
		}

	private: Form^ prevForm;
	private: System::Windows::Forms::Button^ goBackBtn;
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AdminMovies::typeid));
			this->goBackBtn = (gcnew System::Windows::Forms::Button());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// goBackBtn
			// 
			this->goBackBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->goBackBtn->Font = (gcnew System::Drawing::Font(L"Corbel", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->goBackBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"goBackBtn.Image")));
			this->goBackBtn->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->goBackBtn->Location = System::Drawing::Point(12, 36);
			this->goBackBtn->Name = L"goBackBtn";
			this->goBackBtn->Size = System::Drawing::Size(132, 51);
			this->goBackBtn->TabIndex = 0;
			this->goBackBtn->Text = L"   powrót";
			this->goBackBtn->UseVisualStyleBackColor = true;
			this->goBackBtn->Click += gcnew System::EventHandler(this, &AdminMovies::goBackBtn_Click);
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->AutoScroll = true;
			this->flowLayoutPanel1->Location = System::Drawing::Point(12, 110);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(665, 366);
			this->flowLayoutPanel1->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Corbel", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->Location = System::Drawing::Point(274, 32);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(140, 59);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Filmy";
			// 
			// button1
			// 
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Corbel", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->button1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.Image")));
			this->button1->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button1->Location = System::Drawing::Point(535, 36);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(142, 51);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Dodaj film";
			this->button1->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &AdminMovies::button1_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(12, 59);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(240, 150);
			this->dataGridView1->TabIndex = 4;
			this->dataGridView1->Visible = false;
			// 
			// AdminMovies
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(689, 488);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->flowLayoutPanel1);
			this->Controls->Add(this->goBackBtn);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"AdminMovies";
			this->Text = L"Zarz¹dzaj filmami - Kino";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &AdminMovies::onFormClosed);
			this->Load += gcnew System::EventHandler(this, &AdminMovies::AdminMovies_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: int movieNumber;
	private: String^ imagesPath = "\images/posters/";

	private: System::Void AdminMovies_Load(System::Object^ sender, System::EventArgs^ e) {
		this->CenterToScreen();
		this->loadMovies();
	}
	
	private: void loadMovies() {
		this->flowLayoutPanel1->Controls->Clear();
		this->dataGridView1->DataSource = DB::getMovies();
		this->movieNumber = this->dataGridView1->RowCount - 1;
		for (int i = 0; i < this->movieNumber; i++)
		{
			Panel^ moviePanel = gcnew Panel;
			this->flowLayoutPanel1->Controls->Add(moviePanel);
			moviePanel->Location = System::Drawing::Point(3, 3 + (50 * i));
			String^ panelName = "moviePanel" + i.ToString();
			moviePanel->Name = panelName;
			moviePanel->Size = System::Drawing::Size(550, 164);

			PictureBox^ pictureBox = gcnew PictureBox;
			moviePanel->Controls->Add(pictureBox);
			pictureBox->Location = System::Drawing::Point(5, 5);
			String^ pinctureBoxName = "pinctureBox" + i.ToString();
			pictureBox->Name = pinctureBoxName;
			pictureBox->Size = System::Drawing::Size(110, 153);
			pictureBox->TabStop = false;
			pictureBox->SizeMode = PictureBoxSizeMode::StretchImage;
			String^ imgPath = this->imagesPath + this->dataGridView1[2, i]->Value->ToString();
			pictureBox->ImageLocation = imgPath;

			Label^ movieNameLabel = gcnew Label;
			moviePanel->Controls->Add(movieNameLabel);
			movieNameLabel->AutoSize = true;
			movieNameLabel->Font = (gcnew System::Drawing::Font(L"Corbel", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			movieNameLabel->Location = System::Drawing::Point(130, 3);
			String^ movieNameLabelName = "movieNameLabel" + i.ToString();
			movieNameLabel->Name = movieNameLabelName;
			movieNameLabel->Size = System::Drawing::Size(252, 55);
			String^ movieNameLabelText = this->dataGridView1[1, i]->Value->ToString();
			movieNameLabel->Text = movieNameLabelText;

			Button^ editBtn = gcnew Button();
			moviePanel->Controls->Add(editBtn);
			editBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			editBtn->Location = System::Drawing::Point(135, 50);
			String^ movieId = this->dataGridView1[0, i]->Value->ToString();
			String^ editBtnName = "editBtn" + movieId;
			editBtn->Name = editBtnName;
			editBtn->Size = System::Drawing::Size(75, 50);
			editBtn->Text = "Edytuj";
			editBtn->Click += gcnew System::EventHandler(this, &AdminMovies::editBtnClick);

			Button^ deleteBtn = gcnew Button();
			moviePanel->Controls->Add(deleteBtn);
			deleteBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			deleteBtn->Location = System::Drawing::Point(215, 50);
			String^ deleteBtnName = "deleteBtn" + movieId;
			deleteBtn->Name = deleteBtnName;
			deleteBtn->Size = System::Drawing::Size(75, 50);
			deleteBtn->Text = "Usuñ";
			deleteBtn->Click += gcnew System::EventHandler(this, &AdminMovies::deleteBtnClick);
		}
	}

	private: System::Void onFormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
		Application::Exit();
	}
	private: System::Void goBackBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		this->prevForm->Show();
	}

	private: System::Void editBtnClick(System::Object^ sender, System::EventArgs^ e) {
		Button^ clickedBtn = (Button^)sender;
		String^ btnName = clickedBtn->Name;
		int movieId = int::Parse(btnName->Substring(7));
		EditMovie^ editMovie = gcnew EditMovie(this, movieId);
		this->Hide();
		editMovie->ShowDialog();
		this->loadMovies();
		this->Show();
	}

	private: System::Void deleteBtnClick(System::Object^ sender, System::EventArgs^ e) {
		Button^ clickedBtn = (Button^)sender;
		String^ btnName = clickedBtn->Name;
		int movieId = int::Parse(btnName->Substring(9));
		if (DB::isShowOfTheMovie(movieId) == false) {
			DB::deleteMovie(movieId);
			this->loadMovies();
		} else {
			MessageBox::Show("Nie mo¿na usun¹æ filmów, które mia³y lub maj¹ zaplanowane seanse.", "Tego filmu nie mo¿na usun¹æ", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
		   
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		EditMovie^ addMovie = gcnew EditMovie(this);
		this->Hide();
		addMovie->ShowDialog();
		this->loadMovies();
		this->Show();
	}
};
}
