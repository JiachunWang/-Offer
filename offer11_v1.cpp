#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int len = rotateArray.size();
        if(len==0)
            return 0;
        if(rotateArray[0] < rotateArray[len-1] || len == 1)
            return rotateArray[0];
        int low=0, high=len-1, mid;
        while(low<=high){
            mid = (low+high)/2;
            if(rotateArray[mid]<rotateArray[mid-1])
                return rotateArray[mid];
            if(rotateArray[0]==rotateArray[mid] && rotateArray[mid]==rotateArray[len-1])
                return orderSearch(rotateArray);
            else if(rotateArray[mid]>rotateArray[0] || rotateArray[mid]>rotateArray[len-1])
                low = mid + 1;
            else if(rotateArray[mid]<rotateArray[0] || rotateArray[mid]<rotateArray[len-1])
                high = mid - 1;
        }
    }
private:
    int orderSearch(vector<int> rotateArray){
        int len = rotateArray.size();
        for(int i=1;i<len;i++){
            if(rotateArray[i]<rotateArray[i-1])
                return rotateArray[i];
        }
        return rotateArray[0];
    }
};

int main() {
    Solution s;
    int a[]={3,3,3,3,3,3};
    int b[]={3,3,3,1,2,2};
    int c[]={3,3,3,1,3,3};
    vector<int> t1(a,a+6);
    vector<int> t2(b,b+6);
    vector<int> t3(c,c+6);
    int r1 = s.minNumberInRotateArray(t1);
    int r2 = s.minNumberInRotateArray(t2);
    int r3 = s.minNumberInRotateArray(t3);
    cout<<r1<<" "<<r2<<" "<<r3<<endl;
    return 0;
}