// TWo pointers:
// O(NlogN)
class Solution {
public:
struct Node  
    {  
        int num, idx;  
        Node(int _num = 0, int _idx = 0):num(_num),idx(_idx){}  
        bool operator < (Node  orh)  
        {     
            return num < orh.num;  
        }  
    };  
	vector<int> twoSum(vector<int> &numbers, int target){
	    int i,j;
	    int flag=0;
		vector<Node> nodes(numbers.size());
        for(int i = 0; i < numbers.size(); i++)  
            nodes[i] = Node(numbers[i], i);  
		 sort(nodes.begin(), nodes.end());
		i=0;
		j=nodes.size()-1;
		while(nodes[i].num+nodes[j].num!=target)
		{
			if(nodes[i].num+nodes[j].num<target)
				i++;
			else if(nodes[i].num+nodes[j].num>target)
				j--;
			else
			    break;
			
		}
		vector<int> twoSum(2);  
        twoSum[0] = min(nodes[i].idx+1, nodes[j].idx+1); 
        twoSum[1] = max(nodes[i].idx+1, nodes[j].idx+1);  
        return twoSum;  
					
	}
				
};
