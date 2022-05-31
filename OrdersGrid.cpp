#include "OrdersGrid.h"

namespace OrdersNamespace {
	System::Void OrdersForm::OrdersForm_Load(System::Object^ sender, System::EventArgs^ e) {
		Order^ temp;
		for (int i = 0; i < *m_quontOrders; ++i) {
			if (m_Orders->GetLength(0) != 0) {
				OrdersGrid->Rows->Add();
				if ((m_Orders[i]->GetCarnumber() == 0) && (m_Orders[i]->GetPhone() == "") && (Convert::ToDateTime(m_Orders[i]->GetDate()) == DateTime(1880, 01, 01) && (Convert::ToDateTime(m_Orders[i]->GetBackDate()) == DateTime(1880, 01, 01)))) {
					for (int j = i; j < *m_quontOrders; ++j) {
						temp = m_Orders[j];
						m_Orders[i] = m_Orders[j + 1];
						m_Orders[j + 1] = temp;
					}
				}
			}
		}
	}
	System::Void OrdersForm::OrdersForm_Activated(System::Object^ sender, System::EventArgs^ e) {
		OrdersGrid->Rows->Clear();
		OrdersForm_Load(sender, e);
		for (int i = 0; i < *m_quontOrders; ++i) {
			OrdersGrid->Rows[i]->Cells["Number"]->Value = i + 1;
			OrdersGrid->Rows[i]->Cells["Carnumber"]->Value = m_Orders[i]->GetCarnumber();
			OrdersGrid->Rows[i]->Cells["Phone"]->Value = m_Orders[i]->GetPhone();
			OrdersGrid->Rows[i]->Cells["OrderDate"]->Value = m_Orders[i]->GetDate();
			OrdersGrid->Rows[i]->Cells["BackDate"]->Value = m_Orders[i]->GetBackDate();
		}
	}
	System::Void OrdersForm::OrdersGrid_CellDoubleClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		EditOrders = gcnew EditOrder(m_Orders, m_quontOrders, m_Cars, m_quontCars, m_Clients, m_quontClients, OrdersGrid->CurrentCell->RowIndex);
		EditOrders->Show();
	}
	System::Void OrdersForm::AddClient_Click(System::Object^ sender, System::EventArgs^ e) {
		OrdersGrid->Rows->Add();
		EditOrders = gcnew EditOrder(m_Orders, m_quontOrders, m_Cars, m_quontCars, m_Clients, m_quontClients, *m_quontOrders);
		++(*m_quontOrders);
		EditOrders->Show();
	}

	System::Void OrdersForm::FileIn_Click(System::Object^ sender, System::EventArgs^ e) {
		int i{}, count{};
		int tempCarnumber{};
		String^ tempPhone;
		DateTime^ tempDate;
		DateTime^ tempBackDate;
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
		*m_quontOrders = count / 4;
		for (int j = 0; j < *m_quontOrders; ++j) {
			Read(FileText, &tempCarnumber, &i);
			m_Orders[j]->SetCarnumber(tempCarnumber);
			m_Orders[j]->SetPhone(Read(FileText, tempPhone, &i));
			m_Orders[j]->SetDate(Read(FileText, tempDate, &i));
			m_Orders[j]->SetBackDate(Read(FileText, tempBackDate, &i));
		}
		MessageBox::Show("Список клиентов загружен");
	}
	System::Void OrdersForm::FileOut_Click(System::Object^ sender, System::EventArgs^ e) {
		if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::Cancel) {
			return;
		}
		String^ filename = saveFileDialog1->FileName;
		String^ FileText;
		for (int i = 0; i < *m_quontOrders; ++i) {
			FileText += Convert::ToString(m_Orders[i]->GetCarnumber());
			FileText += "|";
			FileText += m_Orders[i]->GetPhone();
			FileText += "|";
			FileText += Convert::ToString(m_Orders[i]->GetDate());
			FileText += "|";
			FileText += Convert::ToString(m_Orders[i]->GetBackDate());
			FileText += "|";
		}
		System::IO::File::WriteAllText(filename, FileText);
		MessageBox::Show("Список автомобилей выгружен");
	}
}