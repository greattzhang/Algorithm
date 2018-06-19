/*
һ���������У����������Ԫ�صĲ�ǡ������ (���� )������� ��������б���Ϊ ҡ������ ��һ��С�� 2��Ԫ�ص����� ֱ�� Ϊҡ�����С�
���� :
���� [1, 7, 4, 9, 2, 5] ������Ԫ�صĲ�(6, -3, 5, -7, 3)��������Ϊҡ�ڡ�
���� [1,4,7,2,5] (3, 3, -5, 3)�� [1,7,4,5,5]  (6, -3, 1, 0) ����ҡ�����С�
��һ��������� ����������ҡ�����ж����������� �ĳ��ȡ�
���� :
���� [1,7,4,9,2,5] ���Ϊ 6������ [1,17,5,10,13,15,10,5,16,8]�����Ϊ 7([1,17,10,13,10,16,8] ������ [1,2,3,4,5,6,7,8,9] �����Ϊ 2��

˼·��
����������������ģ�ֻȥ�����յ㣬�½�Ҳ��
ʹ��״̬��ʵ�֣�
beginΪ����Ԫ����ͬ����ת��Up״̬����Ϊ��һ������ǰһ������ת��DownΪǰһ�����ں�һ��
UpΪ����״̬����һ��>=ǰһ������״̬������ת��Down
DownΪ�½�״̬����һ��<=ǰһ������״̬������ת��Up
*/

//�����

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()<2){
            return nums.size(); //���и���С��2ֱ��Ϊҡ������
        }
        static const int Begin = 0; //����״̬��������״̬
        static const int Up = 1;
        static const int Down = 2;
        int State = Begin;
        int max_length = 1; //ҡ�����г�������Ϊ1  forѭ���ӵڶ���Ԫ�ؿ�ʼ
        
        for(int i=1; i<nums.size(); i++){
            switch(State){
                case Begin:
                    if(nums[i] == nums[i-1]){
                        State = Begin;
                    }
                    else if(nums[i]>nums[i-1]){
                        State = Up;
                        max_length++;
                    }
                    else{
                        State = Down;
                        max_length++;
                    }
                    break;
                case Up:
                    if(nums[i] < nums[i-1]){
                        State = Down;
                        max_length++;
                    }
                    break;
                case Down:
                    if(nums[i] > nums[i-1]){
                        State = Up;
                        max_length++;
                    }
                    break;
            }
        }
        return max_length;
    }
};
