#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

vector<bool> visited;

int main(void)
{
	int iFloor;
	int iCharacterPos;
	int iStartLinkPos;
	int iUp;
	int iDown;

	cin >> iFloor >> iCharacterPos >> iStartLinkPos >> iUp >> iDown;
	
	queue<pair<int, int>> q;
	visited.resize(iFloor + 1, false);

	q.push(make_pair(iCharacterPos, 0));
	visited[iCharacterPos] = true;
	
	int iResult = -1;

	while (q.empty() == false)
	{
		int iCurrentCharacterPos = q.front().first;
		int iCurrentCount = q.front().second;

		q.pop();
		
		if (iCurrentCharacterPos == iStartLinkPos)
		{
			iResult = iCurrentCount;
			break;
		}

		if (iUp != 0 && iCurrentCharacterPos + iUp <= iFloor && visited[iCurrentCharacterPos + iUp] == false)
		{
			q.push(make_pair(iCurrentCharacterPos + iUp, iCurrentCount + 1));
			visited[iCurrentCharacterPos + iUp] = true;
		}

		if (iDown != 0 && iCurrentCharacterPos - iDown > 0 && visited[iCurrentCharacterPos - iDown] == false)
		{
			q.push(make_pair(iCurrentCharacterPos - iDown, iCurrentCount + 1));
			visited[iCurrentCharacterPos - iDown] = true;
		}
	}

	if (iResult != -1)
	{
		cout << iResult;
	}
	else
	{
		cout << "use the stairs";
	}

	return 0;
}