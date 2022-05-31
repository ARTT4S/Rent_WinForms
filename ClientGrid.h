#ifndef CLIENTGRID_H
#define CLIENTGRID_H
#include "Clients.h"
#include "EditClient.h"

namespace ClientNamespace {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace ClientsClass;

	public ref class ClientsForm : public System::Windows::Forms::Form
	{
	private:
		array<Client^>^ m_Clients = gcnew array<Client^>(CLIENT_SIZE);
		EditClient^ EditClients;
		int* m_quontClients;
	public:
		ClientsForm(array<Client^>^ Clients, int* quontClients)
		{
			m_Clients->Copy(Clients, m_Clients, CLIENT_SIZE);
			m_quontClients = quontClients;
			InitializeComponent();
		}

	protected:
		~ClientsForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ ClientGrid;
	protected:
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Number;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Surname;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Name;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Patronymic;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Adress;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Phone;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ DrExp;
	private: System::Windows::Forms::Button^ FileOut;
	private: System::Windows::Forms::Button^ FileIn;
	private: System::Windows::Forms::Button^ AddClient;
	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->ClientGrid = (gcnew System::Windows::Forms::DataGridView());
			this->Number = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Surname = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Name = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Patronymic = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Adress = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Phone = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->DrExp = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->FileOut = (gcnew System::Windows::Forms::Button());
			this->FileIn = (gcnew System::Windows::Forms::Button());
			this->AddClient = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ClientGrid))->BeginInit();
			this->SuspendLayout();
			// 
			// ClientGrid
			// 
			this->ClientGrid->AllowUserToAddRows = false;
			this->ClientGrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->ClientGrid->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(7) {
				this->Number, this->Surname,
					this->Name, this->Patronymic, this->Adress, this->Phone, this->DrExp
			});
			this->ClientGrid->Location = System::Drawing::Point(12, 12);
			this->ClientGrid->Name = L"ClientGrid";
			this->ClientGrid->RowHeadersWidth = 51;
			this->ClientGrid->RowTemplate->Height = 24;
			this->ClientGrid->Size = System::Drawing::Size(991, 254);
			this->ClientGrid->TabIndex = 0;
			this->ClientGrid->CellDoubleClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &ClientsForm::ClientGrid_CellDoubleClick);
			// 
			// Number
			// 
			this->Number->HeaderText = L"№";
			this->Number->MinimumWidth = 6;
			this->Number->Name = L"Number";
			this->Number->Width = 40;
			// 
			// Surname
			// 
			this->Surname->HeaderText = L"Фамилия";
			this->Surname->MinimumWidth = 6;
			this->Surname->Name = L"Surname";
			this->Surname->Width = 80;
			// 
			// Name
			// 
			this->Name->HeaderText = L"Имя";
			this->Name->MinimumWidth = 6;
			this->Name->Name = L"Name";
			this->Name->Width = 80;
			// 
			// Patronymic
			// 
			this->Patronymic->HeaderText = L"Отчество";
			this->Patronymic->MinimumWidth = 6;
			this->Patronymic->Name = L"Patronymic";
			this->Patronymic->Width = 90;
			// 
			// Adress
			// 
			this->Adress->HeaderText = L"Адрес";
			this->Adress->MinimumWidth = 6;
			this->Adress->Name = L"Adress";
			this->Adress->Width = 150;
			// 
			// Phone
			// 
			this->Phone->HeaderText = L"Телефон";
			this->Phone->MinimumWidth = 6;
			this->Phone->Name = L"Phone";
			this->Phone->Width = 90;
			// 
			// DrExp
			// 
			this->DrExp->HeaderText = L"Стаж вождения";
			this->DrExp->MinimumWidth = 6;
			this->DrExp->Name = L"DrExp";
			this->DrExp->Width = 160;
			// 
			// FileOut
			// 
			this->FileOut->Cursor = System::Windows::Forms::Cursors::Hand;
			this->FileOut->Location = System::Drawing::Point(1043, 117);
			this->FileOut->Name = L"FileOut";
			this->FileOut->Size = System::Drawing::Size(104, 43);
			this->FileOut->TabIndex = 6;
			this->FileOut->Text = L"Выгрузить в файл";
			this->FileOut->UseVisualStyleBackColor = true;
			// 
			// FileIn
			// 
			this->FileIn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->FileIn->Location = System::Drawing::Point(1043, 58);
			this->FileIn->Name = L"FileIn";
			this->FileIn->Size = System::Drawing::Size(104, 44);
			this->FileIn->TabIndex = 5;
			this->FileIn->Text = L"Загрузить из файла";
			this->FileIn->UseVisualStyleBackColor = true;
			// 
			// AddClient
			// 
			this->AddClient->Cursor = System::Windows::Forms::Cursors::Hand;
			this->AddClient->ForeColor = System::Drawing::SystemColors::ControlText;
			this->AddClient->Location = System::Drawing::Point(1043, 12);
			this->AddClient->Name = L"AddClient";
			this->AddClient->Size = System::Drawing::Size(104, 31);
			this->AddClient->TabIndex = 4;
			this->AddClient->Text = L"Добавить";
			this->AddClient->UseVisualStyleBackColor = true;
			this->AddClient->Click += gcnew System::EventHandler(this, &ClientsForm::AddClient_Click);
			// 
			// ClientsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1176, 371);
			this->Controls->Add(this->FileOut);
			this->Controls->Add(this->FileIn);
			this->Controls->Add(this->AddClient);
			this->Controls->Add(this->ClientGrid);
			this->Cursor = System::Windows::Forms::Cursors::Hand;
			//this->Name = L"ClientsForm";
			this->Text = L"Клиенты";
			this->Activated += gcnew System::EventHandler(this, &ClientsForm::ClientsForm_Activated);
			this->Load += gcnew System::EventHandler(this, &ClientsForm::ClientsForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ClientGrid))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		private: System::Void ClientsForm_Activated(System::Object^ sender, System::EventArgs^ e);
		private: System::Void ClientsForm_Load(System::Object^ sender, System::EventArgs^ e);
		private: System::Void ClientGrid_CellDoubleClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
		private: System::Void AddClient_Click(System::Object^ sender, System::EventArgs^ e);
};
}

#endif