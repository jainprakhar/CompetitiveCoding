#include <bits/stdc++.h>
using namespace std;

struct player{

public:
	string name;
	int role;//0 - batsman, 1- bowler, 3 - all rounder
	int country;//0 for india and 1 for australia
	int runs_taken;
	int wickets;
	int catches;
	int stumping;
	int run_outs;
	int maiden;
	int overs;
	int runs_given;
	int rating;// will store the ratings for each match
	//matchData(void);

};

player* getPlayer(string nm,int profile,int cont,int runsTaken,int wick,int cat,int stump, int runOut, int maid, int ov, int runsGiven,int rate)
{
	player* p = new player;
	p->name = nm;
	p->country = cont;
	p->role = profile;
	p->runs_taken = runsTaken;
	p->wickets = wick;
	p->catches = cat;
	p->stumping = stump;
	p->run_outs = runOut;
	p->maiden = maid;
	p->overs = ov;
	p->runs_given = runsGiven;
	p->rating = rate;

	return p;

}

struct match{

	int winner;// 0 india, 1 australia
	int m_no;//match no
	player* highest_scorer;// most runs
	player* highest_wickets;// most wickets
	player* mom;//man of the match
	vector<player*> match_players; 
	int runs_by_ind;
	int runs_by_aus;

};


match* getMatch(int win,int mno,player* highScore,player* highWick,player* manofm,vector<player*> mp,int runsInd,int runsAus)
{
	match* m = new match;
	m->winner = win;
	m->m_no = mno;
	m-> highest_scorer = highScore;
	m->highest_wickets = highWick;
	m->mom = manofm;
	m->match_players = mp;
	m->runs_by_ind = runsInd;
	m->runs_by_aus = runsAus;

	return m;
}

struct series{

	map<int,match*> series_matches;//key = m_no i.e. match no

};



// Functions

int batRate(player* p)
{
	int ans = 0;
	if(p->runs_taken > 20)
	{
		ans += 15;
	}

	ans += 2*floor(p->runs_taken/10);

	return ans;
}

int bowlRate(player* p)
{
	int ans = 0;

	ans += 5*p->wickets;
	ans += 2*p->maiden;

	if(p->wickets >= 2)
		ans += 20;

	return ans;
}

int fieldRate(player* p)
{
	int ans = 0;
	ans += 2*p->catches;
	ans += 2*p->run_outs;
	ans += 2*p->stumping;

	return ans;
}

int giveRating(player* curr)
{
	//vector<player*> mp = m->match_players;
	//player* curr;


	int rat = batRate(curr) + bowlRate(curr) + fieldRate(curr);
	// if(!((m->mom)->name).compare(player_name))// bonus for man of the match
	// 	rat += 10;

	return rat;
}

player* manOfMatch(vector<player*> players)
{
	int maxrate = INT_MIN;
	player* temp;
	for(int i=0;i<players.size();i++)
	{
		if(players[i]->rating > maxrate)
		{
			maxrate = players[i]->rating;
			temp = players[i];
		}
	}

	return temp;
}

int totalRuns(vector<player*> team)
{
	int runs = 0;

	for(int i=0;i<team.size();i++)
		runs += team[i]->runs_taken;

	return runs;
}

int winn(int t1runs,int t2runs)
{
	if(t1runs > t2runs)
		return 0;
	else if(t1runs == t2runs)
		return -1;

	return 1;
}

player* HighestRuns(vector<player*> p)
{
	player* temp;
	int runs = 0;
	for(int i=0;i<p.size();i++)
	{
		if(runs < p[i]->runs_taken)
		{
			runs = p[i]->runs_taken;
			temp = p[i];
		}
	}

	return temp;
}

player* HighestWickets(vector<player*> p)
{
	player* temp;
	int wicket = 0;
	for(int i=0;i<p.size();i++)
	{
		if(wicket < p[i]->wickets)
		{
			wicket = p[i]->wickets;
			temp = p[i];
		}
		else if(wicket == p[i]->wickets)
		{
			if(p[i]->runs_given < temp->runs_given)
			{
				temp = p[i];
			}
		}
	}

	return temp;
}

void printTemplate(int winnerIs,player* manMatch,int totalruns_india,int totalruns_aus,player* mostruns,player* mostwickets,int wicketInd,int wicketAus)
{
	if(winnerIs == 0)// India won - template 1
	{
		cout << "India batting first, won the game by " << totalruns_india - totalruns_aus << "runs!!" << 
		manMatch->name << " was Man of the Match. " << mostruns->name << " was the highest run scorer  and " <<
		 mostwickets->name << " bowled the best" << endl; 
	}
	else if(winnerIs == 1)// Australis won - template 2
	{
		cout << "Australia chased successfully and won the game by " << 5 - wicketAus << " wickets!! " << 
		manMatch->name << " was Man of the Match. " << mostruns->name << " was the highest run scorer and " <<
		 mostwickets->name << " bowled the best" << endl;
	}
	else// tie
	{
		cout << "Match b/w India & Australia ended in a tie " << manMatch->name << " was Man of the Match. " << mostruns->name << " was the highest run scorer  and " <<
		 mostwickets->name << " bowled the best" << endl;
	}

}

int goneWickets(vector<player*> p)
{
	int wicks = 0;

	for(int i=0;i<p.size();i++)
	{
		wicks += p[i]->wickets + p[i]->run_outs;
	}

	return wicks;
}

void match1()
{
	//MATCH 1

	vector<player*> playersAre;
	vector<player*> ind;
	vector<player*> aus;

	// indian players
	player* i1 = getPlayer("Virat",0,0,20,0,1,0, 1, 0, 0,0,0);
	player* i2 = getPlayer("Rahane",0,0,25,0,0,0, 0, 0, 0,0,0);
	player* i3 = getPlayer("Bumrah",1,0,0,2,1,0, 1, 0, 2,20,0);
	player* i4 = getPlayer("Shami",1,0,5,0,1,0, 0, 1, 2,6,0);
	player* i5 = getPlayer("Jadeja",2,0,15,2,0,0, 0, 0,1,10,0);

	i1->rating = giveRating(i1);
	i2->rating = giveRating(i2);
	i3->rating = giveRating(i3);
	i4->rating = giveRating(i4);
	i5->rating = giveRating(i5);

	playersAre.push_back(i1);
	playersAre.push_back(i2);
	playersAre.push_back(i3);
	playersAre.push_back(i4);
	playersAre.push_back(i5);

	ind.push_back(i1);
	ind.push_back(i2);
	ind.push_back(i3);
	ind.push_back(i4);
	ind.push_back(i5);	

	// australia players
	player* a1 = getPlayer("Finch",0,1,10,0,1,0, 0, 0, 0,0,0);
	player* a2 = getPlayer("Khwaja",0,1,15,0,2,0, 0, 0, 0,0,0);
	player* a3 = getPlayer("Starc",1,1,4,2,1,0, 0, 0, 2,20,0);
	player* a4 = getPlayer("Lyon",1,1,5,1,0,0, 1, 0, 2,25,0);
	player* a5 = getPlayer("Cummins",2,1,2,1,0,0, 0, 0, 1,20,0);

	a1->rating = giveRating(a1);
	a2->rating = giveRating(a2);
	a3->rating = giveRating(a3);
	a4->rating = giveRating(a4);
	a5->rating = giveRating(a5);

	playersAre.push_back(a1);
	playersAre.push_back(a2);
	playersAre.push_back(a3);
	playersAre.push_back(a4);
	playersAre.push_back(a5);

	aus.push_back(a1);
	aus.push_back(a2);
	aus.push_back(a3);
	aus.push_back(a4);
	aus.push_back(a5);


	//player* manOfmatch = manOfMatch(playersAre);
	int totalruns_india = totalRuns(ind);
	int totalruns_aus = totalRuns(aus);

	int winnerIs = winn(totalruns_india,totalruns_aus);// 0 first team, -1 tie, 1 second team
		
	// 

	player* manMatch;

	if(winnerIs == 0)// first team
	{
		manMatch = manOfMatch(ind);
	}
	else if(winnerIs == 1)// second team
	{
		manMatch = manOfMatch(aus);
	}
	else
	{
		manMatch = manOfMatch(playersAre);
	}

	player* mostruns = HighestRuns(playersAre);
	player* mostwickets = HighestWickets(playersAre);

	int wicketsind = goneWickets(aus);
	int wicketsaus = goneWickets(ind);

	//match* m1 = getMatch()

	// assume india bats first
	printTemplate(winnerIs,manMatch,totalruns_india,totalruns_aus,mostruns,mostwickets,wicketsind,wicketsaus);

}

void match2()
{
	//MATCH 2

	vector<player*> playersAre;
	vector<player*> ind;
	vector<player*> aus;

	// indian players
	player* i1 = getPlayer("Virat",0,0,10,0,1,0, 1, 0, 0,0,0);
	player* i2 = getPlayer("Rahul",0,0,5,0,0,0, 0, 0, 0,0,0);
	player* i3 = getPlayer("Ishant",1,0,0,1,0,0, 1, 0, 2,20,0);
	player* i4 = getPlayer("Shami",1,0,8,0,0,0, 0, 1, 2,9,0);
	player* i5 = getPlayer("Hardik",2,0,15,0,0,0, 0, 0,1,10,0);
	i1->rating = giveRating(i1);
	i2->rating = giveRating(i2);
	i3->rating = giveRating(i3);
	i4->rating = giveRating(i4);
	i5->rating = giveRating(i5);

	playersAre.push_back(i1);
	playersAre.push_back(i2);
	playersAre.push_back(i3);
	playersAre.push_back(i4);
	playersAre.push_back(i5);

	ind.push_back(i1);
	ind.push_back(i2);
	ind.push_back(i3);
	ind.push_back(i4);
	ind.push_back(i5);	

	// australia players
	player* a1 = getPlayer("Warner",0,1,22,0,1,0, 0, 0, 0,0,0);
	player* a2 = getPlayer("TimPane",0,1,14,0,2,0, 0, 0, 0,0,0);
	player* a3 = getPlayer("Starc",1,1,3,2,0,0, 0, 0, 2,10,0);
	player* a4 = getPlayer("Warne",1,1,0,1,1,0, 0, 0, 2,20,0);
	player* a5 = getPlayer("Marsh",2,1,0,1,0,0, 0, 0, 1,18,0);

	a1->rating = giveRating(a1);
	a2->rating = giveRating(a2);
	a3->rating = giveRating(a3);
	a4->rating = giveRating(a4);
	a5->rating = giveRating(a5);

	playersAre.push_back(a1);
	playersAre.push_back(a2);
	playersAre.push_back(a3);
	playersAre.push_back(a4);
	playersAre.push_back(a5);

	aus.push_back(a1);
	aus.push_back(a2);
	aus.push_back(a3);
	aus.push_back(a4);
	aus.push_back(a5);


	//player* manOfmatch = manOfMatch(playersAre);
	int totalruns_india = totalRuns(ind);
	int totalruns_aus = totalRuns(aus);

	int winnerIs = winn(totalruns_india,totalruns_aus);// 0 first team, -1 tie, 1 second team
	
	// for(int i=0;i<playersAre.size();i++)
	// {
	// 	int tp = giveRating(playersAre[i]);
	// 	playerAre[i]->rating = tp;

	// 	if(playersAre[i]->country == 0)
	// 	{
	// 		for(int j=0;j<ind.size();j++)
	// 		{
	// 			if(!ind[j]->name.compare(playersAre[i]->name))
	// 			{
	// 				ind[j]->rating = tp;
	// 				break;
	// 			}
	// 		}
	// 	}
	// 	else if(playersAre[i]->country == 1)
	// 	{
	// 		for(int j=0;j<aus.size();j++)
	// 		{
	// 			if(!aus[j]->name.compare(playersAre[i]->name))
	// 			{
	// 				aus[j]->rating = tp;
	// 				break;
	// 			}
	// 		}
	// 	}

	// }


	player* manMatch;

	if(winnerIs == 0)// first team
	{
		manMatch = manOfMatch(ind);
	}
	else if(winnerIs == 1)// second team
	{
		manMatch = manOfMatch(aus);
	}
	else
	{
		manMatch = manOfMatch(playersAre);
	}

	player* mostruns = HighestRuns(playersAre);
	player* mostwickets = HighestWickets(playersAre);

	int wicketsind = goneWickets(aus);
	int wicketsaus = goneWickets(ind);

	// assume india bats first
	printTemplate(winnerIs,manMatch,totalruns_india,totalruns_aus,mostruns,mostwickets,wicketsind,wicketsaus);

}

int main()
{
	cout << "Match #1 Results:\n" << endl;
	// match 1
	match1();
	cout << "\nMatch #2 Results:\n" << endl;
	// MATCH 2
	match2();



	
	return 0;
}