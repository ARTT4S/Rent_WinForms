#include "AutosGrid.h"

namespace AutosNamespace {

	System::Void AutosForm::AutosForm_Load(System::Object^ sender, System::EventArgs^ e) {
		Autos^ temp;
		for (int i = 0; i < *m_quontCars; ++i) {
			if (m_Cars->GetLength(0) != 0) {
				AutosGrid->Rows->Add();
				if ((m_Cars[i]->getNumber() == 0) && (m_Cars[i]->getBrand() == "") && (m_Cars[i]->getPrice() == 0) && (m_Cars[i]->getType() == "")) {
					for (int j = i; j < *m_quontCars; ++j) {
						temp = m_Cars[j];
						m_Cars[i] = m_Cars[j + 1];
						m_Cars[j + 1] = temp;
					}
				}
			}
		}
	}

	System::Void AutosForm::AutosForm_Activated(System::Object^ sender, System::EventArgs^ e) {
		AutosGrid->Rows->Clear();
		AutosForm_Load(sender, e);
		for (int i = 0; i < *m_quontCars; ++i) {
			AutosGrid->Rows[i]->Cells["Number"]->Value = i + 1;
			AutosGrid->Rows[i]->Cells["AutoNum"]->Value = m_Cars[i]->getNumber();
			AutosGrid->Rows[i]->Cells["Brand"]->Value = m_Cars[i]->getBrand();
			AutosGrid->Rows[i]->Cells["Price"]->Value = m_Cars[i]->getPrice();
			AutosGrid->Rows[i]->Cells["Type"]->Value = m_Cars[i]->getType();
		}
	}

	System::Void AutosForm::AddAuto_Click(System::Object^ sender, System::EventArgs^ e) {
		AutosGrid->Rows->Add();
		EditCars = gcnew EditAuto(m_Cars, m_quontCars);
		++(*m_quontCars);
		EditCars->Show();

	}

	System::Void AutosForm::AutosGrid_CellDoubleClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		int index = AutosGrid->CurrentCell->RowIndex;
		EditCars = gcnew EditAuto(m_Cars, m_quontCars, &index);
		EditCars->Show();
	}

	System::Void AutosForm::FileIn_Click(System::Object^ sender, System::EventArgs^ e) {
		int i{};
		int tempNumber, tempPrice;
		String^ tempBrand;
		String^ tempType;
		saveFileDialog1->CreatePrompt = true;
		saveFileDialog1->OverwritePrompt = true;
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::Cancel) {
			return;
		}
		String^ filename = openFileDialog1->FileName;
		String^ FileText = System::IO::File::ReadAllText(filename);
		for (int j = 0; j < FileText->Length; ++j) {
			Read(FileText, &tempNumber, &i);
			m_Cars[j]->setNumber(tempNumber);
			Read(FileText, tempBrand, &i);
			m_Cars[j]->setBrand(tempBrand);
			Read(FileText, &tempPrice, &i);
			m_Cars[j]->setNumber(tempPrice);
			Read(FileText, tempType, &i);
			m_Cars[j]->setBrand(tempType);
			i = 0;
		}
		MessageBox::Show("Список автомобилей загружен");
	}

	System::Void AutosForm::FileOut_Click(System::Object^ sender, System::EventArgs^ e) {
		if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::Cancel) {
			return;
		}
		String^ filename = saveFileDialog1->FileName;
		String^ FileText;
		for (int i = 0; i < *m_quontCars; ++i) {
			FileText += Convert::ToString(m_Cars[i]->getNumber());
			FileText += "|";
			FileText += m_Cars[i]->getBrand();
			FileText += "|";
			FileText += Convert::ToString(m_Cars[i]->getPrice());
			FileText += "|";
			FileText += m_Cars[i]->getType();
			FileText += "|";
		}
		System::IO::File::WriteAllText(filename, FileText);
		MessageBox::Show("Список автомобилей выгружен");
	}

	System::Void Read(String^ Text, String^ string, int* i) {
		wchar_t read{};
		for (i; read != '|'; ++*i) {
			read = Text[Convert::ToInt32(*i)];
			if (read != '|') {
				string += read;
			}
		}
	}

	System::Void Read(String^ Text, int* integer, int* i) {
		wchar_t read{};
		String^ temp;
		for (i; read != '|'; ++*i) {
			read = Text[Convert::ToInt32(*i)];
			if (read != '|') {
				temp += read;
			}
		}
		*integer = Convert::ToInt32(temp);
	}

}