#include <iostream>
#include <string>
#include <list>
using namespace std;

struct FeedItem
{
	int itemId;
	string title;
	string pics[51];  
	string author;
	string category;
};

typedef list<FeedItem> ReorderList;

ReorderList reorderFeedItems(ReorderList inputItems) { //50->10
	ReorderList ans;
	ReorderList::iterator i;
	ReorderList::iterator j;
	//2.3 重排时, 相同category的FeedItem最多连续显示2条
	for (i = inputItems.begin(), j = ++inputItems.begin(); j != inputItems.end(); i++, j++) {
		if (i->category != j->category) {
			continue;
		}
		else if (i->category == j->category) {
			j++;
			if (i->category != j->category) {
				continue;
			}
			else if (i->category == j->category) { //如果连续3条，则重排到第一个category不同的元素后面
				i = j;
				FeedItem tmp = *i;
				while (i->category == j->category && j != inputItems.end()) {
					j++;
				}
				inputItems.erase(i);
				inputItems.insert(++j, tmp);
			}
		}
	}
	//2.2 重排时, 相同author的FeedItem不能相邻
	for (i = inputItems.begin(), j = ++inputItems.begin(); j != inputItems.end(); i++, j++) {
		if (i->author != j->author) {
			continue;
		}
		else if (i->author == j->author) {  //若相邻，则将元素重排到第一个author不同的元素后面
			i = j;
			FeedItem tmp = *i;
			while (i->author == j->author && j != inputItems.end()) {
				j++;
			}
			inputItems.erase(i);
			inputItems.insert(++j, tmp);
		}
	}
	//优先执行2.3的重排要求，再执行2.2的重排要求，因此在发生冲突时会优先满足2.2

	//最后，提取前10条结果
	int k = 0;
	i = inputItems.begin();
	while (k < 10) {
		ans.push_back(*i);
		i++;
		k++;
	}
	return ans;
}

int main() {
	//主函数部分略
	return 0;
}