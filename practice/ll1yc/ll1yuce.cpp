#include"ll1yuce.h"

void LL1YUCE::get_table()
{
	for (int i = 0; i<T; i++)
	{
		char tmp = analy_str[i].right[0];
		if (!isNotSymbol(tmp))
		{
			if (tmp != '$')
				tableMap[get_index(analy_str[i].left)][get_nindex(tmp)] = i;
			if (tmp == '$')
			{
				set<char>::iterator  it;
				for (it = follow_set[get_index(analy_str[i].left)].begin(); it != follow_set[get_index(analy_str[i].left)].end(); it++)
				{
					tableMap[get_index(analy_str[i].left)][get_nindex(*it)] = i;
				}
			}
		}
		else
		{
			set<char>::iterator ti;
			for (ti = first_set[get_index(tmp)].begin(); ti != first_set[get_index(tmp)].end(); ti++)
			{
				tableMap[get_index(analy_str[i].left)][get_nindex(*ti)] = i;
			}
			if (first_set[get_index(tmp)].count('$') != 0)
			{
				set<char>::iterator  it;
				for (it = follow_set[get_index(analy_str[i].left)].begin(); it != follow_set[get_index(analy_str[i].left)].end(); it++)
				{
					tableMap[get_index(analy_str[i].left)][get_nindex(*it)] = i;
				}
			}
		}
	}
}
void LL1YUCE::analyExp(string s)
{
	for (int i = s.length() - 1; i >= 0; i--)
		left_any.push_back(s[i]);

	to_any.push_back('#');
	to_any.push_back(non_colt[0]);


	while (left_any.size()>0)
	{
		//cout<<"分析栈：";
		string outs = "";
		for (int i = 0; i<to_any.size(); i++)
			outs += to_any[i];
		cout << setw(15) << outs;

		//cout<<"剩余输入串：";
		outs = "";
		for (int i = left_any.size() - 1; i >= 0; i--)
			outs += left_any[i];
		cout << setw(15) << outs;

		char char1 = to_any[to_any.size() - 1];
		char char2 = left_any[left_any.size() - 1];
		if (char1 == char2 && char1 == '#')
		{
			cout << setw(15) << "Accepted!" << endl;
			return;
		}
		if (char1 == char2)
		{
			to_any.pop_back();
			left_any.pop_back();
			cout << setw(15) << char1 << "匹配" << endl;
		}
		else if (tableMap[get_index(char1)][get_nindex(char2)] != -1)
		{
			int tg = tableMap[get_index(char1)][get_nindex(char2)];
			to_any.pop_back();

			if (analy_str[tg].right != "$")
			{
				for (int i = analy_str[tg].right.length() - 1; i >= 0; i--)
					to_any.push_back(analy_str[tg].right[i]);
			}
			//cout<<"推导："<<analy_str[tg].right<<endl; 
			cout << setw(15) << analy_str[tg].right << endl;
		}
		else
		{
			cout << setw(15) << "error!" << endl;
			return;
		}
	}
}

void LL1YUCE::print_out()
{
	//table
	for (int i = 0; i<ter_copy.size(); i++)
	{
		cout << setw(10) << ter_copy[i];
	}
	cout << endl;
	for (int i = 0; i<non_colt.size(); i++)
	{
		cout << non_colt[i] << ": ";
		for (int j = 0; j<ter_copy.size(); j++)
		{
			if (tableMap[i][j] == -1)
				cout << setw(10) << "error";
			else
				cout << setw(10) << analy_str[tableMap[i][j]].right;

		}
		cout << endl;
	}
}

void LL1YUCE::getAns()
{
	inputAndSolve();
	display();
	get_table();
	print_out();
	//栈匹配
	string ss;
	cout << "请输入符号串：" << endl;
	cin >> ss;
	cout << setw(15) << "分析栈" << setw(15) << "剩余输入串" << setw(15) << "推导式" << endl;
	analyExp(ss);

}
