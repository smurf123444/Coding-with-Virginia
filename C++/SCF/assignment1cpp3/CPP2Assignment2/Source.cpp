#include <iostream>
#include "addressBookType.h"
#include "personType.h"
#include <sstream>

/*
i. Load the data into the address book from a disk.
iii. Search for a person by last name.
iv. Print the address, phone number, and date of birth (if it exists) of a
given person.
v. Print the names of the people whose birthdays are in a given month.
vii. Depending on the user’s request, print the names of all family
members, friends, or business associates.
*/
/*
Create the addressType class as outlined in the problem
Create the extpersonType class using the personType class as outlined in the problem

Create the addressBookType class using the extPersonType, addressType and dateType classes as outlined in the problem

Follow the listed operations (I), (iii), (iv), (v) and (vii) in the problem. You will need to create a menu with 5 options as follows (operations (ii) and (vi) are not required for this assignment)

In (i), do not load the file from disk – provide the user a menu option with the ability to enter the personal information, the date of birth information and the address information.  
You will need to create an array of 10 addressBookType objects and add an object to the array as the user data in entered.
The user should have the ability to use this menu option at any time using the program to enter another object.
You will need to keep track of the number of objects entered to make sure the user can not enter more than 10 objects.
in (iii) and (iv), provide a menu option to search by name and print the address, phone number and date of birth if the name exists.  Give an appropriate message if the name is not found
in (v), provide a menu option to enter a month of the year and display the name, address and phone number of the entries with birthdays in that month
in (vii), provide a menu option to enter the classification of a person (family, friend or business) and display the name, address and phone number of the entries with birthdays in that month
Provide a menu option to exit the program
Make sure the user does not exceed the 10 max limit of addressBookType objects at any point during the program
*/

bool searchFirstMethod(string input, addressBookType obj)
{
        if (input == obj.getFirstName())
        {
            return (true);
        }
        else
        {
            return (false);
        }
}
bool searchLastMethod(string input, addressBookType obj)
{
    if (input == obj.getLastName())
    {
        return (true);
    }
    else
    {
        return (false);
    }
}
bool searchDateMethod(int input, addressBookType obj)
{

    if (input == obj.getMonth())
    {
        return (true);
    }
    else
    {
        return (false);
    }
}
bool searchClassificationMethod(int input, addressBookType obj)
{
    if (input == obj.getClassification())
    {
        return (true);
    }
    else {
        return (false);
    }

}
int main(){
    addressBookType person[10];
    string personalFirstNameString = "", personalLastNameString = "";
    string dayString = "", monthString = "", yearString = "";
    string addressString = "", cityString =  "", stateString = "", zipString = "";
    string firstNameSearch = "", lastNameSearch = "", classificationString = "", phoneString = "";
    int day = 0, month = 0, year = 0, classificationInt = 0, phoneInt = 0;
    bool quit = false;
    string selectionString;
    int selection = 0;
    int i = 0, bookCount = 0;
    cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
    cout << "Welcome to SCF assignment 2" << endl;
    cout << endl;
    while (!quit)
    {
        cout << endl;
        cout << "Books Logged : " << bookCount << endl;
        if (bookCount == 0) {
            cout << endl;
            cout << "1. Enter Personal" << endl;
            cout << "6. Exit." << endl;
            cout << endl;
        } 
        else {
            cout << endl;
            cout << "Please Select one of the Following.." << endl;
            cout << "1. Enter Personal" << endl;
            cout << "2. Search By First Name" << endl;
            cout << "3. Search By Last Name" << endl;
            cout << "4. Search By Month" << endl;
            cout << "5. Search By Classification (Friend, Family or Buisness Associate" << endl;
            cout << "6. Exit." << endl;
        }
        cout << "Enter Here : ";
        getline(cin, selectionString);
        stringstream(selectionString) >> selection;
        cout << endl;
        if (bookCount < 10)
        {
            switch (selection) {
            case 1:
                cout << "Enter Personal Information" << endl;
                cout << endl;
                cout << "First Name : ";
                getline(cin, personalFirstNameString);
                cout << endl;
                cout << "Last Name : ";
                getline(cin, personalLastNameString);
                person[bookCount].setName(personalFirstNameString, personalLastNameString);
                cout << endl;
                cout << "Enter Date Information" << endl;
                cout << endl;
                cout << "Day : ";
                getline(cin, dayString);
                cout << endl;
                cout << "Month : ";
                getline(cin, monthString);
                cout << endl;
                cout << "Year : ";
                cout << endl;
                getline(cin, yearString);
                stringstream(dayString) >> day;
                stringstream(monthString) >> month;
                stringstream(yearString) >> year;
                person[bookCount].setDate(month, day, year);
                cout << "Address : ";
                getline(cin, addressString);
                cout << endl;
                cout << "City : ";
                getline(cin, cityString);
                cout << endl;
                cout << "State : ";
                getline(cin, stateString);
                cout << endl;
                cout << "Zip : ";
                getline(cin, zipString);
                cout << endl;
                cout << "Phone # : ";
                getline(cin, phoneString);
                cout << endl;
                cout << "Relation?" << endl;
                cout << "1. Family" << endl;
                cout << "2. Friend" << endl;
                cout << "3. Buisness" << endl;
                getline(cin, classificationString);
                stringstream(classificationString) >> classificationInt;
                stringstream(phoneString) >> phoneInt;
                person[bookCount].setPhoneNumber(phoneInt);
                person[bookCount].setClassification(classificationInt);
                person[bookCount].setAddress(addressString);
                person[bookCount].setCity(cityString);
                person[bookCount].setState(stateString);
                person[bookCount].setZip(zipString);
                //personal Informtaion
                bookCount++;
                break;
            case 2: 
                if (person[0].getFirstName() == "")
                {
                    cout << endl;
                    cout << "No Enteries to access " << endl;
                    cout << endl;
                    break;
                }
                cout << "Search by First Name, Please enter a First Name" << endl;
                getline(cin, firstNameSearch);
                while (i < 10)
                {   
                    if (searchFirstMethod(firstNameSearch, person[i]) == true) {
                        cout << "found name at object " << i++ << endl;
                    }
                    else
                    {
                        cout << endl;
                        i++;
                        cout << endl;
                    }
                }
                i = 0;
                break;
            case 3: 
                if (person[0].getFirstName() == "")
                {
                    cout << endl;
                    cout << "No Enteries to access " << endl;
                    cout << endl;
                    break;
                }
                cout << "Search By Last Name, Please enter a Last Name" << endl;
                getline(cin, lastNameSearch);
                while (i < 10) {
                    if (searchLastMethod(lastNameSearch, person[i]) == true)
                    {
                        cout << endl;
                        cout << "found name at object " << i++ << endl;
                        cout << endl;
                    }
                    else
                    {
                        cout << endl;
                        i++;
                        cout << endl;
                    }
                }
                i = 0;
                break;
            case 4: 
                if (person[0].getFirstName() == "")
                {
                    cout << endl;
                    cout << "No Enteries to access " << endl;
                    cout << endl;
                    break;
                }
                monthString = "";
                cout << "Search By Month, Please enter a Month" << endl;
                getline(cin, monthString);
                stringstream(monthString) >> month;
                while (i < 10)
                {
                        if (searchDateMethod(month, person[i]) == true)
                    {
                            cout << endl;
                        cout << "Found month at object " << ++i << endl;
                        cout << endl;
                    }
                    else
                    {
                    
                        i++;
                    }
                }

                i = 0;
                
                //  provide a menu option to enter a month of the year and display the name, address and phone number of the entries with birthdays in that month
                break;
            case 5:
                if (person[0].getFirstName() == "")
                {
                    cout << endl;
                    cout << "No Enteries to access " << endl;
                    cout << endl;
                    break;
                }
                i = 0;
                cout << "Search By Classification, Please enter a Selection." << endl;
                cout << "1. Seatch by Family" << endl;
                cout << "2. Search by Friend" << endl;
                cout << "3. Search by Buisness" << endl;
                cout << endl;
                cout << "Please Type Here then press [Enter] : ";
                getline(cin, classificationString);
                stringstream(classificationString) >> classificationInt;
                switch (classificationInt) {

                case 1:
                    cout << endl;
                    cout << "Searching By Family...";
                    while (i < 10)
                    {
                        if (searchClassificationMethod(classificationInt, person[i]) == true)
                        {
                            cout << endl;
                            cout << "Found Family at object " << ++i << endl;
                            cout << endl;
                        }
                        else
                        {

                            i++;
                        }
                    }
                    break;
                case 2:
                    cout << endl;
                    cout << "Searching all Friends...";
                    while (i < 10)
                    {
                        if (searchClassificationMethod(classificationInt, person[i]) == true)
                        {
                            cout << endl;
                            cout << "Found Friend at object " << ++i << endl;
                            cout << endl;
                        }
                        else
                        {

                            i++;
                        }
                    }
                    // search by Friend
                    break;
                case 3:
                    cout << endl;
                    cout << "Searching By Buisness...";
                    while (i < 10)
                    {
                        if (searchClassificationMethod(classificationInt, person[i]) == true)
                        {
                            cout << endl;
                            cout << "Found Buisness at object " << ++i << endl;
                            cout << endl;
                        }
                        else
                        {

                            i++;
                        }
                    }
                    // search by Buisness
                    break;
                }
                i = 0;
                // provide a menu option to enter the classification of a person (family, friend or business) and display the name, address and phone number of the entries with birthdays in that month
                break;
            case 6:
                quit = true;
                    cout << endl;
                    cout << "Exiting..." << endl;
                // Provide a menu option to exit the program
                break;
            default:
                cout << endl;
                cout << "Incorrect Selection" << endl;
                cout << endl;
                quit = true;
                break;
            }
        }
    }
     
    /*
    cout << person[0].getFirstName() << endl;
    cout << person[0].getLastName() << endl;
    */
    return (0);
}