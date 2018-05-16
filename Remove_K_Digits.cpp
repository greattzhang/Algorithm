/*
��Ŀ��
��֪һ��ʹ���ַ�����ʾ�ķǸ������Ǹ������Ǹ������Ǹ�����num����num�е�k�������Ƴ�������k�����ֺ󣬿��Ի�õ���С�Ŀ��ܵ������֡�
����:num=��1432219��,k=3:ȥ��3������������ֿ��ܣ���С��Ϊ1219
Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
1.�����num���ַ�������<=10002�������ַ�������>=k
2.�����num�ַ����������κ�������0�ַ���ͷ
˼·��
��ȥ��ĳһλ���֣�Ϊ��ʹ�õ������������£��������λ��С����θ�λ��С������ε�3λ
���ȴ�ͷ��ʼɾ���֣���һ������ǰһ������ɾ��ǰһ������ɾ������һ�����ɱ�֤���յõ��������Ǵ�С����ģ����ɾ����Կ�ɾ����Ӻ���ǰɾ
����ջʵ��
*/
//�����

class Solution {
public:
    string removeKdigits(string num, int k) {
        std::vector<int> S; //��Ϊջʹ��
        std::string result = ""; //���ս��
        for(int i=0; i<num.length(); i++){ //�����λ����num
            int number = num[i] - '0'; //ת��Ϊ����
            while(S.size() != 0 && number<S[S.size()-1] && k>0){ //ջ��Ϊ�գ���ջ������number
                S.pop_back();
                k--; //ɾһ������ɾ������һ��
            }
            if(S.size() != 0 || number != 0){
                S.push_back(number);
            }
        }
        
        while(S.size() != 0 && k>0){ //ջ��Ϊ�գ��Կ�ɾ
            S.pop_back();
            k--;
        }
        for(int i=0; i<S.size(); i++){ //�洢���
            result += to_string(S[i]);
        }
        if(result == "")
            return "0";
        return result;
    }
};