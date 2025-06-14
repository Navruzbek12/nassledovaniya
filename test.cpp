#include <iostream>
using namespace std;

class B1 {
public:
    int b1;
    B1(int x = 0) { b1 = x; }
    virtual ~B1() {}  // Virtual destruktor
    void show_B1() { cout << "B1 = " << b1 << endl; }
    virtual void showV() { cout << "virt B1 = " << b1 << endl; }
};

class B2 {
private:
    int b2;
public:
    B2(int x = 0) { b2 = x; }
    void show_B2() { cout << "B2 = " << b2 << endl; }
    virtual void showV() { cout << "virt B2 = " << b2 << endl; }
};

class D1 : private B1, public B2 {
public:
    int d1;
    D1(int x = 0, int y = 0, int z = 0) : B1(y), B2(z) { d1 = x; }
    void show() {
        cout << "D1 = " << d1 << endl;
        show_B1();
        show_B2();
    }
    void showV() override { cout << "virt D1 = " << d1 << endl; }
};

class D2 : public B1, private B2 {
public:
    int d2;
    D2(int x = 0, int y = 0, int z = 0) : B1(y), B2(z) { d2 = x; }
    void show() {
        cout << "D2 = " << d2 << endl;
        show_B1();
        show_B2();
    }
    void showV() override { cout << "virt D2 = " << d2 << endl; }
};

class D3 : private D1, public D2 {
public:
    int d3;
    D3(int a = 0, int b = 0, int c = 0, int d = 0, int e = 0, int f = 0, int g = 0)
        : D1(b, c, d), D2(e, f, g) { // To'g'ri konstruktorda faqat bitta yo'lni tanlang
        d3 = a;
    }
    void show() {
        cout << "Following the hierarchy of class D3:" << endl;
        cout << "D3 = " << d3 << endl;
        D1::show();
        D2::show();
    }
    void showV() override { cout << "virt D3 = " << d3 << endl; }
};

int main() {
    D3 obj(1, 2, 3, 4, 5, 6, 7);  // Numbers are used for the example
    obj.show();

    cout << "\nVirtual functions demo:\n";
    B1* ptrs[3];
    ptrs[0] = new B1(100);
    ptrs[1] = new D2(200, 300, 400);
    ptrs[2] = new D3(1, 2, 3, 4, 5, 6, 7);

    for (int i = 0; i < 3; ++i)
        ptrs[i]->showV();

    for (int i = 0; i < 3; ++i)
        delete ptrs[i];

    return 0;
}
