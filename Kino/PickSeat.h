#pragma once
#include "DB.h"
#include "User.h"
#include "PaymentForm.h"

namespace Kino {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SQLite;
	using namespace System::Collections::Generic;

	public ref class PickSeat : public System::Windows::Forms::Form
	{
	public:
		PickSeat(void)
		{
			InitializeComponent();
		}

		PickSeat(Form^ prevForm, String^ showId)
		{
			InitializeComponent();
			this->prevForm = prevForm;
			this->showId = showId;
		}

		PickSeat(Form^ prevForm, String^ showId, User^ user)
		{
			InitializeComponent();
			this->prevForm = prevForm;
			this->showId = showId;
			this->user = user;
		}

	protected:
		~PickSeat()
		{
			if (components)
			{
				delete components;
			}
		}

	private: String^ showId;
	private: Form^ prevForm;
	private: User^ user = nullptr;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Button^ goBackBtn;
	private: System::Windows::Forms::Label^ selectedSeatsLabel;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ ticketPriceLabel;
	private: System::Windows::Forms::Button^ SummaryBtn;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Button^ freeSeatbtn;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label11;




	protected:

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(PickSeat::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->goBackBtn = (gcnew System::Windows::Forms::Button());
			this->selectedSeatsLabel = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->ticketPriceLabel = (gcnew System::Windows::Forms::Label());
			this->SummaryBtn = (gcnew System::Windows::Forms::Button());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->freeSeatbtn = (gcnew System::Windows::Forms::Button());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label11 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(192, 48);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(141, 210);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Corbel", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->Location = System::Drawing::Point(339, 67);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(66, 26);
			this->label1->TabIndex = 1;
			this->label1->Text = L"label1";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label2->Location = System::Drawing::Point(340, 114);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(51, 20);
			this->label2->TabIndex = 2;
			this->label2->Text = L"label2";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label3->Location = System::Drawing::Point(340, 154);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(51, 20);
			this->label3->TabIndex = 3;
			this->label3->Text = L"label3";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label4->Location = System::Drawing::Point(340, 194);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(51, 20);
			this->label4->TabIndex = 4;
			this->label4->Text = L"label4";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Corbel", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label5->Location = System::Drawing::Point(19, 765);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(158, 23);
			this->label5->TabIndex = 5;
			this->label5->Text = L"Wybrane miejsca:";
			// 
			// label6
			// 
			this->label6->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label6->ForeColor = System::Drawing::SystemColors::ControlText;
			this->label6->Location = System::Drawing::Point(9, 273);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(603, 28);
			this->label6->TabIndex = 6;
			this->label6->Text = L"EKRAN";
			this->label6->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// goBackBtn
			// 
			this->goBackBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->goBackBtn->Font = (gcnew System::Drawing::Font(L"Corbel", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->goBackBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"goBackBtn.Image")));
			this->goBackBtn->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->goBackBtn->Location = System::Drawing::Point(15, 14);
			this->goBackBtn->Name = L"goBackBtn";
			this->goBackBtn->Size = System::Drawing::Size(141, 62);
			this->goBackBtn->TabIndex = 7;
			this->goBackBtn->Text = L"  powrót";
			this->goBackBtn->UseVisualStyleBackColor = true;
			this->goBackBtn->Click += gcnew System::EventHandler(this, &PickSeat::goBackBtn_Click);
			// 
			// selectedSeatsLabel
			// 
			this->selectedSeatsLabel->AutoSize = true;
			this->selectedSeatsLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->selectedSeatsLabel->Location = System::Drawing::Point(183, 767);
			this->selectedSeatsLabel->Name = L"selectedSeatsLabel";
			this->selectedSeatsLabel->Size = System::Drawing::Size(111, 20);
			this->selectedSeatsLabel->TabIndex = 8;
			this->selectedSeatsLabel->Text = L"selectedSeats";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Corbel", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label7->Location = System::Drawing::Point(27, 800);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(150, 33);
			this->label7->TabIndex = 9;
			this->label7->Text = L"Do zap³aty:";
			this->label7->Click += gcnew System::EventHandler(this, &PickSeat::label7_Click);
			// 
			// ticketPriceLabel
			// 
			this->ticketPriceLabel->AutoSize = true;
			this->ticketPriceLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->ticketPriceLabel->Location = System::Drawing::Point(186, 800);
			this->ticketPriceLabel->Name = L"ticketPriceLabel";
			this->ticketPriceLabel->Size = System::Drawing::Size(56, 31);
			this->ticketPriceLabel->TabIndex = 10;
			this->ticketPriceLabel->Text = L"0 z³";
			this->ticketPriceLabel->Click += gcnew System::EventHandler(this, &PickSeat::ticketPriceLabel_Click);
			// 
			// SummaryBtn
			// 
			this->SummaryBtn->Enabled = false;
			this->SummaryBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->SummaryBtn->Font = (gcnew System::Drawing::Font(L"Corbel", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->SummaryBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"SummaryBtn.Image")));
			this->SummaryBtn->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->SummaryBtn->Location = System::Drawing::Point(411, 800);
			this->SummaryBtn->Name = L"SummaryBtn";
			this->SummaryBtn->Size = System::Drawing::Size(207, 61);
			this->SummaryBtn->TabIndex = 11;
			this->SummaryBtn->Text = L"Podsumowanie";
			this->SummaryBtn->UseVisualStyleBackColor = true;
			this->SummaryBtn->Click += gcnew System::EventHandler(this, &PickSeat::SummaryBtn_Click);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Corbel", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label8->Location = System::Drawing::Point(17, 662);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(108, 29);
			this->label8->TabIndex = 12;
			this->label8->Text = L"Legenda:";
			// 
			// freeSeatbtn
			// 
			this->freeSeatbtn->BackColor = System::Drawing::Color::Green;
			this->freeSeatbtn->Enabled = false;
			this->freeSeatbtn->FlatAppearance->BorderSize = 0;
			this->freeSeatbtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->freeSeatbtn->Location = System::Drawing::Point(23, 699);
			this->freeSeatbtn->Name = L"freeSeatbtn";
			this->freeSeatbtn->Size = System::Drawing::Size(35, 35);
			this->freeSeatbtn->TabIndex = 13;
			this->freeSeatbtn->UseVisualStyleBackColor = true;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label9->Location = System::Drawing::Point(63, 707);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(116, 20);
			this->label9->TabIndex = 14;
			this->label9->Text = L"- miejsce wolne";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Gray;
			this->button1->Enabled = false;
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Location = System::Drawing::Point(216, 699);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(35, 35);
			this->button1->TabIndex = 15;
			this->button1->UseVisualStyleBackColor = false;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label10->Location = System::Drawing::Point(257, 707);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(118, 20);
			this->label10->TabIndex = 16;
			this->label10->Text = L"- miejsce zajête";
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::Orange;
			this->button2->Enabled = false;
			this->button2->FlatAppearance->BorderSize = 0;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Location = System::Drawing::Point(422, 699);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(35, 35);
			this->button2->TabIndex = 17;
			this->button2->UseVisualStyleBackColor = false;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label11->Location = System::Drawing::Point(465, 708);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(134, 20);
			this->label11->TabIndex = 16;
			this->label11->Text = L"- wybrane miejsce";
			// 
			// PickSeat
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(630, 873);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->freeSeatbtn);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->SummaryBtn);
			this->Controls->Add(this->ticketPriceLabel);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->selectedSeatsLabel);
			this->Controls->Add(this->goBackBtn);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"PickSeat";
			this->Text = L"Wybierz miejsce - Kino";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &PickSeat::onFormClosed);
			this->Load += gcnew System::EventHandler(this, &PickSeat::PickSeat_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: String^ imagesPath = "\images/posters/";
	private: String^ imageLocation;
	private: String^ movieName;
	private: String^ showDate;
	private: String^ showVersion;
	private: String^ showRoom;

	private: System::Void PickSeat_Load(System::Object^ sender, System::EventArgs^ e) {
		this->CenterToScreen();
		this->loadShowData(this->showId);
		this->displayShowData();
		this->displaySeats();
		this->selectedSeatsLabel->Text = "";
	}

	private: System::Void onFormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
		Application::Exit();
	}
	
	private: void loadShowData(String^ sId) {
		try {
			List<String^>^ showData = DB::getShowData(sId);
			this->imageLocation = this->imagesPath + showData[0];
			this->movieName = showData[1];
			this->showDate = showData[2];
			String^ showDim = showData[3];
			String^ showLangDB = showData[4];
			String^ showLang = "";
			if (showLangDB == "sub") { showLang = "napisy"; }
			else if (showLangDB == "dub") { showLang = "dubbing"; }
			this->showVersion = showDim + ", " + showLang;
			this->showRoom = showData[5];
		}
		catch (Exception^ e) {
			MessageBox::Show(e->ToString());
		}
	}

	private: void displayShowData() {
		this->pictureBox1->ImageLocation = this->imageLocation;
		this->label1->Text = this->movieName;
		this->label2->Text = this->showDate;
		this->label3->Text = this->showVersion;
		this->label4->Text = this->showRoom;
	}

	private: System::Char getChar(int digit)
	{
		Char gChar[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
		return gChar[digit];
	}

	private: void displaySeats() {
		int rowsNumber = 15;
		int columnNumber = 8;
		for (int i = 0; i < columnNumber; i++) {
			for (int j = 0; j < rowsNumber; j++) {
				Button^ seatBtn = gcnew Button();

				seatBtn->Location = System::Drawing::Point(10 + (40 * j), 320 + (40 * i));
				seatBtn->Size = System::Drawing::Size(35, 35);
				
				String^ rowChar = getChar(i).ToString();
				String^ seatName = rowChar + (j+1).ToString();
				seatBtn->Text = seatName;
				String^ btnName = "seatBtn" + seatName;
				seatBtn->Name = btnName;
				
				if (!this->checkSeatAvaiblity(seatName)) {
					seatBtn->Enabled = false;
					seatBtn->BackColor = Color::Gray;
				} else {
					seatBtn->BackColor = Color::Green;
				}
				seatBtn->FlatAppearance->BorderSize = 0;
				seatBtn->FlatStyle = FlatStyle::Flat;
				
				seatBtn->Click += gcnew System::EventHandler(this, &PickSeat::seatHandler);

				this->Controls->Add(seatBtn);
			}
		}
	}
	
	private: bool checkSeatAvaiblity(String^ seat) {
		return DB::checkSeat(this->showId, seat);
	}
	
	private: List<String^> selectedSeats;
	private: String^ ticketPrice = "0 z³";

	private: System::Void seatHandler(System::Object^ sender, System::EventArgs^ e) {
		
		Button^ seatBtn = (Button^)sender;
		String^ btnName = seatBtn->Name;
		String^ seatName = btnName->Substring(7);

		if (this->selectedSeats.IndexOf(seatName) == -1) { // sprawdzenie czy miejse jest juz w liscie
			if (selectedSeats.Count == 10) {
				MessageBox::Show("W jednym zamówieniu mo¿esz kupiæ maksymalnie 10 biletów.", "Maksymalna liczba biletów", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
			else {
				selectedSeats.Add(seatName);
				seatBtn->BackColor = Color::Orange;
			}
		} else {
			selectedSeats.Remove(seatName);
			seatBtn->BackColor = Color::Green;
		}
		this->updateSeatsLabel();
		this->updateTicketPrice();
		this->updateSummaryBtn();
	}

	private: void updateSeatsLabel() {
		String^ textToSet = "";
		for (int i = 0; i < this->selectedSeats.Count; i++)
		{
			textToSet += this->selectedSeats[i] + " ";
		}
		this->selectedSeatsLabel->Text = textToSet;
	}

	private: void updateTicketPrice() {
		int numberOfTickets = this->selectedSeats.Count;
		int price = numberOfTickets * 15;
		String^ textToSet = price.ToString() + " z³";
		this->ticketPriceLabel->Text = textToSet;
	}
	
	private: void updateSummaryBtn() {
		if (this->selectedSeats.Count > 0) {
			this->SummaryBtn->Enabled = true;
		}
		else {
			this->SummaryBtn->Enabled = false;
		}
	}

	private: System::Void goBackBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		this->prevForm->Show();
	}
	
	private: System::Void label7_Click(System::Object^ sender, System::EventArgs^ e) {
	
	}

	private: System::Void SummaryBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		PaymentForm^ paymentForm = gcnew PaymentForm(this, this->imageLocation, this->movieName, this->showDate, this->showVersion, this->showRoom, this->selectedSeats, this->showId, this->user);
		this->Hide();
		paymentForm->Show();
	}

	private: System::Void ticketPriceLabel_Click(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
