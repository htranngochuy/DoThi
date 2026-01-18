// Cây cấu trúc móc nối 
/* 
#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;
};

void tao_goc(Node*& t) {
    t = NULL;
}

bool Ktra_rong(Node* t) {
    if (t == NULL)
        return true;
    else return false;
}

Node* tao_node(int x) {
    Node* p = new Node;
    p->data = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void them_trai(Node*& t, int x) {
    if (t == NULL || t->left != NULL) {
        std::cout << "Khong them duoc\n";
    }
    else {
        t->left = tao_node(x);
    }
}
void them_phai(Node*& t, int x) {
    if (t == NULL || t->right != NULL) {
        std::cout << "Khong them duoc\n";
    }
    else {
        t->right = tao_node(x);
    }
}

void duyet_truoc(Node* t) {
    if (t != NULL) {
        std::cout << t->data << " ";
        duyet_truoc(t->left);
        duyet_truoc(t->right);
    }
}

void duyet_giua(Node* t) {
    if (t != NULL) {
        duyet_giua(t->left);
        std::cout << t->data << " ";
        duyet_giua(t->right);
    }
}

void duyet_sau(Node* t) {
    if (t != NULL) {
        duyet_sau(t->left);
        duyet_sau(t->right);
        std::cout << t->data << " ";
    }
}
int main()
{
    Node* p = new Node;
    p = tao_node(100);
    them_trai(p, 5);
    them_phai(p, 10);
    them_trai(p->left, 1024);
    them_phai(p->left, 101);
    them_trai(p->right, 50);
    them_phai(p->right, 5000);
    Ktra_rong(p) ? std::cout << "Cay rong\n" : std::cout << "Cay khong rong\n";
    std::cout << "Duyet truoc: ";
    duyet_truoc(p);
    std::cout << "\n";
    std::cout << "Duyet giua: ";
    duyet_giua(p);
    std::cout << "\n";
    std::cout << "Duyet sau: ";
    duyet_sau(p);
    return 0;
}
*/ 
/************************************************************/


// Cây Cấu trúc tuần tự 

#include <iostream>

#define null -1
struct Cay {
    int a[100];
    int n;
};

void rong(Cay &t) {
    for (int i = 0; i < 100; i++) {
        t.a[i] = -1;
    }
}

bool ktra_rong(Cay t) {
    if (t.a[0] == -1)
        return true;
    else return false;
}

void them_goc(Cay& t, int x) {
    if (ktra_rong(t)) {
        t.a[0] = x;
        t.n = 1;
    }
    else std::cout << "Khong them duoc\n";
}

// them vao node co chi so i 
void them_trai(Cay& t, int i, int x) {
    int l = 2 * i + 1;
    if (t.a[i] == -1) {
        std::cout << "Khong them duoc\n";
    }
    else {
        t.a[l] = x;
    }
}

void them_phai(Cay& t, int i, int x) {
    int r = 2 * i + 2;
    if (t.a[i] == -1) {
        std::cout << "Khong them duoc\n";
    }
    else {
        t.a[r] = x;
    }
}

void duyet_truoc(Cay& t, int i) {
    if (t.a[i] != -1 && i < 100) {
        std::cout << t.a[i] << " ";
        duyet_truoc(t, i * 2 + 1);
        duyet_truoc(t, i * 2 + 2);
    }
}

void duyet_giua(Cay& t, int i) {
    if (t.a[i] != -1 && i < 100) {
        duyet_giua(t, i * 2 + 1);
        std::cout << t.a[i] << " ";
        duyet_giua(t, i * 2 + 2);
    }
}

void duyet_sau(Cay& t, int i) {
    if (t.a[i] != -1 && i < 100) {
        duyet_sau(t, i * 2 + 1);
        duyet_sau(t, i * 2 + 2);
        std::cout << t.a[i] << " ";
    }
}
int main() {
    Cay t;
    rong(t);
    them_goc(t, 100);
	them_trai(t, 0, 5);
	them_phai(t, 0, 10);
	them_trai(t, 1, 1024);
	them_phai(t, 1, 101);
	them_trai(t, 2, 50);
    them_phai(t, 2, 50000);
	ktra_rong(t) ? std::cout << "Cay rong\n" : std::cout << "Cay khong rong\n";
	std::cout << "Duyet truoc: ";
	duyet_truoc(t, 0);
	std::cout << "\n";
	std::cout << "Duyet giua: ";
	duyet_giua(t, 0);
	std::cout << "\n";
	std::cout << "Duyet sau: ";
	duyet_sau(t, 0);
    return 0;
}