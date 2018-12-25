#include <bits/stdc++.h>
using namespace std;

typedef struct meeting{

	string Organizer;
	string Name;
	int st_time;// 24 hour clock
	int end_time;//24 hour clock
	int attendees;// total people attending 
};

meeting* getMeeting(string org,string name,int stTime,int endTime,int totAttendees)
{
	meeting* m = new meeting;
	m->Organizer = org;
	m->Name = name;
	m->st_time = stTime;
	m->end_time = endTime;
	m->attendees = totAttendees;

	return m;
} 

typedef struct employees{

	string Name;
	string Designation;
	int rank_id;// lower id better designation
	vector<meeting*> calendar;
};

employees* getEmployee(string name,string designation,int rank,vector<meeting*> cal)
{
	employees* e = new employees;
	e->Name = name;
	e->Designation = designation;
	e->calendar = cal;

	return e;
}

int convertTo24Hour(string time)
{
	int len = time.length();
	string am_pm = time.substr(len-2,2);
	int add = 0;

	if(am_pm == "PM")// need to add 12 for after noon times
		add += 12;

	int hour = add + stoi(time.substr(0,2));
	int min = stoi(time.substr(3,2));

	return (100*hour + min);

}

int assignRank(map<string,int> rank,string designation)// using map for fast access
{
		return(rank[designation]);
}

bool comp(const pair<meeting*,int> &a, const pair<meeting*,int> &b )
{
	return (a.second < b.second);
}

vector<pair<meeting*,meeting*> > findConflict(employees* emp)
{
	int flag = 0;// current meetings
	vector<meeting*> schedule = emp->calendar;
	vector<pair<meeting*,int> > mymeet;

	for(int i=0;i<schedule.size();i++)
	{
		mymeet.push_back(make_pair(schedule[i],schedule[i]->st_time));
		mymeet.push_back(make_pair(schedule[i],schedule[i]->end_time));
	}

	sort(mymeet.begin(),mymeet.end(),comp);// it will sort according to time

	vector<meeting*> existing;// existing meeting happening
	vector<pair<meeting*,meeting*> > conflict;// it will store the conflicts

	for(int i=0;i<mymeet.size();i++)
	{
		if((mymeet[i].first)->st_time == mymeet[i].second)// this means a meeting has started
		{
			if(flag == 0)// no conflicts
			{
				existing.push_back(mymeet[i].first);
			}
			else if(flag > 0)// flag no. of meetings currently going on 
			{
				for(int j=0;j<existing.size();j++)// add conflicts with existing meetings
				{
					conflict.push_back(make_pair(existing[j],mymeet[i].first));
				}
			}

			flag++;// ione more meeting
		}
		else // this meeting has stopped
		{	
			existing.erase(remove(existing.begin(), existing.end(), mymeet[i].first), existing.end()); //  will remove meeting from existing as it has stopped
			flag--;// one less meeting
		}
		
	}

	// return vector<pair<meeting*,meeting*> >();
	return conflict;
}

int heirarchy(string name,map<string,int> rank,vector<employees*> totalEmp)
{
	int ind;
	for(int i=0;i<totalEmp.size();i++)
	{
		if(! (totalEmp[i]->Name).compare(name))
		{
			return rank[totalEmp[i]->Designation];
		}
	}
	
}
// setting priorities
meeting* clearConflict(meeting* m1,meeting* m2,employees* emp,vector<employees*> totalEmp,map<string,int> rank)// clears conflict between two meeting
{
	// Case 1
	if(m1->Organizer == emp->Name && m2->Organizer != emp->Name)
		return m1;
	if(m1->Organizer != emp->Name && m2->Organizer == emp->Name)
		return m2;

	// Case 2
	if(heirarchy(m1->Organizer,rank,totalEmp) > heirarchy(m2->Organizer,rank,totalEmp))
		return m1;
	if(heirarchy(m2->Organizer,rank,totalEmp) > heirarchy(m1->Organizer,rank,totalEmp))
		return m2;

	// Case 3
	if(m1->attendees < m2->attendees)
		return m1;
	if(m2->attendees < m1->attendees)
		return m2;

	//else return meeting
	return m1;

}

vector<meeting*> resolveConflictAll(vector<pair<meeting*,meeting*> > conflict,employees* emp,vector<employees*> totalEmp,map<string,int> rank)// gives final conflict free meetings
{

	vector<meeting*> finalMeet;
	cout << "	1	" << "	2	" << endl;

	for(int i=0;i<conflict.size();i++)
	{
		cout << (conflict[i].first)->Name << "		" << (conflict[i].second)->Name << endl;
		meeting* winner = clearConflict(conflict[i].first,conflict[i].second,emp,totalEmp,rank);
		cout << "Winner: " << winner->Name << endl;

		for(int j=i+1;j<conflict.size();j++)// check whether this meeting has conflict in future or not
		{
			if(!(conflict[j].first == winner || conflict[j].second == winner))
			{
				finalMeet.push_back(winner);
				break;
			}
		}
	}

	return finalMeet;
}

int main()
{
	// make dictionary for rank
	
	// make vector for total employees
	vector<employees*> totalEmp;
	// make rank map
	map<string,int> rank;
	rank["CEO"] = 0;
	rank["COO"] = 0;
	rank["DIRECTOR"] = 0;
	rank["MANAGER"] = 0;

	// Make employees
	employees* e1 = getEmployee("Nitish","MANAGER",rank["MANAGER"],vector<meeting*>());
	totalEmp.push_back(e1);
	employees* e2 = getEmployee("Amit","DIRECTOR",rank["DIRECTOR"],vector<meeting*>());
	totalEmp.push_back(e2);
	employees* e3 = getEmployee("Sachin","DIRECTOR",rank["DIRECTOR"],vector<meeting*>());
	totalEmp.push_back(e3);
	employees* e4 = getEmployee("Sushma","MANAGER",rank["MANAGER"],vector<meeting*>());
	totalEmp.push_back(e4);
	employees* e5 = getEmployee("John","DIRECTOR",rank["DIRECTOR"],vector<meeting*>());
	totalEmp.push_back(e5);
	employees* e6 = getEmployee("Kanhaiya","COO",rank["COO"],vector<meeting*>());
	totalEmp.push_back(e6);
	employees* e7 = getEmployee("Girish","DIRECTOR",rank["DIRECTOR"],vector<meeting*>());
	totalEmp.push_back(e7);
	employees* e8 = getEmployee("Kalyan","CEO",rank["CEO"],vector<meeting*>());
	totalEmp.push_back(e8);
	employees* e9 = getEmployee("Iravati","MANAGER",rank["MANAGER"],vector<meeting*>());
	totalEmp.push_back(e9);
	employees* e10 = getEmployee("Harish","MANAGER",rank["MANAGER"],vector<meeting*>());
	totalEmp.push_back(e10);

	// Add meeting to Amit's calendar
	vector<meeting*> cal;
	meeting* m1 = getMeeting("Nitish","Scrum",convertTo24Hour("10:15AM"),convertTo24Hour("12:00PM"),7);
	cal.push_back(m1);
	meeting* m2 = getMeeting("Kanhaiya","OKR Review",convertTo24Hour("03:00PM"),convertTo24Hour("05:00PM"),4);
	cal.push_back(m2);
	meeting* m3 = getMeeting("Iravati","Design Review",convertTo24Hour("05:00PM"),convertTo24Hour("06:00PM"),6);
	cal.push_back(m3);
	meeting* m4 = getMeeting("Amit","Design Discussion",convertTo24Hour("11:45AM"),convertTo24Hour("01:30PM"),6);
	cal.push_back(m4);
	meeting* m5 = getMeeting("Nitish","Team Meeting",convertTo24Hour("05:30PM"),convertTo24Hour("06:00PM"),4);
	cal.push_back(m5);

	e2->calendar = cal;

	cout << 1 << endl;
	vector<pair<meeting*,meeting*> > conflict =  findConflict(e2);
	vector<meeting*> ans = resolveConflictAll(conflict,e2,totalEmp,rank);
	cout << ans.size() << endl;

	for(int i=0;i<ans.size();i++)
	{
		cout << ans[i]->Name << " " << ans[i]->st_time << endl;
	}

return 0;
}
