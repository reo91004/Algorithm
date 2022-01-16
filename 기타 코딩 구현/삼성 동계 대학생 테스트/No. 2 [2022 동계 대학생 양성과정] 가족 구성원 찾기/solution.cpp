//	 The below commented functions are for your reference. If you want 
//	 to use it, uncomment these functions.
#include <deque>
#include <algorithm>
#include <iostream>

using namespace std;

typedef struct family {
	int relationship;
	int sex;
	char name[20];
} family;


deque<deque<family>> graph;

int mstrcmp(const char a[], const char b[])
{
	int i;
	for (i = 0; a[i] != '\0'; ++i) if (a[i] != b[i]) return a[i] - b[i];
	return a[i] - b[i];
}

void mstrcpy(char dest[], const char src[])
{
	int i = 0;
	while (src[i] != '\0') { dest[i] = src[i]; i++; }
	dest[i] = src[i];
}

int mstrlen(const char a[])
{
	int i;
	for (i = 0; a[i] != '\0'; ++i);
	return i;
}

struct Find {
	char tempname[20];
	bool operator() (family temp) {
		return (mstrcmp(temp.name, tempname));
	}

};

void init(char initialMemberName[], int initialMemberSex)
{
	family tempfamily;
	mstrcpy(tempfamily.name, initialMemberName);
	tempfamily.sex = initialMemberSex;

	graph.push_back(deque<family>());
	graph[0].push_back(tempfamily);
}

bool addMember(char newMemberName[], int newMemberSex, int relationship, char existingMemberName[])
{
	family tempfamily;
	mstrcpy(tempfamily.name, newMemberName);
	tempfamily.sex = newMemberSex;

	switch (relationship) {
		case 0: // 배우자 (성별 다름, 이미 배우자 있으면 안됨)
			break;
		case 1: // 부모 (성별 같은 부모 x)
			break;
		case 2: // 자식
			break;
	}

	return false;
}

int getDistance(char nameA[], char nameB[])
{
	return -1;
}

int countMember(char name[], int dist)
{
	return -1;
}
