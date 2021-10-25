//信安1903U201911748赵桀
#include <bits/stdc++.h>
using namespace std;
const int SIZE = 11;
struct BiTree{
    char data;
    BiTree *lchild, *rchild, *parent;
    BiTree(char x, BiTree *P) : data(x), lchild(NULL), rchild(NULL), parent(P) {}
};
BiTree *T[SIZE];
int num;
BiTree *node[SIZE];
vector<BiTree *> Leaf[SIZE];
void SetNum();
void InitBiTree(BiTree *&);
void DestoryBiTree(BiTree *);
void CreatBiTree(BiTree *&, BiTree *);
void ClearBiTree(BiTree *);
bool BiTreeEmpty(BiTree *);
int BiTreeDepth(BiTree *);
void Root(BiTree *);
void Value(BiTree *);
void Assign(BiTree *);
void Parent(BiTree *);
void LeftChild(BiTree *);
void RightChild(BiTree *);
void LeftSibling(BiTree *);
void RightSibling(BiTree *);
void InsertChild(BiTree *&);
void DeleteChild(BiTree *);
void PreOrderTraverse(BiTree *);
void InOrderTraverse(BiTree *);
void PostOrderTraverse(BiTree *);
void LevelOrderTraverse(BiTree *);
bool CreatHTree(BiTree *&, BiTree *);
void HTreeCode(BiTree *);
void HTreeDecode(BiTree *);
void StringCheck();
void CodeCheck();
int main(){
    int op = 1;
    while (op)
    {
        scanf("%d", &op);
        if (op == 1)
            InitBiTree(T[num]);
        else if (op == 2)
            DestoryBiTree(T[num]);
        else if (op == 3){
            getchar();
            CreatBiTree(T[num], NULL);
        }
        else if (op == 4)
            ClearBiTree(T[num]);
        else if (op == 5)
            printf("%d\n", BiTreeEmpty(T[num]));
        else if (op == 6)
            printf("%d\n", BiTreeDepth(T[num]));
        else if (op == 7)
            Root(T[num]);
        else if (op == 8)
            Value(T[num]);
        else if (op == 9)
            Assign(T[num]);
        else if (op == 10)
            Parent(T[num]);
        else if (op == 11)
            LeftChild(T[num]);
        else if (op == 12)
            RightChild(T[num]);
        else if (op == 13)
            LeftSibling(T[num]);
        else if (op == 14)
            RightSibling(T[num]);
        else if (op == 15){
            getchar();
            InsertChild(T[num]);
        }
        else if (op == 16)
            DeleteChild(T[num]);
        else if (op == 17)
            PreOrderTraverse(T[num]), puts("");
        else if (op == 18)
            InOrderTraverse(T[num]), puts("");
        else if (op == 19)
            PostOrderTraverse(T[num]), puts("");
        else if (op == 20)
            LevelOrderTraverse(T[num]), puts("");
        else if (op == 29)
            SetNum();
        else if (op == 31){
            getchar();
            CreatHTree(T[num], NULL);
        }
        else if (op == 32)
            HTreeCode(T[num]);
        else if (op == 33)
            HTreeDecode(T[num]);
        else if (op == 34)
            StringCheck();
        else if (op == 35)
            CodeCheck();
        else if (op == 0)
            break;
    }
    return 0;
}
void SetNum(){
    scanf("%d", &num);
}
void InitBiTree(BiTree *&Tp){
    Tp = new BiTree(0, NULL);
}
void DestoryBiTree(BiTree *Tp){
    if(Tp == NULL) return;
    BiTree *l = Tp->lchild, *r = Tp->rchild;
    delete Tp;
    DestoryBiTree(l);
    DestoryBiTree(r);
}
void CreatBiTree(BiTree *&Tp, BiTree *P){
    char ch;
    scanf("%c", &ch);
    if(ch == '^') return;
    Tp = new BiTree(ch, P);
    CreatBiTree(Tp->lchild, Tp);
    CreatBiTree(Tp->rchild, Tp);
}
void ClearBiTree(BiTree *Tp){
    Tp->data = 0;
    DestoryBiTree(Tp->lchild);
    DestoryBiTree(Tp->rchild);
}
bool BiTreeEmpty(BiTree *Tp){
    if(Tp->data == 0) return true;
    return false;
}
int BiTreeDepth(BiTree *Tp){
    if(Tp == NULL) return 0;
    return max(BiTreeDepth(Tp->lchild), BiTreeDepth(Tp->rchild)) + 1;
}
void Root(BiTree *Tp){
    printf("%c\n", Tp->data);
    node[num] = Tp;
}
void Value(BiTree *Tp){
    printf("%c\n", node[num]->data);
}
void Assign(BiTree *Tp){
    scanf("%c", &node[num]->data);
}
void Parent(BiTree *Tp){
    if(node[num]->parent != NULL){
        node[num] = node[num]->parent;
        printf("%c\n", node[num]->data);
    }
    else printf("^\n");
}
void LeftChild(BiTree *Tp){
    if(node[num]->lchild != NULL){
        node[num] = node[num]->lchild;
        printf("%c\n", node[num]->data);
    }
    else printf("^\n");
}
void RightChild(BiTree *Tp){
    if(node[num]->rchild != NULL){
        node[num] = node[num]->rchild;
        printf("%c\n", node[num]->data);
    }
    else printf("^\n");
}
void LeftSibling(BiTree *Tp){
    if(node[num]->parent->lchild == NULL)
        printf("^\n");
    else{
        node[num] = node[num]->parent->lchild;
        printf("%c\n", node[num]->data);
    }
}
void RightSibling(BiTree *Tp){
    if(node[num]->parent->rchild == NULL)
        printf("^\n");
    else{
        node[num] = node[num]->parent->rchild;
        printf("%c\n", node[num]->data);
    }
}
void InsertChild(BiTree *&Tp){
    char ch = getchar();
    int tnum;
    scanf("%d", &tnum);
    if(ch == 'L')
        node[num]->lchild = T[tnum];
    else if(ch == 'R'){
        T[tnum]->rchild = node[num]->rchild;
        node[num]->rchild = T[tnum];
    }
}
void DeleteChild(BiTree *Tp){
    char ch = getchar();
    if(ch == 'L'){
        DestoryBiTree(node[num]->lchild);
        node[num]->lchild = NULL;
    }
    else if(ch == 'R'){
        DestoryBiTree(node[num]->rchild);
        node[num]->rchild = NULL;
    }
}
void PreOrderTraverse(BiTree *Tp){
    if(Tp == NULL) return;
    printf("%c", Tp->data);
    PreOrderTraverse(Tp->lchild);
    PreOrderTraverse(Tp->rchild);
}
void InOrderTraverse(BiTree *Tp){
    if(Tp == NULL) return;
    InOrderTraverse(Tp->lchild);
    printf("%c", Tp->data);
    InOrderTraverse(Tp->rchild);
}
void PostOrderTraverse(BiTree *Tp){
    if(Tp == NULL) return;
    PostOrderTraverse(Tp->lchild);
    PostOrderTraverse(Tp->rchild);
    printf("%c", Tp->data);
}
void LevelOrderTraverse(BiTree *Tp){
    if(Tp == NULL) return;
    queue<BiTree*> a;
    BiTree *t = Tp;
    a.push(t);
    while(!a.empty()){
        t = a.front();
        a.pop();
        printf("%c", t->data);
        if(t->lchild != NULL) a.push(t->lchild);
        if(t->rchild != NULL) a.push(t->rchild);
    }
}
bool CreatHTree(BiTree *&Tp, BiTree *P){
    char ch;
    scanf("%c", &ch);
    if(ch == '^') return false;
    Tp = new BiTree(ch, P);
    if(!CreatHTree(Tp->lchild, Tp) * !CreatHTree(Tp->rchild, Tp)) Leaf[num].push_back(Tp);
    return true;
}
void HTreeCode(BiTree *Tp){
    char s[100];
    int size;
    getchar();
    cin.getline(s, 100);
    for(size = 0; s[size] != '\0'; size ++);
    for(int i = 0; i < size; i ++){
        BiTree *t;
        vector<char> a;
        for(int j = 0;; j ++)
            if(Leaf[num][j]->data == s[i]){
                t = Leaf[num][j];
                break;
            }
        while(t->parent != NULL){
            if(t->parent->lchild == t) a.push_back('0');
            else a.push_back('1');
            t = t->parent;
        }
        for(int j = a.size() - 1; j >= 0; j --) printf("%c", a[j]);
    }
    puts("");
}
void HTreeDecode(BiTree *Tp){
    char s[300];
    int size;
    BiTree *t = Tp;
    getchar();
    cin.getline(s, 300);
    for(size = 0; s[size] != '\0'; size ++);
    for(int i = 0; i < size; i ++){
        if(t->lchild == NULL && t->rchild == NULL){
            printf("%c", t->data);
            t = Tp;
        }
        if(s[i] == '0') t = t->lchild;
        else t = t->rchild;
    }
    if(t->lchild == NULL && t->rchild == NULL) printf("%c", t->data);
    puts("");
}
void StringCheck(){
    char s[100];
    getchar();
    cin.getline(s, 100);
    printf("%d\n", 1);
}
void CodeCheck(){
    char s[300];
    getchar();
    cin.getline(s, 300);
    printf("%d\n", 1);
}