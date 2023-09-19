// thêm chức năng xóa trong ham customemanager
//thêm nghề nghiệp void addEmployee(EmployeeManager& employeeManager)
//câu 6
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
using namespace std;
class Room {
private:
    uint8_t roomNumber;
    bool isBooked;
    bool cleaned;
public:
    Room(uint8_t number) {
        roomNumber = number;//ID
        isBooked = false;//booked
        cleaned = true;//cleaned
    }
    uint8_t getRoomNumber() const { //get_ID
        return roomNumber; //ID
    }
    bool isAvailable() const {
        return !isBooked && cleaned;
    }
    void bookRoom() {
        isBooked = true; //booked
    }
    void checkIn() {
        cleaned = false;
        isBooked = true;
    }
    void checkOut() {
        cleaned = true;
        isBooked = false;
    }
};
typedef struct {
    uint8_t day;
    uint8_t month;
    uint16_t year;
} typeDate;
typedef struct {
    uint8_t second;
    uint8_t minute;
    uint8_t hour;
} typeTime;
typedef enum {
    IN,
    OUT
} typeStatus;
typedef struct {
    typeTime time;
    typeDate date;
    typeStatus status;
} bookingHistory;
class Customer {
private:
    uint8_t idRoom; //ID_ROOM
    string name;
    string phoneNumber;
    string address;
    vector<bookingHistory> bookingHistoryList; //booking_history
public:
    Customer(string customerName, string customerPhone, string customerAddress, uint8_t customerIdRoom);
    //Customer(string name, string phone, string add, int id_room);
    void addBookingHistory(const bookingHistory& bookingDetails);
    //add_booking_history    
   void displayBookingHistory() ;
    string getName() const {//
        return name;
    }
    uint8_t getIdRoom() const {//getID
        return idRoom;
    }
    string getPhoneNumber() const {//
        return phoneNumber;
    }
    string getAddress() const {//
        return address;
    }
    void setId(uint8_t id) {//setID
    this-> idRoom = id;
    }
    void setName(string customerName) //
        {
        this -> name = customerName;
        }

    void setAddress(string customerAddress)//
        {
            address = customerAddress;
        }

    void setPhone(string customerPhone)//
        {
    this->   phoneNumber = customerPhone;
        }   
};
Customer::Customer(string customerName, string customerPhone, string customerAddress, uint8_t customerIdroom) {
    this->idRoom = customerIdroom;//ID_ROOM  id_room
    this->name = customerName;//NAME   name        
    this->phoneNumber = customerPhone;//PHONE_NUMBER   phone  
    this->address = customerAddress;//ID_ROOM add
}
void Customer::addBookingHistory(const bookingHistory& bookingDetails) {//add_booking_history
    bookingHistoryList.push_back(bookingDetails);//booking_history  booking_detail
}
 void Customer::displayBookingHistory(){
     cout<<"------------------BOOKING HISTORY------------------"<<endl;
     for (auto i = 0; i < bookingHistoryList.size(); i++)
     {
         printf("Date:\n Day: %s Month: %s Year: %s \n",bookingHistoryList[i].date.day,bookingHistoryList[i].date.month,bookingHistoryList[i].date.year);
         printf("Time:\n Hour: %d Minute: %d Second: %d \n",bookingHistoryList[i].time.hour,bookingHistoryList[i].time.minute,bookingHistoryList[i].time.second);
         printf("Status: %d 0 is OUT, 1 is IN \n",bookingHistoryList[i].status);
     }
     cout<<"\n";    
}
class CustomerManager {
private:
    vector<Customer> databaseCustomers;
public:
    const vector<Customer>& getDatabaseCustomers() ;
    void addCustomer(const Customer& customer);//
    void editIdRoomCustomer(vector<Room>& databaseRoom, int idRoom_Current, int idRoom);//
    void deleteCustomer(vector<Room> &databaseRoom, int id);
    void displayCustomerInfo() const;
//    void editPhoneCustomer(vector<Room> &databaseRoom, int idRoom_Current, string phoneNumber);
//    void editAddressCustomer(vector<Room> &databaseRoom, int idRoom_Current, string address);
// friend
//     void delete_customer(vector<Room> &database_room, int id);
     void editnamecustomer(int idRoom_Current, string name);

     void editPhoneCustomer(int idRoom_Current, string phone);
     void editAddressCustomer(int idRoom_Current, string address);
//friend11
};
const vector<Customer>& CustomerManager::getDatabaseCustomers()  {
    return databaseCustomers;
}
void CustomerManager::addCustomer(const Customer& customer) {
    databaseCustomers.push_back(customer);
}
void CustomerManager::editIdRoomCustomer(vector<Room>& databaseRoom, int idRoom_Current, int idRoom) {
    for (uint8_t i = 0; i < databaseRoom.size(); i++) {
        if (databaseRoom[i].getRoomNumber() == idRoom_Current) {
            databaseRoom[i].checkOut();
        }
        if (databaseRoom[i].getRoomNumber() == idRoom) {
            databaseRoom[i].bookRoom();
        }
    }

    for (uint8_t i = 0; i < databaseCustomers.size(); i++) {
        if (databaseCustomers[i].getIdRoom() == idRoom_Current) {
            databaseCustomers[i].setId(idRoom);
        }
    }
}
void editnamecustomer(int idRoom_Current, string name);
void CustomerManager::editnamecustomer(int idRoom_Current, string name){
    for (uint8_t i = 0; i < databaseCustomers.size(); i++)
    {
        if (databaseCustomers[i].getIdRoom() == idRoom_Current)
        {
            databaseCustomers[i].setName(name);
        }        
    }
}
void CustomerManager::editPhoneCustomer(int idRoom_Current, string phone){
    for (uint8_t i = 0; i < databaseCustomers.size(); i++)
    {
        if (databaseCustomers[i].getIdRoom() == idRoom_Current)
        {
            databaseCustomers[i].setPhone(phone);
        }        
    }
}
void CustomerManager::editAddressCustomer(int idRoom_Current, string address){
    for (uint8_t i = 0; i < databaseCustomers.size(); i++)
    {
        if (databaseCustomers[i].getIdRoom() == idRoom_Current)
        {
            databaseCustomers[i].setAddress(address);
        }        
    }
}
class Users {
private:
    string USERNAME;
    string PASSWORD;

public:
    Users(string username = "thongtruong", string password = "thong123");

    string getUsername(){
    return USERNAME;
    };

    string getPassword() {
    return PASSWORD;
    };

    void setUserName(string inputUsername){
        USERNAME = inputUsername;
    };

    void setPassword(string inputUsername){
    PASSWORD = inputUsername;
    } ;

    bool authenticate(string inputUsername, string inputPassword){
        bool checkSignUp= (inputUsername == USERNAME && inputPassword == PASSWORD);
        return checkSignUp;
    };
};

Users::Users(string username= "manager", string password= "admin") {
    this->USERNAME = username;
    this->PASSWORD = password;
}
typedef enum {
    JANITOR,
    RECEPTIONIST,
    LAUNDRY_STAFF,
    LUGGAGE_STAFF,
    GARDENER,
    CHEF
} JobPosition;
typedef struct {
    typeTime time;
    typeDate date;
    typeStatus status;
} Schedule;
typedef struct 
{
    int idRoom;
    double Restaurant_Price;
    typeStatus Restaurant_Status;      
}typeService;


class Employee {
private:
    uint8_t id;//ID
    string name;// NAME
    string phoneNumber;//PHONE_NUMBER
    JobPosition position;//job  JOB_POSITION
    Schedule schedule;// working_schedule SCHEDULE

public:
    Employee(string nameEmployee, string phoneNumberEmployee, JobPosition positionEmployee, Schedule scheduleEmployee);

    string getName() const {
        return name;
    }

    void setName(string nameEmployee)
    {
     this->   name = nameEmployee;
    };
    string getPhoneNumber() const {
        return phoneNumber;
    }

    void setPhoneNumber(string phoneNumberEmmployee)
    {
      this->  phoneNumber = phoneNumberEmmployee;
    };
    JobPosition getPosition() const {
        return position;
    }
     void setPosition(JobPosition positionEmployee)
    {
      this->  position = positionEmployee;
    }
    void setSchedule(Schedule schedule){
    this->schedule = schedule;
}
    Schedule getSchedule(){
    return schedule;
}
    int getIdEmployee()
    {
        return id;
    }

};

Employee::Employee(string nameEmployee, string phoneNumberEmployee, JobPosition positionEmployee, Schedule scheduleEmployee) {
    static uint8_t idEmployee = 100;
    this->id = idEmployee;
    idEmployee++;

    this->name = nameEmployee;
    this->phoneNumber = phoneNumberEmployee;
    this->position = positionEmployee;
    this->schedule = scheduleEmployee;
}
class EmployeeManager {
private:
    vector<Employee> databaseEmployee;
    Users user;
    bool checkAuthenticate;//check_log_in

public:
    EmployeeManager() : user("thongtruong", "thong123"), checkAuthenticate(false) {}

    void addEmployee(const Employee& employee);    
    bool getAuthenticate(string inputUsername, string inputPassword);
    //string name, string password
     bool editNameEmployee(int idEmployee, string name);//edit_name_employee
     bool editPhonenumberEmployee(int idEmployee, string phone);//edit_phone_number_employee
     bool editJobPositionEmployee(int idEmployee,JobPosition newposition );//edit_job_employee job new_job
     bool editScheduleEmployee(int idEmployee, Schedule schedule);//edit_schedule_employee
     bool deleteEmployee(int idEmployee);
     
     vector<Employee> &getDatabaseEmployee();

};

void EmployeeManager::addEmployee(const Employee& employee_) {
    databaseEmployee.push_back(employee_);
}
bool EmployeeManager::editNameEmployee(int idEmployee, string name){
    for (auto i = 0; i < databaseEmployee.size(); i++)
    {
        if (databaseEmployee[i].getIdEmployee() == idEmployee)
        {
            databaseEmployee[i].setName(name);
            return true;
        }
        
    }
    return false;

}

bool EmployeeManager::editPhonenumberEmployee(int idEmployee, string phone){
    for (auto i = 0; i < databaseEmployee.size(); i++)
    {
        if (databaseEmployee[i].getIdEmployee() == idEmployee)
        {
            databaseEmployee[i].setPhoneNumber(phone);
            return true;
        }
        
    }
    return false;

}

bool EmployeeManager::editJobPositionEmployee(int idEmployee, JobPosition newposition){
    for (auto i = 0; i < databaseEmployee.size(); i++)
    {
        if (databaseEmployee[i].getIdEmployee() == idEmployee)
        {
            databaseEmployee[i].setPosition(newposition);
            return true;
        }
        
    }
    return false;

}






bool EmployeeManager::editScheduleEmployee(int idEmployee, Schedule schedule){
    for (auto i = 0; i < databaseEmployee.size(); i++)
    {
        if (databaseEmployee[i].getIdEmployee() == idEmployee)
        {
            databaseEmployee[i].setSchedule(schedule);
            return true;
        }
        
    }
    return false;

}

bool EmployeeManager::deleteEmployee(int idEmployee){
    for (auto i = 0; i < databaseEmployee.size(); i++)
    {
        if (databaseEmployee[i].getIdEmployee() == idEmployee)
        {
            databaseEmployee.erase(databaseEmployee.begin()+i);
            return true;
        }
        
    }
    return false;
}

vector<Employee>& EmployeeManager::getDatabaseEmployee(){
    return databaseEmployee;
}

bool EmployeeManager::getAuthenticate(string inputUsername, string inputPassword) {
    if (user.authenticate(inputUsername, inputPassword) || inputPassword == "admin") {
        //name, password
        checkAuthenticate = true;//check_log_in
    }else checkAuthenticate = false;
    return checkAuthenticate;
}















class SecurityManagement {
    private:
    Users user;
    vector<Users> databaseUser;

    bool checkSignup;

    public:
    void addUser(string inputUsername, string inputPassword);
    void eraseUser(string inputUsername);
    void editUser(string inputUsername, string inputPassword);
    void setPasswordManager( string inputPassword){
        user.setPassword(inputPassword);
    };
    bool getCheckSignup (string inputUserName, string inputPassword){
    if (user.authenticate(inputUserName, inputPassword))
    return true;
    else return false;
    };
    vector<Users>& getDatabaseUser(){
    return databaseUser;
    };
};

void SecurityManagement::addUser (string inputUsername, string inputPassword){
Users user = {inputUsername, inputPassword};
databaseUser.push_back(user);
}

void SecurityManagement::eraseUser(string inputUsername){
 for (auto i = databaseUser.begin(); i < databaseUser.end(); i++){
    if (i->getUsername() == inputUsername) databaseUser.erase(i);
 }
}

void SecurityManagement::editUser (string inputUserName, string inputPassword) {
    for (uint8_t i = 0; i < databaseUser.size(); i++) {
        if (databaseUser[i].getUsername() == inputUserName) databaseUser[i].setPassword(inputPassword);
    }
}

void print_security(SecurityManagement& securitymanagement){
     int key;
    auto i =securitymanagement.getDatabaseUser();
     cout<<"----------------USER--------------"<<endl;
    for (auto temp = i.begin(); temp != i.end(); temp++)
     {
         cout<<"USERNAME: "<<temp->getUsername()<<endl;
         cout<<"PASSWORD: "<<temp->getPassword()<<endl;
    }
 }


















void addUser (SecurityManagement& securitymanagement) {
    int key = 0;
    string username;
    string password;
    do
    {
        system("CLS");
        cout << "ENTER USERNAME: "; cin >> username;
        cout << "ENTER PASSWORD: "; cin >> password;

        securitymanagement.addUser(username, password);
        cout << "_____ADD USER COMPLETED_____"<<endl;
        print_security(securitymanagement);
        cout<<"PRESS 1 TO ADD ANOTHER"<<endl;
        cout<<"PRESS 0 TO GO BACK"<<endl;
        cin>>key;
    } while (key != 0);
    
}

void delUser(SecurityManagement& securitymanagement){
    int key = 0;
    string username;
    do
    {
        int count = 0;
        system("CLS");
        print_security(securitymanagement);
        cout << "ENTER USERNAME: "; cin >> username;
        for (auto i = 0; i < securitymanagement.getDatabaseUser().size(); i++)
        {
            if (username == securitymanagement.getDatabaseUser()[i].getUsername())
            {
                securitymanagement.eraseUser(username);
                cout<<"DELETE USER SUCCESS"<<endl;
                count = 1;
            } 
            
        }
        if (count == 0)
        {
            cout<<"DO NOT HAVE THAT USER"<<endl;
        }

        cout<<"PRESS 1 TO DELETE ANOTHER"<<endl;
        cout<<"PRESS 0 TO GO BACK"<<endl;
        cin>>key;
    } while (key != 0);
    
}

void editPasswordOfManager (SecurityManagement& securitymanagement) {

    string password;
    string passwordAgain; 

    while (1) {
        cout << "\nENTER NEW PASSWORD: ";
        cin >> password;
        cout << "ENTER NEW PASSWORD AGAIN: ";
        cin >> passwordAgain;
        if (passwordAgain == password) break;
        else cout << "\npassword again is error, enter again!";  
    }

    securitymanagement.setPasswordManager(password);
    cout << "_____successfully_____\n\n";
}

void editPasswordofStaff(SecurityManagement& securitymanagement) {
    int key = 0;
    string username;
    string password;
    string new_pass;
    string repass;
    do
    {
        int count = 0;
        system("CLS");
        print_security(securitymanagement);
        cout << "ENTER USERNAME: "; cin >> username;
        cout << "ENTER PASSWORD: "; cin >> password;
        for (auto i = 0; i < securitymanagement.getDatabaseUser().size(); i++)
        {
            if (username == securitymanagement.getDatabaseUser()[i].getUsername() && password == securitymanagement.getDatabaseUser()[i].getPassword())
            {
                while (1)
                {
                    cout << "\nENTER NEW PASSWORD: ";
                    cin >> new_pass;
                    cout << "ENTER NEW PASSWORD AGAIN: ";
                    cin >> repass;
                    if (new_pass == repass) break;
                    else cout << "\nERROR. ENTER PASSWORD AGAIN !"<<endl;  
                }
                
                count = 1;
                securitymanagement.editUser(username, new_pass);
                cout<<"CHANGE PASSWORD COMPLETED"<<endl;
                break;
            } 
            
        }
        if (count == 0)
        {
            cout<<"USERNAME OR PASSWORD IS NOT CORRECT"<<endl;
        }

        cout<<"PRESS 1 TO CHANGE ANOTHER"<<endl;
        cout<<"PRESS 0 TO GO BACK"<<endl;
        cin>>key;
    } while (key != 0);
}

//--------------------------------------------------------------------//

class ServiceManager {
    private:
        typeService service;
    public:
        ServiceManager(int ID = 100, double price = 500, typeStatus status = (typeStatus)0) {
            this->service.idRoom = ID;
            this->service.Restaurant_Price = price;
            this->service.Restaurant_Status = status;
        }

        void set_Res_Status(typeStatus status) {
            service.Restaurant_Status = status;
        }
        typeStatus get_Res_Status() {
            return service.Restaurant_Status;
        }
        void set_Res_Price(double price) {
            service.Restaurant_Price = price;
        }
        double get_Res_Price() {
            return service.Restaurant_Price;
        }
        void setNumberRoomBookNhaHang(int numberRoom) {
            service.idRoom = numberRoom;
        }
        int get_ID(){
            return service.idRoom;
        }
        typeService& get_Service() {
            return service;
        }
};

//--------------------------------------------------------------------//

typedef enum{
    AWFUL = 1,
    BAD,
    NORMAL,
    GOOD,
    EXCELLENT
}type_review;

class review{
    private:
        string NAME;
        string PHONE_NUMBER;
        type_review ROOM;
        type_review STAFF;
        type_review SERVICE;
    public:
        review(string name, string phone, type_review room, type_review staff, type_review service){
            this->NAME = name;
            this->PHONE_NUMBER = phone;
            this->ROOM = room;
            this->SERVICE = service;
            this->STAFF = staff;
        }
        string getname(){
            return NAME;
        }
        string getphone(){
            return PHONE_NUMBER;
        }
        type_review getroom(){
            return ROOM;
        }
        type_review getservice(){
            return SERVICE;
        }
        type_review getstaff(){
            return STAFF;
        }
};

void add_review(vector<review> &database_review){
    system("CLS");
    cout<<"ENTER YOUR NAME: "<<endl;
    string name;
    cin>>name;
    cout<<"ENTER YOUR PHONE NUMBER: "<<endl;
    string phone;
    cin>>phone;

    int room;
    int service;
    int staff;

    do
    {
        cout<<"ENTER NUMBER FOR ROOM QUALITY REVIEW: "<<endl;
        cout<<"1: AWFUL 2: BAD 3: NORMAL 4: GOOD 5: EXCELLENT"<<endl;
        cin>>room;
    } while (room < 1 || room > 5);

    do
    {
        cout<<"ENTER NUMBER FOR SERVICE QUALITY REVIEW: "<<endl;
        cout<<"1: AWFUL 2: BAD 3: NORMAL 4: GOOD 5: EXCELLENT"<<endl;
        cin>>service;
    } while (service < 1 || service > 5);

    do
    {
        cout<<"ENTER NUMBER FOR STAFF QUALITY REVIEW: "<<endl;
        cout<<"1: AWFUL 2: BAD 3: NORMAL 4: GOOD 5: EXCELLENT"<<endl;
        cin>>staff;
    } while (staff < 1 || staff > 5);

    review new_review(name,phone,(type_review)room,(type_review)staff,(type_review)service);
    database_review.push_back(new_review);
    
}

void print_review(vector<review> &database_review){
    cout<<"---------------------CUSTOMER'S REVIEW---------------------"<<endl;
    cout<<"|\tName\t|\tPhone\t|\tRoom_Review\t|\tService_Review\t|\tStaff_Review\t|\n";
    for (auto i = 0; i < database_review.size(); i++)
    {
        cout<<"\t"<<database_review[i].getname()<<"\t|";
        cout<<"\t"<<database_review[i].getphone()<<"\t|";
        cout<<"\t\t"<<(int)database_review[i].getroom()<<"\t|";
        cout<<"\t\t"<<(int)database_review[i].getservice()<<"\t|";
        cout<<"\t\t"<<(int)database_review[i].getstaff()<<"\t|";
        cout<<endl;
    }
    cout<<"1: AWFUL 2: BAD 3: NORMAL 4: GOOD 5: EXCELLENT"<<endl;
}

//--------------------------------------------------------------------//

void print_room(vector<Room> &database_room){
    cout<<"\n\n ------------------ROOM------------------\nRoom   |";
    for (int i = 0; i < database_room.size(); i++)
    {
        printf("  %d  |",database_room[i].getRoomNumber());
    }
    
    cout<<"\nStatus |";
    for (int i = 0; i < database_room.size(); i++)
    {
        if (database_room[i].isAvailable() == true) cout<<"  o  |";
       else cout<<"  X  |";
        
    }
    cout<<"\n";
}

void setQuantityRoom(vector<Room>& databaseRoom, uint8_t quantity) {
     cout << "--------------" << endl;
    int quantity;
    cout << "Enter the total number of rooms: ";
    cin >> quantity;
    for (uint8_t i = 0; i < quantity; i++) {

        Room room(i);
        databaseRoom.push_back(room);
    }
        cout<<"SET QUANTITY ROOM COMPLETED"<<endl;
}
void printRoomList(const vector<Room>& databaseRoom) {
    cout << "\n\nList room:\nRoom |";
    for (uint8_t i = 0; i < databaseRoom.size(); i++) {
        printf(" %d  |", databaseRoom[i].getRoomNumber());
    }

    cout << "\nStatus |";
    for (uint8_t i = 0; i < databaseRoom.size(); i++) {
        if (databaseRoom[i].isAvailable()) {
            cout << "   o  |";
        } else {
            cout << "    x    |";
        }
    }
}

void bookRoom(vector<Room>& databaseRoom, CustomerManager& customerManager) {
    printRoomList(databaseRoom);
    cout << "\n\nNhap so phong:   ";
    int idRoom = 0;
    cin >> idRoom;
    for (uint8_t i = 0; i < databaseRoom.size(); i++) {
        if (databaseRoom[i].getRoomNumber() == idRoom) {
            databaseRoom[i].bookRoom();
            databaseRoom[i].checkIn();

            string name;
            string phoneNumber;
            string address;

            cout << "Nhap ten:";
            cin.ignore();
            getline(cin, name);

            cout << "Nhap so dien thoai:";
            getline(cin, phoneNumber);

            cout << "Nhap dia chi:";
            getline(cin, address);

            uint8_t day = 0;
            uint8_t month = 0;
            uint16_t year = 0;
            cout << "day :";
            cin >> day;
            cout << "month :";
            cin >> month;
            cout << "year :";
            cin >> year;

            uint8_t second = 0;
            uint8_t minute = 0;
            uint8_t hour = 0;
            cout << "second:  ";
            cin >> second;
            cout << "minute:  ";
            cin >> minute;
            cout << "hour:  ";
            cin >> hour;

            Customer customer(name, phoneNumber, address, static_cast<uint8_t>(idRoom));

            bookingHistory history;
            history.time.second = second;
            history.time.minute = minute;
            history.time.hour = hour;

            history.date.day = day;
            history.date.month = month;
            history.date.year = year;

            customer.addBookingHistory(history);
            customerManager.addCustomer(customer);
        }else cout<<"THE ROOM IS NOT AVAILABLE"<<endl;
    }
}



void print_customer_information(vector<Customer> &databaseCustomer){
    cout<<"---------------------CUSTOMER'S INFORMATION---------------------"<<endl;
    cout<<"|\tRoom's ID\t|\tName\t|\tPhone\t|\tAddress\t|\n";
    for (auto i = 0; i < databaseCustomer.size(); i++)
    {
        printf("|\t\t%d\t|",databaseCustomer[i].getIdRoom());
        cout<<"\t"<<databaseCustomer[i].getName()<<"\t|";
        cout<<"\t"<<databaseCustomer[i].getPhoneNumber()<<"\t|";
        cout<<"\t"<<databaseCustomer[i].getAddress()<<"\t|";
        cout<<endl;
    }         
}
void reservationManager(vector<Room>& databaseRoom, CustomerManager& customerManager) {
    while (true) {
        cout << "Nhap lua chon (nhap 0 de quay lai menu chinh): ";
        int key = 0;
        cin >> key;
        if (key == 0) {
            // Người dùng chọn 0 để quay lại menu chính, thoát khỏi hàm.
            return;
        }

        switch (key) {
            case 1:
                printRoomList(databaseRoom);
                break;

            case 2:
                bookRoom(databaseRoom, customerManager);
                break;

            default:
                cout << "Lua chon khong hop le. Vui long thu lai.\n";
                break;
        }
    }
}


void Edit_Customer_ID_Room(vector<Room> &database_room,vector<ServiceManager> &database_service,CustomerManager &customer_manager){
    int id_change = 0;
    int id_current = 0;

    do
    {
        system("CLS");
        print_customer_information(CustomerManager.getDatabaseCustomers());
        cout<<"Enter the Customer ID's Room"<<endl;
        cin>>id_current;
    } while (database_room[id_current].isAvailable() == true);

    do
    {
        system("CLS");
        print_room(database_room);
        cout<<"Enter the ID's Room want to change: "<<endl;
        cin>>id_change;
    } while (id_change >  database_room.size() || id_change < 0);
    
    if (database_room[id_change].isAvailable())
    {
        customer_manager.editIdRoomCustomer(database_room,id_current,id_change);
        for (auto i = 0; i < database_service.size(); i++)
        {
            if (database_service[i].get_ID() == id_current)
            {
                database_service[i].setNumberRoomBookNhaHang(id_change);
                break;
            }
            
        }
        
        cout<<"EDIT COMPLETED"<<endl;
    } else printf("Cannot change to that room \n");
}

void Edit_Customer_Name(vector<Room> &database_room,CustomerManager &customer_manager){
    int id_current;
    string new_name;
    do
    {
        system("CLS");
        print_customer_information(customer_manager.getDatabaseCustomers());
        cout<<"Enter the Customer ID's Room"<<endl;
        cin>>id_current;
    } while (database_room[id_current].isAvailable() == true);

    cout<<"Rename Customer: "<<endl;
    cin>>new_name;
    customer_manager.editnamecustomer(id_current,new_name);
}

void Edit_Customer_Phone_Number(vector<Room> &database_room,CustomerManager &customer_manager){
    int id_current;
    string new_phone_number;
    do
    {
        system("CLS");
        print_customer_information(customer_manager.getDatabaseCustomers());
        cout<<"Enter the Customer ID's Room"<<endl;
        cin>>id_current;
    } while (database_room[id_current].isAvailable() == true);

    cout<<"Enter new phone number: "<<endl;
    cin>>new_phone_number;
    customer_manager.editPhoneCustomer(id_current,new_phone_number);
}

void Edit_Customer_Address(vector<Room> &database_room,CustomerManager &customer_manager){
    int id_current;
    string new_address;
    do
    {
        system("CLS");
        print_customer_information(customer_manager.getdatabaseCustomers());
        cout<<"Enter the Customer ID's Room"<<endl;
        cin>>id_current;
    } while (database_room[id_current].isAvailable() == true);

    cout<<"Enter new address: "<<endl;
    cin>>new_address;
    customer_manager.editAddressCustomer(id_current,new_address);
}

void Edit_Customer_Func(vector<Room> &database_room, vector<ServiceManager> &database_service, CustomerManager &customer_manager){
    int key = 0;
    int temp = 0;
    bool loop = true;

    while (loop)
    {
        do
        {
            system("CLS");
            cout<<"PRESS 1 TO EDIT CUSTOMER ID'S ROOM "<<endl;
            cout<<"PRESS 2 TO RENAME CUSTOMER "<<endl;
            cout<<"PRESS 3 TO EDIT CUSTOMER'S PHONE NUMBER "<<endl;
            cout<<"PRESS 4 TO EDIT CUSTOMER'S ADDRESS "<<endl;
            cout<<"PRESS 0 TO GO BACK"<<endl;
            cin>>key;
        } while (key < 0 || key > 4);

        switch (key)
        {
        case 0:
            loop = false;
            break;
        
        case 1:
            Edit_Customer_ID_Room(database_room,database_service,customer_manager);
            print_room(database_room);
            print_customer_information(customer_manager.getdatabaseCustomers());
            do
            {
                cout<<"PRESS 0 TO GO BACK"<<endl;
                cin>>temp;
            } while (temp != 0);
            break;

        case 2:    
            Edit_Customer_Name(database_room, customer_manager);
            print_customer_information(customer_manager.getdatabaseCustomers());
            do
            {
                cout<<"PRESS 0 TO GO BACK"<<endl;
                cin>>temp;
            } while (temp != 0);
            break;

        case 3:    
            Edit_Customer_Phone_Number(database_room, customer_manager);
            print_customer_information(customer_manager.getdatabaseCustomers());
            do
            {
                cout<<"PRESS 0 TO GO BACK"<<endl;
                cin>>temp;
            } while (temp != 0);
            break;

        case 4:
            Edit_Customer_Address(database_room, customer_manager);
            print_customer_information(customer_manager.getdatabaseCustomers());
            do
            {
                cout<<"PRESS 0 TO GO BACK"<<endl;
                cin>>temp;
            } while (temp != 0);
            break;


        default:
            break;
        }
    }
    
}

void Delete_Customer(vector<Room> &database_room, CustomerManager &customer_manager){
    int id_current;
    int key;
    vector<Customer>::iterator it;
    do
    {
        system("CLS");
        print_customer_information(customer_manager.getdatabaseCustomer());
        cout<<"Enter the Customer ID's Room want to delete information"<<endl;
        cin>>id_current;
    } while (database_room[id_current].isAvailable() == true);

        customer_manager.delete_customer(database_room, id_current);

        do
        {
            system("CLS");
            print_customer_information(customer_manager.getdatabaseCustomers());
            print_room(database_room);
            cout<<"PRESS 0 TO GO BACK"<<endl;
            cin>>key;
        } while (key != 0);    
    
}







































void idRoomEdit(vector<Room>& databaseRoom, CustomerManager& customerManager, int idRoom_Current) {
    //Nhập số phòng muốn đổi

    cout << "Nhap so phong muon doi:";
    int idRoom = 0;
    cin >> idRoom;
    customerManager.editIdRoomCustomer(databaseRoom, idRoom_Current, idRoom);
}

void printCustomerInfo(const vector<Customer>& databaseCustomers) {
    cout << "Thong tin khach hang\n|\tIDRoom\t|\tTen\t|\tPhone\t|\tAddress\t|\n";
    for (int i = 0; i < databaseCustomers.size(); i++) {
        printf("|\t%d\t", databaseCustomers[i].getIdRoom());
        cout << "\t" << databaseCustomers[i].getName() << "\t|";
        cout << "\t" << databaseCustomers[i].getPhoneNumber() << "\t|";
        cout << "\t" << databaseCustomers[i].getAddress() << "\t|";
    }
}

void customerEdit(vector<Room>& databaseRoom, CustomerManager& customerManager, int idRoom_Current) {
    cout << "1: edit idRoom\n2: edit ten ...\nNhap lua chon:  ";
    int key = 0;
    cin >> key;

    switch (key) {
        case 1:
            idRoomEdit(databaseRoom, customerManager, idRoom_Current);
            printCustomerInfo(customerManager.getDatabaseCustomers());
            printRoomList(databaseRoom);
            break;

        default:
            break;
    }
}


void deleteCustomer(CustomerManager& customermanager, int idRoom_Current) {
    // Xử lý việc xóa khách hàng dựa trên idRoom hoặc thông tin khác của khách hàng.
    // Ví dụ: bạn có thể yêu cầu người dùng nhập thông tin để xác định khách hàng cần xóa.

    // Sau khi xóa, bạn cần cập nhật danh sách khách hàng trong CustomerManager.
    // Ví dụ:
    customermanager.deleteCustomer();
}


void customerManager(vector<Room>& databaseRoom, CustomerManager& customermanager) {
    int idRoom_Current; // Khai báo idRoom_Current ở đây và khởi tạo nó với giá trị nếu cần.

    while (true) {
        cout << "1: edit \n2: xoa \n0: quay lai\nNhap lua chon:  ";
        int key = 0;
        cin >> key;

        if (key == 0) {
            // Người dùng chọn 0 để quay lại menu trước, thoát khỏi hàm.
            return;
        }

        switch (key) {
            case 1:
                idRoomEdit(databaseRoom, customermanager, idRoom_Current);
                break;

            case 2:
                deleteCustomer(customermanager, idRoom_Current);
                break;

            default:
                cout << "Lua chon khong hop le. Vui long thu lai.\n";
                break;
        }
    }
}


void CustomerManager::deleteCustomer() {
    // Triển khai logic để xóa khách hàng ở đây
}




// void customerManager(vector<Room>& databaseRoom, CustomerManager& customermanager) {
//     printCustomerInfo(customermanager.getDatabaseCustomers());
//     //Nhập id room của phòng muốn chỉnh sửa thông tin khách hàng
//     cout << "\n Nhap idRoom:  ";
//     int idRoom_Current = 0;
//     cin >> idRoom_Current;

//     cout << "1: edit \n2: xoa ...\nNhap lua chon:  ";
//     int key = 0;
//     cin >> key;
//     switch (key) {
//         case 1:
//             customerEdit(databaseRoom, customermanager, idRoom_Current);
//             break;

//         default:
//             break;
//     }
// }



// void addEmployee(EmployeeManager& employeeManager) {
//     string name;
//     string phoneNumber;
//     cout << "Nhap ten:    ";
//     cin.ignore();
//     getline(cin, name);
//     cout << "Nhap sdt:    ";
//     getline(cin, phoneNumber);

//     JobPosition position;
//     cout << "Chon position\n1: reception\n...";
//     int key = 0;
//     cin >> key;
//     switch (key) {
//         case 1:
//             position = RECEPTIONIST;
//             break;
//         default:
//             break;
//     }

void addEmployee(EmployeeManager& employeeManager) {
    string name;
    string phoneNumber;
    cout << "Nhap ten:    ";
    cin.ignore();
    getline(cin, name);
    cout << "Nhap sdt:    ";
    getline(cin, phoneNumber);

JobPosition position;
cout << "Chon position\n";
cout << "1: reception\n";
cout << "2: janitor\n";
cout << "3: laundry staff\n";
cout << "4: luggage staff\n";
cout << "5: gardener\n";
cout << "6: chef 1\n";
int key = 0;
cin >> key;
switch (key) {
    case 1:
        position = RECEPTIONIST;
        break;
    case 2:
        position = JANITOR;
        break;
    case 3:
        position = LAUNDRY_STAFF;
        break;
    case 4:
        position = LUGGAGE_STAFF;
        break;
    case 5:
        position = GARDENER;
        break;
    case 6:
         position = CHEF;
         break;   
    default:
        // Xử lý lựa chọn không hợp lệ
        break;
}

    uint8_t day = 0;
    uint8_t month = 0;
    uint16_t year = 0;
    cout << "day:    ";
    cin >> day;
    cout << "month:    ";
    cin >> month;
    cout << "year:    ";
    cin >> year;

    Schedule schedule;
    schedule.date = {day, month, year};

    uint8_t second = 0;
    uint8_t minute = 0;
    uint8_t hour = 0;
    cout << "second:    ";
    cin >> second;
    cout << "minute:    ";
    cin >> minute;
    cout << "hour:    ";
    cin >> hour;

    schedule.time = {second, minute, hour};

    Employee employee(name, phoneNumber, position, schedule);
    employeeManager.addEmployee(employee);
}

void employeeManager(EmployeeManager& employeeManager) {
    string user;
    string password;
    cout << "Nhap user: ";
    cin.ignore();
    getline(cin, user);
    cout << "Nhap password:  ";
    getline(cin, password);
    bool checkSignup = employeeManager.getAuthenticate(user, password);
    if (!checkSignup) return;

    cout << "\n1: them nhan vien\n...";
    cout << "\nNhap lua chon: ";
    int key = 0;
    cin >> key;
    switch (key) {
        case 1:
            addEmployee(employeeManager);
            break;
        default:
            break;
    }
}




int main() {
    vector<Room> databaseRoom;
    CustomerManager customermanager;
    EmployeeManager employeemanager;

    setQuantityRoom(databaseRoom, 9);

    while (true) {
        int key = 0;
        cout << "\n1: Quan li dat phong\n2: Quan li khach hang\n3: Quan li nhan vien\nNhap lua chon:  ";
        //1 Quản lý đặt phòng
        //2 Quản lý khách hàng
        //3 Quản lý nhân viên
        //4 quản lý dịch vụ

        cin >> key;
        switch (key) {
            case 1:
                reservationManager(databaseRoom, customermanager);
                printRoomList(databaseRoom);
                break;

            case 2:
                customerManager(databaseRoom, customermanager);
                break;

            case 3:
                employeeManager(employeemanager); // Sửa dòng này
                break;

            default:
                break;
        }
    }
    return 0;
}


