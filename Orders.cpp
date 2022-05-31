#include "Orders.h"

namespace OrdersClass {
    Order::Order() {
        carnumber = 0;
        phone = "";
        date = DateTime(1880, 01, 01);
        back_date = DateTime(1880, 01, 01);
    }
    void Order::SetCarnumber(int carnumber1) {
        carnumber = carnumber1;
    }
    void Order::SetPhone(String^ phone1) {
        phone = phone1;
    }
    void Order::SetDate(DateTime^ date1) {
        date = date1;
    }
    void Order::SetBackDate(DateTime^ back_date1) {
        back_date = back_date1;
    }
    int Order::GetCarnumber() {
        return carnumber;
    }
    String^ Order::GetPhone() {
        return phone;
    }
    DateTime^ Order::GetDate() {
        return date;
    }
    DateTime^ Order::GetBackDate() {
        return back_date;
    }
}