#include <iostream>

using namespace std;
#define MAX 50

typedef struct Sqlist {
    int data[MAX]; //˳����ڵ�����Ԫ��
    int len; //˳����ڵ�Ԫ�ظ�������ʼ��Ϊ0
} Sqlist; //����˳��洢��˳���

// �������
int linsert(Sqlist &l, int i, int e) { // ��˳���l�ĵ�i��λ�ò���һ������Ԫ��e
    if (i < 1 || i > l.len) {
        cout << "����λ�ò��Ϸ�" << endl;
        return 0;
    }
    if (l.len >= MAX) {
        cout << "˳�������" << endl;
        return 0;
    }
    for (int j = l.len; j >= i; j--) {
        l.data[j] = l.data[j - 1]; // data[i-1]����֮��Ԫ�ض�����һλ
    }
    l.data[i - 1] = e;
    l.len++;
    return 0;
};

// ɾ������
int ldelete(Sqlist &l, int i, int &e) {//ɾ����i��λ�õ�Ԫ�أ������ظ�ֵ��e
    if (i < 1 || i > l.len) {
        cout << "ɾ��λ�ò��Ϸ�" << endl;
        return 0;
    }
    e = l.data[i - 1];
    for (int j = i - 1; j < l.len - 1; j++) {
        l.data[j] = l.data[j + 1];
    }
    l.len--;
    return 0;
}

// ��ֵ����
int lsearchbyvalue(Sqlist &l, int e) { //����l��ֵΪe��Ԫ�أ�������Ϊ��
    for (int i = 0; i < l.len; i++) {
        if (l.data[i] == e) {
            return i + 1;
        }
    }
    cout << "����ʧ��" << endl;
    return 0;
}

// ��λ����
int lsearchebyloacte(Sqlist &l, int i) { //����l��λ��Ϊi��Ԫ�أ�������ֵ
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
    cout << "34�ڵ�" << lsearchbyvalue(l, 34) << "��λ��" << endl;
    v = lsearchebyloacte(l, 7);
    cout << v << endl;
    return 0;
}