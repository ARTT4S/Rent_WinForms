#include "EditClient.h"

namespace ClientNamespace {

	System::Void EditClient::EditClient_Load(System::Object^ sender, System::EventArgs^ e) {
		SurnameTextBox->Text = m_Clients[Convert::ToInt32(*m_numClient)]->GetSName();
		NameTextBox->Text = m_Clients[Convert::ToInt32(*m_numClient)]->GetFName();
		PatronymicTextBox->Text = m_Clients[Convert::ToInt32(*m_numClient)]->GetLName();
		AdressTextBox->Text = m_Clients[Convert::ToInt32(*m_numClient)]->GetAdress();
		PhoneTextBox->Text = m_Clients[Convert::ToInt32(*m_numClient)]->GetPhone();
		if (m_Clients[Convert::ToInt32(*m_numClient)]->GetDriveExperience() != 0) {
			DrExpTextBox->Text = Convert::ToString(m_Clients[Convert::ToInt32(*m_numClient)]->GetDriveExperience());
		}
		else {
			DrExpTextBox->Text = "";
		}
	}
	System::Void EditClient::FinishEdit_Click(System::Object^ sender, System::EventArgs^ e) {
		Close();
	}
	System::Void EditClient::DelClient_Click(System::Object^ sender, System::EventArgs^ e) {
		--(*m_quontClients);
		m_Clients[*m_numClient]->SetFName("");
		m_Clients[*m_numClient]->SetSName("");
		m_Clients[*m_numClient]->SetLName("");
		m_Clients[*m_numClient]->SetAdress("");
		m_Clients[*m_numClient]->SetPhone("");
		m_Clients[*m_numClient]->SetDriveExperience(0);
		FinishEdit_Click(sender, e);
	}
	System::Void EditClient::SurnameTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		m_Clients[Convert::ToInt32(*m_numClient)]->SetSName(SurnameTextBox->Text);
	}
	System::Void EditClient::NameTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		m_Clients[Convert::ToInt32(*m_numClient)]->SetFName(NameTextBox->Text);
	}
	System::Void EditClient::PatronymicTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		m_Clients[Convert::ToInt32(*m_numClient)]->SetLName(PatronymicTextBox->Text);
	}
	System::Void EditClient::AdressTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		m_Clients[Convert::ToInt32(*m_numClient)]->SetAdress(AdressTextBox->Text);
	}
	System::Void EditClient::PhoneTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		m_Clients[Convert::ToInt32(*m_numClient)]->SetPhone(PhoneTextBox->Text);
	}
	System::Void EditClient::DrExpTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		m_Clients[Convert::ToInt32(*m_numClient)]->SetDriveExperience(Convert::ToInt32(DrExpTextBox->Text));
	}
}