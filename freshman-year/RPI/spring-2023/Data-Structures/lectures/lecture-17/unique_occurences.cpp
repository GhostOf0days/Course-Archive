// test case: arr = [1,2,2,1,1,3]
// result: return true
class Solution {
public:
    // use both a map and a set
    bool uniqueOccurrences(vector<int>& arr) {
        // key: array element, value: number of occurrences
        map<int,int> map1;
        std::map<int,int>::iterator itr1;
        int size = arr.size();
        for(int i=0;i<size;i++){
            map1[arr[i]]++;
        }
        // map1:
        // map1[1]:3
        // map1[2]:2
        // map1[3]:1

        // create a set
        set<int> set1;
        std::pair<std::set<int>::iterator,bool> tmp;
        // traverse the map
        itr1=map1.begin();
        while(itr1!=map1.end()){
            tmp = set1.insert(itr1->second);
            if(tmp.second==false){
                return false;
            }
            itr1++;
        }
        return true;
    }
};
