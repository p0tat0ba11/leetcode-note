# 151. Reverse Words in a String

## Method

```cpp=
class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string str="";
        for(char ch: s) {
            if(ch == ' ') {
                if(str != "") {
                    words.push_back(str);
                    str = "";
                }
            }
            else str.push_back(ch);
        }
        if(str != "") {
            words.push_back(str);
            str = "";
        }
        for(int i=words.size()-1; i >= 0; --i) {
            if(i != 0)
                str += words[i] + " ";
            else str += words[i];
        }
        return str;
    }
};
```