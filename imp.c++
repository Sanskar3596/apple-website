#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <limits>
#include <ctime>
#include <cstdlib>
#include <cctype>

using namespace std;

const string STUDENT_FILE = "students.dat";
const string BACKUP_FILE = "students_backup.dat";

const int SUBJECT_COUNT = 5;

const string SUBJECTS[SUBJECT_COUNT] = {
        "C++ Programming",
            "Mathematics",
                "Database",
                    "Communication",
                        "Data Science"
};

void clearScreen()
{
    #ifdef _WIN32
        system("cls");
        #else
            system("clear");
            #endif
}

void pauseScreen()
{
        cout << "\nPress ENTER to continue...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void line()
{
        cout << "=============================================================\n";
}

void smallLine()
{
        cout << "-------------------------------------------------------------\n";
}

void title(const string& text)
{
        cout << "\n";
            line();
                cout << setw(35) << right << text << "\n";
                    line();
}

string getString(const string& message)
{
        string value;
            cout << message;
                getline(cin, value);
                    return value;
}

int getInt(const string& message)
{
        int value;

            while (true)
                {
                            cout << message;

                                    if (cin >> value)
                                            {
                                                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                                                        return value;
                                            }

                                                    cout << "Invalid input. Please enter a number.\n";
                                                            cin.clear();
                                                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                        }
                                    }

                                    double getDouble(const string& message)
                                    {
                                            double value;

                                                while (true)
                                                    {
                                                                cout << message;

                                                                        if (cin >> value)
                                                                                {
                                                                                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                                                                                            return value;
                                                                                }

                                                                                        cout << "Invalid input. Please enter a valid number.\n";
                                                                                                cin.clear();
                                                                                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                                                            }
                                                                        }

                                                                        bool isValidEmail(const string& email)
                                                                        {
                                                                                size_t at = email.find(('@');
                                                                                size_t dot = email.find('.', at);
                                                                            
                                                                                return at != string::npos &&
                                                                                       dot != string::npos &&
                                                                                               at > 0 &&
                                                                                                       dot > at + 1;
                                                                        }
                                                                    
                                                                    bool isValidPhone(const string& phone)
                                                                {
                                                                        if (phone.length() != 10)
                                                                            return false;
                                                                        
                                                                            for (char c : phone)
                                                                            {
                                                                                        if (!isdigit(static_cast<unsigned char>(c)))
                                                                                                return false;
                                                                            }
                                                                        
                                                                            return true;
                                                                }
                                                            
                                                            string currentDate()
                                                        {
                                                                time_t now = time(nullptr);
                                                                tm* localTime = localtime(&now);
                                                            
                                                                stringstream ss;
                                                            
                                                                ss << setfill('0')
                                                                   << setw(2) << localTime->tm_mday
                                                                       << "/"
                                                                           << setw(2) << localTime->tm_mon + 1
                                                                               << "/"
                                                                                   << localTime->tm_year + 1900;
                                                                                
                                                                                    return ss.str();
                                                        }
                                                    
                                                    class Student
                                                {
                                                    private:
                                                    int id;
                                                    string name;
                                                    int age;
                                                    string gender;
                                                    string email;
                                                    string phone;
                                                    string course;
                                                    int semester;
                                                    string city;
                                                    double marks[SUBJECT_COUNT];
                                                    double attendance;
                                                    double totalFees;
                                                    double paidFees;
                                                    string admissionDate;
                                                
                                                public:
                                                Student()
                                                {)
                                            }
                }
}