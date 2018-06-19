/*��Ŀ��
			��֪һ��δ��������飬����������е�K������֡� �磬array = [3,2,1,5,6,4] �� k = 2��return 5
˼·��
ά��һ��K��С����С�ѣ�����Ԫ�ظ���С��Kʱ����Ԫ��ֱ�ӽ���ѣ����򣬵��Ѷ�С����Ԫ��ʱ�������Ѷ�������Ԫ�ؼ���ѡ� ����: ���ڶ�����С�ѣ��Ѷ��Ƕ�����СԪ�أ���Ԫ�ض��ᱣ֤�ȶѶ�С(������Ԫ���滻�Ѷ�)���ʶ���K��Ԫ������ɨ���Ԫ��������K�����Ѷ���Ϊ��K������� �����鳤��ΪN�����K�������ʱ�临�Ӷ� : N * logK
���
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> Q;    //��С��
        for(int i = 0; i<nums.size();i++){
            if(Q.size()<k){    //ά��k��Ԫ�ص���С��
                Q.push(nums[i]);
            }
            else if(nums[i]>Q.top()){    //�Ѷ�Ԫ��С���򵯳���push��Ԫ��
                Q.pop();
                Q.push(nums[i]);
            }
        }
        return Q.top();    //���ضѶ�Ԫ��
    }
};