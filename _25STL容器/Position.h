#pragma once
class Position {
public:
	int x()const { return m_x; }
	int y()const { return m_y; }
	Position(int x, int y) :m_x(x), m_y(y) {}
private:
	int m_x = 0;
	int m_y = 0;
};

template<class T> inline void hash_combine(std::size_t& seed, const T& v) {
	std::hash<T> hasher;
	seed ^= hasher(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}
namespace std {
	template<> class hash<Position> {
	public:
		size_t operator()(const Position& p)const {
			auto key = hash<int>()(p.x());
			hash_combine(key, p.y());
			return key;
		}
	};
}