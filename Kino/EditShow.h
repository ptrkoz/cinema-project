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
	/// Podsumowanie informacji o EditShow
	/// </summary>
	public ref class EditShow : public System::Windows::Forms::Form
	{
	public:
		EditShow(void)
		{
			InitializeComponent();
		}

		EditShow(Form^ prevForm)
		{
			InitializeComponent();
			this->prevForm = prevForm;
		}

		EditShow(Form^ prevForm, int showId)
		{
			InitializeComponent();
			this->prevForm = prevForm;
			this->showId = showId;
		}

	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~EditShow()
		{
			if (components)
			{
				delete components;
			}
		}

	private: Form^ prevForm;
	private: int showId = -1;
	private: int movieId = -1;
	private: int roomId = -1;
	private: DateTime showDate;
	private: String^ showLang;
	private: String^ showDim;
	private: System::Windows::Forms::Button^ cancelBtn;
	private: System::Windows::Forms::Button^ addShowBtn;
	private: System::Windows::Forms::Button^ saveChangesBtn;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::ComboBox^ movieCb;
	private: System::Windows::Forms::ComboBox^ roomCb;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::ComboBox^ langCb;
	private: System::Windows::Forms::ComboBox^ dimCb;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker1;




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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(EditShow::typeid));
			this->cancelBtn = (gcnew System::Windows::Forms::Button());
			this->addShowBtn = (gcnew System::Windows::Forms::Button());
			this->saveChangesBtn = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->movieCb = (gcnew System::Windows::Forms::ComboBox());
			this->roomCb = (gcnew System::Windows::Forms::ComboBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->langCb = (gcnew System::Windows::Forms::ComboBox());
			this->dimCb = (gcnew System::Windows::Forms::ComboBox());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->SuspendLayout();
			// 
			// cancelBtn
			// 
			this->cancelBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->cancelBtn->Font = (gcnew System::Drawing::Font(L"Corbel", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->cancelBtn->Location = System::Drawing::Point(316, 429);
			this->cancelBtn->Name = L"cancelBtn";
			this->cancelBtn->Size = System::Drawing::Size(146, 52);
			this->cancelBtn->TabIndex = 0;
			this->cancelBtn->Text = L"Anuluj";
			this->cancelBtn->UseVisualStyleBackColor = true;
			this->cancelBtn->Click += gcnew System::EventHandler(this, &EditShow::cancelBtn_Click);
			// 
			// addShowBtn
			// 
			this->addShowBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->addShowBtn->Font = (gcnew System::Drawing::Font(L"Corbel", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->addShowBtn->Location = System::Drawing::Point(149, 429);
			this->addShowBtn->Name = L"addShowBtn";
			this->addShowBtn->Size = System::Drawing::Size(150, 52);
			this->addShowBtn->TabIndex = 1;
			this->addShowBtn->Text = L"Dodaj seans";
			this->addShowBtn->UseVisualStyleBackColor = true;
			this->addShowBtn->Click += gcnew System::EventHandler(this, &EditShow::addShowBtn_Click);
			// 
			// saveChangesBtn
			// 
			this->saveChangesBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->saveChangesBtn->Font = (gcnew System::Drawing::Font(L"Corbel", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->saveChangesBtn->Location = System::Drawing::Point(149, 429);
			this->saveChangesBtn->Name = L"saveChangesBtn";
			this->saveChangesBtn->Size = System::Drawing::Size(150, 52);
			this->saveChangesBtn->TabIndex = 2;
			this->saveChangesBtn->Text = L"Zapisz zmiany";
			this->saveChangesBtn->UseVisualStyleBackColor = true;
			this->saveChangesBtn->Click += gcnew System::EventHandler(this, &EditShow::saveChangesBtn_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Corbel", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->Location = System::Drawing::Point(225, 93);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(74, 33);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Film:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Corbel", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label2->Location = System::Drawing::Point(225, 152);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(74, 33);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Sala:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Corbel", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label3->Location = System::Drawing::Point(219, 206);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(80, 33);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Data:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Corbel", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label4->Location = System::Drawing::Point(60, 269);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(239, 33);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Wersja dŸwiêkowa:";
			// 
			// movieCb
			// 
			this->movieCb->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->movieCb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->movieCb->FormattingEnabled = true;
			this->movieCb->Location = System::Drawing::Point(305, 93);
			this->movieCb->Name = L"movieCb";
			this->movieCb->Size = System::Drawing::Size(232, 33);
			this->movieCb->TabIndex = 7;
			// 
			// roomCb
			// 
			this->roomCb->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->roomCb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->roomCb->FormattingEnabled = true;
			this->roomCb->Location = System::Drawing::Point(305, 152);
			this->roomCb->Name = L"roomCb";
			this->roomCb->Size = System::Drawing::Size(232, 33);
			this->roomCb->TabIndex = 8;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Corbel", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label5->Location = System::Drawing::Point(101, 321);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(195, 33);
			this->label5->TabIndex = 9;
			this->label5->Text = L"Format obrazu:";
			// 
			// langCb
			// 
			this->langCb->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->langCb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->langCb->FormattingEnabled = true;
			this->langCb->Location = System::Drawing::Point(305, 269);
			this->langCb->Name = L"langCb";
			this->langCb->Size = System::Drawing::Size(232, 33);
			this->langCb->TabIndex = 11;
			// 
			// dimCb
			// 
			this->dimCb->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->dimCb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->dimCb->FormattingEnabled = true;
			this->dimCb->Location = System::Drawing::Point(305, 321);
			this->dimCb->Name = L"dimCb";
			this->dimCb->Size = System::Drawing::Size(232, 33);
			this->dimCb->TabIndex = 12;
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->CustomFormat = L"dd/MM/yyyy HH:mm";
			this->dateTimePicker1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->dateTimePicker1->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dateTimePicker1->Location = System::Drawing::Point(305, 207);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(232, 31);
			this->dateTimePicker1->TabIndex = 13;
			// 
			// EditShow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(640, 510);
			this->Controls->Add(this->dateTimePicker1);
			this->Controls->Add(this->dimCb);
			this->Controls->Add(this->langCb);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->roomCb);
			this->Controls->Add(this->movieCb);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->saveChangesBtn);
			this->Controls->Add(this->addShowBtn);
			this->Controls->Add(this->cancelBtn);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"EditShow";
			this->Text = L"Zarz¹dzaj seansami - Kino";
			this->Load += gcnew System::EventHandler(this, &EditShow::EditShow_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void EditShow_Load(System::Object^ sender, System::EventArgs^ e) {
		this->CenterToScreen();
		this->setSaveBtnsVisibility();
		if (this->showId != -1) {
			this->loadShowData();
		}
		this->loadMovieList();
		this->loadRoomList();
		this->loadLangList();
		this->loadDimList();
	}

	private: void setSaveBtnsVisibility() {
		if (this->showId == -1) { // przy dodawaniu nowego seansu
			this->saveChangesBtn->Visible = false;
			this->addShowBtn->Visible = true;
		}
		else { // przy edycji istniej¹cego seansu
			this->addShowBtn->Visible = false;
			this->saveChangesBtn->Visible = true;
		}
	}
	
	private: void loadMovieList() {
		movieCb->DisplayMember = "name";
		movieCb->ValueMember = "id";
		movieCb->DataSource = DB::getMovies();
		if (this->showId != -1) {

			movieCb->SelectedValue = this->movieId;
		}
		else {
			movieCb->SelectedItem = nullptr;
		}
	}

	private: void loadRoomList() {
		roomCb->DisplayMember = "name";
		roomCb->ValueMember = "id";
		roomCb->DataSource = DB::getRooms();
		if (this->showId != -1) {
			roomCb->SelectedValue = this->roomId;
		}
		else {
			roomCb->SelectedItem = nullptr;
		}
	}

	private: void loadLangList() {
		DataTable^ langs = gcnew DataTable;
		langs->Columns->Add("id");
		langs->Columns->Add("name");
		DataRow^ dr1 = langs->NewRow();
		dr1[0] = "sub";
		dr1[1] = "napisy";
		langs->Rows->Add(dr1);
		DataRow^ dr2 = langs->NewRow();
		dr2[0] = "dub";
		dr2[1] = "dubbing";
		langs->Rows->Add(dr2);

		langCb->DisplayMember = "name";
		langCb->ValueMember = "id";
		this->langCb->DataSource = langs;
		if (this->showId != -1) {
			langCb->SelectedValue = this->showLang;
		} else {
			langCb->SelectedItem = nullptr;
		}
	}

	private: void loadDimList() {
		dimCb->Items->Add("2D");
		dimCb->Items->Add("3D");
		if (this->showId != -1) {
			dimCb->SelectedItem = this->showDim;
		}
		else {
			dimCb->SelectedItem = nullptr;
		}
	}

	private: void loadShowData() {
		List<String^>^ showData = DB::getShowDataForEdit(this->showId);
		this->movieId = int::Parse(showData[0]);
		this->roomId = int::Parse(showData[1]);
		this->showDate = DateTime::Parse(showData[2]);
		this->dateTimePicker1->Value = this->showDate;
		this->showLang = showData[3];
		this->showDim = showData[4];
	}

	private: System::Void cancelBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

	private: System::Void addShowBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		int sMovieId = int::Parse(movieCb->SelectedValue->ToString());
		int sRoomId = int::Parse(roomCb->SelectedValue->ToString());
		String^ sShowDate = this->dateTimePicker1->Value.ToString("yyyy-MM-dd HH:mm");
		sShowDate += ":00.000";
		String^ sShowLang = langCb->SelectedValue->ToString();
		String^ sShowDim = dimCb->SelectedItem->ToString();
		DB::addShow(sMovieId, sRoomId, sShowDate, sShowLang, sShowDim);
		this->Close();
	}


	private: System::Void saveChangesBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		int sMovieId = int::Parse(movieCb->SelectedValue->ToString());
		int sRoomId = int::Parse(roomCb->SelectedValue->ToString());
		String^ sShowDate = this->dateTimePicker1->Value.ToString("yyyy-MM-dd HH:mm");
		sShowDate += ":00.000";
		String^ sShowLang = langCb->SelectedValue->ToString();
		String^ sShowDim = dimCb->SelectedItem->ToString();
		DB::updateShow(this->showId, sMovieId, sRoomId, sShowDate, sShowLang, sShowDim);
		this->Close();
	}
};
}
