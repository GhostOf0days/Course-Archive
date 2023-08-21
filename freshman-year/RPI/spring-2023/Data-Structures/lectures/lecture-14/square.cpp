// we define - as the distance, and it's always non-negative.
int operator-(vector<int>& A, vector<int>& B){
    return ((A[0]-B[0]) * (A[0]-B[0])) + ((A[1]-B[1]) * (A[1]-B[1]));
}

class Solution {
public:
    // when this function is called, we assume p1 and p3 are the diagonal endpoints, same for p2 and p4.
    bool helper(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4){
        if(p1!=p2 && p1!=p3 && p1!=p4 && p2!=p3 && p3!=p4 && p2!=p4 &&  // points shouldn't have the same coordinates.
            p1-p2 == p2-p3 &&
            p2-p3 == p3-p4 &&
            p3-p4 == p4-p1 &&
            p1-p3 == p2-p4){
            return true;
        }
        return false;
    }

    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        // from p1's perspective, there are only 3 situations, which is who will be the other diagonal endpoint.
        return  helper(p1,p2,p3,p4) || helper(p1,p2,p4,p3) || helper(p1,p4,p2,p3);
    }
};
