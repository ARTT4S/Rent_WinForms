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
		EditCars = gcnew EditAuto(m_Cars, *m_quontCars);
		++(*m_quontCars);
		EditCars->Show();

	}

	System::Void AutosForm::AutosGrid_CellDoubleClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		EditCars = gcnew EditAuto(m_Cars, m_quontCars, AutosGrid->CurrentCell->RowIndex);
		EditCars->Show();
	}

	System::Void AutosForm::FileIn_Click(System::Object^ sender, System::EventArgs^ e) {
		int i{}, count{};
		int tempNumber{}, tempPrice{};
		String^ tempBrand = nullptr;
		String^ tempType = nullptr;
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::Cancel) {
			return;
		}
		String^ filename = openFileDialog1->FileName;
		String^ FileText = System::IO::File::ReadAllText(filename);
		for (int j = 0; j < FileText->Length; ++j) {
			if (FileText[j] == '|') {
				++count;
			}
		}
		*m_quontCars = count / 4;
		for (int j = 0; j < *m_quontCars; ++j) {
			Read(FileText, &tempNumber, &i);
			m_Cars[j]->setNumber(tempNumber);
			m_Cars[j]->setBrand(Read(FileText, tempBrand, &i));
			Read(FileText, &tempPrice, &i);
			m_Cars[j]->setPrice(tempPrice);
			m_Cars[j]->setType(Read(FileText, tempType, &i));
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
}