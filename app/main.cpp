#include "set.h"
#include <iostream>
#include <chrono>
#include <vector>


size_t lcg() {
	static size_t x = 0;
	x = (1021 * x + 24631) % 116640;
	return x;
}


int main() {

	using namespace SetSpace;
	using namespace std;

	const int count = 100000;

	Set set;
	vector<int> vec; vec.reserve(count);

	chrono::steady_clock::time_point _begin, _end;
	double sum = 0;

	// Время заполнения
	for (int i = 0; i < 100; ++i)
	{
		_begin = chrono::steady_clock::now();
		for (int j = 0; j < count; ++j)
		{
			set.insert(lcg());
			//vec.push_back(lcg());
		}
		_end = chrono::steady_clock::now();
		sum += static_cast<double>(chrono::duration_cast<std::chrono::milliseconds>(_end - _begin).count());
	}		

	sum = 0;
	// Время поиска
	for (int i = 0; i < 1000; ++i)
	{
		_begin = chrono::steady_clock::now();
		set.contains(lcg());
		//std::find(vec.begin(), vec.end(), lcg());
		_end = chrono::steady_clock::now();
		sum += chrono::duration_cast<std::chrono::milliseconds>(_end - _begin).count();
	}

	sum = 0;
	// Время добавления и удаления
	for (int i = 0; i < 1000; ++i)
	{
		_begin = chrono::steady_clock::now();
		set.insert(lcg());
		set.erase(lcg());

		/*vec.push_back(lcg());
		auto it = std::remove(vec.begin(), vec.end(), lcg());
		vec.erase(it, vec.end());*/
		_end = chrono::steady_clock::now();
		sum += chrono::duration_cast<std::chrono::milliseconds>(_end - _begin).count();
	}

	std::cout << "The time: " << sum / 1000 << " ms\n";

	return 0;
}

// insert_time 1 000: 0.08 ms
// insert_time 10 000: 6.86 ms
// insert_time 100 000: 32.66 ms
//
// insert_time_vector 1 000: 0 ms
// insert_time_vector 10 000: 0.03 ms
// insert_time_vector 100 000: 6.57 ms
//
// -------------------------------//
// search_time 1 000: 0ms
// search_time 10 000: 0ms
// search_time 100 000: 0ms
//	
// search_time_vector 1 000: 0ms
// search_time_vector 10 000: 0.001 ms
// search_time_vector 100 000: 0.016 ms
//
// -------------------------------//
//
// erase_time 1 000: 0.008 ms
// erase_time 10 000: 0.700 ms
// erase_time 100 000: 4.22 ms
//
// erase_time_vector 1 000: 0 ms
// erase_time_vector 10 000: 2.008 ms
// erase_time_vector 100 000: 16.92 ms