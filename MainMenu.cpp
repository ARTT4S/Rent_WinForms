#include "MainMenu.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace AutosClass;
using namespace ClientsClass;
using namespace OrdersClass;

[STAThread]
void main(array<String^>^ arg) {
	array<Autos^>^ Cars = gcnew array<Autos^>(AUTO_SIZE);
	for (int i = 0; i < AUTO_SIZE; ++i) {
		Cars[i] = gcnew Autos();
	}
	array<Client^>^ Clients = gcnew array<Client^>(CLIENT_SIZE);
	for (int i = 0; i < CLIENT_SIZE; ++i) {
		Clients[i] = gcnew Client();
	}
	array<Order^>^ Orders = gcnew array<Order^>(ORDER_SIZE);
	for (int i = 0; i < ORDER_SIZE; ++i) {
		Orders[i] = gcnew Order();
	}
	int quontCars{0};
	int quontClients{0};
	int quontOrders{0};
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Rent::MainMenu Menu(Cars, &quontCars, Clients, &quontClients, Orders, &quontOrders);
	Application::Run(% Menu);
}