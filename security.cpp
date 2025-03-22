#include<iostream>
#include<fstream>   /*as we have to work with files*/
#include<sstream> /*provides templates*/
#include<string>

using namespace std;

int main()
{
    int a, i=0;
    string text, old, password1, password2, pass, name, password0, age, user, word, word1;
    string creds[2], cp[2];

    cout << "      Security System" << endl;
    cout << "________________________________" << endl << endl;
    cout << "|          1. Register          |" << endl;
    cout << "|          2. Login             |" << endl;
    cout << "|          3. Change Password   |" << endl;
    cout << "|__________4. End Program_______|" << endl << endl;

    do {
        cout << endl << endl;
        cout << "Enter Your Choice :-";
        cin >> a;
        switch (a)
        {
            case 1: {
                cout << "________________________" << endl << endl;
                cout << "|-------Register--------|" << endl;
                cout << "|______________________|" << endl;
                cout << "Please Enter Username :-";
                cin >> name;
                cout << "Please Enter the password :-";
                cin >> password0;
                cout << "Please Enter your age:-";
                cin >> age;

                ofstream of1("file.txt");
                if (of1.is_open()) {
                    of1 << name << "\n";
                    of1 << password0;
                    cout << "Registration Successful" << endl;
                }
                of1.close();
                break;
            }

            case 2: {
                i = 0;
                cout << "__________________________________" << endl << endl;
                cout << "|--------------Login-------------|" << endl;
                cout << "|________________________________|" << endl << endl;

                ifstream of2("file.txt");
                cout << "Please Enter the Username :-";
                cin >> user;
                cout << "Please Enter the Password :-";
                cin >> pass;

                if (of2.is_open()) {
                    while (getline(of2, text)) {
                        istringstream iss(text);
                        iss >> word;
                        creds[i] = word;
                        i++;
                    }
                    of2.close();

                    if (user == creds[0] && pass == creds[1]) {
                        cout << "---Login Successful--- " << endl << endl;
                        cout << "Details : " << endl;
                        cout << "Username : " << creds[0] << endl;
                        cout << "Password : " << creds[1] << endl;
                    } else {
                        cout << endl << endl;
                        cout << "Incorrect Credentials" << endl;
                        cout << "|    1. Press 2 to Login       |" << endl;
                        cout << "|    2. Press 3 to Change Password    |" << endl;
                    }
                }
                break;
            }

            case 3: {
                i = 0;
                cout << "----------------Change Password---------------" << endl;

                ifstream of0("file.txt");
                cout << "Enter the old password :-";
                cin >> old;

                if (of0.is_open()) {
                    while (getline(of0, text)) {
                        istringstream iss(text);
                        iss >> word1;
                        cp[i] = word1;
                        i++;
                    }
                    of0.close();

                    if (old == cp[1]) {
                        ofstream of1("file.txt");
                        if (of1.is_open()) {
                            cout << "Enter your new password :-";
                            cin >> password1;
                            cout << "Enter your password again :-";
                            cin >> password2;

                            if (password1 == password2) {
                                of1 << cp[0] << "\n";
                                of1 << password1;
                                cout << "Password changed successfully" << endl;
                            } else {
                                of1 << cp[0] << "\n";
                                of1 << old;
                                cout << "Passwords do not match" << endl;
                            }
                        }
                        of1.close();
                    } else {
                        cout << "Please enter a valid password" << endl;
                    }
                }
                break;
            }

            case 4: {
                cout << "___________________Thank you!___________________";
                return 0;
            }
            
            default:
                cout << "Enter a valid choice!";
        }
    } while (a != 4);

    return 0;
}
