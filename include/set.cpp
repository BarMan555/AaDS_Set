class Set {
	struct Node {
		int key;
		Node* left;
		Node* right;
	};

public:
	Set() = default;
	Set(const Set& other);
	~Set();

	void print() const;
	bool insert(int key);
	bool contains(int key);
	bool erase(int key);

	Set& operator+(const Set& set);
};
