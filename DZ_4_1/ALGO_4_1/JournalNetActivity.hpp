
#include "JournalNetActivity.h"

#include <fstream>

template <int numLevels>
JournalNetActivity<numLevels>::JournalNetActivity(void)
{
}

template <int numLevels>
JournalNetActivity<numLevels>::~JournalNetActivity(void)
{}

// Read the whole log from the file on fullpath
template <int numLevels>
void JournalNetActivity<numLevels>::parseLog(string fullpath)
{
	ifstream fin(fullpath); // opens the file

	TimeStamp timestamp; // dummy
	NetActivity netactivity; // dummy

	int i = 0;
	while (fin)
	{

		fin >> timestamp;
		if (!fin) break;
		fin >> netactivity.m_user;
		if (!fin) break;
		fin >> netactivity.m_host;
		if (!fin) break;


		m_Journal.insert(netactivity, timestamp);
		i++;
	}
}

// Just dumps the whole journal to the out stream
template <int numLevels>
void JournalNetActivity<numLevels>::dumpJournal(ostream & out)
{
	typename TypeList::TypeNode * prehead, * run;
	prehead = m_Journal.getPreHead();
	run = prehead;

	// prehead is placed before the first and after the last element
	// So it serves two roles.
	while (run->m_next != prehead)
	{
		run = run->m_next;
		out << run->m_key;
		out << " ";
		out << run->m_value;
	}
}

// Outputs all net activity between from and to
template <int numLevels>
void JournalNetActivity<numLevels>::outputSuspiciousActivities(
	string hostSuspicious, const TimeStamp & timeFrom, const TimeStamp & timeTo) const
{
	TimeStamp timeForSearch;

	NodeSkipList<NetActivity,TimeStamp,numLevels>* first = m_Journal.findFirst(timeFrom);
	NodeSkipList<NetActivity,TimeStamp,numLevels>* second= m_Journal.findLastLessThan(timeTo);

	if(first)
	{
		// go through list
		while (first->m_key <= timeTo)
		{
			if (first->m_value.m_host == hostSuspicious)
				std::cout << first->m_value << std::endl;

			first=first->m_next;
		}
	}
	std::cout  << std::endl;


}
