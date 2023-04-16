    #include <iostream>
    #include <string>
    #include <cstring>
    using namespace std;

    class used_car{ // �߰��� class
    int km;       // ���� Ű�ι��ʹ� private
    public:
    string model; // �ڵ��� ��
    int year;     // ���� ����
    void set(string m, int y, int k);
    void print_car_info();  // model year km �� ���
    int get_km();       // km ��ȯ
    };

    class car_dealer{ // �߰��� ȸ�� class
    used_car *p;    // �߰��� ȸ�簡 ������ �ִ� �߰���
    int num_cars;   // �߰��� ȸ�簡 ������ �ִ� �߰��� ��
    public:
    car_dealer(int n); //�߰��� n�� ������ ���� 
    ~car_dealer();      // "delete [] p;" ���
    void print(){       //��� �߰��� ���� ���
        for(int i = 0; i < num_cars; i++ ){
        p[i].print_car_info();
        }
    }       
    void search_model(string model); //ã�� ���� �߰��� ���� ���
    void search(string model, int year);  //ã�� �� ���󿬵��� ���� �߰��� ���� ���
    };
    //���� �ڵ�� ���� �Ұ�

    //���⿡ �ڵ� �ۼ�
    void used_car::set(string m, int y, int k){
        model  = m;
        year = y;
        km = k;
    }
    void used_car::print_car_info(){
        cout << model << " " << year << " " << km << endl;
    }   
    int used_car::get_km(){

    return km;
    }
    car_dealer::car_dealer(int n){

        num_cars = n;
        p = new used_car[num_cars];
        
        cout << "Enter model year km." << endl;

        for(int i = 0 ; i < num_cars; i++){
            string m;
            int y,k;
            cin >> m >> y >> k;
            p[i].set(m,y,k);
        }
    }
    car_dealer::~car_dealer(){
        delete [] p;
        cout << "delete [] p;";
    }
    void car_dealer::search_model(string model){
        for(int i = 0; i < num_cars; i++){
            if(p[i].model == model){
                p[i].print_car_info();
            }
        }
    }
    void car_dealer::search(string model, int year){
        for(int i = 0; i < num_cars; i++){
            if(p[i].model == model && p[i].year == year){
                p[i].print_car_info();
            }
        }
    }
    //�Ʒ� �ڵ�� ���� �Ұ�

    int main() {

    int n;

    cout << "Number of cars?" << endl;
    cin >> n; // �ڵ��� �� �Է�

    car_dealer incheon(n);

    cout << "-----next day-----" << endl;
    cout << "Enter search car model." << endl;

    string smodel;
    cin >> smodel; // ã�� �� �Է�

    incheon.search_model(smodel);

    cout << "-----next day-----" << endl;
    cout << "Enter search car model year." << endl;

    int year;

    cin >> smodel >> year; // ã�� �� ���󿬵� �Է� 
    incheon.search(smodel, year);

    cout << "-----all cars-----" << endl;

    incheon.print();
    
    }
    // �Է� ��� ����
    //(���)Number of cars?
    //(�Է�)3
    //(���)Enter model year km.
    //(�Է�)BMW 2003 50000
    //(�Է�)kia 2010 40000
    //(�Է�)BMW 2005 90000
    //(���)-----next day-----
    //(���)Enter search car model.
    //(�Է�)BMW
    //(���)BMW 2003 50000
    //(���)BMW 2005 90000
    //(���)-----next day-----
    //(���)Enter search car model year.
    //(�Է�)BMW 2003
    //(���)BMW 2003 50000
    //(���)-----all cars-----
    //(���)BMW 2003 50000
    //(���)kia 2010 40000
    //(���)BMW 2005 90000
    //(���)delete [] p;
