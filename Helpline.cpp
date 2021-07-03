#include <bits/stdc++.h>
#include "sha512.h"
#include "csvfile.h"
using namespace std;
// csvfile csv("Data.csv");

void centerstring(string s, int width)
{
  int l = s.length();
  int pos = (int)((width - l) / 2);
  for (int i = 0; i < pos; i++)
    cout << " ";
  cout << s;
}
class Caller_info
{
public:
  string name;
  string location;
  string emr_type;
  string urgency;
  string ph_number;
  string call_time;

  Caller_info()
  {
    name = "Tester";
    location = "Nowhere";
    emr_type = "0";
    urgency = "0";
    ph_number = "101";
    call_time = "0";
  }

  void get_all_data()
  {
    get_caller_name();
    get_location();
    get_emr_type();
    get_urgency();
    get_ph_number();
    get_time();
  }
  void get_caller_name()
  {
    system("clear||cls");
    cout << endl;
    centerstring("Enter name of caller", 80);
    centerstring("...", 79);
    cin.ignore();
    getline(cin, name);
  }

  void get_location()
  {
    system("clear||cls");
    cout << endl;
    centerstring("Enter location of caller", 80);
    centerstring("...", 79);
    getline(cin, location);
  }

  void get_emr_type()
  {
    system("clear||cls");
    cout << endl;
    centerstring("Enter type of emergency", 80);
    cout << endl;
    centerstring("\"p\" for police", 80);
    cout << endl;
    centerstring("\"f\" for fire", 80);
    cout << endl;
    centerstring("\"m\" for medical", 80);
    cout << endl;
    centerstring("\"c\" for COVID", 80);
    cout << endl;
    centerstring("(Enter a Combination of the above if Multiple Services are needed): ", 80);
    centerstring("...", 80);
    cin >> emr_type;
  }

  char get_urgency()
  {
  urlabel:
    system("clear||cls");
    cout << endl;
    centerstring("Enter Code of Urgency", 80);
    cout << endl;
    centerstring("\"R\" for Code Red ", 80);
    cout << endl;
    centerstring("\"O\" for Code Orange", 80);
    cout << endl;
    centerstring("\"Y\" for Code Yellow", 80);
    centerstring("...", 80);
    cin >> urgency;
    char upUrgency = toupper(urgency[0]);
    if (urgency.length() != 1 || (upUrgency != 'R' && upUrgency != 'O' && upUrgency != 'Y'))
    {
      centerstring("Invalid Input....Click Enter to try again...", 80);
      cin.ignore();
      cin.get();
      goto urlabel;
    }

    return upUrgency;
  }

  void get_ph_number()
  {
  phlabel:
    system("clear||cls");
    cout << endl;
    centerstring("Enter caller's phone number: ", 80);
    centerstring("...", 80);
    cin >> ph_number;
    int ch = 0;
    double len = ph_number.length();
    for (int i = 0; i < len; i++)
    {
      if (!isdigit(ph_number[i]))
      {
        ch++;
        break;
      }
    }
    // cout<<ch;
    if (ch != 0 || len > 10 || len < 6)
    {
      centerstring("Invalid Phone Number....Click Enter to try again...", 80);
      cin.ignore();
      cin.get();
      goto phlabel;
    }
  }
  void show_caller_info()
  {
    system("clear||cls");
    cout << "Caller Name: " << name << endl;
    cout << "Emergency type: " << emr_type << endl;
    cout << "Status of urgency: " << urgency << endl;
    cout << "Caller Number: " << ph_number << endl;
    cout << "Caller's location: " << location << endl;
  }

  void get_time()
  {

    time_t givemetime = time(NULL);
    call_time = ctime(&givemetime);
  }
};

// password
class Password
{
  string password;

public:
  Password()
  {
    fstream pword;
    pword.open("hashed_pass.txt", ios::out);
    pword << sha512("0000");
    pword.close();
  }
  string get_password_hash()
  {
    fstream pword;
    pword.open("hashed_pass.txt", ios::in);
    pword.seekg(0, ios::beg);
    string temp;
    getline(pword, temp);
    pword.close();
    return temp;
  }
  void set_password()
  {
    cout << endl;
    centerstring("Enter the new password: ", 80);
    cin >> password;
    fstream pword;
    pword.open("hashed_pass.txt", ios::out);

    pword << sha512(password);
    pword.close();
  }
};
// Show

class Show : public Password, public Caller_info
{
public:
  int password_screen()
  {
    system("clear||cls");
    string p_in;
    int chances = 3;
    centerstring("Weupome", 80);
    cout << endl;
    while (chances)
    {
      cout << endl;
      centerstring("Enter Your Admin Password:", 80);
      cin >> p_in;
      if (sha512(p_in) == Password::get_password_hash())
      {
        return 1;
      }
      else
      {
        centerstring(" Wrong Password", 80);
        cout << endl
             << setw(32) << --chances << " chances remaining";
      }
    }
    return 0;
  }
  int welcome_screen()
  {
    system("clear||cls");
    centerstring("Welcome Administrator", 80);
    cout << endl
         << endl;
    centerstring("Press Enter to continue", 80);
    cin.ignore();
    cin.get();

    return 1;
  }
  int admin_page()
  {

  label1:
    system("clear||cls");
    centerstring("Admin Menu", 80);
    cout << endl
         << endl;
    centerstring("1. Enter New Caller Info", 80);
    cout << endl;
    centerstring("2. View Emergency Unit Status", 80);
    cout << endl;
    centerstring("3. View/Edit Caller Log", 80);
    cout << endl;
    centerstring("4. Change Admin Password", 80);
    cout << endl;
    centerstring("5. LogOut", 80);
    cout << endl
         << endl;
    centerstring("Enter Your choice...", 80);
    unsigned int choice;

    cin >> choice;
    if (choice > 5 || choice <= 0)
    {
      centerstring("Invalid Input...press enter to try again...", 80);
      cin.ignore();
      cin.get();
      goto label1;
    }
    else
      return choice;
  }
  void view_caller_page()
  {
  label5:
    system("cls||clear");
    centerstring("Caller Information", 80);
    cout << endl
         << endl;
  }
} s;

int main()
{

  while (1)
  {
    if (s.password_screen())
    {
      s.welcome_screen();
      int t = 0, k = 0;
      do
      {
        t = s.admin_page();
        if (t == 1)
        {
          s.get_all_data();
          csvfile csv("Data.csv");
          // csv << "X"
          //     << "NAME"
          //     << "LOCATION"
          //     << "EMER_TYPE"
          //     << "URGENCY"
          //     << "PH.NO." << endrow;
          csv << s.name << s.location << s.emr_type << (char)toupper(s.urgency[0]) << s.ph_number << s.call_time << endrow;
          // csv.~csvfile();
          cout << "\nPress Enter to go to admin menu...";
          cin.ignore();
          cin.get();
        }
        else if (t == 2)
        {
          ;
        }
        else if (t == 3)
        {
          s.view_caller_page();
          cout << "\nLog file is opening...";
          system(".\\Data.csv");
          cout << "\nLog file closed...";
          cout << "\nPress Enter to go to admin menu...";
          cin.ignore();
          cin.get();
        }
        else if (t == 4)
        {
          s.set_password();
          cout << "\nPress Enter to go to admin menu...";

          cin.ignore();
          cin.get();
        }
        else if (t == 5)
        {
          break;
        }
        else
        {
          cout << "Execution error";
        }

      } while (1);
    }
  }

  cout << "\n\nPress Enter to exit program...";

  cin.ignore();
  cin.get();
  return 0;
}
