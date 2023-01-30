#pragma once
#include "DB.h"

namespace Kino {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;
	
	public ref class EditMovie : public System::Windows::Forms::Form
	{
	public:
		EditMovie(void)
		{
			InitializeComponent();
		}
		EditMovie(Form^ prevForm)
		{
			InitializeComponent();
			this->prevForm = prevForm;
		}
		EditMovie(Form^ prevForm, int movieId)
		{
			InitializeComponent();
			this->prevForm = prevForm;
			this->movieId = movieId;
		}
	protected:
		~EditMovie()
		{
			if (components)
			{
				delete components;
			}
		}

	private: Form^ prevForm;
	private: int movieId = -1;
	private: System::Windows::Forms::Button^ cancelBtn;

	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ changeImageBtn;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::Button^ saveChangesBtn;
	private: System::Windows::Forms::Button^ addMovieBtn;
	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(EditMovie::typeid));
			this->cancelBtn = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->changeImageBtn = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->saveChangesBtn = (gcnew System::Windows::Forms::Button());
			this->addMovieBtn = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// cancelBtn
			// 
			this->cancelBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->cancelBtn->Font = (gcnew System::Drawing::Font(L"Corbel", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->cancelBtn->Location = System::Drawing::Point(308, 412);
			this->cancelBtn->Name = L"cancelBtn";
			this->cancelBtn->Size = System::Drawing::Size(121, 50);
			this->cancelBtn->TabIndex = 0;
			this->cancelBtn->Text = L"Anuluj";
			this->cancelBtn->UseVisualStyleBackColor = true;
			this->cancelBtn->Click += gcnew System::EventHandler(this, &EditMovie::cancelBtn_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(48, 61);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(151, 235);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// changeImageBtn
			// 
			this->changeImageBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->changeImageBtn->Font = (gcnew System::Drawing::Font(L"Corbel", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->changeImageBtn->Location = System::Drawing::Point(48, 302);
			this->changeImageBtn->Name = L"changeImageBtn";
			this->changeImageBtn->Size = System::Drawing::Size(151, 45);
			this->changeImageBtn->TabIndex = 2;
			this->changeImageBtn->Text = L"Wczytaj zdjêcie";
			this->changeImageBtn->UseVisualStyleBackColor = true;
			this->changeImageBtn->Click += gcnew System::EventHandler(this, &EditMovie::changeImageBtn_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Corbel", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->Location = System::Drawing::Point(247, 78);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(81, 26);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Nazwa:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Corbel", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label2->Location = System::Drawing::Point(269, 151);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(59, 26);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Opis:";
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->textBox1->Location = System::Drawing::Point(334, 78);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(271, 31);
			this->textBox1->TabIndex = 5;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &EditMovie::textBox1_TextChanged);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(334, 151);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(271, 192);
			this->richTextBox1->TabIndex = 6;
			this->richTextBox1->Text = L"";
			this->richTextBox1->TextChanged += gcnew System::EventHandler(this, &EditMovie::richTextBox1_TextChanged);
			// 
			// saveChangesBtn
			// 
			this->saveChangesBtn->Enabled = false;
			this->saveChangesBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->saveChangesBtn->Font = (gcnew System::Drawing::Font(L"Corbel", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->saveChangesBtn->Location = System::Drawing::Point(164, 412);
			this->saveChangesBtn->Name = L"saveChangesBtn";
			this->saveChangesBtn->Size = System::Drawing::Size(137, 50);
			this->saveChangesBtn->TabIndex = 7;
			this->saveChangesBtn->Text = L"Zapisz zmiany";
			this->saveChangesBtn->UseVisualStyleBackColor = true;
			this->saveChangesBtn->Click += gcnew System::EventHandler(this, &EditMovie::saveChangesBtn_Click);
			// 
			// addMovieBtn
			// 
			this->addMovieBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->addMovieBtn->Font = (gcnew System::Drawing::Font(L"Corbel", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->addMovieBtn->Location = System::Drawing::Point(164, 412);
			this->addMovieBtn->Name = L"addMovieBtn";
			this->addMovieBtn->Size = System::Drawing::Size(137, 50);
			this->addMovieBtn->TabIndex = 8;
			this->addMovieBtn->Text = L"Dodaj film";
			this->addMovieBtn->UseVisualStyleBackColor = true;
			this->addMovieBtn->Click += gcnew System::EventHandler(this, &EditMovie::addMovieBtn_Click);
			// 
			// EditMovie
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(642, 480);
			this->Controls->Add(this->addMovieBtn);
			this->Controls->Add(this->saveChangesBtn);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->changeImageBtn);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->cancelBtn);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"EditMovie";
			this->Text = L"Zarz¹dzaj filmami - Kino";
			this->Load += gcnew System::EventHandler(this, &EditMovie::EditMovie_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: String^ imagesPath = "\images/posters/";
	private: String^ posterFileName = "";

	private: System::Void EditMovie_Load(System::Object^ sender, System::EventArgs^ e) {
		this->CenterToScreen();
		this->setSaveBtnsVisibility();
		if (this->movieId != -1) {
			this->loadMovieData();
		}
		this->setBtnsAvailability();
	}

	private: void setSaveBtnsVisibility() {
		if (this->movieId == -1) { // przy dodawaniu nowego filmu
			this->saveChangesBtn->Visible = false;
			this->addMovieBtn->Visible = true;
		} else { // przy edycji istniej¹cego filmu
			this->addMovieBtn->Visible = false;
			this->saveChangesBtn->Visible = true;
		}
	}

	private: void loadMovieData() {
		List<String^>^ movieData = DB::getMovieData(this->movieId.ToString());
		this->textBox1->Text = movieData[0];
		this->richTextBox1->Text = movieData[1];
		this->posterFileName = movieData[2];
		this->pictureBox1->ImageLocation = this->imagesPath + movieData[2];
	}

	private: System::Void changeImageBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		this->saveChangesBtn->Enabled = true;
		OpenFileDialog^ ofd = gcnew OpenFileDialog;
		ofd->Filter = "PNG|*.png|JPG|*.jpg";
		if (ofd->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			Image^ img = Image::FromFile(ofd->FileName);
			String^ filename = System::IO::Path::GetFileName(ofd->FileName);
			this->posterFileName = filename;
			String^ pathAndFilename = this->imagesPath + filename;
			img->Save(pathAndFilename);
			this->pictureBox1->Image = img;
		}
	}

	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		this->saveChangesBtn->Enabled = true;
		this->setBtnsAvailability();
	}

	private: void setBtnsAvailability() {
		if (this->textBox1->Text->Length > 0) {
			this->saveChangesBtn->Enabled = true;
			this->addMovieBtn->Enabled = true;
		} else {
			this->saveChangesBtn->Enabled = false;
			this->addMovieBtn->Enabled = false;
		}
	}

	private: System::Void richTextBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		this->saveChangesBtn->Enabled = true;
	}

	private: System::Void saveChangesBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ movieName = this->textBox1->Text;
		String^ movieDesc = this->richTextBox1->Text;
		DB::updateMovie(this->movieId, movieName, movieDesc, this->posterFileName);
		this->Close();
	}

	private: System::Void cancelBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

	private: System::Void addMovieBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ movieName = this->textBox1->Text;
		String^ movieDesc = this->richTextBox1->Text;
		DB::addMovie(movieName, movieDesc, this->posterFileName);
		this->Close();
	}
};
}
