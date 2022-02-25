#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Solution{
    public: string func(string s){
        vector<int> t={0};
        int j=0;
        while (j<s.size()){
            if (!isalnum(s[j])){
                if (s[j]=='.'||s[j]=='!'||s[j]=='?'){
                    t.push_back(j+1);

                }
            } else s[j]= tolower(s[j]);
            j++;
        }
        for(int i=0;i<t.size();i++){
            int j=t[i];
            while (s[j]== ' '&& j<s.size()){
                j++;
            }
            s[j] = toupper(s[j]);
        }

        return s;

}

};

int main() {

    Solution s = Solution();
    string abc= "pRICES FoR BULK COnTracTS oF COfFEE haVE jUmPed 28 PeR CENt ON AVErAge from 2019 lEVels, AcCoRDiNg to tRadiNG On cHiNa FUtuRes Markets. In THIs wAY, THe PoPUlARItY OF THE Cafe mAY be gOInG DoWn AGaiN!";

    string ret = s.func(abc);
    cout<<ret<<endl;
     return 0;
}
