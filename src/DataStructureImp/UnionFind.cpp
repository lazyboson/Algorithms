#include "UnionFind.h"

UnionFind::UnionFind(const int n) {
	m_Parent.assign(n, 0);
	m_Rank.assign(n, 0);
	//by default each data member is it's own parent
	for (int i = 0; i < n; i++)
		m_Parent[i] = i;
}

bool UnionFind::find_set(int i) {
	return m_Parent[i] == i ? i : m_Parent[i] = find_set(m_Parent[i]);
	
}

bool UnionFind::is_same(const int i, const int j) {
	return find_set(i) == find_set(j);
}

void UnionFind::union_set(const int i, const int j) {
	if(!is_same(i,j)) {
		const int x = find_set(i);
		const int y = find_set(j);
		if (m_Rank[x] > m_Rank[y]) {
			m_Parent[y] = x;
		}
		else {
			m_Parent[x] = y;
			if (m_Rank[x] == m_Rank[y]) {
				m_Rank[y]++;
			}
		}
	}
}
