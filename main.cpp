#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

class address {
protected:
    int aId;
    int streetNumber;
    char * streetName;
    char * city;
    char * stateAbbreviation;
    int zipCode;
    static int counter2;
public:
    int getAId(){return aId;}
    int getStreetNumber(){return streetNumber;}
    char * getStreetName(){return streetName;}
    char * getCity(){return city;}
    char * getStateAbbreviation(){return stateAbbreviation;}
    int getZipCode(){return zipCode;}

    void setAId(int id){aId = id;}
    void setStreetNumber(int number){streetNumber = number;}
    void setStreetName(char * name){
        int l = 0;
        while(name[l] != '\0')
        {
            l++;
        }

        streetName = new char[l+1];

        l=0;
        if(name[0] == ' ' || name[0] == '\t')
        {
            while(name[l+1] != '\0')
            {
                streetName[l] = name[l+1];
                l++;
            }
        }
        else
        {
            while(name[l] != '\0')
            {
                streetName[l] = name[l];
                l++;
            }
        }
        streetName[l] = '\0';
    }

    void setCity(char * c){
        int l = 0;
        while(c[l] != '\0')
        {
            l++;
        }

        city = new char[l+1];

        l=0;
        if(c[0] == ' ' || c[0] == '\t')
        {
            while(c[l+1] != '\0')
            {
                city[l] = c[l+1];
                l++;
            }
        }
        else
        {
            while(c[l] != '\0')
            {
                city[l] = c[l];
                l++;
            }
        }
        city[l] = '\0';
    }
    void setStateAbbreviation(char * state){
        int l = 0;
        while(state[l] != '\0')
        {
            l++;
        }

        stateAbbreviation = new char[l+1];

        l=0;
        if(state[0] == ' ' || state[0] == '\t')
        {
            while(state[l+1] != '\0')
            {
                stateAbbreviation[l] = state[l+1];
                l++;
            }
        }
        else
        {
            while(state[l] != '\0')
            {
                stateAbbreviation[l] = state[l];
                l++;
            }
        }
        stateAbbreviation[l] = '\0';
    }
    void setZipCode(int zip){zipCode = zip;}

    address(){
        aId = 0;
        streetNumber = 0;
        streetName = nullptr;
        city = nullptr;
        stateAbbreviation = nullptr;
        zipCode = 0;
    }
    ~address(){
        delete[] streetName;
        delete[] city;
        delete[] stateAbbreviation;
    }

    virtual void print() const {
        cout << "ID: " << aId << endl;
        cout << "Street Number: " << streetNumber << endl;
        cout << "Street Name: " << streetName << endl;
        cout << "City: " << city << endl;
        cout << "State Abbreviation: " << stateAbbreviation << endl;
        cout << "Zip Code: " << zipCode << endl;
        cout << "Counter: " << counter2 << endl;
    }
   
   friend void display2(address &a){
        if(a.aId != 0){
            cout << a.aId;
        }
        else{
            cout << "Default ID";
        }
        if(a.streetNumber != 0){
            cout << a.streetNumber;
        }
        else{
            cout << "Default Street Number";
        }
        if(a.streetName == nullptr){
            cout << "NOSTREET";
        }
        else{
            cout << a.streetName;
        }
        if(a.city == nullptr){
            cout << "NOCITY";
        }
        else{
            cout << a.city;
        }
        if(a.stateAbbreviation == nullptr){
            cout << "NOSTATE";
        }
        else{
            cout << a.stateAbbreviation;
        }
        if(a.zipCode != 0){
            cout << a.zipCode;
        }
        else{
            cout << "Default Zip Code";
        }
        if(a.counter2 != 0){
            cout << a.counter2;
        }
        else{
            cout << "Default Counter";
        }
    }

};

enum DEPARTMENT {DEFAULT, SALES, CUSTOMER_SERVICE, PRODUCTION, HUMAN_RESOURCES, ACCOUNTING, RESEARCH_AND_DEVELOPMENT};

class employee {
protected:
    int eId;
    char * fullName;
    DEPARTMENT department;
    static int counter;
public:
    int getEId(){return eId;}
    char * getFullName(){return fullName;}
    DEPARTMENT getDepartment(){return department;}

    void setEId(int id){eId = id;}
    void setDepartment(int dep){department = static_cast<DEPARTMENT>(dep);}
    void setFullName(char * name){
        int l = 0;
        while(name[l] != '\0')
        {
            l++;
        }

        fullName = new char[l+1];

        l=0;
        if(name[0] == ' ' || name[0] == '\t')
        {
            while(name[l+1] != '\0')
            {
                fullName[l] = name[l+1];
                l++;
            }
        }
        else
        {
            while(name[l] != '\0')
            {
                fullName[l] = name[l];
                l++;
            }
        }
        fullName[l] = '\0';
    }

    const char * getDepartmentName(){
        switch(department){
            case SALES:
                return "SALES";
            case CUSTOMER_SERVICE:
                return "CUSTOMER SERVICE";
            case PRODUCTION:
                return "PRODUCTION";
            case HUMAN_RESOURCES:
                return "HUMAN RESOURCES";
            case ACCOUNTING:
                return "ACCOUNTING";
            case RESEARCH_AND_DEVELOPMENT:
                return "RESEARCH AND DEVELOPMENT";
            default:
                return "DEFAULT";
        }
    }

    employee(){
        eId = 0;
        fullName = nullptr;
        department = DEFAULT;
        counter++;
    }
    ~employee(){
        delete[] fullName;
        counter--;
    }

    virtual void print(){
        cout << "ID: " << eId << endl;
        if(fullName == nullptr){
            cout << "Full Name: NONAME" << endl;
        }
        else{
            cout << "Full Name: " << fullName << endl;
        }
        cout << "Department: " << getDepartmentName() << endl;
        cout << "Counter: " << counter << endl;
    }

    friend void display(employee &e){
        if(e.eId != 0){
            cout << e.eId;
        }
        else{
            cout << "Default ID";
        }
        if(e.fullName == nullptr){
            cout << "NONAME";
        }
        else{
            cout << e.fullName;
        }
        if(e.department != DEFAULT){
            cout << e.getDepartmentName();
        }
        else{
            cout << "Default Department";
        }
        if(e.counter != 0){
            cout << e.counter;
        }
        else{
            cout << "\tDefault Counter";
        }
    }
};

int address::counter2 = 0;
int employee::counter = 0;

class record: public address, public employee {
public:

    record():address(), employee(){
        counter2++;
    }

    void print(address &a, employee &e){
        if(e.getEId() <= 19)
        {
        cout << left << setw(5) << e.getEId() << setw(20) << e.getFullName() << right << setw(4) << setfill('0') <<  a.getStreetNumber() << " " 
            << left << setw(20) << setfill(' ') << a.getStreetName() << setw(20) << a.getCity() << setw(10) << a.getStateAbbreviation()
            << setw(10) << a.getZipCode() << setw(15) << e.getDepartmentName() << endl;
        }
        else
        {
            cout << left << setw(5) << e.getEId() << setw(20) << e.getFullName() << right 
            << left << setw(25) << a.getStreetName() << setw(20) << a.getCity() << setw(10) << a.getStateAbbreviation()
            << setw(10) << a.getZipCode() << setw(15) << e.getDepartmentName() << endl;
        }
    }
};

int countRecords(const char filename[]) {
    ifstream file(filename);
    if (!file) {
        return -1; // Error opening the file
    }
    int count = 0;
    char buffer[1000];
    while (!file.eof()) {
        file.getline(buffer, sizeof(buffer));
        count++;
    }

    file.close();
    return count; // Return the number of records read
}

int readEmployees(const char filename[], employee *& eData, address *& aData, int size) {
    ifstream file(filename);
    if (!file) {
        return -2; // Error opening the file
    }
    int count = 0;
    int id;
    char buffer[1000];
    int helper;

    while (!file.eof() && count < size) {
        file >> id;
        file.getline(buffer, sizeof(buffer));
        file >> helper;

        eData[count].setEId(id);
        eData[count].setFullName(buffer);
        eData[count].setDepartment(helper);

        count++;
    }
    file.close();
    return count;
}

int readAddresses(const char filename[], address *& data, int size) {
    ifstream file(filename);
    if (!file) {
        return -3; // Error opening the file
    }
    int count = 0;
    int id;
    int streetNumber;
    char streetNameBuffer[1000];
    char cityBuffer[1000];
    char stateBuffer[1000];
    int zip;

    char noStreet[] = "NOSTREET";
    char noCity[] = "NOCITY";
    char noState[] = "NOSTATE";

    while (!file.eof() && count < size) {
        file >> id;
        file >> streetNumber;
        file.getline(streetNameBuffer, sizeof(streetNameBuffer));
        file.getline(cityBuffer, sizeof(cityBuffer));
        file >> stateBuffer;
        file >> zip;

        // data[count].setAddress(id, streetNumber, streetNameBuffer, cityBuffer, stateBuffer, zip);

        data[count].setAId(id);
        data[count].setStreetNumber(streetNumber);
        data[count].setStreetName(streetNameBuffer);
        data[count].setCity(cityBuffer);
        data[count].setStateAbbreviation(stateBuffer);
        data[count].setZipCode(zip);

        if(count > 19){
            data[count].setAId(count);
            data[count].setStreetName(noStreet);
            data[count].setCity(noCity);
            data[count].setStateAbbreviation(noState);
            data[count].setZipCode(0);
        }

        count++;
    }
    file.close();
    return count;
}

void sortID(employee * eData, int num_records){
    bool swap;
    employee temp;
    do{
        swap = false;
        for (int i=0; i<num_records - 1; i++){
            if (eData[i].getEId() > eData[i+1].getEId()){

                temp.setEId(eData[i].getEId());
                temp.setFullName(eData[i].getFullName());
                temp.setDepartment(eData[i].getDepartment());

                eData[i].setEId(eData[i+1].getEId());
                eData[i].setFullName(eData[i+1].getFullName());
                eData[i].setDepartment(eData[i+1].getDepartment());

                eData[i+1].setEId(temp.getEId());
                eData[i+1].setFullName(temp.getFullName());
                eData[i+1].setDepartment(temp.getDepartment());

                swap = true;

            }
        }
    } while(swap);
}

void sortZip(address * aData, int num_records){
    bool swap;
    address temp;
    do{
        swap = false;
        for (int i=0; i<num_records - 1; i++){
            if (aData[i].getZipCode() > aData[i+1].getZipCode()){

                temp.setAId(aData[i].getAId());
                temp.setStreetNumber(aData[i].getStreetNumber());
                temp.setStreetName(aData[i].getStreetName());
                temp.setCity(aData[i].getCity());
                temp.setStateAbbreviation(aData[i].getStateAbbreviation());
                temp.setZipCode(aData[i].getZipCode());

                aData[i].setAId(aData[i+1].getAId());
                aData[i].setStreetNumber(aData[i+1].getStreetNumber());
                aData[i].setStreetName(aData[i+1].getStreetName());
                aData[i].setCity(aData[i+1].getCity());
                aData[i].setStateAbbreviation(aData[i+1].getStateAbbreviation());
                aData[i].setZipCode(aData[i+1].getZipCode());

                aData[i+1].setAId(temp.getAId());
                aData[i+1].setStreetNumber(temp.getStreetNumber());
                aData[i+1].setStreetName(temp.getStreetName());
                aData[i+1].setCity(temp.getCity());
                aData[i+1].setStateAbbreviation(temp.getStateAbbreviation());
                aData[i+1].setZipCode(temp.getZipCode());

                swap = true;

            }
        }
    } while(swap);
}

int main() {
    char addressesFile[100];//
    char employeesFile[100];//

    int N = 0;
    record* data = nullptr;
    char option;
    bool check1 = false;
    bool check2 = false;
    bool check3 = false;
    bool check4 = false;

    employee * employees = nullptr;
    address * addresses = nullptr;

    int countAddress;
    int countEmployee;
    int count, count2;

    do {
        if(check3 == false)
        {
            cout << "\na.  Enter address file fullpath" << endl;
            cout << "b.  Enter employee file fullpath" << endl;
            cout << "c.  Read files" << endl;
            cout << "d.  Print data" << endl;
            cout << "e.  Search:" << endl;
            cout << "f.  Sort" << endl;
            cout << "g.  Exit" << endl;
            cin >> option;
        }
        else if(check3 == true){
            cout << "\na.  Enter address file fullpath" << endl;
            cout << "b.  Enter employee file fullpath" << endl;
            cout << "c.  Read files" << endl;
            cout << "        1.Print record by index" << endl;
            cout << "d.  Print data" << endl;
            cout << "e.  Search:" << endl;
            cout << "f.  Sort" << endl;
            cout << "g.  Exit" << endl;
            cin >> option;
        }

        while (getchar() != '\n');
        switch (option) {
        case 'a':{
            cout << "Enter the fullpath for addresses file: ";
            cin.getline(addressesFile, sizeof(addressesFile));
            countAddress = countRecords(addressesFile);
            if(countAddress < 0){
                cout << "[ERROR] - Enter file location first..." << endl;
                break;
            }
            else
            {
                cout << "[SUCCESS] - Addresses file is readable ..." << endl;
                check1 = true;
            }
            break;
        }
        case 'b':{
            cout << "Enter the fullpath for employees file: ";
            cin.getline(employeesFile, sizeof(employeesFile));
            countEmployee = countRecords(employeesFile);
            if(countEmployee < 0){
                cout << "[ERROR] - Enter file location first..." << endl;
                break;
            }
            else
            {
                cout << "[SUCCESS] - Employees file is readable ..." << endl;
                check2 = true;
            }

            break;
        }
        case 'c':{
            if(check1 == true && check2 == true){
                if(check3 == false)
                {
                    employees = new employee[countEmployee];
                    addresses = new address[countAddress];
                    count = readAddresses(addressesFile, addresses, countAddress);
                    count2 = readEmployees(employeesFile, employees, addresses, countEmployee);
                    if(count < 0 || count2 < 0){
                        cout << "[ERROR] - Error reading files ..." << endl;
                        break;
                    }
                    else
                    {
                        cout << "[SUCCESS] -  File reading is complete ..." << endl;
                        check3 = true;
                        break;
                    }
                }
            }
            else{
                cout << "[ERROR] - Enter file locations first ..." << endl;
            }

            if(check3 == true){
                cout << "Enter the index: ";
                int index;
                cin >> index;
                if(index >= 0 && index < countEmployee)
                {
                    cout << left << setw(5) << "ID" << setw(20) << "FULL NAME" << setw(25) 
                        << "STREET ADDRESS" << setw(20) << "CITY" << setw(10) << "STATE" << setw(10) 
                        << "ZIP" << setw(10) << "DEPARTMENT" << endl;
                    data->print(addresses[index], employees[index]);
                }
                else{
                    cout << "[ERROR] - Invalid index value ..." << endl;
                }
            }
            break;
        }
        case 'd':
         {
            if(check3 == true){
                cout << left << setw(5) << "ID" << setw(20) << "FULL NAME" << setw(25) 
                    << "STREET ADDRESS" << setw(20) << "CITY" << setw(10) << "STATE" << setw(10) 
                    << "ZIP" << setw(10) << "DEPARTMENT" << endl;
                char noStreet[] = "NOSTREET";
                char noCity[] = "NOCITY";
                char noState[] = "NOSTATE";
                if(check4 == false){
                    for(int i = 0; i < count2; i++){
                        bool matchFound = false;
                        for(int j = 0; j < count; j++){
                            if(employees[i].getEId() == addresses[j].getAId()){
                                data->print(addresses[j], employees[i]);
                                matchFound = true;
                                break;
                            }
                        }
                        if(!matchFound && i > 19){
                            addresses[i].setAId(i);
                            addresses[i].setStreetName(noStreet);
                            addresses[i].setCity(noCity);
                            addresses[i].setStateAbbreviation(noState);
                            addresses[i].setZipCode(0);
                            data->print(addresses[i], employees[i]);
                        }
                    }
                }
                else{
                    for(int i = 0; i < count2; i++){
                        bool matchFound = false;
                        for(int j = 0; j < count; j++){
                            if(employees[i].getEId() == addresses[j].getAId()){
                                matchFound = true;
                            }
                        }
                        if(!matchFound && i > 19){
                            addresses[i].setAId(i);
                            addresses[i].setStreetName(noStreet);
                            addresses[i].setCity(noCity);
                            addresses[i].setStateAbbreviation(noState);
                            addresses[i].setZipCode(0);
                            data->print(addresses[i], employees[i]);
                        }
                    }
                    for(int s = 0; s < count2; s++){
                        for(int t = 0; t < count2; t++){
                            if(employees[s].getEId() == addresses[t].getAId() && employees[s].getEId() > 19){
                                data->print(addresses[t], employees[s]);
                            }
                        }
                    }
                    for(int i = 0; i < count; i++){
                        for(int j = 0; j < count2; j++){
                            if(employees[j].getEId() == addresses[i].getAId()){
                                data->print(addresses[i], employees[j]);
                            }
                        }
                    }
                }
                cout << "There are " << count - 1 << " addresses, " << " and " << count2 << " employees." << endl;
            }
            else{
                cout << "[ERROR] - Read files first ..." << endl;
            }
            break;
         }
        case 'e':
         {  
            int choice, input;
            cout << "\t1." << "\tAddress ID" << endl;
            cout << "\t2." << "\tZipCode" << endl;
            cin >> choice;
            if (choice == 1){
                cout << "Enter the ID: ";
                cin >> input;
                for(int i = 0; i < count2; i++){
                    for(int j = 0; j < count; j++){
                        if(employees[i].getEId() == input){
                            if(employees[i].getEId() == addresses[j].getAId()){
                                data->print(addresses[j], employees[i]);
                            }
                        }
                    }
                }
            } else if(choice == 2){
                cout << "Enter the ZipCode: ";
                cin >> input;
                for(int i = 0; i < count2; i++){
                    for(int j = 0; j < count; j++){
                        if(employees[i].getEId() == addresses[j].getAId()){
                            if(addresses[j].getZipCode() == input){
                                data->print(addresses[j], employees[i]);
                            }
                        }
                    }
                }
            }
            else{
                cout << "[ERROR] - Invalid choice ..." << endl;
            }
            break;
         }
        case 'f':
        {
            int choice;
            cout << "\t1." << "\tAddress ID" << endl;
            cout << "\t2." << "\tZipCode" << endl;
            cin >> choice;
            if (choice == 1){
                sortID(employees, count2);
            }
            else if(choice == 2){
                check4 = true;
                sortZip(addresses, count);
            }
            else{
                cout << "[ERROR] - Invalid choice ..." << endl;
            }
            break;
        }
        case 'g':
            cout << "Ending the program ...\n";
            break;
        default:
            cout << "Invalid option, try again!\n";
            break;
        }

    } while (option != 'g' && option != 'G');




    return 0;
}