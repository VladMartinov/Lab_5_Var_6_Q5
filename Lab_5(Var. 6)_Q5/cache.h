#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

template <class T>
class Cache {
public:

	void put(T elem) { cacheVector.push_back(elem); }
	void operator += (T elem) { cacheVector.push_back(elem); }

	bool contains(T elem) {
		if (find(cacheVector.begin(), cacheVector.end(), elem) != cacheVector.end())
			return true;
		else
			return false;
	}

private:
	vector<T> cacheVector;
};

template <>
class Cache<string> {
public:

	void put(string elem) {
		try {
			if (cacheVector.size() < 100)
				cacheVector.push_back(elem);
			else
				throw 1;
		}
		catch (int i) {
			if (i == 1) cout << "You have full Cache!!!" << endl;
			else cout << "Error!" << endl;
		}
	}
	void operator += (string elem) { 
		try {
			if (cacheVector.size() < 100)
				cacheVector.push_back(elem);
			else
				throw 1;
		}
		catch (int i) {
			if (i == 1) cout << "You have full Cache!!!" << endl;
			else cout << "Error!" << endl;
		}
	}


	bool contains(string elem) {
		bool found(false);
		for (size_t i = 0; !found && (i < cacheVector.size()); ++i)
		{
			if (cacheVector[i][0] == elem[0])
				found = true;
		}
		return found;
	}

private:
	vector<string> cacheVector;
};
