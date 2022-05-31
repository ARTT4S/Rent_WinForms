#include "Clients.h"

namespace ClientsClass {
    Client::Client() {
        lname = "";
        fname = "";
        sname = "";
        adress = "";
        phone = "";
        drive_experience = 0;
    }
    void Client::SetLName(String^ lname1) {
        lname = lname1;
    }
    void Client::SetFName(String^ fname1) {
        fname = fname1;
    }
    void Client::SetSName(String^ sname1) {
        sname = sname1;
    }
    void Client::SetAdress(String^ adress1) {
        adress = adress1;
    }
    void Client::SetPhone(String^ phone1) {
        phone = phone1;
    }
    void Client::SetDriveExperience(int drive_experience1) {
        drive_experience = drive_experience1;
    }
    String^ Client::GetLName() {
        return lname;
    }
    String^ Client::GetFName() {
        return fname;
    }
    String^ Client::GetSName() {
        return sname;
    }
    String^ Client::GetAdress() {
        return adress;
    }
    String^ Client::GetPhone() {
        return phone;
    }
    int Client::GetDriveExperience() {
        return drive_experience;
    }
}