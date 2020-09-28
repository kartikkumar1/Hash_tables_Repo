#include <iostream>
#include <vector>
#include <string>
#include <map>
#include<iterator>

using std::string;
using std::vector;
using std::cin;

struct Query {
	string type, name;
	int number;
};



vector<Query> read_queries() {
	int n;
	cin >> n;
	vector<Query> queries(n);
	for (int i = 0; i < n; ++i) {
		cin >> queries[i].type;
		if (queries[i].type == "add")
		{
			cin >> queries[i].number >> queries[i].name;
			//pBook.insert(std::pair<int,string>(queries[i].number,queries[i].name) );
		}
		else
			cin >> queries[i].number;
	}
	return queries;
}

void write_responses(const vector<string>& result) {
	for (size_t i = 0; i < result.size(); ++i)
		std::cout << result[i] << "\n";
}

vector<string> process_queries(const vector<Query>& queries)
{
	//vector<string> result;
	//// Keep list of all existing (i.e. not deleted yet) contacts.
	//vector<Query> contacts;
	//for (size_t i = 0; i < queries.size(); ++i)
	//	if (queries[i].type == "add")
	//	{
	//		bool was_founded = false;
	//		// if we already have contact with such number,
	//		// we should rewrite contact's name
	//		for (size_t j = 0; j < contacts.size(); ++j)
	//			if (contacts[j].number == queries[i].number)
	//			{
	//				contacts[j].name = queries[i].name;
	//				was_founded = true;
	//				break;
	//			}
	//		// otherwise, just add it
	//		if (!was_founded)
	//			contacts.push_back(queries[i]);



	//	}
	//	else if (queries[i].type == "del")
	//	{
	//		for (size_t j = 0; j < contacts.size(); ++j)
	//			if (contacts[j].number == queries[i].number)
	//			{
	//				contacts.erase(contacts.begin() + j);
	//				break;
	//			}

	//	}
	//	else
	//	{
	//		string response = "not found";
	//		for (size_t j = 0; j < contacts.size(); ++j)
	//			if (contacts[j].number == queries[i].number)
	//			{
	//				response = contacts[j].name;
	//				break;
	//			}
	//		result.push_back(response);
	//	}
	////return result;


	vector<string> res;
	std::map <int, string> pBook;
	std::map <int, string> pBookResult;
	for (size_t i = 0; i < queries.size(); ++i)
	{
		if (queries[i].type == "add")
		{
			auto check= pBookResult.insert(std::pair<int, string>(queries[i].number, queries[i].name));
			if (check.second == false)
				check.first->second = queries[i].name;
		}
		else if (queries[i].type == "del")
		{
			pBookResult.erase(queries[i].number);
		}
		else
		{
			//std::map<int, string>::iterator checkIfpresent;
			string response;
			auto checkIfpresent = pBookResult.find(queries[i].number);
			if (checkIfpresent == pBookResult.end())
				response = "not found";
			else
				response = checkIfpresent->second;
			res.push_back(response);
		}
	}
	return res;
}

int main() {
	write_responses(process_queries(read_queries()));
	return 0;
}
