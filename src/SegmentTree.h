#ifndef SEGMENT_TREE_H
#define SEGMENT_TREE_H
#include <vector>

class SegmentTree
{
	std::vector<int> m_SegmentTree, m_Data;
	int m_Size;

	static int left(int p) {
		return p << 1;
	}

	static int right(const int p) {
		return (p << 1) + 1;
	}
	void build(int p, int L, int R);
	int rmq(int p, int L, int R, int i, int j);
public:
	explicit SegmentTree(const std::vector<int>& _data);
};
#endif


