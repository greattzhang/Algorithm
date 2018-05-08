/*
���һ�����ݽṹ�������ݽṹ��̬ά��һ�����ݣ���֧�����²���:
1.���Ԫ��: void addNum(int num)��������num��������ݽṹ�С�
2.�������ݵ���λ��: double findMedian()��������ά�������ݵ���λ����
��λ������:
1.�����ݸ���Ϊ��������λ���Ǹ�����������м������[1,2,3] -> 2
2.�����ݸ���Ϊż������λ���Ǹ�����������м���������ֵ�ƽ��ֵ��[1,2,3,4] -> 2.5

˼·1��
��̬ά��һ��������һ����С�ѣ����Ѵ洢һ�����ݣ���С�Ѵ洢һ�����ݣ�ά�����ѵĶѶ�����С�ѵĶѶ�С��
���Ԫ�أ�
�� ���Ѻ���С��Ԫ�ظ�����ͬ ����ջ��Ԫ��С�ڸ�Ԫ�أ����뵽��С�ѣ�������뵽����
�� ����Ԫ�ظ���������С�ѣ�����ջ�����ڸ�Ԫ�أ���ջ��pop����push����С�ѣ�Ȼ�󽫸�Ԫ��push�����ѣ�����ջ��С�ڸ�Ԫ�أ�����Ԫ��push����С��
�� ��С��Ԫ�ظ����������ѣ���С��ջ��С�ڸ�Ԫ�أ���ջ��pop����push�����ѣ�Ȼ�󽫸�Ԫ��push����С�ѣ���С��ջ�����ڸ�Ԫ�أ�����Ԫ��push������
��λ����ȡ����
������С��Ԫ�ظ�����ͬ��ȡ����ջ���ľ�ֵ
����ͬ��˭��ȡ˭��ջ��
*/

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>


class MedianFinder {
public:
	/** initialize your data structure here. */
	MedianFinder() {

	}

	void addNum(int num) {
		if (big_queue.empty()){
			big_queue.push(num);
		}
		if (small_queue.size() == big_queue.size()) {
			if (num<big_queue.top()) {
				big_queue.push(num);
			}
			else {
				small_queue.push(num);
			}
		}
		else if (big_queue.size()>small_queue.size()) {
			if (num>big_queue.top()) {
				small_queue.push(num);
			}
			else {
				small_queue.push(big_queue.top());
				big_queue.pop();
				big_queue.push(num);
			}
		}
		else if (big_queue.size()<small_queue.size()) {
			if (small_queue.top()>num) {
				big_queue.push(num);
			}
			else {
				big_queue.push(small_queue.top());
				small_queue.pop();
				small_queue.push(num);
			}
		}
	}

	double findMedian() {
		if (big_queue.size() == small_queue.size()) {
			return (big_queue.top() + small_queue.top()) / 2;
		}
		else if (big_queue.size() > small_queue.size()) {
			return big_queue.top();
		}
		return small_queue.top();
	}
private:
	std::priority_queue<int> big_queue;
	std::priority_queue<int, std::vector<int>, std::greater<int>> small_queue;
	
};

/*
˼·2��
 ͬ��ά�����Ѻ���С�ѣ�����Ԫ��ֱ��push�����ѣ��ٽ����ѶѶ�push����С�ѣ�
 ����popһ��Ԫ�أ���ÿ��һ��Ԫ�أ������Ѷ�ҪpushԪ�أ�ֻ����С��push�������ѵ�����ĶѶ���
 ������Ԫ�ظ���С����С��ʱ������С�ѶԶ�push�������У���С��pop��
 ��֤���Ѹ�����С����С�ѣ�������֮��Ĳ���Ԫ��ʱֻ��������ѵĶѶ��������ѵ�ƽ��
 */
 
class MedianFinder1 {
public:
    /** initialize your data structure here. */
    std::priority_queue<int> lo;    //����
    std::priority_queue<int, std::vector<int>, std::greater<int>> hi;   //��С��
    
    MedianFinder1() {
        
    }
    
    void addNum(int num) {
        lo.push(num);
        
        hi.push(lo.top());
        lo.pop();
        
        if(lo.size()<hi.size()){
            lo.push(hi.top());
            hi.pop();
        }
    }
    
    double findMedian() {
        return lo.size() > hi.size()? (double)lo.top() : (double)(lo.top()+hi.top())/2;
    }
};

int main()
{
	MedianFinder m;
	int test[] = { 6,10,1,7,99,4,33 };
	for (size_t i = 0; i < sizeof(test)/sizeof(int); i++)
	{
		m.addNum(test[i]);
		printf("%lf\n", m.findMedian());
	}
	std::cout << std::endl;
	system("pause");
}

