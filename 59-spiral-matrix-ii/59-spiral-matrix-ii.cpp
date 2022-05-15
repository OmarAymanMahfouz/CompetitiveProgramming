class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> vec(n, vector<int>(n));
        
        int i = 0, j = 0;
        bool right = true, left = false, up = false, down = false;
        int num = 0;
        while(true){
            vec[i][j] = ++num;
            
            if(right){
                if(j + 1 < n && !vec[i][j + 1]) j++;
                else right = false, down = true, i++;
            }
            else if (down){
                if (i + 1 < n && !vec[i + 1][j]) i++;
                else down = false, left = true, j--;
            }
            else if (left){
                if (j - 1 > -1 && !vec[i][j - 1]) j--;
                else left = false, up = true, i--;
            }
            else if(up){
                if (i - 1 > -1 && !vec[i - 1][j]) i--;
                else up = false, right = true, j++;
            }
            
            if(i >= n || j >= n || i < 0 || j < 0)
                break;
            if (vec[i][j])
                break;
        }
        return vec;
    }
};