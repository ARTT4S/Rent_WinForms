#ifndef EDITAUTO_H
#define EDITAUTO_H
#include "Autos.h"


namespace AutosNamespace {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace AutosClass;

	public ref class EditAuto : public System::Windows::Forms::Form
	{
	private:
		array<Autos^>^ m_Cars = gcnew array<Autos^>(AUTO_SIZE);
		int* m_quontCars;
		int* m_numCar;
	public:
		EditAuto(array<Autos^>^ Cars, int* quontCars, int* numCar)
		{
			m_Cars->Copy(Cars, m_Cars, AUTO_SIZE);
			m_quontCars = quontCars;
			m_numCar = numCar;

			InitializeComponent();
		}
		EditAuto(array<Autos^>^ Cars, int *numCar)
		{
			m_Cars->Copy(Cars, m_Cars, AUTO_SIZE);
			m_numCar = numCar;
			m_quontCars = numCar;
			InitializeComponent();
		}
	protected:
		~EditAuto()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ NumberLabel;
	private: System::Windows::Forms::TextBox^ NumberTextBox;
	private: System::Windows::Forms::Label^ BrandLabel;
	private: System::Windows::Forms::TextBox^ BrandTextBox;
	private: System::Windows::Forms::Label^ PriceLabel;
	private: System::Windows::Forms::TextBox^ PriceTextBox;
	private: System::Windows::Forms::Label^ TypeLabel;
	private: System::Windows::Forms::TextBox^ TypeTextBox;
	private: System::Windows::Forms::Button^ FinishEdit;
	private: System::Windows::Forms::Button^ DelAuto;


	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->NumberLabel = (gcnew System::Windows::Forms::Label());
			this->NumberTextBox = (gcnew System::Windows::Forms::TextBox());
			this->BrandLabel = (gcnew System::Windows::Forms::Label());
			this->BrandTextBox = (gcnew System::Windows::Forms::TextBox());
			this->PriceLabel = (gcnew System::Windows::Forms::Label());
			this->PriceTextBox = (gcnew System::Windows::Forms::TextBox());
			this->TypeLabel = (gcnew System::Windows::Forms::Label());
			this->TypeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->FinishEdit = (gcnew System::Windows::Forms::Button());
			this->DelAuto = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// NumberLabel
			// 
			this->NumberLabel->AutoSize = true;
			this->NumberLabel->Location = System::Drawing::Point(9, 28);
			this->NumberLabel->Name = L"NumberLabel";
			this->NumberLabel->Size = System::Drawing::Size(135, 16);
			this->NumberLabel->TabIndex = 0;
			this->NumberLabel->Text = L"Номер автомобиля:";
			// 
			// NumberTextBox
			// 
			this->NumberTextBox->Location = System::Drawing::Point(175, 25);
			this->NumberTextBox->Name = L"NumberTextBox";
			this->NumberTextBox->Size = System::Drawing::Size(136, 22);
			this->NumberTextBox->TabIndex = 1;
			this->NumberTextBox->TextChanged += gcnew System::EventHandler(this, &EditAuto::NumberTextBox_TextChanged);
			// 
			// BrandLabel
			// 
			this->BrandLabel->AutoSize = true;
			this->BrandLabel->Location = System::Drawing::Point(9, 68);
			this->BrandLabel->Name = L"BrandLabel";
			this->BrandLabel->Size = System::Drawing::Size(134, 16);
			this->BrandLabel->TabIndex = 2;
			this->BrandLabel->Text = L"Марка автомобиля:";
			// 
			// BrandTextBox
			// 
			this->BrandTextBox->Location = System::Drawing::Point(175, 65);
			this->BrandTextBox->Name = L"BrandTextBox";
			this->BrandTextBox->Size = System::Drawing::Size(136, 22);
			this->BrandTextBox->TabIndex = 3;
			this->BrandTextBox->TextChanged += gcnew System::EventHandler(this, &EditAuto::BrandTextBox_TextChanged);
			// 
			// PriceLabel
			// 
			this->PriceLabel->AutoSize = true;
			this->PriceLabel->Location = System::Drawing::Point(9, 108);
			this->PriceLabel->Name = L"PriceLabel";
			this->PriceLabel->Size = System::Drawing::Size(137, 16);
			this->PriceLabel->TabIndex = 4;
			this->PriceLabel->Text = L"Стоимость проката:";
			// 
			// PriceTextBox
			// 
			this->PriceTextBox->Location = System::Drawing::Point(175, 105);
			this->PriceTextBox->Name = L"PriceTextBox";
			this->PriceTextBox->Size = System::Drawing::Size(136, 22);
			this->PriceTextBox->TabIndex = 5;
			this->PriceTextBox->TextChanged += gcnew System::EventHandler(this, &EditAuto::PriceTextBox_TextChanged);
			// 
			// TypeLabel
			// 
			this->TypeLabel->AutoSize = true;
			this->TypeLabel->Location = System::Drawing::Point(9, 148);
			this->TypeLabel->Name = L"TypeLabel";
			this->TypeLabel->Size = System::Drawing::Size(117, 16);
			this->TypeLabel->TabIndex = 6;
			this->TypeLabel->Text = L"Тип автомобиля:";
			// 
			// TypeTextBox
			// 
			this->TypeTextBox->Location = System::Drawing::Point(175, 145);
			this->TypeTextBox->Name = L"TypeTextBox";
			this->TypeTextBox->Size = System::Drawing::Size(136, 22);
			this->TypeTextBox->TabIndex = 7;
			this->TypeTextBox->TextChanged += gcnew System::EventHandler(this, &EditAuto::TypeTextBox_TextChanged);
			// 
			// FinishEdit
			// 
			this->FinishEdit->Cursor = System::Windows::Forms::Cursors::Hand;
			this->FinishEdit->Location = System::Drawing::Point(12, 237);
			this->FinishEdit->Name = L"FinishEdit";
			this->FinishEdit->Size = System::Drawing::Size(136, 45);
			this->FinishEdit->TabIndex = 8;
			this->FinishEdit->Text = L"Закончить редактирование";
			this->FinishEdit->UseVisualStyleBackColor = true;
			this->FinishEdit->Click += gcnew System::EventHandler(this, &EditAuto::FinishEdit_Click);
			// 
			// DelAuto
			// 
			this->DelAuto->Cursor = System::Windows::Forms::Cursors::Hand;
			this->DelAuto->Location = System::Drawing::Point(175, 237);
			this->DelAuto->Name = L"DelAuto";
			this->DelAuto->Size = System::Drawing::Size(136, 45);
			this->DelAuto->TabIndex = 9;
			this->DelAuto->Text = L"Удалить запись";
			this->DelAuto->UseVisualStyleBackColor = true;
			this->DelAuto->Click += gcnew System::EventHandler(this, &EditAuto::DelAuto_Click);
			// 
			// EditAuto
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(323, 294);
			this->Controls->Add(this->DelAuto);
			this->Controls->Add(this->FinishEdit);
			this->Controls->Add(this->TypeTextBox);
			this->Controls->Add(this->TypeLabel);
			this->Controls->Add(this->PriceTextBox);
			this->Controls->Add(this->PriceLabel);
			this->Controls->Add(this->BrandTextBox);
			this->Controls->Add(this->BrandLabel);
			this->Controls->Add(this->NumberTextBox);
			this->Controls->Add(this->NumberLabel);
			this->Name = L"EditAuto";
			this->Text = L"Автомобиль";
			this->Load += gcnew System::EventHandler(this, &EditAuto::EditAuto_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void EditAuto_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void FinishEdit_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void DelAuto_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void NumberTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void BrandTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void PriceTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void TypeTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e);
};
}

#endif