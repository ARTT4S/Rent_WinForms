#include "EditClient.h"
#include "Func.h"
using namespace functions;

namespace ClientNamespace {

	System::Void EditClient::EditClient_Load(System::Object^ sender, System::EventArgs^ e) {
		SurnameTextBox->Text = m_Clients[Convert::ToInt32(m_numClient)]->GetSName();
		NameTextBox->Text = m_Clients[Convert::ToInt32(m_numClient)]->GetFName();
		PatronymicTextBox->Text = m_Clients[Convert::ToInt32(m_numClient)]->GetLName();
		AdressTextBox->Text = m_Clients[Convert::ToInt32(m_numClient)]->GetAdress();
		PhoneTextBox->Text = m_Clients[Convert::ToInt32(m_numClient)]->GetPhone();
		if (m_Clients[Convert::ToInt32(m_numClient)]->GetDriveExperience() != 0) {
			DrExpTextBox->Text = Convert::ToString(m_Clients[Convert::ToInt32(m_numClient)]->GetDriveExperience());
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
		m_Clients[m_numClient]->SetFName("");
		m_Clients[m_numClient]->SetSName("");
		m_Clients[m_numClient]->SetLName("");
		m_Clients[m_numClient]->SetAdress("");
		m_Clients[m_numClient]->SetPhone("");
		m_Clients[m_numClient]->SetDriveExperience(0);
		FinishEdit_Click(sender, e);
	}
	System::Void EditClient::SurnameTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		String^ temp = SurnameTextBox->Text;
		strCheck(temp);
		m_Clients[Convert::ToInt32(m_numClient)]->SetSName(temp);
	}
	System::Void EditClient::NameTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		String^ temp = NameTextBox->Text;
		strCheck(temp);
		m_Clients[Convert::ToInt32(m_numClient)]->SetFName(temp);
	}
	System::Void EditClient::PatronymicTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		String^ temp = PatronymicTextBox->Text;
		strCheck(temp);
		m_Clients[Convert::ToInt32(m_numClient)]->SetLName(temp);
	}
	System::Void EditClient::AdressTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		String^ temp = AdressTextBox->Text;
		strCheck(temp);
		m_Clients[Convert::ToInt32(m_numClient)]->SetAdress(temp);
	}
	System::Void EditClient::PhoneTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		String^ temp = PhoneTextBox->Text;
		PhoneCheck(m_Clients, *m_quontClients, temp);
		m_Clients[Convert::ToInt32(m_numClient)]->SetPhone(temp);
	}
	System::Void EditClient::DrExpTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		m_Clients[Convert::ToInt32(m_numClient)]->SetDriveExperience(Convert::ToInt32(DrExpTextBox->Text));
	}
}