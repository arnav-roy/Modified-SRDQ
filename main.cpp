#include<bits/stdc++.h>
using namespace std ;
typedef long long ll;
#define forn(i,e) for(ll i=0; i<e; i++)
#define endl "\n"
#define PB push_back


long double harmonicMean(long double arr[], ll n)
{
    long double sum = 0;
    for (int i = 0; i < n; i++)
        sum = sum + (long double)1 / arr[i];
 
    return (long double)n/sum;
}
/*
long double harmonicMean( long double arr[], ll n)
{
return arr[n/2] ;
}*/

long double square(long double a)
{
return (long double) a*a ;
}
int main()
{




ll n ; cin >> n ;
long double a[n] ;
long double tot_burst = 0 ;
forn(i,n)
{
cin >> a[i] ;
tot_burst += a[i] ;
}


vector <long double> q1_b ;
vector <long double> q2_b ;
vector <long double> q1_q ;
vector <long double> q2_q ;

long double q_dash = harmonicMean(a , n) ;

forn(i,n)
{

if(a[i] <= q_dash)
{q1_b.push_back(a[i]) ; q1_q.push_back(0) ; }
else
{q2_b.push_back(a[i]) ; q2_q.push_back(0) ; }
}
long long select = 1;
long long iter =  1 ;
int i = 0 ; int j = 0 ;
long double cur_time = 0 ;  
long double tot_res = 0;  // total response time
long double tot_com = 0;  // total completion
while(!q1_b.empty() || !q2_b.empty())
{
cout << cur_time <<" "<< tot_res << " "<< tot_com << endl ;

if((select % 3 == 1 || select % 3 == 2) && !q1_b.empty())
{
iter++ ;
q1_q[i] = q_dash - (long double) ((q_dash)/ square(q1_b[i] + q1_q[i])) ;
cout <<"my q is " << q1_q[i] << endl ;

int flag = 1 ;
if(q1_b[i] > q1_q[i])
{
if(iter < n+2)
tot_res += cur_time ;  

q1_b[i] = q1_b[i] - q1_q[i] ;
cur_time += q1_q[i];

}

else
{
if(iter < n+2)
tot_res += cur_time ;  
cur_time += q1_b[i] ;
tot_com += cur_time ;
q1_b.erase(q1_b.begin() + i) ;
q1_q.erase(q1_q.begin() + i) ;  
flag = 0 ;
}
if(flag)
{
if(i < q1_b.size()-1) i++;
else i = 0 ; }
}
else if((select % 3 == 0) && !q2_b.empty())
{
iter++ ;
cout << "hie"<< endl ;
q2_q[j] = q_dash + (long double) ((q_dash)/ square(q2_b[j] + q2_q[j])) ;
cout <<"my q is " << q2_q[j] << endl ;
int flag = 1 ;
if(q2_b[j] > q2_q[j])
{
if(iter < n+2)
tot_res += cur_time ;  

q2_b[j] = q2_b[j] - q2_q[j] ;

  cur_time += q2_q[j];


}

else
{
if(iter < n+2)
tot_res += cur_time ;  
cur_time += q2_b[j] ;
tot_com += cur_time ;
q2_b.erase(q2_b.begin() + j) ;
q2_q.erase(q2_q.begin() + j) ;  
flag= 0 ;  
}
if(flag)
{
if(j < q2_b.size()-1) j++;
else j = 0 ;
}

}
cout << cur_time <<" "<< tot_res << " "<< tot_com << endl ;

select++ ;
}

cout << "response time =" << (long double)(tot_res - 11)/n << endl ;
cout << "waiting time = " << (long double) (tot_com - tot_burst - 11) /n << endl ;
cout << "turn around time =" << (long double)(tot_com - 11) / n << endl ;
 


// 0 8 18

}
