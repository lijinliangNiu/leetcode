/*
 * @lc app=leetcode.cn id=468 lang=cpp
 *
 * [468] 验证IP地址
 */

// @lc code=start
class Solution {
private:
    vector<string> split(const string& s, const char delim){
        string s_tmp = s;
        vector<string> ans;
        while(s_tmp.find(delim) != s_tmp.npos){
            ans.push_back(s_tmp.substr(0, s_tmp.find(delim)));
            s_tmp = s_tmp.substr(s_tmp.find(delim) + 1);
        }
        ans.push_back(s_tmp);
        return ans;
    }
    
    bool is_ipv4(string ip){
        vector<string> parts = split(ip, '.');
        if(parts.size() != 4){
            return false;
        }
        for(string& part : parts){
            if(part.empty() || (part.size() > 1 && part[0] == '0') || part.size() > 3){
                return false;
            }
            for(char& ch : part){
                if(!isdigit(ch)){
                    return false;
                }
            }
            int num = stoi(part);
            if(num < 0 || num > 255){
                return false;
            }
        }
        return true;
    }

    bool is_ipv6(string ip){
        vector<string> parts = split(ip, ':');
        if(parts.size() != 8){
            return false;
        }
        for(string& part : parts){
            if(part.empty() || part.size() > 4){
                return false;
            }
            for(char& ch : part){
                if(!(isdigit(ch) || (ch >= 'a' && ch <= 'f') || (ch >= 'A' && ch <= 'F'))){
                    return false;
                }
            }
        }
        return true;
    }
public:
    string validIPAddress(string IP) {
        if (is_ipv4(IP)) {
            return "IPv4";
        } 
        if (is_ipv6(IP)) {
            return "IPv6";
        }
        return "Neither";
    }
};
// @lc code=end

