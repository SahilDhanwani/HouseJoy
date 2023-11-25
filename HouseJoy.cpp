#include <iostream>
#include <fstream>
#include<string>
#include<cstring>
using namespace std;

int Index_Generator(int pin)
{
    int num;
    num = pin / 10000;
    num = num - 11;
    return num;
}

class Data
{
public:

    friend class files;
    // 2 byte space at initial is for pin code.
    char first_name[15]; //0-14
    char middle_name[15]; //15-29
    char last_name[15]; //30-44
    char city[20]; //45-64
    // char address[150];
    char phone_number[11]; //65-75
    char experience[3]; //76-78
    char password[17]; //79-96
    

    Data()
    {
        strcpy(first_name,"NO NAME");
        strcpy(middle_name,"NO NAME");
        strcpy(last_name ,"NO NAME");
        strcpy(city , "NA");
        strcpy(phone_number , "NA");
        strcpy(experience , "NA");
    }

    void get_data()
    {
    stateF:
        cout << "\nEnter your first name:";
        cin >> first_name;
        try
        {
            for (int i = 0;i < strlen(first_name);i++)
                if (!(first_name[i] >= 'A' && first_name[i] <= 'Z') && !(first_name[i] >= 'a' && first_name[i] <= 'z'))
                    throw 'f';
        }
        catch (char a)
        {
            cout << "\nIN-VALID DATA ENTERED!!! (only alphabets allowed)" << endl;
            goto stateF;
        }

    stateM:
        cout << "\nEnter your middle name:";
        cin >> middle_name;
        try
        {
            for (int i = 0;i < strlen(middle_name);i++)
                if (!(middle_name[i] >= 'A' && middle_name[i] <= 'Z') && !(middle_name[i] >= 'a' && middle_name[i] <= 'z'))
                    throw 'm';
        }
        catch (char a)
        {
            cout << "\nIN-VALID DATA ENTERED!!! (only alphabets allowed)" << endl;
            goto stateM;
        }

    ststeL:
        cout << "\nEnter your last name:";
        cin >> last_name;
        try
        {
            for (int i = 0;i < strlen(last_name);i++)
                if (!(last_name[i] >= 'A' && last_name[i] <= 'Z') && !(last_name[i] >= 'a' && last_name[i] <= 'z'))
                    throw 'l';
        }
        catch (char a)
        {
            cout << "\nIN-VALID DATA ENTERED!!! (only alphabets allowed)" << endl;
            goto ststeL;
        }

    stateC:
        cout << "\nEnter city:";
        cin >> city;
        try
        {
            for (int i = 0;i < strlen(city);i++)
                if (!(city[i] >= 'A' && city[i] <= 'Z') && !(city[i] >= 'a' && city[i] <= 'z'))
                    throw 'c';
        }
        catch (char a)
        {
            cout << "\nIN-VALID DATA ENTERED!!! (only alphabets allowed)" << endl;
            goto stateC;
        }

    stateP:
        cout << "\nEnter phone number:";
        cin >> phone_number;
        try
        {
            if (strlen(phone_number) != 10)
                throw 's';

            for (int i = 0;i < strlen(phone_number);i++)
                if (!(phone_number[i] >= '0' && phone_number[i] <= '9'))
                    throw 'e';
        }
        catch (char a)
        {
            if (a == 's')
            {
                cout << "\nENTER A VALID 10 DIGIT PHONE NUMBER!!!" << endl;
                goto stateP;
            }
            else
            {
                cout << "\nENTER A VALID PHONE NUMBER (only Numbers allowed)!!!" << endl;
                goto stateP;
            }
        }

    stateE:
        cout << "\nEnter experience(in years)";
        cin >> experience;
        try
        {
            if (!(strlen(experience) == 1 || strlen(experience) == 2))
                throw 's';

            for (int i = 0;i < strlen(experience);i++)
                if (!(experience[i] >= '0' && experience[i] <= '9'))
                    throw 'e';
        }
        catch (char a)
        {
            if (a == 's')
            {
                cout << "\nIN-VALID EXPERIENCE!!!" << endl;
                goto stateE;
            }
            else
            {
                cout << "\nENTER EXPERIENCE IN NUMBER OF YEARS (ex : 15)" << endl;
                goto stateE;
            }
        }
        
     stateP_W:
        cout << "\nEnter Password = ";
        cin >> password;
        try 
        {
            if (strlen(password) < 8 || strlen(password) > 16)
                throw 'l';
            
            bool small=false;
            bool capital=false;
            bool special=false;
            bool number=false;
            
            for (int i = 0; i < strlen(password); i++) 
            {
                if (small && capital && special && number)
                    break;
                    
                else 
                {
                    if(password[i] >= 'A' && password[i] <= 'Z')
                        capital = true;
                    else if(password[i] >= 'a' && password[i] <= 'z')
                        small = true;
                    else if(password[i] >= '0' && password[i] <= '9')
                        number = true;
                    else
                        special = true;
                }
            }
            
            if(!capital)
                throw 'c';
            if(!small)
                throw 's';
            if(!number)
                throw 'n';
            if(!special)
                throw 'p';
        } 
        
        catch (char a)
        {
            if(a == 'l')
                cout << "\nPassword must be 8 to 16 Characters Long."<< "\n";
            if(a == 'c')
                cout << "\nPassword must contain a Capital Character (A-Z)."<< "\n";
            if(a == 's')
                cout << "\nPassword must contain a small Character (a-z)."<< "\n";
            if(a == 'n')
                cout << "\nPassword must have at least One Digit (0-9)"<< "\n";
            if(a == 'p')
                cout << "\nPassword must contain a Special Character."<< "\n";
            goto stateP_W;
      } 
    }

    void put_data()
    {
        cout << "\nThe details are : ";
        cout << "\nFirst name:" << first_name;
        cout << "\nMiddle name:" << middle_name;
        cout << "\nLast name:" << last_name;
        cout << "\nCity:" << city;
        cout << "\nPhone number:" << phone_number;
        cout << "\nExperience:" << experience << " years";
    }

};

class array_structure
{
public:
    string file_name[5];

    array_structure(int index)
    {
        int num;
        num = index + 11;
        string a;
        a = to_string(num);
        file_name[0] = a + " Mechanic";
        file_name[1] = a + " Plumber";
        file_name[2] = a + " Electrician";
        file_name[3] = a + " Painter";
        file_name[4] = a + " Carpenter";
    }
};

class Hash_Table
{
public:

    array_structure* t;

    Hash_Table()
    {
        t = NULL;
    }

    array_structure* generate(int index)
    {
        t = new array_structure(index);
        return t;
    }
};

class HouseJoy
{
public:

    Hash_Table* s;

    HouseJoy()
    {
        s = new Hash_Table[89];
    }

    string get_file_name(int index)
    {
        int array_index, ch;
        string name_of_file;

        cout << "\n1)Mechanic \n2)Plumber \n3)Electrician \n4)Painter \n5)Carpenter";

    state_3:
        cout << " \nselect your field : ";
        cin >> ch;

        try
        {
            if (ch < 1 || ch>5)
                throw 'd';

            else
                array_index = ch - 1;

            if (s[index].t == NULL)
                s[index].t = s[index].generate(index);

            name_of_file = s[index].t->file_name[array_index];
            return name_of_file;
        }
        catch (char c)
        {
            if (c == 'd')
            {
                cout << "\n IN-VALID CHOICE ";
                goto state_3;
            }
            return NULL;
        }
    }
};

class files
{
    public : 
    fstream f;
    Data d1;
    
    void Read_whole_file(string file_name,int pin)
    {
        f.open(file_name, ios::in | ios::binary);
        f.seekg(0);
        while (!f.eof())
        {   
            f>>pin;
            cout<<pin<<endl;
            f.read((char*)&d1, sizeof(d1));
            d1.put_data();
        }
        f.close();
    }
    
    void Write(string file_name,int pin)
    {
        d1.get_data();
        f.open(file_name, ios::app | ios::binary);
        f<<pin;
        f.write((char*)&d1, sizeof(d1));
        f.close();
    }
    
    void Update(string file_name,int pin)
    {
        
    }
    
    void Delete(string file_name,int pin)
    {
        
    }
    
    void Search(string file_name,int pin)
    { 
        char unique_id[11];
        char mob_no[11];
        
        state_2 : 
        cout << "\nEnter your UNIQUE ID :";
        cin >> unique_id;
        try
        {
            if (strlen(unique_id) != 10)
                throw 's';

            for (int i = 0;i < strlen(unique_id);i++)
                if (!(unique_id[i] >= '0' && unique_id[i] <= '9'))
                    throw 'e';
        }
        catch (char a)
        { 
            cout << "\nIN-VALID UNIQUE ID ENTERED !!!" << endl;
            goto state_2;
        }
        
        f.open(file_name, ios::in | ios::binary);
        f.seekg(67);
        f.read((char*)mob_no,11);
        cout<<mob_no;
        f.close();
        
        
    }
    
    void DisplayData_one_pin(string file_name,int pin)
    {
        
    }
    
    void DisplayData_range_pin(string file_name,int pin)
    {
        
    }
};

int pin_code()
{
    int pin;
    state_0 : 
    cout << "\nEnter pin code of your region : ";
    cin >> pin;
    try
        {
            if (pin < 110000 || pin>999999)
                throw 'a';
            return pin;
        }
    catch (char c)
        {
            cout << endl << "IN-VALID PIN CODE!!!" << endl;
            goto state_0;
        }
}

int main()
{
    files f;
    HouseJoy H1;
    int pin, index, ch1 = 1,ch2;
    string file_name;

    while (ch1)
    {
        cout << "\n    Select any one : " << endl;
        cout << "    1. I am a Home Maintainer" << endl;
        cout << "    2. I am a Customer" << endl;
        cout << "    3. Exit" << endl;
        cout << "    Enter your choice : ";
        cin >> ch1;

        if(ch1 == 3)
            return 0;
            
        switch (ch1)
        {
        case 1:
            
            state_1 : 
            cout << "\n    Select the task you wish to Perform : " << endl;
            cout << "    1. Add a new entry in system" << endl;
            cout << "    2. Search for your data in system" << endl;
            cout << "    3. Update/make changes to your data in system" << endl;
            cout << "    4. Delete your data from the system" << endl;
            cout << "    5. Go to Previous Screen" << endl;
            cout << "    Enter your choice : ";
            cin >> ch2;
            
            if(ch2 == 5)
                continue;
            pin = pin_code();
            index = Index_Generator(pin);
            file_name = H1.get_file_name(index);
            switch(ch2)
            {
                case 1 :
                    f.Write(file_name,pin);
                    break;
                
                case 2 : 
                    f.Search(file_name,pin);
                    break;
                    
                case 3 : 
                    f.Update(file_name,pin);
                    break;
                    
                case 4 : 
                    f.Delete(file_name,pin);
                    break;
                    
                default : 
                    goto state_1;
                    break;
                
            }
            
            break;

        case 2:
            pin = pin_code();
            index = Index_Generator(pin);
            file_name = H1.get_file_name(index);
            f.Read_whole_file(file_name,pin);
            break;

        default:
            cout << "enter valid choice";
            break;
        }
    }
    return 0;
}

