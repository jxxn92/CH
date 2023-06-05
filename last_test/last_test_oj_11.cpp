#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Box {
private:
    string label;                     
    int permitWeight, itemWeight;     
public:
    Box() {
        itemWeight = 0;               
    }
    Box(string label, int weight) {
        this->label = label;
        permitWeight = weight;
        itemWeight = 0;
    }
    int putItem(int item){
        itemWeight += item;

        if (itemWeight > permitWeight){
            cout << "This box doesn't have available space." << endl;
        }
    }
    friend istream& operator >> (istream& ins, Box& b){
        if(b.label != "" ||  b.itemWeight != 0){
            cout << "This box is not empty. You can change only label of this box" << endl;
            cout << "Box label : ";
            ins >> b.label;
        }
        else{
        cout << "Box label and weight : ";
        ins >> b.label >> b.permitWeight;
        }
    }
    friend ostream& operator << (ostream& stream, Box& b){
        stream << "[[[[[ BOX ]]]]]" << endl;
        stream << "Box label : " << b.label << endl;
        stream << "Box available weight : " << b.permitWeight - b.itemWeight << endl;
    }
};

int main() {
    Box box, box2("Book", 30);   

    cin >> box;                 
    cout << box;                
    box.putItem(5);              
    cout << box;
    box.putItem(20);        
    
    cout << box2;
    box2.putItem(15);
    cin >> box2;            
    cout << box2;

    return 0;
}