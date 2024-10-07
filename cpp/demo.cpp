#include <iostream>
#include <string>
#include <vector>
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




// Cấu trúc đối tượng sản phẩm
struct productCategories
{
    string categoriesID;
    string categoriesName;
    string Description;

    productCategories();
    productCategories(string categoriesID, string categoriesName, string Description): categoriesID(categoriesID), categoriesName(categoriesName), Description(Description) {}

};

struct products {
    string MA_SAN_PHAM;
    string TEN_SAN_PHAM;
    string MO_TA;
    productCategories DANH_MUC;
    string KICH_THUOC;
    string MAU_SAC;
    float GIA_BAN;
    float GIA_NHAP;
    int SO_LUONG_TON_KHO;
    string NHA_CUNG_CAP;


    products(string ma_sp, string ten_sp, string mo_ta, productCategories danh_muc, 
              string kich_thuoc, string mau_sac, float gia_ban, float gia_nhap, 
              int so_luong_ton_kho, string nha_cung_cap) 
        : MA_SAN_PHAM(ma_sp), TEN_SAN_PHAM(ten_sp), MO_TA(mo_ta), 
          DANH_MUC(danh_muc), KICH_THUOC(kich_thuoc), MAU_SAC(mau_sac), 
          GIA_BAN(gia_ban), GIA_NHAP(gia_nhap), SO_LUONG_TON_KHO(so_luong_ton_kho), 
          NHA_CUNG_CAP(nha_cung_cap) {}
};

struct customers {
    string MA_KHACH_HANG;
    string TEN_KHACH_HANG;
    string THONG_TIN_LIEN_HE;
    vector<string> LICH_SU_MUA;
    float DIEM_THUONG;
    string GHI_CHU;

    customers(){}
    customers(string ma_khach_hang, string ten_khach_hang, string thong_tin_lien_he) 
        : MA_KHACH_HANG(ma_khach_hang), 
          TEN_KHACH_HANG(ten_khach_hang), 
          THONG_TIN_LIEN_HE(thong_tin_lien_he), 
          DIEM_THUONG(0.0), 
          GHI_CHU("") {}
};

struct orderProduct{
    string MA_SAN_PHAM;
    string TEN_SAN_PHAM;
    int SO_LUONG;
    float TONG_TIEN;
    
    orderProduct(){}

    orderProduct(string ma_sp, string ten_sp, int so_luong, float gia)
        : MA_SAN_PHAM(ma_sp), TEN_SAN_PHAM(ten_sp), SO_LUONG(so_luong), TONG_TIEN(gia) {}

};

struct order{
    string MA_DON_HANG;
    string MA_KHACH_HANG;
    vector<orderProduct> DANH_SACH_HANG_MUA;
    string TRANG_THAI_DON;
    string NGAY_DAT_HANG;
    string PHUONG_THUC_THANH_TOAN;
    string PHUONG_THUC_GIAO_HANG;

    order(string ma_don_hang, string ma_khach_hang, string ngay_dat_hang, 
          string trang_thai_don, string phuong_thuc_thanh_toan, string phuong_thuc_giao_hang)
        : MA_DON_HANG(ma_don_hang), 
          MA_KHACH_HANG(ma_khach_hang), 
          NGAY_DAT_HANG(ngay_dat_hang), 
          TRANG_THAI_DON(trang_thai_don), 
          PHUONG_THUC_THANH_TOAN(phuong_thuc_thanh_toan), 
          PHUONG_THUC_GIAO_HANG(phuong_thuc_giao_hang) {}
    order(){}
};


struct employees{
    string MA_NHAN_VIEN;
    string TEN_NHAN_VIEN;
    string VI_TRI;
    string THONG_TIN_LIEN_LAC;
    string LICH_LAM_VIEC;

     employees() {}

    // Constructor với tham số
    employees(string ma_nv, string ten_nv, string vi_tri, string thong_tin_lien_lac, string lich_lam_viec)
        : MA_NHAN_VIEN(ma_nv), 
          TEN_NHAN_VIEN(ten_nv), 
          VI_TRI(vi_tri), 
          THONG_TIN_LIEN_LAC(thong_tin_lien_lac), 
          LICH_LAM_VIEC(lich_lam_viec) {}
};

struct inventory{
    string MA_SAN_PHAM;
    int SO_LUONG_TON_KHO;
    int LICH_SU_NHAP_XUAT;

    inventory() {}

    // Constructor với tham số
    inventory(string ma_sp, int so_luong)
        : MA_SAN_PHAM(ma_sp), SO_LUONG_TON_KHO(so_luong) {}
};

struct payments{
    string MA_THANH_TOAN;
    string MA_DON_HANG;
    float SO_TIEN_THANH_TOAN;
    string PHUONG_THUC_THANH_TOAN;
    string NGAY_THANH_TOAN;

    payments() {}

    // Constructor với tham số
    payments(string ma_thanh_toan, string ma_don_hang, float so_tien, string phuong_thuc, string ngay_thanh_toan)
        : MA_THANH_TOAN(ma_thanh_toan), 
          MA_DON_HANG(ma_don_hang), 
          SO_TIEN_THANH_TOAN(so_tien), 
          PHUONG_THUC_THANH_TOAN(phuong_thuc), 
          NGAY_THANH_TOAN(ngay_thanh_toan) {}
};

struct promotionsAndDisconts{
    string MA_KHUYEN_MAI;
    string LOAI_KHUYEN_MAI;
    string DIEU_KIEN_AP_DUNG;
    string NGAY_BAT_DAU;
    string NGAY_KET_THUC;

    promotionsAndDisconts() {}

    // Constructor với tham số
    promotionsAndDisconts(string ma_khuyen_mai, string loai_khuyen_mai, string dieu_kien, string ngay_bat_dau, string ngay_ket_thuc)
        : MA_KHUYEN_MAI(ma_khuyen_mai), 
          LOAI_KHUYEN_MAI(loai_khuyen_mai), 
          DIEU_KIEN_AP_DUNG(dieu_kien), 
          NGAY_BAT_DAU(ngay_bat_dau), 
          NGAY_KET_THUC(ngay_ket_thuc) {}
};

struct reviewsAndFeedback {
    string MA_DANH_GIA;
    string MA_KHACH_HANG;
    string MA_SAN_PHAM;
    int SO_SAO;
    string BINH_LUAN;
    string NGAY_DANH_GIA;

     reviewsAndFeedback() {}

    // Constructor với tham số
    reviewsAndFeedback(string ma_danh_gia, string ma_khach_hang, string ma_san_pham, int so_sao, string binh_luan, string ngay_danh_gia)
        : MA_DANH_GIA(ma_danh_gia), 
          MA_KHACH_HANG(ma_khach_hang), 
          MA_SAN_PHAM(ma_san_pham), 
          SO_SAO(so_sao), 
          BINH_LUAN(binh_luan), 
          NGAY_DANH_GIA(ngay_danh_gia) {}
};

struct DoanhSo{
    int TONG_DOANH_SO_THEO_THOI_GIAN;
    int TONG_DOANH_SO_THEO_SP;
};

struct BaoCaoKho{
    string MA_SAN_PHAM;
    string TINH_TRANG;
};

struct KhachHang{
    vector<string> DANH_SACH_KHACH_HANG;
    string LOAI_KHACH_HANG;
};

struct BCTaiChinh {
    float DoanhThu;
    float ChiPhi;
    float LoiNhuan;
};

struct reportsAndAnalytics {
    DoanhSo DOANH_SO_CUA_HANG;
    BaoCaoKho QUAN_LY_KHO;
    KhachHang HE_THONG_KHACH_HANG;
    BCTaiChinh QUAN_LY_TAI_CHINH;

    reportsAndAnalytics(DoanhSo doanhSo, BaoCaoKho baoCaoKho, KhachHang khachHang, BCTaiChinh bcTaiChinh)
        : DOANH_SO_CUA_HANG(doanhSo), QUAN_LY_KHO(baoCaoKho), HE_THONG_KHACH_HANG(khachHang), QUAN_LY_TAI_CHINH(bcTaiChinh) {}

    reportsAndAnalytics(){}
};

struct returnAndExchanges {
    string MA_TRA_HANG;
    string MA_DON_HANG;
    string LY_DO_TRA;
    string TRANG_THAI;

    returnAndExchanges(string maTraHang, string maDonHang, string lyDoTra, string trangThai)
        : MA_TRA_HANG(maTraHang), MA_DON_HANG(maDonHang), LY_DO_TRA(lyDoTra), TRANG_THAI(trangThai) {}
    
    returnAndExchanges(){}
};

struct shippingAndDelivery {
    string MA_DON;
    vector<orderProduct> listProduct;
    string DIA_CHI_GIAO;
    string NHA_VAN_CHUYEN;
    string TRANG_THAI;

    shippingAndDelivery(){}

    shippingAndDelivery(string MA_DON, vector<orderProduct> listProduct, string DIA_CHI_GIAO, string NHA_VAN_CHUYEN, string TRANG_THAI): MA_DON(MA_DON), listProduct(listProduct), DIA_CHI_GIAO(DIA_CHI_GIAO), NHA_VAN_CHUYEN(NHA_VAN_CHUYEN), TRANG_THAI(TRANG_THAI) {}
};


// nâng cao dành cho web 
struct ManagementAndAccessControl {

};

struct NotificationAndCommunition {

};

struct LocationManagement {

};

struct security {

};

struct integrationWithOtherSystems {

};

struct accessControl {

};

struct notificationAndReportingSystem {

};

int main() {
    stack<int> a;
    a.push(1);
    a.push(2);
    cout << a.top();
    a.pop();
    return 0;
}
