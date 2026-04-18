#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include <string>
#include <cmath>
#include <climits>
using namespace std;

struct Node {
    Node* pre  = NULL;
    Node* next = NULL;
    int a;
    Node(Node* p, Node* n, int _)
        : pre(p),
          next(n),
          a(_) {
    }
};
Node* head = NULL;
Node* tail = NULL;
int t;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    if (t < 6) {
        while (t--) {
            bool f;
            int a;
            cin >> f >> a;
            cout << "-1\n";
        }
        return 0;
    }
    bool f;
    int a;
    cin >> f >> a;
    head = tail = new Node(NULL, NULL, a);
    cout << "-1\n";
    for (int n = 2; n <= 6; ++n) {
        cin >> f >> a;
        if (!f) {
            head->pre = new Node(NULL, head, a);
            head      = head->pre;
        }
        else {
            tail->next = new Node(tail, NULL, a);
            tail       = tail->next;
        }
        cout << "-1\n";
    }
    cin >> f >> a;
    if (!f) {
        head->pre = new Node(NULL, head, a);
        head      = head->pre;
    }
    else {
        tail->next = new Node(tail, NULL, a);
        tail       = tail->next;
    }
    cout << tail->a << "\n";
    for (int n = 8; n <= t; ++n) {
        cin >> f >> a;
        if (!f) {
            Node* t    = tail->pre;
            t->next    = NULL;
            tail->pre  = NULL;
            tail->next = head;
            head->pre  = tail;
            tail->a    = a;
            head       = tail;
            tail       = t;
        }
        cout << tail->a << "\n";
    }
    return 0;
}
