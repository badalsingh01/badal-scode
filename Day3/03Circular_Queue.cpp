#include <iostream>
using namespace std;

class Queue {
    int *a, n, cs, f, e;
    public:
    Queue(int s = 5) {
        a = new int[s];
        n = s;
        cs = 0;
        f = 0;
        e = n - 1;
    }

    void push(int d) {
        if(cs < n) {
            e = (e + 1) % n;
            a[e] = d;
            cs++;
        }
        else {
            cout << "Queue is full" << endl;
        }
    }

    void pop() {
        if(cs > 0) {
            f = (f + 1) % n;
            cs--;
        }
        else {
            cout << "Queue is empty" << endl;
        }
    }

    bool empty() {
        return cs == 0;
    }
    int front() {
        return a[f];
    }
    int size() {
        return cs;
    }

};

int main() {
    Queue q(6);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    return 0;
}