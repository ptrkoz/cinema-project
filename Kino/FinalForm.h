#pragma once
#include "DB.h"
#include "User.h"

namespace Kino {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing::Imaging;
	using namespace System::IO;
	using namespace ZXing;

	public ref class FinalForm : public System::Windows::Forms::Form
	{
	public:
		FinalForm(void)
		{
			InitializeComponent();
		}

		FinalForm(String^ imageLocation, String^ movieName, String^ showDate, String^ showVersion, String^ showRoom, String^ selectedSeats, String^ ticketCode, int ticketId, int numberOfTickets, User^ user)
		{
			InitializeComponent();
			this->imageLocation = imageLocation;
			this->movieName = movieName;
			this->showDate = showDate;
			this->showVersion = showVersion;
			this->showRoom = showRoom;
			this->selectedSeats = selectedSeats;
			this->ticketCode = ticketCode;
			this->ticketId = ticketId;
			this->numberOfTickets = numberOfTickets;
			this->user = user;
		}

		FinalForm(Form^ prevForm, String^ imageLocation, String^ movieName, String^ showDate, String^ showVersion, String^ showRoom, String^ selectedSeats, String^ ticketCode, int ticketId, int numberOfTickets, User^ user)
		{
			InitializeComponent();
			this->prevForm = prevForm;
			this->imageLocation = imageLocation;
			this->movieName = movieName;
			this->showDate = showDate;
			this->showVersion = showVersion;
			this->showRoom = showRoom;
			this->selectedSeats = selectedSeats;
			this->ticketCode = ticketCode;
			this->ticketId = ticketId;
			this->numberOfTickets = numberOfTickets;
			this->user = user;
		}
	protected:
		~FinalForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
	private: Form^ prevForm = nullptr;
	private: String^ imageLocation;
	private: String^ movieName;
	private: String^ showDate;
	private: String^ showVersion;
	private: String^ showRoom;
	private: String^ showId;
	private: String^ selectedSeats;
	private: String^ ticketCode;
	private: int ticketId;
	private: int numberOfTickets;
	private: User^ user = nullptr;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ movieNameLabel;
	private: System::Windows::Forms::Label^ showDateLabel;
	private: System::Windows::Forms::Label^ showVersionLabel;
	private: System::Windows::Forms::Label^ showRoomLabel;
	private: System::Windows::Forms::Label^ numberOfTicketsLabel;
	private: System::Windows::Forms::Label^ seatsLabel;
	private: System::Windows::Forms::Label^ ticketPriceLabel;
	private: System::Windows::Forms::Label^ ticketCodeLabel;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Button^ saveQrBtn;
	private: System::Windows::Forms::Button^ returnTicketBtn;
	private: System::Windows::Forms::Button^ backBtn;










		   System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FinalForm::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->movieNameLabel = (gcnew System::Windows::Forms::Label());
			this->showDateLabel = (gcnew System::Windows::Forms::Label());
			this->showVersionLabel = (gcnew System::Windows::Forms::Label());
			this->showRoomLabel = (gcnew System::Windows::Forms::Label());
			this->numberOfTicketsLabel = (gcnew System::Windows::Forms::Label());
			this->seatsLabel = (gcnew System::Windows::Forms::Label());
			this->ticketPriceLabel = (gcnew System::Windows::Forms::Label());
			this->ticketCodeLabel = (gcnew System::Windows::Forms::Label());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->saveQrBtn = (gcnew System::Windows::Forms::Button());
			this->returnTicketBtn = (gcnew System::Windows::Forms::Button());
			this->backBtn = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold));
			this->button1->Location = System::Drawing::Point(379, 551);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(167, 43);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Powrót na strone g³ówn¹";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &FinalForm::button1_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(12, 379);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(150, 221);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// movieNameLabel
			// 
			this->movieNameLabel->AutoSize = true;
			this->movieNameLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->movieNameLabel->Location = System::Drawing::Point(180, 390);
			this->movieNameLabel->Name = L"movieNameLabel";
			this->movieNameLabel->Size = System::Drawing::Size(90, 16);
			this->movieNameLabel->TabIndex = 2;
			this->movieNameLabel->Text = L"movieName";
			// 
			// showDateLabel
			// 
			this->showDateLabel->AutoSize = true;
			this->showDateLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold));
			this->showDateLabel->Location = System::Drawing::Point(180, 419);
			this->showDateLabel->Name = L"showDateLabel";
			this->showDateLabel->Size = System::Drawing::Size(75, 16);
			this->showDateLabel->TabIndex = 3;
			this->showDateLabel->Text = L"showDate";
			// 
			// showVersionLabel
			// 
			this->showVersionLabel->AutoSize = true;
			this->showVersionLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold));
			this->showVersionLabel->Location = System::Drawing::Point(180, 449);
			this->showVersionLabel->Name = L"showVersionLabel";
			this->showVersionLabel->Size = System::Drawing::Size(95, 16);
			this->showVersionLabel->TabIndex = 4;
			this->showVersionLabel->Text = L"showVersion";
			// 
			// showRoomLabel
			// 
			this->showRoomLabel->AutoSize = true;
			this->showRoomLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold));
			this->showRoomLabel->Location = System::Drawing::Point(180, 479);
			this->showRoomLabel->Name = L"showRoomLabel";
			this->showRoomLabel->Size = System::Drawing::Size(83, 16);
			this->showRoomLabel->TabIndex = 5;
			this->showRoomLabel->Text = L"showRoom";
			// 
			// numberOfTicketsLabel
			// 
			this->numberOfTicketsLabel->AutoSize = true;
			this->numberOfTicketsLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold));
			this->numberOfTicketsLabel->Location = System::Drawing::Point(180, 509);
			this->numberOfTicketsLabel->Name = L"numberOfTicketsLabel";
			this->numberOfTicketsLabel->Size = System::Drawing::Size(124, 16);
			this->numberOfTicketsLabel->TabIndex = 6;
			this->numberOfTicketsLabel->Text = L"numberOfTickets";
			// 
			// seatsLabel
			// 
			this->seatsLabel->AutoSize = true;
			this->seatsLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold));
			this->seatsLabel->Location = System::Drawing::Point(180, 539);
			this->seatsLabel->Name = L"seatsLabel";
			this->seatsLabel->Size = System::Drawing::Size(84, 16);
			this->seatsLabel->TabIndex = 7;
			this->seatsLabel->Text = L"seatsLabel";
			// 
			// ticketPriceLabel
			// 
			this->ticketPriceLabel->AutoSize = true;
			this->ticketPriceLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold));
			this->ticketPriceLabel->Location = System::Drawing::Point(180, 572);
			this->ticketPriceLabel->Name = L"ticketPriceLabel";
			this->ticketPriceLabel->Size = System::Drawing::Size(80, 16);
			this->ticketPriceLabel->TabIndex = 8;
			this->ticketPriceLabel->Text = L"ticketPrice";
			// 
			// ticketCodeLabel
			// 
			this->ticketCodeLabel->AutoSize = true;
			this->ticketCodeLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->ticketCodeLabel->Location = System::Drawing::Point(186, 233);
			this->ticketCodeLabel->Name = L"ticketCodeLabel";
			this->ticketCodeLabel->Size = System::Drawing::Size(182, 39);
			this->ticketCodeLabel->TabIndex = 9;
			this->ticketCodeLabel->Text = L"ticketCode";
			// 
			// pictureBox2
			// 
			this->pictureBox2->Location = System::Drawing::Point(183, 12);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(200, 200);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 10;
			this->pictureBox2->TabStop = false;
			// 
			// saveQrBtn
			// 
			this->saveQrBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->saveQrBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold));
			this->saveQrBtn->Location = System::Drawing::Point(183, 292);
			this->saveQrBtn->Name = L"saveQrBtn";
			this->saveQrBtn->Size = System::Drawing::Size(200, 45);
			this->saveQrBtn->TabIndex = 11;
			this->saveQrBtn->Text = L"Zapsiz kod QR";
			this->saveQrBtn->UseVisualStyleBackColor = true;
			this->saveQrBtn->Click += gcnew System::EventHandler(this, &FinalForm::saveQrBtn_Click);
			// 
			// returnTicketBtn
			// 
			this->returnTicketBtn->BackColor = System::Drawing::Color::Maroon;
			this->returnTicketBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->returnTicketBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold));
			this->returnTicketBtn->ForeColor = System::Drawing::SystemColors::Control;
			this->returnTicketBtn->Location = System::Drawing::Point(379, 492);
			this->returnTicketBtn->Name = L"returnTicketBtn";
			this->returnTicketBtn->Size = System::Drawing::Size(167, 43);
			this->returnTicketBtn->TabIndex = 12;
			this->returnTicketBtn->Text = L"Zwróæ bilet";
			this->returnTicketBtn->UseVisualStyleBackColor = false;
			this->returnTicketBtn->Visible = false;
			this->returnTicketBtn->Click += gcnew System::EventHandler(this, &FinalForm::returnTicketBtn_Click);
			// 
			// backBtn
			// 
			this->backBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->backBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold));
			this->backBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"backBtn.Image")));
			this->backBtn->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->backBtn->Location = System::Drawing::Point(12, 12);
			this->backBtn->Name = L"backBtn";
			this->backBtn->Size = System::Drawing::Size(103, 39);
			this->backBtn->TabIndex = 13;
			this->backBtn->Text = L"   powrót";
			this->backBtn->UseVisualStyleBackColor = true;
			this->backBtn->Visible = false;
			this->backBtn->Click += gcnew System::EventHandler(this, &FinalForm::backBtn_Click);
			// 
			// FinalForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(558, 612);
			this->Controls->Add(this->backBtn);
			this->Controls->Add(this->returnTicketBtn);
			this->Controls->Add(this->saveQrBtn);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->ticketCodeLabel);
			this->Controls->Add(this->ticketPriceLabel);
			this->Controls->Add(this->seatsLabel);
			this->Controls->Add(this->numberOfTicketsLabel);
			this->Controls->Add(this->showRoomLabel);
			this->Controls->Add(this->showVersionLabel);
			this->Controls->Add(this->showDateLabel);
			this->Controls->Add(this->movieNameLabel);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"FinalForm";
			this->Text = L"Podsumowanie zamówienia - Kino";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &FinalForm::onFormClosed);
			this->Load += gcnew System::EventHandler(this, &FinalForm::FinalForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void FinalForm_Load(System::Object^ sender, System::EventArgs^ e) {
		this->CenterToScreen();
		this->pictureBox1->ImageLocation = this->imageLocation;
		this->movieNameLabel->Text = this->movieName;
		this->showDateLabel->Text = this->showDate;
		this->showVersionLabel->Text = this->showVersion;
		this->showRoomLabel->Text =  this->showRoom;
		this->numberOfTicketsLabel->Text = "Iloœæ biletów: " + this->numberOfTickets.ToString();
		this->seatsLabel->Text = "Miejsca: " + this->selectedSeats;
		this->ticketPriceLabel->Text = "Zap³acono: " + (15 * this->numberOfTickets) + " z³";
		this->ticketCodeLabel->Text = this->ticketCode;
		this->generateQrCode();
		this->setQrCodeInPictureBox();
		this->setReturnBtnVisibility();
		this->setGoBackBtnVisibility();
	}
	private: String^ ticketPath = "\images/tickets/";

	private: void generateQrCode() {
		String^ qrFileName = ticketPath + "ticket " + this->ticketCode + ".png";
		BarcodeWriter^ qrCode = gcnew BarcodeWriter;
		qrCode->Format = BarcodeFormat::QR_CODE;
		qrCode->Write(this->ticketCode)->Save(qrFileName);
	}

	private: void setQrCodeInPictureBox() {
		this->pictureBox2->ImageLocation = "\images/tickets/ticket " + this->ticketCode + ".png";
	}
	
	private: void setReturnBtnVisibility() {
		DateTime now = DateTime::Now;
		DateTime pShowDate = DateTime::Parse(this->showDate);
		if (DateTime::Compare(now, pShowDate) < 0) {
			this->returnTicketBtn->Visible = true;
		} else {
			this->returnTicketBtn->Visible = false;
		}
	}
	private: void setGoBackBtnVisibility() {
		if (this->prevForm != nullptr) {
			this->backBtn->Visible = true;
		} else {
			this->backBtn->Visible = false;
		}
	}

	private: System::Void returnTicketBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		if (MessageBox::Show("Czy napewno chcesz zwróciæ bilet?", "Zwort biletu", MessageBoxButtons::YesNo, MessageBoxIcon::Exclamation) == System::Windows::Forms::DialogResult::Yes) {
			DB::returnTicket(this->ticketId);
			if (this->prevForm != nullptr) {
				this->Hide();
				this->prevForm->Show();
			} else {
				Application::Restart();
			}
		}

	}

	private: System::Void onFormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
		Application::Exit();
	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Restart();
	}

	private: System::Void saveQrBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		SaveFileDialog^ sDialog = gcnew SaveFileDialog;
		sDialog->Filter = "PNG|*.png|JPG|*.jpg";
		String^ prefix = "";
		if (this->numberOfTickets == 1) {
			prefix = "Bilet ";
		} else {
			prefix = "Bilety ";
		}
		String^ sufix = this->showDate->Split(' ')[0];
		sDialog->FileName = prefix + this->movieName + " " + sufix + ".png";
		ImageFormat^ sFormat = ImageFormat::Png;
		if (sDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			String^ ext = Path::GetExtension(sDialog->FileName);
			if (ext == ".jpg") { // zmiana formatu zdjecia jesli tak wybral uzytkownik
				sFormat = ImageFormat::Jpeg;
			}
			pictureBox2->Image->Save(sDialog->FileName, sFormat);
		}
	}

	private: System::Void backBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		this->prevForm->Show();
	}
};
}
