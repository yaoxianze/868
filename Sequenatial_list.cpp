#include <iostream>

using namespace std;
#define MAX 50

typedef struct Sqlist {
    int data[MAX]; //顺序表内的数据元素
    int len; //顺序表内的元素个数，初始化为0
} Sqlist; //定义顺序存储的顺序表

// 插入操作
int linsert(Sqlist &l, int i, int e) { // 在顺序表l的第i个位置插入一个数据元素e
    if (i < 1 || i > l.len) {
        cout << "插入位置不合法" << endl;
        return 0;
    }
    if (l.len >= MAX) {
        cout << "顺序表已满" << endl;
        return 0;
    }
    for (int j = l.len; j >= i; j--) {
        l.data[j] = l.data[j - 1]; // data[i-1]及其之后元素都后移一位
    }
    l.data[i - 1] = e;
    l.len++;
    return 0;
};

// 删除操作
int ldelete(Sqlist &l, int i, int &e) {//删除第i个位置的元素，并返回该值给e
    if (i < 1 || i > l.len) {
        cout << "删除位置不合法" << endl;
        return 0;
    }
    e = l.data[i - 1];
    for (int j = i - 1; j < l.len - 1; j++) {
        l.data[j] = l.data[j + 1];
    }
    l.len--;
    return 0;
}

// 按值查找
int lsearchbyvalue(Sqlist &l, int e) { //查找l中值为e的元素，返回其为序
    for (int i = 0; i < l.len; i++) {
        if (l.data[i] == e) {
            return i + 1;
        }
    }
    cout << "查找失败" << endl;
    return 0;
}

// 按位查找
int lsearchebyloacte(Sqlist &l, int i) { //查找l中位序为i的元素，返回其值
    return l.data[i - 1];
}

int lshow(Sqlist &l) {
    for (int i = 0; i < l.len; i++) {
        cout << l.data[i] << " ";
    }
    cout << endl;
    return 0;
}

int main() {
    Sqlist l;
    l.len = 0;
    int v = 60;
    for (int i = 0; 2 * i < MAX; i++) {
        l.data[i] = MAX - i;
        l.len++;
    }
    lshow(l);
    linsert(l, 3, v);
    lshow(l);
    ldelete(l, 3, v);
    lshow(l);
    cout << "34在第" << lsearchbyvalue(l, 34) << "个位置" << endl;
    v = lsearchebyloacte(l, 7);
    cout << v << endl;
    return 0;
}