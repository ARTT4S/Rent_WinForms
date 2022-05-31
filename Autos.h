#ifndef AUTOS_H
#define AUTOS_H
#include <string>
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

namespace AutosClass {

	const int AUTO_SIZE = 100;
	ref class Autos
	{
	private:
		int m_number = 0;
		String^ m_brand = "";
		int m_price = 0;
		String^ m_type = "";
		const int err = 48;

	public:
		Autos();
		void setNumber(int number);
		int getNumber();
		void setBrand(String^ brand);
		String^ getBrand();
		void setPrice(int price);
		int getPrice();
		void setType(String^ type);
		String^ getType();

	};
}

#endif