#ifndef EDITORDER_H
#define EDITORDER_H
#include "Orders.h"

namespace OrdersNamespace {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace OrdersClass;

	/// <summary>
	/// Сводка для EditOrder
	/// </summary>
	public ref class EditOrder : public System::Windows::Forms::Form
	{
	private:
		array<Order^>^ m_Orders = gcnew array<Order^>(ORDER_SIZE);
		int* m_quontOrders;
		int* m_numOrder;
	private: System::Windows::Forms::TextBox^ PhoneTextBox;
	private: System::Windows::Forms::Label^ PhoneLabel;
	private: System::Windows::Forms::TextBox^ CarnumberTextBox;
	private: System::Windows::Forms::Label^ CarnumberLabel;
	private: System::Windows::Forms::DateTimePicker^ DateChoise;
	private: System::Windows::Forms::Label^ DateLabel;
	private: System::Windows::Forms::Label^ BackDateLabel;
	private: System::Windows::Forms::DateTimePicker^ BackDateChoise;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	public:
		EditOrder(array<Order^>^ Orders, int* quontOrders, int* numOrder)
		{
			m_Orders->Copy(Orders, m_Orders, ORDER_SIZE);
			m_quontOrders = quontOrders;
			m_numOrder = numOrder;
			InitializeComponent();
		}
		EditOrder(array<Order^>^ Orders, int* numOrder)
		{
			m_Orders->Copy(Orders, m_Orders, ORDER_SIZE);
			m_numOrder = numOrder;
			m_quontOrders = m_numOrder;
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
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// PhoneTextBox
			// 
			this->PhoneTextBox->Location = System::Drawing::Point(173, 58);
			this->PhoneTextBox->Name = L"PhoneTextBox";
			this->PhoneTextBox->Size = System::Drawing::Size(136, 22);
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
			this->CarnumberTextBox->Location = System::Drawing::Point(173, 18);
			this->CarnumberTextBox->Name = L"CarnumberTextBox";
			this->CarnumberTextBox->Size = System::Drawing::Size(136, 22);
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
			this->DateChoise->Location = System::Drawing::Point(143, 96);
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
			this->BackDateChoise->Location = System::Drawing::Point(143, 136);
			this->BackDateChoise->Name = L"BackDateChoise";
			this->BackDateChoise->Size = System::Drawing::Size(169, 22);
			this->BackDateChoise->TabIndex = 10;
			this->BackDateChoise->ValueChanged += gcnew System::EventHandler(this, &EditOrder::BackDateChoise_ValueChanged);
			// 
			// button2
			// 
			this->button2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button2->Location = System::Drawing::Point(173, 213);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(136, 45);
			this->button2->TabIndex = 13;
			this->button2->Text = L"Удалить запись";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &EditOrder::button2_Click);
			// 
			// button1
			// 
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->Location = System::Drawing::Point(22, 213);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(136, 45);
			this->button1->TabIndex = 12;
			this->button1->Text = L"Закончить редактирование";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &EditOrder::button1_Click);
			// 
			// EditOrder
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(331, 283);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
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
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
};
}

#endif