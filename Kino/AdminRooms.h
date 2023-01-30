#pragma once
#include "DB.h"
#include "EditRoom.h"

namespace Kino {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class AdminRooms : public System::Windows::Forms::Form
	{
	public:
		AdminRooms(void)
		{
			InitializeComponent();
		}
		AdminRooms(Form^ prevForm)
		{
			InitializeComponent();
			this->prevForm = prevForm;
		}
	protected:
		~AdminRooms()
		{
			if (components)
			{
				delete components;
			}
		}

	private: Form^ prevForm;
	private: System::Windows::Forms::Button^ goBackBtn;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;
	private: System::Windows::Forms::Button^ addRoomBtn;

	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AdminRooms::typeid));
			this->goBackBtn = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->addRoomBtn = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// goBackBtn
			// 
			this->goBackBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->goBackBtn->Font = (gcnew System::Drawing::Font(L"Corbel", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->goBackBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"goBackBtn.Image")));
			this->goBackBtn->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->goBackBtn->Location = System::Drawing::Point(12, 29);
			this->goBackBtn->Name = L"goBackBtn";
			this->goBackBtn->Size = System::Drawing::Size(115, 45);
			this->goBackBtn->TabIndex = 0;
			this->goBackBtn->Text = L"    powrót";
			this->goBackBtn->UseVisualStyleBackColor = true;
			this->goBackBtn->Click += gcnew System::EventHandler(this, &AdminRooms::goBackBtn_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Corbel", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->Location = System::Drawing::Point(220, 29);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(88, 45);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Sale";
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->AutoScroll = true;
			this->flowLayoutPanel1->Location = System::Drawing::Point(12, 98);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(500, 350);
			this->flowLayoutPanel1->TabIndex = 2;
			// 
			// addRoomBtn
			// 
			this->addRoomBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->addRoomBtn->Font = (gcnew System::Drawing::Font(L"Corbel", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->addRoomBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"addRoomBtn.Image")));
			this->addRoomBtn->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->addRoomBtn->Location = System::Drawing::Point(393, 29);
			this->addRoomBtn->Name = L"addRoomBtn";
			this->addRoomBtn->Size = System::Drawing::Size(119, 45);
			this->addRoomBtn->TabIndex = 3;
			this->addRoomBtn->Text = L"Dodaj sale";
			this->addRoomBtn->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->addRoomBtn->UseVisualStyleBackColor = true;
			this->addRoomBtn->Click += gcnew System::EventHandler(this, &AdminRooms::addRoomBtn_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(26, -76);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(240, 150);
			this->dataGridView1->TabIndex = 4;
			this->dataGridView1->Visible = false;
			// 
			// AdminRooms
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(524, 460);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->addRoomBtn);
			this->Controls->Add(this->flowLayoutPanel1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->goBackBtn);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"AdminRooms";
			this->Text = L"Zarz¹dzaj salami - Kino";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &AdminRooms::onFormClosed);
			this->Load += gcnew System::EventHandler(this, &AdminRooms::AdminRooms_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: int roomNumber;

	private: System::Void AdminRooms_Load(System::Object^ sender, System::EventArgs^ e) {
		this->CenterToScreen();
		this->loadRooms();
	}

	private: void loadRooms() {
		this->flowLayoutPanel1->Controls->Clear();
		this->dataGridView1->DataSource = DB::getRooms();
		this->roomNumber = this->dataGridView1->RowCount - 1;
		for (int i = 0; i < this->roomNumber; i++)
		{
			Panel^ roomPanel = gcnew Panel;
			this->flowLayoutPanel1->Controls->Add(roomPanel);
			roomPanel->Location = System::Drawing::Point(3, 3 + (40 * i));
			String^ panelName = "roomPanel" + i.ToString();
			roomPanel->Name = panelName;
			roomPanel->Size = System::Drawing::Size(400, 75);

			Label^ roomNameLabel = gcnew Label;
			roomPanel->Controls->Add(roomNameLabel);
			roomNameLabel->AutoSize = true;
			roomNameLabel->Font = (gcnew System::Drawing::Font(L"Corbel", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			roomNameLabel->Location = System::Drawing::Point(3, 3);
			String^ roomNameLabelName = "roomNameLabel" + i.ToString();
			roomNameLabel->Name = roomNameLabelName;
			roomNameLabel->Size = System::Drawing::Size(252, 25);
			String^ roomNameLabelText = this->dataGridView1[1, i]->Value->ToString();
			roomNameLabel->Text = roomNameLabelText;

			Button^ editBtn = gcnew Button();
			roomPanel->Controls->Add(editBtn);
			editBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			editBtn->Location = System::Drawing::Point(10, 40);
			String^ roomId = this->dataGridView1[0, i]->Value->ToString();
			String^ editBtnName = "editBtn" + roomId;
			editBtn->Name = editBtnName;
			editBtn->Size = System::Drawing::Size(60, 30);
			editBtn->Text = "Edytuj";
			editBtn->Click += gcnew System::EventHandler(this, &AdminRooms::editBtnClick);
		
			Button^ deleteBtn = gcnew Button();
			roomPanel->Controls->Add(deleteBtn);
			deleteBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			deleteBtn->Location = System::Drawing::Point(75, 40);
			String^ deleteBtnName = "deleteBtn" + roomId;
			deleteBtn->Name = deleteBtnName;
			deleteBtn->Size = System::Drawing::Size(60, 30);
			deleteBtn->Text = "Usuñ";
			deleteBtn->Click += gcnew System::EventHandler(this, &AdminRooms::deleteBtnClick);
		}
	}

	private: System::Void editBtnClick(System::Object^ sender, System::EventArgs^ e) {
		Button^ clickedBtn = (Button^)sender;
		String^ btnName = clickedBtn->Name;
		int roomId = int::Parse(btnName->Substring(7));
		EditRoom^ editRoom = gcnew EditRoom(roomId);
		editRoom->ShowDialog();
		this->loadRooms();
	}

	private: System::Void deleteBtnClick(System::Object^ sender, System::EventArgs^ e) {
		Button^ clickedBtn = (Button^)sender;
		String^ btnName = clickedBtn->Name;
		int roomId = int::Parse(btnName->Substring(9));
		if (DB::willBeAShowInRoom(roomId) == false) {
			DB::deleteRoom(roomId);
			this->loadRooms();
		}
		else {
			MessageBox::Show("Nie mo¿na usun¹æ sali, w której zaplanowany jest seans.", "Tej sali nie mo¿na usun¹æ", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	private: System::Void goBackBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		this->prevForm->Show();
	}

	private: System::Void onFormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
		Application::Exit();
	}
private: System::Void addRoomBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	EditRoom^ editRoom = gcnew EditRoom;
	editRoom->ShowDialog();
	this->loadRooms();
}
};
}
