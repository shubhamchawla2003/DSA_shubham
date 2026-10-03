class Solution {
public:
    bool backspaceCompare(string s, string t) {

        int n = s.length();
        int m = t.length();

        stack<char> s_st;
        stack<char> t_st;

        for(int i=0;i<n;i++){

            if(s_st.empty() && s[i]=='#'){
                continue;
            }

            if(!s_st.empty() && s[i]=='#'){
                s_st.pop();
                continue;
            }

            s_st.push(s[i]);

        }

        for(int i=0;i<m;i++){

            if(t_st.empty() && t[i]=='#'){
                continue;
            }

            if(!t_st.empty() && t[i]=='#'){
                t_st.pop();
                continue;
            }

            t_st.push(t[i]);

        }

        string new_s = "";
        string new_t = "";

        while(!s_st.empty()){
            char ch = s_st.top();
            s_st.pop();
            new_s += ch;
        }

        while(!t_st.empty()){
            char ch = t_st.top();
            t_st.pop();
            new_t += ch;
        }

        //reverse(new_s.begin(),new_s.end());
        //reverse(new_t.begin(),new_t.end());

        return new_s==new_t ? true : false;
        
    }
};