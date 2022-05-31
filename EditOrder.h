#ifndef EDITORDER_H
#define EDITORDER_H
#include "Orders.h"
#include "Autos.h"
#include "Clients.h"

namespace OrdersNamespace {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace OrdersClass;
	using namespace AutosClass;
	using namespace ClientsClass;

	/// <summary>
	/// Сводка для EditOrder
	/// </summary>
	public ref class EditOrder : public System::Windows::Forms::Form
	{
	private:
		array<Order^>^ m_Orders = gcnew array<Order^>(ORDER_SIZE);
		int* m_quontOrders;
		array<Client^>^ m_Clients = gcnew array<Client^>(CLIENT_SIZE);
		array<Autos^>^ m_Cars = gcnew array<Autos^>(AUTO_SIZE);
		int* m_quontCars;
		int* m_quontClients;
		int m_numOrder;
	private: System::Windows::Forms::TextBox^ PhoneTextBox;
	private: System::Windows::Forms::Label^ PhoneLabel;
	private: System::Windows::Forms::TextBox^ CarnumberTextBox;
	private: System::Windows::Forms::Label^ CarnumberLabel;
	private: System::Windows::Forms::DateTimePicker^ DateChoise;
	private: System::Windows::Forms::Label^ DateLabel;
	private: System::Windows::Forms::Label^ BackDateLabel;
	private: System::Windows::Forms::DateTimePicker^ BackDateChoise;
	private: System::Windows::Forms::Button^ DelOrder;
	private: System::Windows::Forms::Button^ Stat;
	private: System::Windows::Forms::Button^ FinishEditting;
	public:
		EditOrder(array<Order^>^ Orders, int* quontOrders, array<Autos^>^ Cars, int* quontCars, array<Client^>^ Clients, int* quontClients, int numOrder)
		{
			m_Orders->Copy(Orders, m_Orders, ORDER_SIZE);
			m_quontOrders = quontOrders;
			m_Cars->Copy(Cars, m_Cars, AUTO_SIZE);
			m_quontCars = quontCars;
			m_Clients->Copy(Clients, m_Clients, CLIENT_SIZE);
			m_quontClients = quontClients;
			m_numOrder = numOrder;
			InitializeComponent();
		}
		EditOrder(array<Order^>^ Orders, array<Autos^>^ Cars, int* quontCars, array<Client^>^ Clients, int* quontClients, int numOrder)
		{
			m_Orders->Copy(Orders, m_Orders, ORDER_SIZE);
			m_numOrder = numOrder;
			m_Cars->Copy(Cars, m_Cars, AUTO_SIZE);
			m_quontCars = quontCars;
			m_Clients->Copy(Clients, m_Clients, CLIENT_SIZE);
			m_quontClients = quontClients;
			m_quontOrders = &numOrder;
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~EditOrder()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->PhoneTextBox = (gcnew System::Windows::Forms::TextBox());
			this->PhoneLabel = (gcnew System::Windows::Forms::Label());
			this->CarnumberTextBox = (gcnew System::Windows::Forms::TextBox());
			this->CarnumberLabel = (gcnew System::Windows::Forms::Label());
			this->DateChoise = (gcnew System::Windows::Forms::DateTimePicker());
			this->DateLabel = (gcnew System::Windows::Forms::Label());
			this->BackDateLabel = (gcnew System::Windows::Forms::Label());
			this->BackDateChoise = (gcnew System::Windows::Forms::DateTimePicker());
			this->DelOrder = (gcnew System::Windows::Forms::Button());
			this->FinishEditting = (gcnew System::Windows::Forms::Button());
			this->Stat = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// PhoneTextBox
			// 
			this->PhoneTextBox->Location = System::Drawing::Point(192, 58);
			this->PhoneTextBox->Name = L"PhoneTextBox";
			this->PhoneTextBox->Size = System::Drawing::Size(169, 22);
			this->PhoneTextBox->TabIndex = 7;
			this->PhoneTextBox->TextChanged += gcnew System::EventHandler(this, &EditOrder::PhoneTextBox_TextChanged);
			// 
			// PhoneLabel
			// 
			this->PhoneLabel->AutoSize = true;
			this->PhoneLabel->Location = System::Drawing::Point(12, 61);
			this->PhoneLabel->Name = L"PhoneLabel";
			this->PhoneLabel->Size = System::Drawing::Size(127, 16);
			this->PhoneLabel->TabIndex = 6;
			this->PhoneLabel->Text = L"Телефон клиента:";
			// 
			// CarnumberTextBox
			// 
			this->CarnumberTextBox->Location = System::Drawing::Point(192, 18);
			this->CarnumberTextBox->Name = L"CarnumberTextBox";
			this->CarnumberTextBox->Size = System::Drawing::Size(169, 22);
			this->CarnumberTextBox->TabIndex = 5;
			this->CarnumberTextBox->TextChanged += gcnew System::EventHandler(this, &EditOrder::CarnumberTextBox_TextChanged);
			// 
			// CarnumberLabel
			// 
			this->CarnumberLabel->AutoSize = true;
			this->CarnumberLabel->Location = System::Drawing::Point(12, 21);
			this->CarnumberLabel->Name = L"CarnumberLabel";
			this->CarnumberLabel->Size = System::Drawing::Size(135, 16);
			this->CarnumberLabel->TabIndex = 4;
			this->CarnumberLabel->Text = L"Номер автомобиля:";
			// 
			// DateChoise
			// 
			this->DateChoise->Location = System::Drawing::Point(192, 96);
			this->DateChoise->Name = L"DateChoise";
			this->DateChoise->Size = System::Drawing::Size(169, 22);
			this->DateChoise->TabIndex = 8;
			this->DateChoise->ValueChanged += gcnew System::EventHandler(this, &EditOrder::DateChoise_ValueChanged);
			// 
			// DateLabel
			// 
			this->DateLabel->AutoSize = true;
			this->DateLabel->Location = System::Drawing::Point(12, 101);
			this->DateLabel->Name = L"DateLabel";
			this->DateLabel->Size = System::Drawing::Size(92, 16);
			this->DateLabel->TabIndex = 9;
			this->DateLabel->Text = L"Дата заказа:";
			// 
			// BackDateLabel
			// 
			this->BackDateLabel->AutoSize = true;
			this->BackDateLabel->Location = System::Drawing::Point(12, 141);
			this->BackDateLabel->Name = L"BackDateLabel";
			this->BackDateLabel->Size = System::Drawing::Size(108, 16);
			this->BackDateLabel->TabIndex = 11;
			this->BackDateLabel->Text = L"Дата возврата:";
			// 
			// BackDateChoise
			// 
			this->BackDateChoise->Location = System::Drawing::Point(192, 136);
			this->BackDateChoise->Name = L"BackDateChoise";
			this->BackDateChoise->Size = System::Drawing::Size(169, 22);
			this->BackDateChoise->TabIndex = 10;
			this->BackDateChoise->ValueChanged += gcnew System::EventHandler(this, &EditOrder::BackDateChoise_ValueChanged);
			// 
			// DelOrder
			// 
			this->DelOrder->Cursor = System::Windows::Forms::Cursors::Hand;
			this->DelOrder->Location = System::Drawing::Point(270, 226);
			this->DelOrder->Name = L"DelOrder";
			this->DelOrder->Size = System::Drawing::Size(91, 45);
			this->DelOrder->TabIndex = 13;
			this->DelOrder->Text = L"Удалить запись";
			this->DelOrder->UseVisualStyleBackColor = true;
			this->DelOrder->Click += gcnew System::EventHandler(this, &EditOrder::DelOrder_Click);
			// 
			// FinishEditting
			// 
			this->FinishEditting->Cursor = System::Windows::Forms::Cursors::Hand;
			this->FinishEditting->Location = System::Drawing::Point(12, 226);
			this->FinishEditting->Name = L"FinishEditting";
			this->FinishEditting->Size = System::Drawing::Size(125, 45);
			this->FinishEditting->TabIndex = 12;
			this->FinishEditting->Text = L"Закончить редактирование";
			this->FinishEditting->UseVisualStyleBackColor = true;
			this->FinishEditting->Click += gcnew System::EventHandler(this, &EditOrder::FinishEditting_Click);
			// 
			// Stat
			// 
			this->Stat->Location = System::Drawing::Point(158, 226);
			this->Stat->Name = L"Stat";
			this->Stat->Size = System::Drawing::Size(93, 45);
			this->Stat->TabIndex = 14;
			this->Stat->Text = L"Статистика";
			this->Stat->UseVisualStyleBackColor = true;
			this->Stat->Click += gcnew System::EventHandler(this, &EditOrder::Stat_Click);
			// 
			// EditOrder
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(373, 283);
			this->Controls->Add(this->Stat);
			this->Controls->Add(this->DelOrder);
			this->Controls->Add(this->FinishEditting);
			this->Controls->Add(this->BackDateLabel);
			this->Controls->Add(this->BackDateChoise);
			this->Controls->Add(this->DateLabel);
			this->Controls->Add(this->DateChoise);
			this->Controls->Add(this->PhoneTextBox);
			this->Controls->Add(this->PhoneLabel);
			this->Controls->Add(this->CarnumberTextBox);
			this->Controls->Add(this->CarnumberLabel);
			this->Name = L"EditOrder";
			this->Text = L"Заказ";
			this->Load += gcnew System::EventHandler(this, &EditOrder::EditOrder_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void EditOrder_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void DateChoise_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void BackDateChoise_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void CarnumberTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void PhoneTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void FinishEditting_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void DelOrder_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Stat_Click(System::Object^ sender, System::EventArgs^ e);
};
}

#endif