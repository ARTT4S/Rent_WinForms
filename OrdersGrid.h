#ifndef ORDERSGRID_H
#define ORDERSGRID_H
#include "Orders.h"
#include "EditOrder.h"

namespace OrdersNamespace {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace OrdersClass;

	public ref class OrdersForm : public System::Windows::Forms::Form
	{
	private:
		   array<Order^>^ m_Orders = gcnew array<Order^>(ORDER_SIZE);
		   EditOrder^ EditOrders;
		   int* m_quontOrders;
	public:
		OrdersForm(array<Order^>^ Orders, int* quontOrders)
		{
			m_Orders->Copy(Orders, m_Orders, ORDER_SIZE);
			m_quontOrders = quontOrders;
			InitializeComponent();
		}

	protected:
		~OrdersForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ OrdersGrid;
	protected:
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Number;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Carnumber;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Phone;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ OrderDate;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ BackDate;
	private: System::Windows::Forms::Button^ FileOut;
	private: System::Windows::Forms::Button^ FileIn;
	private: System::Windows::Forms::Button^ AddClient;
	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->OrdersGrid = (gcnew System::Windows::Forms::DataGridView());
			this->Number = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Carnumber = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Phone = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->OrderDate = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->BackDate = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->FileOut = (gcnew System::Windows::Forms::Button());
			this->FileIn = (gcnew System::Windows::Forms::Button());
			this->AddClient = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->OrdersGrid))->BeginInit();
			this->SuspendLayout();
			// 
			// OrdersGrid
			// 
			this->OrdersGrid->AllowUserToAddRows = false;
			this->OrdersGrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->OrdersGrid->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->Number, this->Carnumber,
					this->Phone, this->OrderDate, this->BackDate
			});
			this->OrdersGrid->Cursor = System::Windows::Forms::Cursors::Hand;
			this->OrdersGrid->Location = System::Drawing::Point(12, 12);
			this->OrdersGrid->Name = L"OrdersGrid";
			this->OrdersGrid->RowHeadersWidth = 51;
			this->OrdersGrid->RowTemplate->Height = 24;
			this->OrdersGrid->Size = System::Drawing::Size(789, 240);
			this->OrdersGrid->TabIndex = 0;
			this->OrdersGrid->CellDoubleClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &OrdersForm::OrdersGrid_CellDoubleClick);
			// 
			// Number
			// 
			this->Number->HeaderText = L"№";
			this->Number->MinimumWidth = 6;
			this->Number->Name = L"Number";
			this->Number->Width = 40;
			// 
			// Carnumber
			// 
			this->Carnumber->HeaderText = L"Номер автомобиля";
			this->Carnumber->MinimumWidth = 6;
			this->Carnumber->Name = L"Carnumber";
			this->Carnumber->Width = 125;
			// 
			// Phone
			// 
			this->Phone->HeaderText = L"Телефон клиента";
			this->Phone->MinimumWidth = 6;
			this->Phone->Name = L"Phone";
			this->Phone->Width = 125;
			// 
			// OrderDate
			// 
			this->OrderDate->HeaderText = L"Дата заказа";
			this->OrderDate->MinimumWidth = 6;
			this->OrderDate->Name = L"OrderDate";
			this->OrderDate->Width = 125;
			// 
			// BackDate
			// 
			this->BackDate->HeaderText = L"Дата возврата";
			this->BackDate->MinimumWidth = 6;
			this->BackDate->Name = L"BackDate";
			this->BackDate->Width = 125;
			// 
			// FileOut
			// 
			this->FileOut->Cursor = System::Windows::Forms::Cursors::Hand;
			this->FileOut->Location = System::Drawing::Point(871, 125);
			this->FileOut->Name = L"FileOut";
			this->FileOut->Size = System::Drawing::Size(99, 43);
			this->FileOut->TabIndex = 9;
			this->FileOut->Text = L"Выгрузить в файл";
			this->FileOut->UseVisualStyleBackColor = true;
			// 
			// FileIn
			// 
			this->FileIn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->FileIn->Location = System::Drawing::Point(871, 62);
			this->FileIn->Name = L"FileIn";
			this->FileIn->Size = System::Drawing::Size(99, 44);
			this->FileIn->TabIndex = 8;
			this->FileIn->Text = L"Загрузить из файла";
			this->FileIn->UseVisualStyleBackColor = true;
			// 
			// AddClient
			// 
			this->AddClient->Cursor = System::Windows::Forms::Cursors::Hand;
			this->AddClient->ForeColor = System::Drawing::SystemColors::ControlText;
			this->AddClient->Location = System::Drawing::Point(871, 12);
			this->AddClient->Name = L"AddClient";
			this->AddClient->Size = System::Drawing::Size(99, 31);
			this->AddClient->TabIndex = 7;
			this->AddClient->Text = L"Добавить";
			this->AddClient->UseVisualStyleBackColor = true;
			this->AddClient->Click += gcnew System::EventHandler(this, &OrdersForm::AddClient_Click);
			// 
			// OrdersForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(996, 329);
			this->Controls->Add(this->FileOut);
			this->Controls->Add(this->FileIn);
			this->Controls->Add(this->AddClient);
			this->Controls->Add(this->OrdersGrid);
			this->Name = L"OrdersForm";
			this->Text = L"Заказы";
			this->Activated += gcnew System::EventHandler(this, &OrdersForm::OrdersForm_Activated);
			this->Load += gcnew System::EventHandler(this, &OrdersForm::OrdersForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->OrdersGrid))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void OrdersForm_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void OrdersForm_Activated(System::Object^ sender, System::EventArgs^ e);
	private: System::Void OrdersGrid_CellDoubleClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
	private: System::Void AddClient_Click(System::Object^ sender, System::EventArgs^ e);
};
}

#endif