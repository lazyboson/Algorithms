#ifndef UNIONFIND_H
#define UNIONFIND_H
#include <vector>

class UnionFind
{
	std::vector<int> m_Parent, m_Rank;
public:
	explicit UnionFind(int);
	bool find_set(int);
	bool is_same(int, int);
	void union_set(int, int);
};
#endif


