#ifndef AUTOSGRID_H
#define AUTOSGRID_H
#include "Autos.h"
#include "EditAuto.h"
#include "Func.h"

namespace AutosNamespace {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace AutosClass;
	using namespace functions;
	
	public ref class AutosForm : public System::Windows::Forms::Form
	{
	
	private:
		array<Autos^>^ m_Cars = gcnew array<Autos^>(AUTO_SIZE);
		EditAuto^ EditCars;
		int* m_quontCars;
	public:
		AutosForm(array<Autos^>^ Cars, int* quontCars)
		{
			m_Cars->Copy(Cars, m_Cars, AUTO_SIZE);
			m_quontCars = quontCars;
			InitializeComponent();
		}

	protected:
		~AutosForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ AutosGrid;
	protected:
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Number;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ AutoNum;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Type;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Brand;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Price;
	private: System::Windows::Forms::Button^ AddAuto;
	private: System::Windows::Forms::Button^ FileIn;
	private: System::Windows::Forms::Button^ FileOut;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->AutosGrid = (gcnew System::Windows::Forms::DataGridView());
			this->Number = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->AutoNum = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Brand = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Price = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Type = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->AddAuto = (gcnew System::Windows::Forms::Button());
			this->FileIn = (gcnew System::Windows::Forms::Button());
			this->FileOut = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->AutosGrid))->BeginInit();
			this->SuspendLayout();
			// 
			// AutosGrid
			// 
			this->AutosGrid->AllowUserToAddRows = false;
			this->AutosGrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->AutosGrid->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->Number, this->AutoNum,
					this->Brand, this->Price, this->Type
			});
			this->AutosGrid->Cursor = System::Windows::Forms::Cursors::Hand;
			this->AutosGrid->Location = System::Drawing::Point(12, 12);
			this->AutosGrid->Name = L"AutosGrid";
			this->AutosGrid->RowHeadersWidth = 51;
			this->AutosGrid->RowTemplate->Height = 24;
			this->AutosGrid->Size = System::Drawing::Size(756, 206);
			this->AutosGrid->TabIndex = 0;
			this->AutosGrid->CellDoubleClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &AutosForm::AutosGrid_CellDoubleClick);
			// 
			// Number
			// 
			this->Number->HeaderText = L"№";
			this->Number->MinimumWidth = 6;
			this->Number->Name = L"Number";
			this->Number->Width = 40;
			// 
			// AutoNum
			// 
			this->AutoNum->HeaderText = L"Номер";
			this->AutoNum->MinimumWidth = 6;
			this->AutoNum->Name = L"AutoNum";
			this->AutoNum->Width = 60;
			// 
			// Brand
			// 
			this->Brand->HeaderText = L"Марка";
			this->Brand->MinimumWidth = 6;
			this->Brand->Name = L"Brand";
			this->Brand->Width = 125;
			// 
			// Price
			// 
			this->Price->HeaderText = L"Стоимость проката";
			this->Price->MinimumWidth = 6;
			this->Price->Name = L"Price";
			this->Price->Width = 165;
			// 
			// Type
			// 
			this->Type->HeaderText = L"Тип";
			this->Type->MinimumWidth = 6;
			this->Type->Name = L"Type";
			this->Type->Width = 125;
			// 
			// AddAuto
			// 
			this->AddAuto->Cursor = System::Windows::Forms::Cursors::Hand;
			this->AddAuto->ForeColor = System::Drawing::SystemColors::ControlText;
			this->AddAuto->Location = System::Drawing::Point(840, 12);
			this->AddAuto->Name = L"AddAuto";
			this->AddAuto->Size = System::Drawing::Size(105, 31);
			this->AddAuto->TabIndex = 1;
			this->AddAuto->Text = L"Добавить";
			this->AddAuto->UseVisualStyleBackColor = true;
			this->AddAuto->Click += gcnew System::EventHandler(this, &AutosForm::AddAuto_Click);
			// 
			// FileIn
			// 
			this->FileIn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->FileIn->Location = System::Drawing::Point(840, 58);
			this->FileIn->Name = L"FileIn";
			this->FileIn->Size = System::Drawing::Size(105, 44);
			this->FileIn->TabIndex = 2;
			this->FileIn->Text = L"Загрузить из файла";
			this->FileIn->UseVisualStyleBackColor = true;
			this->FileIn->Click += gcnew System::EventHandler(this, &AutosForm::FileIn_Click);
			// 
			// FileOut
			// 
			this->FileOut->Cursor = System::Windows::Forms::Cursors::Hand;
			this->FileOut->Location = System::Drawing::Point(840, 120);
			this->FileOut->Name = L"FileOut";
			this->FileOut->Size = System::Drawing::Size(105, 43);
			this->FileOut->TabIndex = 3;
			this->FileOut->Text = L"Выгрузить в файл";
			this->FileOut->UseVisualStyleBackColor = true;
			this->FileOut->Click += gcnew System::EventHandler(this, &AutosForm::FileOut_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->Filter = L"Text files(*.bin)|*.bin";
			this->openFileDialog1->Title = L"Выберите файл для загрузки автомобилей";
			// 
			// saveFileDialog1
			// 
			this->saveFileDialog1->CheckFileExists = true;
			this->saveFileDialog1->Filter = L"Text files(*.bin)|*.bin";
			this->saveFileDialog1->Title = L"Выберите файл для сохранения автомобилей";
			this->saveFileDialog1->CreatePrompt = true;
			this->saveFileDialog1->OverwritePrompt = true;
			this->saveFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &AutosForm::saveFileDialog1_FileOk);
			// 
			// AutosForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(957, 284);
			this->Controls->Add(this->FileOut);
			this->Controls->Add(this->FileIn);
			this->Controls->Add(this->AddAuto);
			this->Controls->Add(this->AutosGrid);
			this->Name = L"AutosForm";
			this->Text = L"Автомобили";
			this->Activated += gcnew System::EventHandler(this, &AutosForm::AutosForm_Activated);
			this->Load += gcnew System::EventHandler(this, &AutosForm::AutosForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->AutosGrid))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		
		private: System::Void AutosForm_Load(System::Object^ sender, System::EventArgs^ e);
		private: System::Void AutosForm_Activated(System::Object^ sender, System::EventArgs^ e);
		private: System::Void AutosGrid_CellDoubleClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
		private: System::Void AddAuto_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void FileIn_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void FileOut_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void saveFileDialog1_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
		}
};
	
}

#endif