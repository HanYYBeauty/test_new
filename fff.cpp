#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define max(Maxnum,temp)  (Maxnum>temp ? Maxnum : temp)  // find the bigger one 
 
using namespace std;

typedef vector<vector<long > >::iterator ITER;
 
bool Vectorcomp(const vector<long > &v1,const vector<long > &v2){
    return v1[1] < v2[1];
}

long  getMaxConcurrentNum(vector<vector<long > > &connections,ITER it1,ITER it2){// compare iterator it1 with it2
    long  Maxnum = 0;
    vector<long > starttime;
    priority_queue<long ,vector<long >,greater<long > > entime;   // entime(endtime of thread)
    for(ITER it = it1;it != it2;++it){
        starttime.push_back((*it)[2]);
        entime.push((*it)[3]);
    }
    sort(starttime.begin(),starttime.end());  //
    for(size_t i = 0;!entime.empty();i++){
        long  MinEnd = entime.top();
        entime.pop();
        long  temp = lower_bound(starttime.begin(),starttime.end(),MinEnd)-starttime.begin() - i;
        Maxnum = max(Maxnum,temp);
    }
    return Maxnum;
}


long  getMaxPool(vector<vector<long > > &connections){
    long  MaxRes = 0,PoolRes;
    sort(connections.begin(),connections.end(),Vectorcomp);
    for(ITER it = connections.begin();it != connections.end() ; )
	{
        long  poolID = (*it)[1];
        pair<ITER ,ITER>  pa;
        pa = equal_range(it,connections.end(),vector<long >(4,poolID),Vectorcomp);
        long  temp = getMaxConcurrentNum(connections,pa.first,pa.second);
        if(temp > MaxRes)
		{
            MaxRes = temp;
            PoolRes = poolID;
        }
        it = pa.second;
    }
    return PoolRes;
}
int main()
{
    long  v1[4] = {10000,20000,1411325674537,1411325726830};
    long  v2[4] = {10001,20001,1411325632683,1411325731213};
    long  v3[4] = {10002,20000,1411325508697,1411325726810};
	long  v4[4] = {10003,20001,1411325632784,1411325731213};
	long  v2[4] = {10001,20001,1411325632683,1411325731213};
    long  v3[4] = {10002,20000,1411325508697,1411325726810};
	long  v4[4] = {10003,20001,1411325632784,1411325731213};
	long  v2[4] = {10001,20001,1411325632683,1411325731213};
    long  v3[4] = {10002,20000,1411325508697,1411325726810};
	long  v4[4] = {10003,20001,1411325632784,1411325731213};
	long  v2[4] = {10001,20001,1411325632683,1411325731213};
    long  v3[4] = {10002,20000,1411325508697,1411325726810};
    printf("zhangpengshishadiao");
    vector<vector<long > > data;
    data.push_back(vector<long >(v1,v1+4));
    data.push_back(vector<long >(v2,v2+4));
    data.push_back(vector<long >(v3,v3+4));
	data.push_back(vector<long >(v4,v4+4));
     
    cout<<getMaxPool(data)<<endl; 
    return 0;
}


