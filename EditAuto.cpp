#include "EditAuto.h"

namespace AutosNamespace {

	System::Void EditAuto::EditAuto_Load(System::Object^ sender, System::EventArgs^ e) {
		if (m_Cars[*m_numCar]->getNumber() != 0) {
			NumberTextBox->Text = Convert::ToString(m_Cars[Convert::ToInt32(*m_numCar)]->getNumber());
		}
		else {
			NumberTextBox->Text = "";
		}
		BrandTextBox->Text = m_Cars[Convert::ToInt32(*m_numCar)]->getBrand();
		if (m_Cars[Convert::ToInt32(*m_numCar)]->getPrice() != 0) {
			PriceTextBox->Text = Convert::ToString(m_Cars[Convert::ToInt32(*m_numCar)]->getPrice());
		}
		else {
			PriceTextBox->Text = "";
		}
		TypeTextBox->Text = m_Cars[Convert::ToInt32(*m_numCar)]->getType();
	}

	System::Void EditAuto::NumberTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		m_Cars[Convert::ToInt32(*m_numCar)]->setNumber(Convert::ToInt32(NumberTextBox->Text));
	}
	System::Void EditAuto::BrandTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		m_Cars[Convert::ToInt32(*m_numCar)]->setBrand(BrandTextBox->Text);
	}
	System::Void EditAuto::PriceTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		m_Cars[Convert::ToInt32(*m_numCar)]->setPrice(Convert::ToInt32(PriceTextBox->Text));
	}
	System::Void EditAuto::TypeTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		m_Cars[Convert::ToInt32(*m_numCar)]->setType(TypeTextBox->Text);
	}
	
	System::Void EditAuto::FinishEdit_Click(System::Object^ sender, System::EventArgs^ e) {
		Close();
	}

	System::Void EditAuto::DelAuto_Click(System::Object^ sender, System::EventArgs^ e) {
		m_Cars[*m_numCar]->setNumber(0);
		m_Cars[*m_numCar]->setBrand("");
		m_Cars[*m_numCar]->setPrice(0);
		m_Cars[*m_numCar]->setType("");
		--(*m_quontCars);
		FinishEdit_Click(sender, e);
	}

}