#include "Func.h"

namespace functions {
	System::String^ Read(String^ Text, String^ string, int* i) {
		wchar_t read{};
		for (i; read != '|'; ++(*i)) {
			read = Text[Convert::ToInt32(*i)];
			if (read != '|') {
				string += read;
			}
		}
		return string;
	}
	System::Void Read(String^ Text, int* integer, int* i) {
		wchar_t read{};
		String^ temp;
		for (i; read != '|'; ++(*i)) {
			read = Text[Convert::ToInt32(*i)];
			if (read != '|') {
				temp += read;
			}
		}
		*integer = Convert::ToInt32(temp);
	}
	System::DateTime^ Read(String^ Text, DateTime^ date, int* i) {
		String^ temp;
		wchar_t read{};
		for (i; read != '|'; ++(*i)) {
			read = Text[Convert::ToInt32(*i)];
			if (read != '|') {
				temp += read;
			}
		}
		return Convert::ToDateTime(temp);
	}
	System::Void PhoneCheck(array<Client^>^ Clients, int quont, String^ string) {
		bool flag = true;
		while (flag) {
			flag = Regex::IsMatch(string, "\d{11}");
			if (flag) {
				flag = false;
				for (int i = 0; i < quont; ++i) {
					if (Clients[i]->GetPhone() == string) {
						flag = true;
					}
				}
				if (flag) {
					MessageBox::Show("Клиент с таким номером телефона уже существует. Введите другое значение.");
				}
			}
			else {
				MessageBox::Show("Вы ввели некорректное значение!Введите другое значение.");
				flag = true;
			}
		}
	}
	System::Boolean PhoneCheck(String^ phone1, array<Client^>^ Clients, int n) {
		bool flag{ 1 };
		for (int i{}; i < n; i++) {
			if (Clients[i]->GetPhone() == phone1) {
				flag = 0;
			}
		}
		return flag;
	}
	System::Boolean NumberCheck(int carnumber1, array<Autos^>^ Cars, int n) {
		bool flag{ 1 };
		for (int i{}; i < n; i++) {
			if (Cars[i]->getNumber() == carnumber1) {
				flag = 0;
			}
		}
		return flag;
	}
	System::Void strCheck(String^ string) {
		bool flag = true;
		wchar_t invalidSymbols[10]{ '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
		while (flag) {
			for (int i = 0; i < string->Length && flag; ++i) {
				for (int j = 0; j < 10 && flag; ++j) {
					if (string[i] == invalidSymbols[j]) {
						flag = false;
					}
				}
			}
			if (flag) {
				flag = false;
			}
			else {
				MessageBox::Show("Вы ввели некорректное значение! Введите другое значение.");
				flag = true;
			}
		}
	}
	System::Void SimilaryCheckNum(array<Autos^>^ Cars, int quont, int n) {
		bool flag = true;
		while (flag) {
			flag = false;
			for (int i = 0; i < quont; ++i) {
				if (Cars[i]->getNumber() == n) {
					flag = true;
				}
			}
			if (flag) {
				MessageBox::Show("Автомобиль с таким номером уже существует. Введите другое значение.");
			}
		}
	}
	System::Void dateCheck(DateTime^ date1, DateTime^ date2) {
		if (DateTime::Compare(Convert::ToDateTime(date1), Convert::ToDateTime(date2)) > 0) {
			MessageBox::Show("Дата возврата не может быть меньше даты заказа.");
		}
	}
	System::Void stat(array<Order^>^ Orders, array<Autos^>^ Cars, array<Client^>^ Clients, int n, int number) {
		int quontMatk{}, quontPhone{};
		for (int i{}; i < n; i++) {
			if (Orders[i]->GetCarnumber() == Cars[number]->getNumber()) {
				quontMatk++;
			}
		}
		for (int i{}; i < n; i++) {
			if (Orders[i]->GetPhone() == Clients[number]->GetPhone()) {
				quontPhone++;
			}
		}
		String^ Text = "Было заказано " + Convert::ToString(quontMatk) + " автомобилей марки " + Cars[number]->getBrand() + '\n' + "Клиентом с номером телефона " + Orders[number]->GetPhone() + " было заказано " + Convert::ToString(quontPhone) + " автомобилей";
		MessageBox::Show(Text);
	}
}