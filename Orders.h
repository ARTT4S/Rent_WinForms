#ifndef ORDERS_H
#define ORDERS_H
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

namespace OrdersClass {
    const int ORDER_SIZE = 100;
	ref class Order
	{
        int carnumber{};
        String^ phone = "";
        DateTime^ date = DateTime(1880, 01, 01);
        DateTime^ back_date = DateTime(1880, 01, 01);
    public:
        Order();
        void SetCarnumber(int carnumber1);
        void SetPhone(String^ phone1);
        void SetDate(DateTime^ date1);
        void SetBackDate(DateTime^ back_date1);
        int GetCarnumber();
        String^ GetPhone();
        DateTime^ GetDate();
        DateTime^ GetBackDate();
	};
}

#endif