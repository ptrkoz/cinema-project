#pragma once
#include <random>
#include "DB.h"
#include "User.h"
#include "LoginForm.h"
#include "FinalForm.h"

namespace Kino {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SQLite;
	using namespace System::Collections::Generic;

	public ref class PaymentForm : public System::Windows::Forms::Form
	{
	public:
		PaymentForm(void)
		{
			InitializeComponent();
		}
		PaymentForm(Form^ prevForm, String^ imageLocation, String^ movieName, String^ showDate, String^ showVersion, String^ showRoom, List<String^>% gSelectedSeats, String^ showId)
		{
			InitializeComponent();
			this->prevForm = prevForm;
			this->imageLocation = imageLocation;
			this->movieName = movieName;
			this->showDate = showDate;
			this->showVersion = showVersion;
			this->showRoom = showRoom;
			this->showId = showId;
			for (int i = 0; i < gSelectedSeats.Count; i++)
			{
				this->selectedSeats.Add(gSelectedSeats[i]);
			}
		}

		PaymentForm(Form^ prevForm, String^ imageLocation, String^ movieName, String^ showDate, String^ showVersion, String^ showRoom, List<String^>% gSelectedSeats, String^ showId, User^ user)
		{
			InitializeComponent();
			this->prevForm = prevForm;
			this->imageLocation = imageLocation;
			this->movieName = movieName;
			this->showDate = showDate;
			this->showVersion = showVersion;
			this->showRoom = showRoom;
			this->showId = showId;
			for (int i = 0; i < gSelectedSeats.Count; i++)
			{
				this->selectedSeats.Add(gSelectedSeats[i]);
			}
			this->user = user;
		}

	protected:
		~PaymentForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: Form^ prevForm;
	private: String^ imageLocation;
	private: String^ movieName;
	private: String^ showDate;
	private: String^ showVersion;
	private: String^ showRoom;
	private: String^ showId;
	private: List<String^> selectedSeats;
	private: User^ user = nullptr;
	private: System::Windows::Forms::Button^ goBackBtn;
	protected:
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ movieNameLabel;
	private: System::Windows::Forms::Label^ showDateLabel;
	private: System::Windows::Forms::Label^ showVersionLabel;
	private: System::Windows::Forms::Label^ showRoomLabel;
	private: System::Windows::Forms::Label^ numberOfTicketsLabel;
	private: System::Windows::Forms::Label^ seatsLabel;
	private: System::Windows::Forms::Button^ payBtn1;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ payBtn4;

	private: System::Windows::Forms::Button^ payBtn2;
	private: System::Windows::Forms::Button^ payBtn3;


	private: System::Windows::Forms::Label^ emailLabel;

	private: System::Windows::Forms::TextBox^ emailTextBox;
	private: System::Windows::Forms::Label^ blikLabel;


	private: System::Windows::Forms::TextBox^ blikTextBox;

	private: System::Windows::Forms::Label^ ticketPriceLabel;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ buyTicketsBtn;






	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(PaymentForm::typeid));
			this->goBackBtn = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->movieNameLabel = (gcnew System::Windows::Forms::Label());
			this->showDateLabel = (gcnew System::Windows::Forms::Label());
			this->showVersionLabel = (gcnew System::Windows::Forms::Label());
			this->showRoomLabel = (gcnew System::Windows::Forms::Label());
			this->numberOfTicketsLabel = (gcnew System::Windows::Forms::Label());
			this->seatsLabel = (gcnew System::Windows::Forms::Label());
			this->payBtn1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->payBtn4 = (gcnew System::Windows::Forms::Button());
			this->payBtn2 = (gcnew System::Windows::Forms::Button());
			this->payBtn3 = (gcnew System::Windows::Forms::Button());
			this->emailLabel = (gcnew System::Windows::Forms::Label());
			this->emailTextBox = (gcnew System::Windows::Forms::TextBox());
			this->blikLabel = (gcnew System::Windows::Forms::Label());
			this->blikTextBox = (gcnew System::Windows::Forms::TextBox());
			this->ticketPriceLabel = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->buyTicketsBtn = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// goBackBtn
			// 
			this->goBackBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->goBackBtn->Font = (gcnew System::Drawing::Font(L"Corbel", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->goBackBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"goBackBtn.Image")));
			this->goBackBtn->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->goBackBtn->Location = System::Drawing::Point(9, 8);
			this->goBackBtn->Margin = System::Windows::Forms::Padding(2);
			this->goBackBtn->Name = L"goBackBtn";
			this->goBackBtn->Size = System::Drawing::Size(112, 42);
			this->goBackBtn->TabIndex = 0;
			this->goBackBtn->Text = L"    powr?t";
			this->goBackBtn->UseVisualStyleBackColor = true;
			this->goBackBtn->Click += gcnew System::EventHandler(this, &PaymentForm::goBackBtn_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(49, 68);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(127, 211);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// movieNameLabel
			// 
			this->movieNameLabel->AutoSize = true;
			this->movieNameLabel->Font = (gcnew System::Drawing::Font(L"Corbel", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->movieNameLabel->Location = System::Drawing::Point(189, 68);
			this->movieNameLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->movieNameLabel->Name = L"movieNameLabel";
			this->movieNameLabel->Size = System::Drawing::Size(137, 29);
			this->movieNameLabel->TabIndex = 2;
			this->movieNameLabel->Text = L"movieName";
			// 
			// showDateLabel
			// 
			this->showDateLabel->AutoSize = true;
			this->showDateLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->showDateLabel->Location = System::Drawing::Point(190, 110);
			this->showDateLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->showDateLabel->Name = L"showDateLabel";
			this->showDateLabel->Size = System::Drawing::Size(93, 24);
			this->showDateLabel->TabIndex = 3;
			this->showDateLabel->Text = L"showDate";
			// 
			// showVersionLabel
			// 
			this->showVersionLabel->AutoSize = true;
			this->showVersionLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F));
			this->showVersionLabel->Location = System::Drawing::Point(190, 148);
			this->showVersionLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->showVersionLabel->Name = L"showVersionLabel";
			this->showVersionLabel->Size = System::Drawing::Size(120, 24);
			this->showVersionLabel->TabIndex = 4;
			this->showVersionLabel->Text = L"showVersion";
			// 
			// showRoomLabel
			// 
			this->showRoomLabel->AutoSize = true;
			this->showRoomLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F));
			this->showRoomLabel->Location = System::Drawing::Point(190, 186);
			this->showRoomLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->showRoomLabel->Name = L"showRoomLabel";
			this->showRoomLabel->Size = System::Drawing::Size(106, 24);
			this->showRoomLabel->TabIndex = 5;
			this->showRoomLabel->Text = L"showRoom";
			// 
			// numberOfTicketsLabel
			// 
			this->numberOfTicketsLabel->AutoSize = true;
			this->numberOfTicketsLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F));
			this->numberOfTicketsLabel->Location = System::Drawing::Point(190, 220);
			this->numberOfTicketsLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->numberOfTicketsLabel->Name = L"numberOfTicketsLabel";
			this->numberOfTicketsLabel->Size = System::Drawing::Size(154, 24);
			this->numberOfTicketsLabel->TabIndex = 6;
			this->numberOfTicketsLabel->Text = L"numberOfTickets";
			// 
			// seatsLabel
			// 
			this->seatsLabel->AutoSize = true;
			this->seatsLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F));
			this->seatsLabel->Location = System::Drawing::Point(190, 255);
			this->seatsLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->seatsLabel->Name = L"seatsLabel";
			this->seatsLabel->Size = System::Drawing::Size(99, 24);
			this->seatsLabel->TabIndex = 7;
			this->seatsLabel->Text = L"seatsLabel";
			// 
			// payBtn1
			// 
			this->payBtn1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"payBtn1.BackgroundImage")));
			this->payBtn1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->payBtn1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->payBtn1->Location = System::Drawing::Point(48, 357);
			this->payBtn1->Margin = System::Windows::Forms::Padding(2);
			this->payBtn1->Name = L"payBtn1";
			this->payBtn1->Size = System::Drawing::Size(153, 91);
			this->payBtn1->TabIndex = 8;
			this->payBtn1->UseVisualStyleBackColor = true;
			this->payBtn1->Click += gcnew System::EventHandler(this, &PaymentForm::payBtn_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Corbel", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->Location = System::Drawing::Point(257, 315);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(227, 23);
			this->label1->TabIndex = 9;
			this->label1->Text = L"Wybierz metod? p?atno?ci";
			// 
			// payBtn4
			// 
			this->payBtn4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"payBtn4.BackgroundImage")));
			this->payBtn4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->payBtn4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->payBtn4->Location = System::Drawing::Point(537, 357);
			this->payBtn4->Margin = System::Windows::Forms::Padding(2);
			this->payBtn4->Name = L"payBtn4";
			this->payBtn4->Size = System::Drawing::Size(153, 91);
			this->payBtn4->TabIndex = 10;
			this->payBtn4->UseVisualStyleBackColor = true;
			this->payBtn4->Click += gcnew System::EventHandler(this, &PaymentForm::payBtn_Click);
			// 
			// payBtn2
			// 
			this->payBtn2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"payBtn2.BackgroundImage")));
			this->payBtn2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->payBtn2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->payBtn2->Location = System::Drawing::Point(210, 357);
			this->payBtn2->Margin = System::Windows::Forms::Padding(2);
			this->payBtn2->Name = L"payBtn2";
			this->payBtn2->Size = System::Drawing::Size(153, 91);
			this->payBtn2->TabIndex = 11;
			this->payBtn2->UseVisualStyleBackColor = true;
			this->payBtn2->Click += gcnew System::EventHandler(this, &PaymentForm::payBtn_Click);
			// 
			// payBtn3
			// 
			this->payBtn3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"payBtn3.BackgroundImage")));
			this->payBtn3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->payBtn3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->payBtn3->Location = System::Drawing::Point(373, 357);
			this->payBtn3->Margin = System::Windows::Forms::Padding(2);
			this->payBtn3->Name = L"payBtn3";
			this->payBtn3->Size = System::Drawing::Size(153, 91);
			this->payBtn3->TabIndex = 12;
			this->payBtn3->UseVisualStyleBackColor = true;
			this->payBtn3->Click += gcnew System::EventHandler(this, &PaymentForm::payBtn_Click);
			// 
			// emailLabel
			// 
			this->emailLabel->AutoSize = true;
			this->emailLabel->Font = (gcnew System::Drawing::Font(L"Corbel", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->emailLabel->Location = System::Drawing::Point(194, 477);
			this->emailLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->emailLabel->Name = L"emailLabel";
			this->emailLabel->Size = System::Drawing::Size(140, 29);
			this->emailLabel->TabIndex = 13;
			this->emailLabel->Text = L"Adres email:";
			// 
			// emailTextBox
			// 
			this->emailTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->emailTextBox->Location = System::Drawing::Point(338, 474);
			this->emailTextBox->Margin = System::Windows::Forms::Padding(2);
			this->emailTextBox->Name = L"emailTextBox";
			this->emailTextBox->Size = System::Drawing::Size(188, 35);
			this->emailTextBox->TabIndex = 14;
			this->emailTextBox->TextChanged += gcnew System::EventHandler(this, &PaymentForm::emailTextBox_TextChanged);
			// 
			// blikLabel
			// 
			this->blikLabel->AutoSize = true;
			this->blikLabel->Font = (gcnew System::Drawing::Font(L"Corbel", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->blikLabel->Location = System::Drawing::Point(210, 525);
			this->blikLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->blikLabel->Name = L"blikLabel";
			this->blikLabel->Size = System::Drawing::Size(116, 29);
			this->blikLabel->TabIndex = 15;
			this->blikLabel->Text = L"Kod BLIK:";
			// 
			// blikTextBox
			// 
			this->blikTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->blikTextBox->Location = System::Drawing::Point(338, 522);
			this->blikTextBox->Margin = System::Windows::Forms::Padding(2);
			this->blikTextBox->MaxLength = 6;
			this->blikTextBox->Name = L"blikTextBox";
			this->blikTextBox->Size = System::Drawing::Size(137, 35);
			this->blikTextBox->TabIndex = 16;
			this->blikTextBox->TextChanged += gcnew System::EventHandler(this, &PaymentForm::blikTextBox_TextChanged);
			// 
			// ticketPriceLabel
			// 
			this->ticketPriceLabel->AutoSize = true;
			this->ticketPriceLabel->Font = (gcnew System::Drawing::Font(L"Corbel", 20.25F, System::Drawing::FontStyle::Bold));
			this->ticketPriceLabel->Location = System::Drawing::Point(566, 246);
			this->ticketPriceLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->ticketPriceLabel->Name = L"ticketPriceLabel";
			this->ticketPriceLabel->Size = System::Drawing::Size(139, 33);
			this->ticketPriceLabel->TabIndex = 17;
			this->ticketPriceLabel->Text = L"ticketPrice";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Corbel", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label4->Location = System::Drawing::Point(412, 248);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(150, 33);
			this->label4->TabIndex = 18;
			this->label4->Text = L"Do zap?aty:";
			// 
			// buyTicketsBtn
			// 
			this->buyTicketsBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buyTicketsBtn->Font = (gcnew System::Drawing::Font(L"Corbel", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->buyTicketsBtn->Location = System::Drawing::Point(551, 540);
			this->buyTicketsBtn->Margin = System::Windows::Forms::Padding(2);
			this->buyTicketsBtn->Name = L"buyTicketsBtn";
			this->buyTicketsBtn->Size = System::Drawing::Size(186, 71);
			this->buyTicketsBtn->TabIndex = 19;
			this->buyTicketsBtn->UseVisualStyleBackColor = true;
			this->buyTicketsBtn->Click += gcnew System::EventHandler(this, &PaymentForm::buyTicketsBtn_Click);
			// 
			// PaymentForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(748, 622);
			this->Controls->Add(this->buyTicketsBtn);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->ticketPriceLabel);
			this->Controls->Add(this->blikTextBox);
			this->Controls->Add(this->blikLabel);
			this->Controls->Add(this->emailTextBox);
			this->Controls->Add(this->emailLabel);
			this->Controls->Add(this->payBtn3);
			this->Controls->Add(this->payBtn2);
			this->Controls->Add(this->payBtn4);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->payBtn1);
			this->Controls->Add(this->seatsLabel);
			this->Controls->Add(this->numberOfTicketsLabel);
			this->Controls->Add(this->showRoomLabel);
			this->Controls->Add(this->showVersionLabel);
			this->Controls->Add(this->showDateLabel);
			this->Controls->Add(this->movieNameLabel);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->goBackBtn);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"PaymentForm";
			this->Text = L"P?atno?? - Kino";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &PaymentForm::onFormClosed);
			this->Load += gcnew System::EventHandler(this, &PaymentForm::PaymentForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	private: bool isLogged;
	private: String^ ticketCode;

	private: System::Void PaymentForm_Load(System::Object^ sender, System::EventArgs^ e) {
		this->CenterToScreen();
		this->checkIfLogged();
		this->updateBuyTicketsBtn();

		this->pictureBox1->ImageLocation = this->imageLocation;
		this->movieNameLabel->Text = this->movieName;
		this->showDateLabel->Text = this->showDate;
		this->showVersionLabel->Text = this->showVersion;
		this->showRoomLabel->Text = this->showRoom;
		this->numberOfTicketsLabel->Text = "Ilo?? bilet?w: " + this->selectedSeats.Count.ToString();
		
		this->seatsLabel->Text = "Miejsca: " + listToString(selectedSeats);

		this->ticketPriceLabel->Text = (this->selectedSeats.Count * 15).ToString() + " z?";
		
		if (this->isLogged == true) {
			this->emailLabel->Visible = false;
			this->emailTextBox->Visible = false;
		} else {
			this->emailLabel->Visible = true;
			this->emailTextBox->Visible = true;
		}

		String^ buyTicketsBtnText;
		if (this->selectedSeats.Count > 1) { buyTicketsBtnText = "Kup bilety"; }
		else { buyTicketsBtnText = "Kup bilet"; }
		this->buyTicketsBtn->Text = buyTicketsBtnText;
	}

	private: String^ listToString(List<String^> %list) {
		String^ result = "";
		for (int i = 0; i < list.Count; i++)
		{
			result += list[i] + ", ";
		}
		result = result->Substring(0, result->Length - 2);
		return result;
	}

	private: void checkIfLogged() {
		if (this->user == nullptr) { this->isLogged = false; }
		else { this->isLogged = true; }
	}

	private: const int blikPaymentId = 3;

	private: void updateBuyTicketsBtn() {

		//ustawienie textboxa i labelu z kodem blik
		if (this->selectedPaymentMethod == this->blikPaymentId) {
			this->blikLabel->Visible = true;
			this->blikTextBox->Visible = true;
		} else {
			this->blikLabel->Visible = false;
			this->blikTextBox->Visible = false;
		}

		//ustawienie przycisku dostepnosci przycisku Kup bilet
		this->buyTicketsBtn->Enabled = false;
		if (this->isLogged == false) { // niezalogwany
			if (this->emailTextBox->Text->Length > 0 && this->selectedPaymentMethod != 0) {
				if (this->selectedPaymentMethod == this->blikPaymentId) {
					if (this->blikTextBox->Text->Length == 6) {
						this->buyTicketsBtn->Enabled = true;
					}
				} else {
					this->buyTicketsBtn->Enabled = true;
				}
			}
		} else { // zalogwany
			if (this->selectedPaymentMethod != 0) {
				if (this->selectedPaymentMethod == this->blikPaymentId) {
					if (this->blikTextBox->Text->Length == 6) {
						this->buyTicketsBtn->Enabled = true;
					}
				} else {
					this->buyTicketsBtn->Enabled = true;
				}
			}
		}
	}

	private: System::Void goBackBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		this->prevForm->Show();
	}

	private: System::Void buyTicketsBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		int ticketId;
		if (this->isLogged == false) {
			String^ gLogin = this->emailTextBox->Text;
			int userId = this->getUserId(gLogin);
			if (userId == -1) { // uzytkownik nie kupowal jeszcze z tego adresu email
				userId = addLoginToDb(gLogin);
			}
			ticketId = saveTickets(userId);
			saveTicketsSeats(ticketId);
		} else {
			ticketId = saveTickets(this->user->getId());
			saveTicketsSeats(ticketId);
		}
		FinalForm^ finalForm = gcnew FinalForm(this->imageLocation, this->movieName, this->showDate, this->showVersion, this->showRoom, listToString(this->selectedSeats), this->ticketCode, ticketId, this->selectedSeats.Count, this->user);
		this->Hide();
		finalForm->Show();
	}
	
	private: int getUserId(String^ gLogin) {
		return DB::getUserIdByLogin(gLogin);
	}
	
	private: String^ generateCode(int ch)
	{
		srand(time(NULL));
		const int numberOfChars = 36;
		Char alphaNumeric[numberOfChars] = {
						   'A', 'B', 'C', 'D', 'E', 'F', 'G',
						   'H', 'I', 'J', 'K', 'L', 'M', 'N',
						   'O', 'P', 'Q', 'R', 'S', 'T', 'U',
						   'V', 'W', 'X', 'Y', 'Z',
						   '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'
						   };
		String^ result = "";
		for (int i = 0; i < ch; i++) {
			result = result + alphaNumeric[rand() % numberOfChars];
		}
			
		return result;
	}

	private: int saveTickets(int userId) {
		this->ticketCode = generateCode(8);
		int id = DB::saveTickets(userId, this->showId, this->ticketCode);
		return id;
	}
	
	private: void saveTicketsSeats(int ticketId) {
		for (int i = 0; i < this->selectedSeats.Count; i++)
		{
			DB::saveTicketsSeat(ticketId, this->selectedSeats[i]);
		}
	}

	private: int addLoginToDb(String^ login) {
		int id = DB::addLoginToDb(login);
		return id;
	}

	private: System::Void onFormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
		Application::Exit();
	}

	private: System::Void emailTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		this->updateBuyTicketsBtn();
	}

	private: int selectedPaymentMethod = 0;
	
	private: void resetAllPayBtns() {
		this->payBtn1->FlatAppearance->BorderColor = Color::Black;
		this->payBtn1->FlatAppearance->BorderSize = 1;

		this->payBtn2->FlatAppearance->BorderColor = Color::Black;
		this->payBtn2->FlatAppearance->BorderSize = 1;

		this->payBtn3->FlatAppearance->BorderColor = Color::Black;
		this->payBtn3->FlatAppearance->BorderSize = 1;

		this->payBtn4->FlatAppearance->BorderColor = Color::Black;
		this->payBtn4->FlatAppearance->BorderSize = 1;
	}

	private: System::Void payBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		Button^ payBtn = (Button^)sender;
		String^ btnName = payBtn->Name;
		String^ paymentId = btnName->Substring(6);
		this->selectedPaymentMethod = System::Convert::ToInt32(paymentId);

		this->resetAllPayBtns();
		payBtn->FlatAppearance->BorderColor = Color::Blue;
		payBtn->FlatAppearance->BorderSize = 2;
		this->updateBuyTicketsBtn();
	}

	private: System::Void blikTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
			this->updateBuyTicketsBtn();
	}
};
}
