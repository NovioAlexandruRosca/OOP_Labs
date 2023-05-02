#include <map>
#include <queue>
#include <utility>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

ifstream file("Text.txt");

typedef pair<string, int> Pair;

struct ComparePairs {
	bool operator()(Pair& p1,Pair& p2){
		
		if (p1.second != p2.second)
		{
			return p1.second < p2.second;
		}

		int result = p1.first.compare(p2.first);

		if (result > 0)
			return 1;
		
		return 0;

	}
};

int main()
{
	string sentence;
	string del = " ?.!,\n";

	map<string, int> list;

	getline(file, sentence);
		
	transform(sentence.begin(), sentence.end(),sentence.begin(), [](unsigned char c) { return tolower(c); });
	string word;

	int end = sentence.find_first_of(del);
	while (end != string::npos) {

		word = sentence.substr(0, end);
		
		if(word.size() > 0)
		{
			list[word]++;
		}

		sentence.erase(sentence.begin(), sentence.begin() + end + 1);
		end = sentence.find_first_of(del);
	}

	word = sentence.substr(0, end);

	if (word.size() > 0)
	{
		list[word]++;
	}

	priority_queue<Pair, vector<Pair>, ComparePairs> prio;

	for (auto& pair : list) {
		prio.push(pair);
	}

	while (!prio.empty())
	{
		cout << prio.top().first << " => ";
		cout << prio.top().second << endl;
		prio.pop();
	}
}