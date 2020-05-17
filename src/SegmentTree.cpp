#include "SegmentTree.h"

void SegmentTree::build(int p, int L, int R) {
	if (L == R)
		m_SegmentTree[p] = L;
	else {
		build(left(p), L, (L + R) / 2);
		build(right(p), (L + R) / 2 + 1, R);
		auto p1 = m_SegmentTree[left(p)], p2 = m_SegmentTree[right(p)];
		m_SegmentTree[p] = (m_Data[p1] <= m_Data[p2]) ? p1 : p2;
	}
}

int SegmentTree::rmq(int p, int L, int R, int i, int j) {
	if (i > R || j < L)
		return -1;
	if (L >= i && R <= j)
		return m_SegmentTree[p];
	auto p1 = rmq(left(p), L, (L + R) / 2, i, j);
	auto p2 = rmq(right(p), (L+R)/2+1, R, i, j);
	if (p1 == -1)
		return p2;
	if (p2 == -1)
		return p1;
	return m_Data[p1] <= m_Data[p2] ? p1 : p2;
	
}

SegmentTree::SegmentTree(const std::vector<int>& _data) {
	m_Data = _data;
	m_Size = _data.size();
	m_SegmentTree.assign(4 * m_Size, 0);
	build(1, 0, m_Size - 1);
}
