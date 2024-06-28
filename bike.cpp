#include<iostream>
#include<fstream>
#include<string>
using namespace std;
//create bike structure for store about bike details
struct bike{
    string no;
    string name;
    string price;
    string engine;

};
//global variables
struct bike b[15];
int counting=0;
int bike_list[100];
long total_prize;
int billno;
string fname;
string lname;
string place;
string nic;
int pmethod;
long totalm1;
long first_installment;

//methord-to check if string equals to int
int isNumber(string s)
    {
        for (int i = 0; i < s.length(); i++)
            if (isdigit(s[i]) == false)
                return 1;

        return 0;
    }
//custemor class
class custemer{
    public:
    //methord-to decide how many bikes and bike list are buy from customer
    void buy_bikes(){
        string string_counting;
        //to decide how many bikes will customer buy
        while(1){
            cout<<"\nHow many Bikes do you want:";
            cin>>string_counting;
            if(isNumber(string_counting)){
                cout<<"\nPlease enter correct number.....\n";
            }else{
                break;
            }
        }
        counting=stoi(string_counting);
        bike_list[counting];
        int i=0;
        string bikeno;
        //to enter bike list
        while(counting!=i){
            while(1){
                cout<<"\nEnter Bike No"<<i+1<<":";
                cin>>bikeno;
                if(isNumber(bikeno)){
                    cout<<"\nPlease enter correct number.....\n\n";
                }else{
                    break;
                }
            }
            bike_list[i]=stoi(bikeno);
            if(bike_list[i]>=0 && bike_list[i]<=14){
                i++;
            }else{
                cout<<"\nPlease enter correct bike no(0-14)........\n\n";
            }

        }
        //for testing-view customer enter bike list
        /*for(int k=0;k<counting;k++){
            cout<<bike_list[k]<<endl;
        }*/


    }
    //methord-to collect customer details
    void collect_details(){
        cout<<"\nEnter your first name\t:";
        cin>>fname;
        cout<<"Enter your last name\t:";
        cin>>lname;
        cout<<"Enter your Place name\t:";
        cin>>place;
        cout<<"Enter your NIC number\t:";
        cin>>nic;


    }
    //to confirm customer buy bikes
    void confirm_buy_bikes(){
        string confirm;
        while(1){
            cout<<"Do you like to buy these bikes(y/n):";
            cin>>confirm;
            for (int i = 0; i < confirm.length(); i++){
                    confirm[i] = tolower(confirm[i]);
                }

            if(confirm=="n" || confirm=="y"){
                if(confirm=="n"){
                    cout<<"\n\n|----Thank you----|\n\n";
                    exit(1);
                }else{
                    break;
                }
            }else{
                cout<<"\nPlease enter correct letter(y/n).....\n\n";
            }
        }
    }
    //methors-about payment details
    void payment_details(){
        string string_pmethord;
        while(1){
            cout<<"Enter your payment methord(1/2/3):";
            cin>>string_pmethord;
            if(!isNumber(string_pmethord)){
                pmethod=stoi(string_pmethord);
                if(pmethod==1 || pmethod==2 || pmethod==3){
                    break;
                }else{
                    cout<<"\nPlease enter 1/2/3 only....\n\n";
                }
            }else{
                cout<<"\nPlease enter letter only(1/2/3)....\n\n";
            }

        }
        //paying methord 1
        if(pmethod==1){
            string string_first_insallment;
            while(1){
                while(1){
                    cout<<"\nEnter your Total amount(Rs."<<totalm1<<"):Rs.";
                    cin>>string_first_insallment;
                    if(!isNumber(string_first_insallment)){
                        first_installment=stoi(string_first_insallment);
                        break;
                    }else{
                        cout<<"\nPlease enter correct numbers....\n\n";
                    }

                }

                if(first_installment>totalm1){
                    cout<<"\nYour Balance is:Rs."<<first_installment-totalm1<<endl;
                    cout<<"\n|---Thank you for your payment---|\n";
                    break;
                }else if(first_installment==totalm1){
                    cout<<"\n|---Thank you for your payment---|\n";
                    break;
                }else{
                    cout<<"\nYou must pay Rs."<<totalm1<<endl;
                }
            }

        }
        //paying method 2
        if(pmethod==2){
            string string_myfirst2;
            long totalm2;
            long myfirst2;
            first_installment=total_prize-(total_prize*50/100);
            while(1){
                while(1){
                    cout<<"\nEnter your first amount value(more than Rs."<<first_installment<<"):Rs.";
                    cin>>string_myfirst2;
                    if(!isNumber(string_myfirst2)){
                        myfirst2=stoll(string_myfirst2);
                        break;
                    }else{
                        cout<<"Please enter correct numbers....\n";
                    }

                }
                if(first_installment<=myfirst2){
                    if(total_prize<myfirst2){
                        cout<<"\nYour Balance is:Rs."<<myfirst2-total_prize<<endl;
                        cout<<"\n|---Thank you for your full payment---|\n";
                        break;
                    }
                    totalm2=(total_prize-myfirst2)/6;
                    cout<<"\n|---Thank you for your payment---|\n";
                    cout<<"\n|||---You have to pay more Rs."<<totalm2<<" with 6 installments---|||"<<endl;
                    break;
                }else{
                    cout<<"You must pay more than Rs."<<first_installment<<endl;
                }
            }

        }
        //paying method 3
        if(pmethod==3){
            string string_myfirst3;
            long totalm3;
            long myfirst3;
            first_installment=total_prize*25/100;
            while(1){
                while(1){
                    cout<<"\nEnter your first amount value(more than Rs."<<first_installment<<"):Rs.";
                    cin>>string_myfirst3;
                    if(!isNumber(string_myfirst3)){
                        myfirst3=stoll(string_myfirst3);
                        break;
                    }else{
                        cout<<"\nPlease enter correct numbers....\n";
                    }

                }
                if(first_installment<=myfirst3){
                        if(total_prize<myfirst3){
                            cout<<"\nYour Balance is:Rs."<<myfirst3-total_prize<<endl;
                            cout<<"\n|---Thank you for your full payment---|\n";
                            break;
                        }
                    totalm3=((total_prize-myfirst3)/36)+ ((total_prize-myfirst3)/36)*5/100;
                    cout<<"\n|---Thank you for your payment---|\n";
                    cout<<"\n|||---You have to pay more Rs."<<totalm3<<" with 36 installments---|||"<<endl;
                    break;
                }else{
                    cout<<"You must pay more than Rs."<<first_installment<<endl;
                }
            }

        }

    }




};
// company class
class company{
    public:
    // Bike art for command line interface
    void bike_art(){
       // cout<<"\t\t         0"<<endl;
        cout<<"\t\t\t     ___0_"<<endl;
        cout<<"\t\t\t  _ ` \ < , _"<<endl;
        cout<<"\t\t\t (*)   /   (*)\n"<<endl;
    }
    //methord-Details of bikes
    void bike_list(){

        int k=0;
        cout<<"\t\tWelocome to ABC Bike Company\n";
        cout<<"\t\t----------------------------\n\n";
        ifstream myfile("bike.txt");
        if(myfile.is_open()){
            for (int i=0; i < 15; i++){
                myfile >> b[i].no >> b[i].name>>b[i].price>> b[i].engine;
            }
        }else{
            cout<<"Unable to open file";
        }
        myfile.close();
        cout<<"No\t"<<"Bike Name\t\t"<<"Price\t\t"<<"Engine\n";
        cout<<"----------------------------------------------------------\n";
        for(int p=0;p<15;p++){
                cout<<b[p].no<<"\t";
                cout<<b[p].name<<"\t\t";
                cout<<b[p].price<<"\t\t";
                cout<<b[p].engine<<endl;
        }
    }
    //method-to calculate total bike price
    long cal_total_price(int bikes[]){
        //for testing
        /*int i;
        int k;*/
        long total;
        int bikeno;
        double bikeprice;
        for(int i=0;i<15;i++){
            for(int k=0;k<counting;k++){
                if(i==bikes[k]){
                    //cout<<"bike:"<<bikes[k]<<endl;
                    bikeprice=stold(b[i].price);
                    //cout<<bikeprice<<endl;
                    total=total+bikeprice;
                }
            }
        }
        cout<<"\nYour Total Bike price is:Rs."<<total<<"\n\n";
        cout<<"Payment Methords"<<endl;
        cout<<"----------------"<<endl;
        cout<<"Method 1"<<endl;
        cout<<"\t-Pay in one time"<<endl;
        cout<<"\t-10% discount for more than rs.1000000 total bill."<<endl;
        cout<<"Method 2"<<endl;
        cout<<"\t-You have to pay 50% for first installment"<<endl;
        cout<<"\t-you can pay others within 6 months without interest"<<endl;
        cout<<"Method 3"<<endl;
        cout<<"\t-You have to pay 25% for first installment"<<endl;
        cout<<"\t-you can pay others within 36 months(5% interest will be added).\n"<<endl;

        if(total>1000000){
            totalm1=total-(total*10/100);
        }else{
            totalm1=total;
        }
        cout<<"------------------------------"<<endl;
        cout<<"|          Method 1          |"<<endl;
        cout<<"------------------------------ "<<endl;
        cout<<"|Total:Rs."<<totalm1<<" "<<endl;
        cout<<"|                             "<<endl;
        cout<<"-----------------------------\n\n";

        cout<<"----------------------------- "<<endl;
        cout<<"|          Method 2          |"<<endl;
        cout<<"------------------------------ "<<endl;
        cout<<"|first:Rs."<<total*50/100<<" "<<endl;
        cout<<"|1 installment:Rs."<<(total-(total*50/100))/6<<" "<<endl;
        cout<<"------------------------------\n\n";

        cout<<"----------------------------- "<<endl;
        cout<<"|          Method 3          |"<<endl;
        cout<<"------------------------------ "<<endl;
        cout<<"first:Rs."<<total*25/100<<""<<endl;
        cout<<"1 installment:Rs."<<((total-(total*25/100))/36)+((total-(total*25/100))/36)*5/100<<"      "<<endl;
        cout<<"-------------------------------\n\n";
                return total;


    }
    //method-create bill no for customer
    void create_billno(){
        billno=rand();
        cout<<"\n\nYour Bill No is:"<<billno<<"\n\n";
    }
    //method-this is a company message
    void last_company_msg(){
        cout<<"\n\nOur production unit will inform you about your bikes.\n\n";
    }


};
//class production
class production_unit{
    public:
    //This is a production unit message
    void production_msg(){
        cout<<"\t\tWelocome to ABC Production Unit\n";
        cout<<"\t\t-------------------------------\n\n";
        cout<<"\n\n|****your bikes are ready. you can get it on 2021/10/25.*****|\n";
        cout<<"|****Please visit to our company store***|\n\n";
    }
};
//class gatekeeper
class gatekeeper{
    public:
    //check bill no of customer
    void check_billno(){
        string string_billno;
        int check_bill;
        int round=0;
        int check_bill_correct=0;
        cout<<"\t\tWelocome to ABC Bike Company Store\n";
        cout<<"\t\t-----------------------------------\n\n";
        while(round<5){
            cout<<"Please enter your bill no:";
            cin>>string_billno;
            if(!isNumber(string_billno)){
                check_bill=stoi(string_billno);
                if(check_bill==billno){
                    check_bill_correct=1;
                    cout<<"\n\n\t|*****Your bill is ok.*****|\n\n";
                    break;
                }else{
                    cout<<"\nYour bill no is incorrect.Please enter correct bill no.....\n\n";
                    round++;
                }

            }else{
                cout<<"\nPlease enter correct numbers only....\n\n";
            }

        }
        //if customer can not give bill no.then check about nic no
        if(!check_bill_correct){
            string check_nic;
            cout<<"|*****You tried 5 time.This is Your Last Time.Try with your NIC*****|\n\n";
            cout<<"Enter your NIC number:";
            cin>>check_nic;
            if(nic==check_nic){
                cout<<"\n\n\t|*****Your bill is ok.*****|\n\n";
            }else{
                cout<<"\n\n\t|*****Wrong nic*****|\n\n";
                cout<<"|***You are a thief. please get out from this store***|\n";
                exit(1);
            }


        }
    }
};
//store class
class store{
    public:
    int i=0;
    //methord-view of customer bikes
    void ready_bikes(){
        //for testing-check customer bike list
         /*for(int k=0;k<counting;k++){
            cout<<bike_list[k]<<endl;
        }*/
        cout<<"\n\nWelcome "<<fname<<" "<<lname<<" to our store\n\n";
        cout<<"|****Your Bikes Are Ready****|\n\n";
        while(i!=counting){
            //cout<<"check:"<<bike_list[i]<<endl;
            cout<<b[bike_list[i]].name<<endl;
            bike_relase_art();
            cout<<"\n\n";
            i++;

        }
        cout<<"\n\t\t|---Thank You.Come again---|\n\n";
    }
    //methors-draw bikes in cmd
    void bike_relase_art(){
        cout<<"|-------------------|"<<endl;
        cout<<"|       ___0_       |"<<endl;
        cout<<"|    _ ` \ < , _     |"<<endl;
        cout<<"|   (*)   /   (*)   |"<<endl;
        cout<<"|-------------------|\n\n";
    }





};
//main methord
int main(){

    company com;
    custemer cus;
    gatekeeper gk;
    store sto;
    production_unit pu;
    com.bike_art();
    com.bike_list();
    cout<<"\n--------------------------------------------------------------\n";
    cus.buy_bikes();
    cout<<"\n------------------------------------------------------------------------------------------------------------\n";
    total_prize=com.cal_total_price(bike_list);
    cout<<"\n-------------------------------------------------------------------------------------------------------------\n\n";
    cus.confirm_buy_bikes();
    cus.collect_details();
    cus.payment_details();
    com.create_billno();
    com.last_company_msg();
    cout<<"\n---------------------------------------------------------------------------------------------------------------\n";
    com.bike_art();
    pu.production_msg();
    cout<<"\n---------------------------------------------------------------------------------------------------------------\n";
    com.bike_art();
    gk.check_billno();
    sto.ready_bikes();

    return 0;
}

