class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) 
	{
		for (int i = 0; i < cost.size(); )
		{
			int leftGas = 0;
			int j = 0;
			for (; j < cost.size(); j++)
			{
				int k = (i+j)%cost.size();
				leftGas += (gas[k] - cost[k]);
				if (leftGas < 0) break;
			}
			if ( j == cost.size()) return i;
			i+=j+1;
		}
		return -1;
	}
};