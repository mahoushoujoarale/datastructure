//信安1903班 U201911748 赵桀
#include <bits/stdc++.h>
using namespace std;

const int SIZE = 110;
const double eps = 1e-6;

struct Node
{
    int length;
    char value;
    Node *next;
    double cof;
    double pow;
    Node(char x) : length(0), value(x), next(NULL) {}
    Node(double x, double y) : cof(x), pow(y), next(NULL) {}
};

Node *L[SIZE];
int num;

void setListnum();
void InitList(Node*&);
void DestroyList(Node*);
void ClearList(Node*);
void ListEmpty(Node*);
void ListLength(Node*);
void GetElem(Node*, int);
void LocateElem(Node*, char);
void PriorElem(Node*, char&);
void NextElem(Node*, char&);
void ListInsert(Node*, int, char);
void ListDelete(Node*, int);
void ListTraverse(Node*);
void CreatList(Node*);
void ShowList(int);
void AddList(int, int, int);
void MinusList(int, int, int);

int main()
{
    int op = 1;
    int index;
    char elem;
    int listnum;
    int num1, num2, num3;
    while (op)
    {
        scanf("%d", &op);
        if (op == 1)
        {
            InitList(L[num]);
        }
        else if (op == 2)
            DestroyList(L[num]);
        else if (op == 3)
            ClearList(L[num]);
        else if (op == 4)
            ListEmpty(L[num]);
        else if (op == 5)
            ListLength(L[num]);
        else if (op == 6)
        {
            scanf("%d", &index);
            GetElem(L[num], index);
        }
        else if (op == 7)
        {
            getchar();
            scanf("%c", &elem);
            LocateElem(L[num], elem);
        }
        else if (op == 8)
            PriorElem(L[num], elem);
        else if (op == 9)
            NextElem(L[num], elem);
        else if (op == 10)
        {
            scanf("%d", &index);
            getchar();
            scanf("%c", &elem);
            ListInsert(L[num], index, elem);
        }
        else if (op == 11)
        {
            scanf("%d", &index);
            ListDelete(L[num], index);
        }
        else if (op == 12)
            ListTraverse(L[num]);
        else if(op == 19)
            setListnum();
        else if(op == 21) 
            CreatList(L[num]);
        else if(op == 22)
        {
            scanf("%d", &listnum);
            ShowList(listnum);
        }
        else if(op == 23)
        {
            scanf("%d%d%d", &num1, &num2, &num3);
            AddList(num1, num2, num3);
        }
        else if(op == 24)
        {
            scanf("%d%d%d", &num1, &num2, &num3);
            MinusList(num1, num2, num3);
        }
        else if (op == 0)
            break;
        else
            continue;
    }
    return 0;
}

void setListnum()
{
    scanf("%d", &num);
}
void InitList(Node *&L)
{
    L = new Node(0);
}
void DestroyList(Node *L)
{
    Node *t;
    while (L != NULL)
    {
        t = L;
        L = L->next;
        delete t;
    }
}
void ClearList(Node *L)
{
    L->length = 0;
    Node *t = L;
    while (t->next != NULL)
    {
        t->next->value = 0;
        t = t->next;
    }
}
void ListEmpty(Node *L)
{
    if (L->length == 0)
        printf("1\n");
    else
        printf("0\n");
}
void ListLength(Node *L)
{
    printf("%d\n", L->length);
}
void GetElem(Node *L, int index)
{
    if (index > L->length || index < 1)
        {
            printf("NoElem\n");
            return;
        }
    Node *t = L;
    for (int i = 0; i < index; i++)
        t = t->next;
    printf("%c\n", t->value);
    return;
}
void LocateElem(Node *L, char elem)
{
    Node *t = L;
    for (int i = 0; t != NULL; i++)
    {
        if (t->value == elem)
            {
                printf("%d\n", i);
                return;
            }
        t = t->next;
    }
    printf("NoElem\n");
}
void PriorElem(Node *L, char& cur)
{
    Node *t = L->next;
    if (t->value == cur)
    {
        printf("NoElem\n");
        return;
    }
    Node *p = t;
    for (int i = 0; t != NULL; i++)
    {
        if (t->value == cur)
            {
                printf("%c\n", p->value);
                cur = p->value;
                return;
            }
        p = t;
        t = t->next;
    }
}
void NextElem(Node *L, char& cur)
{
    Node *t = L;
    for (int i = 0; t != NULL; i++)
    {
        if (t->value == cur)
        {
            if (t->next != NULL)
                {
                    printf("%c\n", t->next->value);
                    cur = t->next->value;
                    return;
                }
            else
            {
                printf("NoElem\n");
                return;
            }
        }
        t = t->next;
    }
}
void ListInsert(Node *L, int index, char elem)
{
    L->length++;
    Node *p = new Node(0);
    Node *t = L;
    for (int i = 0; i < index - 1; i++)
        t = t->next;
    p->value = elem;
    p->next = t->next;
    t->next = p;
}
void ListDelete(Node *L, int index)
{
    L->length--;
    Node *t = L;
    for (int i = 0; i < index - 1; i++)
        t = t->next;
    char res = t->next->value;
    t->next = t->next->next;
    printf("%c\n", res);
}
void ListTraverse(Node *L)
{
    Node *t = L;
    while (t->next != NULL)
    {
        printf("%c", t->next->value);
        t = t->next;
    }
    printf("\n");
}
void CreatList(Node *H)
{
    Node *p = H;
    int n;
    double x, y;
    vector<pair<double, double>> a;
    scanf("%d", &n);
    for(int i = 0; i < n; i ++)
    {
        scanf("%lf%lf", &x, &y);
        a.push_back({y, x});
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    for(int i = 0; i < a.size() - 1; i ++)
    {
        if(a[i].first == a[i + 1].first)
        {
            a[i].second += a[i + 1].second;
            a.erase(a.begin() + i + 1);
        }
    }
    for(int i = 0; i < a.size(); i ++)
    {
        Node *t = new Node(a[i].second, a[i].first);
        p->next = t;
        p = t;
    }
}
void ShowList(int number)
{
    if(L[number]->next == NULL)
    {
        printf("0\n");
        return;
    }
    Node *t = L[number]->next;
    if(fabs(t->cof) < eps)
    {
        printf("0\n");
        return;
    }
    while(t != NULL)
    {
        if(fabs(t->cof) != 1)
        {
            if(fabs(t->cof - round(t->cof)) < eps)
                printf("%d", (int)t->cof);
            else
                printf("%.1lf", t->cof);
        }
        else if(fabs(t->pow) < eps)
            printf("%d", (int)t->cof);
        if(fabs(t->cof + 1) < eps)
            printf("-");
        if(fabs(t->pow) > eps)
            printf("x");
        if(fabs(t->pow) > 0 && t->pow != 1)
        {
            if(fabs(t->pow - round(t->pow)) < eps)
                printf("^%d", (int)t->pow);
            else
                printf("^%.1lf", t->pow);
        }
        if(t->next !=NULL && t->next->cof > 0)
            printf("+");
        else if(t->next == NULL)
            printf("\n");
        t = t->next;
    }
}
void AddList(int num1, int num2, int num3)
{
    Node *p;
    while (L[num3]->next != NULL)
    {
        p = L[num3]->next;
        L[num3]->next = L[num3]->next->next;
        delete p;
    }
    Node *m = L[num1]->next, *n = L[num2]->next, *k = L[num3];
    while(m != NULL && n != NULL)
    {
        bool flag = 1;
        Node *t = new Node(0, 0);
        if(m->pow > n->pow)
        {
            t->pow = m->pow;
            t->cof = m->cof;
            m = m->next;
        }
        else if(m->pow == n->pow)
        {
            if(fabs(m->cof + n->cof) > eps)
            {
                t->pow = m->pow;
                t->cof = m->cof + n->cof;
            }
            else flag = 0;
            m = m->next;
            n = n->next;
        }
        else
        {
            t->pow = n->pow;
            t->cof = n->cof;
            n = n->next;
        }
        if(flag)
        {
            k->next = t;
            k = t;
        }
    }
    while(m != NULL)
    {
        Node *t = new Node(0, 0);
        t->pow = m->pow;
        t->cof = m->cof;
        k->next = t;
        k = t;
        m = m->next;
    }
    while(n != NULL)
    {
        Node *t = new Node(0, 0);
        t->pow = n->pow;
        t->cof = n->cof;
        k->next = t;
        k = t;
        n = n->next;
    }
}
void MinusList(int num1, int num2, int num3)
{
    Node *p;
    while (L[num3]->next != NULL)
    {
        p = L[num3]->next;
        L[num3]->next = L[num3]->next->next;
        delete p;
    }
    Node *m = L[num1]->next, *n = L[num2]->next, *k = L[num3];
    while(m != NULL && n != NULL)
    {
        bool flag = 1;
        Node *t = new Node(0, 0);
        if(m->pow > n->pow)
        {
            t->pow = m->pow;
            t->cof = m->cof;
            m = m->next;
        }
        else if(fabs(m->pow - n->pow) < eps)
        {
            if(fabs(m->cof - n->cof) > eps)
            {
                t->pow = m->pow;
                t->cof = m->cof - n->cof;
            }
            else flag = 0;
            m = m->next;
            n = n->next;
        }
        else
        {
            t->pow = n->pow;
            t->cof = -1 * n->cof;
            n = n->next;
        }
        if(flag)
        {
            k->next = t;
            k = t;
        }
    }
    while(m != NULL)
    {
        Node *t = new Node(0, 0);
        t->pow = m->pow;
        t->cof = m->cof;
        k->next = t;
        k = t;
        m = m->next;
    }
    while(n != NULL)
    {
        Node *t = new Node(0, 0);
        t->pow = n->pow;
        t->cof = -1 * n->cof;
        k->next = t;
        k = t;
        n = n->next;
    }
}