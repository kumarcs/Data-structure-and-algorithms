#include<bits/stdc++.h>
using namespace std;

const int alphasize=26;

struct trienode
{
    trienode *next[alphasize];
    bool endofword;
};

struct trienode *getnode()
{
    trienode *temp =new trienode;
    temp->endofword=false;
    for(int i=0; i<alphasize; i++)
    {
        temp->next[i]=NULL;
    }

    return temp;

};

void insert(trienode *root, string key)
{
    trienode *pcrawl=root;
    for(int i=0; i<key.length(); i++)
    {
        int index=key[i]-'a';
        if(!pcrawl->next[index])
            pcrawl->next[index]=getnode();
        pcrawl =pcrawl->next[index];
    }
    pcrawl->endofword=true;
}

bool search(trienode *root, string key)
{
    trienode *pcrawl=root;
    for(int i=0; i<key.length(); i++)
    {
        int index=key[i]-'a';
        if(!pcrawl->next[index])
            return false;
        pcrawl =pcrawl->next[index];
    }
    return pcrawl->endofword;
}
int main()
{
    int n;
    cout << "Enter number of strings want to enter: ";
    cin >> n;
    vector <string> s;
    string temp;
    cout << "Enter strings: " << endl;
    for(int i=0; i<n; i++)
    {
        cin >> temp;
        s.push_back(temp);
    }
    trienode *root=getnode();
    for(int i=0; i<s.size(); i++)
    {
        insert(root, s[i]);
    }
    char ch='y';
    while(ch=='y')
    {
        cout << "\nEnter item to search: " << endl;
        cin >> temp;
        if(search(root, temp))
            cout << "string found!!" << endl;
        else
            cout << "not found" << endl;
        cout << "continue?? (y/n) : ";
        cin >> ch;
    }
}
