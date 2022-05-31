#ifndef CLIENTS_H
#define CLIENTS_H
#include <string>
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

namespace ClientsClass {
    const int CLIENT_SIZE = 100;
	ref class Client
	{
    private:
        String^ lname = "";
        String^ fname = "";
        String^ sname = "";
        String^ adress = "";
        String^ phone = "";
        int drive_experience{};
    public:
        Client();
        void SetLName(String^ lname1);
        void SetFName(String^ fname1);
        void SetSName(String^ sname1);
        void SetAdress(String^ adress1);
        void SetPhone(String^ phone1);
        void SetDriveExperience(int drive_experience1);
        String^ GetLName();
        String^ GetFName();
        String^ GetSName();
        String^ GetAdress();
        String^ GetPhone();
        int GetDriveExperience();
	};
}

#endif