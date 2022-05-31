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
		int index = ClientGrid->CurrentCell->RowIndex;
		EditClients = gcnew EditClient(m_Clients, m_quontClients, &index);
		EditClients->Show();
	}
	System::Void ClientsForm::AddClient_Click(System::Object^ sender, System::EventArgs^ e) {
		ClientGrid->Rows->Add();
		EditClients = gcnew EditClient(m_Clients, m_quontClients);
		++(*m_quontClients);
		EditClients->Show();
	}

}