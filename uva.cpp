#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

struct Node {
    int data;
    Node* parent;

    Node(int data) 
    : data(data), parent(this) {}

    Node* find_parent() {
        Node *ptr = this;
        while(ptr != ptr->parent) {
            ptr = ptr->parent;
        }
        parent = ptr;
        return ptr;
    }

    bool isParent() {
        return parent == this;
    }
};

vector<Node*> sets;

void union_sets(int x, int y) {
    Node *ptr_x = sets[x]->find_parent();
    Node *ptr_y = sets[y]->find_parent();

    if (ptr_x->data == ptr_y->data)
        return;

    ptr_x->parent = ptr_y;
}

int main() {
    int index;
    int num_sets;
    char links[3];
    vector<int> result;
    cin >> index;
    cin.ignore();

    while (true) {
        if (index == 0)
            break;

        cin.getline(links, 3);

        switch (strlen(links)) {
        case 0:
            if (sets.empty())
                break;
            num_sets = 0;
            for (int i = 0; i < sets.size(); ++i)
                num_sets += sets[i]->isParent();
            cout << num_sets << endl;
            sets.clear();
            --index;
            if (index)
                cout << endl;
            break;
        case 1:
            for (int i = 0; i < links[0] - 64; ++i)
                sets.push_back(new Node(i));
            break;
        case 2:
            union_sets(links[0] - 65, links[1] - 65);
            break;
        }
    }
    return 0;
}
