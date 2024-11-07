#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;

// Cài đặt cấu trúc dữ liệu

// Node
template <typename T>
struct singerNode {
    T data;
    singerNode* next;

    // Constructor mặc định
    singerNode() : next(nullptr) {}

    // Constructor với giá trị
    singerNode(T value) : data(value), next(nullptr) {}

    // Phương thức tĩnh để tạo node mới
    static singerNode* createNode(T data) {
        return new singerNode(data);
    }
};

template <typename T>
struct SingerLinkedList {
    singerNode<T>* head;

    // Constructor
    SingerLinkedList() : head(nullptr) {}

    // Kiểm tra danh sách có rỗng hay không
    bool isEmpty() {
        return head == nullptr;
    }

    void addHead(T value){
        singerNode<T> * add = singerNode<T>::createNode(value);
        if(this-> isEmpty()){
            this->head = add;
        }else{
            add->next = this->head;
            this->head = add;
        }
    }

    void addEnd(T value){
        singerNode<T> * add = singerNode<T>::createNode(value);
        if(this-> isEmpty()){
            this->head = add;
        }else{
            singerNode<T> * last = new singerNode<T>;
            singerNode<T>* current = this->head; // Sử dụng con trỏ để duyệt danh sách
            while (current != nullptr) {
                last = current;
                current = current->next;
            }
            last-> next = add;
        }
    }

    void printList(){
        singerNode<T>* current = this->head; // Sử dụng con trỏ để duyệt danh sách
        while (current != nullptr) {
            cout << current->data << " "; // In dữ liệu của node hiện tại
            current = current->next; // Chuyển đến node tiếp theo
        }
    }
};

// stack 
template <typename T>
struct stack {
    SingerLinkedList<T>* st;

    // Constructor
    stack() {
        st = new SingerLinkedList<T>();
    }

    // Hủy bộ nhớ khi không sử dụng
    ~stack() {
        while (!isEmpty()) {
            pop();
        }
        delete st; // Giải phóng bộ nhớ cho danh sách
    }

    // Thêm phần tử vào ngăn xếp
    void push(T value) {
        st->addEnd(value);
    }

    // Xóa phần tử ở đầu ngăn xếp
    void pop() {
        if (!isEmpty()) {
            singerNode<T>* old = st->head;
            st->head = st->head->next;
            delete old; // Giải phóng bộ nhớ
        }
    }

    // Kiểm tra ngăn xếp có rỗng hay không
    bool isEmpty() {
        return st->isEmpty();
    }

    // Lấy phần tử ở đỉnh ngăn xếp
    T top() {
        if (!isEmpty()) {
            return st->head->data;
        }
        throw out_of_range("Ngăn xếp rỗng");
    }

    // Kích thước ngăn xếp
    int size() {
        int result = 0;
        singerNode<T>* current = st->head;
        while (current != nullptr) {
            result++;
            current = current->next;
        }
        return result; // Trả về kích thước
    }
};

template <typename T>
struct queue
{
    SingerLinkedList<T>* st;
    // Constructor
    queue() {
        st = new SingerLinkedList<T>();
    }

    // Hủy bộ nhớ khi không sử dụng
    ~queue() {
        while (!isEmpty()) {
            pop();
        }
        delete st; // Giải phóng bộ nhớ cho danh sách
    }

    // Thêm phần tử vào ngăn xếp
    void push(T value) {
        st->addHead(value);
    }

    // Xóa phần tử ở đầu ngăn xếp
    void pop() {
        if (!isEmpty()) {
            singerNode<T>* old = st->head;
            st->head = st->head->next;
            delete old; // Giải phóng bộ nhớ
        }
    }

    // Kiểm tra ngăn xếp có rỗng hay không
    bool isEmpty() {
        return st->isEmpty();
    }

    // Lấy phần tử ở đỉnh ngăn xếp
    T top() {
        if (!isEmpty()) {
            return st->head->data;
        }
        throw out_of_range("Ngăn xếp rỗng");
    }

    // Kích thước ngăn xếp
    int size() {
        int result = 0;
        singerNode<T>* current = st->head;
        while (current != nullptr) {
            result++;
            current = current->next;
        }
        return result; // Trả về kích thước
    }
};



struct hashTable
{
    string hashkey;

    void setHashKey(string index){
        this->hashkey = index;
    }

    string getHashKey(){
        return this->hashkey;
    }


    void hashFunction(){
        
    }
};

template <typename T>
void fileWrite(SingerLinkedList<T> s, string filename){
    
}

// cửa hàng bán quần áo 
// Cấu trúc đối tượng sản phẩm

struct QuanAo 
{
    string maSP;
    string ten;
    string size;
    int soLuong;
    float giaBan;
    string danhMuc;
    string mauSac;

};

// quản lý của đối tượng quần áo 


int main() {
    
}
