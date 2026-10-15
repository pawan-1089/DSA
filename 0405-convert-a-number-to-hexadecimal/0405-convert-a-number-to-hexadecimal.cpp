class Solution {
public:
    string toHex(int num) {
        if (num == 0)return "0";
        string digits = "0123456789abcdef";
        string ans = "";
        unsigned int n = static_cast<unsigned int>(num);
        while (n > 0) {
            int rem = n & 15;
            ans += digits[rem];
            n >>= 4;
        }
        int i = 0, j = ans.size() - 1;
        while (i < j) {
            char temp = ans[i];
            ans[i] = ans[j];
            ans[j] = temp;
            i++;
            j--;
        }
        return ans;
    }
};