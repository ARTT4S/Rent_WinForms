#ifndef FUNC_H
#define FUNC_H
#include "Autos.h"
#include "Clients.h"
#include "Orders.h"
#include <regex>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Text::RegularExpressions;
using namespace AutosClass;
using namespace ClientsClass;
using namespace OrdersClass;

namespace functions {
	System::String^ Read(String^ Text, String^ string, int* i);
	System::Void Read(String^ Text, int* integer, int* i);
	System::DateTime^ Read(String^ Text, DateTime^ date, int* i);
	System::Void PhoneCheck(array<Client^>^ Clients, int quont, String^ string);
	System::Boolean PhoneCheck(String^ phone1, array<Client^>^ Clients, int n);
	System::Boolean NumberCheck(int carnumber1, array<Autos^>^ Cars, int n);
	System::Void strCheck(String^ string);
	System::Void SimilaryCheckNum(array<Autos^>^ Cars, int quont, int n);
	System::Void dateCheck(DateTime^ date1, DateTime^ date2);
	System::Void stat(array<Order^>^ Orders, array<Autos^>^ Cars, array<Client^>^ Clients, int n, int number);

}

#endif