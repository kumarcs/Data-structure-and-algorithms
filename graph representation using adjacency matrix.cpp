#include<bits/stdc++.h>
using namespace std;
#define max 100

int adj[max][max]={0};
int n;

void display(int matrix[max][max]);
void insertedge(int o, int d);
void creategraph();
void deleteedge(int , int);
void multiply(int mat1[max][max], int mat2[max][max], int mat3[max][max]);

//for breadth first search
#define initial 1
#define waiting 2
#define visited 3
int state[max];
void BF_Traversal();
void BFS(int v);
void insertqueue(int v);
int isemptyqueue();
int deletequeue();
int bfsqueue[max], front=-1, rear=-1;

//for depth first search
int gstack[max];
void DF_traversal();
void DFS(int v);
int top=-1;
void push(int v);
int pop();
int isemptystack();


int main()
{
    int choice, item, origin, dest;
    int adjp[max][max], x[max][max], pathm[max][max]; //for path matrix by powers of matrix
    int i, j, k, p;
    creategraph();
    while(1)
    {
        cout << "1. insert an edge" << endl
             << "2. delete an edge" << endl
             << "3. display" << endl
             << "4. find path matrix from powers of matrix" << endl
             << "5. find path matrix from powers of matrix by Warshall algorithm " << endl
             << "6. breadth first search" << endl
             << "7. depth first traversal" << endl
             << "8. exit" << endl
             << "Enter your choice: ";
             cin >> choice;
        switch(choice)
        {
        case 1:
            cout << "Enter edge to be inserted: ";
            cin >> origin >> dest;
            insertedge(origin, dest);
            break;
        case 2:
            cout << "Enter edge to be deleted: ";
            cin >> origin >> dest;
            deleteedge(origin, dest);
            break;
        case 3:
            display(adj);
            break;
        case 4:
            for(i=0; i<n; i++)
                for(j=0; j<n; j++)
                    adjp[i][j]=adj[i][j];
            for(i=0; i<n; i++)
                for(j=0; j<n; j++)
                    x[i][j]=adj[i][j];
            for(p=1; p<n; p++)
            {
                multiply(adjp, adj, pathm);
                for(i=0; i<n; i++)
                    for(j=0; j<n; j++)
                    {
                        adjp[i][j]=pathm[i][j];
                    }
                cout << "adjacency matrix raised to power " << p+1 << " is " <<endl;
                display(adjp);
                for(i=0; i<n; i++)
                    for(j=0; j<n; j++)
                    {
                        x[i][j]=x[i][j]+adjp[i][j];
                    }
            }
                cout << "The x matrix is: " << endl;
                display(x);
                for(i=0; i<n; i++)
                    for(j=0; j<n; j++)
                        if(x[i][j]==0)
                            pathm[i][j]=0;
                        else
                            pathm[i][j]=1;
                cout << "The path matrix is: " << endl;
                display(pathm);
            break;
        case 5:
            for(i=0; i<n; i++)
                    for(j=0; j<n; j++)
                    {
                        x[i][j]=adj[i][j];
                    }
            for(k=0; k<n; k++)
            {
                for(i=0; i<n; i++)
                    for(j=0; j<n; j++)
                        x[i][j]=(x[i][j] || (x[i][k] && x[k][j]));
            }
            cout << "path matrix is: " << endl;
            display(x);
            break;
        case 6:
            BF_Traversal();
            break;
        case 7:
            DF_traversal();
            break;
        case 8:
            exit(0);
        }

    }
}

void insertedge(int o, int d)
{
    if(o<0 || o>n)
        cout << "origin vertex does not exist" << endl;
    else if(d<0 || d>n)
        cout << "destination vertex does not exist" << endl;
    else
    {
        adj[o][d]=1;
        cout << "inserted !!" << endl;
    }
}

void creategraph()
{
    int maxedges, i, origin, dest;
    cout << "Enter number of vertices: ";
    cin >> n;
    maxedges= n*(n-1);
    for(i=1; i<=maxedges; i++)
    {
        cout << "Enter no: "<< i << " edge (origin and vertex)(-1 -1 to exit): ";
        cin >> origin >> dest;
        if(origin == -1 && dest==-1)
            return;
        else if(adj[origin][dest]==1)
        {
            cout << "edge already exist!!" << endl;
            i--;
        }
        else
            insertedge(origin, dest);
    }
}

void deleteedge(int o, int d)
{
    if(o<0 || o>n)
        cout << "origin vertex does not exist" << endl;
    else if(d<0 || d>n)
        cout << "destination vertex does not exist" << endl;
    else
    {
        adj[o][d]=0;
        cout << "deleted!!";
    }
}

// display with vertices number marked
void display(int matrix[max][max])
{
    cout << setw(1) << " ";
    for(int i=0; i<n; i++)
        cout << setw(2) << i;
    cout << endl;;
    for(int i=0; i<n; i++)
    {
        cout << setw(1) << i;
        for(int j=0; j<n; j++)
            cout << setw(2) << matrix[i][j];
        cout << endl;
    }
}

void multiply(int mat1[max][max], int mat2[max][max], int mat3[max][max])
{
    int i, j, k;
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
        {
            mat3[i][j]=0;
            for(k=0; k<n; k++)
            {
                mat3[i][j]=mat3[i][j]+mat1[i][k]*mat2[k][j];
            }
        }
}

void BF_Traversal()
{
    int v;
    for(v=0; v<n; v++)
    {
        state[v]=initial;
    }
    cout << "Enter the starting point: ";
    cin >> v;
    BFS(v);
}

void BFS(int v)
{
    int i;
    insertqueue(v);
    state[v]=waiting;
    while(!isemptyqueue())
    {
        v=deletequeue();
        cout << v << endl;
        state[v]=visited;
        for(i=0; i<n; i++)
        {
            if(adj[v][i]==1 && state[i]==initial)
            {
                insertqueue(i);
                state[i]=waiting;
            }

        }
    }
}

void insertqueue(int v)
{
    if(rear==max-1)
    {
        cout << "queue overflowed" << endl;
    }
    else
    {
        if(front == -1)
            front=0;
        rear=rear+1;
        bfsqueue[rear]=v;
    }
}

int isemptyqueue()
{
    if(front==-1 && rear==-1)
    {
        return 1;
    }
    else
        return 0;
}

int deletequeue()
{
    int item;
    if(isemptyqueue())
    {
        cout << "queue underflowed" << endl;
        exit(1);
    }
    item=bfsqueue[front];
    if(front==rear)
        front=rear=-1;
    else
        front=front+1;
    return item;
}

//start DFS
void DF_traversal()
{
    int v;
    for(v=0; v<n; v++)
    {
        state[v]=initial;
    }
    cout << "Enter starting point: ";
    cin >> v;
    DFS(v);
}

void DFS(int v)
{
    int i;
    push(v);
    while(!(isemptystack()))
    {
        v=pop();
        if(state[v]==initial)
        {
            cout << v << " ";
            state[v]=visited;
        }
        for(i=n-1; i>=0; i--)
        {
            if(adj[v][i]==1 && state[i]==initial)
                push(i);
        }
    }
}

void push(int v)
{
    if(top==max-1)
    {
        cout << "stack overflow" << endl;
        return;
    }
    top=top+1;
    gstack[top]=v;
}

int pop()
{
    int v;
    if(top==-1)
    {
        cout << "stack underflow" << endl;
        exit(1);
    }
    else
    {
        v=gstack[top];
        top=top-1;
        return v;
    }
}

int isemptystack()
{
    if(top==-1)
        return 1;
    else
        return 0;
}
