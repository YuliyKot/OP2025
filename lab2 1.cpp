#include <iostream>
#include <locale.h>
#include <set>
using namespace std;

class Car {
private:
    string marka_;
    string model_;
    string nomerkuzov_;
    unsigned probeg_;

protected:
    string gosnomer_;

public:

    Car() {
        marka_ = "Undefined";
        model_ = "Undefined";
        gosnomer_ = "Undefined";
        nomerkuzov_ = "Undefined";
        probeg_ = 0;
    }

    Car(string marka, string model, string gosnomer, string nomerkuzov, unsigned probeg) {
        marka_ = marka;
        model_ = model;
        try {
            Nomer(gosnomer);
            gosnomer_ = gosnomer;
        }
        catch (...) {
            cout << "Номер не соответствует стандарту" << endl; 
            gosnomer_ = "Undefined";
        }
        nomerkuzov_ = nomerkuzov;
        probeg_ = probeg;
    }
    Car(const Car& car) {
        marka_ = car.marka_;
        model_ = car.model_;
        gosnomer_ = car.gosnomer_;
        nomerkuzov_ = car.nomerkuzov_;
        probeg_ = car.probeg_;
    }

    ~Car() {
        cout << this << " удалён" << endl;
    }

    void print_marka() {
        cout << marka_ << endl;
    }
    void print_model() {
        cout << model_ << endl;
    }
    void print_gosnomer() {
        cout << gosnomer_ << endl;
    }
    void print_nomerkuzov() {
        cout << nomerkuzov_ << endl;
    }
    void print_probeg() {
        cout << probeg_ << endl;
    }

    void print_all() {
        cout << marka_ << endl;
        cout << model_ << endl;
        cout << gosnomer_ << endl;
        cout << nomerkuzov_ << endl;
        cout << probeg_ << endl;
    }

    void change_probeg(unsigned x, bool z) {
        if (z == 1) probeg_ += x;
        else probeg_ -= x;
    }
    
    void change_gosnomer(string gosnomer) {
        Nomer(gosnomer);
        gosnomer_ = gosnomer;
    }
    
    void change_nomerkuzov(string nomerkuzov) {
        nomerkuzov_ = nomerkuzov;
    }

    

protected:
    void Nomer(string nomer) {
        set<int> Num{ '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
        set<int> Alf{ 'А', 'В', 'Е', 'К', 'М', 'Н', 'О', 'Р', 'С', 'Т', 'У', 'Х'};
        unsigned flag = 0;
        if (nomer.length() != 6) throw invalid_argument("Номер не соответствует стандарту");
        else {
            for (int i = 0; i < 6; i++) {
                if ((i == 0) or (i == 4) or (i == 5)) {
                    flag += Alf.count(nomer[i]);
                }
                else {
                    flag += Num.count(nomer[i]);
                }
            }   
        }
        if (flag != 6) throw invalid_argument("Номер не соответствует стандарту");
    }
   

    

};



int main()
{
    setlocale(LC_ALL, "rus");
    
    Car Inf("Inf", "jkjx", "А585АА", "648454687", 1515);
    Inf.print_marka();
    Inf.print_model();
    Inf.print_gosnomer();
    Inf.print_nomerkuzov();
    Inf.print_probeg();
    
    Car Inf2(Inf);
    Inf2.print_all();

    Car Audi;
    Audi.print_all();

    Car Mers("Mers", "gjkjx", "O2jlOO", "648454687", 1515);
    Mers.print_all();
    
    try {
        Inf.change_gosnomer("hjytdbx");
    }
    catch (...) {
        cout << "Номер не соответствует стандарту" << endl;
    }
    Inf.print_gosnomer();
    try {
        Mers.change_gosnomer("В253ЕВ");
    }
    catch (...) {
        cout << "Номер не соответствует стандарту" << endl;
    }
    Mers.print_gosnomer();

    Audi.change_probeg(28977, 1);
    Mers.change_probeg(89, 0);
    Inf.change_nomerkuzov("54728hjhg");
}
