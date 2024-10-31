#include <iostream>
#include <cmath>

using namespace std;

class point {
public:
    point() {
        x = 0;
        y = 0;
        count++;
        cout << "使用点构造函数" << endl;
    }

    point(int a, int b) {
        x = a;
        y = b;
        count++;
        cout << "使用点构造函数" << endl;
    }

    point(point &p) {
        x = p.x;
        y = p.y;
        cout << "使用点拷贝构造函数" << endl;
    }

    void show() {
        cout << "x坐标为" << x << "  " << "y坐标为" << y << endl;
    }

    void show() const {
        cout << "调用常对象的常成员函数成功" << endl;
    }

    ~point() {
        count--;
    }

    void move(int x, int y) {
        this->x = this->x + x;
        this->y = this->y + y;
    }

    friend double len(point &b, point &a);

    static void showcount() {
        cout << count << "个" << endl;
    }

private:
    int x, y;
    static int count;
};

double len(point &b, point &a){
        float len;
        len = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
        return len;
}

class line {
public:
    line(point xp1, point xp2) : p1(xp1), p2(xp2) {
        dis = len(p1, p2);
        cout << "使用线构造函数" << endl;
    }

    line(line &l) : p1(l.p1), p2(l.p2) {
        dis = l.dis;
        cout << "使用线拷贝构造函数" << endl;
    }

    double getdis() {
        return dis;
    }

private:
    point p1, p2;
    double dis;
};

int point::count = 0;

int main() {
    point c;
    point a[2] = {point(1, 2), point(4, 6)};
    point::showcount();
    a[0].show();
    a[1].show();
    cout << len(a[0], a[1]) << endl;
    a[0].move(3, 1);
    a[0].show();
    c.show();
    len(a[0], c);
    c.~point();
    point::showcount();
    c.show();
    const point d;
    d.show();
    c.move(2, 3);
    line l1(c, a[1]);
    cout << l1.getdis() << endl;
    line l2(l1);
    cout << l2.getdis() << endl;
}