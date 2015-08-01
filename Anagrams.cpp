//Sort the string see if it existed in the map
class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        // Note: The Solution object is instantiated only once.
        vector<string> solution;
				map<string,int> smp;
				map<string,int>::iterator it;
				for(int i = 0; i < strs.size(); i++)
				{
					string tmps = strs[i];
					sort(tmps.begin(),tmps.end());
					it = smp.find(tmps);
					if(it==smp.end())
							smp.insert(pair<string, int>(tmps, i));
						//smp[tmps] = i;
					else{
						if(smp[tmps]==-1)
							solution.push_back(strs[i]);
						else
						{
							solution.push_back(strs[smp[tmps]]);
							smp[tmps]=-1;
							solution.push_back(strs[i]);
						}
					}
				}
				return solution;
    }
};
