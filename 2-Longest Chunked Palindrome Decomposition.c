class Solution {
public:
    int longestDecomposition(string text) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        string a,b;
        int i=0,j=text.size()-1,ans=0;

        while(i<j)
        {
            //Appending characters from start and end
            a+=text[i];
            b=text[j]+b;

            if(a==b)
            {
                ans++;
                a="";
                b="";
            }
            i++;
            j--;
        }

        //We incremented answer by 1, but actually got two strings; so multiply answer by 2.
        ans*=2;

        //If no string exists in middle, we can directly return answer.
        if(a=="" and i>j)
            return ans;
        //Account for the string in the middle
        return ans+1;
    }
};
