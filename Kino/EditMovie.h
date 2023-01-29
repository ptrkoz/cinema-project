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
	
	/// <summary>
	/// Podsumowanie informacji o EditMovie
	/// </summary>
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
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
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
			this->cancelBtn->Location = System::Drawing::Point(301, 477);
			this->cancelBtn->Name = L"cancelBtn";
			this->cancelBtn->Size = System::Drawing::Size(121, 50);
			this->cancelBtn->TabIndex = 0;
			this->cancelBtn->Text = L"Anuluj";
			this->cancelBtn->UseVisualStyleBackColor = true;
			this->cancelBtn->Click += gcnew System::EventHandler(this, &EditMovie::cancelBtn_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(56, 65);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(151, 235);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// changeImageBtn
			// 
			this->changeImageBtn->Location = System::Drawing::Point(56, 306);
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
			this->label1->Location = System::Drawing::Point(295, 146);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(43, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Nazwa:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(298, 236);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(31, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Opis:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(344, 143);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 5;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &EditMovie::textBox1_TextChanged);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(335, 233);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(271, 192);
			this->richTextBox1->TabIndex = 6;
			this->richTextBox1->Text = L"";
			this->richTextBox1->TextChanged += gcnew System::EventHandler(this, &EditMovie::richTextBox1_TextChanged);
			// 
			// saveChangesBtn
			// 
			this->saveChangesBtn->Enabled = false;
			this->saveChangesBtn->Location = System::Drawing::Point(157, 477);
			this->saveChangesBtn->Name = L"saveChangesBtn";
			this->saveChangesBtn->Size = System::Drawing::Size(137, 50);
			this->saveChangesBtn->TabIndex = 7;
			this->saveChangesBtn->Text = L"Zapisz zmiany";
			this->saveChangesBtn->UseVisualStyleBackColor = true;
			this->saveChangesBtn->Click += gcnew System::EventHandler(this, &EditMovie::saveChangesBtn_Click);
			// 
			// addMovieBtn
			// 
			this->addMovieBtn->Location = System::Drawing::Point(158, 477);
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
			this->ClientSize = System::Drawing::Size(642, 539);
			this->Controls->Add(this->addMovieBtn);
			this->Controls->Add(this->saveChangesBtn);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->changeImageBtn);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->cancelBtn);
			this->Name = L"EditMovie";
			this->Text = L"EditMovie";
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
