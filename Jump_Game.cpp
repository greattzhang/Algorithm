/*
��Ŀ��
����һ���Ǹ��������飬�����λ������ĵ�һ��λ�á�
�����е�ÿ��Ԫ�ش������ڸ�λ�ÿ�����Ծ����󳤶ȡ�
�ж����Ƿ��ܹ��������һ��λ�á�
ʾ�� 1:
����: [2,3,1,1,4]
���: true
����: ��λ�� 0 �� 1 �� 1 ��, Ȼ���� 3 ���������һ��λ�á�
ʾ�� 2:
����: [3,2,1,0,4]
���: false
����: �������������ܻᵽ������Ϊ 3 ��λ�á�����λ�õ������Ծ������ 0 �� ��������Զ�����ܵ������һ��λ�á�

˼·����0��λ������jump�����У���Զ���Ե����λ����max_index��ʾ����index�����洢��ǰλ�ÿ�ʼ������Ծ������Զλ�ã���λ��x������Ծ��index��x������Ҳ������Ծ��i+1,i+2,...,index[x]��ʹ��jump����ǰ����λ�ã������տ��Ե���nums��β�����򷵻�true��jump++������ δ��Ծ��nums��β�� �� С��max_index��max_index���·�����max_indexС��index[jump]
*/

//����

class Solution {
public:
    bool canJump(vector<int>& nums) {
        std::vector<int> index;
        for(int i=0; i<nums.size(); i++){
            index.push_back(nums[i] + i); //�ӵ�i��λ����Զ����Ծ֮��index[i]λ��
        }
        int jump = 0;
        int max_index = index[0];
        while(max_index>=jump && jump<index.size()){ //δ����β�� �� δ��Խ��ǰ������Ծ��Զλ��
            if(max_index<index[jump]){
                max_index = index[jump];
            }
            jump++;
        }
        if(jump == index.size()){
            return true;
        }
        return false;
    }
};