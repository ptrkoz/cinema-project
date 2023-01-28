#pragma once
#include "DB.h"
#include "User.h"
#include "FinalForm.h"

namespace Kino {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o MyTickets
	/// </summary>
	public ref class MyTickets : public System::Windows::Forms::Form
	{
	public:
		MyTickets(void)
		{
			InitializeComponent();
		}
		MyTickets(Form^ prevForm, User^ user)
		{
			InitializeComponent();
			this->prevForm = prevForm;
			this->user = user;
		}
	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~MyTickets()
		{
			if (components)
			{
				delete components;
			}
		}
	private: Form^ prevForm;
	private: User^ user = nullptr;
	private: System::Windows::Forms::Button^ backBtn;
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;
	private: System::Windows::Forms::Label^ label1;

	private: System::Windows::Forms::DataGridView^ dataGridView1;


	protected:

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
			this->backBtn = (gcnew System::Windows::Forms::Button());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// backBtn
			// 
			this->backBtn->Location = System::Drawing::Point(12, 12);
			this->backBtn->Name = L"backBtn";
			this->backBtn->Size = System::Drawing::Size(75, 23);
			this->backBtn->TabIndex = 0;
			this->backBtn->Text = L"<- powrót";
			this->backBtn->UseVisualStyleBackColor = true;
			this->backBtn->Click += gcnew System::EventHandler(this, &MyTickets::backBtn_Click);
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->AutoScroll = true;
			this->flowLayoutPanel1->Location = System::Drawing::Point(12, 147);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(581, 415);
			this->flowLayoutPanel1->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->Location = System::Drawing::Point(169, 64);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(252, 55);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Moje bilety";
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(427, 12);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(240, 129);
			this->dataGridView1->TabIndex = 3;
			// 
			// MyTickets
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(605, 574);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->flowLayoutPanel1);
			this->Controls->Add(this->backBtn);
			this->Name = L"MyTickets";
			this->Text = L"MyTickets";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &MyTickets::onFormClosed);
			this->Load += gcnew System::EventHandler(this, &MyTickets::MyTickets_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: int ticketsNumber = 0;
	private: String^ imagesPath = "\images/posters/";

	private: System::Void MyTickets_Load(System::Object^ sender, System::EventArgs^ e) {
		this->CenterToScreen();
		this->loadMyTickets();
	}

	private: System::Void onFormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
		Application::Exit();
	}

	private: void loadMyTickets() {
		this->flowLayoutPanel1->Controls->Clear();
		this->dataGridView1->DataSource = DB::getMyTicketsList(this->user->getId());
		this->ticketsNumber = this->dataGridView1->RowCount - 1;
		for (int i = 0; i < this->ticketsNumber; i++)
		{
			Panel^ ticketPanel = gcnew Panel;
			this->flowLayoutPanel1->Controls->Add(ticketPanel);
			ticketPanel->Location = System::Drawing::Point(3, 3 + (50*i));
			String^ panelName = "ticketPanel" + i.ToString();
			ticketPanel->Name = panelName;
			ticketPanel->Size = System::Drawing::Size(550, 164);
			//ticketPanel->TabIndex = 0;

			PictureBox^ pictureBox = gcnew PictureBox;
			ticketPanel->Controls->Add(pictureBox);
			pictureBox->Location = System::Drawing::Point(5, 5);
			String^ pinctureBoxName = "pinctureBox" + i.ToString();
			pictureBox->Name = pinctureBoxName;
			pictureBox->Size = System::Drawing::Size(110, 153);
			//pictureBox->TabIndex = 0;
			pictureBox->TabStop = false;
			pictureBox->SizeMode = PictureBoxSizeMode::StretchImage;
			String ^ imgPath = this->imagesPath + this->dataGridView1[0, i]->Value->ToString();
			pictureBox->ImageLocation = imgPath;

			Label^ movieNameLabel = gcnew Label;
			ticketPanel->Controls->Add(movieNameLabel);
			movieNameLabel->AutoSize = true;
			movieNameLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,static_cast<System::Byte>(238)));
			movieNameLabel->Location = System::Drawing::Point(130, 3);
			String^ movieNameLabelName = "movieNameLabel" + i.ToString();
			movieNameLabel->Name = movieNameLabelName;
			movieNameLabel->Size = System::Drawing::Size(252, 55);
			//movieNameLabel->TabIndex = 2;
			String^ movieNameLabelText = this->dataGridView1[1, i]->Value->ToString();
			movieNameLabel->Text = movieNameLabelText;

			Label^ showDateLabel = gcnew Label;
			ticketPanel->Controls->Add(showDateLabel);
			showDateLabel->AutoSize = true;
			showDateLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			showDateLabel->Location = System::Drawing::Point(135, 53);
			String^ showDateLabelName = "showDateLabel" + i.ToString();
			showDateLabel->Name = showDateLabelName;
			showDateLabel->Size = System::Drawing::Size(252, 55);
			//showDateLabel->TabIndex = 2;
			String^ showDateLabelText = this->dataGridView1[2, i]->Value->ToString();
			showDateLabelText = showDateLabelText->Remove(16); // usuniecie minut i sekund z daty
			showDateLabel->Text = showDateLabelText;


			Label^ ticketNumberLabel = gcnew Label;
			ticketPanel->Controls->Add(ticketNumberLabel);
			ticketNumberLabel->AutoSize = true;
			ticketNumberLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			ticketNumberLabel->Location = System::Drawing::Point(135, 83);
			String^ ticketNumberLabelName = "ticketNumberLabel" + i.ToString();
			ticketNumberLabel->Name = ticketNumberLabelName;
			ticketNumberLabel->Size = System::Drawing::Size(252, 55);
			//ticketNumberLabel->TabIndex = 2;
			String^ ticketNumberLabelText = "Iloœæ biletów: " + this->dataGridView1[4, i]->Value->ToString();
			ticketNumberLabel->Text = ticketNumberLabelText;

			Button^ detailsBtn = gcnew Button();
			ticketPanel->Controls->Add(detailsBtn);
			detailsBtn->Location = System::Drawing::Point(135, 110);
			String^ ticketId = this->dataGridView1[3, i]->Value->ToString();
			String^ btnName = "detailsBtn" + ticketId;
			detailsBtn->Name = btnName;
			detailsBtn->Size = System::Drawing::Size(75, 50);
			detailsBtn->Text = "Szczegó³y";
			detailsBtn->Click += gcnew System::EventHandler(this, &MyTickets::detailsBtnClick);
		}
	}
	private: System::Void backBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		this->prevForm->Show();
	}

	private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}

	private: String^ listToString(List<String^>^ list) {
		String^ result = "";
		for (int i = 0; i < list->Count; i++)
		{
			result += list[i] + ", ";
		}
		result = result->Substring(0, result->Length - 2);
		return result;
	}

	private: System::Void detailsBtnClick(System::Object^ sender, System::EventArgs^ e) {
		Button^ clickedPanel = (Button^)sender;
		String^ panelName = clickedPanel->Name;
		int ticketId = int::Parse(panelName->Substring(10));
		List<String^>^ ticketData = DB::getTicketData(ticketId);
		List<String^>^ ticketSeats = DB::getTicketSeats(ticketId);
		FinalForm^ finalForm = gcnew FinalForm(this, imagesPath + ticketData[0], ticketData[1], ticketData[2], ticketData[3], ticketData[4], this->listToString(ticketSeats), ticketData[5], ticketId, ticketSeats->Count, this->user);
		this->Hide();
		finalForm->ShowDialog();
		this->loadMyTickets();
	}

};
}
