#pragma once
#include "DB.h"
#include "EditShow.h"

namespace Kino {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o AdminShows
	/// </summary>
	public ref class AdminShows : public System::Windows::Forms::Form
	{
	public:
		AdminShows(void)
		{
			InitializeComponent();
		}

		AdminShows(Form^ prevForm)
		{
			InitializeComponent();
			this->prevForm = prevForm;
		}
	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~AdminShows()
		{
			if (components)
			{
				delete components;
			}
		}

	private: Form^ prevForm;
	private: System::Windows::Forms::Button^ goBackbtn;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Button^ addShowBtn;
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;
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
			this->goBackbtn = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->addShowBtn = (gcnew System::Windows::Forms::Button());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// goBackbtn
			// 
			this->goBackbtn->Location = System::Drawing::Point(12, 12);
			this->goBackbtn->Name = L"goBackbtn";
			this->goBackbtn->Size = System::Drawing::Size(75, 23);
			this->goBackbtn->TabIndex = 0;
			this->goBackbtn->Text = L"<- powrót";
			this->goBackbtn->UseVisualStyleBackColor = true;
			this->goBackbtn->Click += gcnew System::EventHandler(this, &AdminShows::goBackbtn_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->Location = System::Drawing::Point(195, 28);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(188, 55);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Seanse";
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(141, -106);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(240, 150);
			this->dataGridView1->TabIndex = 2;
			this->dataGridView1->Visible = false;
			// 
			// addShowBtn
			// 
			this->addShowBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->addShowBtn->Location = System::Drawing::Point(427, 28);
			this->addShowBtn->Name = L"addShowBtn";
			this->addShowBtn->Size = System::Drawing::Size(168, 50);
			this->addShowBtn->TabIndex = 3;
			this->addShowBtn->Text = L"Dodaj seans";
			this->addShowBtn->UseVisualStyleBackColor = true;
			this->addShowBtn->Click += gcnew System::EventHandler(this, &AdminShows::addShowBtn_Click);
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->AutoScroll = true;
			this->flowLayoutPanel1->Location = System::Drawing::Point(12, 103);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(583, 377);
			this->flowLayoutPanel1->TabIndex = 4;
			// 
			// AdminShows
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(607, 492);
			this->Controls->Add(this->flowLayoutPanel1);
			this->Controls->Add(this->addShowBtn);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->goBackbtn);
			this->Name = L"AdminShows";
			this->Text = L"AdminShows";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &AdminShows::onFormClosed);
			this->Load += gcnew System::EventHandler(this, &AdminShows::AdminShows_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: int showsNumber;
	private: String^ imagesPath = "\images/posters/";
	private: System::Void AdminShows_Load(System::Object^ sender, System::EventArgs^ e) {
		this->CenterToScreen();
		this->loadShows();
	}

	private: void loadShows() {
		this->flowLayoutPanel1->Controls->Clear();
		this->dataGridView1->DataSource = DB::getShows();
		this->showsNumber = this->dataGridView1->RowCount - 1;
		for (int i = 0; i < this->showsNumber; i++)
		{
			Panel^ showsPanel = gcnew Panel;
			this->flowLayoutPanel1->Controls->Add(showsPanel);
			showsPanel->Location = System::Drawing::Point(3, 3 + (50 * i));
			String^ panelName = "showsPanel" + i.ToString();
			showsPanel->Name = panelName;
			showsPanel->Size = System::Drawing::Size(550, 164);

			PictureBox^ pictureBox = gcnew PictureBox;
			showsPanel->Controls->Add(pictureBox);
			pictureBox->Location = System::Drawing::Point(5, 5);
			String^ pinctureBoxName = "pinctureBox" + i.ToString();
			pictureBox->Name = pinctureBoxName;
			pictureBox->Size = System::Drawing::Size(110, 153);
			pictureBox->TabStop = false;
			pictureBox->SizeMode = PictureBoxSizeMode::StretchImage;
			String^ imgPath = this->imagesPath + this->dataGridView1[2, i]->Value->ToString();
			pictureBox->ImageLocation = imgPath;

			Label^ movieNameLabel = gcnew Label;
			showsPanel->Controls->Add(movieNameLabel);
			movieNameLabel->AutoSize = true;
			movieNameLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			movieNameLabel->Location = System::Drawing::Point(130, 3);
			String^ movieNameLabelName = "movieNameLabel" + i.ToString();
			movieNameLabel->Name = movieNameLabelName;
			movieNameLabel->Size = System::Drawing::Size(252, 55);
			String^ movieNameLabelText = this->dataGridView1[1, i]->Value->ToString();
			movieNameLabel->Text = movieNameLabelText;

			Label^ showDateLabel = gcnew Label;
			showsPanel->Controls->Add(showDateLabel);
			showDateLabel->AutoSize = true;
			showDateLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			showDateLabel->Location = System::Drawing::Point(130, 35);
			String^ showDateLabelName = "showDateLabel" + i.ToString();
			showDateLabel->Name = showDateLabelName;
			showDateLabel->Size = System::Drawing::Size(252, 55);
			String^ showDateLabelText = this->dataGridView1[4, i]->Value->ToString();
			showDateLabelText = showDateLabelText->Remove(16); // usuniecie koncowki minut i sekund z daty 
			showDateLabel->Text = showDateLabelText;

			Label^ showRoomLabel = gcnew Label;
			showsPanel->Controls->Add(showRoomLabel);
			showRoomLabel->AutoSize = true;
			showRoomLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			showRoomLabel->Location = System::Drawing::Point(130, 75);
			String^ showRoomLabelName = "showRoomLabel" + i.ToString();
			showRoomLabel->Name = showRoomLabelName;
			showRoomLabel->Size = System::Drawing::Size(252, 55);
			String^ showRoomLabelText = this->dataGridView1[3, i]->Value->ToString();
			showRoomLabel->Text = showRoomLabelText;

			Label^ showVersionLabel = gcnew Label;
			showsPanel->Controls->Add(showVersionLabel);
			showVersionLabel->AutoSize = true;
			showVersionLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			showVersionLabel->Location = System::Drawing::Point(130, 110);
			String^ showVersionLabelName = "showVersionLabel" + i.ToString();
			showVersionLabel->Name = showVersionLabelName;
			showVersionLabel->Size = System::Drawing::Size(252, 55);\
			String^ showLang = this->dataGridView1[5, i]->Value->ToString();
			if (showLang == "sub") {
				showLang = "napisy";
			}
			else if (showLang == "dub") {
				showLang = "dubbing";
			}
			String^ showDim = this->dataGridView1[6, i]->Value->ToString(); 
			String^ showVersionLabelText = showDim + ", " + showLang;
			showVersionLabel->Text = showVersionLabelText;


			Button^ editBtn = gcnew Button();
			showsPanel->Controls->Add(editBtn);
			editBtn->Location = System::Drawing::Point(265, 90);
			String^ showId = this->dataGridView1[0, i]->Value->ToString();
			String^ editBtnName = "editBtn" + showId;
			editBtn->Name = editBtnName;
			editBtn->Size = System::Drawing::Size(75, 50);
			editBtn->Text = "Edytuj";
			editBtn->Click += gcnew System::EventHandler(this, &AdminShows::editBtnClick);

			Button^ deleteBtn = gcnew Button();
			showsPanel->Controls->Add(deleteBtn);
			deleteBtn->Location = System::Drawing::Point(345, 90);
			String^ deleteBtnName = "deleteBtn" + showId;
			deleteBtn->Name = deleteBtnName;
			deleteBtn->Size = System::Drawing::Size(75, 50);
			deleteBtn->Text = "Usuñ";
			deleteBtn->Click += gcnew System::EventHandler(this, &AdminShows::deleteBtnClick);
		}
	}

	private: System::Void onFormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
		Application::Exit();
	}

	private: System::Void goBackbtn_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		this->prevForm->Show();
	}

	private: System::Void editBtnClick(System::Object^ sender, System::EventArgs^ e) {
		Button^ clickedBtn = (Button^)sender;
		String^ btnName = clickedBtn->Name;
		int showId = int::Parse(btnName->Substring(7));
		EditShow^ editShow = gcnew EditShow(this, showId);
		this->Hide();
		editShow->ShowDialog();
		this->loadShows();
		this->Show();
	}

	private: System::Void deleteBtnClick(System::Object^ sender, System::EventArgs^ e) {
		Button^ clickedBtn = (Button^)sender;
		String^ btnName = clickedBtn->Name;
		int showId = int::Parse(btnName->Substring(9));
		if (DB::areTicketsSoldForShow(showId) == false) {
			DB::deleteShow(showId);
			this->loadShows();
		}
		else {
			MessageBox::Show("Nie mo¿na usun¹æ tego seansu, na który sprzedano ju¿ bilety.", "Tego seansu nie mo¿na usun¹æ", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
private: System::Void addShowBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	EditShow^ editShow = gcnew EditShow(this);
	this->Hide();
	editShow->ShowDialog();
	this->loadShows();
	this->Show();
}
};
}
