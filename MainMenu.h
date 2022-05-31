#ifndef MAINMENU_H
#define MAINMENU_H
#include "AutosGrid.h"
#include "ClientGrid.h"
#include "OrdersGrid.h"
#include "Autos.h"
#include "Clients.h"
#include "Orders.h"

namespace Rent {

	using namespace AutosNamespace;
	using namespace ClientNamespace;
	using namespace OrdersNamespace;
	using namespace AutosClass;
	using namespace ClientsClass;
	using namespace OrdersClass;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MainMenu : public System::Windows::Forms::Form
	{
	private:
		array<Autos^>^ m_Cars = gcnew array<Autos^>(AUTO_SIZE);
		array<Client^>^ m_Clients = gcnew array<Client^>(CLIENT_SIZE);
		array<Order^>^ m_Orders = gcnew array<Order^>(ORDER_SIZE);
		int* m_quontCars{}; 
		int* m_quontClients{};
		int* m_quontOrders{};
	public:
		MainMenu(array<Autos^>^ Cars, int* quontCars, array<Client^>^ Clients, int* quontClients, array<Order^>^ Orders, int* quontOrders)
		{
			m_Cars->Copy(Cars, m_Cars, AUTO_SIZE);
			m_quontCars = quontCars;
			m_Clients->Copy(Clients, m_Clients, CLIENT_SIZE);
			m_quontClients = quontClients;
			m_Orders->Copy(Orders, m_Orders, ORDER_SIZE);
			m_quontOrders = quontOrders;
			InitializeComponent();
		}

	protected:
		~MainMenu()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ AutoButton;
	protected:
	private: System::Windows::Forms::Button^ ClientButton;
	private: System::Windows::Forms::Button^ OrderButton;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->AutoButton = (gcnew System::Windows::Forms::Button());
			this->ClientButton = (gcnew System::Windows::Forms::Button());
			this->OrderButton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// AutoButton
			// 
			this->AutoButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->AutoButton->Location = System::Drawing::Point(80, 93);
			this->AutoButton->Name = L"AutoButton";
			this->AutoButton->Size = System::Drawing::Size(255, 88);
			this->AutoButton->TabIndex = 0;
			this->AutoButton->Text = L"Автомобили";
			this->AutoButton->UseVisualStyleBackColor = true;
			this->AutoButton->Click += gcnew System::EventHandler(this, &MainMenu::AutoButton_Click);
			// 
			// ClientButton
			// 
			this->ClientButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->ClientButton->Location = System::Drawing::Point(80, 217);
			this->ClientButton->Name = L"ClientButton";
			this->ClientButton->Size = System::Drawing::Size(255, 88);
			this->ClientButton->TabIndex = 1;
			this->ClientButton->Text = L"Клиенты";
			this->ClientButton->UseVisualStyleBackColor = true;
			this->ClientButton->Click += gcnew System::EventHandler(this, &MainMenu::ClientButton_Click);
			// 
			// OrderButton
			// 
			this->OrderButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->OrderButton->Location = System::Drawing::Point(80, 337);
			this->OrderButton->Name = L"OrderButton";
			this->OrderButton->Size = System::Drawing::Size(255, 88);
			this->OrderButton->TabIndex = 2;
			this->OrderButton->Text = L"Заказы";
			this->OrderButton->UseVisualStyleBackColor = true;
			this->OrderButton->Click += gcnew System::EventHandler(this, &MainMenu::OrderButton_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(140, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(133, 16);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Добро пожаловать.";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(131, 36);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(151, 16);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Выберите пункт меню";
			// 
			// MainMenu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(414, 478);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->OrderButton);
			this->Controls->Add(this->ClientButton);
			this->Controls->Add(this->AutoButton);
			this->Name = L"MainMenu";
			this->Text = L"Прокат автомобилей";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: System::Void AutoButton_Click(System::Object^ sender, System::EventArgs^ e) {
			AutosForm^ AutoForm = gcnew AutosForm(m_Cars, m_quontCars);
			AutoForm->Show();
		}
		private: System::Void ClientButton_Click(System::Object^ sender, System::EventArgs^ e) {
			ClientsForm^ ClientForm = gcnew ClientsForm(m_Clients, m_quontClients);
			ClientForm->Show();
		}
		private: System::Void OrderButton_Click(System::Object^ sender, System::EventArgs^ e) {
			OrdersForm^ OrderForm = gcnew OrdersForm(m_Orders, m_quontOrders, m_Cars, m_quontCars, m_Clients, m_quontClients);
			OrderForm->Show();
		}
};
}

#endif