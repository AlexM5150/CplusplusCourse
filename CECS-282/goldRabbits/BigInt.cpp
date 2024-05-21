#include "BigInt.h"

BigInt::BigInt(){
    storage.push_back(0);
}

BigInt::BigInt(int n){
    while (n/10 >= 1){
        int num = n % 10;
        storage.push_back(num);
        n /=10;
    }
    storage.push_back(n);
}

BigInt::BigInt(string s){
    for (int i = s.size() - 1; i >= 0; i--){
        storage.push_back(s[i]-'0');
    }
}

BigInt BigInt::operator+(BigInt n) const{
    BigInt temp(*this);

    while (n.storage.size() != temp.storage.size()) {
        if (n.storage.size() > temp.storage.size())
            temp.storage.push_back(0); 
        else
            n.storage.push_back(0);
    }
    char carry = 0;
    for (int i = 0; i < temp.storage.size(); i++){
        if (carry == 1) {
            carry = 0;
            temp.storage[i] += 1;
        }
        if (temp.storage[i] + n.storage[i] >= 10)
            carry = 1;
        temp.storage[i] += n.storage[i] - carry * 10;
    }
    if (carry == 1)
        temp.storage.push_back(carry);
    
    return temp;
    
}

BigInt BigInt::operator-(BigInt n) const{
     BigInt temp(*this);
     BigInt num = n;
     BigInt result = temp; 
     int carry = 0;
     while (temp.storage.size() > num.storage.size()){
         num.storage.push_back(0);
     }
     for (int i = 0; i < temp.storage.size() ; i++){
     if (temp.storage[i] < num.storage[i]){
         temp.storage[i] = temp.storage[i] + 10;
         carry = 1;
         temp.storage[i + 1] = temp.storage[i + 1] - carry;
     }
         result.storage[i] = temp.storage[i] - num.storage[i];
         if (temp.storage[i] == 0 && num.storage[i] == 0 && i == temp.storage.size() -1){
             result.storage.erase(result.storage.end()-1);
         }
     }
     return result;

}

BigInt BigInt::operator++(int n){
    *this = *this + BigInt(1);
    return *this;
}

bool BigInt::operator == (int n){
    BigInt temp = BigInt(n);
    return *this == temp;
}

bool BigInt::operator<=(int n){
    return *this <= (BigInt(n));
}

BigInt BigInt::operator+(int n){
    BigInt temp = BigInt(n);
    return *this + temp;

}

BigInt BigInt::operator-(int n){
    BigInt N = BigInt(n);
    return *this - N;
}

bool BigInt::operator<(const BigInt &n) const{
    bool comp = false;
    
    if (*this == n){
        return false;
    }
    else if (storage.size() < n.storage.size()){
        comp = true;
    }
    else if (storage.size() > n.storage.size()){
        comp = false;
    }
    else{
        for (int i = (int)storage.size() - 1; i > -1 ; i--){
            if (storage[i] < n.storage[i]){
                return true;
            }
            else if (storage[i] > n.storage[i]){
                return false;
            }
        }
    }
    return comp;
}

bool BigInt::operator == (const BigInt &n) const{
    bool comp = false;    
    if(storage.size() == n.storage.size()){
            for (int i = 0; i < (int)(storage.size()); i++){
                if (storage[i] == n.storage[i]) {
                    comp = true;
                }
                else{
                    comp = false;
                    break;
                }
        }
    }
        return comp;
}

bool BigInt::operator<=(const BigInt &n) const{
    return *this < n || *this == n;
}

void BigInt::print(){
    vector<char>::reverse_iterator r;
    for(r = storage.rbegin(); r != storage.rend(); r++){
        cout << int(*r);
    }
}

vector<char> BigInt::getV()
{
return storage;
}

ostream &operator<<(ostream &out, BigInt temp){
    if (temp.getV().size() > 11)
    {
        for (int i = temp.getV().size() - 1; i >= temp.storage.size() - 11; i--){
            out << int(temp.getV()[i]);
            if (i == temp.getV().size() - 1)
                out << ".";
        }
        out << "e" << temp.getV().size()-1 << endl;
    }
    else
        temp.print();
    return out;
}