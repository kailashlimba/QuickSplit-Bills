#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int i, n, m, u, v, w, mini, x, maxi, y, up, TotalTransactions=0, t1=1, t2=0, t3=0;
    cout<<"\t \t \t ################# WELCOME TO QUICK-SPLIT ####################"<<endl;
    cout<<endl;
    
    
    cout<<"Enter the number of people and the number of transaction"<<endl;
    cin >> n >> m;

    vector<int> debt(n+100,0);

    cout<<"ThankYou!"<<endl;
    cout<<"In the next "<<m<<" lines " <<"please enter the index of the person who paid the amount followed by the index of the person who owe it"<<endl;
    
    for(i=0; i<m; i++) 
    {
        //u paid an amount w to v 
        cin >> u >> v >> w;
        debt[u] = debt[u] + w;
        debt[v] = debt[v] - w;
    }

    while(t1==1)
    {
        if(t3==1)
        {
            cout<<"Enter the number of transactions you want to addon"<<endl;
            cin>>up; 
            cout<<"In the next "<<up<<" lines " <<"please enter the index of the person who paid the amount followed by the index of the person who owe it"<<endl;
            for(i=0; i<up; i++) 
            {
                //u paid an amount w to v
                cin >> u >> v >> w;
                debt[u] = debt[u] + w;
                debt[v] = debt[v] - w;
            }

        }

        multiset< pair<int, int > > S;

        for(i=0; i<n; i++)
        {
            if(debt[i] != 0) S.insert(make_pair(debt[i], i));
        } 
               
        TotalTransactions = 0;
        
        cout<<endl;
        while(!S.empty()) 
        {
            pair<int, int > p1 = *S.begin(); 
            S.erase(S.begin());
            mini = p1.first;
            x = p1.second;

            pair<int, int > p2 = *S.rbegin(); 
            S.erase(prev(S.end()));
            maxi = p2.first;
            y = p2.second;
            
            int amount = min(-mini, maxi);
            
            TotalTransactions++; 
            // mini pays amount "amount" to maxi
            cout<<x<<" should pay amount $"<<amount<<" to "<<y<<endl;
            mini = mini + amount;
            maxi = maxi - amount;
            
            if(mini)
            {
                S.insert(make_pair(mini, x));
            }
            if(maxi) 
            {
                S.insert(make_pair(maxi, y));
            }        
        }
        
        t1=0;
        cout<<endl;
        
        cout<<"Do you want to add more transaction ?,if yes then press 1 else press 0"<<endl;
        cin>>t3;

        if(t3==1)
        {
            t1=1;
        }
        else  if(t3==0)
        {
            break;
        }
    }
    
    cout <<"Total number of Transactions occurred are "<<TotalTransactions << endl;   
    
}