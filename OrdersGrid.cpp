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
		int index = OrdersGrid->CurrentCell->RowIndex;
		EditOrders = gcnew EditOrder(m_Orders, m_quontOrders, &index);
		EditOrders->Show();
	}
	System::Void OrdersForm::AddClient_Click(System::Object^ sender, System::EventArgs^ e) {
		OrdersGrid->Rows->Add();
		EditOrders = gcnew EditOrder(m_Orders, m_quontOrders);
		++(*m_quontOrders);
		EditOrders->Show();
	}
}