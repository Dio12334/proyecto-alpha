#include<iostream>
#include<vector>
#include<algorithm>

/*
 *1 1 2 -2 5 2 4 4 -1 -2 5
 * 
 * */


std::vector<int> buscar_impar(std::vector<int> v){
	vector<int> res;
	sort(v.begin(), v.end());

	/*
	 *-2 -2 -1 1 1 2 2 4 4 5 5
	 *res = empty
	 *res = -2
	 *res = empty
	 */
	for(auto item: v){
		if(!res.empty() && res.back() == item)
			res.pop_back();
		else
			res.push_back(item);
	}
	return res;
}
