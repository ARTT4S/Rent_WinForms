#ifndef EDITCLIENT_H
#define EDITCLIENT_H
#include "Clients.h"

namespace ClientNamespace {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace ClientsClass;

	public ref class EditClient : public System::Windows::Forms::Form
	{
	private:
		array<Client^>^ m_Clients = gcnew array<Client^>(CLIENT_SIZE);
		int* m_quontClients;
		int m_numClient;
	public:
		EditClient(array<Client^>^ Clients, int* quontClients, int numClient)
		{
			m_Clients->Copy(Clients, m_Clients, CLIENT_SIZE);
			m_quontClients = quontClients;
			m_numClient = numClient;
			InitializeComponent();
		}
		EditClient(array<Client^>^ Clients, int numClient)
		{
			m_Clients->Copy(Clients, m_Clients, CLIENT_SIZE);
			m_numClient = numClient;
			m_quontClients = &numClient;
			InitializeComponent();
		}

	protected:
		~EditClient()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ DelClient;
	protected:
	private: System::Windows::Forms::Button^ FinishEdit;
	private: System::Windows::Forms::TextBox^ AdressTextBox;
	private: System::Windows::Forms::Label^ AdressLabel;
	private: System::Windows::Forms::TextBox^ PatronymicTextBox;
	private: System::Windows::Forms::Label^ PatronymicLabel;
	private: System::Windows::Forms::TextBox^ NameTextBox;
	private: System::Windows::Forms::Label^ NameLabel;
	private: System::Windows::Forms::TextBox^ SurnameTextBox;
	private: System::Windows::Forms::Label^ SurnameLabel;
	private: System::Windows::Forms::TextBox^ PhoneTextBox;
	private: System::Windows::Forms::Label^ PhoneLabel;
	private: System::Windows::Forms::TextBox^ DrExpTextBox;
	private: System::Windows::Forms::Label^ DrExpLabel;

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->DelClient = (gcnew System::Windows::Forms::Button());
			this->FinishEdit = (gcnew System::Windows::Forms::Button());
			this->AdressTextBox = (gcnew System::Windows::Forms::TextBox());
			this->AdressLabel = (gcnew System::Windows::Forms::Label());
			this->PatronymicTextBox = (gcnew System::Windows::Forms::TextBox());
			this->PatronymicLabel = (gcnew System::Windows::Forms::Label());
			this->NameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->NameLabel = (gcnew System::Windows::Forms::Label());
			this->SurnameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->SurnameLabel = (gcnew System::Windows::Forms::Label());
			this->PhoneTextBox = (gcnew System::Windows::Forms::TextBox());
			this->PhoneLabel = (gcnew System::Windows::Forms::Label());
			this->DrExpTextBox = (gcnew System::Windows::Forms::TextBox());
			this->DrExpLabel = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// DelClient
			// 
			this->DelClient->Cursor = System::Windows::Forms::Cursors::Hand;
			this->DelClient->Location = System::Drawing::Point(175, 302);
			this->DelClient->Name = L"DelClient";
			this->DelClient->Size = System::Drawing::Size(136, 45);
			this->DelClient->TabIndex = 19;
			this->DelClient->Text = L"Удалить запись";
			this->DelClient->UseVisualStyleBackColor = true;
			this->DelClient->Click += gcnew System::EventHandler(this, &EditClient::DelClient_Click);
			// 
			// FinishEdit
			// 
			this->FinishEdit->Cursor = System::Windows::Forms::Cursors::Hand;
			this->FinishEdit->Location = System::Drawing::Point(24, 302);
			this->FinishEdit->Name = L"FinishEdit";
			this->FinishEdit->Size = System::Drawing::Size(136, 45);
			this->FinishEdit->TabIndex = 18;
			this->FinishEdit->Text = L"Закончить редактирование";
			this->FinishEdit->UseVisualStyleBackColor = true;
			this->FinishEdit->Click += gcnew System::EventHandler(this, &EditClient::FinishEdit_Click);
			// 
			// AdressTextBox
			// 
			this->AdressTextBox->Location = System::Drawing::Point(175, 140);
			this->AdressTextBox->Name = L"AdressTextBox";
			this->AdressTextBox->Size = System::Drawing::Size(136, 22);
			this->AdressTextBox->TabIndex = 17;
			this->AdressTextBox->TextChanged += gcnew System::EventHandler(this, &EditClient::AdressTextBox_TextChanged);
			// 
			// AdressLabel
			// 
			this->AdressLabel->AutoSize = true;
			this->AdressLabel->Location = System::Drawing::Point(21, 143);
			this->AdressLabel->Name = L"AdressLabel";
			this->AdressLabel->Size = System::Drawing::Size(50, 16);
			this->AdressLabel->TabIndex = 16;
			this->AdressLabel->Text = L"Адрес:";
			// 
			// PatronymicTextBox
			// 
			this->PatronymicTextBox->Location = System::Drawing::Point(175, 100);
			this->PatronymicTextBox->Name = L"PatronymicTextBox";
			this->PatronymicTextBox->Size = System::Drawing::Size(136, 22);
			this->PatronymicTextBox->TabIndex = 15;
			this->PatronymicTextBox->TextChanged += gcnew System::EventHandler(this, &EditClient::PatronymicTextBox_TextChanged);
			// 
			// PatronymicLabel
			// 
			this->PatronymicLabel->AutoSize = true;
			this->PatronymicLabel->Location = System::Drawing::Point(21, 103);
			this->PatronymicLabel->Name = L"PatronymicLabel";
			this->PatronymicLabel->Size = System::Drawing::Size(130, 16);
			this->PatronymicLabel->TabIndex = 14;
			this->PatronymicLabel->Text = L"Отчество клиента:";
			// 
			// NameTextBox
			// 
			this->NameTextBox->Location = System::Drawing::Point(175, 60);
			this->NameTextBox->Name = L"NameTextBox";
			this->NameTextBox->Size = System::Drawing::Size(136, 22);
			this->NameTextBox->TabIndex = 13;
			this->NameTextBox->TextChanged += gcnew System::EventHandler(this, &EditClient::NameTextBox_TextChanged);
			// 
			// NameLabel
			// 
			this->NameLabel->AutoSize = true;
			this->NameLabel->Location = System::Drawing::Point(21, 63);
			this->NameLabel->Name = L"NameLabel";
			this->NameLabel->Size = System::Drawing::Size(118, 16);
			this->NameLabel->TabIndex = 12;
			this->NameLabel->Text = L"Имя автомобиля:";
			// 
			// SurnameTextBox
			// 
			this->SurnameTextBox->Location = System::Drawing::Point(175, 20);
			this->SurnameTextBox->Name = L"SurnameTextBox";
			this->SurnameTextBox->Size = System::Drawing::Size(136, 22);
			this->SurnameTextBox->TabIndex = 11;
			this->SurnameTextBox->TextChanged += gcnew System::EventHandler(this, &EditClient::SurnameTextBox_TextChanged);
			// 
			// SurnameLabel
			// 
			this->SurnameLabel->AutoSize = true;
			this->SurnameLabel->Location = System::Drawing::Point(21, 23);
			this->SurnameLabel->Name = L"SurnameLabel";
			this->SurnameLabel->Size = System::Drawing::Size(126, 16);
			this->SurnameLabel->TabIndex = 10;
			this->SurnameLabel->Text = L"Фамилия клиента:";
			// 
			// PhoneTextBox
			// 
			this->PhoneTextBox->Location = System::Drawing::Point(175, 180);
			this->PhoneTextBox->Name = L"PhoneTextBox";
			this->PhoneTextBox->Size = System::Drawing::Size(136, 22);
			this->PhoneTextBox->TabIndex = 21;
			this->PhoneTextBox->MaxLength = 11;
			this->PhoneTextBox->TextChanged += gcnew System::EventHandler(this, &EditClient::PhoneTextBox_TextChanged);
			// 
			// PhoneLabel
			// 
			this->PhoneLabel->AutoSize = true;
			this->PhoneLabel->Location = System::Drawing::Point(21, 183);
			this->PhoneLabel->Name = L"PhoneLabel";
			this->PhoneLabel->Size = System::Drawing::Size(70, 16);
			this->PhoneLabel->TabIndex = 20;
			this->PhoneLabel->Text = L"Телефон:";
			// 
			// DrExpTextBox
			// 
			this->DrExpTextBox->Location = System::Drawing::Point(175, 220);
			this->DrExpTextBox->Name = L"DrExpTextBox";
			this->DrExpTextBox->Size = System::Drawing::Size(136, 22);
			this->DrExpTextBox->TabIndex = 23;
			this->DrExpTextBox->TextChanged += gcnew System::EventHandler(this, &EditClient::DrExpTextBox_TextChanged);
			// 
			// DrExpLabel
			// 
			this->DrExpLabel->AutoSize = true;
			this->DrExpLabel->Location = System::Drawing::Point(21, 223);
			this->DrExpLabel->Name = L"DrExpLabel";
			this->DrExpLabel->Size = System::Drawing::Size(111, 16);
			this->DrExpLabel->TabIndex = 22;
			this->DrExpLabel->Text = L"Опыт вождения:";
			// 
			// EditClient
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(339, 377);
			this->Controls->Add(this->DrExpTextBox);
			this->Controls->Add(this->DrExpLabel);
			this->Controls->Add(this->PhoneTextBox);
			this->Controls->Add(this->PhoneLabel);
			this->Controls->Add(this->DelClient);
			this->Controls->Add(this->FinishEdit);
			this->Controls->Add(this->AdressTextBox);
			this->Controls->Add(this->AdressLabel);
			this->Controls->Add(this->PatronymicTextBox);
			this->Controls->Add(this->PatronymicLabel);
			this->Controls->Add(this->NameTextBox);
			this->Controls->Add(this->NameLabel);
			this->Controls->Add(this->SurnameTextBox);
			this->Controls->Add(this->SurnameLabel);
			this->Name = L"EditClient";
			this->Text = L"Клиент";
			this->Load += gcnew System::EventHandler(this, &EditClient::EditClient_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void EditClient_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void FinishEdit_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void DelClient_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void SurnameTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void NameTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void PatronymicTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void AdressTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void PhoneTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void DrExpTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e);
};
}

#endif