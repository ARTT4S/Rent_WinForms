#include "EditOrder.h"
#include "Func.h"
using namespace functions;

namespace OrdersNamespace {
	System::Void EditOrder::EditOrder_Load(System::Object^ sender, System::EventArgs^ e) {
		if (m_Orders[Convert::ToInt32(m_numOrder)]->GetCarnumber() != 0) {
			CarnumberTextBox->Text = Convert::ToString(m_Orders[Convert::ToInt32(m_numOrder)]->GetCarnumber());
		}
		else {
			CarnumberTextBox->Text = "";
		}
		PhoneTextBox->Text = m_Orders[Convert::ToInt32(m_numOrder)]->GetPhone();
		if (Convert::ToDateTime(m_Orders[Convert::ToInt32(m_numOrder)]->GetDate()) == DateTime(1880, 01, 01)) {
			DateChoise->Value = DateTime::Today;
		}
		else {
			DateChoise->Value = Convert::ToDateTime(m_Orders[Convert::ToInt32(m_numOrder)]->GetDate());
		}
		if (Convert::ToDateTime(m_Orders[Convert::ToInt32(m_numOrder)]->GetBackDate()) == DateTime(1880, 01, 01)) {
			BackDateChoise->Value = DateTime::Today;
		} 
		else {
			BackDateChoise->Value = Convert::ToDateTime(m_Orders[Convert::ToInt32(m_numOrder)]->GetBackDate());
		}
	}
	System::Void EditOrder::FinishEditting_Click(System::Object^ sender, System::EventArgs^ e) {
		Close();
	}
	System::Void EditOrder::DelOrder_Click(System::Object^ sender, System::EventArgs^ e) {
		--(*m_quontOrders);
		m_Orders[m_numOrder]->SetCarnumber(0);
		m_Orders[m_numOrder]->SetPhone("");
		m_Orders[m_numOrder]->SetDate(DateTime(1880, 01, 01));
		m_Orders[m_numOrder]->SetBackDate(DateTime(1880, 01, 01));
		FinishEditting_Click(sender, e);
	}
	System::Void EditOrder::Stat_Click(System::Object^ sender, System::EventArgs^ e) {
		stat(m_Orders, m_Cars, m_Clients, *m_quontOrders, m_numOrder);
	}
	System::Void EditOrder::CarnumberTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		m_Orders[Convert::ToInt32(m_numOrder)]->SetCarnumber(Convert::ToInt32(CarnumberTextBox->Text));
	}
	System::Void EditOrder::PhoneTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		m_Orders[Convert::ToInt32(m_numOrder)]->SetPhone(PhoneTextBox->Text);
	}
	System::Void EditOrder::DateChoise_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
		m_Orders[Convert::ToInt32(m_numOrder)]->SetDate(DateChoise->Value);
	}
	System::Void EditOrder::BackDateChoise_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
		DateTime^ temp = BackDateChoise->Value;
		dateCheck(m_Orders[m_numOrder]->GetDate(), temp);
		m_Orders[Convert::ToInt32(m_numOrder)]->SetBackDate(temp);
	}
}