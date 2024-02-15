#include "set.h"
#include <iostream>
#include <chrono>


size_t lcg() {
	static size_t x = 0;
	x = (1021 * x + 24631) % 116640;
	return x;
}


int main() {

	using namespace SetSpace;
	using namespace std;

	Set set1000;
	int count = 100000;
	
	chrono::steady_clock::time_point _begin, _end;
	double sum = 0;

	//for (int i = 0; i < 100; ++i)
	//{
		//begin = chrono::steady_clock::now();
		for (int j = 0; j < count; ++j)
		{
			set1000.insert(lcg());
		}
		//end = chrono::steady_clock::now();
		//sum += static_cast<double>(chrono::duration_cast<std::chrono::milliseconds>(end - begin).count());
	//}

	//for (int i = 0; i < 1000; ++i)
	//{
	//	_begin = chrono::steady_clock::now();
	//	//std::find(begin(set1000), end(set1000), lcg());
	//	set1000.contains(lcg());
	//	_end = chrono::steady_clock::now();
	//	sum += chrono::duration_cast<std::chrono::milliseconds>(_end - _begin).count();
	//}

	for (int i = 0; i < 1000; ++i)
	{
		_begin = chrono::steady_clock::now();
		/*	set1000.push_back(lcg());
			set1000.erase(remove(set1000.begin(), set1000.end(), lcg()), set1000.end());*/
		set1000.insert(lcg());
		set1000.erase(lcg());
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