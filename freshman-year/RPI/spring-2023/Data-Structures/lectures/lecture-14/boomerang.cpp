double operator-(vector<int>& A, vector<int>& B){
    if(B[0]==A[0]){
        return std::numeric_limits<double>::infinity();
    }
    return (double)(B[1]-A[1])/(double)(B[0]-A[0]);
}

class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        // as long as two points are the same, all 3 must be in the same line.
        if(points[0]==points[1] || points[0]==points[2] || points[1]==points[2]){
            return false;
        }
        cout<< (points[1]-points[0]) <<endl;
        cout<< (points[2]-points[0]) <<endl;
        // as long as they have different slope.
        return ((points[1]-points[0]) != (points[2]-points[0])); 
    }
};
