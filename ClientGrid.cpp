#include "ClientGrid.h"

namespace ClientNamespace {

	System::Void ClientsForm::ClientsForm_Activated(System::Object^ sender, System::EventArgs^ e) {
		ClientGrid->Rows->Clear();
		ClientsForm_Load(sender, e);
		for (int i = 0; i < *m_quontClients; ++i) {
			ClientGrid->Rows[i]->Cells["Number"]->Value = i + 1;
			ClientGrid->Rows[i]->Cells["Surname"]->Value = m_Clients[i]->GetSName();
			ClientGrid->Rows[i]->Cells["Name"]->Value = m_Clients[i]->GetFName();
			ClientGrid->Rows[i]->Cells["Patronymic"]->Value = m_Clients[i]->GetLName();
			ClientGrid->Rows[i]->Cells["Adress"]->Value = m_Clients[i]->GetAdress();
			ClientGrid->Rows[i]->Cells["Phone"]->Value = m_Clients[i]->GetPhone();
			ClientGrid->Rows[i]->Cells["DrExp"]->Value = m_Clients[i]->GetDriveExperience();
		}
	}

	System::Void ClientsForm::ClientsForm_Load(System::Object^ sender, System::EventArgs^ e) {
		Client^ temp;
		for (int i = 0; i < *m_quontClients; ++i) {
			if (m_Clients->GetLength(0) != 0) {
				ClientGrid->Rows->Add();
				if ((m_Clients[i]->GetFName() == "") && (m_Clients[i]->GetSName() == "") && (m_Clients[i]->GetLName() == "") && (m_Clients[i]->GetAdress() == "") && (m_Clients[i]->GetPhone() == "") && (m_Clients[i]->GetDriveExperience() == 0)) {
					for (int j = i; j < *m_quontClients; ++j) {
						temp = m_Clients[j];
						m_Clients[i] = m_Clients[j + 1];
						m_Clients[j + 1] = temp;
					}
				}
			}
		}
		
	}
	System::Void ClientsForm::ClientGrid_CellDoubleClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		EditClients = gcnew EditClient(m_Clients, m_quontClients, ClientGrid->CurrentCell->RowIndex);
		EditClients->Show();
	}
	System::Void ClientsForm::AddClient_Click(System::Object^ sender, System::EventArgs^ e) {
		ClientGrid->Rows->Add();
		EditClients = gcnew EditClient(m_Clients, *m_quontClients);
		++(*m_quontClients);
		EditClients->Show();
	}

	System::Void ClientsForm::FileIn_Click(System::Object^ sender, System::EventArgs^ e) {
		int i{}, count{};
		int tempDrExp{};
		String^ tempFName;
		String^ tempSName;
		String^ tempLName;
		String^ tempAdress;
		String^ tempPhone;
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
		*m_quontClients = count / 6;
		for (int j = 0; j < *m_quontClients; ++j) {
			m_Clients[j]->SetFName(Read(FileText, tempFName, &i));
			m_Clients[j]->SetSName(Read(FileText, tempSName, &i));
			m_Clients[j]->SetLName(Read(FileText, tempLName, &i));
			m_Clients[j]->SetAdress(Read(FileText, tempAdress, &i));
			m_Clients[j]->SetPhone(Read(FileText, tempPhone, &i));
			Read(FileText, &tempDrExp, &i);
			m_Clients[j]->SetDriveExperience(tempDrExp);
		}
		MessageBox::Show("Список клиентов загружен");
	}
	System::Void ClientsForm::FileOut_Click(System::Object^ sender, System::EventArgs^ e) {
		if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::Cancel) {
			return;
		}
		String^ filename = saveFileDialog1->FileName;
		String^ FileText;
		for (int i = 0; i < *m_quontClients; ++i) {
			FileText += m_Clients[i]->GetFName();
			FileText += "|";
			FileText += m_Clients[i]->GetSName();
			FileText += "|";
			FileText += m_Clients[i]->GetLName();
			FileText += "|";
			FileText += m_Clients[i]->GetAdress();
			FileText += "|";
			FileText += m_Clients[i]->GetPhone();
			FileText += "|";
			FileText += Convert::ToString(m_Clients[i]->GetDriveExperience());
			FileText += "|";
		}
		System::IO::File::WriteAllText(filename, FileText);
		MessageBox::Show("Список автомобилей выгружен");
	}

}